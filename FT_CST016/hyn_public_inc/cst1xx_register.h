
#ifndef __CST1XX_REGISTER_H__
#define __CST1XX_REGISTER_H__
//-----------------------------------------------------------
#define SCR_BASE 		    0x40080000
	
#define SCR_CFG            REG32(SCR_BASE + 0x00)
#define SCR_CALI           REG32(SCR_BASE + 0x04)
#define SCR_ID             REG32(SCR_BASE + 0x08)
#define SCR_SCB_CR         REG32(SCR_BASE + 0x0C)
	
#define SCR_XRES_CR        REG32(SCR_BASE + 0x10)
#define POR_CR             REG32(SCR_BASE + 0x20)

#define SCR_MISR_DR        REG32(SCR_BASE + 0x40)
#define SCR_MISR_CR        REG32(SCR_BASE + 0x44)
#define SCR_DFT_CR         REG32(SCR_BASE + 0x48)
	
#define SCR_HCLK_CR        REG32(SCR_BASE + 0xC0)
#define SCR_PCLK_CR        REG32(SCR_BASE + 0xC4)
#define SCR_PCLK_DIV0      REG32(SCR_BASE + 0xC8)
#define SCR_PCLK_DIV1      REG32(SCR_BASE + 0xCC)
	
//-----------------------------------------------------------
#define EEP_CR_BASE        0x40080100
	
#define EEP_CR               REG32(EEP_CR_BASE + 0x00)	
#define EEP_KEY              REG32(EEP_CR_BASE + 0x04)	
#define EEP_AD               REG32(EEP_CR_BASE + 0x08)	
#define EEP_DR               REG32(EEP_CR_BASE + 0x0C)	
#define EEP_BURST_AD         REG32(EEP_CR_BASE + 0x10)	
#define EEP_TEST             REG32(EEP_CR_BASE + 0x14)	
#define EEP_TRIM             REG32(EEP_CR_BASE + 0x18)	

//-----------------------------------------------------------
#define SLP_BASE           0x40080200
	
#define SLPTIM_CR             REG32(SLP_BASE + 0x00)
#define SLPTIM_STAT           REG32(SLP_BASE + 0x04)
#define SLPTIM_CLR            REG32(SLP_BASE + 0x08)
#define SLPTIM_CNT            REG32(SLP_BASE + 0x0C)
#define SLPTIM_WDT            REG32(SLP_BASE + 0x10)
#define SLPTIM_ACC_CR         REG32(SLP_BASE + 0x14)
	
//-----------------------------------------------------------
#define ANA_BASE 		   0x40080300
	
#define LDO_CR           REG32(ANA_BASE + 0x68) 
#define LDO_TRIM         REG32(ANA_BASE + 0x6C) 
#define IMO_CR           REG32(ANA_BASE + 0x70) 
#define IMO_TRIM         REG32(ANA_BASE + 0x74) 
#define ILO_CR           REG32(ANA_BASE + 0x78) 
#define ILO_TRIM         REG32(ANA_BASE + 0x7C) 
	
#define CSD_TX_CR       REG32(ANA_BASE + 0x80) 
#define CSD_TX_DRV      REG32(ANA_BASE + 0x84) 
#define CSD_TX_DFT      REG32(ANA_BASE + 0x8C) 
//-----------------------------------------------------------
#define IOA0_BASE 	   0x40081000
	
#define IOA0_PD           REG32(IOA0_BASE + 0x00)	
#define IOA0_TXM          REG32(IOA0_BASE + 0x04)	
#define IOA0_RXM0         REG32(IOA0_BASE + 0x08)	
#define IOA0_RXM1         REG32(IOA0_BASE + 0x0C)	
//------------------------------------------------------
#define IOA1_BASE 	   0x40081010
	
#define IOA1_PD           REG32(IOA1_BASE + 0x00)	
#define IOA1_TXM          REG32(IOA1_BASE + 0x04)	
#define IOA1_RXM0         REG32(IOA1_BASE + 0x08)	
#define IOA1_RXM1         REG32(IOA1_BASE + 0x0C)	
//------------------------------------------------------
#define IOA2_BASE 	   0x40081020
	
