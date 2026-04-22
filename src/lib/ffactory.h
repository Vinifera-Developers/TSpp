/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Basic file factories.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "critsection.h"


class FileClass;
class RawFileClass;


class FileFactoryClass
{
public:
    FileFactoryClass() {}
    virtual ~FileFactoryClass() {}

    virtual FileClass* Get_File(const char* filename) = 0;
    virtual void Return_File(FileClass* file) = 0;
};

class RawFileFactoryClass : public FileFactoryClass
{
public:
    RawFileFactoryClass() {}
    virtual ~RawFileFactoryClass() {}

    virtual FileClass* Get_File(const char* filename) override;
    virtual void Return_File(FileClass* file) override;
};

class SimpleFileFactoryClass : public FileFactoryClass
{
public:
    SimpleFileFactoryClass();
    virtual ~SimpleFileFactoryClass() {}

    virtual FileClass* Get_File(const char* filename) override;
    virtual void Return_File(FileClass* file) override;

    void Get_Sub_Directory(char* new_dir);
    void Set_Sub_Directory(const char* sub_directory);
    void Prepend_Sub_Directory(const char* sub_directory);
    void Append_Sub_Directory(const char* sub_directory);
    bool Get_Strip_Path() { return IsStripPath; }
    void Set_Strip_Path(bool strip) { IsStripPath = strip; }

private:
    bool Is_Full_Path(const char* path);

private:
    char SubDirectory[PATH_MAX];
    CriticalSectionClass Mutex;
    bool IsStripPath;
};

/**
 *  Pointer wrapper from RAII style use of file classes.
 */
class FileAutoPtr
{
public:
    FileAutoPtr();
    FileAutoPtr(FileFactoryClass* fac, const char* filename);
    ~FileAutoPtr();

    FileAutoPtr& operator=(const FileAutoPtr& that)
    {
        if (this != &that) {
            Ptr = that.Ptr;
            Fac = that.Fac;
        }
        return *this;
    }

    operator FileClass*() const { return Ptr; }
    operator bool() const { return Ptr != nullptr; }

    FileClass& operator*() { return *Ptr; }
    FileClass* operator->() { return Ptr; }

    FileClass* Get() { return Ptr; }

private:
    FileClass* Ptr;
    FileFactoryClass* Fac;
};

extern FileFactoryClass* TheFileFactory;
extern RawFileFactoryClass* TheWritingFileFactory;
