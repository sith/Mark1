//
// Created by Oleksandra Baukh on 12/16/17.
//

#ifndef MARK1_IRSENSOR_H
#define MARK1_IRSENSOR_H

#include <Arduino.h>
#include "IRremote.h"
#include "os/logger/Logger.h"

#define READINGS_SIZE 5
enum class IRCode {
    POWER, //0
    FUNC_STOP, //1
    VOL_UP, //2
    FAST_BACK, //3
    PAUSE, //4
    FAST_FORWARD, //5
    DOWN, //6
    VOL_DOWN, //7
    UP, //8
    EQ, //9
    ST_REPT, //10
    NUMBER_0, //11
    NUMBER_1, //12
    NUMBER_2, //13
    NUMBER_3, //14
    NUMBER_4, //15
    NUMBER_5, //16
    NUMBER_6, //17
    NUMBER_7, //18
    NUMBER_8, //19
    NUMBER_9, //20
    REPEAT_,  //21
    NONE, //22
};

class IRSensor {
private:
    Logger &LOG;
    IRrecv irrecv;
    decode_results results;

    IRCode translateIR();

public:
    IRSensor();

    IRCode readCode();
};

#endif //MARK1_IRSENSOR_H
