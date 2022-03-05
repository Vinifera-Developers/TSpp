/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          REFPTR.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Reference counted pointer implementation.
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

#include "tspp_assert.h"


/**
 *  For debugging purposes only!
 */
//#define REFPTR_ASSERTS

#ifdef REFPTR_ASSERTS
#define refptr_assert(x) TSPP_ASSERT(x)
#else
#define refptr_assert(x) ((void)0)
#endif


template<class T>
class RefPtr
{
    public:
        RefPtr(T *realptr = nullptr) : Pointer(realptr) {}
        RefPtr(const RefPtr &that) : Pointer(that.Pointer) {}
        ~RefPtr() { Pointer = nullptr; }

        operator T *() const { refptr_assert(Pointer != nullptr); return Pointer; }
        operator T & () const { refptr_assert(Pointer != nullptr); return (*Pointer); }
        // operator uintptr_t() const { return uintptr_t(Pointer); }

        bool operator!() const { refptr_assert(Pointer != nullptr); return Pointer == nullptr; }

        RefPtr &operator=(const T *that)
        {
            refptr_assert(that != nullptr);

            Pointer = const_cast<T *>(that);
            return (*this);
        }

        RefPtr &operator=(const RefPtr &that)
        {
            Pointer = that.Pointer;
            return (*this);
        }

        T ** operator &() { refptr_assert(Pointer != nullptr); return &Pointer; } // Address-of operator.
        T *operator->() const { refptr_assert(Pointer != nullptr); return Pointer; }
        T &operator*() const { refptr_assert(Pointer != nullptr); return (*Pointer); }

        bool Is_Valid() const { return Pointer != nullptr; }

    private:
        /**
         *  Raw pointer to the object.
         */
        T *Pointer;
};
