//
// Created by Oleksandra Baukh on 12/22/17.
//

#include <os/environment/Environment.h>
#include "FreeRunMode.h"

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

FreeRunMode::FreeRunMode(DistanceSensor &distanceSensor, MovementDriver &movementDriver)
        : Mode(ModeName::FREE_RUN), distanceSensor(&distanceSensor), movementDriver(&movementDriver),
          logger(Environment::getEnvironment().getLoggerFactory()->createLogger("FreeRunMode")) {}
