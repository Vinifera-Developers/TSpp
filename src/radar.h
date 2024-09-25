/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          RADAR.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Class for the game radar interface.
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


#include "display.h"
#include "rect.h"
#include "point.h"
#include "ttimer.h"
#include "stimer.h"


class DSurface;
class BSurface;


class RadarClass : public DisplayClass
{
    public:
        RadarClass();
        RadarClass(const NoInitClass &x);
        ~RadarClass();

        /**
         *  GScreenClass
         */
		virtual void One_Time() override;
		virtual void Init_Clear() override;
		virtual void AI(KeyNumType &input, Point2D &xy) override;
        virtual void Draw_It(bool forced = false) override;

        /**
         *  MapClass
         */
        virtual void Set_Map_Dimensions(Rect &rect, bool a2 = true, int level = 1, bool a4 = false) override;
        virtual void entry_70(Rect &rect) override;

        /**
         *  DisplayClass
         */
		virtual HRESULT Load(IStream *pStm) override;
		virtual HRESULT Save(IStream *pStm) override;
        virtual void Set_Dimensions() override;
		virtual bool Map_Cell(Cell &cell, HouseClass *house) override;

        virtual Cell Click_Cell_Calc(Point2D &cell);
        virtual void Set_Tactical_Position(Coordinate &coord);
        virtual void Init_For_House();

        // 005B9050
        int Cell_On_Radar(Cell &cell) const;
        void Draw_Names();
        // 005B99D0
        // 005B9B90
        // 005B9D10
        // 005BA3E0
        // 005BA590
        // 005BA600
        // 005BA690
        // 005BA700
        // 005BA790
        // 005BAAA0
        // 005BAC80
        // 005BAD30
        // 005BAE10
        // 005BAED0
        // 005BAFD0
        // 005BB060
        // 005BB180
        // 005BB4D0
        // 005BB620
        // 005BB6F0
        // 005BB8C0
        // 005BB8E0
        // 005BBA90
        // 005BBE50
        // 005BBED0
        bool Radar_Activate(int control);
        // 005BC050
        // 005BC070
        void Toggle_Radar(bool tactical_availability);
        // 005BC150
        // 005BC170
        // 005BC190
        // 005BC1C0
        // 005BCC40
        // 005BCE90

    public:
        int RadarX;                     // Offset of the radar image.
        int RadarY;
        int RadarWidth;
        int RadarHeight;
        int RadarOffX;                  // offset for the interactive area relative from the radar image.
        int RadarOffY;
        int RadarIWidth;
        int RadarIHeight;
        int RadarPWidth;
        int RadarPHeight;
        Rect field_1214;
        DSurface *field_1224;
        BSurface *field_1228;
        DynamicVectorClass<Cell> field_122C;
        int field_1244;
        int field_1248;
        int field_124C;
        int field_1250;
        int field_1254;
        int field_1258;
        int field_125C;
        int field_1260;
        DynamicVectorClass<Point2D> field_1264;
        int field_127C;
        DynamicVectorClass<Point2D> field_1280[22];
        int field_1490;
        int field_1494;
        int field_1498;
        int field_149C;
        int field_14A0;
        Rect field_14A4;
        int field_14B4;
        int field_14B8;
        int field_14BC;
        bool IsRadarAvailable;
        bool IsToRedraw;
        bool field_14C2;
        Rect field_14C4;
        Rect field_14D4;
        int RadarAnimFrame;
        CDTimerClass<SystemTimerClass> RadarAnimTimer;

    public:
		class RTacticalClass : public GadgetClass
        {
			public:
				RTacticalClass();
				virtual bool Action(unsigned flags, KeyNumType &key) override;

			friend class RadarClass;
		};

		friend class RTacticalClass;

		static RTacticalClass &RadarButton;
};
