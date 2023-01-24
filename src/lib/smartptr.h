/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SMARTPTR.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Basic smart pointer implementation.
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
#include "noinit.h"
#include "tspp_assert.h"


template<class T>
class SmartPtr
{
    public:
        SmartPtr(const NoInitClass &) {}
        SmartPtr(T * realptr = nullptr) : Pointer(realptr) {}
        SmartPtr(const SmartPtr & rvalue) : Pointer(rvalue.Pointer) {}
        ~SmartPtr() { Pointer = nullptr; }

        operator T * () const { return Pointer; }

        operator long () const { return (long)Pointer; }

        bool Is_Valid() const { return Pointer != nullptr; }

        // SmartPtr<T> operator ++ (int) { TSPP_ASSERT(Pointer != nullptr); SmartPtr<T> temp = *this; ++Pointer; return temp; }
        // SmartPtr<T> & operator ++ () { TSPP_ASSERT(Pointer != nullptr); ++Pointer; return(*this); }
        // SmartPtr<T> operator -- (int) { TSPP_ASSERT(Pointer != nullptr); SmartPtr<T> temp = *this; --Pointer; return temp; }
        // SmartPtr<T> & operator -- () { TSPP_ASSERT(Pointer != nullptr); --Pointer; return(*this); }

        SmartPtr & operator = (const SmartPtr & rvalue) { Pointer = rvalue.Pointer; return (*this); }
        T * operator -> () const { /*TSPP_ASSERT(Pointer != nullptr);*/ return(Pointer);}
        T & operator * () const { /*TSPP_ASSERT(Pointer != nullptr);*/ return(*Pointer);}

    private:
        T * Pointer;
};
