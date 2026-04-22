/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Secure Hash pipe.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "pipe.h"
#include "sha.h"


class SHAPipe : public Pipe
{
public:
    SHAPipe();
    ~SHAPipe();

    virtual int Put(const void* source, int slen) override;

    int Result(void* result) const;

protected:
    SHAEngine SHA;

private:
    SHAPipe(const SHAPipe&) = delete;
    SHAPipe& operator=(const SHAPipe&) = delete;
};
