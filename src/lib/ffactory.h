/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          FFACTORY.H
 *
 *  @authors       CCHyper, OmniBlade
 *
 *  @brief         Basic file factories.
 *
 *  @license       TS++ is free software: you can redistribute it and/or
 *                 modify it under the terms of the GNU General Public License
 *                 as published by the Free Software Foundation, either version
 *                 3 of the License, or (at your option) any later version.
 *
 *                 TS++ is distributed in the hope that it will be
 *                 useful, but WITHOUT ANY WARRANTY; without even the implied
 *                 warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *                 PURPOSE. See the GNU General Public License for more details.
 *
 *                 You should have received a copy of the GNU General Public
 *                 License along with this program.
 *                 If not, see <http://www.gnu.org/licenses/>.
 *
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
