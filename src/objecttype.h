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
#include "shapeset.h"
#include "voxelobj.h"


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
    IFACEMETHOD(Load)(IStream* pStm);
    IFACEMETHOD(Save)(IStream* pStm, BOOL fClearDirty);
    IFACEMETHOD_(LONG, GetSizeMax)(ULARGE_INTEGER* pcbSize);

public:
    ObjectTypeClass(const char* ini_name = nullptr);
    ObjectTypeClass(const NoInitClass& noinit);
    virtual ~ObjectTypeClass();

    /**
     *  AbstractTypeClass
     */
    virtual bool Read_INI(CCINIClass& ini) override;

    /**
     *  ObjectTypeClass
     */
    virtual Coord Coord_Fixup(Coord* coord) const;
    virtual int Get_Ownable() const;
    virtual int Max_Pips() const;
    virtual Point3D Pixel_Dimensions() const;
    virtual Point3D Lepton_Dimensions() const;
    virtual bool Create_And_Place(Cell& cell, HouseClass* house = nullptr) const = 0;
    virtual int Cost_Of(HouseClass* house = nullptr) const;
    virtual int Time_To_Build() const;
    virtual ObjectClass* const Create_One_Of(HouseClass* house = nullptr) const = 0;
    virtual Cell* Occupy_List(bool placement = false) const;
    virtual BuildingClass* const Who_Can_Build_Me(bool in_theory = false, bool a2 = false, bool legal = false, HouseClass* house = nullptr) const;
    virtual ShapeSet* const Get_Cameo_Data() const;
    virtual ShapeSet* const Get_Image_Data() const;

    const char* Graphic_Name() const
    {
        if (!GraphicName.empty()) {
            return GraphicName.c_str();
        }
        return Name();
    }

    const char* Alpha_Graphic_Name() const
    {
        if (!AlphaGraphicName.empty()) {
            return AlphaGraphicName.c_str();
        }
        return Name();
    }


    void Theater_Naming_Convention(char* name, TheaterType theater);
    void Fetch_Normal_Image();

    static const ObjectTypeClass* From_Name(const char* name);

    static void Clear_Voxel_Indexes();

public:
    RGBStruct RadialColor;
    ArmorType Armor;
    unsigned int MaxStrength;
    const ShapeSet* Image;
    const ShapeSet* AlphaImage;
    VoxelObject Voxel;
    VoxelObject AuxVoxel;
    VoxelObject AuxVoxel2;
    unsigned int MaxDimension;
    VocType CrushSound;
    TStringID<24> GraphicName;
    TStringID<24> AlphaGraphicName;
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
    VoxelIndexClass VoxelIndex;
    VoxelIndexClass AuxVoxelIndex;
    VoxelIndexClass ShadowVoxelIndex;
    VoxelIndexClass AuxVoxel2Index;

public:
    /*
    **  Selected objects have a special marking box around them. This is the shapes that are
    **  used for this purpose.
    */
    static const ShapeSet*& SelectShapes;

    static const ShapeSet*& PipShapes;
    static const ShapeSet*& Pip2Shapes;

    static const ShapeSet*& TalkBubbleShapes;
};
