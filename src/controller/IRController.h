//
// Created by Oleksandra Baukh on 1/17/18.
//

#ifndef MARK1_IRCONTROLLER_H
#define MARK1_IRCONTROLLER_H


#include <os/controller/Controller.h>
#include <sensors/IRSensor.h>

class IRController : public Controller {
    IRSensor irSensor;
    Mode *currentMode = nullptr;
public:
    IRController(const IRSensor &irSensor);

    void readControllerCommand() override;
};


#endif //MARK1_IRCONTROLLER_H
