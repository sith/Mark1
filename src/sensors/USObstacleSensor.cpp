//
// Created by Oleksandra Baukh on 2/4/18.
//

#include "USObstacleSensor.h"

Obstacle USObstacleSensor::read() {
    Obstacle obstacle{false, false, false};
    if (sr04.getDistance() < allowedDistanceToObstacle) {
        obstacle.forward = true;
    }
    return obstacle;
}
