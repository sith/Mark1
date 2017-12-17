#include <HardwareSerial.h>
#include "Mode.h"
#include "MovementDriver.h"
#include "IRSensor.h"

class SupervisedControlMode : public Mode {

    MovementDriver *movementDriver;
    IRSensor irSensor;

public:
    SupervisedControlMode(MovementDriver *movementDriver, const IRSensor &irSensor) : movementDriver(movementDriver),
                                                                                      irSensor(irSensor) {}

    const void process() override {
        IRCode code = irSensor.readCode();
        switch (code) {
            case IRCode::NUMBER_2:
                movementDriver->forward();
                break;
            case IRCode::NUMBER_4 :
                movementDriver->turnLeft();
                break;
            case IRCode::NUMBER_6:
                movementDriver->turnRight();
                break;
            case IRCode::NUMBER_8:
                movementDriver->backward();
                break;
            case IRCode::NUMBER_5:
                movementDriver->stop();
                break;
            default:
                break;
        }
    }

    const void stop() override {
        movementDriver->stop();
    }

    const char *getName() override {
        return "SupervisedControl";
    }
};


