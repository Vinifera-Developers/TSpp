/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  A class used by blitters for alpha lighting remapping.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include <algorithm>

#include "vector.h"

class AlphaLightingRemapClass;

class AlphaLightingRemapInitClass
{
public:
    AlphaLightingRemapInitClass();
    ~AlphaLightingRemapInitClass();
    AlphaLightingRemapClass* Init(int count);
    void Deinit(AlphaLightingRemapClass* ptr);
};

class AlphaLightingRemapClass
{
public:
    AlphaLightingRemapClass(int count);
    ~AlphaLightingRemapClass();

    unsigned short* Get_Table(int level)
    {
        int v10 = level > 0 ? level : 0;
        v10 = (261 * v10) >> 11;
        v10 = std::min(v10, 254);
        return Buffer[v10];
    }

    enum {
        BUFFER_SIZE = 256 * 256,
    };

    unsigned short Buffer[256][256];
    int Count;
    int RefCount;

    static DynamicVectorClass<AlphaLightingRemapClass*>& AlphaLightingRemaps;
};

extern AlphaLightingRemapInitClass & AlphaLightingRemapInit;
