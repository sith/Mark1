//
// Created by Oleksandra Baukh on 12/15/17.
//

#ifndef MARK1_MOVEMENTDRIVER_H
#define MARK1_MOVEMENTDRIVER_H

#define SPEED_MODE_ZERO 0
#define SPEED_MODE_SLOW 64
#define SPEED_MODE_MEDIUM 128
#define SPEED_MODE_FAST 255


enum MovementDriverState {
    FORWARD_,
    BACKWARD_,
    TURN_LEFT_,
    TURN_RIGHT_,
    STOP_
};

class MovementDriver {
public:
    virtual void forward()=0;

    virtual void backward()=0;

    virtual void turnLeft()=0;

    virtual void turnRight()=0;

    virtual void stop()=0;


    virtual MovementDriverState getMovementDriverState()=0;


};

#endif //MARK1_MOVEMENTDRIVER_H
