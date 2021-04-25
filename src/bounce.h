/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          BOUNCE.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Anim/object bouncing physics.
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

#include "vector3.h"
#include "quat.h"


class NoInitClass;


class BounceClass
{
    public:
        BounceClass();
        BounceClass(const NoInitClass &noinit);
        ~BounceClass();

        // 004245B0
        // 00424700
        // 004248C0
        // 00424900
        // 00424930
        // 00424A20

    public:
        double Elasticity;
        double field_8;
        double field_10;
        Vector3 Coords;
        Vector3 field_24; // some sort of steps for Coords, maybe velocity.
        Quaternion field_30; // quaternion made from angle
        Quaternion field_40; // quaternion made from angular 

    private:
        // copy and assignment not implemented; prevent their use by declaring as private.
        BounceClass(const BounceClass &) = delete;
        BounceClass &operator=(const BounceClass &) = delete;
};
