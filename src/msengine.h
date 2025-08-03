/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          GRAPHICMENU.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Graphic menu instance class.
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
#include "rect.h"
#include "vector.h"


class MSAnim;
class MSSfx;


class MSEngine
{
public:
    MSEngine();
    virtual ~MSEngine();

public:
    int field_4;
    VectorClass<TRect<int>> Rects;
    DynamicVectorClass<MSAnim*> Anims;
    DynamicVectorClass<MSSfx*> Sounds;
};
