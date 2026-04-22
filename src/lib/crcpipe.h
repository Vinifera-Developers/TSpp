/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  CRC based data stream pipe using the Westwood CRC engine.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "pipe.h"
#include "wwcrc.h"


class CRCPipe : public Pipe
{
public:
    CRCPipe() {}
    ~CRCPipe() {}

    virtual int Put(const void* source, int slen);

    long Result() const;

protected:
    CRCEngine CRC;

private:
    CRCPipe(CRCPipe&) = delete;
    CRCPipe& operator=(const CRCPipe&) = delete;
};
