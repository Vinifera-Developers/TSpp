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
#include "stimer.h"
#include "typelist.h"
#include "special.h"


class CCINIClass;
class CellClass;
class TechnoTypeClass;


class ScenarioClass
{
public:
    ScenarioClass();
    ~ScenarioClass();

    void Save(LPSTREAM pStm);
    void Load(LPSTREAM pStm);

    bool Read_INI(CCINIClass &ini);
    bool Write_INI(CCINIClass &ini);
    
    bool Read_Global_INI(CCINIClass &ini);
    bool Read_Local_INI(CCINIClass &ini);
    bool Write_Local_INI(CCINIClass &ini);

    Cell Waypoint_Cell(int wp) const;
    CellClass *Waypoint_CellClass(int wp) const;
    Coord Waypoint_Coord(int wp) const;
    bool Is_Waypoint_Valid(int wp) const;

    void Read_Waypoint_INI(CCINIClass& ini);
    void Write_Waypoint_INI(CCINIClass& ini);

public:
    SpecialClass Special;
    char NextScenarioName[PATH_MAX];
    char AltNextScenarioName[PATH_MAX];
    int Home;                               // These are waypoint indices, not Cell coordinates
    int AltHome;
    int UniqueID;
    Random2Class RandomNumber;
    DiffType Difficulty;                    // For human player.
    DiffType CDifficulty;                   // For computer players.
    TTimerClass<SystemTimerClass> ElapsedTimer;
    Cell Waypoint[WAYPT_COUNT];
    CDTimerClass<FrameTimerClass> MissionTimer;
    CDTimerClass<FrameTimerClass> ShroudTimer;
    CDTimerClass<FrameTimerClass> FogTimer;
    CDTimerClass<FrameTimerClass> IceGrowthTimer;
    CDTimerClass<FrameTimerClass> VeinGrowthTimer;
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
    bool IsTibGrowth;
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
    bool IsGDI;
    bool IsMultiplayerOnly;
    bool IsRandom;
    bool IsCratePickup;
    CDTimerClass<FrameTimerClass> FadeTimer;
    CampaignType Campaign;
    int StartingDropships;
    TypeList<TechnoTypeClass *> AllowableUnits;
    TypeList<int> AllowableUnitMaximums;
    TypeList<int> AllowableUnitUsage;
    int AmbientLight;
    int CurrentAmbientLight;
    int DesiredAmbientLight;
    int RedTint;
    int GreenTint;
    int BlueTint;
    int GroundLight;
    int LevelLight;
    int IonAmbientLight;
    int IonRedTint;
    int IonGreenTint;
    int IonBlueTint;
    int IonGroundLight;
    int IonLevelLight;
    bool field_1E38;                    // Currently reading scenario ini?
    int InitTime;
    AddonType RequiredAddOn;
    SideType SpeechSide;
    unsigned short Stage;
    bool InputLock;
};


bool Start_Scenario(char *name, bool briefing, CampaignType campaign = CAMPAIGN_NONE);
bool Read_Scenario(char *name);
void Clear_Scenario();
void Do_Win();
void Do_Lose();
void Do_Restart();
void Do_Abort();
void Assign_Houses();
void Pause_Scenario_Timer();
void Resume_Scenario_Timer();

// This really belongs in MainOptionsClass.
bool Change_Video_Mode(int height, int width);
