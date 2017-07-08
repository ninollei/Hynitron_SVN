
#include "all_includes.h"
#include "css1xxx_code.h"

#define CSX_RXCH_BASE	 (CSD_BASE + 0x100)
#define GET_APIN_NO(x)	 ((x>>4)*4 + (x&0x0f))
#define GET_RXCH_NO(x)	 (GET_APIN_NO(x)%16)
#define GET_RXCH_CR(x)	 (CSX_RXCH_BASE + 0x08*GET_RXCH_NO(x))

typedef struct{
	unsigned char addr;
    unsigned char fun;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char byte3;
    unsigned char byte4;
    unsigned char byte5;
}SCALL_t;
static SCALL_t scall;
const unsigned char  set_cmd_idata[2] = {CST0_REG_IDATA << 1, SCALL_ADDR >> 6};
const unsigned char  set_cmd_xdata[2] = {CST0_REG_XDATA << 1, 0x00};
const unsigned char set_cmd_call[] = {0x70,SCALL_ADDR};
unsigned char b_ChipType;
const uint16 dut_pinlist[100] = EXPECTED_PIN_LIST;
static unsigned char g_trim_data[129] = {0};


void setIDAC(uint8 source, uint8 idac)
{
	if(source == IDAC_SRC) CSD_ICR = 0x100;
	else                   CSD_ICR = 0x300;

	CSD_IBL = idac;
	CSD_IMS = idac;
}

void initCSD(void)
{
   register uint8  idx;
   register uint32 addr;
   
   CSD_EN          = 0x01;   //enable so that analog can be settling
   
   //CSD_ICR         = 0x100;  ///DFT source
   //CSD_IBL         = 0x10;
   //CSD_IMS         = 0x10;   //800*16=12.8uA
   
   setIDAC(IDAC_SRC, IDAC_128UA);

   CSD_VREF      =  0x0f;   //enable vref, ref_mid = 1.6v, pumpout = 6V
   CSD_TX_DRV    =  0x20;   //set pump clock
   CSD_TX_CR     =  0x11;   //set hvsel, pumpen

   CSD_MODE   	|= 0x030;  ///set const_cmp_en
   CSD_SW_CR   	 = 0x190;

   //enable analog channels
   addr = CSD_BASE + 0x100;
   for(idx=0; idx<16; idx++) {
       REG32(addr) = 0x300;
       addr += 0x08;
   }

}

void reset_dut(void)
{
     uint8 dly;
     setAport(DUT_XRES, STAT_LOW);
	 for(dly=0; dly<50; dly++);
	 setAport(DUT_XRES, STAT_HIZ);
}

void delay1ms(uint16 dly)
{
    cnt1ms = 0;
    enable_slpTimer(0x20);
    while(cnt1ms<dly); 
    disable_slpTimer();
}

void delay250us(uint16 dly)
{
    cnt1ms = 0;
    enable_slpTimer(0x08);
    while(cnt1ms<dly); 
    disable_slpTimer();
}

void delay10us(unsigned int dly)
{
	unsigned short i,j;

	for(j=0;j<dly;j++)
		for(i=0;i<12;i++);
}

void setAport(uint16 aport, uint16 stat)
{
    uint8 bitMask = 0x01<<(aport & 0x0f);
	uint32 addr;

    aport &= 0xff0;
    addr  = 0x40081000 + aport;

    if     (stat==STAT_HIZ) {
		REG32(addr     ) &= ~bitMask;
		REG32(addr+0x04) &= ~bitMask;
		REG32(addr+0x08) &= ~bitMask;
		REG32(addr+0x0C) &= ~bitMask;
    }
    else if(stat==STAT_LOW) {
		REG32(addr+0x04) &= ~bitMask;
		REG32(addr+0x08) &= ~bitMask;
		REG32(addr+0x0C) &= ~bitMask;
		REG32(addr)      |=  bitMask;
    }
	else if(stat==STAT_RX) {		
		REG32(addr     ) &= ~bitMask;
		REG32(addr+0x04) &= ~bitMask;
		REG32(addr+0x08) &= ~bitMask;
		REG32(addr+0x0C) |=  bitMask;
    }
	else if(stat==STAT_TX) {		
		REG32(addr     ) &= ~bitMask;
		REG32(addr+0x08) &= ~bitMask;
		REG32(addr+0x0C) &= ~bitMask;
		REG32(addr+0x04) |=  bitMask;
    }
}


void enable_slpTimer(uint16 value)
{
    SLPTIM_CR  = 0x08;
    SLPTIM_CLR = SLPTIM_STAT;
    SLPTIM_ACC_CR = 0x8000|value;  //0X8020;   ///1ms
    SLPTIM_CR  = 0x80;
}

