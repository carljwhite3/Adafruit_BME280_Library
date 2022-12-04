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

#include "RaspberryPiI2C.h"
#include <stdexcept>

#include <wiringPiI2C.h>
#include <unistd.h>

RaspberryPiI2C::RaspberryPiI2C(int aDevId)
{
    mFd = wiringPiI2CSetup(aDevId);

    if (mFd < 0)
    {
        throw std::runtime_error("Runtime Error");
    }
}

RaspberryPiI2C::~RaspberryPiI2C()
{
    close(mFd);
}

int RaspberryPiI2C::writeReg8(int aReg, int aData)
{
    return wiringPiI2CWriteReg8(mFd, aReg, aData);
}

int RaspberryPiI2C::readReg8(int aReg)
{
    int result = wiringPiI2CReadReg8(mFd, aReg);
    return result;
}

int RaspberryPiI2C::writeReg16(int aReg, int aData)
{
    int result = wiringPiI2CWriteReg16(mFd, aReg, aData);
    return result;
}

int RaspberryPiI2C::readReg16(int aReg)
{
    int result = wiringPiI2CReadReg16(mFd, aReg);
    return result;
}
