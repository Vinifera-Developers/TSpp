/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SWIZZLE.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Pointer swizzling interface for save/load.
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
#include "iswizzle.h"
#include "vector.h"


class SwizzleManagerClass : public ISwizzle
{
public:
    struct SwizzlePointerStruct {
        SwizzlePointerStruct() : ID(0), Pointer(nullptr) {}
        SwizzlePointerStruct(LONG id, void* pointer) : ID(id), Pointer(pointer) {}
        ~SwizzlePointerStruct() {}

        void operator=(const SwizzlePointerStruct& that)
        {
            ID = that.ID;
            Pointer = that.Pointer;
        }

        bool operator==(const SwizzlePointerStruct& that) const { return ID == that.ID; }
        bool operator!=(const SwizzlePointerStruct& that) const { return ID != that.ID; }
        bool operator<(const SwizzlePointerStruct& that) const { return ID < that.ID; }
        bool operator>(const SwizzlePointerStruct& that) const { return ID > that.ID; }

        LONG ID;
        void* Pointer;
    };

public:
    /**
     *  IUnknown
     */
    IFACEMETHOD(QueryInterface)(REFIID riid, LPVOID* ppvObj);
    IFACEMETHOD_(ULONG, AddRef)();
    IFACEMETHOD_(ULONG, Release)();

    /**
     *  ISwizzle
     */
    IFACEMETHOD_(LONG, Reset)();
    IFACEMETHOD_(LONG, Swizzle)(void** pointer);
    IFACEMETHOD_(LONG, Fetch_Swizzle_ID)(void* pointer, LONG* id);
    IFACEMETHOD_(LONG, Here_I_Am)(LONG id, void* pointer);
    IFACEMETHOD(Save_Interface)(IStream* stream, IUnknown* pointer);
    IFACEMETHOD(Load_Interface)(IStream* stream, CLSID* riid, void** pointer);
    IFACEMETHOD_(LONG, Get_Save_Size)(LONG* size);

public:
    SwizzleManagerClass();
    ~SwizzleManagerClass();

    void Process_Tables();

public:
    DynamicVectorClass<SwizzlePointerStruct> RequestTable;
    DynamicVectorClass<SwizzlePointerStruct> PointerTable;
};