void disable_slpTimer(void)
{
    SLPTIM_CR  = 0x08;
    SLPTIM_CLR = SLPTIM_STAT;
}

uint8 getAPortVal(uint16 aport)
{
    uint8 duty, times;
	uint32 addr = GET_RXCH_CR(aport);
	

    duty = 20;
	for(times=0; times<10; times++)
	{
	    if(REG32(addr) & 0x80) duty++;
		else duty--;
	}
	
	if(duty>20) return 1;
	else        return 0;
}		 

void pullDownI2C(void)
{
    IOD0_DM2 &= ~0x0C;
    IOD0_DM1 &= ~0x0C;
    IOD0_DM0 |=  0x0C;

	IOD0_GOE &= ~0x0C;
	IOD0_DR  &= ~0x0C;
}

void outputTestInfo(uint32 *testInfo)
{
    register uint8 cnt;

	IMO_CR       &= ~0x80; 
	I2C0_CR       = 0x00;     ///disable I2C before reconfig 
    I2C0_STAT     = 0x00;     ///@zdf: clear all residual status if exist

	SCR_SCB_CR  =  0x32;
	IOD0_GOE   |=  0x0c; 
	IOD0_GIE   |=  0x0c; 
	
    IOD0_DM2   &=  ~0x0C;  
	IOD0_DM1   |=   0x0C;  
	IOD0_DM0   |=   0x0C;  
	
	/*cfg clk rate*/  
    SCR_PCLK_DIV0 = (2<<4);   //24M clk_sys, 1M iic clk @zdf: too fast???
	SCR_PCLK_CR   = 0x40;
	
    
	I2C0_BURST_CR  = 0x20|0x0f;    	//enable nack IE, burst mode and buf size is 16byte
    I2C0_AD        = 0x1A|0x80;	  	//master trans slaver addr(eeprom iic address)	

	I2C0_CR        = 0x01;    	//disable i2c IE, sel pclk1 and slave mode
	I2C0_STAT      = 0x14; 
	I2C0_BURST_AD  = 0x00;
	
	I2C0_DR = testInfo[0]>>24;
	I2C0_DR = testInfo[0]>>16;
	I2C0_DR = testInfo[0]>>8;
	I2C0_DR = testInfo[0];
	I2C0_DR = testInfo[1]>>24;
	I2C0_DR = testInfo[1]>>16;
	I2C0_DR = testInfo[1]>>8;
	I2C0_DR = testInfo[1];
	I2C0_DR = testInfo[2]>>24;
	I2C0_DR = testInfo[2]>>16;
	I2C0_DR = testInfo[2]>>8;
	I2C0_DR = testInfo[2];
	I2C0_DR = testInfo[3]>>24;
	I2C0_DR = testInfo[3]>>16;
	I2C0_DR = testInfo[3]>>8;
	I2C0_DR = testInfo[3];
	
	while((I2C0_STAT&0x01) != 0x01);

    for(cnt=0; cnt<88; cnt++);

    I2C0_STAT = 0;
	I2C0_CR   = 0;	
} 

unsigned char chip_scall(void)
{
	unsigned char ret;
	
	scall.addr = 0x80 | ((SCALL_ADDR&0x3F)<<1);		// SCALL_ADDR = 0xF4
	
	fwi2c_start();
	ret = fwi2c_sendBytes((unsigned char *)set_cmd_idata, 0x02);	// 下发 CST0_REG_IDATA << 1,  SCALL_ADDR>> 6
	fwi2c_stop();	
	if (ret != 0)
		return 1;	

	fwi2c_start();
	ret = fwi2c_sendBytes((unsigned char *)&scall, sizeof(scall));	
	fwi2c_stop(); 
	if (ret != 0)
		return 1;

 	delay10us(2); 
	
	fwi2c_start();
	ret = fwi2c_sendBytes((unsigned char *)set_cmd_call, 0x02);		// 下发 0x70,SCALL_ADDR, 如果此过程是擦除操作则耗时比较长
	fwi2c_stop(); 
	if (ret != 0)
		return 1;	 
 
	delay10us(2);
	
	fwi2c_start();
	ret = scall.addr|0x81;
	ret = fwi2c_sendBytes(&ret, 1);
	if (ret != 0)
	{
		fwi2c_stop(); 
		return 1;
	}
	fwi2c_getBytes(&(scall.fun),sizeof(scall)-1, sizeof(scall)-2);
	fwi2c_stop(); 

	delay10us(2);

	if (scall.fun == 0)
		return 0;
	else 
		return 1;

} 

