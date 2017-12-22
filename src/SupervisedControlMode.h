//
// Created by Oleksandra Baukh on 12/20/17.
//

#ifndef MARK1_SUPERVISEDCONTROLMODE_H
#define MARK1_SUPERVISEDCONTROLMODE_H

#include <HardwareSerial.h>
#include "Mode.h"
#include "MovementDriver.h"
#include "IRSensor.h"
#include "DistanceSensor.h"


static const int MIN_FORWARD_DISTANCE = 10;

class SupervisedControlMode : public Mode {
private:
    static Logger *LOG;

    MovementDriver *movementDriver;
    DistanceSensor *distanceSensor;
    IRSensor *irSensor;

    bool checkForObstacles(long forwardObstacleDistance) const;

public:
    SupervisedControlMode(MovementDriver *movementDriver, IRSensor *irSensor, DistanceSensor *distanceSensor);

    const void process() override;

    const void stop() override;

    const char *getName() override;
};


#endif //MARK1_SUPERVISEDCONTROLMODE_H
