/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  An arbitrary precision integer class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "int.h"


int BigInt::Error = 0;
bool BigInt::Carry = false;
bool BigInt::Borrow = false;
BigInt BigInt::Remainder = BigInt();
