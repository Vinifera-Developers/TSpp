/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          PCXIMGBTN.H
 *
 *  @authors       CCHyper
 *
 *  @brief         PCX image button.
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


class BSurface;


class PCXButtonClass : public ToggleClass
{
    public:
        PCXButtonClass();
        PCXButtonClass(unsigned id, const char *image_fname, int x, int y, int w = -1, int h = -1);
        ~PCXButtonClass();

        virtual bool Draw_Me(bool forced = false) override;

        bool Load_Image(const char *filename);

    public:
        BSurface *ImageSurface;
};
