#include <BMI160Gen.h>

const int bmi160_i2c_addr = 0x68;
const int bmi160_select_pin = 10;
const int bmi160_interrupt_pin = 2;

void bmi160_intr(void)
{
  Serial.println("BMI160 interrupt: TAP!");
}

void setup() {
  Serial.begin(9600); // initialize Serial communication
  while (!Serial);    // wait for the serial port to open

  // initialize device
  Serial.println("Initializing IMU device...");
  BMI160.begin(BMI160GenClass::SPI_MODE, bmi160_select_pin, bmi160_interrupt_pin);
  //BMI160.begin(BMI160GenClass::I2C_MODE, bmi160_i2c_addr, bmi160_interrupt_pin);
  BMI160.attachInterrupt(bmi160_intr);
  BMI160.setIntTapEnabled(true);
  Serial.println("Initializing IMU device...done.");
}

void loop() {
}
