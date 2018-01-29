//
// Created by Oleksandra Baukh on 12/17/17.
//

#ifndef MARK1_USDISTANCESENSOR_H
#define MARK1_USDISTANCESENSOR_H
static const int COURSE_OFFSET = 90;
static const int MIN_COURSE = 10;
static const int MAX_COURSE = 170;

#include <Servo.h>
#include <logger/Logger.h>
#include "sensors/DistanceSensor.h"
#include "SR04.h"
#include "PinConfiguration.h"

class USDistanceSensor : public DistanceSensor {
private:

    Logger *LOG;

    Servo servo;
    int currentCourse = COURSE_OFFSET;
    SR04 sr04 = SR04(DistanceModulePins::echo, DistanceModulePins::trig);

    void standardDelay() const;

    int calculateCourse(int course);

public:
    USDistanceSensor();

    long getDistance(int course) override;
};


#endif //MARK1_USDISTANCESENSOR_H
