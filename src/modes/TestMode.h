//
// Created by Oleksandra Baukh on 12/16/17.
//

#ifndef MARK1_TESTMODE_H
#define MARK1_TESTMODE_H


#include <os/modes/ModeName.h>
#include "modes/Mode.h"
#include "os/logger/Logger.h"

class TestMode : public Mode {
private:

public:
    TestMode();

    const void process() override;

    const void stop() override;

};


#endif //MARK1_TESTMODE_H