unsigned char time_parameters_set(void)
{
	unsigned ret;

 	//din[0]=0x02;din[1]=0x13;din[2]=0x05;din[3]=0x07;
	//din[0]=0x01;din[1]=0x07;din[2]=0x05;din[3]=0x12;
	//set program/erase timing parameters
	ret = fwi2c_write_register(CST0_REG_IDATA,0xFC,0x01);
	if (ret != 0)
		return 1;

	ret = fwi2c_write_register(CST0_REG_IDATA,0xFD,0x07);
	if (ret != 0)
		return 1;

	ret = fwi2c_write_register(CST0_REG_IDATA,0xFE,0x05);
	if (ret != 0)
		return 1;

	ret = fwi2c_write_register(CST0_REG_IDATA,0xFF,0x12);
	if (ret != 0)
		return 1; 		

	return 0;
} 

// 读取xdm数据
unsigned char NVM_ID_XDM_read(unsigned char tId, unsigned char *pBuf)
{
	unsigned char ret;
	unsigned char tmp[8]; 
	
	// read trim data	
	scall.fun = CMD_NVM_ID_READ;
	scall.byte1 = tId; 
	scall.byte2 = TMP_REG;
	scall.byte3 = 0x00; 
	scall.byte4 = 0x00;
	scall.byte5 = 0x00;	
	ret = chip_scall();
	if (ret != 0)
		return ret;	

	ret = fwi2c_read_registers(CST0_REG_XDATA,TMP_REG,tmp,8);
	if (ret != 0)
		return ret;

	memcpy(pBuf, tmp, 8);

	return 0;
}

// read trim data,INFO and VBG Data
unsigned char chip_trim_read(void)
{
	unsigned char i, ret;
	unsigned short checksum, c_sum;

	for (i = 0; i < 8; i++)
	{
		ret = NVM_ID_XDM_read(0x8C+i, g_trim_data+8*i);
		if (ret != 0)
			return 1;
	}

	c_sum = 0;
	for (i = 0; i < 14; i++)
		c_sum += g_trim_data[i];
	c_sum = 65536-18782- c_sum;
	checksum = g_trim_data[14]*256 + g_trim_data[15];
	if (c_sum != checksum)
		return 1;

	return 0; 
}

//	write trim data,INFO and VBG Data
unsigned char chip_retrim_writeback(void)
{
	unsigned char ret, i;
	unsigned short c_sum;
	
	// set erase timing parameter
	ret = time_parameters_set();
	if (ret != 0)
		return 1;

	// erase block
	scall.fun = CMD_NVM_CLEAR_BLOCK;
	scall.byte1 = 0x81;
	scall.byte2 = 0x00;
	scall.byte3 = 0x00;
	scall.byte4 = 0x00;
	scall.byte5 = 0x00;
	ret = chip_scall();
	if (ret != 0)
		return 1;

	c_sum = 0;
	for (i = 0; i < 14; i++)
		c_sum += g_trim_data[i];		 
	c_sum = 65536-18782-c_sum; 
	g_trim_data[14] = c_sum>>8;
	g_trim_data[15] = c_sum&0x00FF;	 

	// write back necessary info 
	ret = fwi2c_write_registers(CST0_REG_IDATA, ADDR_TABLE, g_trim_data, 64);
	if (ret != 0)
		return 1;

	for (i = 0; i < 8; i++)
	{
		scall.fun = CMD_WRITE_TRIM_TBL;
		scall.byte1 = 0x0C + i;
		scall.byte2 = ADDR_TABLE + i * 8;
		scall.byte3 = 0x00;
		scall.byte4 = 0x00;
		scall.byte5 = 0x00;
		ret = chip_scall();
		if (ret != 0)
			return 1;
	}

//	chip_trim_read();
//	while(1);

	// check if write back OK
	scall.fun = 0x4B;		// check if trim data writeback is ok
	scall.byte1 = 0x00;
	scall.byte2 = 0x00;
	scall.byte3 = 0x00;
	scall.byte4 = 0x00;
	scall.byte5 = 0x00;
	ret = chip_scall();
	if (ret != 0)
		return 1;
	 
	return 0;
}

