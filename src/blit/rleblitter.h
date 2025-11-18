/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          RLEBLITTER.H
 *
 *  @authors       CCHyper
 *
 *  @brief         RLE Blitter base class.
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


class RLEBlitter
{
public:
    RLEBlitter() {}
    virtual ~RLEBlitter() {}

    virtual void Blit(void* dest, void const* source, int length, int leadskip = 0, int z_min = 0, int z_buff = NULL, int a_buff = NULL, int alpha_level = 0, int warp_offset = 0, int zshape = NULL) const = 0;
};
