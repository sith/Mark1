//
// Created by Oleksandra Baukh on 2/26/18.
//

#ifndef MARK1_MARKIENVIRONMENT_H
#define MARK1_MARKIENVIRONMENT_H


#include <memory/SRAMMemoryMonitor.h>
#include <controller/IRController.h>
#include <drivers/DualMotorMovementDriver.h>
#include <sensors/USObstacleSensor.h>
#include <time/ArduinoClock.h>
#include <environment/Environment.h>
#include <filesystem/SDFileSystem.h>

class MarkIEnvironment : public Environment {
    ModeManager modeManager;
    Cycle cycle;
    SRAMMemoryMonitor memoryMonitor;
    IRSensor irSensor;
    IRController controller{irSensor};
    DualMotorMovementDriver motorDriver;
    USObstacleSensor obstacleSensor;
    ArduinoClock clock;
    SDFileSystem fileSystem;
    Timer timer{&clock};

public:
    virtual ModeManager &getModeManager();

    virtual Cycle &getCycle();

    virtual Timer &getTimer();

    virtual Controller &getController();

    virtual Clock &getClock();

    virtual MotorDriver &getMotorDriver();

    virtual ObstacleSensor &getObstacleSensor();

    virtual FileSystem &getFileSystem();

    virtual MemoryMonitor &getMemoryMonitor();
};


#endif //MARK1_MARKIENVIRONMENT_H
