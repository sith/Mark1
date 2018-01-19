//
// Created by Oleksandra Baukh on 12/22/17.
//

#ifndef MARK1_FREERUNMODE_H
#define MARK1_FREERUNMODE_H


#include <drivers/MovementDriver.h>
#include <os/logger/Logger.h>
#include <sensors/DistanceSensor.h>
#include <os/modes/ModeName.h>
#include "Mode.h"

#define MIN_DISTANCE 20


class FreeRunMode : public Mode {

private:
    DistanceSensor *distanceSensor;
    MovementDriver *movementDriver;
    Logger &logger;
public:
    FreeRunMode(DistanceSensor &distanceSensor, MovementDriver &movementDriver);

    const void process() override;

    const void stop() override;
};


#endif //MARK1_FREERUNMODE_H
