/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          LASERDRAW.H
 *
 *  @author        CCHyper, tomsons26
 *
 *  @brief         Graphical laser drawing.
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
#include "rgb.h"
#include "stage.h"
#include "tibsun_defines.h"


class LaserDrawClass
{
public:
    LaserDrawClass(Coord source, Coord target, int z_adjust, bool a9, RGBClass inner, RGBClass outer, RGBClass outer_spread, int duration, bool blinks = false, bool fades = true, float start_int = 0.5f, float end_int = 1.0f);
    ~LaserDrawClass();

    void Draw_It();
    void AI();

    static void Update_All();
    static void Clear_All();
    static void Draw_All();

public:
    StageClass DrawStage;
    Coord Source;
    Coord Target;
    int ZAdjust;
    bool field_34;
    RGBClass InnerColor;
    RGBClass OuterColor;
    RGBClass OuterSpreadColor;
    int Duration;
    bool Blinks;
    bool BlinkState;
    bool FadeOut;
    float StartIntensity;
    float EndIntensity;
};
