#include "RaspberryPiI2C.h"
#include "Adafruit_BME280.h"
#include "Adafruit_I2CDevice_Adapter.h"

#include <iostream>

#define SEALEVELPRESSURE_HPA (1013.25)

using namespace std;

int main(int argc, char **argv)
{
    RaspberryPiI2C device(BME280_ADDRESS);
    Adafruit_I2CDevice_Adapter adapter(device);

    Adafruit_BME280 sensor(adapter);

    if (sensor.begin())
    {
        cout << "Temperature = " << sensor.readTemperature() << " C" << endl;
        cout << "Pressure = " << sensor.readPressure()/100 <<" hPa" << endl;
        cout << "Humidity = " << sensor.readHumidity() << " %" << endl;
        cout << "Altitude = " << sensor.readAltitude(SEALEVELPRESSURE_HPA) << " m" << endl;
    }

    return 0;
}
