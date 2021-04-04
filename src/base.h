#pragma once

#include "vector.h"
#include "tibsun_defines.h"
#include <unknwn.h>


class NoInitClass;
class WWCRCEngine;
class CCINIClass;
class BuildingClass;


class BaseNodeClass
{
	public:
		BaseNodeClass() : Type(BUILDING_NONE), Cell(-1, -1) {}
		BaseNodeClass(BuildingType building, CellStruct cell) : Type(building), Cell(cell) {}
		bool operator == (const BaseNodeClass & node) const { return Type == node.Type && Cell == node.Cell; }
		bool operator != (const BaseNodeClass & node) const { return Type != node.Type && Cell != node.Cell; }
		bool operator > (const BaseNodeClass & node) const { return true; }

		BuildingType Type;
		CellStruct Cell;
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
        IFACEMETHOD(Load)(IStream *pStm);
        IFACEMETHOD(Save)(IStream *pStm, BOOL fClearDirty);
		
        virtual void Compute_CRC(WWCRCEngine &crc) const;

	public:
		BaseClass();
		BaseClass(const NoInitClass &x);
		~BaseClass();

		void Init() { House = HOUSE_NONE; Nodes.Clear(); }

		bool Is_Built(int index) const;
		BuildingClass * Get_Building(int index) const;
		bool Is_Node(const BuildingClass * obj);
		BaseNodeClass * Get_Node(const BuildingClass * obj);
		BaseNodeClass * Get_Node(CellStruct &cell);
		BaseNodeClass * Next_Buildable(BuildingType type = BUILDING_NONE);
		int Next_Buildable_Index(BuildingType type = BUILDING_NONE);

		void Read_INI(CCINIClass &ini, const char *section);
		void Write_INI(const CCINIClass &ini, const char *section);

	public:
		DynamicVectorClass<BaseNodeClass> Nodes;
		int PercentBuilt;
		DynamicVectorClass<CellStruct> field_20;
		DynamicVectorClass<CellStruct> field_38;
		int field_50;
		Rect field_54;
		int field_64;
		int field_68;
		int field_6C;
		int field_70;
		HousesType House;
};
