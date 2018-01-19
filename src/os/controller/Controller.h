//
// Created by Oleksandra Baukh on 1/16/18.
//

#ifndef MARK1_CONTROLLER_H
#define MARK1_CONTROLLER_H

#include <os/modes/EmptyModeListener.h>
#include "os/modes/ModeListener.h"

class Controller {
protected:
    ModeListener *modeListener = new EmptyModeListener;
public:
    void addModeListener(ModeListener &ml);

    virtual void readControllerCommand()=0;
};

#endif //MARK1_CONTROLLER_H
