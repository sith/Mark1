//
// Created by Oleksandra Baukh on 12/22/17.
//

#ifndef MARK1_IRSENSORLISTENER_H
#define MARK1_IRSENSORLISTENER_H

#include "IRSensor.h"

class IRSensorListener {
    virtual void onResult(IRCode irCode)=0;
};

#endif //MARK1_IRSENSORLISTENER_H
