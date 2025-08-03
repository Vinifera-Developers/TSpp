/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          MULTIMISS.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Multiplayer mission definition class.
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
