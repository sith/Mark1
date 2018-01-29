//
// Created by Oleksandra Baukh on 1/17/18.
//

#include <environment/Environment.h>
#include "IRController.h"

void IRController::readControllerCommand() {

    IRCode code = irSensor.readCode();

    if (code == IRCode::FUNC_STOP) {
        logger->newLine()->logAppend("Stop mode: ")->logAppend(Mode::getModeNameString(currentModeName));
        modeListener->onModeChange(ModeName::NONE);
        currentModeName = ModeName::NONE;
        return;
    }

    if (currentModeName != ModeName::NONE) {
        return;
    }

    switch (code) {
        case IRCode::NUMBER_1:
            break;
        case IRCode::NUMBER_2:
            break;
        case IRCode::NUMBER_3:
            break;
        case IRCode::NUMBER_4:
            //            setCurrentMode(newCode, new SupervisedControlMode(movementDriver, &irSensor, distanceSensor));
            break;
        case IRCode::NUMBER_5:
//            setCurrentMode(newCode, new FreeRunMode(distanceSensor, movementDriver));
            break;
        case IRCode::NUMBER_0:
            notifyNewMode(ModeName::TEST);
            break;
        default:
            break;
    }

}

IRController::IRController( IRSensor *irSensor) : irSensor(*irSensor),
                                                       logger(Environment::getEnvironment().getLoggerFactory()->createLogger(
                                                               "IRController")) {}

void IRController::notifyNewMode(ModeName name) {
//    logger->newLine()->logAppend("New mode: ")->logAppend(Mode::getModeNameString(name));
    currentModeName = name;
    modeListener->onModeChange(name);
}
