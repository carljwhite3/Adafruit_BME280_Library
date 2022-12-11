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

#ifndef __Adafruit_SPIDevice_Adapter_H
#define __Adafruit_SPIDevice_Adapter_H

#include <cstdint>
#include <cstddef>

class SPIInterface;

class Adafruit_SPIDevice_Adapter
{
public:
    Adafruit_SPIDevice_Adapter(SPIInterface &interface);
    virtual ~Adafruit_SPIDevice_Adapter();

    virtual bool write (const uint8_t *buffer, size_t len,
                        const uint8_t *prefix_buffer = nullptr, size_t prefix_len = 0);

    virtual bool write_then_read (const uint8_t *write_buffer, size_t write_len,
                                  uint8_t *read_buffer, size_t read_len,
                                  uint8_t sendvalue = 0xFF);

protected:
    SPIInterface &interface;

};

#endif
