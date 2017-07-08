#ifndef __CST0xx_FWI2C_H__
#define __CST0xx_FWI2C_H__

void fwi2c_init(void);
extern void fwi2c_start(void);
extern void fwi2c_stop(void);
extern unsigned char fwi2c_sendBytes(unsigned char *buf, unsigned short num);
extern void fwi2c_getBytes(unsigned char *buf, unsigned short num, unsigned char stopNum);
extern unsigned char fwi2c_write_register(unsigned char type, unsigned short reg, unsigned char data);
extern unsigned char fwi2c_read_register(unsigned char type, unsigned short reg, unsigned char *data);
extern unsigned char fwi2c_write_registers(unsigned char type, unsigned char start_reg,
	unsigned char *src, unsigned short len);
extern unsigned char fwi2c_read_registers(unsigned char type, unsigned char start_reg,
	unsigned char *dst, unsigned short len);
extern void fwi2c_w0(void);
extern void fwi2c_w1(void);


#endif


