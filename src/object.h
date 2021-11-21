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


/*******************************************************************************
 *	Every game object (that can exist on the map) is ultimately derived from
 *  this object class. It holds the common information between all objects.
 *  This is primarily the object unique ID number and its location in the world.
 *  All common operations between game objects are represented by virtual
 *  functions in this class.
 */
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

        /**
         *  AbstractClass
         */
        virtual void Detach(TARGET target, bool all = false) override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;
        virtual bool Is_Inactive() const override;
        virtual Coordinate Center_Coord() const override;
        virtual bool On_Ground() const override;
        virtual bool In_Air() const override;
        virtual void AI() override;

        /**
         *  ObjectClass
         */

        /**
         *  Query functions.
         */
        virtual bool Is_Players_Army() const;
        virtual VisualType Visual_Character(bool raw = false, const HouseClass *house = nullptr);
        virtual void *const Get_Image_Data() const;
        virtual ActionType What_Action(const ObjectClass *object, bool disallow_force = false);
        virtual ActionType What_Action(Cell &cell, bool check_fog = false, bool disallow_force = false) const;
        virtual LayerType In_Which_Layer() const;
        virtual bool entry_7C() const;
        virtual bool entry_80() const;
        virtual TechnoTypeClass *const Techno_Type_Class() const;
        virtual ObjectTypeClass *const Class_Of() const;
        virtual int Get_Ownable() const;
        virtual const char *Full_Name() const;
        virtual bool Can_Repair() const;
        virtual bool Can_Demolish() const;
        virtual bool Can_Player_Fire() const;
        virtual bool Can_Player_Move() const; 

        /**
         *  Coordinate inquiry functions. These are used for both display and
         *  combat purposes.
         */
        virtual Coordinate Target_Coord() const;
        virtual Coordinate Docking_Coord() const;
        virtual Coordinate Render_Coord() const;
        virtual Coordinate Fire_Coord(WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const;
        virtual Coordinate Exit_Coord() const;
        virtual int Sort_Y() const;

        virtual bool entry_BC();
        virtual bool entry_C0() const;

        virtual bool Limbo();
        virtual bool Unlimbo(Coordinate &coord, DirType dir = DIR_N);
        virtual void Detach_All(bool all = false);
        virtual void Record_The_Kill(const ObjectClass *source);
        virtual bool Paradrop(Coordinate &coord);
        virtual void entry_D8();
        virtual void Set_Occupy_Bit(Coordinate &coord);
        virtual void Clear_Occupy_Bit(Coordinate &coord);
        virtual void entry_E4();

        /**
         *  Display and rendering support functionality. Supports imagery and how
         *  object interacts with the map and thus indirectly controls rendering.
         */
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
        virtual void entry_11C() const;
        virtual void Mark_For_Redraw();

        /**
         *  User I/O.
         */
        virtual bool Active_Click_With(ActionType action, ObjectClass *target, bool a3 = false);
        virtual bool Active_Click_With(ActionType action, Cell &cell, bool a3 = false);
        virtual void Clicked_As_Target(int count = 7);
        virtual bool Select();
        virtual void Unselect();

        /**
         *  Combat related.
         */
        virtual bool In_Range(Coordinate &coord, WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const;
        virtual int Weapon_Range(WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const;
        virtual ResultType Take_Damage(int &damage, int distance, const WarheadTypeClass *warhead, const ObjectClass *source, bool forced = false, bool a6 = false);
        virtual void Scatter(Coordinate &coord = Coordinate{-1, -1, -1}, bool forced = false, bool nokidding = false);
        virtual bool Catch_Fire();
        virtual void Fire_Out();
        virtual int Value() const;
        virtual MissionType Get_Mission() const;
        virtual void Assign_Mission(MissionType order);

        /**
         *  AI.
         */
        virtual void Per_Cell_Process(PCPType why);
        virtual BuildingClass *const Who_Can_Build_Me(bool intheory = false, bool legal = false) const;
        virtual RadioMessageType Receive_Message(RadioClass *from, RadioMessageType message, long &param);
        virtual bool Revealed(const HouseClass *house = nullptr);
        virtual void Repair(int control);
        virtual void Sell_Back(int control);

        virtual void entry_174(int a1, int a2);

        /**
         *  Scenario and debug support.
         */
        virtual void Move(FacingType facing);

        virtual MoveType Can_Enter_Cell(const CellClass *cell, FacingType facing = FACING_NONE, int cell_level = -1, const CellClass *a4 = nullptr, bool a5 = false);
        virtual MoveType entry_180(const CellClass *cell, FacingType facing = FACING_NONE, int *cell_level = nullptr, bool *a4 = nullptr, const CellClass *a5 = nullptr);
        virtual Coordinate Get_Coord() const;
        virtual void Set_Coord(Coordinate &coord);
        virtual Cell Get_Cell() const;
        virtual CellClass *Get_Cell_Ptr() const;
        virtual Cell Get_Target_Cell() const;
        virtual TARGET Get_Target_Cell_Ptr() const;
        virtual int Get_Height() const;
        virtual void Set_Height(int a1) const;
        virtual int Get_Z_Coord() const;

        bool Attach_Tag(TagClass *tag);
        float Health_Ratio() const;
        void Set_Health_Ratio(double health);
        int func_586730() const;
        void Set_Z_Coord(int z);
        DirStruct Direction(TARGET *target);
        int Distance(TARGET target) const;
        int Distance(const AbstractClass *target) const;
        int Distance_Squared(const AbstractClass *object) const;
        int Distance_Squared(const Coordinate &coord);
        // 00586E30
        // 00586F10
        // 00586F90

		bool Is_Techno() const { RTTIType rtti = Kind_Of(); return rtti == RTTI_BUILDING || rtti == RTTI_UNIT || rtti == RTTI_INFANTRY || rtti == RTTI_AIRCRAFT; }
        bool Is_Foot() const;
        bool Is_Infantry() const { RTTIType rtti = Kind_Of(); return rtti == RTTI_INFANTRY; }
		
        bool Has_Class() const { return Class_Of() != nullptr; }

        const char *Name() const;

        /**
         *  Reduces attached animation durations.
         */
        static void Shorten_Attached_Anims();

		/**
		 *  Object selection control.
		 */
        static void Init() { CurrentObjects.Clear(); }

    public:
        int field_14;
        int field_18;
        int Riser;

        /**
         *  Several objects could exist in the same cell list. This is a pointer
         *  to the next object in the cell list. The objects in this list are
         *  not in any significant order.
         */
        ObjectClass *Next;

        TagClass *Tag;

        /**
         *  This is the current strength of this object.
         */
        int Strength;

		/**
		 *  The object can be in one of two states -- placed down on the map, or not.
         *  If the object is placed down on the map, then this flag will be true.
		 */
        bool IsDown;

        /**
         *  This is a support flag that is only used while building a list of
         *  objects to be damaged by a proximity affect (explosion). When this
         *  flag is set, this object will not be added to the list of units to
         *  damage. When damage is applied to the object, this flag is cleared
         *  again. This process ensures that an object is never subject
         *  to "double jeopardy".
         */
        bool IsToDamage;

        /**
         *  Is this object flagged to be displayed during the next rendering
         *  process?  This flag could be set by many different circumstances.
         *  It is automatically cleared when the object is rerendered.
         */
        bool IsToDisplay;

        /**
         *  An object in the game may be valid yet held in a state of "limbo".
         *  Units are in such a state if they are being transported or are
         *  otherwise "inside" another unit. They can also be in limbo if they
         *  have been created but are being held until the proper time for delivery.
         */
        bool IsInLimbo;

        /**
         *  When an object is "selected" it is given a floating bar graph or
         *  other graphic imagery to display this fact. When the player performs
         *  I/O, the actions may have a direct bearing on the actions of the
         *  currently selected object. For quick checking purposes, if this
         *  object is the one that is "selected", this flag will be true.
         */
        bool IsSelected;

        /**
         *  If an animation is attached to this object, then this flag will be true.
         */
        bool IsAnimAttached;

        bool IsOnBridge;

        /**
         *  If this object should process falling logic, then this flag will be true. Such
         *  objects might be ballistic projectiles, grenades, or parachuters.
         */
        bool IsFalling;

        bool IsToExplode;

        /**
         *  The actual object ram-space is located in arrays in the data segment.
         *  This flag is used to indicate which objects are free to be reused and
         *  which are currently in use by the game.
         */
        bool IsActive;

        LayerType Layer;
        bool IsSubmittedToLayer;

        /**
         *  The coordinate location of the unit. For vehicles, this is the center
         *  point. For buildings, it is the upper left corner.
         */
        Coordinate Coord;

    private:
        // copy and assignment not implemented; prevent their use by declaring as private.
        ObjectClass(const ObjectClass &) = delete;
        ObjectClass &operator=(const ObjectClass &) = delete;
};
