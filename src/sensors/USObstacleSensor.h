//
// Created by Oleksandra Baukh on 2/4/18.
//

#ifndef MARK1_USOBSTACLESENSOR_H
#define MARK1_USOBSTACLESENSOR_H


#include <sensors/ObstacleSensor.h>
#include <SR04.h>
#include <PinConfiguration.h>
#include <logger/Logger.h>

class USObstacleSensor : public ObstacleSensor {
    SR04 sr04{DistanceModulePins::echo, DistanceModulePins::trig};
    const long allowedDistanceToObstacle = 10;
    Logger *logger;
public:
    Obstacle read() override;

    USObstacleSensor();

    virtual ~USObstacleSensor();
};


#endif //MARK1_USOBSTACLESENSOR_H
