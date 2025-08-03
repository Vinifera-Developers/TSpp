/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TYPELIST.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Type vector with save/load interface.
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
#include "tspp_assert.h"
#include "vector.h"
#include <unknwn.h>


template<class T>
class TypeList : public DynamicVectorClass<T>
{
public: // Needs to be public otherwise calls to Count() using a TypeList instance is not allowed.
    using DynamicVectorClass<T>::Count;
    using DynamicVectorClass<T>::Add;

public:
    TypeList(unsigned size = 0, const T* array = nullptr);
    TypeList(const TypeList& that);
    TypeList(const NoInitClass& noinit) : DynamicVectorClass<T>(noinit) {}
    virtual ~TypeList() {}

    TypeList& operator=(const TypeList& that)
    {
        DynamicVectorClass<T>::operator=(that);
        field_18 = that.field_18;
        return (*this);
    }

    bool Save(IStream* pStm);
    bool Load(IStream* pStm);

protected:
    int field_18;
};


template<class T>
TypeList<T>::TypeList(unsigned size, T const* array) :
    DynamicVectorClass<T>(size, array), field_18(0)
{
}


template<class T>
TypeList<T>::TypeList(const TypeList<T>& that) :
    DynamicVectorClass<T>(that), field_18(that.field_18)
{
}


/**
 *  Saves all active objects to the data stream.
 *
 *  @author: CCHyper
 */
template<class T>
bool TypeList<T>::Save(IStream* pStm)
{
    TSPP_ASSERT(pStm != nullptr);

    ULONG bytes_written = 0;
    T object;

    /**
     *  Save the number of instances of this class.
     */
    pStm->Write(&ActiveCount, sizeof(ActiveCount), &bytes_written);
    TSPP_ASSERT(bytes_written == sizeof(ActiveCount));

    /**
     *  Save the pointer to the object.
     */
    for (int index = 0; index < ActiveCount; ++index) {
        object = (*this)[index];
        pStm->Write(&object, sizeof(T), &bytes_written);
        TSPP_ASSERT(bytes_written == sizeof(T));
    }

    return true;
}


/**
 *  Saves all active objects from the data stream.
 *
 *  @author: CCHyper
 */
template<class T>
bool TypeList<T>::Load(IStream* pStm)
{
    TSPP_ASSERT(pStm != nullptr);

    ULONG bytes_read = 0;
    T object;

    new (this) TypeList<T>;

    /**
     *  Read the number of instances of this class.
     */
    int a_count = 0;
    pStm->Read(&a_count, sizeof(a_count), &bytes_read);
    TSPP_ASSERT(bytes_read == sizeof(a_count));

    /**
     *  Read each class instance.
     */
    for (int index = 0; index < a_count; ++index) {
        pStm->Read(&object, sizeof(T), &bytes_read);
        TSPP_ASSERT(bytes_read == sizeof(T));
        Add(object);
    }

    return true;
}
