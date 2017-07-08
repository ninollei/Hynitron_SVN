
#ifndef __CST2XX_REGISTER_H__
#define _CST2XX_REGISTER_H__

//-----------------------------------------------------------
#define CST2_CST2_ROM_TAB_BASE 		0xF0000000
	
//-----------------------------------------------------------
#define CST2_SCR_BASE 		    0x40080000
	
#define CST2_SCR_CFG            REG32(CST2_SCR_BASE + 0x00) 	//#define CST2_SCR_SYS_BOOT  
#define CST2_SCR_CALI           REG32(CST2_SCR_BASE + 0x04)	//#define CST2_SCR_SYS_CALI  
#define CST2_SCR_SCB_CR         REG32(CST2_SCR_BASE + 0x0C)	//#define CST2_SCR_I2C_ROUTE 
	
#define CST2_SCR_XRES_CR        REG32(CST2_SCR_BASE + 0x10) 
#define CST2_SCR_FUSE_CR        REG32(CST2_SCR_BASE + 0x14) 
#define CST2_SCR_SRAM_KEY       REG32(CST2_SCR_BASE + 0x18) 

#define CST2_SCR_MISR_DR        REG32(CST2_SCR_BASE + 0x40)	//#define CST2_SCR_BIST_MISR 
#define CST2_SCR_MISR_CR        REG32(CST2_SCR_BASE + 0x44)	//#define CST2_SCR_BIST_CR0  
#define CST2_SCR_DFT_CR         REG32(CST2_SCR_BASE + 0x48)	//#define CST2_SCR_BIST_CR1  
	
#define CST2_SCR_HCLK_CR        REG32(CST2_SCR_BASE + 0xC0)	//#define CST2_CLK_CR_CPU    
#define CST2_SCR_PCLK_CR        REG32(CST2_SCR_BASE + 0xC4)	//#define CST2_CLK_CR_AUX    
#define CST2_SCR_PCLK_DIV0      REG32(CST2_SCR_BASE + 0xC8)	//#define CST2_CLK_CR_VC12    
#define CST2_SCR_PCLK_DIV1      REG32(CST2_SCR_BASE + 0xCC)	//#define CST2_CLK_CR_VC3    
	
//-----------------------------------------------------------
#define CST2_SLP_BASE           0x40080200
	
#define CST2_SLPTIM_CR             REG32(CST2_SLP_BASE + 0x00)	//#define CST2_SLP_CTRL   
#define CST2_SLPTIM_STAT           REG32(CST2_SLP_BASE + 0x04)	//#define CST2_SLP_STAT   
#define CST2_SLPTIM_CLR            REG32(CST2_SLP_BASE + 0x08)	//#define CST2_SLP_WDT_RES
#define CST2_SLPTIM_CNT            REG32(CST2_SLP_BASE + 0x0C)	//#define CST2_SLP_CNT    
#define CST2_SLPTIM_WDT            REG32(CST2_SLP_BASE + 0x10)	//#define CST2_SLP_WDT    
#define CST2_SLPTIM_ACC_CR         REG32(CST2_SLP_BASE + 0x14)	//#define CST2_SLP_PRD
	
//-----------------------------------------------------------
#define CST2_ANA_BASE 		   0x40080300

#define CST2_ILO_CR           REG32(CST2_ANA_BASE + 0x78) 
#define CST2_ILO_TRIM         REG32(CST2_ANA_BASE + 0x7C) 
	
#define CST2_CSD_TX_CR       REG32(CST2_ANA_BASE + 0x80) 
#define CST2_CSD_TX_DRV      REG32(CST2_ANA_BASE + 0x84) 
#define CST2_CSD_TX_DFT      REG32(CST2_ANA_BASE + 0x8C) 
//-----------------------------------------------------------
#define CST2_IOA0_BASE 	   0x40081000
	
#define CST2_IOA0_PD           REG32(CST2_IOA0_BASE + 0x00)	
#define CST2_IOA0_TXM          REG32(CST2_IOA0_BASE + 0x04)	
#define CST2_IOA0_RXM0         REG32(CST2_IOA0_BASE + 0x08)	
#define CST2_IOA0_RXM1         REG32(CST2_IOA0_BASE + 0x0C)	
//------------------------------------------------------
#define CST2_IOA1_BASE 	   0x40081010
	
#define CST2_IOA1_PD           REG32(CST2_IOA1_BASE + 0x00)	
#define CST2_IOA1_TXM          REG32(CST2_IOA1_BASE + 0x04)	
#define CST2_IOA1_RXM0         REG32(CST2_IOA1_BASE + 0x08)	
#define CST2_IOA1_RXM1         REG32(CST2_IOA1_BASE + 0x0C)	
//------------------------------------------------------
#define CST2_IOA2_BASE 	   0x40081020
	
#define CST2_IOA2_PD           REG32(CST2_IOA2_BASE + 0x00)	
#define CST2_IOA2_TXM          REG32(CST2_IOA2_BASE + 0x04)	
#define CST2_IOA2_RXM0         REG32(CST2_IOA2_BASE + 0x08)	
#define CST2_IOA2_RXM1         REG32(CST2_IOA2_BASE + 0x0C)	
//------------------------------------------------------
#define CST2_IOA3_BASE 	   0x40081030
	
#define CST2_IOA3_PD           REG32(CST2_IOA3_BASE + 0x00)	
#define CST2_IOA3_TXM          REG32(CST2_IOA3_BASE + 0x04)	
#define CST2_IOA3_RXM0         REG32(CST2_IOA3_BASE + 0x08)	
#define CST2_IOA3_RXM1         REG32(CST2_IOA3_BASE + 0x0C)	
//------------------------------------------------------
#define CST2_IOA4_BASE 	   0x40081040
	
