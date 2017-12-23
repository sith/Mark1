//
// Created by Oleksandra Baukh on 12/22/17.
//

#ifndef MARK1_MAINPROCESS_H
#define MARK1_MAINPROCESS_H


#include "sensors/IRSensorListener.h"
#include "Process.h"
#include "../logger/Logger.h"

class MainProcess : public framework::Process, public IRSensorListener {
    Logger *LOG = Logger::createLogger("MainProcess");

    virtual void runCurrentProcess();

    void onResult(IRCode irCode) override;

public:
    MainProcess();

};


#endif //MARK1_MAINPROCESS_H
