/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          OBJECT.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Game object class.
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
#include "abstract.h"
#include "rect.h"
#include "point.h"
#include "shapeset.h"
#include "tibsun_defines.h"


class TagClass;
class CellClass;
class RadioClass;
class TechnoClass;
class FootClass;
class BuildingClass;
class ObjectTypeClass;
class TechnoTypeClass;
class WarheadTypeClass;


class ObjectClass : public AbstractClass
{
    public:
        /**
         *  IPersistStream
         */
        IFACEMETHOD(Load)(IStream *pStm);

    public:
        ObjectClass();
        ObjectClass(const NoInitClass &noinit);
        virtual ~ObjectClass();

        bool operator < (const ObjectClass & object) const;
        bool operator > (const ObjectClass & object) const;

        inline operator int () const;

        /**
         *  AbstractClass
         */
        virtual void Detach(AbstractClass * target, bool all = false) override;
        virtual void Object_CRC(CRCEngine &crc) const override;
        virtual bool Is_Inactive() const override;
        virtual Coordinate Center_Coord() const override;
        virtual bool On_Ground() const override;
        virtual bool In_Air() const override;
        virtual void AI() override;

        /**
         *  ObjectClass
         */
        virtual bool Is_Players_Army() const;
        virtual VisualType Visual_Character(bool raw = false, const HouseClass *house = nullptr);
        virtual ShapeSet* const Get_Image_Data() const;
        virtual ActionType What_Action(const ObjectClass *object, bool disallow_force = false);
        virtual ActionType What_Action(const Cell &cell, bool check_fog = false, bool disallow_force = false) const;
        virtual LayerType In_Which_Layer() const;
        virtual bool entry_7C() const;
        virtual bool entry_80() const;
        virtual const TechnoTypeClass * Techno_Type_Class() const;
        __declspec(property(get = Techno_Type_Class)) const TechnoTypeClass* TClass;
        virtual const ObjectTypeClass * Class_Of() const;
        virtual int Get_Ownable() const;
        virtual const char *Full_Name() const;
        virtual bool Can_Repair() const;
        virtual bool Can_Demolish() const;
        virtual bool Can_Player_Fire() const;
        virtual bool Can_Player_Move() const; 
        virtual Coordinate Target_Coord() const;
        virtual Coordinate Docking_Coord() const;
        virtual Coordinate Render_Coord() const;
        virtual Coordinate Fire_Coord(WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const;
        virtual Coordinate Exit_Coord() const;
        virtual int Sort_Y() const;
        virtual bool entry_BC();
        virtual bool entry_C0() const;
        virtual bool Limbo();
        virtual bool Unlimbo(const Coordinate &coord, Dir256 dir = DIR_N);
        virtual void Detach_All(bool all = false);
        virtual void Record_The_Kill(const ObjectClass *source);
        virtual bool Paradrop(Coordinate &coord);
        virtual void entry_D8();
        virtual void Set_Occupy_Bit(Coordinate &coord);
        virtual void Clear_Occupy_Bit(Coordinate &coord);
        virtual void Remove_This();
        virtual void Do_Shimmer();
        virtual ExitType Exit_Object(const TechnoClass *object);
        virtual bool Render(Rect &rect, bool force = false, bool a3 = false);
        virtual Cell *Occupy_List(bool placement = false) const;
        virtual void entry_F8(Point2D &point, Rect &bounds) const;
        virtual void entry_FC(Point2D &point, Rect &bounds) const;
        virtual void Draw_It(Point2D &point, Rect &bounds) const;
        virtual void Placement_Draw_It(Point2D &point, Rect &bounds) const;
        virtual void Hidden();
        virtual void Look(bool incremental = false, bool a2 = false);
        virtual bool Mark(MarkType mark = MARK_CHANGE);
        virtual Rect entry_114() const;
        virtual Rect entry_118() const;
        virtual void Draw_Radial_Indicator() const;
        virtual void Mark_For_Redraw();
        virtual bool Active_Click_With(ActionType action, ObjectClass *target, bool a3 = false);
        virtual bool Active_Click_With(ActionType action, Cell &cell, bool a3 = false);
        virtual void Clicked_As_Target(int count = 7);
        virtual bool Select();
        virtual void Unselect();
        virtual bool In_Range(Coordinate &coord, WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const;
        virtual int Weapon_Range(WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const;
        virtual ResultType Take_Damage(int &damage, int distance, const WarheadTypeClass *warhead, const ObjectClass *source, bool forced = false, bool a6 = false);
        virtual void Scatter(const Coordinate &coord = Coordinate{-1, -1, -1}, bool forced = false, bool nokidding = false);
        virtual bool Catch_Fire();
        virtual void Fire_Out();
        virtual int Value() const;
        virtual MissionType Get_Mission() const;
        __declspec( property( get=Get_Mission /*put=Assign_Mission*/ ) ) MissionType Mission;
        virtual void Assign_Mission(MissionType order);
        virtual void Per_Cell_Process(PCPType why);
        virtual BuildingClass *const Who_Can_Build_Me(bool intheory = false, bool legal = false) const;
        virtual RadioMessageType Receive_Message(RadioClass *from, RadioMessageType message, long &param);
        virtual bool Revealed(const HouseClass *house = nullptr);
        virtual void Repair(int control);
        virtual void Sell_Back(int control);
        virtual void entry_174(int a1, int a2);
        virtual void Move(FacingType facing);
        virtual MoveType Can_Enter_Cell(const CellClass *cell, FacingType facing = FACING_NONE, int cell_level = -1, const CellClass *a4 = nullptr, bool a5 = true);
        virtual MoveType entry_180(const CellClass *cell, FacingType facing = FACING_NONE, int *cell_level = nullptr, bool *a4 = nullptr, const CellClass *a5 = nullptr);
        virtual Coordinate Get_Coord() const;
        virtual void Set_Coord(const Coordinate &coord);
        __declspec(property(get = Get_Coord, put = Set_Coord)) Coordinate PositionCoord;
        virtual Cell Get_Cell() const;
        __declspec(property(get = Get_Cell)) Cell PositionCell;
        virtual CellClass *Get_Cell_Ptr() const;
        virtual Cell Get_Target_Cell() const;
        virtual AbstractClass * Get_Target_Cell_Ptr() const;
        virtual int Get_Height_AGL() const;
        __declspec(property(get = Get_Height_AGL, put = Set_Height_AGL)) int HeightAGL;
        virtual void Set_Height_AGL(int height) const;
        virtual int Get_Height() const;
        __declspec(property( get=Get_Height, put=Set_Height)) int Height;

        bool Attach_Tag(TagClass *tag);
        double Get_Health_Ratio() const;
        void Set_Health_Ratio(double health);
        __declspec( property( get=Get_Health_Ratio, put=Set_Health_Ratio ) ) double HealthRatio;
        int Get_Cell_Height() const;
        void Set_Height(int height);
        DirType Direction(AbstractClass * target) const;
        int Distance(AbstractClass * target) const;
        int Distance(const AbstractClass *target) const;
        int Distance_Squared(const AbstractClass *object) const;
        int Distance_Squared(const Coordinate &coord);
        // 00586E30
        // 00586F10
        // 00586F90

        bool Is_Techno() const { return RTTI == RTTI_BUILDING || RTTI == RTTI_UNIT || RTTI == RTTI_INFANTRY || RTTI == RTTI_AIRCRAFT; }
        bool Is_Foot() const;
        bool Is_Infantry() const { return RTTI == RTTI_INFANTRY; }
        
        bool Has_Class() const { return Class_Of() != nullptr; }

        TechnoClass *As_Techno();
        FootClass *As_Foot();

        const char *Name() const;

    public:
        Cell field_14;
        Cell field_18;
        int Riser;
        ObjectClass *Next;
        TagClass *Tag;
        int Strength;
        bool IsDown;
        bool IsToDamage;
        bool IsToDisplay;
        bool IsInLimbo;
        bool IsSelected;
        bool IsAnimAttached;
        bool IsOnBridge;
        bool IsFalling;
        bool IsToExplode;
        bool IsActive;
        LayerType Layer;
        bool IsSubmittedToLayer;
        Coordinate Coord;

    private:
        // copy and assignment not implemented; prevent their use by declaring as private.
        ObjectClass(const ObjectClass &) = delete;
        ObjectClass &operator=(const ObjectClass &) = delete;
};