#define CST2_IOA4_PD           REG32(CST2_IOA4_BASE + 0x00)	
#define CST2_IOA4_TXM          REG32(CST2_IOA4_BASE + 0x04)	
#define CST2_IOA4_RXM0         REG32(CST2_IOA4_BASE + 0x08)	
#define CST2_IOA4_RXM1         REG32(CST2_IOA4_BASE + 0x0C)	
//------------------------------------------------------
#define CST2_IOA5_BASE 	   0x40081050	
	
#define CST2_IOA5_PD           REG32(CST2_IOA5_BASE + 0x00)	
#define CST2_IOA5_TXM          REG32(CST2_IOA5_BASE + 0x04)	
#define CST2_IOA5_RXM0         REG32(CST2_IOA5_BASE + 0x08)	
#define CST2_IOA5_RXM1         REG32(CST2_IOA5_BASE + 0x0C)	
//------------------------------------------------------
#define CST2_IOA6_BASE 	   0x40081060
	
#define CST2_IOA6_PD           REG32(CST2_IOA6_BASE + 0x00)	
#define CST2_IOA6_TXM          REG32(CST2_IOA6_BASE + 0x04)	
#define CST2_IOA6_RXM0         REG32(CST2_IOA6_BASE + 0x08)	
#define CST2_IOA6_RXM1         REG32(CST2_IOA6_BASE + 0x0C)	
//------------------------------------------------------
#define CST2_IOA7_BASE 	   0x40081070	
	
#define CST2_IOA7_PD           REG32(CST2_IOA7_BASE + 0x00)	
#define CST2_IOA7_TXM          REG32(CST2_IOA7_BASE + 0x04)	
#define CST2_IOA7_RXM0         REG32(CST2_IOA7_BASE + 0x08)	
#define CST2_IOA7_RXM1         REG32(CST2_IOA7_BASE + 0x0C)	
	
//------------------------------------------------------
#define CST2_IOA8_BASE 	   0x40081080	
	
#define CST2_IOA8_PD           REG32(CST2_IOA8_BASE + 0x00)	
#define CST2_IOA8_TXM          REG32(CST2_IOA8_BASE + 0x04)	
#define CST2_IOA8_RXM0         REG32(CST2_IOA8_BASE + 0x08)	
#define CST2_IOA8_RXM1         REG32(CST2_IOA8_BASE + 0x0C)	
//------------------------------------------------------
#define CST2_IOA9_BASE 	   0x40081090	
	
#define CST2_IOA9_PD           REG32(CST2_IOA9_BASE + 0x00)	
#define CST2_IOA9_TXM          REG32(CST2_IOA9_BASE + 0x04)	
#define CST2_IOA9_RXM0         REG32(CST2_IOA9_BASE + 0x08)	
#define CST2_IOA9_RXM1         REG32(CST2_IOA9_BASE + 0x0C)	
/////------------------------------------------------------

//4 dport pins
#define CST2_IOD_BASE       0x40081FC0
	
#define CST2_IOD0_DR          REG32(CST2_IOD_BASE + 0x00)	
#define CST2_IOD0_GIE         REG32(CST2_IOD_BASE + 0x04)	
#define CST2_IOD0_GOE         REG32(CST2_IOD_BASE + 0x08)	
#define CST2_IOD0_DM0         REG32(CST2_IOD_BASE + 0x0C)	
#define CST2_IOD0_DM1         REG32(CST2_IOD_BASE + 0x10)	
#define CST2_IOD0_DM2         REG32(CST2_IOD_BASE + 0x14)	
#define CST2_IOD0_IE          REG32(CST2_IOD_BASE + 0x18)	
#define CST2_IOD0_IC0         REG32(CST2_IOD_BASE + 0x1C)	
#define CST2_IOD0_IC1         REG32(CST2_IOD_BASE + 0x20)	
#define CST2_IOD0_FLAG        REG32(CST2_IOD_BASE + 0x24)	

//-----------------------------------------------------------
#define CST2_CSD_BASE 	      0x40082000
	
#define CST2_CSD_EN        REG32(CST2_CSD_BASE + 0x000)	//#define CST2_CSX_CR          
#define CST2_CSD_MODE      REG32(CST2_CSD_BASE + 0x004)	//#define CST2_CSX_CFG         
#define CST2_CSD_STAT      REG32(CST2_CSD_BASE + 0x008)	//#define CST2_CSX_STAT        
#define CST2_CSD_NSCAN       REG32(CST2_CSD_BASE + 0x00C)	//#define CST2_CSX_NSUB        
#define CST2_CSD_TRES      REG32(CST2_CSD_BASE + 0x010)	//#define CST2_CSX_NRESET      
#define CST2_CSD_TITO      REG32(CST2_CSD_BASE + 0x014)	//#define CST2_CSX_NWAIT_ITO   
#define CST2_CSD_TANA      REG32(CST2_CSD_BASE + 0x018)	//#define CST2_CSX_NWAIT_ANA   
#define CST2_CSD_TBL       REG32(CST2_CSD_BASE + 0x01C)	//#define CST2_CSX_NBL         
#define CST2_CSD_SYNC      REG32(CST2_CSD_BASE + 0x020)	//#define CST2_CSX_SYNC_CR     
#define CST2_CSD_SHIELD    REG32(CST2_CSD_BASE + 0x028)	//#define CST2_CSX_SHIELD_CR   
#define CST2_CSD_VREF      REG32(CST2_CSD_BASE + 0x02C)	//#define CST2_CSX_VREF_CR     
#define CST2_CSD_ICR       REG32(CST2_CSD_BASE + 0x030)	//#define CST2_CSX_IDAC_CR     
#define CST2_CSD_IBL       REG32(CST2_CSD_BASE + 0x034)	//#define CST2_CSX_IDAC_BL     
#define CST2_CSD_IMS       REG32(CST2_CSD_BASE + 0x038)	//#define CST2_CSX_IDAC_MEAS   
#define CST2_CSD_TRIM      REG32(CST2_CSD_BASE + 0x03C)	//#define CST2_CSX_TRIM        
	
