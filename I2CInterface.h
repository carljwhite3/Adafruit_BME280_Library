/*!
 * Copyright (C) 2022 Carl J. White III
 *
 * @file Adafruit_BME280.cpp
 *
 * @section author Author
 *
 * Written by Carl J. White III.
 *
 * @section license License
 *
 * BSD license, all text here must be included in any redistribution.
 * See the LICENSE file for details.
 *
 */

#ifndef __I2CInterface
#define __I2CInterface

class I2CInterface
{
public:
    I2CInterface() {};
    virtual ~I2CInterface() {};

    virtual int writeReg8(int aReg, int aData) = 0;
    virtual int readReg8(int aReg) = 0;
    virtual int writeReg16(int aReg, int aData) = 0;
    virtual int readReg16(int aReg) = 0;

};

#endif
