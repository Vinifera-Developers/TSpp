/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  File based straw.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "straw.h"
#include "wwfile.h"


class FileStraw : public Straw
{
public:
    FileStraw(FileClass* file);
    FileStraw(FileClass& file);
    virtual ~FileStraw();

    virtual int Get(void* source, int slen) override;

private:
    bool Valid_File() { return File != nullptr; }

private:
    FileClass* File;
    bool HasOpened;

private:
    FileStraw(FileStraw&) = delete;
    FileStraw& operator=(const FileStraw&) = delete;
};
