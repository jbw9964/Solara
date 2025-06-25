
#include <Arduino.h>
#include <Sensor.h>

Sensor::Sensor(int pin, bool isDigital) : pin(pin), isDigital(isDigital)
{
    if (isDigital)
    {
        pinMode(pin, INPUT);
    }

    this->initialized = true;
}

void Sensor::prepareDestroy()
{
    this->initialized = false;
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

bool Sensor::isInitialized() const
{
    return this->initialized;
}

int Sensor::getPin() const
{
    return this->pin;
}

bool Sensor::isDigitalSensor() const
{
    return this->isDigital;
}
