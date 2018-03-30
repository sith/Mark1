//
// Created by Oleksandra Baukh on 2/26/18.
//

#ifndef MARK1_SDFILE_H
#define MARK1_SDFILE_H

#include <filesystem/File.h>


class SDFile : public mark_os::filesystem::File {
public:
    virtual int readInt();

    virtual Pointer<const char *> readString();
};


#endif //MARK1_SDFILE_H
