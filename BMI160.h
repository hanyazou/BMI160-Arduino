/*
===============================================
BMI160 accelerometer/gyroscope library for Intel(R) Curie(TM) devices.
Copyright (c) 2015 Intel Corporation.  All rights reserved.

Based on MPU6050 Arduino library provided by Jeff Rowberg as part of his
excellent I2Cdev device library: https://github.com/jrowberg/i2cdevlib

===============================================
I2Cdev device library code is placed under the MIT license
Copyright (c) 2012 Jeff Rowberg

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
===============================================
*/

#ifndef _BMI160_H_
#define _BMI160_H_

#include "Arduino.h"

/********** Define for magnetometer *************/
#define BMI160_MAG_PMU_STATUS_BIT   0     //Added for BMM150 Support
#define BMI160_MAG_PMU_STATUS_LEN   2     //Added for BMM150 Support

#define BMI160_STATUS_DRDY_MAG      5     //Added for BMM150 Support
#define BMI160_STATUS_MAG_MAN_OP    2     //Added for BMM150 Support
#define BMI160_MAG_RATE_SEL_BIT     0     //Added for BMM150 Support
#define BMI160_MAG_RATE_SEL_LEN     4     //Added for BMM150 Support
#define BMI160_FIFO_MAG_EN_BIT      5     //Added for BMM150 Support

#define BMI160_MAG_IF_0             0x4B  //Added for BMM150 Support
#define BMI160_MAG_IF_1             0x4C  //Added for BMM150 Support
#define BMI160_MAG_IF_2             0x4D  //Added for BMM150 Support
#define BMI160_MAG_IF_3             0x4E  //Added for BMM150 Support
#define BMI160_MAG_IF_4             0x4F  //Added for BMM150 Support

#define BMM150_OK					0x00 //Added for BMM150 Support

#define BMM150_EN_SLEEP_MODE        0x01  //Added for BMM150 Support
//#define BMM150_XY_REPETITIONS       0x04  //Added for BMM150 Support
//#define BMM150_Z_REPETITIONS        0x0E  //Added for BMM150 Support

/**\name POWER MODE DEFINTIONS      */
#define BMM150_NORMAL_MODE		UINT8_C(0x00)
#define BMM150_FORCED_MODE		UINT8_C(0x01)
#define BMM150_SLEEP_MODE		UINT8_C(0x03)
#define BMM150_SUSPEND_MODE		UINT8_C(0x04)

#define BMM150_OP_MODE_BIT			1
#define BMM150_OP_MODE_LEN			2

//**\name PRESET MODES - REPETITIONS-XY RATES */
#define BMM150_LOWPOWER_REPXY       UINT8_C(1)
#define BMM150_REGULAR_REPXY        UINT8_C(4)
#define BMM150_ENHANCED_REPXY       UINT8_C(7)
#define BMM150_HIGHACCURACY_REPXY   UINT8_C(23)

/**\name PRESET MODES - REPETITIONS-Z RATES */
#define BMM150_LOWPOWER_REPZ        UINT8_C(2)
#define BMM150_REGULAR_REPZ         UINT8_C(14)
#define BMM150_ENHANCED_REPZ        UINT8_C(26)
#define BMM150_HIGHACCURACY_REPZ    UINT8_C(82)

#define BMM150_DATA_REG             0x42  //Added for BMM150 Support
#define BMM150_POWER_REG            0x4B  //Added for BMM150 Support
#define BMM150_OPMODE_REG           0x4C  //Added for BMM150 Support
#define BMM150_XY_REP_REG           0x51  //Added for BMM150 Support
#define BMM150_Z_REP_REG            0x52  //Added for BMM150 Support

//Based I2C addr is 0x20 caused it is 0x10 plus one 0 at the end.
#define BMM150_BASED_I2C_ADDR       0x20  //Added for BMM150 Support
#define BMI160_MAG_MAN_EN           0x83  //Added for BMM150 Support
#define BMI160_MAG_MAN_DIS          0x03  //Added for BMM150 Support
#define BMI160_MAG_CONF_25Hz        0x06  //Added for BMM150 Support
#define BMM150_BASED_I2C_MASK		0xFE

#define BMM150_POWER_REG_DEFAULT    0x01  //Added for BMM150 Support
#define BMM150_OPMODE_REG_DEFAULT   0x02  //Added for BMM150 Support
#define BMM150_OPMODE_REG_P         0x06  //Added for BMM150 Support
#define BMM150_R_DATA_ADDR          0x42  //Added for BMM150 Support

//**\name Register Address */
#define BMM150_CHIP_ID_ADDR			UINT8_C(0x40)
#define BMM150_DATA_X_LSB			UINT8_C(0x42)
#define BMM150_DATA_READY_STATUS	UINT8_C(0x48)
#define BMM150_INTERRUPT_STATUS		UINT8_C(0x4A)
#define BMM150_POWER_CONTROL_ADDR	UINT8_C(0x4B)
#define BMM150_OP_MODE_ADDR			UINT8_C(0x4C)
#define BMM150_INT_CONFIG_ADDR		UINT8_C(0x4D)
#define BMM150_AXES_ENABLE_ADDR		UINT8_C(0x4E)
#define BMM150_LOW_THRESHOLD_ADDR	UINT8_C(0x4F)
#define BMM150_HIGH_THRESHOLD_ADDR	UINT8_C(0x50)
#define BMM150_REP_XY_ADDR			UINT8_C(0x51)
#define BMM150_REP_Z_ADDR			UINT8_C(0x52)