#define CST2_CSD_NX_CFG    REG32(CST2_CSD_BASE + 0x040)	//#define CST2_CSX_NSCH_LUT    
#define CST2_CSD_NX_TMO    REG32(CST2_CSD_BASE + 0x044)	//#define CST2_CSX_NSCH_TMO    
#define CST2_CSD_NX_STAT   REG32(CST2_CSD_BASE + 0x048)	//#define CST2_CSX_NSCH_STAT   
#define CST2_CSD_PRS_CR    REG32(CST2_CSD_BASE + 0x04C)	//#define CST2_CSX_PRS_CR

#define CST2_CSD_BURST_SEQ REG32(CST2_CSD_BASE + 0x050)	//#define CST2_CSX_RX_SEQ
#define CST2_CSD_RX_SEQL   REG32(CST2_CSD_BASE + 0x050)	//#define CST2_CSX_RX_SEQL
#define CST2_CSD_RX_SEQH   REG32(CST2_CSD_BASE + 0x054)	//#define CST2_CSX_RX_SEQH
#define CST2_CSD_BURST_AD  REG32(CST2_CSD_BASE + 0x058)	//#define CST2_CSX_DFT_OUT0    
#define CST2_CSD_BURST_CR  REG32(CST2_CSD_BASE + 0x05C)	//#define CST2_CSX_DFT_OUT0    


#define CST2_CSD_SW_CR     REG32(CST2_CSD_BASE + 0x060)	//#define CST2_CSX_DFT_CR      
#define CST2_CSD_DFT_DR0   REG32(CST2_CSD_BASE + 0x064)	//#define CST2_CSX_DFT_OUT0    
#define CST2_CSD_DFT_DR1   REG32(CST2_CSD_BASE + 0x068)	//#define CST2_CSX_DFT_OUT1    

#define CST2_BG_CR         REG32(CST2_CSD_BASE + 0x80)
#define CST2_BG_TRIM       REG32(CST2_CSD_BASE + 0x84)
#define CST2_BG_ITRIM      REG32(CST2_CSD_BASE + 0x88)
#define CST2_BG_TCTRIM     REG32(CST2_CSD_BASE + 0x8C)

#define CST2_IMO_CR        REG32(CST2_CSD_BASE + 0x90)
#define CST2_IMO_TRIM      REG32(CST2_CSD_BASE + 0x94)
#define CST2_LDO_CR        REG32(CST2_CSD_BASE + 0x98)
#define CST2_LDO_TRIM      REG32(CST2_CSD_BASE + 0x9C)
	
#define CST2_CSD_RX0_CR    REG32(CST2_CSD_BASE + 0x100)	//#define CST2_CSX_RXCH0_CR    
#define CST2_CSD_RX0_DR    REG32(CST2_CSD_BASE + 0x104)	//#define CST2_CSX_RXCH0_CNT   
	
#define CST2_CSD_RX1_CR    REG32(CST2_CSD_BASE + 0x108)	//#define CST2_CSX_RXCH1_CR    
#define CST2_CSD_RX1_DR    REG32(CST2_CSD_BASE + 0x10C)	//#define CST2_CSX_RXCH1_CNT   
	
#define CST2_CSD_RX2_CR    REG32(CST2_CSD_BASE + 0x110)	//#define CST2_CSX_RXCH2_CR    
#define CST2_CSD_RX2_DR    REG32(CST2_CSD_BASE + 0x114)	//#define CST2_CSX_RXCH2_CNT   
	
#define CST2_CSD_RX3_CR    REG32(CST2_CSD_BASE + 0x118)	//#define CST2_CSX_RXCH3_CR    
#define CST2_CSD_RX3_DR    REG32(CST2_CSD_BASE + 0x11C)	//#define CST2_CSX_RXCH3_CNT   
	
#define CST2_CSD_RX4_CR    REG32(CST2_CSD_BASE + 0x120)	//#define CST2_CSX_RXCH4_CR    
#define CST2_CSD_RX4_DR    REG32(CST2_CSD_BASE + 0x124)	//#define CST2_CSX_RXCH4_CNT   
	
#define CST2_CSD_RX5_CR    REG32(CST2_CSD_BASE + 0x128)	//#define CST2_CSX_RXCH5_CR    
#define CST2_CSD_RX5_DR    REG32(CST2_CSD_BASE + 0x12C)	//#define CST2_CSX_RXCH5_CNT   
	
#define CST2_CSD_RX6_CR    REG32(CST2_CSD_BASE + 0x130)	//#define CST2_CSX_RXCH6_CR    
#define CST2_CSD_RX6_DR    REG32(CST2_CSD_BASE + 0x134)	//#define CST2_CSX_RXCH6_CNT   
	
#define CST2_CSD_RX7_CR    REG32(CST2_CSD_BASE + 0x138)	//#define CST2_CSX_RXCH7_CR    
#define CST2_CSD_RX7_DR    REG32(CST2_CSD_BASE + 0x13C)	//#define CST2_CSX_RXCH7_CNT   
	
