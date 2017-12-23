//
// Created by Oleksandra Baukh on 12/22/17.
//

#ifndef MARK1_ENVIRONMENT_H
#define MARK1_ENVIRONMENT_H

#include "../sensors/DistanceSensorListener.h"

#include <StandardCplusplus.h>
#include <list>
#include <sensors/IRSensorListener.h>
#include <drivers/MovementDriver.h>
#include <sensors/DistanceSensor.h>

class Environment {
    static std::list<DistanceSensorListener *> distanceSensorListeners;
    static std::list<IRSensorListener *> irSensorListeners;
    static MovementDriver *movementDriver;
    static DistanceSensor *distanceSensor;
    static IRSensor *irSensor;

public:
    static void registorDistanceSensorListener(DistanceSensorListener *distanceSensorListener);

    static void registorIRSensorListener(IRSensorListener *irSensorListener);

    static void setMovementDriver(MovementDriver *movementDriver);

    static void setDistanceSensor(DistanceSensor *distanceSensor);

    static void setIrSensor(IRSensor *irSensor);

    static MovementDriver *getMovementDriver();

    static DistanceSensor *getDistanceSensor();

    static IRSensor *getIrSensor();

};


#endif //MARK1_ENVIRONMENT_H
