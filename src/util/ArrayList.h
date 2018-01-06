//
// Created by Oleksandra Baukh on 12/25/17.
//

#ifndef MARK1_ARRAYLIST_H
#define MARK1_ARRAYLIST_H


#include "List.h"

namespace util {
    template<class T>
    class ArrayList : public util::List<T> {
    private:
        T array[];
        int lastIndex;
    public:
        ArrayList();

        ArrayList(int size);

        virtual void add(T &t);

        virtual void add(int index, T &t);

        virtual T *get(int index);

        virtual T *remove(int index);

        virtual T *remove(T &t);

        virtual int size();
    };

}
#endif //MARK1_ARRAYLIST_H
