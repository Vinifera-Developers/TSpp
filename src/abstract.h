/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          ABSTRACT.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Base class for all game world objects.
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
#include "irttitypeinfo.h"
#include "noinit.h"
#include "tibsun_defines.h"


class NoInitClass;
class HouseClass;
class WWCRCEngine;


class AbstractClass : public IPersistStream, public IRTTITypeInfo
{
    public:
        /**
         *  IUnknown
         */
        IFACEMETHOD(QueryInterface)(REFIID riid, LPVOID *ppvObj) override;
        IFACEMETHOD_(ULONG, AddRef)() override;
        IFACEMETHOD_(ULONG, Release)() override;

        /**
         *  IPersistStream
         */
        IFACEMETHOD_(LONG, IsDirty)();
        IFACEMETHOD_(LONG, GetSizeMax)(ULARGE_INTEGER *pcbSize);

    protected:
        /**
         *  #NOTE:
         *  These two are used as the real base Load/Save, but are not virtual.
         *  Ensure you call these directly if your class derives from Abstract and
         *  do not call AbstractClass::Save/Load or AbstractTypeClass::Save/Load
         *  directly as they are pure virtual and must be overridden!
         */
        HRESULT STDMETHODCALLTYPE Abstract_Load(IStream *pStm);
        HRESULT STDMETHODCALLTYPE Abstract_Save(IStream *pStm, BOOL fClearDirty);

    public:
        /**
         *  IRTTITypeInfo.
         */
        IFACEMETHOD_(int, What_Am_I)();
        IFACEMETHOD_(int, Fetch_ID)();
        IFACEMETHOD_(VOID, Create_ID)();

    public:
        AbstractClass();
        AbstractClass(const NoInitClass &noinit);
        virtual ~AbstractClass();

        virtual void Init();
        virtual void Detach(TARGET target, bool all = true);
        virtual RTTIType Kind_Of() const = 0;
        virtual int Size_Of(bool firestorm = false) const = 0;
        virtual int entry_34() const;
        virtual void Compute_CRC(WWCRCEngine &crc) const;
        virtual int Owner() const;
        virtual HouseClass *Owning_House() const;
        virtual int Get_Heap_ID() const;
        virtual bool Is_Inactive() const;
        virtual CoordStruct Center_Coord() const;
        virtual CoordStruct Target_Coord() const;
        virtual bool On_Ground() const;
        virtual bool In_Air() const;
        virtual CoordStruct entry_5C() const;       // As_Coord?
        virtual void AI();

        bool Is_Dirty() const { return Dirty; }

    protected:
        int ID;
        int HeapID;
        bool Dirty;

    private:
        // Copy and assignment not implemented; prevent their use by declaring as private.
        AbstractClass(const AbstractClass &);
        AbstractClass &operator=(const AbstractClass &);
};
