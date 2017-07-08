
#include "all_includes.h"

void fwi2c_init(void)
{
   	fwi2c_set1_sda;

	///open drain low 
	IOD0_DM2 |= DUT_SWD;
	IOD0_DM1 |= DUT_SWD;
	IOD0_DM0 |= DUT_SWD;
	
}

void fwi2c_dly(void)
{
	unsigned short i;

	for(i=0;i<5;i++);	///about 5us
}

void fwi2c_w0(void)
{
	fwi2c_set0_sda;
	fwi2c_set0_scl;
	fwi2c_set1_scl;
	fwi2c_set0_scl;
}

void fwi2c_w1(void)
{
	fwi2c_set1_sda;
	fwi2c_set0_scl;
	fwi2c_set1_scl;
	fwi2c_set0_scl;	
}

void fwi2c_start(void)
{
	fwi2c_set1_sda;
	fwi2c_dly();
	fwi2c_set1_scl;
	fwi2c_dly();//建立时间是I2C_SDA保持时间>4.7us
	fwi2c_set0_sda;
	fwi2c_dly();//保持时间是>4us
	fwi2c_set0_scl;
	fwi2c_dly();               
}


void fwi2c_stop(void)
{
    fwi2c_set0_sda;
    fwi2c_dly();
    fwi2c_set1_scl;
    fwi2c_dly();//建立时间大于4.7us
    fwi2c_set1_sda;
    fwi2c_dly();               
}


unsigned char fwi2c_sendBytes(unsigned char *buf, unsigned short num)
{
	unsigned char dat;
	unsigned char a;//最大255，一个机器周期为1us，最大延时255us。
	unsigned short i;
	unsigned int b;

	for (i = 0; i < num; i++)
	{
		dat = buf[i];
		for(a=0; a<8; a++)//要发送8位，从最高位开始
		{
	        if (dat & 0x80)	fwi2c_set1_sda;
			else			fwi2c_set0_sda;
	        dat = dat << 1;
	        fwi2c_dly();
	        fwi2c_set1_scl;
	        fwi2c_dly();//建立时间>4.7us
	        fwi2c_set0_scl;
	        fwi2c_dly();//时间大于4us               
		}

		fwi2c_set1_sda;
		fwi2c_dly();
		fwi2c_dly();
		fwi2c_set1_scl;
		fwi2c_dly();
		
		b = 0;
		while(fwi2c_get_sda)//等待应答，也就是等待从设备把I2C_SDA拉低
		{
	        b++;
	        if(b > 0x9FFF8)         //如果超过1s 没有应答发送失败，或者为非应答，表示接收结束
	        {
	            fwi2c_set0_scl;
	            fwi2c_dly();
	            return 1;
	        }			
		}
		
		fwi2c_dly();
		fwi2c_set0_scl;
		fwi2c_dly();
		fwi2c_dly();
	}
	
	return 0;               
}


void fwi2c_getBytes(unsigned char *buf, unsigned short num, unsigned char stopNum)
{
	register unsigned char bitCnt, rec;
	unsigned short idx;
	unsigned char* pdata = buf;

	for(idx=0; idx<num; idx++)
	{
		rec = 0;
		bitCnt = 0x80;
		while(bitCnt) {
			fwi2c_set0_scl; 
			fwi2c_dly();
			
			rec    <<= 1;
			bitCnt >>= 1;
			
			fwi2c_set1_scl; 
			fwi2c_dly();
			
	        if(fwi2c_get_sda) rec |= 0x01;
		}
		
		fwi2c_set0_scl;
		fwi2c_dly();
		
		if(idx==stopNum)    fwi2c_set1_sda;  //NAK
        else                fwi2c_set0_sda;  //ACK
		fwi2c_dly();
		
		*pdata = rec;
		
		fwi2c_set1_scl; 
		fwi2c_dly();
		pdata++;

		fwi2c_set0_scl; 				
		fwi2c_dly();
		fwi2c_set1_sda; 
		fwi2c_dly();
		fwi2c_dly();
	}  
	
}

unsigned char fwi2c_write_register(unsigned char type, unsigned short reg, unsigned char data)
{
	unsigned char tmp[2];
	unsigned char ret;

	tmp[0] = type << 1;
	tmp[1] = reg >> 6;

	fwi2c_start();
	ret = fwi2c_sendBytes(tmp, 2);
	fwi2c_stop();
	if (ret != 0)
		return 0x01;

	tmp[0] = ((reg & 0x3F) << 1) | 0x80;
	tmp[1] = data;	

	fwi2c_start();
	ret = fwi2c_sendBytes(tmp, 2);
	fwi2c_stop();
	if (ret != 0)
		return 0x02;

	return 0;
}

unsigned char fwi2c_read_register(unsigned char type, unsigned short reg, unsigned char *data)
{
	unsigned char tmp[2];
	unsigned char ret;

	tmp[0] = type << 1;
	tmp[1] = reg >> 6;

	fwi2c_start();
	ret = fwi2c_sendBytes(tmp, 2);
	fwi2c_stop();
	if (ret != 0)
		return 0x01;

	tmp[0] = ((reg & 0x3F) << 1) | 0x81;	

	fwi2c_start();
	ret = fwi2c_sendBytes(tmp, 1);
	if (ret != 0)
	{
		fwi2c_stop();
		return 0x02;
	}
	fwi2c_getBytes(data, 1, 0);
	fwi2c_stop();	

	return 0;
}



unsigned char fwi2c_write_registers(unsigned char type, unsigned char start_reg,
	unsigned char *src, unsigned short len)
{	
	unsigned char ret;
	unsigned char ptr[2];

	ptr[0] = type << 1;
	ptr[1] = start_reg >> 6;

	fwi2c_start();
	ret = fwi2c_sendBytes(ptr, 2);
	fwi2c_stop();
	if (ret != 0)
	{
		return 1;
	}

	ptr[0] = ((start_reg & 0x3F) << 1) | 0x80;
	fwi2c_start();
	ret = fwi2c_sendBytes(ptr, 1);		
	if (ret != 0)
	{
		fwi2c_stop();
		return 1;
	}
	ret = fwi2c_sendBytes(src, len);
	fwi2c_stop();
	if (ret != 0)
	{
		return 1;
	}

	return 0;	
}

unsigned char fwi2c_read_registers(unsigned char type, unsigned char start_reg,
	unsigned char *dst, unsigned short len)
{
	unsigned char ret;
	unsigned char tmp[2];
	
	tmp[0] = type << 1;
	tmp[1] = start_reg >> 6;	
	fwi2c_start();
	ret = fwi2c_sendBytes(tmp, 2);
	fwi2c_stop();
	if (ret != 0)
		return 1;
	
	tmp[0] = ((start_reg & 0x3F) << 1) | 0x81;
	fwi2c_start();
	ret = fwi2c_sendBytes(tmp, 1);
	if (ret != 0)
	{
		fwi2c_stop();
		return ret;
	}
	fwi2c_getBytes(dst, len, len-1);
	fwi2c_stop();	

	return 0;
}







