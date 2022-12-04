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

#ifndef __RaspberryPiI2C
#define __RaspberryPiI2C

#include "I2CInterface.h"

class RaspberryPiI2C : public I2CInterface
{
public:
    RaspberryPiI2C(int aDevId);
    virtual ~RaspberryPiI2C();

    virtual int writeReg8(int aReg, int aData);
    virtual int readReg8(int aReg);
    virtual int writeReg16(int aReg, int aData);
    virtual int readReg16(int aReg);

private:
    int mFd; // file descriptor

};

#endif
