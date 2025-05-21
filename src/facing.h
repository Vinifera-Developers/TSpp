/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          FACING.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         General unit facing handler class.
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
#include "ttimer.h"
#include "ftimer.h"
#include "tibsun_defines.h"


class NoInitClass;


class FacingClass
{
    public:
        FacingClass();
        FacingClass(int rate);
        FacingClass(DirType &facing);
        FacingClass(Dir256 dir);
        FacingClass(FacingClass &that) :
            DesiredFacing(that.DesiredFacing),
            StartFacing(that.StartFacing),
            RotationTimer(that.RotationTimer),
            ROT(that.ROT)
        {
        }

        FacingClass(const NoInitClass &noinit);

        FacingClass & operator = (const FacingClass &that)
        {
            if (this != &that) {
                DesiredFacing = that.DesiredFacing;
                StartFacing = that.StartFacing;
                RotationTimer = that.RotationTimer;
                ROT = that.ROT;
            }
            return *this;
        }

        bool Set_Desired(const DirType &facing);
        bool Set(const DirType &facing);

        DirType Desired() const;
        DirType Current() const;

        bool Is_Rotating() const;
        bool Is_Rotating_CW() const;
        bool Is_Rotating_CCW() const;

        DirType Difference() const;
        DirType Difference(DirType &facing) const;

        void Set_ROT(int rate);

    public:
        DirType DesiredFacing;
        DirType StartFacing; // The starting direction from which to calcuate the rotation.
        CDTimerClass<FrameTimerClass> RotationTimer;
        DirType ROT;
};
