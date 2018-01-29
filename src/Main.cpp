#include <Arduino.h>

#include <logger/Logger.h>
#include <environment/Environment.h>
#include <controller/IRController.h>
#include <modes/ModeManager.h>
#include "time/ArduinoClock.h"
#include "SerialLoggerFactory.h"

ModeManager *modeManager;
IRController *irController;

void setup() {

    Serial.begin(9600);

    Environment::getEnvironment().setLoggerFactory(new SerialLoggerFactory);

    modeManager = new ModeManager;

    IRSensor *irSensor = new IRSensor;
    irController = new IRController(irSensor);
    Environment::getEnvironment().setController(irController);
    ArduinoClock *clock = new ArduinoClock;
    Environment::getEnvironment().setClock(clock);
    Timer *timer = new Timer(*clock);
    Environment::getEnvironment().setTimer(timer);
    Environment::getEnvironment().getCycle().getListeners()->add(timer);
    irController->addModeListener(*modeManager);

    Environment::getEnvironment().getLoggerFactory()->createLogger("Main")->newLine()->logAppend("App is started");
}

void loop() {
    Environment::getEnvironment().getCycle().next();
    irController->readControllerCommand();
    modeManager->getCurrentMode().process();
}