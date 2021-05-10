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


typedef enum DropPodDirType
{
    DPOD_DIR_NE,
    DPOD_DIR_NW,
    DPOD_DIR_SE,
    DPOD_DIR_SW,
} DropPodDirType;


class DECLSPEC_UUID("4A582747-9839-11D1-B709-00A024DDAFD1")
DropPodLocomotionClass : public LocomotionClass, public IPiggyback
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
        IFACEMETHOD_(CoordStruct, Destination)();
        IFACEMETHOD_(bool, Process)();
        IFACEMETHOD_(void, Move_To)(CoordStruct to);
        IFACEMETHOD_(void, Stop_Moving)();
        IFACEMETHOD_(LayerType, In_Which_Layer)();
        IFACEMETHOD_(int, Drawing_Code)();
        
        /**
         *  IPiggyback
         */
        IFACEMETHOD(Begin_Piggyback)(ILocomotion *pointer);
        IFACEMETHOD(End_Piggyback)(ILocomotion **pointer);
        IFACEMETHOD_(bool, Is_Ok_To_End)();
        IFACEMETHOD(Piggyback_CLSID)(CLSID *classid);
        IFACEMETHOD_(bool, Is_Piggybacking)();

    public:
        DropPodLocomotionClass();
        DropPodLocomotionClass(const NoInitClass &noinit);
        virtual ~DropPodLocomotionClass();

        /**
         *  LocomotionClass
         */
        virtual int Size_Of(bool firestorm = false) const override;

    protected:
        DropPodDirType field_18;
        CoordStruct DestinationCoord;
        IPiggybackPtr Piggybacker;

    private:
        // copy and assignment not implemented; prevent their use by declaring as private.
        DropPodLocomotionClass(const DropPodLocomotionClass &);
        DropPodLocomotionClass &operator=(const DropPodLocomotionClass &);
};
