//
// Created by Oleksandra Baukh on 12/25/17.
//

#ifndef MARK1_LIST_H
#define MARK1_LIST_H

namespace util {
    template<class T>
    class List {

    public:

        virtual void add(T &t) =0;

        virtual void add(int index, T &t) =0;

        virtual T *get(int index)=0;

        virtual T *remove(int index)=0;

        virtual T *remove(T &t)=0;

        virtual int size()=0;
    };

}
#endif //MARK1_LIST_H