#define IOA2_PD           REG32(IOA2_BASE + 0x00)	
#define IOA2_TXM          REG32(IOA2_BASE + 0x04)	
#define IOA2_RXM0         REG32(IOA2_BASE + 0x08)	
#define IOA2_RXM1         REG32(IOA2_BASE + 0x0C)	
//------------------------------------------------------
#define IOA3_BASE 	   0x40081030
	
#define IOA3_PD           REG32(IOA3_BASE + 0x00)	
#define IOA3_TXM          REG32(IOA3_BASE + 0x04)	
#define IOA3_RXM0         REG32(IOA3_BASE + 0x08)	
#define IOA3_RXM1         REG32(IOA3_BASE + 0x0C)	
//------------------------------------------------------
#define IOA4_BASE 	   0x40081040
	
#define IOA4_PD           REG32(IOA4_BASE + 0x00)	
#define IOA4_TXM          REG32(IOA4_BASE + 0x04)	
#define IOA4_RXM0         REG32(IOA4_BASE + 0x08)	
#define IOA4_RXM1         REG32(IOA4_BASE + 0x0C)	
//------------------------------------------------------
#define IOA5_BASE 	   0x40081050	
	
#define IOA5_PD           REG32(IOA5_BASE + 0x00)	
#define IOA5_TXM          REG32(IOA5_BASE + 0x04)	
#define IOA5_RXM0         REG32(IOA5_BASE + 0x08)	
#define IOA5_RXM1         REG32(IOA5_BASE + 0x0C)	
//------------------------------------------------------
#define IOA6_BASE 	   0x40081060
	
#define IOA6_PD           REG32(IOA6_BASE + 0x00)	
#define IOA6_TXM          REG32(IOA6_BASE + 0x04)	
#define IOA6_RXM0         REG32(IOA6_BASE + 0x08)	
#define IOA6_RXM1         REG32(IOA6_BASE + 0x0C)	
//------------------------------------------------------
#define IOA7_BASE 	   0x40081070	
	
#define IOA7_PD           REG32(IOA7_BASE + 0x00)	
#define IOA7_TXM          REG32(IOA7_BASE + 0x04)	
#define IOA7_RXM0         REG32(IOA7_BASE + 0x08)	
#define IOA7_RXM1         REG32(IOA7_BASE + 0x0C)	
	
//------------------------------------------------------
#define IOA8_BASE 	   0x40081080	
	
#define IOA8_PD           REG32(IOA8_BASE + 0x00)	
#define IOA8_TXM          REG32(IOA8_BASE + 0x04)	
#define IOA8_RXM0         REG32(IOA8_BASE + 0x08)	
#define IOA8_RXM1         REG32(IOA8_BASE + 0x0C)	
//------------------------------------------------------
#define IOA9_BASE 	   0x40081090	
	
#define IOA9_PD           REG32(IOA9_BASE + 0x00)	
#define IOA9_TXM          REG32(IOA9_BASE + 0x04)	
#define IOA9_RXM0         REG32(IOA9_BASE + 0x08)	
#define IOA9_RXM1         REG32(IOA9_BASE + 0x0C)	
//------------------------------------------------------
#define IOA10_BASE 	   0x400810A0
	
#define IOA10_PD          REG32(IOA10_BASE + 0x00)	
#define IOA10_TXM         REG32(IOA10_BASE + 0x04)	
#define IOA10_RXM0        REG32(IOA10_BASE + 0x08)	
#define IOA10_RXM1        REG32(IOA10_BASE + 0x0C)	
//------------------------------------------------------
#define IOA11_BASE 	   0x400810B0	
	
#define IOA11_PD          REG32(IOA11_BASE + 0x00)	
#define IOA11_TXM         REG32(IOA11_BASE + 0x04)	
#define IOA11_RXM0        REG32(IOA11_BASE + 0x08)	
#define IOA11_RXM1        REG32(IOA11_BASE + 0x0C)	

//4 dport pins
#define IOD_BASE       0x40081FC0
	
