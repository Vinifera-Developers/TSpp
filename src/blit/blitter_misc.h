/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Miscellaneous utility blit functions.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


void __cdecl Brighten_555(unsigned char* add_buffer, unsigned short* buffer, int addbuff_width, int buff_width, int width, int height);
void __cdecl Brighten_556(unsigned char* add_buffer, unsigned short* buffer, int addbuff_width, int buff_width, int width, int height);
void __cdecl Brighten_565(unsigned char* add_buffer, unsigned short* buffer, int addbuff_width, int buff_width, int width, int height);
void __cdecl Brighten_655(unsigned char* add_buffer, unsigned short* buffer, int addbuff_width, int buff_width, int width, int height);
