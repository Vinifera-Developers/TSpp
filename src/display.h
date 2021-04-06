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


class ObjectClass;
class ObjectTypeClass;
class LayerClass;
struct ShapeFileStruct;


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

		virtual void Load(IStream *pStm);
		virtual void Save(IStream *pStm);
		virtual void Read_INI(CCINIClass &ini);
		virtual void Help_Text(int text);
        virtual void entry_84();
        virtual void Abort_Drag_Select();
		virtual bool Map_Cell(CellStruct &cell, HouseClass *house);
        virtual bool entry_90(CellStruct &cell, HouseClass *house);
        virtual bool entry_94(CellStruct &cell, HouseClass *house);
        virtual MouseType Get_Mouse_Shape() const = 0;
		virtual bool Scroll_Map(DirType facing, int &distance, bool really = true);
		virtual void Set_View_Dimensions(Rect &rect);
        virtual void Put_Place_Back(TechnoClass *techno);
		virtual void Mouse_Right_Press(Point2D &xy = Point2D());
		virtual void Mouse_Left_Press(Point2D &xy);
		virtual void Mouse_Left_Up(CellStruct &cell, bool shadow, ObjectClass *object, ActionType action, bool wsmall = false);
		virtual void Mouse_Left_Held(Point2D &xy);
		virtual void Mouse_Left_Release(Point2D &xy, CellStruct &cell, ObjectClass *object, ActionType action, bool wsmall = false);
		virtual void Mouse_Right_Up(Point2D &xy = Point2D());

        void Set_Cursor_Shape(CellStruct const *list);
        // 004761A0
        // 00476350
        CellStruct Set_Cursor_Pos(CellStruct &pos = CellStruct(-1,-1));
        wDimensionStruct Get_Occupy_Dimensions(CellStruct const *list) const;
        void Cursor_Mark(CellStruct &pos, bool on);
        void Submit(ObjectClass const *object);
        void Remove(ObjectClass const *object);
		ObjectClass *Cell_Object(CellStruct &cell, Point2D &xy = Point2D());
		ObjectClass *Next_Object(ObjectClass *object) const;
		ObjectClass *Prev_Object(ObjectClass *object) const;
		CellStruct Calculated_Cell(SourceType dir, CellStruct &waypoint = CellStruct(-1,-1), CellStruct &cell = CellStruct(-1,-1), SpeedType loco = SPEED_FOOT, bool zonecheck = true, MZoneType mzone = MZONE_NORMAL) const;
        bool Good_Reinforcement_Cell(CellStruct &outcell, CellStruct &incell, SpeedType loco, int zone, MZoneType mzone) const;
        // 00479150
        // 004793A0
        void Sell_Mode_Control(int control);
        void Waypoint_Mode_Control(int control, bool a2);
        void Power_Mode_Control(int control);
        void Repair_Mode_Control(int control);
        CoordStruct Closest_Free_Spot(CoordStruct &coord, bool any = false) const;
        bool Is_Spot_Free(CoordStruct &coord, bool a2 = false) const;
        void Encroach_Shadow();
        void Encroach_Fog();
        void Fog_Cell(CellStruct &cell);
        void Shroud_Cell(CellStruct &cell);
        void Write_INI(CCINIClass &ini);
        // 0047A790
        // 0047A900
        void All_To_Look(bool units_only = false, bool a2 = false);
        void Constrained_Look(CoordStruct &coord, LEPTON distance);
        void Compute_Start_Pos();
        // 0047AE80
        // 0047AEF0
        // 0047B170
        // 0047B190
        // 0047B210
        // 0047BF50
        // 0047BFC0
        ObjectClass *Following_What() const;
        void Follow_This(ObjectClass *object);

    public:
        CellStruct ZoneCell;
        CellStruct ZoneOffset;
        CellStruct *CursorSize;
        bool IsProximityCheck;
        bool field_11A9;                    // shroud proximity check?
        bool IsFollowingObject;
        ObjectClass *FollowingObjectPtr;
        ObjectClass *PendingObjectPtr;
        ObjectTypeClass *PendingObject;
        HousesType PendingHouse;
        bool IsRepairMode;
        bool IsSellMode;
        bool IsPowerMode;
        bool IsWaypointMode;
        SpecialWeaponType TargettingType;
        CoordStruct *field_11C4;            // waypoint related
        CoordStruct field_11C8;             // current waypoint coord (as user is moving mouse around).
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
        static LayerClass *Layer;
};
