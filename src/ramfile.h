/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          RAMFILE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Memory file object.
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

#include "wwfile.h"


class RAMFileClass : public FileClass
{
    public:
        RAMFileClass(void *buffer, int len);
        virtual ~RAMFileClass();

        virtual const char *File_Name() const override;
        virtual const char *Set_Name(const char *filename) override;
        virtual bool Create() override;
        virtual bool Delete() override;
        virtual bool Is_Available(bool forced = false) override;
        virtual bool Is_Open() const override;
        virtual bool Open(const char *filename, FileAccessType rights = FILE_ACCESS_READ) override;
        virtual bool Open(FileAccessType rights = FILE_ACCESS_READ) override;
        virtual long Read(void *buffer, int length) override;
        virtual off_t Seek(off_t offset, FileSeekType whence = FILE_SEEK_CURRENT) override;
        virtual off_t Size() override;
        virtual long Write(const void *buffer, int length) override;
        virtual void Close() override;
        virtual LONG Get_Date_Time() const override;
        virtual bool Set_Date_Time(LONG date_time) override;
        virtual void Error(FileErrorType error, bool can_retry = false, const char *filename = nullptr) override;

    private:
        char * Buffer;
        int MaxLength;
        int Length;
        int Offset;
        FileAccessType Access;
        bool IsOpen;
        bool IsAllocated;
};
