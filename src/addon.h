/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Expansion pack / addon utility functions.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "tibsun_defines.h"

extern int& InstalledMode;
extern int& EnabledMode;

bool Detect_Addons();
bool Addon_Installed(AddonType addon);
bool Addon_Enabled(AddonType addon);
void Enable_Addon(AddonType addon);
void Disable_Addon(AddonType addon);
bool Is_Required_Addon(AddonType addon);
AddonType Get_Required_Addon();
void Set_Required_Addon(AddonType addon);
