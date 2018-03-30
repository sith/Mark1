//
// Created by Oleksandra Baukh on 2/26/18.
//

#ifndef MARK1_MARKIENVIRONMENT_H
#define MARK1_MARKIENVIRONMENT_H


#include <memory/SRAMMemoryMonitor.h>
#include <controller/RemoteController.h>
#include <drivers/DualMotorMovementDriver.h>
#include <sensors/USObstacleSensor.h>
#include <time/ArduinoClock.h>
#include <environment/Environment.h>
#include <filesystem/MySDFileSystem.h>
#include <missions/InMemoryMissionManager.h>
#include <TR433.h>

class MarkIEnvironment : public Environment {
    ModeManager modeManager;
    mark_os::cycle::Cycle cycle;
    SRAMMemoryMonitor memoryMonitor;
    TR433<mark_os::controller::ControllerState> receiver;
    RemoteController controller{receiver};

    DualMotorMovementDriver motorDriver;
    USObstacleSensor obstacleSensor;
    ArduinoClock clock;
    MySDFileSystem fileSystem;
    Timer timer{&clock};
    InMemoryMissionManager eventBasedMissionManager{motorDriver, timer, clock};
public:
    virtual ModeManager &getModeManager();

    virtual mark_os::cycle::Cycle &getCycle();

    virtual Timer &getTimer();

    virtual Controller &getController();

    virtual Clock &getClock();

    virtual MotorDriver &getMotorDriver();

    virtual ObstacleSensor &getObstacleSensor();

    virtual mark_os::filesystem::FileSystem &getFileSystem();

    virtual MemoryMonitor &getMemoryMonitor();

    MissionManager &getMissionManager() override;
};


#endif //MARK1_MARKIENVIRONMENT_H