#define CST2_CSD_RX8_CR    REG32(CST2_CSD_BASE + 0x140)	//#define CST2_CSX_RXCH8_CR    
#define CST2_CSD_RX8_DR    REG32(CST2_CSD_BASE + 0x144)	//#define CST2_CSX_RXCH8_CNT   
	
#define CST2_CSD_RX9_CR    REG32(CST2_CSD_BASE + 0x148)	//#define CST2_CSX_RXCH9_CR    
#define CST2_CSD_RX9_DR    REG32(CST2_CSD_BASE + 0x14C)	//#define CST2_CSX_RXCH9_CNT   
	
#define CST2_CSD_RX10_CR   REG32(CST2_CSD_BASE + 0x150)	//#define CST2_CSX_RXCH10_CR   
#define CST2_CSD_RX10_DR   REG32(CST2_CSD_BASE + 0x154)	//#define CST2_CSX_RXCH10_CNT  
	
#define CST2_CSD_RX11_CR   REG32(CST2_CSD_BASE + 0x158)	//#define CST2_CSX_RXCH11_CR   
#define CST2_CSD_RX11_DR   REG32(CST2_CSD_BASE + 0x15C)	//#define CST2_CSX_RXCH11_CNT  
	
#define CST2_CSD_RX12_CR   REG32(CST2_CSD_BASE + 0x160)	//#define CST2_CSX_RXCH12_CR   
#define CST2_CSD_RX12_DR   REG32(CST2_CSD_BASE + 0x164)	//#define CST2_CSX_RXCH12_CNT  
	
#define CST2_CSD_RX13_CR   REG32(CST2_CSD_BASE + 0x168)	//#define CST2_CSX_RXCH13_CR   
#define CST2_CSD_RX13_DR   REG32(CST2_CSD_BASE + 0x16C)	//#define CST2_CSX_RXCH13_CNT  
		
//-----------------------------------------------------------
#define CST2_I2C0_BASE 			0x400830C0
	
#define CST2_I2C0_AD 			REG32(CST2_I2C0_BASE + 0x00) //#define CST2_I2C0_ADDR
#define CST2_I2C0_CR 			REG32(CST2_I2C0_BASE + 0x04)	//#define CST2_I2C0_CFG 	 
#define CST2_I2C0_STAT 			REG32(CST2_I2C0_BASE + 0x08)	//#define CST2_I2C0_SCR 	 
#define CST2_I2C0_DR 			REG32(CST2_I2C0_BASE + 0x0C)	//#define CST2_I2C0_DR 	 
#define CST2_I2C0_MCR     		REG32(CST2_I2C0_BASE + 0x10)	//#define CST2_I2C0_MSCR 	 
#define CST2_I2C0_BURST_CR		REG32(CST2_I2C0_BASE + 0x14)	//#define CST2_I2C0_BUF_CTRL
#define CST2_I2C0_BURST_AD		REG32(CST2_I2C0_BASE + 0x18)	//#define CST2_I2C0_BUF_ADDR
	
//-----------------------------------------------------------
#define CST2_UART0_BASE 			0x40083100
	
#define CST2_UART0_SHIFTER       REG32(CST2_UART0_BASE + 0x00) 	//#define CST2_UART0_SHIFTER
#define CST2_UART0_DR            REG32(CST2_UART0_BASE + 0x04)	//#define CST2_UART0_DATA   
#define CST2_UART0_CR            REG32(CST2_UART0_BASE + 0x08)	//#define CST2_UART0_CR0    
#define CST2_UART0_STAT          REG32(CST2_UART0_BASE + 0x0C)	//#define CST2_UART0_CR1    
#define CST2_UART0_CLK           REG32(CST2_UART0_BASE + 0x10)	//#define CST2_UART0_CR2  




#define CST2_ADDR_CST2_ADDR_ROM_TAB_BASE 		0xF0000000

#define CST2_ADDR_SCR_BASE 		    0x40080000
	
#define CST2_ADDR_SCR_CFG            (CST2_ADDR_SCR_BASE + 0x00) 	//#define CST2_ADDR_SCR_SYS_BOOT  
#define CST2_ADDR_SCR_CALI           (CST2_ADDR_SCR_BASE + 0x04)	//#define CST2_ADDR_SCR_SYS_CALI  
#define CST2_ADDR_SCR_SCB_CR         (CST2_ADDR_SCR_BASE + 0x0C)	//#define CST2_ADDR_SCR_I2C_ROUTE 
	
#define CST2_ADDR_SCR_XRES_CR        (CST2_ADDR_SCR_BASE + 0x10) 
#define CST2_ADDR_SCR_FUSE_CR        (CST2_ADDR_SCR_BASE + 0x14) 
#define CST2_ADDR_SCR_SRAM_KEY       (CST2_ADDR_SCR_BASE + 0x18) 

#define CST2_ADDR_SCR_MISR_DR        (CST2_ADDR_SCR_BASE + 0x40)	//#define CST2_ADDR_SCR_BIST_MISR 
#define CST2_ADDR_SCR_MISR_CR        (CST2_ADDR_SCR_BASE + 0x44)	//#define CST2_ADDR_SCR_BIST_CR0  
#define CST2_ADDR_SCR_DFT_CR         (CST2_ADDR_SCR_BASE + 0x48)	//#define CST2_ADDR_SCR_BIST_CR1  
	