/**
*	进入PTM模式:write 0x674A
*	检查芯片是否trim并读取trim值
*	两种进入PTM模式的方式：有reset和没有reset的进入方式不同
*/
unsigned char chip_acquire_ptm(void)
{
	unsigned char ret = 0;
	unsigned char retry = 0;

	memset((unsigned char *)&scall, 0, sizeof(scall));
	
Start:	
	fwi2c_init();
	reset_dut();

	//after reset, 0x674A must send in 80us		
	fwi2c_w0();fwi2c_w1();fwi2c_w1();fwi2c_w0();
	fwi2c_w0();fwi2c_w1();fwi2c_w1();fwi2c_w1();	//write 67
	
	fwi2c_w0();fwi2c_w1();fwi2c_w0();fwi2c_w0();
	fwi2c_w1();fwi2c_w0();fwi2c_w1();fwi2c_w0();	//write 4A 

	fwi2c_set1_sda;
	fwi2c_set1_scl;
	delay250us(1);
	
	ret = fwi2c_write_register(CST0_REG_SFR, CST0_SCKCR2, 0x02);
	if (ret != 0)
	{
		ret = 201;
		goto End;
	}
		
	scall.fun = CMD_MEM_TEST;
    scall.byte1 = 0x00;
    scall.byte2 = 0xFF;
	scall.byte3 = 0x00;
	scall.byte4 = 0x00;
	scall.byte5 = 0x00;
	ret = chip_scall();
	if (ret != 0)
	{
		ret = 202;
		goto End;
	}

//	chip_trim_read();
//	chip_trim_default();
//	chip_retrim_writeback();
// 	while (1);

	// 检查芯片trim值，并读到寄存器去
	scall.fun = 0x4B;		
	scall.byte1 = 0x00;
	scall.byte2 = 0x00;
	scall.byte3 = 0x00;
	scall.byte4 = 0x00;
	scall.byte5 = 0x00;
	ret = chip_scall();		
	if (ret != 0)
	{			
		ret = 203;
		goto End;
	} 

	ret = chip_trim_read();
	if (ret != 0)
	{			
		ret = 204;
		goto End;
	}  	

End:
	if (ret != 0 && retry < MAX_RETRY_TIMES)
	{
		retry++;
		goto Start;
	}

	return ret;
}
   
unsigned char chip_pins_test(void)
{
	unsigned char i, reg, dat;
	unsigned short pinNo, rd_apin, tmp_apin;
	register unsigned char data;	

	fwi2c_write_register(CST0_REG_SFR, CST0_SP4MD0, 0x00);
	fwi2c_write_register(CST0_REG_SFR, CST0_SP4MD1, 0x00);

	fwi2c_write_register(CST0_REG_SFR, CST0_SP5MD0, 0x00);
	fwi2c_write_register(CST0_REG_SFR, CST0_SP5MD1, 0x00);

	fwi2c_write_register(CST0_REG_SFR, CST0_SP6MD0, 0x00);
	fwi2c_write_register(CST0_REG_SFR, CST0_SP6MD1, 0x00);

	fwi2c_write_register(CST0_REG_SFR, CST0_SP7MD0, 0x00);
	fwi2c_write_register(CST0_REG_SFR, CST0_SP7MD1, 0x00);

	fwi2c_write_register(CST0_REG_SFR, CST0_SP8MD0, 0x00);
	fwi2c_write_register(CST0_REG_SFR, CST0_SP8MD1, 0x00);

	rd_apin = 0x000;
	for (i = 0; i < EXPECTED_PIN_NUM; i++)
	{
		pinNo = dut_pinlist[i];
		reg = (pinNo >> 4) & 0xFF;
		dat = 1 << (pinNo & 0x007);
		tmp_apin = (rd_apin&0x003)|((rd_apin&0xffc)<<2);

		setAport(tmp_apin, STAT_RX);
		
		///(1)--------------------------
		setIDAC(IDAC_SRC, IDAC_128UA);
		fwi2c_write_register(CST0_REG_SFR, reg, ~dat&0xFF);
		fwi2c_write_register(CST0_REG_SFR, reg+1, 0x00);
		delay250us(1);
		data = getAPortVal(tmp_apin);
		if (data == 1)
		{
			setAport(tmp_apin, STAT_HIZ);
			return i+1; 
		}
		
		///(1)--------------------------
		setIDAC(IDAC_SNK, IDAC_128UA);
		fwi2c_write_register(CST0_REG_SFR, reg, dat);
		fwi2c_write_register(CST0_REG_SFR, reg+1, 0x00);
		delay250us(1);
		data = getAPortVal(tmp_apin);
		if (data == 0)
		{
			setAport(tmp_apin, STAT_HIZ);
			return i+101;
		}

		///(3)--------------------------
		CSD_SW_CR = 0x1f0;
		setIDAC(IDAC_SRC, IDAC_2UA);
		CSD_SW_CR = 0x190;
		delay250us(2);
		
		data = getAPortVal(tmp_apin);
		if(data==0)	
		{
			setAport(tmp_apin, STAT_HIZ);
			return 205;  //LOW leak test fail
		}
		
		///(4)--------------------------
		CSD_SW_CR = 0x1f0;
		setIDAC(IDAC_SNK, IDAC_2UA);
		CSD_SW_CR = 0x190;
		delay250us(2);

		data = getAPortVal(tmp_apin);
		if(data > 1) 
		{
			setAport(tmp_apin, STAT_HIZ);
			return 206;  //LOW leak test fail
		}
		
		setAport(tmp_apin, STAT_HIZ);

		rd_apin++;
	}

	fwi2c_write_register(CST0_REG_SFR, CST0_SP8MD0, 0x00);
	fwi2c_write_register(CST0_REG_SFR, CST0_SP8MD1, 0x00);
	
	return 0;
}

