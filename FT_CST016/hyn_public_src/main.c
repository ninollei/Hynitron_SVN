/**************************************************************
*
* File name:   ../public_src/main.c    
*
* Description: Main function start file.
*
* Author:    xx
*
* Version: V1.0  
*
***************************************************************/

#include "all_includes.h"	

#define DUT_PWRON          setAport(CST148_RX12, STAT_LOW)
#define DUT_PWROFF         setAport(CST148_RX12, STAT_HIZ)

int main()
{
	unsigned int testInfo[4];
	unsigned char ret, retry;
	unsigned char idac_value=0;
	unsigned short freq_value=0;
	
	__enable_irq(); 
	NVIC_EnableIRQ(SLP_IRQn); 
		
	initCSD();	//prepare to read following  APORT status	

	DUT_PWROFF;
	pullDownI2C();
	delay1ms(10); 

	DUT_PWRON; 
	delay1ms(10);

	idac_value = 0x00;
	freq_value = 0x0000;

	//trim_delay_640us();

	// 进入PTM模式，检查芯片
	ret = chip_acquire_ptm();	
	if (ret != 0)
		goto End;

	//chip_freq_output_test(); 
	//while(1);	

	//if (FT_IC_TRIMMED == 0)
		//chip_trim_init();	// debug test	
		
	// 检测芯片管脚是否能正常拉高拉低
	ret = chip_pins_test();
	if (ret != 0)
		goto End;

	// 检测芯片电压输出
	ret = chip_vref_test();
	if (ret != 0)
		goto End;

	// 检测芯片电流输出
//	retry = 0;
//Idac_Flow:	
//	idac_value = chip_idac_test();	
//	if (idac_value < 32 || idac_value > 48)
//	{
//		ret = 209;
//		if (retry < MAX_RETRY_TIMES)
//		{
//			retry++;
//			goto Idac_Flow;
//		}
//		goto End;
//	}
//	else
//	{
//		ret = 0;
//	}

	// MTP write 0xFF test	
	ret = chip_mtp_write_test();
	if (ret != 0)
		goto End;

	// 检测芯片频率输出
	retry = 0;
Freq_Flow:		
	freq_value = chip_freq_test(); 
	if (freq_value > 8356 || freq_value < 8027)	// about 2% error
	{
		ret = 210;
		if (retry < MAX_RETRY_TIMES)
		{
			retry++;
			chip_retrim_freq();			
			goto Freq_Flow;
		}
		goto End;
	}
	else 
	{
		ret = 0;
	}	 

	ret = LHIASICPE(0);
	if (ret != 0)
		goto End; 

	ret = chip_trim_read();
	if (ret != 0)
	{
		ret = 243;
		goto End;
	}

End:
	if (ret != 0)
	{	
		testInfo[0] = ret;	//EXPECTED_RESULT_CODE;//		
		testInfo[1] = freq_value;
		testInfo[2] = FT_IC_TYPE; //EXPECTED_PARTNO;  
		testInfo[3] = idac_value; //EXPECTED_I2CCFG;  
	}
	else 
	{
		testInfo[0] = EXPECTED_RESULT_CODE;
		testInfo[1] = freq_value;
		testInfo[2] = FT_IC_TYPE; //EXPECTED_PARTNO;  
		testInfo[3] = idac_value; //EXPECTED_I2CCFG;  
	}	

	delay1ms(10);
	DUT_PWROFF;
	
	outputTestInfo(testInfo);	// 输出测试结果
	
	__WFI();
	__WFI();
	__WFI();
	
	while(1);

}



