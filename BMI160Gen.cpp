#include "BMI160Gen.h"
#include "internal/ss_spi.h"

bool BMI160GenClass::begin(const int spi_cs_pin)
{
    ss_spi_cs = spi_cs_pin;
    return CurieIMUClass::begin();
}
