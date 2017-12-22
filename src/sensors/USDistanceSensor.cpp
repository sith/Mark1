//
// Created by Oleksandra Baukh on 12/17/17.
//

#include "USDistanceSensor.h"

Logger *USDistanceSensor::LOG = Logger::createLogger("USDistanceSensor");

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

USDistanceSensor::USDistanceSensor() {
    servo.attach(ServoMotorPins::pulse);
    servo.write(currentCourse);
    delay(250);
    standardDelay();
    LOG->newLine()->logAppend("Servo motor is reset");

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

