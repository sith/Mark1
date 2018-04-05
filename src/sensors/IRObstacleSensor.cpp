//
// Created by Oleksandra Baukh on 4/2/18.
//

#include "IRObstacleSensor.h"

#include <Arduino.h>

Obstacle IRObstacleSensor::read() {
    Obstacle obstacle{};
    obstacle.left = digitalRead(leftSensorPin) == LOW;
    obstacle.forward = digitalRead(forwardSensorPin) == LOW;
    obstacle.right = digitalRead(leftSensorPin) == LOW;
    return obstacle;
}

IRObstacleSensor::IRObstacleSensor() {
    pinMode(leftSensorPin, INPUT);
    pinMode(forwardSensorPin, INPUT);
    pinMode(rightSensorPin, INPUT);
}
