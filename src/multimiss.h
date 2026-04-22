/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Multiplayer mission definition class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "tibsun_defines.h"
#include "typelist.h"


class INIClass;


class MultiMission
{
public:
    MultiMission(INIClass& ini, const char* filename);
    MultiMission(const char* filename = nullptr, const char* description = nullptr, const char* digest = nullptr, bool official = true);
    ~MultiMission();

    bool Is_Available(DiskID disk);
    DiskID Get_Disk() const;

    void Set_Description(const char* description);
    void Set_Filename(const char* filename);
    void Set_Digest(const char* digest);
    void Set_Official(bool official);

public:
    char ScenarioDescription[DESCRIP_MAX];
    char Filename[NAME_MAX];
    char Digest[32];
    bool IsOfficial;
    int MinPlayers;
    int MaxPlayers;
    TypeList<DiskID> Disks;
};
