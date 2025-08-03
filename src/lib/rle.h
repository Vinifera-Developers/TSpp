/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          RLE.H
 *
 *  @authors       tomsons26
 *
 *  @brief         Run-length encoding (RLE) implementation.
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

#include "always.h"
#include "buff.h"


class RLEClass
{
public:
    RLEClass() {}

    int Compress(void* source, void* dest, int length);
    int Uncompress(void* source, void* dest);
};


inline int RLE_Compress(const Buffer& inbuff, const Buffer& outbuff)
{
    RLEClass rle;
    return rle.Compress(inbuff, outbuff, inbuff.Get_Size());
}


inline int RLE_Uncompress(const Buffer& inbuff, const Buffer& outbuff)
{
    RLEClass rle;
    return rle.Uncompress(inbuff, outbuff);
}
