//
// Created by Oleksandra Baukh on 2/26/18.
//

#include "MarkIEnvironment.h"

ModeManager &MarkIEnvironment::getModeManager() {
    return modeManager;
}

Cycle &MarkIEnvironment::getCycle() {
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

FileSystem &MarkIEnvironment::getFileSystem() {
    return fileSystem;
}

MemoryMonitor &MarkIEnvironment::getMemoryMonitor() {
    return memoryMonitor;
}
