/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SHAPEBTN.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Shape image button.
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

#include "toggle.h"


class ConvertClass;
class ShapeSet;


class ShapeButtonClass : public ToggleClass
{
public:
    ShapeButtonClass();
    ShapeButtonClass(unsigned id, const ShapeSet* shapes, int x, int y, int w = 0, int h = 0, bool alpha = false);
    virtual ~ShapeButtonClass();

    virtual bool Draw_Me(bool forced = false) override;

    virtual void Set_Shape(const ShapeSet* data, int width = 0, int height = 0);

    const ShapeSet* Get_Shape_Data() { return ShapeData; }

public:
    bool ReflectButtonState;
    int DrawX;
    int DrawY;
    bool DrawnOnSidebarSurface;
    ConvertClass* ShapeDrawer;
    bool IsDrawn;
    bool DrawAlpha;
    const ShapeSet* ShapeData;
};