#define CST2_ADDR_SCR_HCLK_CR        (CST2_ADDR_SCR_BASE + 0xC0)	//#define CST2_ADDR_CLK_CR_CPU    
#define CST2_ADDR_SCR_PCLK_CR        (CST2_ADDR_SCR_BASE + 0xC4)	//#define CST2_ADDR_CLK_CR_AUX    
#define CST2_ADDR_SCR_PCLK_DIV0      (CST2_ADDR_SCR_BASE + 0xC8)	//#define CST2_ADDR_CLK_CR_VC12    
#define CST2_ADDR_SCR_PCLK_DIV1      (CST2_ADDR_SCR_BASE + 0xCC)	//#define CST2_ADDR_CLK_CR_VC3    
	
//-----------------------------------------------------------
#define CST2_ADDR_SLP_BASE           0x40080200
	
#define CST2_ADDR_SLPTIM_CR             (CST2_ADDR_SLP_BASE + 0x00)	//#define CST2_ADDR_SLP_CTRL   
#define CST2_ADDR_SLPTIM_STAT           (CST2_ADDR_SLP_BASE + 0x04)	//#define CST2_ADDR_SLP_STAT   
#define CST2_ADDR_SLPTIM_CLR            (CST2_ADDR_SLP_BASE + 0x08)	//#define CST2_ADDR_SLP_WDT_RES
#define CST2_ADDR_SLPTIM_CNT            (CST2_ADDR_SLP_BASE + 0x0C)	//#define CST2_ADDR_SLP_CNT    
#define CST2_ADDR_SLPTIM_WDT            (CST2_ADDR_SLP_BASE + 0x10)	//#define CST2_ADDR_SLP_WDT    
#define CST2_ADDR_SLPTIM_ACC_CR         (CST2_ADDR_SLP_BASE + 0x14)	//#define CST2_ADDR_SLP_PRD
	
//-----------------------------------------------------------
#define CST2_ADDR_ANA_BASE 		   0x40080300

#define CST2_ADDR_ILO_CR           (CST2_ADDR_ANA_BASE + 0x78) 
#define CST2_ADDR_ILO_TRIM         (CST2_ADDR_ANA_BASE + 0x7C) 
	
#define CST2_ADDR_CSD_TX_CR       (CST2_ADDR_ANA_BASE + 0x80) 
#define CST2_ADDR_CSD_TX_DRV      (CST2_ADDR_ANA_BASE + 0x84) 
#define CST2_ADDR_CSD_TX_DFT      (CST2_ADDR_ANA_BASE + 0x8C) 
//-----------------------------------------------------------
#define CST2_ADDR_IOA0_BASE 	   0x40081000
	
#define CST2_ADDR_IOA0_PD           (CST2_ADDR_IOA0_BASE + 0x00)	
#define CST2_ADDR_IOA0_TXM          (CST2_ADDR_IOA0_BASE + 0x04)	
#define CST2_ADDR_IOA0_RXM0         (CST2_ADDR_IOA0_BASE + 0x08)	
#define CST2_ADDR_IOA0_RXM1         (CST2_ADDR_IOA0_BASE + 0x0C)	
//------------------------------------------------------
#define CST2_ADDR_IOA1_BASE 	   0x40081010
	
#define CST2_ADDR_IOA1_PD           (CST2_ADDR_IOA1_BASE + 0x00)	
#define CST2_ADDR_IOA1_TXM          (CST2_ADDR_IOA1_BASE + 0x04)	
#define CST2_ADDR_IOA1_RXM0         (CST2_ADDR_IOA1_BASE + 0x08)	
#define CST2_ADDR_IOA1_RXM1         (CST2_ADDR_IOA1_BASE + 0x0C)	
//------------------------------------------------------
#define CST2_ADDR_IOA2_BASE 	   0x40081020
	
#define CST2_ADDR_IOA2_PD           (CST2_ADDR_IOA2_BASE + 0x00)	
#define CST2_ADDR_IOA2_TXM          (CST2_ADDR_IOA2_BASE + 0x04)	
#define CST2_ADDR_IOA2_RXM0         (CST2_ADDR_IOA2_BASE + 0x08)	
#define CST2_ADDR_IOA2_RXM1         (CST2_ADDR_IOA2_BASE + 0x0C)	
//------------------------------------------------------
#define CST2_ADDR_IOA3_BASE 	   0x40081030
	
#define CST2_ADDR_IOA3_PD           (CST2_ADDR_IOA3_BASE + 0x00)	
#define CST2_ADDR_IOA3_TXM          (CST2_ADDR_IOA3_BASE + 0x04)	
#define CST2_ADDR_IOA3_RXM0         (CST2_ADDR_IOA3_BASE + 0x08)	
#define CST2_ADDR_IOA3_RXM1         (CST2_ADDR_IOA3_BASE + 0x0C)	
//------------------------------------------------------
#define CST2_ADDR_IOA4_BASE 	   0x40081040
	
#define CST2_ADDR_IOA4_PD           (CST2_ADDR_IOA4_BASE + 0x00)	
#define CST2_ADDR_IOA4_TXM          (CST2_ADDR_IOA4_BASE + 0x04)	
#define CST2_ADDR_IOA4_RXM0         (CST2_ADDR_IOA4_BASE + 0x08)	
#define CST2_ADDR_IOA4_RXM1         (CST2_ADDR_IOA4_BASE + 0x0C)	
//------------------------------------------------------
#define CST2_ADDR_IOA5_BASE 	   0x40081050	
	
#define CST2_ADDR_IOA5_PD           (CST2_ADDR_IOA5_BASE + 0x00)	
#define CST2_ADDR_IOA5_TXM          (CST2_ADDR_IOA5_BASE + 0x04)	
#define CST2_ADDR_IOA5_RXM0         (CST2_ADDR_IOA5_BASE + 0x08)	
#define CST2_ADDR_IOA5_RXM1         (CST2_ADDR_IOA5_BASE + 0x0C)	
//------------------------------------------------------
#define CST2_ADDR_IOA6_BASE 	   0x40081060
	
