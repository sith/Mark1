#include <Arduino.h>
#include <environment/Environment.h>
#include "DualMotorMovementDriver.h"
#include "PinConfiguration.h"

DualMotorMovementDriver::DualMotorMovementDriver() : logger(LoggerFactory::newLogger("MotorDriver")) {
    pinMode(MotorShieldPins::motor1Enable, OUTPUT);
    pinMode(MotorShieldPins::motor1Input1, OUTPUT);
    pinMode(MotorShieldPins::motor1Input2, OUTPUT);
    pinMode(MotorShieldPins::motor2Enable, OUTPUT);
    pinMode(MotorShieldPins::motor2Input1, OUTPUT);
    pinMode(MotorShieldPins::motor2Input2, OUTPUT);
}

void DualMotorMovementDriver::runMotor(byte speed,
                                       byte direction,
                                       byte enablePin,
                                       byte input1Pin,
                                       byte input2Pin) const {

    digitalWrite(enablePin, speed);

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

byte DualMotorMovementDriver::convertSpeedMode(const Speed &speed) const {
    byte speedMode = SPEED_MODE_ZERO;
    switch (speed) {
        case Speed::LOW_SPEED:
            speedMode = SPEED_MODE_SLOW;
            break;
        case Speed::MEDIUM_SPEED:
            speedMode = SPEED_MODE_MEDIUM;
            break;
        case Speed::HIGH_SPEED:
            speedMode = SPEED_MODE_FAST;
            break;
    }
    return speedMode;
}

DualMotorMovementDriver::~DualMotorMovementDriver() {
    delete logger;
}

void DualMotorMovementDriver::logCommand(const Direction &direction) const {
    switch (direction) {
        case Direction::FORWARD:
            logger->newLine()->logAppend("go forward");
            break;
        case Direction::BACKWARD:
            logger->newLine()->logAppend("go backward");
            break;
        case Direction::TURN_LEFT:
            logger->newLine()->logAppend("go left");
            break;
        case Direction::TURN_RIGHT:
            logger->newLine()->logAppend("go right");
            break;
    }
}

void DualMotorMovementDriver::leftWheel(Direction direction, Speed speedMode) {

    byte speedFlag = convertSpeedMode(speedMode);
    byte directionFlag = 0;
    switch (direction) {
        case Direction::FORWARD:
            directionFlag = MOVE_FORWARD;
            break;
        case Direction::BACKWARD:
            directionFlag = MOVE_BACKWARD;
            break;
        case Direction::TURN_LEFT:
            directionFlag = MOVE_BACKWARD;
            break;
        case Direction::TURN_RIGHT:
            directionFlag = MOVE_FORWARD;
            break;
    }

    runMotor(speedFlag,
             directionFlag,
             MotorShieldPins::motor1Enable,
             MotorShieldPins::motor1Input1,
             MotorShieldPins::motor1Input2);

}

void DualMotorMovementDriver::rightWheel(Direction direction, Speed speedMode) {

    byte speedFlag = convertSpeedMode(speedMode);
    byte directionFlag = 0;
    switch (direction) {
        case Direction::FORWARD:
            directionFlag = MOVE_FORWARD;
            break;
        case Direction::BACKWARD:
            directionFlag = MOVE_BACKWARD;
            break;
        case Direction::TURN_LEFT:
            directionFlag = MOVE_FORWARD;
            break;
        case Direction::TURN_RIGHT:
            directionFlag = MOVE_BACKWARD;
            break;
    }


    runMotor(speedFlag,
             directionFlag,
             MotorShieldPins::motor2Enable,
             MotorShieldPins::motor2Input2,
             MotorShieldPins::motor2Input1);
}

void DualMotorMovementDriver::executeInternal(Direction direction, Speed speed) {
    if (direction == currentDirection && speed == currentSpeed) {
        return;
    }

    currentDirection = direction;
    currentSpeed = speed;

    logCommand(direction);
    leftWheel(direction, speed);
    rightWheel(direction, speed);
}

void DualMotorMovementDriver::stopInternal() {
    logger->newLine()->logAppend("stop");
    currentSpeed = Speed::NONE;
    currentDirection = Direction::NONE;
    digitalWrite(MotorShieldPins::motor1Enable, SPEED_MODE_ZERO);
    digitalWrite(MotorShieldPins::motor2Enable, SPEED_MODE_ZERO);
}
