
#include <Arduino.h>
#include <Sensor.h>

Sensor::Sensor(int pin, bool isDigital)
{
    this->pin = pin;
    if (isDigital)
    {
        pinMode(pin, INPUT);
    }

    this->initialized = true;
}

void Sensor::prepareDestroy()
{
    this->initialized = false;
    this->pin = -1;
}

Sensor::~Sensor()
{
    prepareDestroy();
}

int Sensor::readValue()
{
    if (!this->initialized)
    {
        return -1; // Not initialized
    }

    if (this->isDigital)
    {
        return digitalRead(this->pin);
    }
    else
    {
        return analogRead(this->pin);
    }
}

bool Sensor::isInitialized()
{
    return this->initialized;
}

int Sensor::getPin()
{
    return this->pin;
}

bool Sensor::isDigitalSensor()
{
    return this->isDigital;
}
