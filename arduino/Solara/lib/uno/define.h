
#ifndef DEFINE_H
#define DEFINE_H

#include <Arduino.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// sensor/**
#define MAX_LIGHT_RESISTANCE 1023

#define DIGITAL_PIN(pin) ((pin) == 2 || (pin) == 3 || (pin) == 4 || (pin) == 5 || (pin) == 6 || (pin) == 7 || (pin) == 8 || (pin) == 9 || (pin) == 10 || (pin) == 11 || (pin) == 12 || (pin) == 13 ? true : false)
#define ANALOG_PIN(pin) ((pin) == A0 || (pin) == A1 || (pin) == A2 || (pin) == A3 || (pin) == A4 || (pin) == A5 ? true : false)

// actor/**
#define PWM_MAX 255

#define PWM_PIN(pin) ((pin) == 3 || (pin) == 5 || (pin) == 6 || (pin) == 9 || (pin) == 10 || (pin) == 11 ? true : false)

#endif