/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  CRC based data stream straw using the Westwood CRC engine.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "straw.h"
#include "wwcrc.h"


class CRCStraw : public Straw
{
public:
    CRCStraw() {}
    ~CRCStraw() {}

    virtual int Get(void* source, int slen);

    long Result() const;

protected:
    CRCEngine CRC;

private:
    CRCStraw(CRCStraw&) = delete;
    CRCStraw& operator=(const CRCStraw&) = delete;
};
