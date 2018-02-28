#include <Arduino.h>

#include <logger/Logger.h>
#include <environment/Environment.h>
#include <controller/IRController.h>
#include <drivers/DualMotorMovementDriver.h>
#include <sensors/USObstacleSensor.h>
#include "time/ArduinoClock.h"
#include "SerialLoggerFactory.h"
#include "MarkIEnvironment.h"


void setup() {

    Serial.begin(9600);

    LoggerFactory::setLoggerFactory(new SerialLoggerFactory);
    SRAMMemoryMonitor memoryMonitor;
    Environment::setEnvironment(*new MarkIEnvironment{});
    Environment::getEnvironment().init();

     auto mainLogger = LoggerFactory::newLogger("Main");
     mainLogger->newLine()->logAppend("App is started");

    Serial.println(memoryMonitor.available());
}

void loop() {
    Environment::getEnvironment().loop();
}