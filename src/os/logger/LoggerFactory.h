//
// Created by Oleksandra Baukh on 1/19/18.
//

#ifndef MARK1_LOGGERFACTORY_H
#define MARK1_LOGGERFACTORY_H

#include "Logger.h"

class LoggerFactory {
public:
    virtual Logger &createLogger(const char *name)= 0;
};

#endif //MARK1_LOGGERFACTORY_H
