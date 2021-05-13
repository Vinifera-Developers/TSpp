/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SCENARIO.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Current scenario/mission info.
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

#include <always.h>
#include "tibsun_defines.h"
#include "random.h"
#include "ttimer.h"
#include "ftimer.h"
#include "typelist.h"
#include "special.h"


class CellClass;
class TechnoTypeClass;


class ScenarioClass
{
    public:
        ScenarioClass();
        ~ScenarioClass();

        Cell Get_Waypoint_Location(int wp) const;
        CellClass *Get_Waypoint_Cell(int wp) const;
        Coordinate *Get_Waypoint_Coord(int wp) const;
        bool Is_Valid_Waypoint(int wp) const;

    public:
        SpecialClass SpecialFlags;
        char NextScenario[PATH_MAX];
        char AltNextScenario[PATH_MAX];
        Cell HomeCell;
        Cell AltHomeCell;
        int UniqueID;
        Random2Class RandomNumber;
        DiffType Difficulty;			        // For human player.
        DiffType CDifficulty;		            // For computer players.
        TTimerClass<FrameTimerClass> ElapsedTimer;
        Cell Waypoint[WAYPT_COUNT];
        CDTimerClass<FrameTimerClass> MissionTimer;
        CDTimerClass<FrameTimerClass> ShroudTimer;
        CDTimerClass<FrameTimerClass> FogTimer;
        CDTimerClass<FrameTimerClass> IceTimer;
        CDTimerClass<FrameTimerClass> field_7E0;
        CDTimerClass<FrameTimerClass> AmbientChangeTimer;
        int Scenario;
        TheaterType Theater;
        char ScenarioName[PATH_MAX];
        char Description[DESCRIP_MAX];
        VQType IntroMovie;
        VQType BriefMovie;
        VQType WinMovie;
        VQType LoseMovie;
        VQType ActionMovie;
        VQType PostScoreMovie;
        VQType PreMapSelectMovie;
        char BriefingText[1024];
        ThemeType TransitTheme;
        HousesType PlayerHouse;
        double CarryOverPercent;
        int CarryOverCap;
        int Percent;
        VariableFlagStruct GlobalFlags[50];
        VariableFlagStruct LocalFlags[50];
        Cell Views[VIEW_COUNT];
        int BridgeCount;
        bool IsFreeRadar;
        bool IsTrainCrate;
        bool IsTiberiumGrowth;
        bool IsVeinGrowth;
        bool IsIceGrowth;
        bool IsBridgeChanged;
        bool IsFlagChanged;
        bool IsAmbientChanged;
        bool IsEndOfGame;
        bool IsInheritTimer;
        bool IsSkipScore;
        bool IsOneTimeOnly;
        bool IsNoMapSel;
        bool IsTruckCrate;
        bool IsMoneyTiberium;
        bool IsTiberiumDeathToVisceroid;
        bool IsIgnoreGlobalAITriggers;
        bool field_1D91;                    // Is GDI or NOD?
        bool IsMultiplayerOnly;
        bool IsRandom;
        bool CratePickedUp;
        CDTimerClass<FrameTimerClass> FadeTimer;
        CampaignType CampaignID;
        int StartingDropships;
        TypeList<TechnoTypeClass *> AllowableUnits;
        TypeList<int> AllowableUnitMaximums;
        TypeList<int> DropshipUnitCounts;
        int AmbientOriginal;
        int AmbientCurrent;
        int AmbientTarget;
        int Red;
        int Green;
        int Blue;
        int Ground;
        int Level;
        int IonAmbient;
        int IonRed;
        int IonGreen;
        int IonBlue;
        int IonGround;
        int IonLevel;
        bool field_1E38;                    // Currently reading scenario ini?
        int InitTime;
        AddonType RequiredAddOn;
        int SpeechSide;
        unsigned short Stage;
        bool UserInputLocked;
};
