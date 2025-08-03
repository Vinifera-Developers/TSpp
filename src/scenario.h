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

#include "always.h"
#include "ftimer.h"
#include "random.h"
#include "special.h"
#include "stimer.h"
#include "tibsun_defines.h"
#include "ttimer.h"
#include "typelist.h"


class INIClass;
class CCINIClass;
class CellClass;
class TechnoTypeClass;
class CRCEngine;


class ScenarioClass
{
public:
    ScenarioClass();
    ScenarioClass(NoInitClass const& x);

    void Reset();

    void Set_Scenario_Name(char const* name);

    bool Read_INI(CCINIClass& ini);
    bool Write_INI(CCINIClass& ini);

    bool Read_Global_INI(INIClass& ini);
    bool Read_Local_INI(INIClass& ini);
    bool Write_Local_INI(INIClass& ini);

    bool Set_Global_To(int global, bool value);
    bool Set_Global_To(char const* name, bool value);
    bool Get_Global_Value(int global, bool& value);
    bool Get_Global_Value(char const* name, bool& value);
    bool Set_Local_To(int local, bool value);
    bool Set_Local_To(char const* name, bool value);
    bool Get_Local_Value(int local, bool& value);
    bool Get_Local_Value(char const* name, bool& value);

    int Find_Global_Variable_Index(char const* name);
    int Find_Local_Variable_Index(char const* name);

    int Find_Free_Local() const;
    int Num_Locals() const;

    int Unique_ID();

    Cell Waypoint_Cell(WAYPOINT wp) const;
    AbstractClass* Waypoint_Target(WAYPOINT wp) const;
    CellClass* Waypoint_CellClass(WAYPOINT wp) const;
    Coord Waypoint_Coord(WAYPOINT wp) const;
    void Clear_Waypoint(WAYPOINT wp);
    void Clear_All_Waypoints();
    bool Is_Waypoint_Valid(WAYPOINT wp) const;
    char const* Unused_Waypoint() const;
    void Set_Waypoint(WAYPOINT wp, Cell cell);

    void Read_Waypoints(CCINIClass& ini);
    void Write_Waypoints(CCINIClass& ini);

    void Object_CRC(CRCEngine&) const;

    void Save_Self(LPSTREAM stream);
    void Load_Self(LPSTREAM stream);

public:
    SpecialClass Special;
    char NextScenarioName[PATH_MAX];
    char AltNextScenarioName[PATH_MAX];
    int Home; // These are waypoint indices, not Cell coordinates
    int AltHome;
    int UniqueID;
    Random2Class RandomNumber;
    DiffType Difficulty;  // For human player.
    DiffType CDifficulty; // For computer players.
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
    bool IsGlobalChanged;
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
    TypeList<TechnoTypeClass*> AllowableUnits;
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
    bool field_1E38; // Currently reading scenario ini?
    int InitTime;
    AddonType RequiredAddOn;
    SideType SpeechSide;
    unsigned short Stage;
    bool InputLock;
};


bool Start_Scenario(char* name, bool briefing, CampaignType campaign = CAMPAIGN_NONE);
bool Read_Scenario(char* name);
void Clear_Scenario();
void Do_Win();
void Do_Lose();
void Do_Restart();
void Do_Abort();
void Assign_Houses();
void Pause_Scenario();
void Resume_Scenario();
bool Read_Scenario_INI(const char* fname, bool fresh = true);
bool Read_Scenario_INI(CCINIClass& ini, bool random = false);
void Last_Minute_Multiplayer_Fixups(bool official);
void Write_Scenario_INI(const char* root, bool a2 = false);

// This really belongs in MainOptionsClass.
bool Change_Video_Mode(int height, int width);
