//
// Created by Oleksandra Baukh on 12/16/17.
//

#ifndef MARK1_DUALMOTORMOVEMENTDRIVER_H
#define MARK1_DUALMOTORMOVEMENTDRIVER_H

#include <logger/Logger.h>
#include <Arduino.h>

#define MOVE_FORWARD 0x1
#define MOVE_BACKWARD 0x2

#define SPEED_MODE_ZERO 0
#define SPEED_MODE_SLOW 64
#define SPEED_MODE_MEDIUM 128
#define SPEED_MODE_FAST 250


class DualMotorMovementDriver : public MotorDriver {

    Logger *logger;
    Speed currentSpeed = Speed::NONE;
    Direction currentDirection = Direction::NONE;

    void leftWheel(Direction direction, Speed speedMode);

    void rightWheel(Direction direction, Speed speedMode);

    void runMotor(byte speed, byte direction, byte enablePin, byte input1Pin, byte input2Pin) const;

    byte convertSpeedMode(const Speed &speed) const;

    void logCommand(const Direction &direction) const;
public:
    virtual ~DualMotorMovementDriver();

    DualMotorMovementDriver();

protected:
    void executeInternal(Direction direction, Speed speed) override;

    void stopInternal() override;

};


#endif //MARK1_DUALMOTORMOVEMENTDRIVER_H
