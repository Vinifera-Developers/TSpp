/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TUNNELLOCOMOTION.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Tunnel locomotion class.
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
#include "ttimer.h"
#include "ftimer.h"


class DECLSPEC_UUID("4A582743-9839-11D1-B709-00A024DDAFD1")
TunnelLocomotionClass : public LocomotionClass
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
        IFACEMETHOD_(MoveType, Can_Enter_Cell)(Cell cell);
        IFACEMETHOD_(bool, Is_To_Have_Shadow)();
        IFACEMETHOD_(Matrix3D, Draw_Matrix)(int *key);
        IFACEMETHOD_(VisualType, Visual_Character)(bool flag);
        IFACEMETHOD_(int, Z_Adjust)();
        IFACEMETHOD_(ZGradientType, Z_Gradient)();
        IFACEMETHOD_(bool, Process)();
        IFACEMETHOD_(void, Move_To)(Coordinate to);
        IFACEMETHOD_(void, Stop_Moving)();
        IFACEMETHOD_(void, Do_Turn)(DirStruct coord);
        IFACEMETHOD_(LayerType, In_Which_Layer)();
        IFACEMETHOD_(bool, Is_Moving_Now)();
        IFACEMETHOD_(FireErrorType, Can_Fire)();
        IFACEMETHOD_(bool, Is_Surfacing)();

    public:
        TunnelLocomotionClass();
        TunnelLocomotionClass(const NoInitClass &noinit);
        virtual ~TunnelLocomotionClass();

        /**
         *  LocomotionClass
         */
        virtual int Size_Of(bool firestorm = false) const override;

    public:

        typedef enum ProcessStateType
        {
            NORMAL,
            DIGGING_IN_START,
            DIGGING_IN_FINISH,
            DIGGING_DOWN,
            UNDERGROUND,
            DIGGING_UP,
            DIGGING_OUT,
            POST_DUG_OUT
        } ProcessStateType;

        ProcessStateType CurrentState;
        Coordinate DestinationCoord;
        CDRateTimerClass<FrameTimerClass> DigTimer;
        bool IsMoving;

    private:
        // copy and assignment not implemented; prevent their use by declaring as private.
        TunnelLocomotionClass(const TunnelLocomotionClass &);
        TunnelLocomotionClass &operator=(const TunnelLocomotionClass &);
};
