//
// Created by Oleksandra Baukh on 12/16/17.
//

#ifndef MARK1_TESTMODE_H
#define MARK1_TESTMODE_H


#include "Mode.h"
#include "logger/Logger.h"

class TestMode : public Mode {
private:

public:
    TestMode();

    const void process() override;

    const void stop() override;

    const char *getName() override;
};


#endif //MARK1_TESTMODE_H
