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

#include "ftimer.h"
#include "ipiggyback.h"
#include "locomotion.h"
#include "tibsun_defines.h"
#include "ttimer.h"


class DECLSPEC_UUID("4A582741-9839-11D1-B709-00A024DDAFD1")
DriveLocomotionClass : public LocomotionClass, public IPiggyback
{
public:
    /**
     *  IUnknown
     */
    IFACEMETHOD(QueryInterface)(REFIID riid, LPVOID* ppvObj);
    IFACEMETHOD_(ULONG, AddRef)();
    IFACEMETHOD_(ULONG, Release)();

    /**
     *  IPersist
     */
    IFACEMETHOD(GetClassID)(CLSID* pClassID);

    /**
     *  IPersistStream
     */
    IFACEMETHOD(Load)(IStream* pStm);
    IFACEMETHOD(Save)(IStream* pStm, BOOL fClearDirty);

    /**
     *  ILocomotion
     */
    IFACEMETHOD_(bool, Is_Moving)();
    IFACEMETHOD_(Coord, Destination)();
    IFACEMETHOD_(Coord, Head_To_Coord)();
    IFACEMETHOD_(Matrix3D, Draw_Matrix)(int* key);
    IFACEMETHOD_(int, Z_Adjust)();
    IFACEMETHOD_(ZGradientType, Z_Gradient)();
    IFACEMETHOD_(bool, Process)();
    IFACEMETHOD_(void, Move_To)(Coord to);
    IFACEMETHOD_(void, Stop_Moving)();
    IFACEMETHOD_(void, Do_Turn)(DirType coord);
    IFACEMETHOD_(void, Unlimbo)();
    IFACEMETHOD_(void, Force_Track)(int track, Coord coord);
    IFACEMETHOD_(LayerType, In_Which_Layer)();
    IFACEMETHOD_(void, Force_New_Slope)(TileRampType ramp);
    IFACEMETHOD_(bool, Is_Moving_Now)();
    IFACEMETHOD_(void, Mark_All_Occupation_Bits)(MarkType mark);
    IFACEMETHOD_(bool, Is_Moving_Here)(Coord to);
    IFACEMETHOD_(bool, Will_Jump_Tracks)();
    IFACEMETHOD_(void, Lock)();
    IFACEMETHOD_(void, Unlock)();
    IFACEMETHOD_(int, Get_Track_Number)();
    IFACEMETHOD_(int, Get_Track_Index)();
    IFACEMETHOD_(int, Get_Speed_Accum)();

    /**
     *  IPiggyback
     */
    IFACEMETHOD(Begin_Piggyback)(ILocomotion* pointer);
    IFACEMETHOD(End_Piggyback)(ILocomotion** pointer);
    IFACEMETHOD_(bool, Is_Ok_To_End)();
    IFACEMETHOD(Piggyback_CLSID)(CLSID* classid);
    IFACEMETHOD_(bool, Is_Piggybacking)();

public:
    DriveLocomotionClass();
    DriveLocomotionClass(const NoInitClass& noinit);
    virtual ~DriveLocomotionClass();

    /**
     *  LocomotionClass
     */
    virtual int Get_Object_Size(bool firestorm = false) const override;

    // 0047D370
    // 0047D460
    // 0047D4C0
    // 0047D830
    void Mark_Track(Coord& headto, MarkType type);
    bool Stop_Driver();
    bool Start_Driver(Coord& headto);
    bool While_Moving(bool a1 = false);
    bool Start_Of_Move(bool* a1 = nullptr, bool a2 = false, bool a3 = false);
    // 00481DC0
    Coord Smooth_Turn(Coord& adj, Dir256& dir);
    bool Incoming(Cell cell); // 00481E50
    // 00481EE0

public:
    TileRampType CurrentRamp;
    TileRampType PreviousRamp;
    CDRateTimerClass<FrameTimerClass> RampTransitionTimer;
    Coord DestinationCoord;
    Coord HeadToCoord;
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
    ILocomotionPtr Piggybacker;

private:
    // copy and assignment not implemented; prevent their use by declaring as private.
    DriveLocomotionClass(const DriveLocomotionClass&) = delete;
    DriveLocomotionClass& operator=(const DriveLocomotionClass&) = delete;
};