unsigned char chip_vref_test(void)
{
	unsigned char data;
	unsigned char ret = 0;	
	unsigned char retry = 0;

Start:	
    CSD_ICR       =  0x00;
    CSD_TX_DRV    =  0x20;   //set pump clock
    CSD_TX_CR     =  0x11;   //set hvsel, pumpen
    CSD_MODE   	 |=  0x030;  ///set const_cmp_en
    CSD_SW_CR     =  0x1F0;
    CSD_RX13_CR   = 0x100; //enable cmp
	setAport(CST148_RX13, STAT_RX);

    //output 1.5V
	fwi2c_write_register(CST0_REG_TRIM, 0x89, 0x84);

	CSD_VREF      =  0x10f;   //enable vref, ref_mid = 1.4v
 
	delay1ms(1);
	data = getAPortVal(CST148_RX13);
	if(data)
	{
		ret = 207;
		goto End;
	}
	
	CSD_VREF      =  0x00f;   //enable vref, ref_mid = 1.6v

	delay1ms(1);
	data = getAPortVal(CST148_RX13);
	if(data==0) 
	{
		ret = 208;
		goto End;
	}

End:
	//close output
	fwi2c_write_register(CST0_REG_TRIM, 0x89, 0x00);	
	setAport(CST148_RX13, STAT_HIZ);
	if (ret != 0 && retry < MAX_RETRY_TIMES)
	{
		retry++;
		goto Start;
	}
	
	return ret;
}

unsigned char chip_idac_test(void)
{
	unsigned char data, idac, bit;
	
	fwi2c_write_register(CST0_REG_SFR, CST0_CP1MD0, 0x01);
	fwi2c_write_register(CST0_REG_SFR, CST0_CP1MD1, 0x01);
	fwi2c_write_register(CST0_REG_SFR, CST0_CP1MD2, 0x01);
	
	fwi2c_write_register(CST0_REG_SFR, CST0_IDAC0CR, 0xC0);
	fwi2c_write_register(CST0_REG_SFR, CST0_IDAC0D, 0x20);		//32uA
	
    CSD_ICR       =  0x00;
    CSD_TX_DRV    =  0x20;   //set pump clock
    CSD_TX_CR     =  0x11;   //set hvsel, pumpen
    CSD_MODE   	 |=  0x030;  //set const_cmp_en
    CSD_RX13_CR    = 0x300;  //enable opa & cmp
	setAport(CST148_RX13, STAT_RX);

    idac = 0x20;
    for(bit=0x20; bit>0; bit>>=1)
    {
        idac |= bit;
		
		CSD_SW_CR = 0x1f0;
    	setIDAC(IDAC_SNK, idac);
    	CSD_SW_CR = 0x190;
    	delay250us(2);

		data = getAPortVal(CST148_RX13);

		if(data==0) idac &= ~bit;
    }

	fwi2c_write_register(CST0_REG_SFR, CST0_CP1MD0, 0x00);
	fwi2c_write_register(CST0_REG_SFR, CST0_CP1MD1, 0x00);
	fwi2c_write_register(CST0_REG_SFR, CST0_CP1MD2, 0x00);
	setAport(CST148_RX13, STAT_HIZ);
	
    return idac;
}

void delay_640us(void)
{
	unsigned short cnt;

	for (cnt = 0; cnt < 845; cnt++);	// adjust to 640us
}

