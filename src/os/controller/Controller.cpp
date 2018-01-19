//
// Created by Oleksandra Baukh on 1/17/18.
//


#include "Controller.h"
#include "../modes/ModeListener.h"

void Controller::addModeListener(ModeListener &ml) {
    modeListener = &ml;
}
