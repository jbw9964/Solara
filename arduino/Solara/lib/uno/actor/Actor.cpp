
#include <Arduino.h>
#include <actor/Actor.h>

Actor::Actor(int pin, bool isDigital) : pin(pin), isDigital(isDigital)
{

    if (isDigital && !DIGITAL_PIN(pin))
    {
        Serial.print("Error: Pin ");
        Serial.print(pin);
        Serial.println(" is not a valid digital pin.");
        delete this;
        exit(1);
    }

    pinMode(pin, OUTPUT);

    this->initialized = true;
}

void Actor::prepareDestroy()
{
    if (isDigital)
    {
        digitalWrite(pin, LOW);
    }
    else
    {
        analogWrite(pin, 0);
    }

    this->initialized = false;
}

Actor::~Actor()
{
    prepareDestroy();
}

bool Actor::isInitialized() const
{
    return this->initialized;
}

int Actor::getPin() const
{
    return this->pin;
}

bool Actor::isDigitalActor() const
{
    return this->isDigital;
}
