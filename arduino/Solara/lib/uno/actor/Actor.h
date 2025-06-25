
#ifndef ACTOR_H
#define ACTOR_H

#include <define.h>

class Actor
{
private:
    const int pin;
    const bool isDigital;
    bool initialized = false;

protected:
    Actor(int pin, bool isDigital);

    void prepareDestroy();

public:
    virtual ~Actor();

    bool isInitialized() const;
    int getPin() const;
    bool isDigitalActor() const;

    virtual int normalizeActValue(int valMin, int valMax, int actValue) = 0;
    virtual int actOn(int value) = 0;
};

#endif
