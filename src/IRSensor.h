//
// Created by Oleksandra Baukh on 12/16/17.
//

#ifndef MARK1_IRSENSOR_H
#define MARK1_IRSENSOR_H

#include "IRremote.h"

enum class IRCode {
    POWER,
    FUNC_STOP,
    VOL_UP,
    FAST_BACK,
    PAUSE,
    FAST_FORWARD,
    DOWN,
    VOL_DOWN,
    UP,
    EQ,
    ST_REPT,
    NUMBER_0,
    NUMBER_1,
    NUMBER_2,
    NUMBER_3,
    NUMBER_4,
    NUMBER_5,
    NUMBER_6,
    NUMBER_7,
    NUMBER_8,
    NUMBER_9,
    REPEAT_,
    NONE,
    UNKNOWN_CODE,
};

class IRSensor {


    IRrecv irrecv;
    decode_results results;

    IRCode translateIR();

public:
    IRSensor();
    IRCode readCode();
};

#endif //MARK1_IRSENSOR_H