#define IOD0_DR          REG32(IOD_BASE + 0x00)	
#define IOD0_GIE         REG32(IOD_BASE + 0x04)	
#define IOD0_GOE         REG32(IOD_BASE + 0x08)	
#define IOD0_DM0         REG32(IOD_BASE + 0x0C)	
#define IOD0_DM1         REG32(IOD_BASE + 0x10)	
#define IOD0_DM2         REG32(IOD_BASE + 0x14)	
#define IOD0_IE          REG32(IOD_BASE + 0x18)	
#define IOD0_IC0         REG32(IOD_BASE + 0x1C)	
#define IOD0_IC1         REG32(IOD_BASE + 0x20)	
#define IOD0_FLAG        REG32(IOD_BASE + 0x24)	

//-----------------------------------------------------------
#define CSD_BASE 	      0x40082000
	
#define CSD_EN        REG32(CSD_BASE + 0x000)	
#define CSD_MODE      REG32(CSD_BASE + 0x004)	
#define CSD_STAT      REG32(CSD_BASE + 0x008)	
#define CSD_NSCAN     REG32(CSD_BASE + 0x00C)	
#define CSD_TRES      REG32(CSD_BASE + 0x010)	
#define CSD_TITO      REG32(CSD_BASE + 0x014)	
#define CSD_TANA      REG32(CSD_BASE + 0x018)	
#define CSD_TBL       REG32(CSD_BASE + 0x01C)	
#define CSD_SYNC      REG32(CSD_BASE + 0x020)	
#define CSD_SHIELD    REG32(CSD_BASE + 0x028)	
#define CSD_VREF      REG32(CSD_BASE + 0x02C)	
#define CSD_ICR       REG32(CSD_BASE + 0x030)	
#define CSD_IBL       REG32(CSD_BASE + 0x034)	
#define CSD_IMS       REG32(CSD_BASE + 0x038)	
#define CSD_TRIM      REG32(CSD_BASE + 0x03C)	
	
#define CSD_NX_CFG    REG32(CSD_BASE + 0x040)	
#define CSD_NX_TMO    REG32(CSD_BASE + 0x044)	
#define CSD_NX_STAT   REG32(CSD_BASE + 0x048)	
#define CSD_PRS_CR    REG32(CSD_BASE + 0x04C)	

#define CSD_BURST_SEQ REG32(CSD_BASE + 0x050)	
#define CSD_RX_SEQL   REG32(CSD_BASE + 0x050)	
#define CSD_RX_SEQH   REG32(CSD_BASE + 0x054)	
#define CSD_BURST_AD  REG32(CSD_BASE + 0x058)	
#define CSD_BURST_CR  REG32(CSD_BASE + 0x05C)	

#define CSD_SW_CR     REG32(CSD_BASE + 0x060)	
#define CSD_DFT_DR0   REG32(CSD_BASE + 0x064)	
#define CSD_DFT_DR1   REG32(CSD_BASE + 0x068)	

#define BG_CR         REG32(CSD_BASE + 0x80)
#define BG_TRIM       REG32(CSD_BASE + 0x84)
#define BG_ITRIM      REG32(CSD_BASE + 0x88)
#define BG_TCTRIM     REG32(CSD_BASE + 0x8C)
	
#define CSD_RX0_CR    REG32(CSD_BASE + 0x100)	
#define CSD_RX0_DR    REG32(CSD_BASE + 0x104)	
	
#define CSD_RX1_CR    REG32(CSD_BASE + 0x108)	
#define CSD_RX1_DR    REG32(CSD_BASE + 0x10C)	
	
#define CSD_RX2_CR    REG32(CSD_BASE + 0x110)	
#define CSD_RX2_DR    REG32(CSD_BASE + 0x114)	
	
#define CSD_RX3_CR    REG32(CSD_BASE + 0x118)	
#define CSD_RX3_DR    REG32(CSD_BASE + 0x11C)	
	
#define CSD_RX4_CR    REG32(CSD_BASE + 0x120)	
#define CSD_RX4_DR    REG32(CSD_BASE + 0x124)	
	
#define CSD_RX5_CR    REG32(CSD_BASE + 0x128)	
#define CSD_RX5_DR    REG32(CSD_BASE + 0x12C)	
	
#define CSD_RX6_CR    REG32(CSD_BASE + 0x130)	
#define CSD_RX6_DR    REG32(CSD_BASE + 0x134)	
	
