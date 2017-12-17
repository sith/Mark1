//
// Created by Oleksandra Baukh on 12/16/17.
//

#ifndef MARK1_TESTMODE_H
#define MARK1_TESTMODE_H


#include "Mode.h"
#include "Logger.h"

class TestMode : public Mode {
private:
    Logger *logger;
public:
    TestMode(Logger *logger);

    const void process() override;

    const void stop() override;

    const char *getName() override;
};


#endif //MARK1_TESTMODE_H
