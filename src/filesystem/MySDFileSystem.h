//
// Created by Oleksandra Baukh on 2/26/18.
//

#ifndef MARK1_SDFILESYSTEM_H
#define MARK1_SDFILESYSTEM_H

#include <filesystem/FileSystem.h>


class MySDFileSystem : public mark_os::filesystem::FileSystem {
    virtual Pointer<mark_os::filesystem::File> openFile(const char *path);

    virtual void deleteFile(const char *path);

    virtual void createDirectory(const char *path);
};


#endif //MARK1_SDFILESYSTEM_H
