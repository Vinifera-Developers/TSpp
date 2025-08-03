/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SCRIPT.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Script mission value container.
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

#include "abstract.h"
#include "tibsun_defines.h"


class ScriptTypeClass;
class ScriptMissionClass;


class DECLSPEC_UUID("42F3A646-0789-11D2-ACA5-006008055BB5")
ScriptClass : public AbstractClass
{
public:
    /**
     *  IPersist
     */
    IFACEMETHOD(GetClassID)(CLSID* pClassID);

    /**
     *  IPersistStream
     */
    IFACEMETHOD(Load)(IStream* pStm);
    IFACEMETHOD(Save)(IStream* pStm, BOOL fClearDirty);

public:
    ScriptClass(ScriptTypeClass* classof);
    ScriptClass(const NoInitClass& noinit);
    virtual ~ScriptClass();

    /**
     *  AbstractClass
     */
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;

    ScriptMissionClass Get_Current_Mission();
    ScriptMissionClass Get_Next_Mission();
    bool Stop_Script();
    bool Set_Line(int line);
    bool Next_Mission();
    bool Has_Missions_Remaining() const;

    const char* Name() const;

public:
    ScriptTypeClass* Class;
    int field_18;
    int CurrentMission;
};
