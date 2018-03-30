//
// Created by Oleksandra Baukh on 1/28/18.
//

#ifndef MARK1_ARDUINOCLOCK_H
#define MARK1_ARDUINOCLOCK_H


#include <Clock.h>

class ArduinoClock : public Clock {
public:
    long getTime() override;

};


#endif //MARK1_ARDUINOCLOCK_H
