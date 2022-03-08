/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WALKLOCOMOTION.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Walker locomotion class.
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


class DECLSPEC_UUID("4A582744-9839-11D1-B709-00A024DDAFD1")
WalkLocomotionClass : public LocomotionClass, public IPiggyback
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
        IFACEMETHOD_(bool, Process)();
        IFACEMETHOD_(void, Move_To)(Coordinate to);
        IFACEMETHOD_(void, Stop_Moving)();
        IFACEMETHOD_(void, Do_Turn)(DirStruct coord);
        IFACEMETHOD_(LayerType, In_Which_Layer)();
        IFACEMETHOD_(void, Force_Immediate_Destination)(Coordinate coord);
        IFACEMETHOD_(bool, Is_Moving_Now)();
        IFACEMETHOD_(void, Mark_All_Occupation_Bits)(int mark);
        IFACEMETHOD_(bool, Is_Moving_Here)(Coordinate to);
        IFACEMETHOD_(bool, Is_Really_Moving_Now)();
        IFACEMETHOD_(void, Stop_Movement_Animation)();

        /**
         *  IPiggyback
         */
        IFACEMETHOD(Begin_Piggyback)(ILocomotion *pointer);
        IFACEMETHOD(End_Piggyback)(ILocomotion **pointer);
        IFACEMETHOD_(bool, Is_Ok_To_End)();
        IFACEMETHOD(Piggyback_CLSID)(CLSID *classid);
        IFACEMETHOD_(bool, Is_Piggybacking)();

    public:
        WalkLocomotionClass();
        WalkLocomotionClass(const NoInitClass &noinit);
        virtual ~WalkLocomotionClass();

        /**
         *  LocomotionClass
         */
        virtual int Size_Of(bool firestorm = false) const override;

        void Internal_Process(bool a2 = false);
        bool func_66E170(Coordinate &coord);

    public:
        Coordinate DestinationCoord;
        Coordinate HeadToCoord;
        bool IsMoving;
        bool field_31; // flagged when "processing" walking.
        bool IsReallyMoving;
        IPiggybackPtr Piggybacker;

    private:
        // copy and assignment not implemented; prevent their use by declaring as private.
        WalkLocomotionClass(const WalkLocomotionClass &);
        WalkLocomotionClass &operator=(const WalkLocomotionClass &);
};