#define CSD_RX7_CR    REG32(CSD_BASE + 0x138)	
#define CSD_RX7_DR    REG32(CSD_BASE + 0x13C)	
	
#define CSD_RX8_CR    REG32(CSD_BASE + 0x140)	
#define CSD_RX8_DR    REG32(CSD_BASE + 0x144)	
	
#define CSD_RX9_CR    REG32(CSD_BASE + 0x148)	
#define CSD_RX9_DR    REG32(CSD_BASE + 0x14C)	
	
#define CSD_RX10_CR   REG32(CSD_BASE + 0x150)	
#define CSD_RX10_DR   REG32(CSD_BASE + 0x154)	
	
#define CSD_RX11_CR   REG32(CSD_BASE + 0x158)	
#define CSD_RX11_DR   REG32(CSD_BASE + 0x15C)	
	
#define CSD_RX12_CR   REG32(CSD_BASE + 0x160)	
#define CSD_RX12_DR   REG32(CSD_BASE + 0x164)	
	
#define CSD_RX13_CR   REG32(CSD_BASE + 0x168)	
#define CSD_RX13_DR   REG32(CSD_BASE + 0x16C)	
	
#define CSD_RX14_CR   REG32(CSD_BASE + 0x170)	
#define CSD_RX14_DR   REG32(CSD_BASE + 0x174)	
	
#define CSD_RX15_CR   REG32(CSD_BASE + 0x178)	
#define CSD_RX15_DR   REG32(CSD_BASE + 0x17C)	
	
//-----------------------------------------------------------
#define I2C0_BASE 			0x400830C0
	
#define I2C0_AD 		REG32(I2C0_BASE + 0x00) 
#define I2C0_CR 		REG32(I2C0_BASE + 0x04)	
#define I2C0_STAT 		REG32(I2C0_BASE + 0x08)	
#define I2C0_DR 		REG32(I2C0_BASE + 0x0C)	
#define I2C0_MCR     		REG32(I2C0_BASE + 0x10)	
#define I2C0_BURST_CR		REG32(I2C0_BASE + 0x14)	
#define I2C0_BURST_AD		REG32(I2C0_BASE + 0x18)	
	
//-----------------------------------------------------------
#define UART0_BASE 			0x40083100
	
#define UART0_SHIFTER       REG32(UART0_BASE + 0x00)
#define UART0_DR            REG32(UART0_BASE + 0x04)
#define UART0_CR            REG32(UART0_BASE + 0x08)
#define UART0_STAT          REG32(UART0_BASE + 0x0C)
#define UART0_CLK           REG32(UART0_BASE + 0x10)











//-----------------------------------------------------------

#define ADDR_SCR_CFG           	(SCR_BASE + 0x00)

#define ADDR_EEP_CR               (EEP_CR_BASE + 0x00)	
#define ADDR_EEP_KEY              (EEP_CR_BASE + 0x04)	
#define ADDR_EEP_AD               (EEP_CR_BASE + 0x08)	
#define ADDR_EEP_DR               (EEP_CR_BASE + 0x0C)	
#define ADDR_EEP_BURST_AD         (EEP_CR_BASE + 0x10)	
#define ADDR_EEP_TEST             (EEP_CR_BASE + 0x14)	
#define ADDR_EEP_TRIM             (EEP_CR_BASE + 0x18)	

#define ADDR_CSD_EN        			(CSD_BASE + 0x000)
#define ADDR_CSD_TX_CR       		(ANA_BASE + 0x80) 
#define ADDR_CSD_TX_DRV      		(ANA_BASE + 0x84) 

