//
// Created by Oleksandra Baukh on 1/17/18.
//

#include <environment/Environment.h>
#include "IRController.h"

IRController::IRController(IRSensor &irSensor) : irSensor(irSensor){}

Command IRController::readControllerCommand() {
    IRCode code = irSensor.readCode();

    if (code == IRCode::FUNC_STOP) {
        modeName = ModeName::NONE;
        return Command::STOP_MODE;
    }

    if (modeName == ModeName::NONE) {
        switch (code) {
            case IRCode::NUMBER_1:
                break;
            case IRCode::NUMBER_2:
                break;
            case IRCode::NUMBER_3:
                return selectCommand(ModeName::FREE_RUN);
            case IRCode::NUMBER_4:
                break;
            case IRCode::NUMBER_5:
                return selectCommand(ModeName::SUPERVISED);
            default:
                break;
        }
    } else {
        switch (code) {
            case IRCode::NUMBER_1:
                break;
            case IRCode::NUMBER_2:
                return Command::FORWARD;
            case IRCode::NUMBER_3:
                break;
            case IRCode::NUMBER_4:
                return Command::LEFT;
            case IRCode::NUMBER_5:
                return Command::STOP;
            case IRCode::NUMBER_6:
                return Command::RIGHT;
            case IRCode::NUMBER_8:
                return Command::BACKWARD;
            default:
                break;
        }
    }

    return Command::NONE;
}

Command IRController::selectCommand(ModeName name) {
    if (modeName == ModeName::NONE) {
        modeName = name;
        return Command::SELECT_MODE;
    } else {
        return Command::NONE;
    }
}
