/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Base64 implementation.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"

int Base64_Encode(const void* source, int slen, void* dest, int dlen);
int Base64_Decode(const void* source, int slen, void* dest, int dlen);