#define CST2_ADDR_IOA6_PD           (CST2_ADDR_IOA6_BASE + 0x00)	
#define CST2_ADDR_IOA6_TXM          (CST2_ADDR_IOA6_BASE + 0x04)	
#define CST2_ADDR_IOA6_RXM0         (CST2_ADDR_IOA6_BASE + 0x08)	
#define CST2_ADDR_IOA6_RXM1         (CST2_ADDR_IOA6_BASE + 0x0C)	
//------------------------------------------------------
#define CST2_ADDR_IOA7_BASE 	   0x40081070	
	
#define CST2_ADDR_IOA7_PD           (CST2_ADDR_IOA7_BASE + 0x00)	
#define CST2_ADDR_IOA7_TXM          (CST2_ADDR_IOA7_BASE + 0x04)	
#define CST2_ADDR_IOA7_RXM0         (CST2_ADDR_IOA7_BASE + 0x08)	
#define CST2_ADDR_IOA7_RXM1         (CST2_ADDR_IOA7_BASE + 0x0C)	
	
//------------------------------------------------------
#define CST2_ADDR_IOA8_BASE 	   0x40081080	
	
#define CST2_ADDR_IOA8_PD           (CST2_ADDR_IOA8_BASE + 0x00)	
#define CST2_ADDR_IOA8_TXM          (CST2_ADDR_IOA8_BASE + 0x04)	
#define CST2_ADDR_IOA8_RXM0         (CST2_ADDR_IOA8_BASE + 0x08)	
#define CST2_ADDR_IOA8_RXM1         (CST2_ADDR_IOA8_BASE + 0x0C)	
//------------------------------------------------------
#define CST2_ADDR_IOA9_BASE 	   0x40081090	
	
#define CST2_ADDR_IOA9_PD           (CST2_ADDR_IOA9_BASE + 0x00)	
#define CST2_ADDR_IOA9_TXM          (CST2_ADDR_IOA9_BASE + 0x04)	
#define CST2_ADDR_IOA9_RXM0         (CST2_ADDR_IOA9_BASE + 0x08)	
#define CST2_ADDR_IOA9_RXM1         (CST2_ADDR_IOA9_BASE + 0x0C)	
/////------------------------------------------------------

//4 dport pins
#define CST2_ADDR_IOD_BASE       0x40081FC0
	
#define CST2_ADDR_IOD0_DR          (CST2_ADDR_IOD_BASE + 0x00)	
#define CST2_ADDR_IOD0_GIE         (CST2_ADDR_IOD_BASE + 0x04)	
#define CST2_ADDR_IOD0_GOE         (CST2_ADDR_IOD_BASE + 0x08)	
#define CST2_ADDR_IOD0_DM0         (CST2_ADDR_IOD_BASE + 0x0C)	
#define CST2_ADDR_IOD0_DM1         (CST2_ADDR_IOD_BASE + 0x10)	
#define CST2_ADDR_IOD0_DM2         (CST2_ADDR_IOD_BASE + 0x14)	
#define CST2_ADDR_IOD0_IE          (CST2_ADDR_IOD_BASE + 0x18)	
#define CST2_ADDR_IOD0_IC0         (CST2_ADDR_IOD_BASE + 0x1C)	
#define CST2_ADDR_IOD0_IC1         (CST2_ADDR_IOD_BASE + 0x20)	
#define CST2_ADDR_IOD0_FLAG        (CST2_ADDR_IOD_BASE + 0x24)	

//-----------------------------------------------------------
#define CST2_ADDR_CSD_BASE 	      0x40082000
	
#define CST2_ADDR_CSD_EN        (CST2_ADDR_CSD_BASE + 0x000)	//#define CST2_ADDR_CSX_CR          
#define CST2_ADDR_CSD_MODE      (CST2_ADDR_CSD_BASE + 0x004)	//#define CST2_ADDR_CSX_CFG         
#define CST2_ADDR_CSD_STAT      (CST2_ADDR_CSD_BASE + 0x008)	//#define CST2_ADDR_CSX_STAT        
#define CST2_ADDR_CSD_NSCAN       (CST2_ADDR_CSD_BASE + 0x00C)	//#define CST2_ADDR_CSX_NSUB        
#define CST2_ADDR_CSD_TRES      (CST2_ADDR_CSD_BASE + 0x010)	//#define CST2_ADDR_CSX_NRESET      
#define CST2_ADDR_CSD_TITO      (CST2_ADDR_CSD_BASE + 0x014)	//#define CST2_ADDR_CSX_NWAIT_ITO   
#define CST2_ADDR_CSD_TANA      (CST2_ADDR_CSD_BASE + 0x018)	//#define CST2_ADDR_CSX_NWAIT_ANA   
#define CST2_ADDR_CSD_TBL       (CST2_ADDR_CSD_BASE + 0x01C)	//#define CST2_ADDR_CSX_NBL         
#define CST2_ADDR_CSD_SYNC      (CST2_ADDR_CSD_BASE + 0x020)	//#define CST2_ADDR_CSX_SYNC_CR     
#define CST2_ADDR_CSD_SHIELD    (CST2_ADDR_CSD_BASE + 0x028)	//#define CST2_ADDR_CSX_SHIELD_CR   
#define CST2_ADDR_CSD_VREF      (CST2_ADDR_CSD_BASE + 0x02C)	//#define CST2_ADDR_CSX_VREF_CR     
#define CST2_ADDR_CSD_ICR       (CST2_ADDR_CSD_BASE + 0x030)	//#define CST2_ADDR_CSX_IDAC_CR     
#define CST2_ADDR_CSD_IBL       (CST2_ADDR_CSD_BASE + 0x034)	//#define CST2_ADDR_CSX_IDAC_BL     
#define CST2_ADDR_CSD_IMS       (CST2_ADDR_CSD_BASE + 0x038)	//#define CST2_ADDR_CSX_IDAC_MEAS   
#define CST2_ADDR_CSD_TRIM      (CST2_ADDR_CSD_BASE + 0x03C)	//#define CST2_ADDR_CSX_TRIM        
	
