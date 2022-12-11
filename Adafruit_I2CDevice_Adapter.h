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

#ifndef __Adafruit_I2CDevice_Adapter_H
#define __Adafruit_I2CDevice_Adapter_H

#include <cstdint>
#include <cstddef>

class I2CInterface;

class Adafruit_I2CDevice_Adapter
{
public:
    Adafruit_I2CDevice_Adapter(I2CInterface &interface);
    virtual ~Adafruit_I2CDevice_Adapter();

    virtual bool write (const uint8_t *buffer, size_t len, bool stop=true,
                        const uint8_t *prefix_buffer=nullptr,
                        size_t prefix_len=0);

    virtual bool write_then_read (const uint8_t *write_buffer, size_t write_len,
                                  uint8_t *read_buffer, size_t read_len,
                                  bool stop=false);

protected:
    I2CInterface &interface;

};

#endif
