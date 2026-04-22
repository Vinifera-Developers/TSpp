/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Basic file io interface.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "wwfile.h"
#include <Windows.h>


class RawFileClass : public FileClass
{
public:
    RawFileClass();
    // RawFileClass(const RawFileClass &f);
    RawFileClass(const char* filename);
    RawFileClass(const Wstring& filename);
    virtual ~RawFileClass();

    virtual const char* File_Name() const override;
    virtual const char* Set_Name(const char* filename) override;
    virtual bool Create() override;
    virtual bool Delete() override;
    virtual bool Is_Available(bool forced = false) override;
    virtual bool Is_Open() const override;
    virtual bool Open(const char* filename, FileAccessType rights = FILE_ACCESS_READ) override;
    virtual bool Open(FileAccessType rights = FILE_ACCESS_READ) override;
    virtual long Read(void* buffer, int length) override;
    virtual off_t Seek(off_t offset, FileSeekType whence = FILE_SEEK_CURRENT) override;
    virtual off_t Size() override;
    virtual long Write(const void* buffer, int length) override;
    virtual void Close() override;
    virtual LONG Get_Date_Time() const override;
    virtual bool Set_Date_Time(LONG date_time) override;
    virtual void Error(FileErrorType error, bool can_retry = false, const char* filename = nullptr) override;

    void Bias(off_t start, int length = -1);

    HANDLE Get_File_Handle() { return Handle; }

protected:
    int Transfer_Block_Size() { return (int)((unsigned)UINT_MAX) - 16L; }
    const char* Get_Safe_File_Name() const { return (Filename != nullptr && Filename[0] != '\0') ? Filename : "<unknown>"; }

    off_t Raw_Seek(off_t offset, FileSeekType whence = FILE_SEEK_CURRENT);

protected:
    FileAccessType Rights;

public:
    int BiasStart;
    int BiasLength;

protected:
    HANDLE Handle;
    char* Filename;
    WORD Date;
    WORD Time;
    bool Allocated;
};
