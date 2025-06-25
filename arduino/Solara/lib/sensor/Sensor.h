
#ifndef SENSOR_H
#define SENSOR_H

class Sensor
{
private:
    const int pin;
    const bool isDigital;
    bool initialized = false;

protected:
    Sensor(int pin, bool isDigital);

    void prepareDestroy();

public:
    virtual ~Sensor();

    bool isInitialized() const;
    int getPin() const;
    bool isDigitalSensor() const;

    virtual int readValue() = 0;
};

#endif
