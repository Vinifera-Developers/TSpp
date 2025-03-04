/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TACTICAL.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Tactical interface handler.
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

#include "abstract.h"
#include "rect.h"
#include "point.h"
#include "ttimer.h"
#include "ftimer.h"
#include "matrix3d.h"


class CellClass;
class XSurface;


struct IsoCoordinate : public Point2D {};

typedef enum RenderPassEnum
{
    RENDERPASS_FIRST,       // Tile surface, ZBuffer, and ABuffer.
    RENDERPASS_SECOND,      // Buildings (without animations), Overlays, and Smudges.
    RENDERPASS_THIRD,       // Animations, Terrain, Tile animations, and Objects.
    RENDERPASS_ALL,         // Composite of all passes.
};


class DECLSPEC_UUID("CF56B38A-240D-11D2-817C-006008055BB5")
Tactical : public AbstractClass
{
    public:
        /**
         *  IPersist
         */
        IFACEMETHOD(GetClassID)(CLSID *pClassID);

        /**
         *  IPersistStream
         */
        IFACEMETHOD(Load)(IStream *pStm);
        IFACEMETHOD(Save)(IStream *pStm, BOOL fClearDirty);

    public:
        Tactical();
        Tactical(const NoInitClass &noinit);
        virtual ~Tactical();

        /**
         *  AbstractClass
         */
        virtual void Detach(TARGET target, bool all = true) override;
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual void AI() override;

        /**
         *  Tactical
         */
        virtual bool entry_64(Rect &a1, Rect &a2, unsigned color, bool a4 = false);

        Point2D func_60F150(const Coordinate &coord) const; // Coord to Pixel (without validation)?
        Point2D func_60F270(const Cell &cell) const; // Cell to pixel (without validation)?
        Point2D func_60F350(const Coordinate &coord) const;
        static int func_60F3C0(int a1);
        bool Coord_To_Pixel(const Coordinate &coord, Point2D &pixel) const;
        Coordinate Pixel_To_Coord(const Point2D &pixel) const;
        Coordinate func_60F740(const Point2D &pixel) const;
        void func_60F800(const Coordinate &coord, int a2);
        void Register_Dirty_Area(Rect rect, bool a5 = false); // 0060FBB0
        static int Z_Lepton_To_Pixel(LEPTON z);
        static LEPTON Pixel_To_Z_Lepton(int a1);
        // 0060FF70
        // 0060FF80
        // 00610240
        // 006104A0
        // 006106F0
        // 006108E0
        // 00610AD0
        // 00610D40
        // 00610F90
        void Render(XSurface &surface, bool full_redraw, RenderPassEnum render_pass);
        void Set_Caption_Text(int text_id);
        void Clear_Caption_Text();
        void Draw_Screen_Text(const char *text);
        // 00611DD0
        // 006122C0
        // 00612570
        // 00612810
        // 00612B10
        void Set_Tactical_Dimensions(const Rect & rect);
        void Set_Tactical_Center_Position(const Point2D &point);
        void Set_Tactical_Position(const Coordinate &coord);
        Point2D Get_Tactical_Center_Position() const;
        Point2D Get_Tactical_Position() const;
        // 00612DA0
        // 00612E00
        // 00612E80
        // 00612F00
        // 00612F90
        // 00613040
        Cell Click_Cell_Calc(Point2D &pixel) const;
        // 006136F0
        // 00613730
        // 00613750
        // 00613810
        // 00613970
        // 00613E50
        // 006141C0
        // 006144A0
        // 006147B0
        // 00614AF0
        // 00614D50
        // 00614DB0
        // 00614EB0
        // 00614EC0
        int Cell_Shadow(Cell &cell, bool a2 = false);
        // 00615380
        // 006153D0
        // 006154E0
        // 006156A0
        // 00615C50
        // 00615D80
        // 00615D90
        // 00615EC0
        // 00615FB0
        // 00616180
        // 006163C0
        // 00616440
        // 00616480
        // 006164B0
        // 00616540
        // 00616560
        // 00616610
        // 00616730
        // 00616740
        // 00616750
        // 00616760
        // 00616920
        // 00616940
        // 00616AA0
        // 00616C40
        // 00616C90
        // 00616F20
        void Debug_Draw_Occupiers(); // 006173B0
        void Debug_Draw_Occupiers_Flags(); // 006177A0
        // 00617CD0
        // 00617EE0
        void Draw_Radial_Indicators() const; // 00617FA0
        
        static Point2D func_60F0F0(Point2D point);
        static int func_60F450(int a1);

    public:
        char ScreenText[64];
        int LastAIFrame;
        bool field_58;
        bool field_59;
        IsoCoordinate field_5C;
        IsoCoordinate field_64;
        int field_6C;
        double ZoomFactor;
        int DirtyObjectCount;
        IsoCoordinate MoveFrom;
        IsoCoordinate MoveTo;
        float MoveRate;
        float MoveFactor;
        int field_94;
        CellClass *field_98[800];
        IsoCoordinate field_D18;
        IsoCoordinate field_D20;
        IsoCoordinate field_D28;
        bool field_D30;
        bool IsToRedraw;
        bool field_D32;
        Rect field_D34;
        Rect Band;
        int field_D54;
        CDTimerClass<FrameTimerClass> WaypointAnimTimer;
        Matrix3D field_D64;
        Matrix3D field_D94;
};
