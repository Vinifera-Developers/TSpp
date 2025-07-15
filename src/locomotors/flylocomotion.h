/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          FLYLOCOMOTION.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Flyer locomotion class.
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


class DECLSPEC_UUID("4A582746-9839-11D1-B709-00A024DDAFD1")
FlyLocomotionClass : public LocomotionClass
{
    public:
        /**
         *  IUnknown
         */
        IFACEMETHOD(QueryInterface)(REFIID riid, LPVOID *ppvObj);
        IFACEMETHOD_(ULONG, AddRef)();
        IFACEMETHOD_(ULONG, Release)();

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
        IFACEMETHOD_(Matrix3D, Draw_Matrix)(int *key);
        IFACEMETHOD_(Matrix3D, Shadow_Matrix)(int *key);
        IFACEMETHOD_(Point2D, Draw_Point)();
        IFACEMETHOD_(Point2D, Shadow_Point)();
        IFACEMETHOD_(bool, Process)();
        IFACEMETHOD_(void, Move_To)(Coord to);
        IFACEMETHOD_(void, Stop_Moving)();
        IFACEMETHOD_(void, Do_Turn)(DirType coord);
        IFACEMETHOD_(bool, Power_Off)();
        IFACEMETHOD_(bool, Is_Powered)();
        IFACEMETHOD_(bool, Is_Ion_Sensitive)();
        IFACEMETHOD_(LayerType, In_Which_Layer)();
        IFACEMETHOD_(bool, Is_Moving_Now)();
        IFACEMETHOD_(int, Apparent_Speed)();
        IFACEMETHOD_(int, Get_Status)();
        IFACEMETHOD_(void, Acquire_Hunter_Seeker_Target)();

    public:
        FlyLocomotionClass();
        FlyLocomotionClass(const NoInitClass &noinit);
        virtual ~FlyLocomotionClass();

        /**
         *  LocomotionClass
         */
        virtual int Get_Object_Size(bool firestorm = false) const override;

        // 00499CA0
        // 00499E40
        // 00499F20
        // 0049AFE0
        // 0049B0D0
        // 0049B1A0
        // 0049B360
        // 0049BBA0
        // 0049CB00
        // 0049CBA0
        // 0049CCE0
        // 0049CE70
        // 0049D210
        // 0049D2D0

    public:
        Coord DestinationCoord;
        Coord HeadToCoord;
        bool IsMoving;
        int FlightLevel;
        double TargetSpeed;
        double CurrentSpeed;
        bool IsTakingOff;
        bool IsLanding;
        bool WasLanding;
        bool field_4B;
        int field_4C;
        int field_50;
        bool IsElevating;

    private:
        // copy and assignment not implemented; prevent their use by declaring as private.
        FlyLocomotionClass(const FlyLocomotionClass &) = delete;
        FlyLocomotionClass &operator=(const FlyLocomotionClass &) = delete;
};
