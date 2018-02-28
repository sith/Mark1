//
// Created by Oleksandra Baukh on 2/26/18.
//

#ifndef MARK1_SDFILESYSTEM_H
#define MARK1_SDFILESYSTEM_H

#include <filesystem/FileSystem.h>

class SDFileSystem : public FileSystem{
    virtual Pointer <File> openFile(const char *path);

    Pointer<List<Pointer<File>>> listFiles() override;

    virtual void deleteFile(const char *path);

    virtual void createDirectory(const char *path);
};


#endif //MARK1_SDFILESYSTEM_H