#define ADDR_IOA0_PD          (IOA0_BASE + 0x00)	
#define ADDR_IOA0_TXM         (IOA0_BASE + 0x04)	
#define ADDR_IOA0_RXM0        (IOA0_BASE + 0x08)	
#define ADDR_IOA0_RXM1        (IOA0_BASE + 0x0C)	
#define ADDR_IOA1_PD          (IOA1_BASE + 0x00)	
#define ADDR_IOA1_TXM         (IOA1_BASE + 0x04)	
#define ADDR_IOA1_RXM0        (IOA1_BASE + 0x08)	
#define ADDR_IOA1_RXM1        (IOA1_BASE + 0x0C)	
#define ADDR_IOA2_PD          (IOA2_BASE + 0x00)	
#define ADDR_IOA2_TXM         (IOA2_BASE + 0x04)	
#define ADDR_IOA2_RXM0        (IOA2_BASE + 0x08)	
#define ADDR_IOA2_RXM1        (IOA2_BASE + 0x0C)	
#define ADDR_IOA3_PD          (IOA3_BASE + 0x00)	
#define ADDR_IOA3_TXM         (IOA3_BASE + 0x04)	
#define ADDR_IOA3_RXM0        (IOA3_BASE + 0x08)	
#define ADDR_IOA3_RXM1        (IOA3_BASE + 0x0C)	
#define ADDR_IOA4_PD          (IOA4_BASE + 0x00)	
#define ADDR_IOA4_TXM         (IOA4_BASE + 0x04)	
#define ADDR_IOA4_RXM0        (IOA4_BASE + 0x08)	
#define ADDR_IOA4_RXM1        (IOA4_BASE + 0x0C)	
#define ADDR_IOA5_PD          (IOA5_BASE + 0x00)	
#define ADDR_IOA5_TXM         (IOA5_BASE + 0x04)	
#define ADDR_IOA5_RXM0        (IOA5_BASE + 0x08)	
#define ADDR_IOA5_RXM1        (IOA5_BASE + 0x0C)	
#define ADDR_IOA6_PD          (IOA6_BASE + 0x00)	
#define ADDR_IOA6_TXM         (IOA6_BASE + 0x04)	
#define ADDR_IOA6_RXM0        (IOA6_BASE + 0x08)	
#define ADDR_IOA6_RXM1        (IOA6_BASE + 0x0C)	
#define ADDR_IOA7_PD          (IOA7_BASE + 0x00)	
#define ADDR_IOA7_TXM         (IOA7_BASE + 0x04)	
#define ADDR_IOA7_RXM0        (IOA7_BASE + 0x08)	
#define ADDR_IOA7_RXM1        (IOA7_BASE + 0x0C)	
#define ADDR_IOA8_PD          (IOA8_BASE + 0x00)	
#define ADDR_IOA8_TXM         (IOA8_BASE + 0x04)	
#define ADDR_IOA8_RXM0        (IOA8_BASE + 0x08)	
#define ADDR_IOA8_RXM1        (IOA8_BASE + 0x0C)	
#define ADDR_IOA9_PD          (IOA9_BASE + 0x00)	
#define ADDR_IOA9_TXM         (IOA9_BASE + 0x04)	
#define ADDR_IOA9_RXM0        (IOA9_BASE + 0x08)	
#define ADDR_IOA9_RXM1        (IOA9_BASE + 0x0C)	
#define ADDR_IOA10_PD         (IOA10_BASE + 0x00)	
#define ADDR_IOA10_TXM        (IOA10_BASE + 0x04)	
#define ADDR_IOA10_RXM0       (IOA10_BASE + 0x08)	
#define ADDR_IOA10_RXM1       (IOA10_BASE + 0x0C)	
#define ADDR_IOA11_PD         (IOA11_BASE + 0x00)	
#define ADDR_IOA11_TXM        (IOA11_BASE + 0x04)	
#define ADDR_IOA11_RXM0       (IOA11_BASE + 0x08)	
#define ADDR_IOA11_RXM1       (IOA11_BASE + 0x0C)	

#define ADDR_IOD0_DR          (IOD_BASE + 0x00)	
#define ADDR_IOD0_GIE         (IOD_BASE + 0x04)	
#define ADDR_IOD0_GOE         (IOD_BASE + 0x08)	
#define ADDR_IOD0_DM0         (IOD_BASE + 0x0C)	
#define ADDR_IOD0_DM1         (IOD_BASE + 0x10)	
#define ADDR_IOD0_DM2         (IOD_BASE + 0x14)	
#define ADDR_IOD0_IE          (IOD_BASE + 0x18)	
#define ADDR_IOD0_IC0         (IOD_BASE + 0x1C)	
#define ADDR_IOD0_IC1         (IOD_BASE + 0x20)	
#define ADDR_IOD0_FLAG        (IOD_BASE + 0x24)	
//------------------------------------------------------


#endif

