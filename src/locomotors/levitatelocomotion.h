/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          DROPPODLOCOMOTION.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Drop pod locomotion class.
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


class DECLSPEC_UUID("3DC0B295-6546-11D3-80B0-00902792494C")
LevitateLocomotionClass : public LocomotionClass
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
        IFACEMETHOD(Link_To_Object)(void *object);
        IFACEMETHOD_(bool, Is_Moving)();
        IFACEMETHOD_(Coord, Destination)();
        IFACEMETHOD_(Coord, Head_To_Coord)();
        IFACEMETHOD_(bool, Process)();
        IFACEMETHOD_(LayerType, In_Which_Layer)();
        IFACEMETHOD_(bool, Is_Moving_Now)();
        IFACEMETHOD_(void, Mark_All_Occupation_Bits)(MarkType mark);

    public:
        LevitateLocomotionClass();
        LevitateLocomotionClass(const NoInitClass &noinit);
        virtual ~LevitateLocomotionClass();

        /**
         *  LocomotionClass
         */
        virtual int Get_Object_Size(bool firestorm = false) const override;

    public:
        int field_14; // State?
        double field_18; // CurrentVelocity?
        double field_20; // DeltaX?
        double field_28; // DeltaY?
        double field_30; // AccelerationDurationCosinus?
        double field_38; // AccelerationDurationNegSinus?
        int field_40; // AccelerationDuration?
        int field_44; // BlocksCounter?
        double field_48; // CurrentSpeed?
        double field_50; // Dampen?
        double field_58;

    private:
        // copy and assignment not implemented; prevent their use by declaring as private.
        LevitateLocomotionClass(const LevitateLocomotionClass &);
        LevitateLocomotionClass &operator=(const LevitateLocomotionClass &);
};
