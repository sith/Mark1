//
// Created by Oleksandra Baukh on 1/17/18.
//

#ifndef MARK1_MARKIMODELISTENER_H
#define MARK1_MARKIMODELISTENER_H


#include <os/logger/Logger.h>
#include <os/environment/Environment.h>
#include "os/modes/ModeListener.h"

class ModeManager : public ModeListener {
    Logger &logger;
public:
    ModeManager();

    void onModeChange(ModeName mode) override;
};


#endif //MARK1_MARKIMODELISTENER_H
