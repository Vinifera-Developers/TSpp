/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          DRIVELOCOMOTION.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Tracked locomotion class.
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
#include "ttimer.h"
#include "ftimer.h"


class DECLSPEC_UUID("4A582741-9839-11D1-B709-00A024DDAFD1")
DriveLocomotionClass : public LocomotionClass, public IPiggyback
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
        IFACEMETHOD(Save)(IStream *pStm, BOOL fClearDirty);

        /**
         *  ILocomotion
         */
        IFACEMETHOD_(bool, Is_Moving)();
        IFACEMETHOD_(Coordinate, Destination)();
        IFACEMETHOD_(Coordinate, Head_To_Coord)();
        IFACEMETHOD_(Matrix3D, Draw_Matrix)(int *key);
        IFACEMETHOD_(int, Z_Adjust)();
        IFACEMETHOD_(ZGradientType, Z_Gradient)();
        IFACEMETHOD_(bool, Process)();
        IFACEMETHOD_(void, Move_To)(Coordinate to);
        IFACEMETHOD_(void, Stop_Moving)();
        IFACEMETHOD_(void, Do_Turn)(DirStruct coord);
        IFACEMETHOD_(void, Unlimbo)();
        IFACEMETHOD_(void, Force_Track)(int track, Coordinate coord);
        IFACEMETHOD_(LayerType, In_Which_Layer)();
        IFACEMETHOD_(void, Force_New_Slope)(int ramp);
        IFACEMETHOD_(bool, Is_Moving_Now)();
        IFACEMETHOD_(void, Mark_All_Occupation_Bits)(int mark);
        IFACEMETHOD_(bool, Is_Moving_Here)(Coordinate to);
        IFACEMETHOD_(bool, Will_Jump_Tracks)();
        IFACEMETHOD_(void, Lock)();
        IFACEMETHOD_(void, Unlock)();
        IFACEMETHOD_(int, Get_Track_Number)();
        IFACEMETHOD_(int, Get_Track_Index)();
        IFACEMETHOD_(int, Get_Speed_Accum)();

        /**
         *  IPiggyback
         */
        IFACEMETHOD(Begin_Piggyback)(ILocomotion *pointer);
        IFACEMETHOD(End_Piggyback)(ILocomotion **pointer);
        IFACEMETHOD_(bool, Is_Ok_To_End)();
        IFACEMETHOD(Piggyback_CLSID)(CLSID *classid);
        IFACEMETHOD_(bool, Is_Piggybacking)();

    public:
        DriveLocomotionClass();
        DriveLocomotionClass(const NoInitClass &noinit);
        virtual ~DriveLocomotionClass();

        /**
         *  LocomotionClass
         */
        virtual int Size_Of(bool firestorm = false) const override;

        // 0047D370
        // 0047D460
        // 0047D4C0
        // 0047D830
        void Mark_Track(Coordinate &headto, MarkType type);
        bool Stop_Driver();
        bool Start_Driver(Coordinate &headto);
        bool While_Moving(bool a1 = false);
        bool Start_Of_Move(bool *a1 = nullptr, bool a2 = false, bool a3 = false);
        // 00481DC0
        Coordinate Smooth_Turn(Coordinate &adj, DirType &dir);
        bool Incoming(Cell cell); // 00481E50
        // 00481EE0

    public:
        int field_18; // current slope/ramp?
        int field_1C; // previous slope/ramp?
        CDRateTimerClass<FrameTimerClass> field_20;
        Coordinate DestinationCoord;
        Coordinate HeadToCoord;
        int SpeedAccum;
        double field_50; // slope related, speed adjuster/multiplier?
        int TrackNumber;
        int TrackIndex;
        bool IsOnShortTrack;
        bool IsTurretLockedDown;
        bool IsRotating;
        bool IsDriving;
        bool IsRocking;
        bool IsUnlocked;
        IPiggybackPtr *Piggybacker;

    private:
        // copy and assignment not implemented; prevent their use by declaring as private.
        DriveLocomotionClass(const DriveLocomotionClass &) = delete;
        DriveLocomotionClass &operator=(const DriveLocomotionClass &) = delete;
};
