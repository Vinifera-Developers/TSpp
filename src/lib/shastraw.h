/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Secure Hash straw.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "sha.h"
#include "straw.h"


class SHAStraw : public Straw
{
public:
    SHAStraw(bool bypass_sha = false);
    ~SHAStraw();

    virtual int Get(void* source, int slen) override;

    int Result(void* result) const;

protected:
    bool BypassSHA;
    SHAEngine SHA;

private:
    SHAStraw(const SHAStraw&) = delete;
    SHAStraw& operator=(const SHAStraw&) = delete;
};