//**\name PRESET MODE DEFINITIONS  */
#define BMM150_PRESETMODE_LOWPOWER                 UINT8_C(0x01)
#define BMM150_PRESETMODE_REGULAR                  UINT8_C(0x02)
#define BMM150_PRESETMODE_HIGHACCURACY             UINT8_C(0x03)
#define BMM150_PRESETMODE_ENHANCED                 UINT8_C(0x04)		

//**\name DATA RATE DEFINITIONS  */
#define BMM150_DATA_RATE_10HZ        UINT8_C(0x00)
#define BMM150_DATA_RATE_02HZ        UINT8_C(0x01)
#define BMM150_DATA_RATE_06HZ        UINT8_C(0x02)
#define BMM150_DATA_RATE_08HZ        UINT8_C(0x03)
#define BMM150_DATA_RATE_15HZ        UINT8_C(0x04)
#define BMM150_DATA_RATE_20HZ        UINT8_C(0x05)
#define BMM150_DATA_RATE_25HZ        UINT8_C(0x06)
#define BMM150_DATA_RATE_30HZ        UINT8_C(0x07)

#define BMM150_DATA_RATE_BIT		3
#define BMM150_DATA_RATE_LEN		3

#define BMI160_FOC_CONF_DEFAULT     0x40  //Added for BMM150 Support

#define BMI160_IF_CONF              0x6B  //Added for BMM150 Support

#define BMI160_2ND_INT_MAG          0x20  //Added for BMM150 Support

#define BMI160_EN_PULL_UP_REG_1     0x37  //Added for BMM150 Support
#define BMI160_EN_PULL_UP_REG_2     0x9A  //Added for BMM150 Support
#define BMI160_EN_PULL_UP_REG_3     0xC0  //Added for BMM150 Support
#define BMI160_EN_PULL_UP_REG_4     0x90  //Added for BMM150 Support
#define BMI160_EN_PULL_UP_REG_5     0x80  //Added for BMM150 Support

#define BMI160_7F                   0x7F  //Added for BMM150 Support

#define BMI160_CMD_MAG_MODE_NORMAL  0x19  //Added for BMM150 Support

#define BMI160_RA_MAG_X_L           0x04  //Added for BMM150 Support
#define BMI160_RA_MAG_X_H           0x05  //Added for BMM150 Support
#define BMI160_RA_MAG_Y_L           0x06  //Added for BMM150 Support
#define BMI160_RA_MAG_Y_H           0x07  //Added for BMM150 Support
#define BMI160_RA_MAG_Z_L           0x08  //Added for BMM150 Support
#define BMI160_RA_MAG_Z_H           0x09  //Added for BMM150 Support
#define BMI160_RA_MAG_R_L           0x0A  //Added for BMM150 Support
#define BMI160_RA_MAG_R_H           0x0B  //Added for BMM150 Support

//#define BMI160_RA_MAG_CONF          0X44  //Added for BMM150 Support
#define BMI160_AUX_ODR_ADDR         UINT8_C(0x44) //Added for BMM150 Support

/**************************/

#define BMI160_SPI_READ_BIT         7

#define BMI160_RA_CHIP_ID           0x00

#define BMI160_ACC_PMU_STATUS_BIT   4
#define BMI160_ACC_PMU_STATUS_LEN   2
#define BMI160_GYR_PMU_STATUS_BIT   2
#define BMI160_GYR_PMU_STATUS_LEN   2

#define BMI160_RA_PMU_STATUS        0x03

#define BMI160_RA_GYRO_X_L          0x0C
#define BMI160_RA_GYRO_X_H          0x0D
#define BMI160_RA_GYRO_Y_L          0x0E
#define BMI160_RA_GYRO_Y_H          0x0F
#define BMI160_RA_GYRO_Z_L          0x10
#define BMI160_RA_GYRO_Z_H          0x11
#define BMI160_RA_ACCEL_X_L         0x12
#define BMI160_RA_ACCEL_X_H         0x13
#define BMI160_RA_ACCEL_Y_L         0x14
#define BMI160_RA_ACCEL_Y_H         0x15
#define BMI160_RA_ACCEL_Z_L         0x16
#define BMI160_RA_ACCEL_Z_H         0x17

#define BMI160_STATUS_FOC_RDY       3
#define BMI160_STATUS_NVM_RDY       4
#define BMI160_STATUS_DRDY_GYR      6
#define BMI160_STATUS_DRDY_ACC      7

#define BMI160_RA_STATUS            0x1B

#define BMI160_STEP_INT_BIT         0
#define BMI160_ANYMOTION_INT_BIT    2
#define BMI160_D_TAP_INT_BIT        4
#define BMI160_S_TAP_INT_BIT        5
#define BMI160_NOMOTION_INT_BIT     7
#define BMI160_FFULL_INT_BIT        5
#define BMI160_DRDY_INT_BIT         4
#define BMI160_LOW_G_INT_BIT        3
#define BMI160_HIGH_G_INT_BIT       2

#define BMI160_TAP_SIGN_BIT         7
#define BMI160_TAP_1ST_Z_BIT        6
#define BMI160_TAP_1ST_Y_BIT        5
#define BMI160_TAP_1ST_X_BIT        4

#define BMI160_ANYMOTION_SIGN_BIT   3
#define BMI160_ANYMOTION_1ST_Z_BIT  2
#define BMI160_ANYMOTION_1ST_Y_BIT  1
#define BMI160_ANYMOTION_1ST_X_BIT  0

#define BMI160_HIGH_G_SIGN_BIT      3
#define BMI160_HIGH_G_1ST_Z_BIT     2
#define BMI160_HIGH_G_1ST_Y_BIT     1
#define BMI160_HIGH_G_1ST_X_BIT     0

