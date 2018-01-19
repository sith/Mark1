
#include "SerialLoggerFactory.h"
#include "logger/SerialLogger.h"

Logger &SerialLoggerFactory::createLogger(const char *name) {
    return *new SerialLogger(name);
}
