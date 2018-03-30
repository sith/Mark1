#include "MarkIEnvironment.h"

ModeManager &MarkIEnvironment::getModeManager() {
    return modeManager;
}

mark_os::cycle::Cycle &MarkIEnvironment::getCycle() {
    return cycle;
}

Timer &MarkIEnvironment::getTimer() {
    return timer;
}

Controller &MarkIEnvironment::getController() {
    return controller;
}

Clock &MarkIEnvironment::getClock() {
    return clock;
}

MotorDriver &MarkIEnvironment::getMotorDriver() {
    return motorDriver;
}

ObstacleSensor &MarkIEnvironment::getObstacleSensor() {
    return obstacleSensor;
}

mark_os::filesystem::FileSystem &MarkIEnvironment::getFileSystem() {
    return fileSystem;
}

MemoryMonitor &MarkIEnvironment::getMemoryMonitor() {
    return memoryMonitor;
}

MissionManager &MarkIEnvironment::getMissionManager() {
    return eventBasedMissionManager;
}
