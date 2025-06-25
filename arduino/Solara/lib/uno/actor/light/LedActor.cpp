
#include <Arduino.h>
#include <actor/light/LedActor.h>

LedActor::LedActor(int pin) : Actor(pin, false)
{
    if (!PWM_PIN(pin))
    {
        Serial.println("Error: Pin does not support PWM.");
        delete this;
        exit(1);
    }
}

LedActor::~LedActor()
{
    Actor::prepareDestroy();
    analogWrite(this->getPin(), 0);
}

int LedActor::normalizeActValue(int valMin, int valMax, int actValue)
{
    if (valMin >= valMax)
    {
        Serial.println("Error: valMin must be less than valMax.");
        return -1; // Error case
    }

    return map(actValue, valMin, valMax, 0, PWM_MAX);
}

int LedActor::inspectPwm(int actValue) const
{
    // Ensure value is within the PWM range
    actValue = MIN(PWM_MAX, MAX(0, actValue));

    // Invert the value for LED control
    // if given value is low, the LED will glow brighter
    actValue = map(actValue, 0, PWM_MAX, PWM_MAX, 0);

    switch (actValue)
    {
    case 50 ... 120:
        return 80;

    case 121 ... 200:
        return 150;

    case 201 ... 255:
        return 255;

    default:
        return 0;
    }
}

int LedActor::actOn(int value)
{
    int pin = this->getPin();
    int pwm = this->inspectPwm(value);

    analogWrite(pin, pwm);

    return pwm;
}
