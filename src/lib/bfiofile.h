/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Buffered file interface with caching support.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "rawfile.h"


class BufferIOFileClass : public RawFileClass
{
public:
    BufferIOFileClass();
    BufferIOFileClass(const char* filename);
    BufferIOFileClass(const Wstring& filename);
    virtual ~BufferIOFileClass();

    virtual const char* Set_Name(const char* filename) override;
    virtual bool Is_Available(bool forced = false) override;
    virtual bool Is_Open() const override;
    virtual bool Open(const char* filename, FileAccessType rights = FILE_ACCESS_READ) override;
    virtual bool Open(FileAccessType rights = FILE_ACCESS_READ) override;
    virtual long Read(void* buffer, int length) override;
    virtual off_t Seek(off_t offset, FileSeekType whence = FILE_SEEK_CURRENT) override;
    virtual off_t Size() override;
    virtual long Write(const void* buffer, int length) override;
    virtual void Close() override;

    bool Cache(long size = 0, void* ptr = nullptr);
    void Free();
    bool Commit();

    enum {
        MINIMUM_BUFFER_SIZE = 1024
    };

private:
    bool IsAllocated;
    bool IsOpen;
    bool IsDiskOpen;
    bool IsCached;
    bool IsChanged;
    bool UseBuffer;
    int BufferRights;
    void* BufferPtr;
    long BufferSize;
    long BufferPos;
    long BufferFilePos;
    long BufferChangeBeg;
    long BufferChangeEnd;
    long FileSize;
    long FilePos;
    long TrueFileStart;
};
