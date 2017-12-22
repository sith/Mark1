#include <Arduino.h>
#include "ModeManager.h"
#include "IRModeManager.h"
#include "DualMotorMovementDriver.h"
#include "USDistanceSensor.h"

ModeManager *modeManager;

void setup() {
    Serial.begin(9600);
    IRSensor sensor;
    DistanceSensor *distanceDriver = new USDistanceSensor();
    MovementDriver *movementDriver = new DualMotorMovementDriver();
    modeManager = new IRModeManager(sensor, distanceDriver, movementDriver);
}

void loop() {
    Logger::nextCycle();
    Mode *mode = modeManager->getMode();
    mode->process();
}