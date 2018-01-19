//
// Created by Oleksandra Baukh on 1/17/18.
//

#ifndef MARK1_MODELISTENER_H
#define MARK1_MODELISTENER_H

#include "ModeName.h"
#include "modes/Mode.h"

class ModeListener {
protected:
    Mode *currentMode = new NoopMode;
public:
    virtual void onModeChange(ModeName mode)= 0;

    Mode *getCurrentMode() const {
        return currentMode;
    }

};

#endif //MARK1_MODELISTENER_H
