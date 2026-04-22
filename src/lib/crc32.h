/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Standard CRC32 routines.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


uint32_t CRC32_Memory(const void* data, uint32_t bytes, uint32_t prev_crc = 0);
uint32_t CRC32_String(const char* string, uint32_t prev_crc = 0);