/**
* 检测芯片频率，输出频率计数(8192=640us * 12.8MKZ),
* 需要将148芯片trim准，使得输出脉冲为640us左右
**/
unsigned short chip_freq_test(void)
{
	unsigned short freq_value;
	unsigned char cntL, cntH;

	fwi2c_write_register(CST0_REG_SFR, CST0_CP1MD0, 0x00);	
	fwi2c_write_register(CST0_REG_SFR, CST0_CP1MD1, 0x00);	
	fwi2c_write_register(CST0_REG_SFR, CST0_CP1MD2, 0x00);
	
	CSD_TX_DRV = 0x0007;
	CSD_TX_CR = 0x83;
	setAport(CST148_RX13, STAT_TX);
	
	CSD_EN = 0x00;		//set CP10 LOW	
		
	//enable extend pulse input to GDI[0]
	fwi2c_write_register(CST0_REG_SFR, CST0_CP1DIEN, 0x01);
	fwi2c_write_register(CST0_REG_SFR, CST0_CP1INS, 0x01);
	//set sys clk	
	fwi2c_write_register(CST0_REG_SFR, CST0_SCKCR0, 0x1F);	
	fwi2c_write_register(CST0_REG_SFR, CST0_SCKCR1, 0x01);	
	fwi2c_write_register(CST0_REG_SFR, CST0_SCKCR2, 0x32);		
	//set chained 16-bit-counter	
	fwi2c_write_register(CST0_REG_SFR, CST0_TM0CR, 0x46);  	//set tm0 as start 8-bit-counter
	fwi2c_write_register(CST0_REG_SFR, CST0_TM1CR, 0x4A);  	//set tm1 as end 8-bit-counter
	//set counter reg			
	fwi2c_write_register(CST0_REG_SFR, CST0_TM0PRD, 0xFF);	
	fwi2c_write_register(CST0_REG_SFR, CST0_TM1PRD, 0xFF);		
	//select GDI[0] as extend signal input	
	fwi2c_write_register(CST0_REG_SFR, CST0_TM0CFG, 0x80);	
	fwi2c_write_register(CST0_REG_SFR, CST0_TM1CFG, 0x80);		
	//sck1 as Counter 0/1 internal clk input	
	fwi2c_write_register(CST0_REG_SFR, CST0_TMCKCFG, 0x05);	
	
	//enable counter function	
	fwi2c_write_register(CST0_REG_SFR, CST0_TM0CR, 0x47);  	//only need enable TM0 since TM0/TM1 chained

	CSD_EN = 0x80;		//set CP10 HI	---> CST148's RX13	
	delay_640us();		//640us	----> counter=8192=12.8MHz * 640us 
	CSD_EN = 0x00;		//set CP10 LOW 	
	
	fwi2c_write_register(CST0_REG_SFR, CST0_TM0CR, 0xC6);	
	
	fwi2c_read_register(CST0_REG_SFR, CST0_TM0PRD, &cntL);	
	fwi2c_read_register(CST0_REG_SFR, CST0_TM1PRD, &cntH);

	setAport(CST148_RX13, STAT_HIZ);
	
	freq_value = cntH;
	freq_value <<= 8;
	freq_value |= cntL;
	
	return freq_value;
}

unsigned char chip_retrim_freq(void)
{
	unsigned short freq_cnt;
	unsigned char mask, good, tmp;
	unsigned char status;
	
	good = 0;
	tmp = 0x80;
	mask = 0x80;
	status = 0;
	while (1)
	{
		fwi2c_write_register(CST0_REG_TRIM, 0xBD, tmp);
		freq_cnt = chip_freq_test();
		if (freq_cnt > 8220)	
		{
			if (status == 2)
			{
				mask <<= 1;
			}
			tmp &= ~mask;
			status = 1;
		}
		else if (freq_cnt < 8160)
		{
			tmp |= mask;
			status = 2;
		}
		else 
		{
			good = 1;
		}

		if (good == 1 || mask == 1)
			break;
		mask >>= 1;
	}

	if (good == 1)
	{
		unsigned char ret;	
		// 将 trim 后的 IMO 值写入并检验是否真正写入了	
		g_trim_data[11] = tmp;
		ret = chip_retrim_writeback();
		if (ret != 0)
			return 1;
		else 
			return 0;
	} 

	return 1;	
}

unsigned char MTPWD[256];
const unsigned char MTP1[64]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,
		0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,
		0x14,0x15,0x16,0x17,0x18,0x19,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,
		0x20,0x21,0x22,0x23,0x24,0x25,0x26,0x27,0x28,0x29,0x2A,0x2B,
		0x2C,0x2D,0x2E,0x2F,0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,
		0x38,0x39,0x3A,0x3B,0x3C,0x3D,0x3E,0x3F};