#define BMI160_RA_INT_STATUS_0      0x1C
#define BMI160_RA_INT_STATUS_1      0x1D
#define BMI160_RA_INT_STATUS_2      0x1E
#define BMI160_RA_INT_STATUS_3      0x1F

#define BMI160_RA_TEMP_L            0x20
#define BMI160_RA_TEMP_H            0x21

#define BMI160_RA_FIFO_LENGTH_0     0x22
#define BMI160_RA_FIFO_LENGTH_1     0x23

#define BMI160_FIFO_DATA_INVALID    0x80
#define BMI160_RA_FIFO_DATA         0x24

#define BMI160_ACCEL_RATE_SEL_BIT    0
#define BMI160_ACCEL_RATE_SEL_LEN    4

#define BMI160_RA_ACCEL_CONF        0X40
#define BMI160_RA_ACCEL_RANGE       0X41

#define BMI160_GYRO_RATE_SEL_BIT    0
#define BMI160_GYRO_RATE_SEL_LEN    4

#define BMI160_RA_GYRO_CONF         0X42
#define BMI160_RA_GYRO_RANGE        0X43

#define BMI160_FIFO_HEADER_EN_BIT   4
#define BMI160_FIFO_ACC_EN_BIT      6
#define BMI160_FIFO_GYR_EN_BIT      7

#define BMI160_RA_FIFO_CONFIG_0     0x46
#define BMI160_RA_FIFO_CONFIG_1     0x47

#define MAX_FIFO_BYTES				1024

#define BMI160_ANYMOTION_EN_BIT     0
#define BMI160_ANYMOTION_EN_LEN     3
#define BMI160_D_TAP_EN_BIT         4
#define BMI160_S_TAP_EN_BIT         5
#define BMI160_NOMOTION_EN_BIT      0
#define BMI160_NOMOTION_EN_LEN      3
#define BMI160_LOW_G_EN_BIT         3
#define BMI160_LOW_G_EN_LEN         1
#define BMI160_HIGH_G_EN_BIT        0
#define BMI160_HIGH_G_EN_LEN        3

#define BMI160_STEP_EN_BIT          3
#define BMI160_DRDY_EN_BIT          4
#define BMI160_FFULL_EN_BIT         5

#define BMI160_RA_INT_EN_0          0x50
#define BMI160_RA_INT_EN_1          0x51
#define BMI160_RA_INT_EN_2          0x52

#define BMI160_INT1_EDGE_CTRL       0
#define BMI160_INT1_LVL             1
#define BMI160_INT1_OD              2
#define BMI160_INT1_OUTPUT_EN       3

#define BMI160_RA_INT_OUT_CTRL      0x53

#define BMI160_LATCH_MODE_BIT       0
#define BMI160_LATCH_MODE_LEN       4

#define BMI160_RA_INT_LATCH         0x54
#define BMI160_RA_INT_MAP_0         0x55
#define BMI160_RA_INT_MAP_1         0x56
#define BMI160_RA_INT_MAP_2         0x57

#define BMI160_ANYMOTION_DUR_BIT    0
#define BMI160_ANYMOTION_DUR_LEN    2
#define BMI160_NOMOTION_DUR_BIT     2
#define BMI160_NOMOTION_DUR_LEN     6

#define BMI160_NOMOTION_SEL_BIT     0
#define BMI160_NOMOTION_SEL_LEN     1

#define BMI160_RA_INT_LOWHIGH_0     0x5A
#define BMI160_RA_INT_LOWHIGH_1     0x5B
#define BMI160_RA_INT_LOWHIGH_2     0x5C
#define BMI160_RA_INT_LOWHIGH_3     0x5D
#define BMI160_RA_INT_LOWHIGH_4     0x5E

#define BMI160_RA_INT_MOTION_0      0x5F
#define BMI160_RA_INT_MOTION_1      0x60
#define BMI160_RA_INT_MOTION_2      0x61
#define BMI160_RA_INT_MOTION_3      0x62

#define BMI160_TAP_DUR_BIT          0
#define BMI160_TAP_DUR_LEN          3
#define BMI160_TAP_SHOCK_BIT        6
#define BMI160_TAP_QUIET_BIT        7
#define BMI160_TAP_THRESH_BIT       0
#define BMI160_TAP_THRESH_LEN       5

#define BMI160_RA_INT_TAP_0         0x63
#define BMI160_RA_INT_TAP_1         0x64

#define BMI160_FOC_ACC_Z_BIT        0
#define BMI160_FOC_ACC_Z_LEN        2
#define BMI160_FOC_ACC_Y_BIT        2
#define BMI160_FOC_ACC_Y_LEN        2
#define BMI160_FOC_ACC_X_BIT        4
#define BMI160_FOC_ACC_X_LEN        2
#define BMI160_FOC_GYR_EN           6

#define BMI160_RA_FOC_CONF          0x69

#define BMI160_GYR_OFFSET_X_MSB_BIT 0
#define BMI160_GYR_OFFSET_X_MSB_LEN 2
#define BMI160_GYR_OFFSET_Y_MSB_BIT 2
#define BMI160_GYR_OFFSET_Y_MSB_LEN 2
#define BMI160_GYR_OFFSET_Z_MSB_BIT 4
#define BMI160_GYR_OFFSET_Z_MSB_LEN 2
#define BMI160_ACC_OFFSET_EN        6
#define BMI160_GYR_OFFSET_EN        7

#define BMI160_RA_OFFSET_0          0x71
#define BMI160_RA_OFFSET_1          0x72
#define BMI160_RA_OFFSET_2          0x73
#define BMI160_RA_OFFSET_3          0x74
#define BMI160_RA_OFFSET_4          0x75
#define BMI160_RA_OFFSET_5          0x76
#define BMI160_RA_OFFSET_6          0x77

