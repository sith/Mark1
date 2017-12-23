//
// Created by Oleksandra Baukh on 12/20/17.
//

#ifndef MARK1_IRMODEMANAGER_H
#define MARK1_IRMODEMANAGER_H

#include "ModeManager.h"
#include "sensors/Sensor.h"
#include "sensors/IRSensor.h"
#include "modes/FreeRunMode.h"
#include "modes/SupervisedControlMode.h"
#include "modes/TestMode.h"

class IRModeManager : public ModeManager {
private:

    static Logger *LOG;

    IRSensor irSensor;
    Mode *currentMode = new NoopMode;
    DistanceSensor *distanceSensor;
    MovementDriver *movementDriver;

    IRCode currentCode = IRCode::NONE;

    void stopCurrentMode();

    void setCurrentMode(IRCode code, Mode *currentMode);

public:
    IRModeManager(IRSensor irSensor,

                  DistanceSensor *distanceSensor,
                  MovementDriver *movementDriver);

    ~IRModeManager();

    Mode *getMode() override;
};


#endif //MARK1_IRMODEMANAGER_H
