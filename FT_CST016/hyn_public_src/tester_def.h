

#define FT_CST016          0x0160

#define FT_IC_TYPE         FT_CST016

#define FT_IC_TRIMMED      1


//------------------------------------------------------
#define EXPECTED_CHKSUM  			0x28083B5C	//0x2682015A
#define EXPECTED_RESULT_CODE		0xCACAA5A5

#if (FT_IC_TYPE == FT_CST016)
	#define EXPECTED_PIN_NUM		(15)
	#define EXPECTED_PARTNO			(0xCACA0160)
	#define EXPECTED_I2CCFG			(0x00000000)
	#define EXPECTED_PIN_LIST       CST016_PIN_LIST
	#define IIC_PIN                 (0x0C)	
#else
	#define EXPECTED_PIN_NUM		(0)
	#define EXPECTED_PARTNO			(0x00000000)
	#define EXPECTED_I2CCFG			(0x00000000)
	#define EXPECTED_PIN_LIST       CST1XX_PIN_LIST
	#define IIC_PIN                 (0x0C)
#endif

#define MAX_RETRY_TIMES	   1

#define MAX_AVAIL_APINS    44

#define STAT_HIZ           0
#define STAT_LOW           1
#define STAT_RX            2
#define STAT_TX            3

#define IDAC_SRC           0
#define IDAC_SNK           1
#define IDAC_128UA         0xff
#define IDAC_2UA	       0x02

#define FWI2C_ADDR 		   0x1A

#define cnt1ms    			REG32(0x20000800)

#define IDCODE      		0x0bb11477 

#define DUT_XRES            CST148_RX14
#define DUT_SWCLK           CST148_RX15
#define DUT_SWD             CST148_IRQ
#define DUT_DPORT_RDAPIN    CST148_RX13

#define swd_cycle_wait  CSD_TITO = 0x00 
#define	fwi2c_set1_scl  (IOA11_PD &= ~0x08) 
#define fwi2c_set0_scl  (IOA11_PD |=  0x08)
#define fwi2c_set1_sda  (IOD0_DR  |=  DUT_SWD) 
#define fwi2c_set0_sda  (IOD0_DR  &= ~DUT_SWD)
#define fwi2c_get_sda   (IOD0_DR&DUT_SWD)



#define ROM0_ADDR_BASE           (0x00000000)
#define ROM0_ADDR_END            (ROM0_ADDR_BASE+24*1024) //24k
#define ROM0_CODE_LEN            (ROM0_ADDR_END-ROM0_ADDR_BASE-4)
#define ROM0_ADDR_CHECKSUM       (ROM0_ADDR_END-4)

#define ROM1_ADDR_BASE           (ROM0_ADDR_END)
#define ROM1_ADDR_END            (ROM1_ADDR_BASE+6*1024)  //6k
#define ROM1_CODE_LEN            (ROM1_ADDR_END-ROM1_ADDR_BASE-4)
#define ROM1_ADDR_CHECKSUM       (ROM1_ADDR_END-4)

#define RAM_ADDR_BASE            (0x20000000)
#define RAM_ADDR_END             (RAM_ADDR_BASE+4*1024)   //4k
#define RAM_ADDR_UPDATE_KEY      (RAM_ADDR_END-4)  
#define RAM_ADDR_RESET_KEY       (RAM_ADDR_END-8)  
#define RAM_ADDR_ROM0_CHKSUM     (RAM_ADDR_END-12) 
#define RAM_ADDR_ROM1_BIST       (RAM_ADDR_END-16)


