/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          BASE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Pre-built base nodes for AI houses.
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

#include "tibsun_defines.h"
#include "vector.h"
#include <unknwn.h>


class NoInitClass;
class CRCEngine;
class CCINIClass;
class BuildingClass;


class BaseNodeClass
{
public:
    BaseNodeClass() : Type(STRUCT_NONE), CellID(-1, -1) {}
    BaseNodeClass(StructType building, Cell cell) : Type(building), CellID(cell) {}
    bool operator==(const BaseNodeClass& node) const { return Type == node.Type && CellID == node.CellID; }
    bool operator!=(const BaseNodeClass& node) const { return Type != node.Type && CellID != node.CellID; }
    bool operator>(const BaseNodeClass& node) const { return true; }

    StructType Type;
    Cell CellID;
};


/****************************************************************************
** This is the class that defines a pre-built base for the computer AI.
** (Despite its name, this is NOT the "base" class for C&C's class hierarchy!)
*/
class BaseClass
{
public:
    /**
     *  IPersistStream
     */
    IFACEMETHOD(Load)(IStream* pStm);
    IFACEMETHOD(Save)(IStream* pStm, BOOL fClearDirty);

    virtual void Object_CRC(CRCEngine& crc) const;

public:
    BaseClass();
    BaseClass(const NoInitClass& x);
    ~BaseClass();

    void Init()
    {
        House = HOUSE_NONE;
        Nodes.Clear();
    }

    bool Is_Built(int index) const;
    BuildingClass* Get_Building(int index) const;
    bool Is_Node(const BuildingClass* obj);
    BaseNodeClass* Get_Node(const BuildingClass* obj);
    BaseNodeClass* Get_Node(Cell& cell);
    BaseNodeClass* Next_Buildable(StructType type = STRUCT_NONE);
    int Next_Buildable_Index(StructType type = STRUCT_NONE);

    void Read_INI(CCINIClass& ini, const char* section);
    void Write_INI(const CCINIClass& ini, const char* section);

public:
    DynamicVectorClass<BaseNodeClass> Nodes;
    int PercentBuilt;
    DynamicVectorClass<Cell> field_20;
    DynamicVectorClass<Cell> field_38;
    Cell field_50;
    Rect field_54;
    int field_64;
    int field_68;
    int field_6C;
    int field_70;
    HousesType House;
};
