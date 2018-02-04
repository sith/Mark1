#include <Arduino.h>

#include <logger/Logger.h>
#include <environment/Environment.h>
#include <controller/IRController.h>
#include <modes/ModeManager.h>
#include "time/ArduinoClock.h"
#include "SerialLoggerFactory.h"


void setup() {

    Serial.begin(9600);

    LoggerFactory::setLoggerFactory(new SerialLoggerFactory);
    auto *irSensor = new IRSensor;
    Environment::getEnvironment().setClock(new ArduinoClock);
    Environment::getEnvironment().setController(new IRController(irSensor));

    Environment::getEnvironment().init();

    LoggerFactory::newLogger("Main")->newLine()->logAppend("App is started");
}

void loop() {
    Environment::getEnvironment().loop();

}