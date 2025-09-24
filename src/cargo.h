/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CARGO.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class that handles the basic cargo logic.
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
#include "noinit.h"


class FootClass;
enum RTTIType;


class CargoClass
{
public:
    CargoClass();
    CargoClass(const NoInitClass& noinit);
    ~CargoClass();

    void AI();

    int How_Many() const { return Quantity; }
    bool Is_Something_Attached() const { return CargoHold != nullptr; }
    FootClass* Attached_Object() const;
    FootClass* Detach_Object();
    void Attach(FootClass* object);
    void Detach(FootClass* object);

    /**
     *  New methods to allow for more precise manipulations.
     */
    int How_Many(RTTIType rtti) const;
    bool Is_Something_Attached(RTTIType rtti) const;
    FootClass* Attached_Object(RTTIType rtti) const;
    FootClass* Detach_Object(RTTIType rtti);

public:
    unsigned Quantity;
    FootClass* CargoHold;
};
