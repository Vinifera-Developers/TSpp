/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          DISPLAY.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Class for the game user input interface.
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

#include "map.h"
#include "gadget.h"
#include "rect.h"
#include "tspp.h"


class ObjectClass;
class ObjectTypeClass;
class LayerClass;
class ShapeSet;


class DisplayClass : public MapClass
{
    public:
        DisplayClass();
        DisplayClass(const NoInitClass &x);
        ~DisplayClass();

        /**
         *  GScreenClass
         */
        virtual void One_Time() override;
        virtual void Init_Clear() override;
        virtual void Init_IO() override;
        virtual void AI(KeyNumType &input, Point2D &xy) override;

        virtual HRESULT Load(IStream *pStm);
        virtual HRESULT Save(IStream *pStm);
        virtual void Read_INI(CCINIClass &ini);
        virtual const char *Help_Text(int text);
        virtual void Set_Dimensions();
        virtual void Abort_Drag_Select();
        virtual bool Map_Cell(Cell &cell, HouseClass *house);
        virtual bool entry_90(Cell &cell, HouseClass *house);
        virtual bool entry_94(Cell &cell, HouseClass *house);
        virtual MouseType Get_Mouse_Shape() const = 0;
        virtual bool Scroll_Map(FacingType facing, int &distance, bool really = true);
        virtual void Set_View_Dimensions(Rect &rect);
        virtual void Put_Place_Back(TechnoClass *techno);
        virtual void Mouse_Right_Press(Point2D &xy = Point2D());
        virtual void Mouse_Left_Press(Point2D &xy);
        virtual void Mouse_Left_Up(Cell &cell, bool shadow, ObjectClass *object, ActionType action, bool wsmall = false);
        virtual void Mouse_Left_Held(Point2D &xy);
        virtual void Mouse_Left_Release(Point2D &xy, Cell &cell, ObjectClass *object, ActionType action, bool wsmall = false);
        virtual void Mouse_Right_Up(Point2D &xy = Point2D());

        void Set_Cursor_Shape(Cell const *list);
        bool Passes_Proximity_Check(const ObjectTypeClass *object, HousesType house, const Cell *list, Cell &trycell);
        bool Passes_Shroud_Check(const ObjectTypeClass *object, HousesType house, const Cell *list, Cell &trycell);
        Cell Set_Cursor_Pos(Cell &pos = CELL_NONE);
        wDimensionStruct Get_Occupy_Dimensions(Cell const *list) const;
        void Cursor_Mark(Cell &pos, bool on);
        void Submit(ObjectClass const *object);
        void Remove(ObjectClass const *object);
        ObjectClass *Cell_Object(Cell &cell, Point2D &xy = Point2D());
        ObjectClass *Next_Object(ObjectClass *object) const;
        ObjectClass *Prev_Object(ObjectClass *object) const;
        Cell Calculated_Cell(SourceType dir, Cell &waypoint = CELL_NONE, Cell &cell = CELL_NONE, SpeedType loco = SPEED_FOOT, bool zonecheck = true, MZoneType mzone = MZONE_NORMAL) const;
        bool Good_Reinforcement_Cell(Cell &outcell, Cell &incell, SpeedType loco, int zone, MZoneType mzone) const;
        void Compute_Start_Pos();
        void Sell_Mode_Control(int control);
        void Waypoint_Mode_Control(int control, bool a2);
        void Power_Mode_Control(int control);
        void Repair_Mode_Control(int control);
        Coordinate Closest_Free_Spot(const Coordinate &coord, bool any = false) const;
        bool Is_Spot_Free(Coordinate &coord, bool a2 = false) const;
        void Encroach_Shadow();
        void Encroach_Fog();
        void Fog_Cell(Cell &cell);
        void Shroud_Cell(Cell &cell);
        void Write_INI(CCINIClass &ini);
        // 0047A790
        // 0047A900
        void All_To_Look(bool units_only = false, bool a2 = false);
        void Constrained_Look(Coordinate &coord, LEPTON distance);
        void Center_On_Selection();
        // 0047AE80
        // 0047AEF0
        // 0047B170
        // 0047B190
        // 0047B210
        // 0047BF50
        // 0047BFC0
        ObjectClass *Following_What() const;
        void Follow_This(ObjectClass *object);

        static void Bandbox_Select(ObjectClass* obj);

    public:
        Cell ZoneCell;
        Cell ZoneOffset;
        Cell *CursorSize;
        bool IsProximityCheck;
        bool IsShroudCheck;
        bool IsFollowingObject;
        ObjectClass *FollowingObjectPtr;
        ObjectClass *PendingObjectPtr;
        ObjectTypeClass *PendingObject;
        HousesType PendingHouse;
        bool IsRepairMode;
        bool IsSellMode;
        bool IsPowerMode;
        bool IsWaypointMode;
        SuperWeaponType TargettingType;
        Coordinate *field_11C4;            // waypoint related
        Coordinate field_11C8;             // current waypoint coord (as user is moving mouse around).
        RGBStruct field_11D4;               // waypoint related, waypoint scrolling color?
        bool IsRubberBand;
        bool IsTentative;
        bool IsShadowPresent;
        Point2D Band;
        Point2D New;

    public:
        class TacticalClass : public GadgetClass
        {
            public:
                TacticalClass();

            protected:
                virtual bool Action(unsigned flags, KeyNumType &key) override;
        };

        friend class TacticalClass;

    public:
        static TacticalClass &TacButton;
        static ARRAY_MEMBER_DEC(LayerClass, Layer, LAYER_COUNT);
};
