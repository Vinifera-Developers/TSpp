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
struct ShapeFileStruct;


class ShapeButtonClass : public ToggleClass
{
    public:
        ShapeButtonClass();
        ShapeButtonClass(unsigned id, const ShapeFileStruct *shapes, int x, int y);
        virtual ~ShapeButtonClass();

        virtual bool Draw_Me(bool forced = false) override;

        virtual void Set_Shape(const ShapeFileStruct *data, int width = -1, int height = -1);

        const ShapeFileStruct *Get_Shape_Data() { return ShapeData; }

    public:
        bool ReflectButtonState;
        int DrawX;
        int DrawY;
        bool field_3C;
        ConvertClass *ShapeDrawer;
        bool IsDrawn;
        bool field_55;
        const ShapeFileStruct *ShapeData;
};
