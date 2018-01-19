//
// Created by Oleksandra Baukh on 1/19/18.
//

#ifndef MARK1_SERIALLOGGERFACTORY_H
#define MARK1_SERIALLOGGERFACTORY_H


#include "os/logger/LoggerFactory.h"

class SerialLoggerFactory : public LoggerFactory {
public:
    Logger &createLogger(const char *name) override;
};


#endif //MARK1_SERIALLOGGERFACTORY_H
