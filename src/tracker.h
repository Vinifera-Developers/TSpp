/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Detach target from all known trackers/heaps.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "tibsun_defines.h"


/**
 *	Remove from targeting computers.
 */
void Detach_This_From_All(AbstractClass* target, bool all = true);

void Delete_Marked();
