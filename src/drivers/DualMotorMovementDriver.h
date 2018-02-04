//
// Created by Oleksandra Baukh on 12/16/17.
//

#ifndef MARK1_DUALMOTORMOVEMENTDRIVER_H
#define MARK1_DUALMOTORMOVEMENTDRIVER_H

#include "drivers/MovementDriver.h"
#include <logger/Logger.h>
#include <Arduino.h>

#define STOP 0x0
#define MOVE_FORWARD 0x1
#define MOVE_BACKWARD 0x2




class DualMotorMovementDriver : public MovementDriver {
private:

    Logger *logger;

    MovementDriverState movementDriverState;

    void leftWheel(byte speedMode = SPEED_MODE_ZERO, byte direction = STOP);

    void rightWheel(byte speedMode = SPEED_MODE_ZERO, byte direction = STOP);

    void runMotor(byte speedMode, byte direction, byte enablePin, byte input1Pin, byte input2Pin) const;

public:

    virtual ~DualMotorMovementDriver();

    DualMotorMovementDriver();

    void forward() override;

    void backward() override;

    void turnLeft() override;

    void turnRight() override;

    void stop() override;

    MovementDriverState getMovementDriverState() override;

};


#endif //MARK1_DUALMOTORMOVEMENTDRIVER_H
