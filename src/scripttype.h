/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SCRIPTTYPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for script types.
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
#include "tibsun_defines.h"


class ScriptMissionClass
{
public:
    ScriptMissionClass() : Mission(SMISSION_NONE), Data() {}
    ~ScriptMissionClass() {}

    static const char *Mission_Name(ScriptMissionType mission);
    static const char *Mission_Description(ScriptMissionType mission);

public:
    ScriptMissionType Mission;  // Mission type.
    union {
        xCell Cell;
        QuarryType Quarry;      // Combat quarry type.
        MissionType Mission;    // General mission orders.
        int Value;              // Usually a waypoint number.
    } Data;

private:
    struct MissionDescriptionStruct
    {
        char const *Name;
        char const *Description;
    };

    static MissionDescriptionStruct MissionDescriptions[SMISSION_COUNT];
};


class DECLSPEC_UUID("42F3A647-0789-11D2-ACA5-006008055BB5")
ScriptTypeClass : public AbstractTypeClass
{
    public:
        enum ScriptTypeClassEnums {
            MAX_SCRIPT_MISSIONS = 50
        };

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
        ScriptTypeClass(const char *ini_name = nullptr);
        ScriptTypeClass(const NoInitClass &noinit);
        virtual ~ScriptTypeClass();

        /**
         *  AbstractClass
         */
        virtual RTTIType Fetch_RTTI() const override;
        virtual int Get_Object_Size(bool firestorm = false) const override;
        virtual void Object_CRC(CRCEngine &crc) const override;
        virtual int Fetch_Heap_ID() const override;

        /**
         *  AbstractTypeClass
         */
        virtual bool Read_INI(CCINIClass &ini) override;
        virtual bool Write_INI(CCINIClass &ini) const override;

        static void Read_Scenario_INI(CCINIClass &ini, bool a2 = false);
        static void Write_Scenario_INI(CCINIClass &ini, bool a2 = false);

        static ScriptType From_Name(const char *name);
        static const char *Name_From(ScriptType type);
        static const ScriptTypeClass *Find_Or_Make(const char *name);

    public:
        ScriptType HeapID;
        int field_64;
        int MissionCount;
        ScriptMissionClass MissionList[MAX_SCRIPT_MISSIONS];
};