#define BMI160_RA_STEP_CNT_L        0x78
#define BMI160_RA_STEP_CNT_H        0x79

#define BMI160_STEP_BUF_MIN_BIT     0
#define BMI160_STEP_BUF_MIN_LEN     3
#define BMI160_STEP_CNT_EN_BIT      3

#define BMI160_STEP_TIME_MIN_BIT    0
#define BMI160_STEP_TIME_MIN_LEN    3
#define BMI160_STEP_THRESH_MIN_BIT  3
#define BMI160_STEP_THRESH_MIN_LEN  2
#define BMI160_STEP_ALPHA_BIT       5
#define BMI160_STEP_ALPHA_LEN       3

#define BMI160_RA_STEP_CONF_0       0x7A
#define BMI160_RA_STEP_CONF_1       0x7B

#define BMI160_RA_STEP_CONF_0_NOR   0x15
#define BMI160_RA_STEP_CONF_0_SEN   0x2D
#define BMI160_RA_STEP_CONF_0_ROB   0x1D
#define BMI160_RA_STEP_CONF_1_NOR   0x03
#define BMI160_RA_STEP_CONF_1_SEN   0x00
#define BMI160_RA_STEP_CONF_1_ROB   0x07


#define BMI160_GYRO_RANGE_SEL_BIT   0
#define BMI160_GYRO_RANGE_SEL_LEN   3

#define BMI160_GYRO_RATE_SEL_BIT    0
#define BMI160_GYRO_RATE_SEL_LEN    4

#define BMI160_GYRO_DLPF_SEL_BIT    4
#define BMI160_GYRO_DLPF_SEL_LEN    2

#define BMI160_ACCEL_DLPF_SEL_BIT   4
#define BMI160_ACCEL_DLPF_SEL_LEN   3

#define BMI160_ACCEL_RANGE_SEL_BIT  0
#define BMI160_ACCEL_RANGE_SEL_LEN  4

#define BMI160_CMD_START_FOC        0x03
#define BMI160_CMD_ACC_MODE_NORMAL  0x11
#define BMI160_CMD_GYR_MODE_NORMAL  0x15
#define BMI160_CMD_FIFO_FLUSH       0xB0
#define BMI160_CMD_INT_RESET        0xB1
#define BMI160_CMD_STEP_CNT_CLR     0xB2
#define BMI160_CMD_SOFT_RESET       0xB6

#define BMI160_RA_CMD               0x7E

//** Enable/disable bit value */
#define BMI160_ENABLE                        UINT8_C(0x01)
#define BMI160_DISABLE                       UINT8_C(0x00)

//Added for getMotion9() and convertMagneto[X-Z]() support

//Define Overflow Constants for MagnetoConversion on BMM150
#define BMM150_XYAXES_FLIP_OVERFLOW_ADCVAL  INT16_C(-4096)
#define BMM150_ZAXIS_HALL_OVERFLOW_ADCVAL   INT16_C(-16384)
#define BMM150_OVERFLOW_OUTPUT_FLOAT        0.0f

//Important BMM150 Registers
#define BMM150_DIG_X1                   UINT8_C(0x5D)
#define BMM150_DIG_Z4_LSB               UINT8_C(0x62)
#define BMM150_DIG_Z2_LSB               UINT8_C(0x68)

//Delays, in milliseconds
#define BMI160_AUX_COM_DELAY            UINT8_C(10)
#define BMI160_READ_WRITE_DELAY         UINT8_C(1)

//Bit Masks for MAG_IF[1]
#define BMI160_MANUAL_MODE_EN_MSK       UINT8_C(0x80)
#define BMI160_AUX_READ_BURST_MSK       UINT8_C(0x03)

//Bit Masks and POS for LSB registers
#define BMM150_DATA_X_MSK       UINT8_C(0xF8)
#define BMM150_DATA_X_POS       UINT8_C(0x03)

#define BMM150_DATA_Y_MSK       UINT8_C(0xF8)
#define BMM150_DATA_Y_POS       UINT8_C(0x03)

#define BMM150_DATA_Z_MSK       UINT8_C(0xFE)
#define BMM150_DATA_Z_POS       UINT8_C(0x01)

#define BMM150_DATA_RHALL_MSK       UINT8_C(0xFC)
#define BMM150_DATA_RHALL_POS       UINT8_C(0x02)

#define BMM150_GET_BITS(reg_data, bitname)  ((reg_data & (bitname##_MSK)) >> (bitname##_POS))


/** Bandwidth settings */
/* Accel Bandwidth */
#define BMI160_ACCEL_BW_OSR4_AVG1            UINT8_C(0x00)
#define BMI160_ACCEL_BW_OSR2_AVG2            UINT8_C(0x01)
#define BMI160_ACCEL_BW_NORMAL_AVG4          UINT8_C(0x02)
#define BMI160_ACCEL_BW_RES_AVG8             UINT8_C(0x03)
#define BMI160_ACCEL_BW_RES_AVG16            UINT8_C(0x04)
#define BMI160_ACCEL_BW_RES_AVG32            UINT8_C(0x05)
#define BMI160_ACCEL_BW_RES_AVG64            UINT8_C(0x06)
#define BMI160_ACCEL_BW_RES_AVG128           UINT8_C(0x07)

#define BMI160_GYRO_BW_OSR4_MODE             UINT8_C(0x00)
#define BMI160_GYRO_BW_OSR2_MODE             UINT8_C(0x01)
#define BMI160_GYRO_BW_NORMAL_MODE           UINT8_C(0x02)
                            
