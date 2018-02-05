//
// Created by Oleksandra Baukh on 1/17/18.
//

#include <environment/Environment.h>
#include "IRController.h"

IRController::IRController(IRSensor *irSensor) : irSensor(*irSensor),
                                                 logger(LoggerFactory::newLogger("IRController")) {}

Command IRController::readControllerCommand() {
    IRCode code = irSensor.readCode();

    if (code == IRCode::FUNC_STOP) {
        logger->newLine()->logAppend("Stop mode: ")->logAppend(Mode::getModeNameString(modeName));
        modeName = ModeName::NONE;
        return Command::STOP_MODE;
    }

    switch (code) {
        case IRCode::NUMBER_1:
            break;
        case IRCode::NUMBER_2:
            break;
        case IRCode::NUMBER_3:
            break;
        case IRCode::NUMBER_4:
            break;
        case IRCode::NUMBER_5:
            return selectCommand(SUPERVISED);
        case IRCode::NUMBER_6:
            return selectCommand(TEST);
        default:
            break;
    }
}

Command IRController::selectCommand(ModeName name) {
    if (modeName == NONE) {
        modeName = name;
        return Command::SELECT_MODE;
    } else {
        return Command::NONE;
    }
}
