/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          LOCOMOTION.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Base locomotion class.
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
#include "ilocomotion.h"
#include "tibsun_defines.h"


class NoInitClass;
class TechnoClass;
class FootClass;


class LocomotionClass : public IPersistStream, public ILocomotion
{
    public:
        /**
         *  IUnknown
         */
        IFACEMETHOD(QueryInterface)(REFIID riid, LPVOID *ppvObj);
        IFACEMETHOD_(ULONG, AddRef)();
        IFACEMETHOD_(ULONG, Release)();
        
        /**
         *  IPersistStream
         */
        IFACEMETHOD_(LONG, IsDirty)();
        IFACEMETHOD(Save)(IStream *pStm, BOOL fClearDirty);
        IFACEMETHOD_(LONG, GetSizeMax)(ULARGE_INTEGER *pcbSize);

        /**
         *  ILocomotion
         */
        IFACEMETHOD(Link_To_Object)(void *object);
        IFACEMETHOD_(bool, Is_Moving)();
        IFACEMETHOD_(Coordinate, Destination)();
        IFACEMETHOD_(Coordinate, Head_To_Coord)();
        IFACEMETHOD_(MoveType, Can_Enter_Cell)(Cell cell);
        IFACEMETHOD_(bool, Is_To_Have_Shadow)();
        IFACEMETHOD_(Matrix3D, Draw_Matrix)(int *key);
        IFACEMETHOD_(Matrix3D, Shadow_Matrix)(int *key);
        IFACEMETHOD_(Point2D, Draw_Point)();
        IFACEMETHOD_(Point2D, Shadow_Point)();
        IFACEMETHOD_(VisualType, Visual_Character)(bool flag);
        IFACEMETHOD_(int, Z_Adjust)();
        IFACEMETHOD_(ZGradientType, Z_Gradient)();
        IFACEMETHOD_(bool, Process)();
        IFACEMETHOD_(void, Move_To)(Coordinate to);
        IFACEMETHOD_(void, Stop_Moving)();
        IFACEMETHOD_(void, Do_Turn)(DirStruct coord);
        IFACEMETHOD_(void, Unlimbo)();
        IFACEMETHOD_(void, Tilt_Pitch_AI)();
        IFACEMETHOD_(bool, Power_On)();
        IFACEMETHOD_(bool, Power_Off)();
        IFACEMETHOD_(bool, Is_Powered)();
        IFACEMETHOD_(bool, Is_Ion_Sensitive)();
        IFACEMETHOD_(bool, Push)(DirStruct dir);
        IFACEMETHOD_(bool, Shove)(DirStruct dir);
        IFACEMETHOD_(void, Force_Track)(int track, Coordinate coord);
        IFACEMETHOD_(void, Force_Immediate_Destination)(Coordinate coord);
        IFACEMETHOD_(void, Force_New_Slope)(int ramp);
        IFACEMETHOD_(bool, Is_Moving_Now)();
        IFACEMETHOD_(int, Apparent_Speed)();
        IFACEMETHOD_(int, Drawing_Code)();
        IFACEMETHOD_(FireErrorType, Can_Fire)();
        IFACEMETHOD_(int, Get_Status)();
        IFACEMETHOD_(void, Acquire_Hunter_Seeker_Target)();
        IFACEMETHOD_(bool, Is_Surfacing)();
        IFACEMETHOD_(void, Mark_All_Occupation_Bits)(int mark);
        IFACEMETHOD_(bool, Is_Moving_Here)(Coordinate to);
        IFACEMETHOD_(bool, Will_Jump_Tracks)();
        IFACEMETHOD_(bool, Is_Really_Moving_Now)();
        IFACEMETHOD_(void, Stop_Movement_Animation)();
        IFACEMETHOD_(void, Lock)();
        IFACEMETHOD_(void, Unlock)();
        IFACEMETHOD_(int, Get_Track_Number)();
        IFACEMETHOD_(int, Get_Track_Index)();
        IFACEMETHOD_(int, Get_Speed_Accum)();

        /**
         *  Fetch the raw pointer to the linked object, casted to FootClass.
         */
        FootClass *Linked_To() const;

    public:
        LocomotionClass();
        LocomotionClass(const NoInitClass &noinit);
        virtual ~LocomotionClass();

        virtual int Size_Of(bool firestorm = false) const = 0;

    protected:
        /**
         *  #NOTE:
         *  Non virtual override of IPersistStream::ILoad() to ensure derived classes
         *  implement their own version, while making sure we handle the main locomotor
         *  pointer at the start of the stream.
         */
        HRESULT STDMETHODCALLTYPE Locomotion_Load(IStream *pStm);

    protected:
        TechnoClass *LinkedTo;
        bool IsPowered;
        bool Dirty;
        LONG RefCount;

    private:
        LocomotionClass(const LocomotionClass &) = delete;
        LocomotionClass &operator=(const LocomotionClass &) = delete;
};


/**
 *  IPersist and IPersistStream com smart pointer declaration.
 */
_COM_SMARTPTR_TYPEDEF(IPersist, __uuidof(IPersist));
//typedef _com_ptr_t<_com_IIID<IPersist, __uuidof(IPersist)> > IPersistPtr;

_COM_SMARTPTR_TYPEDEF(IPersistStream, __uuidof(IPersistStream));
//typedef _com_ptr_t<_com_IIID<IPersistStream, __uuidof(IPersistStream)> > IPersistStreamPtr;
