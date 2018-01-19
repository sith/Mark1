//
// Created by Oleksandra Baukh on 1/17/18.
//

#include "IRController.h"

void IRController::readControllerCommand() {

    IRCode code = irSensor.readCode();

    if (code == IRCode::FUNC_STOP) {
        modeListener->onModeChange(ModeName::NONE);
        currentMode = nullptr;
        return;
    }

    if (currentMode != nullptr) {
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
            modeListener->onModeChange(ModeName::TEST);
            break;
        default:
            break;
    }

}

IRController::IRController(const IRSensor &irSensor) : irSensor(irSensor) {}
