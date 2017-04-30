#ifndef _BMI160GEN_H_
#define _BMI160GEN_H_

//#define BMI160GEN_USE_CURIEIMU
#include "CurieIMU.h"

class BMI160GenClass : public CurieIMUClass {
    public:
        typedef enum { INVALID_MODE = -1, I2C_MODE = 1, SPI_MODE = 2 } Mode;
        bool begin(const int spi_cs_pin = 10, const int intr_pin = 2);
        bool begin(Mode mode, const int arg1 = 0x68, const int arg2 = 2);
        void attachInterrupt(void (*callback)(void));
    protected:
        int interrupt_pin = -1;
        int i2c_addr = -1;
        int spi_ss = -1;
        Mode mode;
        virtual void ss_init();
        virtual int ss_xfer(uint8_t *buf, unsigned tx_cnt, unsigned rx_cnt);
        void i2c_init();
        int i2c_xfer(uint8_t *buf, unsigned tx_cnt, unsigned rx_cnt);
        void spi_init();
        int spi_xfer(uint8_t *buf, unsigned tx_cnt, unsigned rx_cnt);
};

extern BMI160GenClass BMI160;

#endif /* _BMI160GEN_H_ */
