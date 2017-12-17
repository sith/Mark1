#include "Mode.h"
#include "DistanceSensor.h"
#include "MovementDriver.h"

#define OBSTACLE_DISTANCE_THRESHOLD 15

class FreeRunMode : public Mode {

    DistanceSensor *distanceSensor;
    MovementDriver *movementDriver;

public:
    FreeRunMode(DistanceSensor *distanceSensor,
                MovementDriver *movementDriver) :
            distanceSensor(distanceSensor),
            movementDriver(movementDriver) {}

    const void process() {
        int distance = distanceSensor->getDistance();

        if (distance <= OBSTACLE_DISTANCE_THRESHOLD) {
            movementDriver->turnLeft();
        } else {
            movementDriver->turnRight();
        }
    }

    virtual const void stop() {
        movementDriver->stop();
    }

    virtual const char *getName() {
        return "FreeRunMode";
    }
};