#define CST2_ADDR_CSD_NX_CFG    (CST2_ADDR_CSD_BASE + 0x040)	//#define CST2_ADDR_CSX_NSCH_LUT    
#define CST2_ADDR_CSD_NX_TMO    (CST2_ADDR_CSD_BASE + 0x044)	//#define CST2_ADDR_CSX_NSCH_TMO    
#define CST2_ADDR_CSD_NX_STAT   (CST2_ADDR_CSD_BASE + 0x048)	//#define CST2_ADDR_CSX_NSCH_STAT   
#define CST2_ADDR_CSD_PRS_CR    (CST2_ADDR_CSD_BASE + 0x04C)	//#define CST2_ADDR_CSX_PRS_CR

#define CST2_ADDR_CSD_BURST_SEQ (CST2_ADDR_CSD_BASE + 0x050)	//#define CST2_ADDR_CSX_RX_SEQ
#define CST2_ADDR_CSD_RX_SEQL   (CST2_ADDR_CSD_BASE + 0x050)	//#define CST2_ADDR_CSX_RX_SEQL
#define CST2_ADDR_CSD_RX_SEQH   (CST2_ADDR_CSD_BASE + 0x054)	//#define CST2_ADDR_CSX_RX_SEQH
#define CST2_ADDR_CSD_BURST_AD  (CST2_ADDR_CSD_BASE + 0x058)	//#define CST2_ADDR_CSX_DFT_OUT0    
#define CST2_ADDR_CSD_BURST_CR  (CST2_ADDR_CSD_BASE + 0x05C)	//#define CST2_ADDR_CSX_DFT_OUT0    


#define CST2_ADDR_CSD_SW_CR     (CST2_ADDR_CSD_BASE + 0x060)	//#define CST2_ADDR_CSX_DFT_CR      
#define CST2_ADDR_CSD_DFT_DR0   (CST2_ADDR_CSD_BASE + 0x064)	//#define CST2_ADDR_CSX_DFT_OUT0    
#define CST2_ADDR_CSD_DFT_DR1   (CST2_ADDR_CSD_BASE + 0x068)	//#define CST2_ADDR_CSX_DFT_OUT1    

#define CST2_ADDR_BG_CR         (CST2_ADDR_CSD_BASE + 0x80)
#define CST2_ADDR_BG_TRIM       (CST2_ADDR_CSD_BASE + 0x84)
#define CST2_ADDR_BG_ITRIM      (CST2_ADDR_CSD_BASE + 0x88)
#define CST2_ADDR_BG_TCTRIM     (CST2_ADDR_CSD_BASE + 0x8C)

#define CST2_ADDR_IMO_CR        (CST2_ADDR_CSD_BASE + 0x90)
#define CST2_ADDR_IMO_TRIM      (CST2_ADDR_CSD_BASE + 0x94)
#define CST2_ADDR_LDO_CR        (CST2_ADDR_CSD_BASE + 0x98)
#define CST2_ADDR_LDO_TRIM      (CST2_ADDR_CSD_BASE + 0x9C)
	
#define CST2_ADDR_CSD_RX0_CR    (CST2_ADDR_CSD_BASE + 0x100)	//#define CST2_ADDR_CSX_RXCH0_CR    
#define CST2_ADDR_CSD_RX0_DR    (CST2_ADDR_CSD_BASE + 0x104)	//#define CST2_ADDR_CSX_RXCH0_CNT   
	
#define CST2_ADDR_CSD_RX1_CR    (CST2_ADDR_CSD_BASE + 0x108)	//#define CST2_ADDR_CSX_RXCH1_CR    
#define CST2_ADDR_CSD_RX1_DR    (CST2_ADDR_CSD_BASE + 0x10C)	//#define CST2_ADDR_CSX_RXCH1_CNT   
	
#define CST2_ADDR_CSD_RX2_CR    (CST2_ADDR_CSD_BASE + 0x110)	//#define CST2_ADDR_CSX_RXCH2_CR    
#define CST2_ADDR_CSD_RX2_DR    (CST2_ADDR_CSD_BASE + 0x114)	//#define CST2_ADDR_CSX_RXCH2_CNT   
	
#define CST2_ADDR_CSD_RX3_CR    (CST2_ADDR_CSD_BASE + 0x118)	//#define CST2_ADDR_CSX_RXCH3_CR    
#define CST2_ADDR_CSD_RX3_DR    (CST2_ADDR_CSD_BASE + 0x11C)	//#define CST2_ADDR_CSX_RXCH3_CNT   
	
#define CST2_ADDR_CSD_RX4_CR    (CST2_ADDR_CSD_BASE + 0x120)	//#define CST2_ADDR_CSX_RXCH4_CR    
#define CST2_ADDR_CSD_RX4_DR    (CST2_ADDR_CSD_BASE + 0x124)	//#define CST2_ADDR_CSX_RXCH4_CNT   
	
