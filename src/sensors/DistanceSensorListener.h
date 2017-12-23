//
// Created by Oleksandra Baukh on 12/22/17.
//

#ifndef MARK1_DISTANCESENSORLISTENER_H
#define MARK1_DISTANCESENSORLISTENER_H

class DistanceSensorListener {
    virtual void onResult(int course, int distance)=0;
};

#endif //MARK1_DISTANCESENSORLISTENER_H
