/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          HOUSETYPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for house types.
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


class DECLSPEC_UUID("1DD43928-046B-11D2-ACA4-006008055BB5")
HouseTypeClass : public AbstractTypeClass
{
public:
    /**
     *  IUnknown
     */
    IFACEMETHOD(QueryInterface)(REFIID riid, LPVOID* ppvObj);
    IFACEMETHOD_(ULONG, AddRef)();
    IFACEMETHOD_(ULONG, Release)();

public:
    /**
     *  IPersist
     */
    IFACEMETHOD(GetClassID)(CLSID* pClassID);

    /**
     *  IPersistStream
     */
    IFACEMETHOD_(LONG, IsDirty)();
    IFACEMETHOD(Load)(IStream* pStm);
    IFACEMETHOD(Save)(IStream* pStm, BOOL fClearDirty);
    IFACEMETHOD_(LONG, GetSizeMax)(ULARGE_INTEGER* pcbSize);

public:
    HouseTypeClass(const char* ini_name = nullptr);
    HouseTypeClass(const NoInitClass& noinit);
    virtual ~HouseTypeClass();

    /**
     *  AbstractClass
     */
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;
    virtual int Fetch_Heap_ID() const override;

    /**
     *  AbstractTypeClass
     */
    virtual bool Read_INI(CCINIClass& ini) override;

    static HousesType From_Name(const char* name);
    static const char* Name_From(HousesType type);
    static const HouseTypeClass* Find_Or_Make(const char* name);

public:
    HousesType HeapID;
    HousesType House;
    SideType Side;
    ColorSchemeType RemapColor;
    double FirepowerBias;
    double GroundspeedBias;
    double AirspeedBias;
    double ArmorBias;
    double ROFBias;
    double CostBias;
    double BuildSpeedBias;
    char Suffix[4];
    char Prefix;
    bool IsMultiplay;
    bool IsMultiplayPassive;
    bool IsWallOwner;
    bool IsSmartAI;
};
