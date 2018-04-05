//
// Created by Oleksandra Baukh on 4/2/18.
//

#ifndef MARK1_IROBSTACLESENSOR_H
#define MARK1_IROBSTACLESENSOR_H


#include <sensors/ObstacleSensor.h>
#include <types.h>
#include <PinConfiguration.h>

class IRObstacleSensor : public ObstacleSensor {
public:
    IRObstacleSensor();

    virtual Obstacle read();

    uint8 rightSensorPin = D17_ANALOG;
    uint8 forwardSensorPin = D16_ANALOG;
    uint8 leftSensorPin = D15_ANALOG;
};


#endif //MARK1_IROBSTACLESENSOR_H
