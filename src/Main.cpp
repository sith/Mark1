#ifndef UNIT_TEST

#include <Arduino.h>
#include <process/MainProcess.h>
#include <env/Environment.h>
#include "ModeManager.h"
#include "IRModeManager.h"
#include "drivers/DualMotorMovementDriver.h"
#include "sensors/USDistanceSensor.h"

ModeManager *modeManager;

MainProcess mainProcess = *new MainProcess();
Environment environment;

void setup() {
    Serial.begin(9600);
    IRSensor sensor;


    IRSensorListener *mainProcessIRSensorListener = &mainProcess;
    environment.registorIRSensorListener(mainProcessIRSensorListener);

    DistanceSensor *distanceDriver = new USDistanceSensor();
    MovementDriver *movementDriver = new DualMotorMovementDriver();
    modeManager = new IRModeManager(sensor, distanceDriver, movementDriver);
}

void loop() {


    Logger::nextCycle();
    mainProcess.run();
    Mode *mode = modeManager->getMode();
    mode->process();
}

#endif