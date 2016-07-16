#include <stdint.h>
#include <SPI.h>

#include "internal/ss_spi.h"

#ifdef __cplusplus
extern "C" {
#endif

int ss_spi_cs = -1;
//#define DEBUG

void ss_spi_init()
{
#ifdef DEBUG
  Serial.println("ss_spi_init()...");
#endif // DEBUG

  // start the SPI library:
  SPI.begin();
  if (0 <= ss_spi_cs) {
    pinMode(ss_spi_cs, OUTPUT);
  } else {
    Serial.println("ss_spi_init(): WARNING: No chip select pin specified.");
  }

#ifdef DEBUG
  Serial.println("ss_spi_init()...done");
#endif // DEBUG
}

int ss_spi_xfer(uint8_t *buf, unsigned tx_cnt, unsigned rx_cnt)
{
  uint8_t *p;

#ifdef DEBUG
  Serial.print("ss_spi_xfer(");
  Serial.print((unsigned long)buf, HEX);
  Serial.print("=");
  Serial.print(*buf, HEX);
  Serial.print(",");
  Serial.print(tx_cnt);
  Serial.print(",");
  Serial.print(rx_cnt);
  Serial.print("):");
#endif // DEBUG

  if (0 <= ss_spi_cs)
    digitalWrite(ss_spi_cs, LOW);
  p = buf;
  while (0 < tx_cnt) {
    tx_cnt--;
    SPI.transfer(*p++);
  }
  p = buf;
  while (0 < rx_cnt) {
    rx_cnt--;
#ifdef DEBUG
    int t = *p++ = SPI.transfer(0);
    Serial.print(" ");
    Serial.print(t, HEX);
#else
    *p++ = SPI.transfer(0);
#endif // DEBUG
  }
  if (0 <= ss_spi_cs)
    digitalWrite(ss_spi_cs, HIGH);

#ifdef DEBUG
  Serial.println("");
#endif // DEBUG

  return (0);
}

#ifdef __cplusplus
}
#endif
