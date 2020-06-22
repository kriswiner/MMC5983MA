/*
 * Copyright (c) 2020 Tlera Corp.  All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal with the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 *  1. Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimers.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimers in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of Tlera Corp, nor the names of its contributors
 *     may be used to endorse or promote products derived from this Software
 *     without specific prior written permission.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 * CONTRIBUTORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * WITH THE SOFTWARE.
 * 
 * The MMC5983MA is an AEC-Q100 qualified complete 3-axis magnetic sensor with on-chip 
 * signal processing and integrated I2C/SPI bus suitable for use in automotive applications.
 * Couple with the LSM6DSM accel/gyro and LPS22HB barometer the system provides a compact and
 * accurate absolute orientation estimation engine.
 * 
 * Uses the I2C interface for data transfer.
 * 
 * Intended to be run on a Dragonfly development board:
 * 
 * https://www.tindie.com/products/tleracorp/dragonfly-stm32l47696-development-board/
 *  
 * 
 * Library may be used freely and without limit with attribution.
 */

#include "LPS22HB.h"
#include "I2Cdev.h"

LPS22H::LPS22H(I2Cdev* i2c_bus)
{
  _i2c_bus = i2c_bus;
}

uint8_t LPS22H::getChipID()
{
  // Read the WHO_AM_I register of the altimeter this is a good test of communication
  uint8_t temp = _i2c_bus->readByte(LPS22H_ADDRESS, LPS22H_WHOAMI);  // Read WHO_AM_I register for LPS22H
  return temp;
}

uint8_t LPS22H::status()
{
  // Read the status register of the altimeter  
  uint8_t temp = _i2c_bus->readByte(LPS22H_ADDRESS, LPS22H_STATUS);   
  return temp;
}

int32_t LPS22H::readAltimeterPressure()
{
    uint8_t rawData[3];  // 24-bit pressure register data stored here
    _i2c_bus->readBytes(LPS22H_ADDRESS, (LPS22H_PRESS_OUT_XL | 0x80), 3, &rawData[0]); // bit 7 must be one to read multiple bytes
    return (int32_t) ((int32_t) rawData[2] << 16 | (int32_t) rawData[1] << 8 | rawData[0]);
}

int16_t LPS22H::readAltimeterTemperature()
{
    uint8_t rawData[2];  // 16-bit pressure register data stored here
    _i2c_bus->readBytes(LPS22H_ADDRESS, (LPS22H_TEMP_OUT_L | 0x80), 2, &rawData[0]); // bit 7 must be one to read multiple bytes
    return (int16_t)((int16_t) rawData[1] << 8 | rawData[0]);
}


void LPS22H::Init(uint8_t PODR)
{
  // set sample rate by setting bits 6:4 
  // enable low-pass filter by setting bit 3 to one
  // bit 2 == 0 means bandwidth is odr/9, bit 2 == 1 means bandwidth is odr/20
  // make sure data not updated during read by setting block data udate (bit 1) to 1
    _i2c_bus->writeByte(LPS22H_ADDRESS, LPS22H_CTRL_REG1, PODR << 4 | 0x08 | 0x02);  
    _i2c_bus->writeByte(LPS22H_ADDRESS, LPS22H_CTRL_REG3, 0x04);  // enable data ready as interrupt source
}
