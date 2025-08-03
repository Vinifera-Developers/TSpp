/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TUBE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Tunnel path container.
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
#include "always.h"
#include "tibsun_defines.h"


class NoInitClass;
class CCINIClass;


class DECLSPEC_UUID("0B4CA41C-B3A7-11D1-B457-006097C6A979")
TubeClass : public AbstractClass
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
    TubeClass(Cell& enter, FacingType enter_dir);
    TubeClass(const NoInitClass& noinit);
    virtual ~TubeClass();

    /**
     *  AbstractClass
     */
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;

    void Add_Direction(FacingType dir);
    bool Is_Next_Cell(Cell& cell);

    const char* Name() const;

    static void Assign_Tubes();

    static void Read_Scenario_INI(CCINIClass& ini);
    static void Write_Scenario_INI(CCINIClass& ini);

public:
    Cell Enter;
    Cell Exit;
    FacingType EnterDir;
    FacingType TubeDir[100];
    int DirCount;
};
