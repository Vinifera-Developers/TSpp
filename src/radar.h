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
#include "point.h"
#include "rect.h"
#include "stimer.h"
#include "ttimer.h"


class DSurface;
class BSurface;


struct RadarTrackingStruct {

    RadarTrackingStruct(TechnoClass* object, int x, int y) : Object(object), X(x), Y(y) {}
    RadarTrackingStruct() {}

    TechnoClass* Object;
    int X;
    int Y;

    bool operator==(const RadarTrackingStruct& that) const { return (X == that.X && Y == that.Y); }
    bool operator!=(const RadarTrackingStruct& that) const { return (X != that.X && Y != that.Y); }

    int Hash() const { return ((X - 5 * Y) & 0xFF); }
};


class RadarClass : public DisplayClass
{
public:
    RadarClass();
    RadarClass(const NoInitClass& x);
    ~RadarClass();

    /**
     *  GScreenClass
     */
    virtual void One_Time() override;
    virtual void Init_Clear() override;
    virtual void AI(KeyNumType& input, Point2D& xy) override;
    virtual void Draw_It(bool forced = false) override;

    /**
     *  MapClass
     */
    virtual void Set_Map_Dimensions(Rect& rect, bool a2 = true, int level = 1, bool a4 = false) override;
    virtual void entry_70(Rect& rect) override;

    /**
     *  DisplayClass
     */
    virtual HRESULT Load(IStream* pStm) override;
    virtual HRESULT Save(IStream* pStm) override;
    virtual void Set_Dimensions() override;
    virtual bool Map_Cell(Cell& cell, HouseClass* house) override;

    virtual Cell Click_Cell_Calc(Point2D& cell);
    virtual void Set_Tactical_Position(Coord& coord);
    virtual void Init_For_House();

    // 005B9050
    int Cell_On_Radar(Cell& cell) const;
    void Draw_Names();
    // 005B99D0
    void Compute_Radar_Image();
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
    bool Is_Radar_Existing();
    void Toggle_Radar(bool tactical_availability);
    bool Is_Player_Names();
    // 005BC170
    void Redraw_Radar(bool a1);
    // 005BC1C0
    // 005BCC40
    void Total_Radar_Refresh();

    void Clear_Background_Update_Stack() { PixelStack.Clear(); }

public:

    /**
     *  The dimensions and coordinates of the radar map.
     */
    int RadX;
    int RadY;
    int RadWidth;
    int RadHeight;
    int RadOffX;
    int RadOffY;
    int RadIWidth;
    int RadIHeight;
    int RadPWidth;
    int RadPHeight;

    Rect field_1214;
    DSurface* field_1224;
    BSurface* field_1228;

    /**
     *  This is the list of radar pixels that need to be updated. Only a partial
     *  list is maintained for maximum speed.
     */
    DynamicVectorClass<Cell> PixelStack;
    RGBClass* PixelColors;

    /**
     *  The width and height is controlled by the actual dimensions
     *  of the radar map display box (in pixels).
     */
    unsigned RadarCellWidth;
    unsigned RadarCellHeight;

    Rect field_1250;
    void* field_1260; // hash table
    DynamicVectorClass<Point2D> field_1264;
    int field_127C;

    DynamicVectorClass<Point2D> Foundation[BSIZE_COUNT];

    /**
     * This is the zoom factor to use. This value is the number of pixels wide
     * each cell will occupy on the radar map. Completely zoomed out would be a
     * value of 1.
     */
    float ZoomFactor;

    /**
     *  The current radar position as the upper left corner cell for the
     *  radar map display.
     */
    int field_1494;
    int RadarX;
    int field_149C;
    int RadarY;

    /**
     *  This is the origin (pixel offsets) for the upper left corner
     *  of the radar map within the full radar map area of the screen.
     *  This is biased so that the radar map, when smaller than full
     *  size will appear centered.
     */
    Rect RadarRect;

    typedef enum RadarStateType {
        RSTATE_INACTIVE,
        RSTATE_ACTIVE,
        RSTATE_DEACTIVATING,
        RSTATE_ACTIVATING,
        RSTATE_NEXT_MOVIE,
        RSTATE_MOVIE_DONE,
    } RadarStateType;

    int RadarState;

    typedef enum RadarModeType {
        RMODE_UNAVAILABLE,
        RMODE_TACTICAL,
        RMODE_PLAYER_NAMES,
        RMODE_MOVIE,
        RMODE_4,
        RMODE_5,
    } RadarModeType;

    int RadarMode;
    int SuspendedRadarMode;

    /**
     *  If the radar map is visible then this flag is true.
     */
    bool DoesRadarExist;

    /**
     *  If the radar map must be completely redrawn, then this flag will be true.
     *  Typical causes of this would be when the radar first appears, or when the
     *  screen has been damaged.
     */
    bool IsToRedraw;
    bool FullRedraw;

    Rect field_14C4;
    Rect field_14D4;

    int RadarAnimFrame;
    CDTimerClass<SystemTimerClass> RadarAnimTimer;

public:
    class RTacticalClass : public GadgetClass
    {
    public:
        RTacticalClass();
        virtual bool Action(unsigned flags, KeyNumType& key) override;

        friend class RadarClass;
    };

    friend class RTacticalClass;

    static RTacticalClass& RadarButton;
};
