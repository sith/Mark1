//
// Created by Oleksandra Baukh on 12/22/17.
//

#include "FreeRunMode.h"


Logger *FreeRunMode::LOG = Logger::createLogger("FreeRunMode");

const void FreeRunMode::process() {

    long forwardDistanceToObstacle = distanceSensor->getDistance();
    long leftDistanceToObstacle = distanceSensor->getDistance(-30);
    long rightDistanceToObstacle = distanceSensor->getDistance(30);

    if (forwardDistanceToObstacle > MIN_DISTANCE &&
        leftDistanceToObstacle > MIN_DISTANCE &&
        rightDistanceToObstacle > MIN_DISTANCE) {
        movementDriver->forward();
        return;
    }

    if (leftDistanceToObstacle < MIN_DISTANCE) {
        movementDriver->turnRight();
    } else if (rightDistanceToObstacle < MIN_DISTANCE) {
        movementDriver->turnLeft();
    }
    delay(250);
}

const void FreeRunMode::stop() {
    movementDriver->stop();
}

const char *FreeRunMode::getName() {
    return "FreeRun";
}

FreeRunMode::FreeRunMode(DistanceSensor *distanceSensor, MovementDriver *movementDriver)
        : distanceSensor(distanceSensor), movementDriver(movementDriver) {}