/**
 * Interrupt Latch Mode options
 * @see setInterruptLatch()
 */
typedef enum {
    BMI160_LATCH_MODE_NONE = 0, /**< Non-latched */
    BMI160_LATCH_MODE_312_5_US, /**< Temporary, 312.50 microseconds */
    BMI160_LATCH_MODE_625_US,   /**< Temporary, 625.00 microseconds */
    BMI160_LATCH_MODE_1_25_MS,  /**< Temporary,   1.25 milliseconds */
    BMI160_LATCH_MODE_2_5_MS,   /**< Temporary,   2.50 milliseconds */
    BMI160_LATCH_MODE_5_MS,     /**< Temporary,   5.00 milliseconds */
    BMI160_LATCH_MODE_10_MS,    /**< Temporary,  10.00 milliseconds */
    BMI160_LATCH_MODE_20_MS,    /**< Temporary,  20.00 milliseconds */
    BMI160_LATCH_MODE_40_MS,    /**< Temporary,  40.00 milliseconds */
    BMI160_LATCH_MODE_80_MS,    /**< Temporary,  80.00 milliseconds */
    BMI160_LATCH_MODE_160_MS,   /**< Temporary, 160.00 milliseconds */
    BMI160_LATCH_MODE_320_MS,   /**< Temporary, 320.00 milliseconds */
    BMI160_LATCH_MODE_640_MS,   /**< Temporary, 640.00 milliseconds */
    BMI160_LATCH_MODE_1_28_S,   /**< Temporary,   1.28 seconds      */
    BMI160_LATCH_MODE_2_56_S,   /**< Temporary,   2.56 seconds      */
    BMI160_LATCH_MODE_LATCH,    /**< Latched, @see resetInterrupt() */
} BMI160InterruptLatchMode;

/**
 * Digital Low-Pass Filter Mode options
 * @see setGyroDLPFMode()
 * @see setAccelDLPFMode()
 */
typedef enum {
    BMI160_DLPF_MODE_NORM = 0x2,
    BMI160_DLPF_MODE_OSR2 = 0x1,
    BMI160_DLPF_MODE_OSR4 = 0x0,
} BMI160DLPFMode;

/**
 * Accelerometer Sensitivity Range options
 * @see setFullScaleAccelRange()
 */
typedef enum {
    BMI160_ACCEL_RANGE_2G  = 0X03, /**<  +/-  2g range */
    BMI160_ACCEL_RANGE_4G  = 0X05, /**<  +/-  4g range */
    BMI160_ACCEL_RANGE_8G  = 0X08, /**<  +/-  8g range */
    BMI160_ACCEL_RANGE_16G = 0X0C, /**<  +/- 16g range */
} BMI160AccelRange;

/**
 * Gyroscope Sensitivity Range options
 * @see setFullScaleGyroRange()
 */
typedef enum {
    BMI160_GYRO_RANGE_2000 = 0, /**<  +/- 2000 degrees/second */
    BMI160_GYRO_RANGE_1000,     /**<  +/- 1000 degrees/second */
    BMI160_GYRO_RANGE_500,      /**<  +/-  500 degrees/second */
    BMI160_GYRO_RANGE_250,      /**<  +/-  250 degrees/second */
    BMI160_GYRO_RANGE_125,      /**<  +/-  125 degrees/second */
} BMI160GyroRange;

/**
 * Accelerometer Output Data Rate options
 * @see setAccelRate()
 */
typedef enum {
    BMI160_ACCEL_RATE_25_2HZ = 5,  /**<   25/2  Hz */
    BMI160_ACCEL_RATE_25HZ,        /**<   25    Hz */
    BMI160_ACCEL_RATE_50HZ,        /**<   50    Hz */
    BMI160_ACCEL_RATE_100HZ,       /**<  100    Hz */
    BMI160_ACCEL_RATE_200HZ,       /**<  200    Hz */
    BMI160_ACCEL_RATE_400HZ,       /**<  400    Hz */
    BMI160_ACCEL_RATE_800HZ,       /**<  800    Hz */
    BMI160_ACCEL_RATE_1600HZ,      /**< 1600    Hz */
} BMI160AccelRate;

/**
 * Gyroscope Output Data Rate options
 * @see setGyroRate()
 */
typedef enum {
    BMI160_GYRO_RATE_25HZ = 6,     /**<   25    Hz */
    BMI160_GYRO_RATE_50HZ,         /**<   50    Hz */
    BMI160_GYRO_RATE_100HZ,        /**<  100    Hz */
    BMI160_GYRO_RATE_200HZ,        /**<  200    Hz */
    BMI160_GYRO_RATE_400HZ,        /**<  400    Hz */
    BMI160_GYRO_RATE_800HZ,        /**<  800    Hz */
    BMI160_GYRO_RATE_1600HZ,       /**< 1600    Hz */
    BMI160_GYRO_RATE_3200HZ,       /**< 3200    Hz */
} BMI160GyroRate;

/**
 * Magnetometer Output Data Rate options
 * @see setMagRate()
 */
typedef enum {                          //Added for BMM150 Support
    BMI160_MAG_RATE_25_32HZ = 1,   /**<  25/32  Hz */
    BMI160_MAG_RATE_25_16HZ,       /**<  25/16  Hz */
    BMI160_MAG_RATE_25_8HZ,        /**<  25/8   Hz */
    BMI160_MAG_RATE_25_4HZ,        /**<  25/4   Hz */
    BMI160_MAG_RATE_25_2HZ,        /**<  25/2   Hz */
    BMI160_MAG_RATE_25HZ,          /**<  25     Hz */
    BMI160_MAG_RATE_50HZ,          /**<  50     Hz */
    BMI160_MAG_RATE_100HZ,         /**<  100    Hz */
    BMI160_MAG_RATE_200HZ,         /**<  200    Hz */
    BMI160_MAG_RATE_400HZ,         /**<  400    Hz */
    BMI160_MAG_RATE_800HZ,         /**<  800    Hz */
} BMI160MagRate;