const unsigned char MTPS[8]={0x7F,0xBF,0xDF,0xEF,0xF7,0xFB,0xFD,0xFE};
//	MTP write 0xFF test
unsigned char chip_mtp_write_test(void)
{  
	unsigned char ret;	
	int j, k, k1;

	memset(MTPWD, 0xFF, 256);

	// set erase timing parameter
	ret = time_parameters_set();
	if (ret != 0)
		return 233;

	// Erase all
	scall.fun = CMD_NVM_CLRALL;
	scall.byte1 = 0x00;
	scall.byte2 = 0x00;
	scall.byte3 = 0x00;
	scall.byte4 = 0x00;
	scall.byte5 = 0x00;
	ret = chip_scall();
	if (ret != 0)
		return 234;	  

	k=0;k1=0;
	for(j=0;j<64;j++)
	{ 
		MTPWD[127]=MTPS[k1];
		ret = fwi2c_write_registers(CST0_REG_IDATA,0x70,&MTPWD[k],128);
		if (ret != 0)
			return 235;

		k=k+1;
		k1=k1+1;

		scall.fun = CMD_NVM_WRITE;
		scall.byte1 = 0x7F;
		scall.byte2 = 0x00;
		scall.byte3 = MTP1[j];
		scall.byte4 = 0x70;
		scall.byte5 = 0x00;
		ret = chip_scall();
		if (ret != 0)
			return 236;
				 
		MTPWD[127]=MTPS[k1];
		ret = fwi2c_write_registers(CST0_REG_IDATA,0x70,&MTPWD[k],128);
		if (ret != 0)
			return 237;

		k=k+1;
		k1=k1+1;	

		scall.fun = CMD_NVM_WRITE;
		scall.byte1 = 0x7F;
		scall.byte2 = 0x80;
		scall.byte3 = MTP1[j];
		scall.byte4 = 0x70;
		scall.byte5 = 0x00;
		ret = chip_scall();
		if (ret != 0)
			return 238;
								
		if(k1==8){k1=0;}
  	}  

	scall.fun = CMD_NVM_CHKSUM;
	scall.byte1 = 0x7F;
	scall.byte2 = 0x00;
	scall.byte3 = 0x00;
	scall.byte4 = 0x00;
	scall.byte5 = 0x00;
	ret = chip_scall();
	if (ret != 0)
		return 239;

   /// byte2 store checksum low byte,  byte3 store high byte
	if (scall.byte1 != 0x7F)
		return 240;
	if (scall.byte2 != 0x00)
		return 241;
	if (scall.byte3 != 0x40)
		return 242;	

	return 0;

}

unsigned char LHIASICPE(unsigned char partName)
{
	unsigned int j; //0: read checksum/block; 1: calc checksum/block;  2 whole checksum/calc 3 whole checksum/read
	unsigned int  Bindex=0,EEBindex;
	unsigned char ret;

	// set erase timing parameter
	ret = time_parameters_set();
	if (ret != 0)
		return 211;

	// Erase all
	scall.fun = CMD_NVM_CLRALL;
	ret = chip_scall();
	scall.byte1 = 0x00;
	scall.byte2 = 0x00;
	scall.byte3 = 0x00;
	scall.byte4 = 0x00;
	scall.byte5 = 0x00;
	if (ret != 0)
		return 212;

	Bindex = 0;
	for(j = 0; j < 4; j++)
	{
		EEBindex=Bindex*128;			
		ret = fwi2c_write_registers(CST0_REG_IDATA, 0x70, (unsigned char *)&DUT_NVM[EEBindex], 128);
		if (ret != 0)
			return 213;	

		scall.fun = CMD_NVM_WRITE;
		scall.byte1 = 0x7F;
		scall.byte2 = 0x00;
		scall.byte3 = j;
		scall.byte4 = 0x70;
		scall.byte5 = 0x00;
		ret = chip_scall();
		if (ret != 0)
			return 214;		
		
		Bindex=Bindex+1;
		EEBindex=Bindex*128;
		ret = fwi2c_write_registers(CST0_REG_IDATA, 0x70, (unsigned char *)&DUT_NVM[EEBindex], 128);
		if (ret != 0)
			return 215;
				
		scall.fun = CMD_NVM_WRITE;
		scall.byte1 = 0x7F;
		scall.byte2 = 0x80;
		scall.byte3 = j;
		scall.byte4 = 0x70;
		scall.byte5 = 0x00;
		ret = chip_scall();
		if (ret != 0)
			return 216;
		
		Bindex=Bindex+1;
	}

	scall.fun = CMD_NVM_SEGSET;
	scall.byte1 = 0x20;
	scall.byte2 = 0x00;
	scall.byte3 = 0x00;
	scall.byte4 = 0xFF;
	scall.byte5 = 0x03;
	ret = chip_scall();
	if (ret != 0)
		return 217;	

	scall.fun = CMD_NVM_SEGSET;
	scall.byte1 = 0x11;
	scall.byte2 = 0x00;
	scall.byte3 = 0x04;
	scall.byte4 = 0xFF;
	scall.byte5 = 0x10;
	ret = chip_scall();
	if (ret != 0)
		return 217;

	scall.fun = CMD_NVM_SEGSET;
	scall.byte1 = 0x12;
	scall.byte2 = 0x00;
	scall.byte3 = 0x11;
	scall.byte4 = 0xFF;
	scall.byte5 = 0x15;
	ret = chip_scall();
	if (ret != 0)
		return 217;

	scall.fun = CMD_NVM_SEGSET;
	scall.byte1 = 0x13;
	scall.byte2 = 0x00;
	scall.byte3 = 0x16;
	scall.byte4 = 0xFF;
	scall.byte5 = 0x1A;
	ret = chip_scall();
	if (ret != 0)
		return 217;

	scall.fun = CMD_NVM_SEGSET;
	scall.byte1 = 0x14;
	scall.byte2 = 0x00;
	scall.byte3 = 0x1B;
	scall.byte4 = 0xFF;
	scall.byte5 = 0x1F;
	ret = chip_scall();
	if (ret != 0)
		return 217;

	scall.fun = CMD_NVM_SEGSET;
	scall.byte1 = 0x15;
	scall.byte2 = 0x00;
	scall.byte3 = 0x20;
	scall.byte4 = 0xFF;
	scall.byte5 = 0x40;
	ret = chip_scall();
	if (ret != 0)
		return 217;

	scall.fun = CMD_NVM_CHKSUM;
	scall.byte1 = 0x07;
	scall.byte2 = 0x00;
	scall.byte3 = 0x00;
	scall.byte4 = 0x00;
	scall.byte5 = 0x00;
	ret = chip_scall();
	if (ret != 0)
		return 218;
	if (scall.byte1 != 0x07)
		return 219;
	if (scall.byte2 != 0xD6)
		return 220;
	if (scall.byte3 != 0x43)
		return 221;	

	return 0;
}


