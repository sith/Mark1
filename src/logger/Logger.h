//
// Created by Oleksandra Baukh on 12/13/17.
//

#ifndef MARK1_LOGGER_H
#define MARK1_LOGGER_H


class Logger {
private:
    static Logger *LOGGER;
    static unsigned long cycle;
public:
    static void nextCycle();

    static unsigned long getCycle();

    virtual Logger *logAppend(const char c[])= 0;

    virtual Logger *logAppend(int number)= 0;

    virtual Logger *newLine()= 0;

    static Logger *createLogger(char *name);

};

#endif //MARK1_LOGGER_H
