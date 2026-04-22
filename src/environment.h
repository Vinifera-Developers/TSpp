/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Carryover values to the next mission.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "tibsun_defines.h"


struct IStream;


class EnvironmentClass
{
public:
    EnvironmentClass();
    ~EnvironmentClass();

    void Snapshot_Game_State();
    void Apply_To_Game_State();

    void Load(IStream* pStm);
    void Save(IStream* pStm);

public:
    bool Globals[50];
    int CarryOverMoney;
    int MissionTimer;
    int Difficulty;
    unsigned short Stage;
};
