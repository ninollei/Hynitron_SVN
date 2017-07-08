
extern void delay1ms(uint16 n);

extern void delay250us(uint16 dly);

extern void setAport(uint16 aport, uint16 stat);

extern void enable_slpTimer(uint16 value);

extern void disable_slpTimer(void);

extern void reset_dut(void);

extern void initCSD(void);

extern void setIDAC(uint8 source, uint8 idac);

extern void pullDownI2C(void);

extern uint8 getAPortVal(uint16 aport);	  

extern void outputTestInfo(uint32 *testInfo);

extern unsigned char chip_acquire_ptm(void);

extern unsigned char chip_pins_test(void);

extern unsigned char chip_vref_test(void);

extern unsigned char chip_idac_test(void);

extern unsigned short chip_freq_test(void);

extern unsigned char chip_trim_init(void);		///just for use for un-trimed IC test

extern unsigned short chip_freq_output_test(void);

extern unsigned char chip_retrim_freq(void);

extern unsigned char chip_writeback_info(void);

extern unsigned char chip_trim_read(void);

extern unsigned char chip_retrim_writeback(void);

extern unsigned char chip_mtp_write_test(void);

extern unsigned char LHIASICPE(unsigned char partName);

extern unsigned char time_parameters_set(void);


void chip_trim_default(void);
void trim_delay_640us(void);
unsigned short chip_freq_output_test(void);



