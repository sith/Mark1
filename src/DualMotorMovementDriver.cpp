#include <Arduino.h>
#include "DualMotorMovementDriver.h"
#include "PinConfiguration.h"


bool DualMotorMovementDriver::forwardFlag = false;
bool DualMotorMovementDriver::backwardFlag = false;
bool DualMotorMovementDriver::turnLeftFlag = false;
bool DualMotorMovementDriver::turnRightFlag = false;
bool DualMotorMovementDriver::stopFlag = true;


Logger *DualMotorMovementDriver::logger = Logger::createLogger("DualMotorMovementDriver");

void DualMotorMovementDriver::forward() {
    logger->newLine()->logAppend("Forward");
    forwardFlag = true;
    leftWheel(SPEED_MODE_MEDIUM, MOVE_FORWARD);
    rightWheel(SPEED_MODE_MEDIUM, MOVE_FORWARD);
}

void DualMotorMovementDriver::backward() {
    logger->newLine()->logAppend("Backward");
    backwardFlag = true;
    leftWheel(SPEED_MODE_MEDIUM, MOVE_BACKWARD);
    rightWheel(SPEED_MODE_MEDIUM, MOVE_BACKWARD);
}

void DualMotorMovementDriver::turnLeft() {
    logger->newLine()->logAppend("Left");
    turnLeftFlag = true;
    leftWheel(SPEED_MODE_MEDIUM, MOVE_FORWARD);
    rightWheel(SPEED_MODE_MEDIUM, MOVE_BACKWARD);
}

void DualMotorMovementDriver::turnRight() {
    logger->newLine()->logAppend("Right");
    turnRightFlag = true;
    leftWheel(SPEED_MODE_MEDIUM, MOVE_BACKWARD);
    rightWheel(SPEED_MODE_MEDIUM, MOVE_FORWARD);
}

void DualMotorMovementDriver::stop() {
    logger->newLine()->logAppend("Stop");
    stopFlag = true;
    leftWheel();
    rightWheel();
}

DualMotorMovementDriver::DualMotorMovementDriver() {
    pinMode(MotorShieldPins::motor1Enable, OUTPUT);
    pinMode(MotorShieldPins::motor1Input1, OUTPUT);
    pinMode(MotorShieldPins::motor1Input2, OUTPUT);
    pinMode(MotorShieldPins::motor2Enable, OUTPUT);
    pinMode(MotorShieldPins::motor2Input1, OUTPUT);
    pinMode(MotorShieldPins::motor2Input2, OUTPUT);
}

void DualMotorMovementDriver::leftWheel(byte speedMode = SPEED_MODE_ZERO, byte direction = STOP) {
    if (direction == STOP) {
        digitalWrite(MotorShieldPins::motor1Enable, LOW);
    } else {
        runMotor(speedMode,
                 direction,
                 MotorShieldPins::motor1Enable,
                 MotorShieldPins::motor1Input1,
                 MotorShieldPins::motor1Input2);
    }
}

void DualMotorMovementDriver::rightWheel(byte speedMode = SPEED_MODE_ZERO, byte direction = STOP) {
    if (direction == STOP) {
        digitalWrite(MotorShieldPins::motor2Enable, LOW);
    } else {
        runMotor(speedMode,
                 direction,
                 MotorShieldPins::motor2Enable,
                 MotorShieldPins::motor2Input2,
                 MotorShieldPins::motor2Input1);
    }
}

void DualMotorMovementDriver::runMotor(byte speedMode,
                                       byte direction,
                                       byte enablePin,
                                       byte input1Pin,
                                       byte input2Pin) const {
    digitalWrite(enablePin, speedMode);

    byte dirA;
    byte dirB;
    if (direction == MOVE_FORWARD) {
        dirA = HIGH;
        dirB = LOW;

    } else {
        dirA = LOW;
        dirB = HIGH;
    }

    digitalWrite(input1Pin, dirA);
    digitalWrite(input2Pin, dirB);
}

bool DualMotorMovementDriver::isForward() {
    return forwardFlag;
}

bool DualMotorMovementDriver::isBackward() {
    return backwardFlag;
}

bool DualMotorMovementDriver::isTurnLeft() {
    return turnLeftFlag;
}

bool DualMotorMovementDriver::isTurnRight() {
    return turnRightFlag;
}

bool DualMotorMovementDriver::isStop() {
    return stopFlag;
}
