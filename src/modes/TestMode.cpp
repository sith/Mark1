//
// Created by Oleksandra Baukh on 12/16/17.
//

#include "TestMode.h"
#include "drivers/DualMotorMovementDriver.h"

const void TestMode::process() {
    return;
}

const void TestMode::stop() {
    return;
}

const char *TestMode::getName() {
    return "Test";
}

TestMode::TestMode() {
        DualMotorMovementDriver movementDriver();
}     