#define CST2_ADDR_CSD_RX5_CR    (CST2_ADDR_CSD_BASE + 0x128)	//#define CST2_ADDR_CSX_RXCH5_CR    
#define CST2_ADDR_CSD_RX5_DR    (CST2_ADDR_CSD_BASE + 0x12C)	//#define CST2_ADDR_CSX_RXCH5_CNT   
	
#define CST2_ADDR_CSD_RX6_CR    (CST2_ADDR_CSD_BASE + 0x130)	//#define CST2_ADDR_CSX_RXCH6_CR    
#define CST2_ADDR_CSD_RX6_DR    (CST2_ADDR_CSD_BASE + 0x134)	//#define CST2_ADDR_CSX_RXCH6_CNT   
	
#define CST2_ADDR_CSD_RX7_CR    (CST2_ADDR_CSD_BASE + 0x138)	//#define CST2_ADDR_CSX_RXCH7_CR    
#define CST2_ADDR_CSD_RX7_DR    (CST2_ADDR_CSD_BASE + 0x13C)	//#define CST2_ADDR_CSX_RXCH7_CNT   
	
#define CST2_ADDR_CSD_RX8_CR    (CST2_ADDR_CSD_BASE + 0x140)	//#define CST2_ADDR_CSX_RXCH8_CR    
#define CST2_ADDR_CSD_RX8_DR    (CST2_ADDR_CSD_BASE + 0x144)	//#define CST2_ADDR_CSX_RXCH8_CNT   
	
#define CST2_ADDR_CSD_RX9_CR    (CST2_ADDR_CSD_BASE + 0x148)	//#define CST2_ADDR_CSX_RXCH9_CR    
#define CST2_ADDR_CSD_RX9_DR    (CST2_ADDR_CSD_BASE + 0x14C)	//#define CST2_ADDR_CSX_RXCH9_CNT   
	
#define CST2_ADDR_CSD_RX10_CR   (CST2_ADDR_CSD_BASE + 0x150)	//#define CST2_ADDR_CSX_RXCH10_CR   
#define CST2_ADDR_CSD_RX10_DR   (CST2_ADDR_CSD_BASE + 0x154)	//#define CST2_ADDR_CSX_RXCH10_CNT  
	
#define CST2_ADDR_CSD_RX11_CR   (CST2_ADDR_CSD_BASE + 0x158)	//#define CST2_ADDR_CSX_RXCH11_CR   
#define CST2_ADDR_CSD_RX11_DR   (CST2_ADDR_CSD_BASE + 0x15C)	//#define CST2_ADDR_CSX_RXCH11_CNT  
	
#define CST2_ADDR_CSD_RX12_CR   (CST2_ADDR_CSD_BASE + 0x160)	//#define CST2_ADDR_CSX_RXCH12_CR   
#define CST2_ADDR_CSD_RX12_DR   (CST2_ADDR_CSD_BASE + 0x164)	//#define CST2_ADDR_CSX_RXCH12_CNT  
	
#define CST2_ADDR_CSD_RX13_CR   (CST2_ADDR_CSD_BASE + 0x168)	//#define CST2_ADDR_CSX_RXCH13_CR   
#define CST2_ADDR_CSD_RX13_DR   (CST2_ADDR_CSD_BASE + 0x16C)	//#define CST2_ADDR_CSX_RXCH13_CNT  
		
//-----------------------------------------------------------
#define CST2_ADDR_I2C0_BASE 			0x400830C0
	
#define CST2_ADDR_I2C0_AD 			(CST2_ADDR_I2C0_BASE + 0x00) //#define CST2_ADDR_I2C0_ADDR
#define CST2_ADDR_I2C0_CR 			(CST2_ADDR_I2C0_BASE + 0x04)	//#define CST2_ADDR_I2C0_CFG 	 
#define CST2_ADDR_I2C0_STAT 			(CST2_ADDR_I2C0_BASE + 0x08)	//#define CST2_ADDR_I2C0_SCR 	 
#define CST2_ADDR_I2C0_DR 			(CST2_ADDR_I2C0_BASE + 0x0C)	//#define CST2_ADDR_I2C0_DR 	 
#define CST2_ADDR_I2C0_MCR     		(CST2_ADDR_I2C0_BASE + 0x10)	//#define CST2_ADDR_I2C0_MSCR 	 
#define CST2_ADDR_I2C0_BURST_CR		(CST2_ADDR_I2C0_BASE + 0x14)	//#define CST2_ADDR_I2C0_BUF_CTRL
#define CST2_ADDR_I2C0_BURST_AD		(CST2_ADDR_I2C0_BASE + 0x18)	//#define CST2_ADDR_I2C0_BUF_ADDR
	
//-----------------------------------------------------------
#define CST2_ADDR_UART0_BASE 			0x40083100
	
#define CST2_ADDR_UART0_SHIFTER       (CST2_ADDR_UART0_BASE + 0x00) 	//#define CST2_ADDR_UART0_SHIFTER
#define CST2_ADDR_UART0_DR            (CST2_ADDR_UART0_BASE + 0x04)	//#define CST2_ADDR_UART0_DATA   
#define CST2_ADDR_UART0_CR            (CST2_ADDR_UART0_BASE + 0x08)	//#define CST2_ADDR_UART0_CR0    
#define CST2_ADDR_UART0_STAT          (CST2_ADDR_UART0_BASE + 0x0C)	//#define CST2_ADDR_UART0_CR1    
#define CST2_ADDR_UART0_CLK           (CST2_ADDR_UART0_BASE + 0x10)	//#define CST2_ADDR_UART0_CR2  



#endif 

