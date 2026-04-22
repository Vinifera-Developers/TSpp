/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  LZO real-time data compression library.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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
