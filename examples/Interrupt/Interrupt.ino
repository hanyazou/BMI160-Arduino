#include <BMI160Gen.h>

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
  BMI160.begin(bmi160_select_pin, bmi160_interrupt_pin);
  BMI160.attachInterrupt(bmi160_intr);
  BMI160.setIntTapEnabled(true);
}

void loop() {
}
