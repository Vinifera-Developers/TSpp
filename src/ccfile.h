/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  File interface which supports mixfiles.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "buff.h"
#include "cdfile.h"
#include "mixfile.h"


class CCFileClass : public CDFileClass
{
public:
    CCFileClass();
    CCFileClass(const char* filename);
    CCFileClass(const Wstring& filename);
    virtual ~CCFileClass();

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

    bool Is_Resident() const { return Data.Get_Buffer() != nullptr; }

private:
    Buffer Data;
    long Position;

private:
    CCFileClass const& operator=(const CCFileClass&) = delete;
    CCFileClass(const CCFileClass&) = delete;
};


/**
 *  Shorthand typedef to aid the programmer.
 */
typedef MixFileClass MFCD;
