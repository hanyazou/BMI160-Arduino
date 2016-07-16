#include "BMI160Gen.h"
#include "internal/ss_spi.h"

#if defined(ARDUINO_ARC32_TOOLS)
#define digitalPinToInterrupt(a) (a)
#endif

bool BMI160GenClass::begin(const int spi_cs_pin, const int intr_pin)
{
    ss_spi_cs = spi_cs_pin;
    if (0 <= intr_pin) {
        interrupt_pin = digitalPinToInterrupt(intr_pin);
    }
    return CurieIMUClass::begin();
}

void BMI160GenClass::attachInterrupt(void (*callback)(void))
{
    CurieIMUClass::attachInterrupt(NULL);
    if (0 <= interrupt_pin) {
        ::attachInterrupt(interrupt_pin, callback, FALLING); 
    } else {
        Serial.println("BMI160GenClass::attachInterrupt: No interruption pin specified.");
    }
}

BMI160GenClass BMI160;
