
#ifndef SENSOR_H
#define SENSOR_H

class Sensor
{
private:
    int pin;
    bool isDigital;
    bool initialized = false;

protected:
    Sensor(int pin, bool isDigital);

    void prepareDestroy();

public:
    virtual ~Sensor();

    bool isInitialized();
    int getPin();
    bool isDigitalSensor();
    virtual int readValue() = 0;
};

#endif
