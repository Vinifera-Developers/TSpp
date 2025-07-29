/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          ENVIRONMENT.H
 *
 *  @author        CCHyper
 *
 *  @brief         Carryover values to the next mission.
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


struct IStream;


class EnvironmentClass
{
    public:
        EnvironmentClass();
        ~EnvironmentClass();

        void Snapshot_Game_State();
        void Apply_To_Game_State();

        void Load(IStream *pStm);
        void Save(IStream *pStm);

    public:
        bool Globals[50];
        int CarryOverMoney;
        int MissionTimer;
        int Difficulty;
        unsigned short Stage;
};
