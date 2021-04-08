/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          BLITTER.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Base class for the templated blitters.
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


class Blitter
{
    public:
        Blitter() {}
        virtual ~Blitter() {}

        virtual void entry_4(void *dest, void *source, unsigned length, unsigned short z_min = 0x8000, int *z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) = 0;
        virtual void entry_8(void *dest, void *source, unsigned length, unsigned short z_min = 0x8000, int *z_buff = nullptr, int *alpha_buff = nullptr, int alpha_level = 1000) = 0;
};
