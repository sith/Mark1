//
// Created by Oleksandra Baukh on 12/22/17.
//

#ifndef MARK1_FREERUNMODE_H
#define MARK1_FREERUNMODE_H


#include <drivers/MovementDriver.h>
#include <logger/Logger.h>
#include <sensors/DistanceSensor.h>
#include "Mode.h"

#define MIN_DISTANCE 20


class FreeRunMode : public Mode {

private:

    static Logger *LOG;

    DistanceSensor *distanceSensor;
    MovementDriver *movementDriver;


public:
    FreeRunMode(DistanceSensor *distanceSensor, MovementDriver *movementDriver);

    const void process() override;

    const void stop() override;

    const char *getName() override;

};


#endif //MARK1_FREERUNMODE_H
