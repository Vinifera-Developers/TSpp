/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          LCW.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Westwood Studios proprietary compression.
 *                 "Lempel–Castle–Welch", a variation on the LZW compression
 *                 called "Lempel–Ziv–Welch", with "Castle" referring to its
 *                 programmer Louis "Castle".
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


int LCW_Compress(void const * source, void * dest, int length);

/**
 *  #NOTE:
 *  The 3rd argument is dummy and it exists to provide backward compatibility.
 */
int LCW_Uncompress(void const * source, void * dest, unsigned long length = 0);
