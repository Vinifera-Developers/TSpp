/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Game world utility functions.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "tibsun_defines.h"
#include "wwkeyboard.h"


Cell Get_Cell_Under_Mouse();
Coord Get_Coord_Under_Mouse();

bool Simple_YesNo_WWMessageBox(const char* msg);

FacingType KN_To_Facing(KeyNumType input);
