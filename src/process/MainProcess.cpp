//
// Created by Oleksandra Baukh on 12/22/17.
//

#include "env/Environment.h"
#include "MainProcess.h"

void MainProcess::runCurrentProcess() {

    IRCode code = Environment::getIrSensor()->getData();

/*
    IRCode newCode = irSensor.readCode();
    if (newCode == IRCode::FUNC_STOP) {
        irSensor.consumeLastCode();
        stopCurrentMode();
        return new NoopMode;
    }

    if (currentCode == IRCode::NONE) {
        switch (newCode) {
            case IRCode::NUMBER_1:
                irSensor.consumeLastCode();
                break;
            case IRCode::NUMBER_2:
                irSensor.consumeLastCode();
                break;
            case IRCode::NUMBER_3:
                irSensor.consumeLastCode();
                break;   
            case IRCode::NUMBER_4:
                irSensor.consumeLastCode();
                setCurrentMode(newCode, new SupervisedControlMode(movementDriver, &irSensor, distanceSensor));
                break;
            case IRCode::NUMBER_5:
                irSensor.consumeLastCode();
                setCurrentMode(newCode, new FreeRunMode(distanceSensor, movementDriver));
                break;
            case IRCode::NUMBER_0:
                irSensor.consumeLastCode();
                setCurrentMode(newCode, new TestMode());
                break;
            default:
                break;
        }
    }
    */

}

MainProcess::MainProcess() {

}

void MainProcess::onResult(IRCode irCode) {


}
