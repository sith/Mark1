#include <Arduino.h>
#include "ModeManager.h"
#include "IRModeManager.cpp"
#include "SerialLogger.cpp"
#include "DualMotorMovementDriver.h"

ModeManager *modeManager;
Logger *logger;


void setup() {
    Serial.begin(9600);
    logger = new SerialLogger();
    IRSensor sensor;
    DistanceSensor *distanceDriver = NULL;
    MovementDriver *movementDriver = new DualMotorMovementDriver(logger);
    modeManager = new IRModeManager(sensor, logger, distanceDriver, movementDriver);
}

void loop() {
    Mode *mode = modeManager->getMode();
    mode->process();
}