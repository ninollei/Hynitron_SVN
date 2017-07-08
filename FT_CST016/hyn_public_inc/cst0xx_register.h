
#ifndef __CST0XX_REGISTER_H__
#define _CST0XX_REGISTER_H__

//Memory Type 
#define CST0_REG_XDATA  		0x00
#define CST0_REG_IDATA  		0x01
#define CST0_REG_SFR    		0x02
#define CST0_REG_TRIM   		0x03

//scall function cmd
#define SCALL_ADDR				0xF4
#define CMD_NVM_READ       		0xF0
#define CMD_NVM_WRITE       	0xE1
#define CMD_NVM_CHKSUM      	0xD2
#define CMD_NVM_ID_READ     	0xC3
#define CMD_NVM_SEGSET      	0xB4
#define CMD_IRST            	0x87
#define CMD_NVM_CLRALL      	0x78
#define CMD_WRITE_ALL       	0x69
#define CMD_MEM_TEST        	0x0F
#define CMD_NVM_CLEAR_BLOCK 	0x96
#define CMD_WRITE_TRIM_TBL  	0x5A

#define TMP_REG    				0x80
#define ADDR_TABLE				0x90
#define TABLE_12				ADDR_TABLE
#define TABLE_13				TABLE_12+0x08
#define TABLE_14				TABLE_13+0x08
#define TABLE_15				TABLE_14+0x08
#define TABLE_16				TABLE_15+0x08
#define TABLE_17				TABLE_16+0x08
#define TABLE_18				TABLE_17+0x08
#define TABLE_19				TABLE_18+0x08


//GPIO 可编程输入输出管脚
#define CST0_CP1DR				0xB8
#define CST0_CP1IE				0xB9
#define CST0_CP1INS				0xBA
#define CST0_CP1DS				0xBB
#define CST0_CP1MD0				0xBC
#define CST0_CP1MD1				0xBD
#define CST0_CP1MD2				0xBE
#define CST0_CP1DIEN			0xBF
#define CST0_CP1CHSEL			0x11		///XDM

//SnsIO 电容检测专用管脚
#define CST0_SP4CHSEL			0x14		///XDM
#define CST0_SP4DR				0x20
#define CST0_SP4MD0				0x21		
#define CST0_SP4MD1				0x22

#define CST0_SP5CHSEL			0x15		///XDM
#define CST0_SP5DR				0x28
#define CST0_SP5MD0				0x29		
#define CST0_SP5MD1				0x2A

#define CST0_SP6CHSEL			0x16		///XDM
#define CST0_SP6DR				0x30
#define CST0_SP6MD0				0x31		
#define CST0_SP6MD1				0x32

#define CST0_SP7CHSEL			0x17		///XDM
#define CST0_SP7DR				0x38
#define CST0_SP7MD0				0x39		
#define CST0_SP7MD1				0x3A

#define CST0_SP8CHSEL			0x18		///XDM
#define CST0_SP8DR				0x40
#define CST0_SP8MD0				0x41		
#define CST0_SP8MD1				0x42

//CLOCK
#define CST0_SCKCR0				0xF2
#define CST0_SCKCR1				0xF3
#define CST0_SCKCR2				0xFC

//Global input and output
#define CST0_GDOSEL0			0xAC
#define CST0_GDOSEL1			0xAD
#define CST0_GDOSEL2			0xAE
#define CST0_GDOSEL3			0xAF
#define CST0_GDOINV				0xAB

//CDC
#define CST0_VDBCR1				0xE5
#define CST0_IDAC0CR			0xF4
#define CST0_IDAC1CR			0xF6
#define CST0_IDAC0D				0xF5
#define CST0_IDAC1D				0xF7

//Timer and Counter
#define CST0_TMCKCFG			0x89
#define CST0_TM0CR				0x8C
#define CST0_TM1CR				0x8D
#define CST0_TM2CR				0x8E
#define CST0_TM3CR				0x8F
#define CST0_TM0PRD				0x94
#define CST0_TM1PRD				0x95
#define CST0_TM2PRD				0x96
#define CST0_TM3PRD				0x97
#define CST0_TM0CMPV			0x9C
#define CST0_TM1CMPV			0x9D
#define CST0_TM2CMPV			0x9E
#define CST0_TM3CMPV			0x9F
#define CST0_TM0CFG				0xA4
#define CST0_TM1CFG				0xA5
#define CST0_TM2CFG				0xA6
#define CST0_TM3CFG				0xA7
#define CST0_TMIE				0x8B
#define CST0_TMIS				0x88

#define CST0_IE					0xA8

#define	CST0_INTMSK0			0xA9
#define	CST0_INTMSK1			0xAA

#define CST0_INTSTT0			0x90
#define CST0_INTSTT1			0x91


#endif



