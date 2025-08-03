/*******************************************************************************
/*               O P E N  S O U R C E -- P R O J E C T T S Y R                **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          BLITTER_MISC.H
 *
 *  @author        tomsons26
 *
 *  @contributors  CHyper
 *
 *  @brief         Miscellaneous utility blit functions.
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


void __cdecl Brighten_555(unsigned char* add_buffer, unsigned short* buffer, int addbuff_width, int buff_width, int width, int height);
void __cdecl Brighten_556(unsigned char* add_buffer, unsigned short* buffer, int addbuff_width, int buff_width, int width, int height);
void __cdecl Brighten_565(unsigned char* add_buffer, unsigned short* buffer, int addbuff_width, int buff_width, int width, int height);
void __cdecl Brighten_655(unsigned char* add_buffer, unsigned short* buffer, int addbuff_width, int buff_width, int width, int height);
