#include <Arduino.h>
#include <modes/ModeManager.h>
#include <os/logger/Logger.h>
#include <os/environment/Environment.h>
#include <controller/IRController.h>
#include "SerialLoggerFactory.h"


ModeManager *modeManager;

void setup() {
    Serial.begin(9600);

    Environment environment = *new Environment;

    IRSensor &irSensor = *new IRSensor;
    modeManager = new ModeManager;

    Controller &controller = *new IRController(irSensor);
    controller.addModeListener(*modeManager);

    environment.setController(controller);
    environment.setLoggerFactory(*new SerialLoggerFactory);

    Environment::setEnvironment(environment);
}

void loop() {
    Mode *mode = modeManager->getCurrentMode();
    mode->process();
}