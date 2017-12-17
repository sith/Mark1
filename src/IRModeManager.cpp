#include "ModeManager.h"
#include "IRSensor.h"
#include "Logger.h"
#include "FreeRunMode.cpp"
#include "SupervisedControlMode.cpp"
#include "MovementDriver.h"
#include "DistanceSensor.h"
#include "TestMode.h"

class IRModeManager : public ModeManager {
private:
    IRSensor irSensor;
    Logger *logger;
    Mode *currentMode = new NoopMode;
    DistanceSensor *distanceSensor;
    MovementDriver *movementDriver;

    IRCode currentCode = IRCode::UNKNOWN_CODE;

    void stopCurrentMode() {
        logger
                ->logAppend("Cancel mode:")
                ->logAppend(currentMode->getName())
                ->newLine();
        currentMode->stop();
        currentCode = IRCode::NONE;
        currentMode = new NoopMode;
    }

    void setCurrentMode(IRCode code, Mode *currentMode) {
        logger->logAppend("Set mode: ")->logAppend(currentMode->getName())->newLine();
        stopCurrentMode();
        IRModeManager::currentMode = currentMode;
        IRModeManager::currentCode = code;
    }

public:
    IRModeManager(IRSensor irSensor,
                  Logger *logger,
                  DistanceSensor *distanceSensor,
                  MovementDriver *movementDriver) :
            irSensor(irSensor),
            logger(logger),
            distanceSensor(distanceSensor),
            movementDriver(movementDriver) {
    }

    ~IRModeManager() {
        currentMode->stop();
    }

    Mode *getMode() override {

        IRCode newCode = irSensor.readCode();
        if (newCode == IRCode::FUNC_STOP) {
            stopCurrentMode();
            return new NoopMode;
        }

        if (currentCode == IRCode::NONE) {
            switch (newCode) {
                case IRCode::NUMBER_1:
                    break;
                case IRCode::NUMBER_2:
                    break;
                case IRCode::NUMBER_3:
                    break;
                case IRCode::NUMBER_4:
                    setCurrentMode(newCode, new SupervisedControlMode(movementDriver, irSensor));
                    break;
                case IRCode::NUMBER_5: {
                    //setCurrentMode(new FreeRunMode(distanceSensor, movementDriver));
                    break;
                }
                case IRCode::NUMBER_0:
                    setCurrentMode(newCode, new TestMode(logger));
                    break;
                default:
                    break;
            }
        }
        return currentMode;
    }
};