/**
 * Step Detection Mode options
 * @see setStepDetectionMode()
 */
typedef enum {
    BMI160_STEP_MODE_NORMAL = 0,
    BMI160_STEP_MODE_SENSITIVE,
    BMI160_STEP_MODE_ROBUST,
    BMI160_STEP_MODE_UNKNOWN,
} BMI160StepMode;

/**
 * Tap Detection Shock Duration options
 * @see setTapShockDuration()
 */
typedef enum {
    BMI160_TAP_SHOCK_DURATION_50MS = 0,
    BMI160_TAP_SHOCK_DURATION_75MS,
} BMI160TapShockDuration;

/**
 * Tap Detection Quiet Duration options
 * @see setTapQuietDuration()
 */
typedef enum {
    BMI160_TAP_QUIET_DURATION_30MS = 0,
    BMI160_TAP_QUIET_DURATION_20MS,
} BMI160TapQuietDuration;

/**
 * Double-Tap Detection Duration options
 * @see setDoubleTapDetectionDuration()
 */
typedef enum {
    BMI160_DOUBLE_TAP_DURATION_50MS = 0,
    BMI160_DOUBLE_TAP_DURATION_100MS,
    BMI160_DOUBLE_TAP_DURATION_150MS,
    BMI160_DOUBLE_TAP_DURATION_200MS,
    BMI160_DOUBLE_TAP_DURATION_250MS,
    BMI160_DOUBLE_TAP_DURATION_375MS,
    BMI160_DOUBLE_TAP_DURATION_500MS,
    BMI160_DOUBLE_TAP_DURATION_700MS,
} BMI160DoubleTapDuration;

/**
 * Zero-Motion Detection Duration options
 * @see setZeroMotionDetectionDuration()
 */
typedef enum {
    BMI160_ZERO_MOTION_DURATION_1_28S   = 0x00, /**<   1.28 seconds */
    BMI160_ZERO_MOTION_DURATION_2_56S,          /**<   2.56 seconds */
    BMI160_ZERO_MOTION_DURATION_3_84S,          /**<   3.84 seconds */
    BMI160_ZERO_MOTION_DURATION_5_12S,          /**<   5.12 seconds */
    BMI160_ZERO_MOTION_DURATION_6_40S,          /**<   6.40 seconds */
    BMI160_ZERO_MOTION_DURATION_7_68S,          /**<   7.68 seconds */
    BMI160_ZERO_MOTION_DURATION_8_96S,          /**<   8.96 seconds */
    BMI160_ZERO_MOTION_DURATION_10_24S,         /**<  10.24 seconds */
    BMI160_ZERO_MOTION_DURATION_11_52S,         /**<  11.52 seconds */
    BMI160_ZERO_MOTION_DURATION_12_80S,         /**<  12.80 seconds */
    BMI160_ZERO_MOTION_DURATION_14_08S,         /**<  14.08 seconds */
    BMI160_ZERO_MOTION_DURATION_15_36S,         /**<  15.36 seconds */
    BMI160_ZERO_MOTION_DURATION_16_64S,         /**<  16.64 seconds */
    BMI160_ZERO_MOTION_DURATION_17_92S,         /**<  17.92 seconds */
    BMI160_ZERO_MOTION_DURATION_19_20S,         /**<  19.20 seconds */
    BMI160_ZERO_MOTION_DURATION_20_48S,         /**<  20.48 seconds */
    BMI160_ZERO_MOTION_DURATION_25_60S  = 0x10, /**<  25.60 seconds */
    BMI160_ZERO_MOTION_DURATION_30_72S,         /**<  30.72 seconds */
    BMI160_ZERO_MOTION_DURATION_35_84S,         /**<  35.84 seconds */
    BMI160_ZERO_MOTION_DURATION_40_96S,         /**<  40.96 seconds */
    BMI160_ZERO_MOTION_DURATION_46_08S,         /**<  46.08 seconds */
    BMI160_ZERO_MOTION_DURATION_51_20S,         /**<  51.20 seconds */
    BMI160_ZERO_MOTION_DURATION_56_32S,         /**<  56.32 seconds */
    BMI160_ZERO_MOTION_DURATION_61_44S,         /**<  61.44 seconds */
    BMI160_ZERO_MOTION_DURATION_66_56S,         /**<  66.56 seconds */
    BMI160_ZERO_MOTION_DURATION_71_68S,         /**<  71.68 seconds */
    BMI160_ZERO_MOTION_DURATION_76_80S,         /**<  76.80 seconds */
    BMI160_ZERO_MOTION_DURATION_81_92S,         /**<  81.92 seconds */
    BMI160_ZERO_MOTION_DURATION_87_04S,         /**<  87.04 seconds */
    BMI160_ZERO_MOTION_DURATION_92_16S,         /**<  92.16 seconds */
    BMI160_ZERO_MOTION_DURATION_97_28S,         /**<  97.28 seconds */
    BMI160_ZERO_MOTION_DURATION_102_40S,        /**< 102.40 seconds */
    BMI160_ZERO_MOTION_DURATION_112_64S = 0x20, /**< 112.64 seconds */
    BMI160_ZERO_MOTION_DURATION_122_88S,        /**< 122.88 seconds */
    BMI160_ZERO_MOTION_DURATION_133_12S,        /**< 133.12 seconds */
    BMI160_ZERO_MOTION_DURATION_143_36S,        /**< 143.36 seconds */
    BMI160_ZERO_MOTION_DURATION_153_60S,        /**< 153.60 seconds */
    BMI160_ZERO_MOTION_DURATION_163_84S,        /**< 163.84 seconds */
    BMI160_ZERO_MOTION_DURATION_174_08S,        /**< 174.08 seconds */
    BMI160_ZERO_MOTION_DURATION_184_32S,        /**< 184.32 seconds */
    BMI160_ZERO_MOTION_DURATION_194_56S,        /**< 194.56 seconds */
    BMI160_ZERO_MOTION_DURATION_204_80S,        /**< 204.80 seconds */
    BMI160_ZERO_MOTION_DURATION_215_04S,        /**< 215.04 seconds */
    BMI160_ZERO_MOTION_DURATION_225_28S,        /**< 225.28 seconds */
    BMI160_ZERO_MOTION_DURATION_235_52S,        /**< 235.52 seconds */
    BMI160_ZERO_MOTION_DURATION_245_76S,        /**< 245.76 seconds */
    BMI160_ZERO_MOTION_DURATION_256_00S,        /**< 256.00 seconds */
    BMI160_ZERO_MOTION_DURATION_266_24S,        /**< 266.24 seconds */
    BMI160_ZERO_MOTION_DURATION_276_48S,        /**< 276.48 seconds */
    BMI160_ZERO_MOTION_DURATION_286_72S,        /**< 286.72 seconds */
    BMI160_ZERO_MOTION_DURATION_296_96S,        /**< 296.96 seconds */
    BMI160_ZERO_MOTION_DURATION_307_20S,        /**< 307.20 seconds */
    BMI160_ZERO_MOTION_DURATION_317_44S,        /**< 317.44 seconds */
    BMI160_ZERO_MOTION_DURATION_327_68S,        /**< 327.68 seconds */
    BMI160_ZERO_MOTION_DURATION_337_92S,        /**< 337.92 seconds */
    BMI160_ZERO_MOTION_DURATION_348_16S,        /**< 348.16 seconds */
    BMI160_ZERO_MOTION_DURATION_358_40S,        /**< 358.40 seconds */
    BMI160_ZERO_MOTION_DURATION_368_64S,        /**< 368.64 seconds */
    BMI160_ZERO_MOTION_DURATION_378_88S,        /**< 378.88 seconds */
    BMI160_ZERO_MOTION_DURATION_389_12S,        /**< 389.12 seconds */
    BMI160_ZERO_MOTION_DURATION_399_36S,        /**< 399.36 seconds */
    BMI160_ZERO_MOTION_DURATION_409_60S,        /**< 409.60 seconds */
    BMI160_ZERO_MOTION_DURATION_419_84S,        /**< 419.84 seconds */
    BMI160_ZERO_MOTION_DURATION_430_08S,        /**< 430.08 seconds */
} BMI160ZeroMotionDuration;

