#include "SupervisedControlMode.h"

Logger *SupervisedControlMode::LOG = Logger::createLogger("SupervisedControlMode");

SupervisedControlMode::SupervisedControlMode(MovementDriver *movementDriver, IRSensor *irSensor,
                                             DistanceSensor *distanceSensor)
        : movementDriver(movementDriver),
          irSensor(irSensor),
          distanceSensor(distanceSensor) {
}

    const void SupervisedControlMode::process() {
        bool obstacleUpFront = checkForObstacles(distanceSensor->getDistance());
    bool obstacleOnTheLeft = checkForObstacles(distanceSensor->getDistance(-30));
    bool obstacleOnTheRight = checkForObstacles(distanceSensor->getDistance(30));
    IRCode code = irSensor->readCode();
    switch (code) {
        case IRCode::NUMBER_2:
            movementDriver->forward();
            irSensor->consumeLastCode();
            break;
        case IRCode::NUMBER_4 :
            movementDriver->turnLeft();
            irSensor->consumeLastCode();
            break;
        case IRCode::NUMBER_6:
            movementDriver->turnRight();
            irSensor->consumeLastCode();
            break;
        case IRCode::NUMBER_8:
            movementDriver->backward();
            irSensor->consumeLastCode();
            break;
        case IRCode::NUMBER_5:
            movementDriver->stop();
            irSensor->consumeLastCode();
            break;
        default:
            break;
    }
}

bool SupervisedControlMode::checkForObstacles(long forwardObstacleDistance) const {
    if (forwardObstacleDistance < MIN_FORWARD_DISTANCE) {
        LOG->newLine()->logAppend("Obstacle found. Distance: ")->logAppend(forwardObstacleDistance);
        movementDriver->stop();
        return true;
    }
    return false;
}

const char *SupervisedControlMode::getName() {
    return "SupervisedControl";
}

const void SupervisedControlMode::stop() {
    movementDriver->stop();
}
