//
// Created by Oleksandra Baukh on 12/22/17.
//

#include "Environment.h"

std::list<DistanceSensorListener *> Environment::distanceSensorListeners = std::list<DistanceSensorListener *>();

std::list<IRSensorListener *> Environment::irSensorListeners = std::list<IRSensorListener *>();

void Environment::setMovementDriver(MovementDriver *movementDriver) {
    Environment::movementDriver = movementDriver;
}

void Environment::setDistanceSensor(DistanceSensor *distanceSensor) {
    Environment::distanceSensor = distanceSensor;
}

void Environment::setIrSensor(IRSensor *irSensor) {
    Environment::irSensor = irSensor;
}

MovementDriver *Environment::getMovementDriver() {
    return movementDriver;
}

DistanceSensor *Environment::getDistanceSensor() {
    return distanceSensor;
}

IRSensor *Environment::getIrSensor() {
    return irSensor;
}

void Environment::registorDistanceSensorListener(DistanceSensorListener *distanceSensorListener) {
    distanceSensorListeners.insert(distanceSensorListeners.end(), distanceSensorListener);

}

void Environment::registorIRSensorListener(IRSensorListener *irSensorListener) {
    irSensorListeners.insert(irSensorListeners.end(), irSensorListener);
}
