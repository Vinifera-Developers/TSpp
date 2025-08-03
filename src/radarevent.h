/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          RADAREVENT.H
 *
 *  @authors       tomsons26, CCHyper
 *
 *  @brief         Radar event types.
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
#include "ftimer.h"
#include "rgb.h"
#include "tibsun_defines.h"
#include "ttimer.h"


typedef struct RadarDrawStruct {
    Point2D Points[4];
} RadarDrawStruct;


class RadarEventClass
{
public:
    RadarEventClass(RadarEventType event, Cell cell);
    ~RadarEventClass();

    void Process();
    void Draw();
    void Plot();
    int Get_Visibility_Duration();
    int Get_Duration();
    int Get_Supression_Distance();
    RGBClass Get_Max_Color();
    RGBClass Get_Min_Color();
    RadarDrawStruct Get_Draw_Data() const;

    static bool Create_Event(RadarEventType event, Cell cell);
    static bool Is_Combat_Event(RadarEventType event);
    static void Process_Events();
    static void Draw_Events();
    static void Remove_Finished();
    static bool Suppression_Check(RadarEventType type, int a2, Cell cell);
    static bool Any_Active();

    static void Plot_Point(Point2D* point);

    static void Clear_All();

    static bool Save_All(IStream* pStm);
    static bool Load_All(IStream* pStm);

public:
    RadarEventType Type;
    int XOffset;
    int YOffset;
    int Radius;
    int RotationAngle;
    int RotationSpeed;
    int ColorFactor;
    int ColorSpeed;
    Cell Location;
    CDTimerClass<FrameTimerClass> DurationTimer;
    CDTimerClass<FrameTimerClass> VisibilityTimer;
    bool IsRotating;
    bool IsVisible;

public:
    static Cell& LastEventCell;
};