class BMI160Class {
    public:
        void initialize();
        bool testConnection();
		
		uint8_t getMagRate();                    //Added for BMM150 Support
        void setMagRate(uint8_t rate);           //Added for BMM150 Support

        uint8_t getGyroRate();
        void setGyroRate(uint8_t rate);

        uint8_t getAccelRate();
        void setAccelRate(uint8_t rate);

        uint8_t getGyroDLPFMode();
        void setGyroDLPFMode(uint8_t bandwidth);

        uint8_t getAccelDLPFMode();
        void setAccelDLPFMode(uint8_t bandwidth);

        uint8_t getFullScaleGyroRange();
        void setFullScaleGyroRange(uint8_t range);
        uint8_t getFullScaleAccelRange();
        void setFullScaleAccelRange(uint8_t range);

        void autoCalibrateGyroOffset();
        bool getGyroOffsetEnabled();
        void setGyroOffsetEnabled(bool enabled);

        int16_t getXGyroOffset();
        void setXGyroOffset(int16_t offset);
        int16_t getYGyroOffset();
        void setYGyroOffset(int16_t offset);
        int16_t getZGyroOffset();
        void setZGyroOffset(int16_t offset);

        void autoCalibrateXAccelOffset(int target);
        void autoCalibrateYAccelOffset(int target);
        void autoCalibrateZAccelOffset(int target);
        bool getAccelOffsetEnabled();
        void setAccelOffsetEnabled(bool enabled);

        int8_t getXAccelOffset();
        void setXAccelOffset(int8_t offset);
        int8_t getYAccelOffset();
        void setYAccelOffset(int8_t offset);
        int8_t getZAccelOffset();
        void setZAccelOffset(int8_t offset);

        uint8_t getFreefallDetectionThreshold();
        void setFreefallDetectionThreshold(uint8_t threshold);

        uint8_t getFreefallDetectionDuration();
        void setFreefallDetectionDuration(uint8_t duration);

        uint8_t getShockDetectionThreshold();
        void setShockDetectionThreshold(uint8_t threshold);

        uint8_t getShockDetectionDuration();
        void setShockDetectionDuration(uint8_t duration);

		uint8_t getMotionDetectionThreshold();
		void setMotionDetectionThreshold(uint8_t threshold);

		uint8_t getMotionDetectionDuration();
		void setMotionDetectionDuration(uint8_t duration);

        uint8_t getZeroMotionDetectionThreshold();
        void setZeroMotionDetectionThreshold(uint8_t threshold);

        uint8_t getZeroMotionDetectionDuration();
        void setZeroMotionDetectionDuration(uint8_t duration);

        uint8_t getTapDetectionThreshold();
        void setTapDetectionThreshold(uint8_t threshold);

