/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          MECHLOCOMOTION.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Mech locomotion class.
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


class DECLSPEC_UUID("55D141B8-DB94-11D1-AC98-006008055BB5")
MechLocomotionClass : public LocomotionClass
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
        IFACEMETHOD_(Coord, Destination)();
        IFACEMETHOD_(Coord, Head_To_Coord)();
        IFACEMETHOD_(bool, Process)();
        IFACEMETHOD_(void, Move_To)(Coord to);
        IFACEMETHOD_(void, Stop_Moving)();
        IFACEMETHOD_(void, Do_Turn)(DirType coord);
        IFACEMETHOD_(LayerType, In_Which_Layer)();
        IFACEMETHOD_(void, Force_Immediate_Destination)(Coord coord);
        IFACEMETHOD_(bool, Is_Moving_Now)();
        IFACEMETHOD_(void, Mark_All_Occupation_Bits)(MarkType mark);
        IFACEMETHOD_(bool, Is_Moving_Here)(Coord to);

    public:
        MechLocomotionClass();
        MechLocomotionClass(const NoInitClass &noinit);
        virtual ~MechLocomotionClass();

        /**
         *  LocomotionClass
         */
        virtual int Get_Object_Size(bool firestorm = false) const override;

    public:
        Coord DestinationCoord;
        Coord HeadToCoord;

    private:
        // copy and assignment not implemented; prevent their use by declaring as private.
        MechLocomotionClass(const MechLocomotionClass &);
        MechLocomotionClass &operator=(const MechLocomotionClass &);
};
