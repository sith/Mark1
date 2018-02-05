//
// Created by Oleksandra Baukh on 2/4/18.
//

#ifndef MARK1_USOBSTACLESENSOR_H
#define MARK1_USOBSTACLESENSOR_H


#include <sensors/ObstacleSensor.h>
#include <SR04.h>
#include <PinConfiguration.h>

class USObstacleSensor : public ObstacleSensor {
    SR04 sr04{DistanceModulePins::echo, DistanceModulePins::trig};
    const byte allowedDistanceToObstacle = 10;
public:
    Obstacle read() override;
};


#endif //MARK1_USOBSTACLESENSOR_H
