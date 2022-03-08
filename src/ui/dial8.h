/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          DIAL8.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Dial gadget with 8 directions.
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

#include "gcntrl.h"


class Dial8Class : public ControlClass
{
    public:
        Dial8Class(int id, int x, int y, int w, int h, DirType dir);
        virtual ~Dial8Class();

        virtual bool Draw_Me(bool forced = false) override;
        virtual bool Action(unsigned flags, KeyNumType &key) override;

        DirType Get_Direction() const;
        void Set_Direction(DirType dir);

    public:
        int FaceX;
        int FaceY;
        int FacePoint[8][2];
        int FaceLine[8][2];
        DirType Direction;
        FacingType Facing;
        FacingType OldFacing;
};
