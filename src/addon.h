/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          ADDON.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Expansion pack / addon utility functions.
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
 ******************************************************************************/
#pragma once

#include "always.h"
#include "tibsun_defines.h"

extern int &InstalledMode;
extern int &EnabledMode;

bool Addon_Present();
bool Addon_Installed(AddonType addon);
bool Addon_Enabled(AddonType addon);
void Addon_407190(AddonType addon);
void Addon_4071C0(AddonType addon);
bool Is_Addon_Set(AddonType addon);
AddonType Get_Required_Addon();
void Set_Required_Addon(AddonType addon);
