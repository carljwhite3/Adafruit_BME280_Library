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

#ifndef __SPIInterface
#define __SPIInterface

class SPIInterface
{
public:
    SPIInterface() {};
    virtual ~SPIInterface() {};

    virtual int writeReg8(int aReg, int aData) = 0;
    virtual int readReg8(int aReg) = 0;
    virtual int writeReg16(int aReg, int aData) = 0;
    virtual int readReg16(int aReg) = 0;

};

#endif
