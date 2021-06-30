/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          JUMPJETLOCOMOTION.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Jumpjet locomotion class.
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

#include "locomotion.h"
#include "ipiggyback.h"
#include "tibsun_defines.h"
#include "facing.h"


class DECLSPEC_UUID("92612C46-F71F-11D1-AC9F-006008055BB5")
JumpjetLocomotionClass : public LocomotionClass
{
    public:
        /**
         *  IPersist
         */
        IFACEMETHOD(GetClassID)(CLSID *pClassID);

        /**
         *  IPersistStream
         */
        IFACEMETHOD(Load)(IStream *pStm);

        /**
         *  ILocomotion
         */
        IFACEMETHOD_(bool, Is_Moving)();
        IFACEMETHOD_(Coordinate, Destination)();
        IFACEMETHOD_(Coordinate, Head_To_Coord)();
        IFACEMETHOD_(bool, Process)();
        IFACEMETHOD_(void, Move_To)(Coordinate to);
        IFACEMETHOD_(void, Stop_Moving)();
        IFACEMETHOD_(void, Do_Turn)(DirStruct coord);
        IFACEMETHOD_(LayerType, In_Which_Layer)();
        IFACEMETHOD_(bool, Is_Moving_Now)();
        IFACEMETHOD_(void, Mark_All_Occupation_Bits)(int mark);

    public:
        JumpjetLocomotionClass();
        JumpjetLocomotionClass(const NoInitClass &noinit);
        virtual ~JumpjetLocomotionClass();

        /**
         *  LocomotionClass
         */
        virtual int Size_Of(bool firestorm = false) const override;

    public:
        Coordinate HeadToCoord;
        bool IsMoving;
        int field_24;
        FacingClass Facing;
        double field_40;
        double field_48;
        int field_50;
        double field_58;
        bool field_60;

    private:
        // copy and assignment not implemented; prevent their use by declaring as private.
        JumpjetLocomotionClass(const JumpjetLocomotionClass &);
        JumpjetLocomotionClass &operator=(const JumpjetLocomotionClass &);
};
