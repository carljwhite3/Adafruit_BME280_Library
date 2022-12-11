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

#include "Adafruit_I2CDevice_Adapter.h"
#include "I2CInterface.h"

#include <iostream>

using namespace std;

Adafruit_I2CDevice_Adapter::Adafruit_I2CDevice_Adapter(I2CInterface &interface) : interface(interface)
{
}

Adafruit_I2CDevice_Adapter::~Adafruit_I2CDevice_Adapter()
{
}

bool Adafruit_I2CDevice_Adapter::write (const uint8_t *buffer, size_t len,
                                        bool stop,
                                        const uint8_t *prefix_buffer,
                                        size_t prefix_len)
{
//    printf("write(0x");
//    for (size_t i=0; i < len; i++)
//        printf("%02x", buffer[i]);
//    printf(", %ld)\n", len);

    if (len == 2)
    {
        interface.writeReg8(buffer[0], buffer[1]);
    }

    return true;
}

bool Adafruit_I2CDevice_Adapter::write_then_read (const uint8_t *write_buffer, 
		                                  size_t write_len,
                                                  uint8_t *read_buffer, 
						  size_t read_len,
                                                  bool stop)
{
//    printf("write_then_read(0x");
//    for (size_t i=0; i < write_len; i++)
//        printf("%02x", write_buffer[i]);
//    printf(", %ld, 0x", write_len);

    if (write_len == 1)
    {
        int reg = write_buffer[0];

        for (size_t i = 0; i < read_len; i++)
        {
            read_buffer[i] = interface.readReg8(reg + i);
        }

//        for (size_t i=0; i < read_len; i++)
//	    printf("%02x", read_buffer[i]);
//	printf(", %ld)\n", read_len);
    }

    return true;
}

