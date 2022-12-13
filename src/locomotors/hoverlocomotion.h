/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          HOVERLOCOMOTION.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Hover locomotion class.
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
#include "facing.h"


class DECLSPEC_UUID("4A582742-9839-11D1-B709-00A024DDAFD1")
HoverLocomotionClass : public LocomotionClass
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
        IFACEMETHOD_(Matrix3D, Draw_Matrix)(int *key);
        IFACEMETHOD_(bool, Process)();
        IFACEMETHOD_(void, Move_To)(Coordinate to);
        IFACEMETHOD_(void, Stop_Moving)();
        IFACEMETHOD_(void, Do_Turn)(DirStruct coord);
        IFACEMETHOD_(bool, Power_Off)();
        IFACEMETHOD_(bool, Is_Powered)();
        IFACEMETHOD_(bool, Is_Ion_Sensitive)();
        IFACEMETHOD_(bool, Push)(DirStruct dir);
        IFACEMETHOD_(bool, Shove)(DirStruct dir);
        IFACEMETHOD_(LayerType, In_Which_Layer)();
        IFACEMETHOD_(bool, Is_Moving_Now)();
        IFACEMETHOD_(void, Mark_All_Occupation_Bits)(MarkType mark);
        IFACEMETHOD_(bool, Is_Moving_Here)(Coordinate to);

    public:
        HoverLocomotionClass();
        HoverLocomotionClass(const NoInitClass &noinit);
        virtual ~HoverLocomotionClass();

        /**
         *  LocomotionClass
         */
        virtual int Size_Of(bool firestorm = false) const override;

    public:
        Coordinate DestinationCoord;
        Coordinate HeadToCoord;
        FacingClass Facing;
        double field_48;
        double field_50;
        double field_58;
        double field_60;
        bool field_68;
        int field_6C;
        bool field_70;

    private:
        // copy and assignment not implemented; prevent their use by declaring as private.
        HoverLocomotionClass(const HoverLocomotionClass &) = delete;
        HoverLocomotionClass &operator=(const HoverLocomotionClass &) = delete;
};
