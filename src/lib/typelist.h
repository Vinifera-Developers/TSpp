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
#include "random.h"
#include "tspp_assert.h"
#include "vector.h"
#include <unknwn.h>


template<class T>
class TypeList : public DynamicVectorClass<T>
{
public: // Needs to be public otherwise calls to Count() using a TypeList instance is not allowed.
    using DynamicVectorClass<T>::ActiveCount;
    using DynamicVectorClass<T>::Count;
    using DynamicVectorClass<T>::Add;

public:
    TypeList(unsigned size = 0, const T* array = nullptr);
    TypeList(const TypeList& that);
    TypeList(TypeList&& that) noexcept;
    TypeList(const NoInitClass& noinit) : DynamicVectorClass<T>(noinit) {}
    TypeList(std::initializer_list<T> list) : DynamicVectorClass<T>(list), field_18(0) {}
    virtual ~TypeList() {}

    TypeList& operator=(const TypeList& that);
    TypeList& operator=(TypeList&& that) noexcept;

    bool Is_In_List(const T& object) const;

    T Pick(int index) const;
    const T& Random_Pick(Random2Class& rand) const;

    bool Save_Self(IStream* pStm) const;
    bool Load_Self(IStream* pStm);

protected:
    int field_18;
};


template<class T>
TypeList<T>::TypeList(unsigned size, const T* array) :
    DynamicVectorClass<T>(size, array), field_18(0)
{
}


template<class T>
TypeList<T>::TypeList(const TypeList<T>& that) :
    DynamicVectorClass<T>(that), field_18(that.field_18)
{
}


template<class T>
TypeList<T>::TypeList(TypeList<T>&& that) noexcept :
    DynamicVectorClass<T>(std::move(that)), field_18(that.field_18)
{
}


template<class T>
TypeList<T>& TypeList<T>::operator=(const TypeList<T>& that)
{
    if (this != &that) {
        DynamicVectorClass<T>::operator=(that);
        field_18 = that.field_18;
    }
    return *this;
}


template<class T>
TypeList<T>& TypeList<T>::operator=(TypeList<T>&& that) noexcept
{
    if (this != &that) {
        DynamicVectorClass<T>::operator=(std::move(that));
        field_18 = that.field_18;
    }
    return *this;
}


template<class T>
bool TypeList<T>::Is_In_List(const T& object) const
{
    for (int index = 0; index < ActiveCount; ++index) {
        if ((*this)[index] == object) {
            return true;
        }
    }
    return false;
}


template<class T>
T TypeList<T>::Pick(int index) const
{
    return (*this)[static_cast<unsigned>(index) % static_cast<unsigned>(Count())];
}


template<class T>
const T& TypeList<T>::Random_Pick(Random2Class& rand) const
{
    return (*this)[rand(0, Count() - 1)];
}


/**
 *  Saves all active objects to the data stream.
 *
 *  @author: CCHyper
 */
template<class T>
bool TypeList<T>::Save_Self(IStream* pStm) const
{
    TSPP_ASSERT(pStm != nullptr);

    ULONG bytes_written = 0;

    /**
     *  Save the number of instances of this class.
     */
    pStm->Write(&ActiveCount, sizeof(ActiveCount), &bytes_written);
    TSPP_ASSERT(bytes_written == sizeof(ActiveCount));

    /**
     *  Save each object.
     */
    for (int index = 0; index < ActiveCount; ++index) {
        T object = (*this)[index];
        pStm->Write(&object, sizeof(T), &bytes_written);
        TSPP_ASSERT(bytes_written == sizeof(T));
    }

    return true;
}


/**
 *  Loads all active objects from the data stream.
 *
 *  @author: CCHyper
 */
template<class T>
bool TypeList<T>::Load_Self(IStream* pStm)
{
    TSPP_ASSERT(pStm != nullptr);

    ULONG bytes_read = 0;

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
        T object;
        pStm->Read(&object, sizeof(T), &bytes_read);
        TSPP_ASSERT(bytes_read == sizeof(T));
        Add(object);
    }

    return true;
}
