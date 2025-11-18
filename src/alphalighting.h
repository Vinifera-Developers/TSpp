/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          ALPHALIGHTING.H
 *
 *  @authors       tomsons26
 *
 *  @brief         A class used by blitters for alpha lighting remapping.
 *
 *  @license       TS++ is free software: you can redistribute it and/or
 *                 modify it under the terms of the GNU General Public License
 *                 as published by the Free Software Foundation, either version
 *                 3 of the License, or (at your option) any later version.
 *
 *                 TS++ is distributed in the hope that it will be
 *                 useful, but WITHOUT ANY WARRANTY; without even the implied
 *                 warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *                 PURPOSE. See the GNU General Public License for more details.
 *
 *                 You should have received a copy of the GNU General Public
 *                 License along with this program.
 *                 If not, see <http://www.gnu.org/licenses/>.
 *
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
