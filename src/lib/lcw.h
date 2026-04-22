/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Westwood Studios proprietary compression. "Lempel�Castle�Welch", a
 *          variation on the LZW compression called "Lempel�Ziv�Welch", with
 *          "Castle" referring to its programmer Louis "Castle".
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


int LCW_Compress(void const* source, void* dest, int length);

/**
 *  #NOTE:
 *  The 3rd argument is dummy and it exists to provide backward compatibility.
 */
int LCW_Uncompress(void const* source, void* dest, unsigned long length = 0);
