//
// Created by Oleksandra Baukh on 1/19/18.
//

#include "../os/modes/ModeName.h"
#include "Mode.h"


Mode::Mode(ModeName modeName) : modeName(modeName) {}

ModeName &Mode::getModeName() const {
    return modeName;
}