        bool getTapShockDuration();
        void setTapShockDuration(bool duration);

        bool getTapQuietDuration();
        void setTapQuietDuration(bool duration);

        uint8_t getDoubleTapDetectionDuration();
        void setDoubleTapDetectionDuration(uint8_t duration);

        uint8_t getStepDetectionMode();
        void setStepDetectionMode(BMI160StepMode mode);
        bool getStepCountEnabled();
        void setStepCountEnabled(bool enabled);
        uint16_t getStepCount();
        void resetStepCount();

        bool getIntFreefallEnabled();
        void setIntFreefallEnabled(bool enabled);
        bool getIntShockEnabled();
        void setIntShockEnabled(bool enabled);
        bool getIntStepEnabled();
        void setIntStepEnabled(bool enabled);
        bool getIntMotionEnabled();
        void setIntMotionEnabled(bool enabled);
        bool getIntZeroMotionEnabled();
        void setIntZeroMotionEnabled(bool enabled);
        bool getIntTapEnabled();
        void setIntTapEnabled(bool enabled);
        bool getIntDoubleTapEnabled();
        void setIntDoubleTapEnabled(bool enabled);

        bool getGyroFIFOEnabled();
        void setGyroFIFOEnabled(bool enabled);
        bool getAccelFIFOEnabled();
        void setAccelFIFOEnabled(bool enabled);
		bool getMagFIFOEnabled();                   //Added for BMM150 Support
        void setMagFIFOEnabled(bool enabled);       //Added for BMM150 Support
		
		bool getIntFIFOBufferFullEnabled();
        void setIntFIFOBufferFullEnabled(bool enabled);
        bool getIntDataReadyEnabled();
        void setIntDataReadyEnabled(bool enabled);
		
        uint8_t getIntStatus0();
        uint8_t getIntStatus1();
        uint8_t getIntStatus2();
        uint8_t getIntStatus3();
        bool getIntFreefallStatus();
        bool getIntShockStatus();
        bool getIntStepStatus();
        bool getIntMotionStatus();
        bool getIntZeroMotionStatus();
        bool getIntTapStatus();
        bool getIntDoubleTapStatus();
        bool getIntFIFOBufferFullStatus();
        bool getIntDataReadyStatus();

        void getMotion6(int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz);
        void getMotion9(int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz, int16_t* mx, int16_t* my, int16_t* mz, uint16_t* rh);		//Added for BMM150 Support
		void extractMotion9(uint8_t* buffer, int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz, int16_t* mx, int16_t* my, int16_t* mz, uint16_t* rh);		//Added for BMM150 Support
		void getAcceleration(int16_t* x, int16_t* y, int16_t* z);
        int16_t getAccelerationX();
        int16_t getAccelerationY();
        int16_t getAccelerationZ();

        int16_t getTemperature();

        void getRotation(int16_t* x, int16_t* y, int16_t* z);
        int16_t getRotationX();
        int16_t getRotationY();
        int16_t getRotationZ();

        //DO NOT USE: UNTESTED, but changed to match getMotion9()
        // void getMagneto(int16_t* mx, int16_t* my, int16_t* mz, uint16_t* rh);     //Added for BMM150 Support
        // int16_t getMagnetoX();                                                    //Added for BMM150 Support
        // int16_t getMagnetoY();                                                    //Added for BMM150 Support
        // int16_t getMagnetoZ();                                                    //Added for BMM150 Support
        // uint16_t getRHall();

        bool getXNegShockDetected();
        bool getXPosShockDetected();
        bool getYNegShockDetected();
        bool getYPosShockDetected();
        bool getZNegShockDetected();
        bool getZPosShockDetected();

        bool getXNegMotionDetected();
        bool getXPosMotionDetected();
        bool getYNegMotionDetected();
        bool getYPosMotionDetected();
        bool getZNegMotionDetected();
        bool getZPosMotionDetected();

        bool getXNegTapDetected();
        bool getXPosTapDetected();
        bool getYNegTapDetected();
        bool getYPosTapDetected();
        bool getZNegTapDetected();
        bool getZPosTapDetected();

        bool getFIFOHeaderModeEnabled();
        void setFIFOHeaderModeEnabled(bool enabled);
        void resetFIFO();

        uint16_t getFIFOCount();
        void getFIFOBytes(uint8_t *data, uint16_t length);

        uint8_t getDeviceID();

        uint8_t getRegister(uint8_t reg);
        void setRegister(uint8_t reg, uint8_t data);
		void setRegister(uint8_t reg, uint8_t data, uint8_t bitMask);

        bool getIntEnabled();
        void setIntEnabled(bool enabled);
        bool getInterruptMode();
        void setInterruptMode(bool mode);
        bool getInterruptDrive();
        void setInterruptDrive(bool drive);
        uint8_t getInterruptLatch();
        void setInterruptLatch(uint8_t latch);
        void resetInterrupt();

        void reg_write_bits(uint8_t reg, uint8_t data, unsigned pos, unsigned len);
        //Added for a better hibernate function
        //Puts Accel, Gyro, and Mag into suspend mode, for low power consumption
        //Time to exectute function is untested; while() is present
        void suspendIMU();

    protected:
        virtual int serial_buffer_transfer(uint8_t *buf, unsigned tx_cnt, unsigned rx_cnt);

    private:
        uint8_t reg_read (uint8_t reg);
        void reg_write(uint8_t reg, uint8_t data);
        uint8_t reg_read_bits(uint8_t reg, unsigned pos, unsigned len);
        bool get_bit(uint8_t num, uint8_t bit); //some cases this may be useful for when the register is already read
};

#endif /* _BMI160_H_ */
