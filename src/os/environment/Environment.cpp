//
// Created by Oleksandra Baukh on 1/10/18.
//

#include "Environment.h"

Environment Environment::environment;

Environment &Environment::getEnvironment() {
    return environment;
}

void Environment::setEnvironment(Environment &environment) {
    Environment::environment = environment;
}

void Environment::setController(Controller &controller) {
    Environment::controller = &controller;
}

LoggerFactory *Environment::getLoggerFactory() const {
    return loggerFactory;
}

void Environment::setLoggerFactory(LoggerFactory &loggerFactory) {
    Environment::loggerFactory = &loggerFactory;
}
