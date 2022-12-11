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

#include "Adafruit_SPIDevice_Adapter.h"
#include "SPIInterface.h"

Adafruit_SPIDevice_Adapter::Adafruit_SPIDevice_Adapter(SPIInterface &interface) : interface(interface)
{
}

Adafruit_SPIDevice_Adapter::~Adafruit_SPIDevice_Adapter()
{
}

//bool Adafruit_SPIDevice_Adapter::read (uint8_t *buffer, size_t len,
//                                       bool stop)
//{
//    return false;
//}

bool Adafruit_SPIDevice_Adapter::write (const uint8_t *buffer, size_t len,
                                        const uint8_t *prefix_buffer, size_t prefix_len)
{
    return false;
}

bool Adafruit_SPIDevice_Adapter::write_then_read (const uint8_t *write_buffer, size_t write_len,
        uint8_t *read_buffer, size_t read_len,
        uint8_t sendvalue)
{
    return false;
}

