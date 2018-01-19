//
// Created by Oleksandra Baukh on 1/10/18.
//

#ifndef MARKOS_ENVIRONMENT_H
#define MARKOS_ENVIRONMENT_H


#include <os/controller/Controller.h>
#include <os/logger/LoggerFactory.h>

class Environment {
    static Environment environment;
    Controller *controller;
    LoggerFactory *loggerFactory;

public:
    static void setEnvironment(Environment &environment);

    LoggerFactory *getLoggerFactory() const;

    void setLoggerFactory(LoggerFactory &loggerFactory);

    static Environment &getEnvironment();

    void setController(Controller &controller);

};


#endif //MARKOS_ENVIRONMENT_H
