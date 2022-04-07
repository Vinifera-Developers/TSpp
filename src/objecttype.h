/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          OBJECTTYPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class which all game object types derive from.
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
#include "search.h"


class ObjectClass;
class BuildingClass;
class VoxelLibClass;
class MotLibClass;


class ObjectTypeClass : public AbstractTypeClass
{
    public:
        /**
         *  IPersistStream
         */
        IFACEMETHOD(Load)(IStream *pStm);
        IFACEMETHOD(Save)(IStream *pStm, BOOL fClearDirty);
        IFACEMETHOD_(LONG, GetSizeMax)(ULARGE_INTEGER *pcbSize);

    public:
        ObjectTypeClass(const char *ini_name = nullptr);
        ObjectTypeClass(const NoInitClass &noinit);
        virtual ~ObjectTypeClass();

        /**
         *  AbstractTypeClass
         */
        virtual bool Read_INI(CCINIClass &ini) override;

        /**
         *  ObjectTypeClass
         */
        virtual Coordinate Coord_Fixup(Coordinate *coord) const;
        virtual int Get_Ownable() const;
        virtual int Max_Pips() const;
        virtual Point3D Pixel_Dimensions() const;
        virtual Point3D Lepton_Dimensions() const;
        virtual bool Create_And_Place(Cell &cell, HouseClass *house = nullptr) const = 0;
        virtual int Cost_Of(HouseClass *house = nullptr) const;
        virtual int Time_To_Build() const;
        virtual ObjectClass *const Create_One_Of(HouseClass *house = nullptr) const = 0;
        virtual Cell *Occupy_List(bool placement = false) const;
        virtual BuildingClass *const Who_Can_Build_Me(bool in_theory = false, bool a2 = false, bool legal = false, HouseClass *house = nullptr) const;
        virtual ShapeFileStruct *const Get_Cameo_Data() const;
        virtual ShapeFileStruct *const Get_Image_Data() const;

		const char * Graphic_Name() const
		{
			if (GraphicName[0] != '\0') {
				return GraphicName;
			}
			return Name();
		}

		const char * Alpha_Graphic_Name() const
		{
			if (AlphaGraphicName[0] != '\0') {
				return AlphaGraphicName;
			}
			return Name();
		}

        void Assign_Theater_Name(char *buffer, TheaterType theater);

        static ObjectTypeClass * From_Name(const char *name); 

    public:
        RGBStruct RadialColor;
        ArmorType Armor;
        unsigned int MaxStrength;
        const ShapeFileStruct *Image;
        const ShapeFileStruct *AlphaImage;
        VoxelLibClass *BodyVoxel;
        MotLibClass *BodyMotion;
        VoxelLibClass *TurretVoxel;
        MotLibClass *TurretMotion;
        VoxelLibClass *BarrelVoxel;
        MotLibClass *BarrelMotion;
        unsigned int MaxDimension;
        VocType CrushSound;
        char GraphicName[25];
        char AlphaGraphicName[25];
        bool IsTheater;
        bool IsCrushable;
        bool IsStealthy;
        bool IsSelectable;
        bool IsLegalTarget;
        bool IsInsignificant;
        bool IsImmune;
		bool IsSentient;
		bool IsFootprint;
        bool IsVoxel;
        bool IsNewTheater;
        bool IsHasRadialIndicator;
        bool IsIgnoresFirestorm;
        IndexClass<int, int> field_D4;
        IndexClass<int, int> field_E8;
        IndexClass<int, int> field_FC;
        IndexClass<int, int> field_110;
};
