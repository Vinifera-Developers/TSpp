/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Special game options.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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
