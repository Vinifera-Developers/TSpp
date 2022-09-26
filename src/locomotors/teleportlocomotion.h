/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TELEPORTLOCOMOTION.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Teleport locomotion class.
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


class DECLSPEC_UUID("4A582747-9839-11D1-B709-00A024DDAFD1")
TeleportLocomotionClass : public LocomotionClass
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
        IFACEMETHOD_(bool, Process)();
        IFACEMETHOD_(void, Move_To)(Coordinate to);
        IFACEMETHOD_(void, Stop_Moving)();
        IFACEMETHOD_(LayerType, In_Which_Layer)();

    public:
        TeleportLocomotionClass();
        TeleportLocomotionClass(const NoInitClass &noinit);
        virtual ~TeleportLocomotionClass();

        /**
         *  LocomotionClass
         */
        virtual int Size_Of(bool firestorm = false) const override;

        /**
         *  TeleportLocomotionClass
         */
        virtual bool Is_Stationary() const;

    public:
        Coordinate DestinationCoord;

    private:
        // copy and assignment not implemented; prevent their use by declaring as private.
        TeleportLocomotionClass(const TeleportLocomotionClass &);
        TeleportLocomotionClass &operator=(const TeleportLocomotionClass &);
};
