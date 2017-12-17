//
// Created by Oleksandra Baukh on 12/16/17.
//

#ifndef MARK1_byteCONFIGURATION_H
#define MARK1_byteCONFIGURATION_H

#include <Arduino.h>
/*Arduino UNO pins*/
#define   D0  0
#define   D1  1
#define   D2  2
#define   D3_PWM  3
#define   D4  4
#define   D5_PWM  5
#define   D6_PWM  6
#define   D7  7
#define   D8  8
#define   D9_PWM  9
#define   D10_PWM  10
#define   D11_PWM  11
#define   D12  12
#define   D13  13
#define   D14_ANALOG  14
#define   D15_ANALOG  15
#define   D16_ANALOG  16
#define   D17_ANALOG  17
#define   D18_ANALOG  18
#define   D19_ANALOG  19
#define   A0  0
#define   A1  1
#define   A2  2
#define   A3  3
#define   A4  4
#define   A5  5


/*IR receiver module*/
class IRReceiverPins {
public:
    static const byte y = D10_PWM;
};

/*HC-SR04 Ultra sound sensor*/
class DistanceModulePins {
public:
    static const byte trig = D7;
    static const byte echo = D6_PWM;
};

/*Motor shield L293D*/
class MotorShieldPins {
public:
    static const byte motor1Enable = D3_PWM;
    static const byte motor1Input1 = D2;
    static const byte motor1Input2 = D8;
    static const byte motor2Enable = D5_PWM;
    static const byte motor2Input1 = D4;
    static const byte motor2Input2 = D7;
};

/*Servo motor SG90*/
struct ServoMotorPins {
public:
    static const byte pulse = D9_PWM;
};


#endif //MARK1_byteCONFIGURATION_H
