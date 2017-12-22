#include "IRModeManager.h"

Logger *IRModeManager::LOG = Logger::createLogger("IRModeManager");

void IRModeManager::stopCurrentMode() {
    LOG
            ->newLine()
            ->logAppend("Cancel mode:")
            ->logAppend(currentMode->getName());
    currentMode->stop();
    currentCode = IRCode::NONE;
    currentMode = new NoopMode;
}

void IRModeManager::setCurrentMode(IRCode code, Mode *currentMode) {
    LOG->newLine()->logAppend("Set mode: ")->logAppend(currentMode->getName());
    stopCurrentMode();
    IRModeManager::currentMode = currentMode;
    IRModeManager::currentCode = code;
}

IRModeManager::IRModeManager(IRSensor irSensor, DistanceSensor *distanceSensor, MovementDriver *movementDriver) :
        irSensor(irSensor),
        distanceSensor(distanceSensor),
        movementDriver(movementDriver) {
}

IRModeManager::~IRModeManager() {
    currentMode->stop();
}

Mode *IRModeManager::getMode() {
    IRCode newCode = irSensor.readCode();
    if (newCode == IRCode::FUNC_STOP) {
        irSensor.consumeLastCode();
        stopCurrentMode();
        return new NoopMode;
    }

    if (currentCode == IRCode::NONE) {
        switch (newCode) {
            case IRCode::NUMBER_1:
                irSensor.consumeLastCode();
                break;
            case IRCode::NUMBER_2:
                irSensor.consumeLastCode();
                break;
            case IRCode::NUMBER_3:
                irSensor.consumeLastCode();
                break;
            case IRCode::NUMBER_4:
                irSensor.consumeLastCode();
                setCurrentMode(newCode, new SupervisedControlMode(movementDriver, &irSensor, distanceSensor));
                break;
            case IRCode::NUMBER_5:
                irSensor.consumeLastCode();
                setCurrentMode(newCode, new FreeRunMode(distanceSensor, movementDriver));
                break;
            case IRCode::NUMBER_0:
                irSensor.consumeLastCode();
                setCurrentMode(newCode, new TestMode());
                break;
            default:
                break;
        }
    }
    return currentMode;
}
