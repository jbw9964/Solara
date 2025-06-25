
#ifndef LED_ACTOR_H
#define LED_ACTOR_H

#include <actor/Actor.h>

#ifndef PWM_MAX
#define PWM_MAX 255
#endif

class LedActor : public Actor
{
private:
    int inspectPwm(int actValue) const;

public:
    LedActor(int pin);
    ~LedActor() override;

    int normalizeActValue(int valMin, int valMax, int actValue) override;
    int actOn(int value) override;
};

#endif
