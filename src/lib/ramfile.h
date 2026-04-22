/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Memory file object.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "wwfile.h"


class RAMFileClass : public FileClass
{
public:
    RAMFileClass(void* buffer, int len);
    virtual ~RAMFileClass();

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

private:
    char* Buffer;
    int MaxLength;
    int Length;
    int Offset;
    FileAccessType Access;
    bool IsOpen;
    bool IsAllocated;
};
