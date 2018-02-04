//
// Created by Oleksandra Baukh on 12/17/17.
//

#include <environment/Environment.h>
#include "USDistanceSensor.h"


long USDistanceSensor::getDistance(int course) {
    int newCourse = calculateCourse(course);
    if (currentCourse != newCourse) {
        currentCourse = newCourse;
        servo.write(currentCourse);
        standardDelay();
    }
    long distance = sr04.Distance();

    return distance;
}

USDistanceSensor::USDistanceSensor() : logger(
        LoggerFactory::newLogger("USDistanceSensor")) {

    servo.attach(ServoMotorPins::pulse);
    servo.write(currentCourse);
    delay(250);
    standardDelay();
    logger->newLine()->logAppend("Servo motor is reset");

}

void USDistanceSensor::standardDelay() const { delay(250); }

int USDistanceSensor::calculateCourse(int course) {
    int newCourse = course + COURSE_OFFSET;
    if (newCourse > MAX_COURSE) {
        return MAX_COURSE;
    }
    if (newCourse < MIN_COURSE) {
        return MIN_COURSE;
    }
    return newCourse;
}

USDistanceSensor::~USDistanceSensor() {
    delete logger;
}

