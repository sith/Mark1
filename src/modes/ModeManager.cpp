//
// Created by Oleksandra Baukh on 1/17/18.
//

#include "ModeManager.h"
#include "TestMode.h"

void ModeManager::onModeChange(ModeName mode) {

    if (currentMode->getModeName() == mode) {
        return;
    }

    switch (mode) {
        case ModeName::TEST:
            currentMode = new TestMode;
            break;
        default:
            return;
    }
}

ModeManager::ModeManager() : logger(Environment::getEnvironment().getLoggerFactory()->createLogger("ModeManager")) {}
