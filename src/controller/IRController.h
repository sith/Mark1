//
// Created by Oleksandra Baukh on 1/17/18.
//

#ifndef MARK1_IRCONTROLLER_H
#define MARK1_IRCONTROLLER_H


#include <controller/Controller.h>
#include <sensors/IRSensor.h>

class IRController : public Controller {
    IRSensor irSensor;
public:
    IRController(IRSensor &irSensor);

    Command readControllerCommand() override;

    Command selectCommand(ModeName name);
};


#endif //MARK1_IRCONTROLLER_H
