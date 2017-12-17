//
// Created by Oleksandra Baukh on 12/13/17.
//

#ifndef MARK1_MODE_H
#define MARK1_MODE_H

class Mode {
public:
    virtual const void process()=0;

    virtual const void stop()=0;

    virtual const char *getName()=0;
};

class NoopMode : public Mode {
public:
    const void process() override {
    }

    const char *getName() override {
        return "NoOP";
    }

    const void stop() override {
    }
};

#endif //MARK1_MODE_H

