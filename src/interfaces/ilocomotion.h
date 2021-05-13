/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          ILOCOMOTION.H
 *
 *  @authors       CCHyper
 *
 *  @brief         ILocomotion interface.
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
#include "matrix3d.h"
#include "tibsun_defines.h"
#include <comdef.h>
#include <unknwn.h>


class Point2D;
struct DirStruct;

enum MoveType;
enum VisualType;
enum ZGradientType;
enum LayerType;
enum FireErrorType;


/*******************************************************************************
 *  @class   ILocomotion
 *
 *  @brief   Game object locomotion handler.
 */
DECLARE_INTERFACE_IID_(ILocomotion, IUnknown, "070F3290-9841-11D1-B709-00A024DDAFD1")
{
    /**
     *  Links object to locomotor.
     */
    STDMETHOD(Link_To_Object)(void *object) PURE;

    /**
     *  Sees if object is moving.
     */
    STDMETHOD_(bool, Is_Moving)() PURE;

    /**
     *  Fetches destination coordinate.
     */
    STDMETHOD_(Coordinate, Destination)() PURE;

    /**
     *  Fetches immediate (next cell) destination coordinate.
     */
    STDMETHOD_(Coordinate, Head_To_Coord)() PURE;

    /**
     *  Determine if specific cell can be entered.
     */
    STDMETHOD_(MoveType, Can_Enter_Cell)(Cell cell) PURE;

    /**
     *  Should object cast a shadow?
     */
    STDMETHOD_(bool, Is_To_Have_Shadow)() PURE;

    /**
     *  Fetch voxel draw matrix.
     */
    STDMETHOD_(Matrix3D, Draw_Matrix)(int *key) PURE;

    /**
     *  Fetch shadow draw matrix.
     */
    STDMETHOD_(Matrix3D, Shadow_Matrix)(int *key) PURE;

    /**
     *  Draw point center location.
     */
    STDMETHOD_(Point2D, Draw_Point)() PURE;

    /**
     *  Shadow draw point center location.
     */
    STDMETHOD_(Point2D, Shadow_Point)() PURE;

    /**
     *  Visual character for drawing.
     */
    STDMETHOD_(VisualType, Visual_Character)(bool flag) PURE;

    /**
     *  Z adjust control value.
     */
    STDMETHOD_(int, Z_Adjust)() PURE;

    /**
     *  Z gradient control value.
     */
    STDMETHOD_(ZGradientType, Z_Gradient)() PURE;

    /**
     *  Process movement of object.
     */
    STDMETHOD_(bool, Process)() PURE;

    /**
     *  Instruct to move to location specified.
     */
    STDMETHOD_(void, Move_To)(Coordinate to) PURE;

    /**
     *  Stop moving at first opportunity.
     */
    STDMETHOD_(void, Stop_Moving)() PURE;

    /**
     *  Try to face direction specified.
     */
    STDMETHOD_(void, Do_Turn)(DirStruct coord) PURE;

    /**
     *  Object is appearing in the world.
     */
    STDMETHOD_(void, Unlimbo)() PURE;

    /**
     *  Special tilting AI function.
     */
    STDMETHOD_(void, Tilt_Pitch_AI)() PURE;

    /**
     *  Locomotor becomes powered.
     */
    STDMETHOD_(bool, Power_On)() PURE;

    /**
     *  Locomotor loses power.
     */
    STDMETHOD_(bool, Power_Off)() PURE;

    /**
     *  Is locomotor powered?
     */
    STDMETHOD_(bool, Is_Powered)() PURE;

    /**
     *  Is locomotor sensitive to ion storms?
     */
    STDMETHOD_(bool, Is_Ion_Sensitive)() PURE;

    /**
     *  Push object in direction specified.
     */
    STDMETHOD_(bool, Push)(DirStruct dir) PURE;

    /**
     *  Shove object (with spin) in direction specified.
     */
    STDMETHOD_(bool, Shove)(DirStruct dir) PURE;

    /**
     *  Force drive track -- special case only.
     */
    STDMETHOD_(void, Force_Track)(int track, Coordinate coord) PURE;

    /**
     *  What display layer is it located in.
     */
    STDMETHOD_(LayerType, In_Which_Layer)() PURE;

    /**
     *  Force object to destination (no processing). NOTE: Don't use this function!
     */
    STDMETHOD_(void, Force_Immediate_Destination)(Coordinate coord) PURE;

    /**
     *  Force a voxel unit to a given slope. Used in cratering.
     */
    STDMETHOD_(void, Force_New_Slope)(int ramp) PURE;

    /**
     *  Is it actually moving across the ground this very second?
     */
    STDMETHOD_(bool, Is_Moving_Now)() PURE;

    /**
     *  Actual current speed of object expressed as leptons per game frame.
     */
    STDMETHOD_(int, Apparent_Speed)() PURE;

    /**
     *  Special drawing feedback code (locomotor specific meaning).
     */
    STDMETHOD_(int, Drawing_Code)() PURE;

    /**
     *  Queries if any locomotor specific state prevents the object from firing.
     */
    STDMETHOD_(FireErrorType, Can_Fire)() PURE;

    /**
     *  Queries the general state of the locomotor.
     */
    STDMETHOD_(int, Get_Status)() PURE;

    /**
     *  Forces a hunter seeker droid to find a target.
     */
    STDMETHOD_(void, Acquire_Hunter_Seeker_Target)() PURE;

    /**
     *  Is this object surfacing?
     */
    STDMETHOD_(bool, Is_Surfacing)() PURE;

    /**
     *  Lifts all occupation bits associated with the object off the map.
     */
    STDMETHOD_(void, Mark_All_Occupation_Bits)(int mark) PURE;

    /**
     *  Is this object in the process of moving into this coord.
     */
    STDMETHOD_(bool, Is_Moving_Here)(Coordinate to) PURE;

    /**
     *  Will this object jump tracks?
     */
    STDMETHOD_(bool, Will_Jump_Tracks)() PURE;

    /**
     *  Infantry moving query function.
     */
    STDMETHOD_(bool, Is_Really_Moving_Now)() PURE;

    /**
     *  Falsifies the IsReallyMoving flag in WalkLocomotionClass.
     */
    STDMETHOD_(void, Stop_Movement_Animation)() PURE;

    /**
     *  Locks the locomotor from being deleted.
     */
    STDMETHOD_(void, Lock)() PURE;

    /**
     *  Unlocks the locomotor from being deleted.
     */
    STDMETHOD_(void, Unlock)() PURE;

    /**
     *  Queries internal variables.
     */
    STDMETHOD_(int, Get_Track_Number)() PURE;

    /**
     *  Queries internal variables.
     */
    STDMETHOD_(int, Get_Track_Index)() PURE;

    /**
     *  Queries internal variables.
     */
    STDMETHOD_(int, Get_Speed_Accum)() PURE;
};


/**
 *  ILocomtion com smart pointer declaration.
 */
_COM_SMARTPTR_TYPEDEF(ILocomotion, __uuidof(ILocomotion));
