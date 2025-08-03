/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WWAUD.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Westwoo AUD format header.
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


#define AUD_CHUNK_MAGIC_ID 0xDEAF

#define AUD_FLAG_STEREO 1
#define AUD_FLAG_16BIT  2

#pragma pack(push, 1)
typedef struct AUDHeaderType {
    unsigned short Rate;       // Playback rate (hertz).
    int Size;                  // Size of data (bytes).
    int UncompSize;            // Size of data (bytes).
    unsigned char Flags;       // Holds flags for info
                               //  1: Is the sample stereo?
                               //  2: Is the sample 16 bits?
    unsigned char Compression; // What kind of compression for this sample?
} AUDHeaderType;
#pragma pack(pop)
