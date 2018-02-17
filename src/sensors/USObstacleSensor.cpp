//
// Created by Oleksandra Baukh on 2/4/18.
//

#include <logger/LoggerFactory.h>
#include "USObstacleSensor.h"

Obstacle USObstacleSensor::read() {
    Obstacle obstacle{false, false, false};
    auto distance = sr04.Distance();
    if (distance < allowedDistanceToObstacle) {
        logger->newLine()->logAppend("Obstacle found");
        obstacle.forward = true;
    }
    return obstacle;
}

USObstacleSensor::~USObstacleSensor() {
    delete logger;
}

USObstacleSensor::USObstacleSensor() : logger(LoggerFactory::newLogger("USObstacleSensor")) {}
