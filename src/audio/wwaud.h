/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Westwoo AUD format header.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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
