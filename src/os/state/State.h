//
// Created by Oleksandra Baukh on 1/10/18.
//

#ifndef MARKOS_STATE_H
#define MARKOS_STATE_H

template<class T>
class TransitionFunction;


class State {
protected:
public:

    virtual State &execute()= 0;

    virtual void cancel()=0;

    virtual void reset()=0;
};


template<class T>
class TransitionFunction {
public:
    virtual State &nextState(T &stateValue)= 0;
};


#endif //MARKOS_STATE_H
