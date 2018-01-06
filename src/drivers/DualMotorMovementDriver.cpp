#ifndef UNIT_TEST

#include <Arduino.h>
#include "DualMotorMovementDriver.h"
#include "PinConfiguration.h"

Logger *DualMotorMovementDriver::logger = Logger::createLogger("DualMotorMovementDriver");

void DualMotorMovementDriver::forward() {
    logger->newLine()->logAppend("Forward");
    movementDriverState = FORWARD_;
    leftWheel(SPEED_MODE_MEDIUM, MOVE_FORWARD);
    rightWheel(SPEED_MODE_MEDIUM, MOVE_FORWARD);
}

void DualMotorMovementDriver::backward() {
    logger->newLine()->logAppend("Backward");
    movementDriverState = BACKWARD_;
    leftWheel(SPEED_MODE_MEDIUM, MOVE_BACKWARD);
    rightWheel(SPEED_MODE_MEDIUM, MOVE_BACKWARD);
}

void DualMotorMovementDriver::turnLeft() {
    logger->newLine()->logAppend("Left");
    movementDriverState = TURN_LEFT_;
    leftWheel(SPEED_MODE_MEDIUM, MOVE_FORWARD);
    rightWheel(SPEED_MODE_MEDIUM, MOVE_BACKWARD);
}

void DualMotorMovementDriver::turnRight() {
    logger->newLine()->logAppend("Right");
    movementDriverState = TURN_RIGHT_;
    leftWheel(SPEED_MODE_MEDIUM, MOVE_BACKWARD);
    rightWheel(SPEED_MODE_MEDIUM, MOVE_FORWARD);
}

void DualMotorMovementDriver::stop() {
    logger->newLine()->logAppend("Stop");
    movementDriverState = STOP_;
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
    movementDriverState = STOP_;
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

MovementDriverState DualMotorMovementDriver::getMovementDriverState() {
    return movementDriverState;
}

#endif