/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          LZO.H
 *
 *  @author        Markus Franz Xaver Johannes Oberhumer (see notes below)
 *
 *  @contributors  CCHyper
 *
 *  @brief         LZO real-time data compression library.
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
 *  @note          This file is part of the LZO real-time data compression library.
 *                 Copyright (C) 1996-2017 Markus Franz Xaver Johannes Oberhumer.
 *                 All Rights Reserved.
 *
 *                 Markus F.X.J. Oberhumer <markus@oberhumer.com>
 *
 *                 The full LZO package can be found at
 *                 http://www.oberhumer.com/opensource/lzo/
 *
 ******************************************************************************/
#pragma once

#include "always.h"


#ifdef __cplusplus
extern "C" {
#endif

typedef void* lzo_voidp;
typedef unsigned char* lzo_bytep;
typedef unsigned long lzo_uint;
typedef lzo_uint* lzo_uintp;

int lzo1x_1_compress(const lzo_bytep src, lzo_uint src_len, lzo_bytep dst, lzo_uintp dst_len, lzo_voidp wrkmem);

int lzo1x_decompress(const lzo_bytep src, lzo_uint src_len, lzo_bytep dst, lzo_uintp dst_len, lzo_voidp wrkmem);

#ifdef __cplusplus
} /* extern "C" */
#endif
