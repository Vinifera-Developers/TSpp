/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SPECIAL.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Special game options.
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


class CCINIClass;


class SpecialClass
{
public:
    void Init();

    void Read_INI(CCINIClass& ini);
    void Write_INI(CCINIClass& ini) const;

public:
    unsigned IsShadowGrow : 1;     // 1
    unsigned IsSpeedBuild : 1;     // 2
    unsigned IsFromInstall : 1;    // 4
    unsigned IsCaptureTheFlag : 1; // 8
    unsigned IsInert : 1;          // 16
    unsigned IsTGrowth : 1;        // 32
    unsigned IsTSpread : 1;        // 64
    unsigned IsMCVDeploy : 1;      // 128

    unsigned IsInitialVeteran : 1;     // 1
    unsigned IsFixedAlliance : 1;      // 2
    unsigned IsHarvesterImmune : 1;    // 4
    unsigned IsFogOfWar : 1;           // 8
    unsigned Bit2_16 : 1;              // 16   // could be ShroudRegrows?
    unsigned IsTExplosive : 1;         // 32
    unsigned IsDestroyableBridges : 1; // 64
    unsigned IsMeteorites : 1;         // 128

    unsigned IsIonStorms : 1;  // 1
    unsigned IsVisceroids : 1; // 2
};
