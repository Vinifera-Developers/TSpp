/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  File based pipe.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "pipe.h"
#include "wwfile.h"


class FilePipe : public Pipe
{
public:
    FilePipe(FileClass* file);
    FilePipe(FileClass& file);
    virtual ~FilePipe();

    virtual int Put(const void* source, int slen) override;
    virtual int End() override;

private:
    bool Valid_File() { return File != nullptr; }

private:
    FileClass* File;
    bool HasOpened;

private:
    FilePipe(FilePipe& rvalue);
    FilePipe& operator=(const FilePipe& pipe);
};
