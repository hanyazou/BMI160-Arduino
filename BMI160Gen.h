#ifndef _BMI160GEN_H_
#define _BMI160GEN_H_

//#define BMI160GEN_USE_CURIEIMU
#include "CurieIMU.h"

class BMI160GenClass : public CurieIMUClass {
    protected:
        int interrupt_pin = -1;
    public:
        bool begin(const int spi_cs_pin = -1, const int intr_pin = -1);
        void attachInterrupt(void (*callback)(void));
};

extern BMI160GenClass BMI160;

#endif /* _BMI160GEN_H_ */