//----------------------------------test code-------------------------------------------

void chip_trim_default(void)
{ 
	const unsigned char idata[64] =  {
	0x09,0x41,0x00,0x14,0x00,0x0C,0x00,0x01,
	0x00,0x00,0x30,0x8D,0x00,0x00,0xB5,0x7A,
	0x10,0x0C,0x1D,0x53,0x00,0x08,0x43,0x21,
	0x43,0x48,0x39,0x52,0x32,0x00,0x18,0x3A,
	0xEC,0x34,0x59,0x35,0xC3,0x35,0x22,0x36,
	0x99,0x36,0x02,0x37,0x82,0x37,0xF9,0x37,
	0x7D,0x38,0xF6,0x38,0x84,0x39,0x01,0x3A,			
	0xA1,0x3A,0x1F,0x3B,0xB8,0x3B,0x0D,0xF5			 	
	};
	unsigned char i;

	for (i = 0; i < 64; i++)
		g_trim_data[i] = idata[i];
}

//this function is only for test if the IC not trimed
unsigned char chip_trim_init(void)
{
	fwi2c_write_register(CST0_REG_TRIM, 0xBD, 0x00);		///debug

	return 0;
}

void trim_delay_640us(void)
{
	CSD_TX_DRV = 0x0007;
	CSD_TX_CR = 0x83;
	setAport(CST148_RX13, STAT_TX);
	
	CSD_EN = 0x00;		//set CP10 LOW	
	while(1)
	{
		CSD_EN = 0x80;		//set CP10 HI	---> CST148's RX13	
		delay_640us();		//640us	----> counter=8192=12.8MHz * 640us 
		CSD_EN = 0x00;		//set CP10 LOW 	
		delay_640us();
	}
}


unsigned short chip_freq_output_test(void)
{
	unsigned short cmpo = 0;

	//fwi2c_write_register(CST0_REG_SFR, 0xFC, 0x02);

	fwi2c_write_register(CST0_REG_SFR, 0x89, 0x00);		// select sysclk
	//fwi2c_write_register(CST0_REG_SFR, 0x94, 0xFF);	// 25.6MHZ / (0xFF+1) = 100KHZ
	//fwi2c_write_register(CST0_REG_SFR, 0x9C, 0x3F);
	
	//fwi2c_write_register(CST0_REG_SFR, 0x94, 0x09);		// 25.6MHZ / (0x09+1) = 2.56MHZ
	//fwi2c_write_register(CST0_REG_SFR, 0x9C, 0x04);

	fwi2c_write_register(CST0_REG_SFR, 0x94, 0x63);		// 25.6MHZ / (0x63+1) = 0.256MHZ
	fwi2c_write_register(CST0_REG_SFR, 0x9C, 0x31);
	
	fwi2c_write_register(CST0_REG_SFR, 0xBB, 0x01);
	fwi2c_write_register(CST0_REG_SFR, 0xBC, 0x01);
	fwi2c_write_register(CST0_REG_SFR, 0xBD, 0x00);
	fwi2c_write_register(CST0_REG_SFR, 0xBF, 0x00);
	
	fwi2c_write_register(CST0_REG_SFR, 0xAC, 0x04);
	fwi2c_write_register(CST0_REG_SFR, 0x8C, 0x21);

	//fwi2c_write_register(CST0_REG_SFR, 0x8C, 0x00);
	

	delay1ms(1);
	//while(1);
	
	return cmpo;

}





















