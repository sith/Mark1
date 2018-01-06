//
// Created by Oleksandra Baukh on 12/15/17.
//

#ifndef MARK1_DISTANCESENSOR_H
#define MARK1_DISTANCESENSOR_H

#include "Sensor.h"

class DistanceSensor : public Sensor<long> {
public:
    virtual long getDistance(int course)=0;

    long getDistance() {
        return getDistance(0);
    }

};

#endif //MARK1_DISTANCESENSOR_H
