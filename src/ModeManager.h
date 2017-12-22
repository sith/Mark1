//
// Created by Oleksandra Baukh on 12/13/17.
//

#ifndef MARK1_MODESELECTOR_H
#define MARK1_MODESELECTOR_H

#include "modes/Mode.h"

class ModeManager {
public:
    virtual Mode *getMode()=0;

};

#endif //MARK1_MODESELECTOR_H
