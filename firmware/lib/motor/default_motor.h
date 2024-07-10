//Copyright (c) STEMTEC AI and Robotics Private Limited, India


#ifndef DEFAULT_MOTOR
#define DEFAULT_MOTOR

#include <Arduino.h>
#include <Servo.h> 

#include "motor_interface.h"

class Generic1: public MotorInterface
{
    private:
        int in_pin_;
        int pwm_pin_;

    protected:
        void forward(int pwm) override
        {
            digitalWrite(in_pin_, HIGH);
            analogWrite(pwm_pin_, abs(pwm));
        }

        void reverse(int pwm) override
        {
            digitalWrite(in_pin_, LOW);
            analogWrite(pwm_pin_, abs(pwm));
        }

    public:
        Generic1(float pwm_frequency, int pwm_bits, bool invert, int pwm_pin, int in_pin, int unused=-1): 
            MotorInterface(invert),
            in_pin_(in_pin),
            pwm_pin_(pwm_pin)
        {
            pinMode(in_pin_, OUTPUT);
            pinMode(pwm_pin_, OUTPUT);

            if(pwm_frequency > 0)
            {
                analogWriteFrequency(pwm_pin_, pwm_frequency);
            }
            analogWriteResolution(pwm_bits);

            //ensure that the motor is in neutral state during bootup
            analogWrite(pwm_pin_, abs(0));
        }

        void brake() override
        {
            analogWrite(pwm_pin_, 0);
        }
};

#endif