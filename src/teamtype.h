/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TEAMTYPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for team types.
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

#include "abstracttype.h"
#include "typelist.h"
#include "tibsun_defines.h"


class TeamClass;
class HouseClass;
class TagTypeClass;
class ScriptTypeClass;
class TaskForceClass;


class DECLSPEC_UUID("D1DBA64E-0778-11D2-ACA5-006008055BB5")
TeamTypeClass : public AbstractTypeClass
{
public:
    /**
     *  IPersist
     */
    IFACEMETHOD(GetClassID)(CLSID *pClassID);

    /**
     *  IPersistStream
     */
    IFACEMETHOD(Load)(IStream *pStm);
    IFACEMETHOD(Save)(IStream *pStm, BOOL fClearDirty);

public:
    TeamTypeClass(const char *ini_name = nullptr);
    TeamTypeClass(const NoInitClass &noinit);
    virtual ~TeamTypeClass();

    /**
     *  AbstractClass
     */
    virtual void Detach(AbstractClass * target, bool all = true) override;
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual void Object_CRC(CRCEngine &crc) const override;
    virtual int Fetch_Heap_ID() const override;

    /**
     *  AbstractTypeClass
     */
    virtual bool Read_INI(CCINIClass &ini) override;
    virtual bool Write_INI(CCINIClass &ini) const override;

    TeamClass *Create_One_Of(HouseClass *house) const;
    void Destroy_All_Of() const;
    static TypeList<const TeamTypeClass *> Suggested_New_Team(HouseClass *house, bool alerted);
    // 00628BE0
    Cell Get_Origin() const;
    // 006290F0
    // 006291E0
    // 00629220

    static void Read_Scenario_INI(CCINIClass &ini, int a2);
    static void Write_Scenario_INI(CCINIClass &ini, int a2);

    static const TeamTypeClass &As_Reference(TeamType type);
    static const TeamTypeClass *As_Pointer(TeamType type);
    static const TeamTypeClass &As_Reference(const char *name);
    static const TeamTypeClass *As_Pointer(const char *name);
    static TeamType From_Name(const char *name);
    static const char *Name_From(TeamType type);
    static const TeamTypeClass *Find_Or_Make(const char *name);

public:
    TeamType ID;
    int Group;
    int VeteranLevel;
    bool IsLoadable;
    bool IsFull;
    bool IsAnnoyance;
    bool IsGuardSlower;
    bool IsRecruiter;
    bool IsAutocreate;
    bool IsPrebuilt;
    bool IsReinforcable;
    bool IsWhiner;
    bool IsAggressive;
    bool IsLooseRecruit;
    bool IsSuicide;
    bool IsDroppod;
    bool IsDropship;
    bool OnTransOnly;
    int RecruitPriority;
    int MaxAllowed;
    int Fear;
    HouseClass *House;
    int TechLevel;
    TagTypeClass *Tag;
    int Origin;
    int Number;
    ScriptTypeClass *Script;
    TaskForceClass *TaskForce;
    int field_A4;
    bool AvoidThreats;
    bool IsIonImmune;
    bool TransportsReturnOnUnload;
    bool AreTeamMembersRecruitable;
    bool IsBaseDefense;
    bool OnlyTargetHouseEnemy;
};
