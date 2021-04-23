/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          VECTOR.H
 *
 *  @authors       CCHyper, OmniBlade, tomsons26
 *
 *  @brief         VectorClass and DynamicVectorClass.
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
#include <memory>
#include <new>


class NoInitClass;


template<typename T>
class VectorClass
{
    public:
        VectorClass(unsigned size = 0, const T *array = nullptr);
        VectorClass(const NoInitClass &noinit) {}
        VectorClass(const VectorClass<T> &that);
        virtual ~VectorClass();

        T &operator[](int index);
        const T &operator[](int index) const;

        VectorClass<T> &operator=(const VectorClass<T> &that);

        virtual bool operator==(const VectorClass<T> &that) const;

        virtual bool Resize(int newsize, const T *array = nullptr);
        virtual void Clear();
        virtual int ID(const T *ptr);
        virtual int ID(const T &ptr);

        int Length() const { return VectorMax; }

    protected:
		T * Vector;
		int VectorMax;
		bool IsValid;
		bool IsAllocated;
		bool VectorClassPad[2];
};


template<typename T>
T &VectorClass<T>::operator[](int index)
{
    TSPP_ASSERT(unsigned(index) < unsigned(VectorMax));
    return Vector[index];
}


template<typename T>
const T &VectorClass<T>::operator[](int index) const
{
    TSPP_ASSERT(unsigned(index) < unsigned(VectorMax));
    return Vector[index];
}


template<typename T>
VectorClass<T>::VectorClass(unsigned size, const T *array) :
    Vector(nullptr),
    VectorMax(size),
    IsValid(true),
    IsAllocated(false)
{
    if (size > 0) {
        if (array != nullptr) {
            Vector = new ((void *)array) T[size];
        } else {
            Vector = new T[size];
            IsAllocated = true;
        }
    }
}


template<typename T>
VectorClass<T>::~VectorClass()
{
    VectorClass<T>::Clear();
}


template<typename T>
VectorClass<T>::VectorClass(const VectorClass<T> &that) :
    Vector(nullptr),
    VectorMax(0),
    IsAllocated(false)
{
    *this = that;
}


template<typename T>
VectorClass<T> &VectorClass<T>::operator=(const VectorClass<T> &that)
{
    if (this != &that) {
        Clear();
        VectorMax = that.Length();

        if (VectorMax > 0) {
            Vector = new T[VectorMax];

            if (Vector != nullptr) {
                IsAllocated = true;

                for (int i = 0; i < VectorMax; ++i) {
                    (*this)[i] = that[i];
                }
            }
        } else {
            Vector = nullptr;
            IsAllocated = false;
        }
    }

    return *this;
}


template<typename T>
bool VectorClass<T>::operator==(const VectorClass<T> &that) const
{
    if (VectorMax != that.Length()) {
        return false;
    }

    for (int i = 0; i < VectorMax; ++i) {
        if ((*this)[i] != that[i]) {
            return false;
        }
    }

    return true;
}


template<typename T>
inline int VectorClass<T>::ID(const T *ptr)
{
    if (!IsValid) {
        return 0;
    }

    return ((uintptr_t)ptr - (uintptr_t)Vector) / sizeof(T);
}


template<typename T>
int VectorClass<T>::ID(const T &object)
{
    if (!IsValid) {
        return 0;
    }

    for (int i = 0; i < VectorMax; ++i) {
        if ((*this)[i] == object) {
            return i;
        }
    }

    return -1;
}


template<typename T>
void VectorClass<T>::Clear()
{
    if (Vector != nullptr && IsAllocated) {
        delete[] Vector;
        Vector = nullptr;
    }

    IsAllocated = false;
    VectorMax = 0;
}


template<typename T>
bool VectorClass<T>::Resize(int newsize, const T *array)
{
    if (newsize > 0) {
        T *newptr = nullptr;
        IsValid = false;

        if (array == nullptr) {
            newptr = new T[newsize];
        } else {
            newptr = new ((void *)array) T[newsize];
        }

        IsValid = true;

        if (newptr == nullptr) {
            return false;
        }

        if (Vector != nullptr) {
            int copy_count = (newsize < VectorMax) ? newsize : VectorMax;

            for (int i = 0; i < copy_count; ++i) {
                newptr[i] = (*this)[i];
            }

            if (IsAllocated) {
                delete[] Vector;
                Vector = nullptr;
            }
        }

        Vector = newptr;
        VectorMax = newsize;
        IsAllocated = (Vector != nullptr && array == nullptr);

    } else {
        Clear();
    }

    return true;
}


template<typename T>
class DynamicVectorClass : public VectorClass<T>
{
    using VectorClass<T>::Vector;
    using VectorClass<T>::VectorMax;
    using VectorClass<T>::IsAllocated;

    public:
        DynamicVectorClass(unsigned size = 0, const T *array = nullptr);
        DynamicVectorClass(const NoInitClass &noinit) : VectorClass(noinit) {}
        DynamicVectorClass(const DynamicVectorClass &that);
        virtual ~DynamicVectorClass() {}

        bool operator==(const DynamicVectorClass &src) { return false; }
        bool operator!=(const DynamicVectorClass &src) { return true; }

        DynamicVectorClass &operator=(const DynamicVectorClass &that);

        virtual bool Resize(int newsize, const T *array = nullptr) override;
        virtual void Clear() override;
        virtual int ID(const T *ptr) override { return VectorClass::ID(ptr); }
        virtual int ID(const T &ptr) override;

        bool Add(const T &object);
        bool Add_Head(const T &object);

        T * Uninitialized_Add();
        bool Delete(const T &object);
        bool Delete(int index);
        void Delete_All();

        bool Insert(int index, const T &object);

        const T &Fetch_Head() const { return (*this)[0]; }

        void Reset_Active() { ActiveCount = 0; }
        void Set_Active(int count) { ActiveCount = count; }

        int Count() const { return ActiveCount; }

        bool Empty() const { return ActiveCount <= 0; }

        int Set_Growth_Step(int step) { return GrowthStep = step; }

        int Growth_Step() { return GrowthStep; }

    protected:
		int ActiveCount;
		int GrowthStep;
};


template<typename T>
DynamicVectorClass<T>::DynamicVectorClass(unsigned size, const T *array) :
    VectorClass<T>(size, array),
    GrowthStep(10),
    ActiveCount(0)
{
}


template<typename T>
DynamicVectorClass<T>::DynamicVectorClass(const DynamicVectorClass<T> &that) :
    VectorClass<T>(that),
    GrowthStep(10),
    ActiveCount(0)
{
    *this = that;
}


template<typename T>
void DynamicVectorClass<T>::Clear()
{
    ActiveCount = 0;
    VectorClass<T>::Clear();
}


template<typename T>
DynamicVectorClass<T> &DynamicVectorClass<T>::operator=(const DynamicVectorClass<T> &that)
{
    VectorClass<T>::operator=(that);
    ActiveCount = that.ActiveCount;
    GrowthStep = that.GrowthStep;

    return *this;
}


template<typename T>
bool DynamicVectorClass<T>::Resize(int newsize, const T *array)
{
    if (!VectorClass<T>::Resize(newsize, array)) {
        return false;
    }

    if (VectorMax < ActiveCount) {
        ActiveCount = VectorMax;
    }

    return true;
}


template<typename T>
int DynamicVectorClass<T>::ID(const T &object)
{
    for (int i = 0; i < Count(); ++i) {
        if ((*this)[i] == object) {
            return i;
        }
    }

    return -1;
}


template<typename T>
bool DynamicVectorClass<T>::Add(const T &object)
{
    if (ActiveCount >= VectorMax) {
        if ((IsAllocated || !VectorMax) && GrowthStep > 0) {
            if (!Resize(VectorMax + GrowthStep)) {
                return false;
            }
        } else {
            return false;
        }
    }

    (*this)[ActiveCount++] = object;

    return true;
}


template<typename T>
bool DynamicVectorClass<T>::Add_Head(const T &object)
{
    if (ActiveCount >= VectorMax) {
        if ((IsAllocated || !VectorMax) && GrowthStep > 0) {
            if (!Resize(VectorMax + GrowthStep)) {
                return false;
            }
        } else {
            return false;
        }
    }

    if (ActiveCount > 0) {
        std::memmove(&(*this)[1], &(*this)[0], ActiveCount * sizeof(T));
    }


    (*this)[0] = object;
    ++ActiveCount;
//	(*this)[ActiveCount++] = object;

    return true;
}


template<typename T>
bool DynamicVectorClass<T>::Insert(int index, const T &object)
{
    if (index < 0 || index > ActiveCount) {
        return false;
    }

    if (ActiveCount >= VectorMax) {
        if ((IsAllocated || !VectorMax) && GrowthStep > 0) {
            if (!Resize(VectorMax + GrowthStep)) {
                return false;
            }
        } else {
            return false;
        }
    }

    if (index < ActiveCount) {
        std::memmove(&(*this)[index + 1], &(*this)[index], (ActiveCount - index) * sizeof(T));
    }

    (*this)[index] = object;
    ++ActiveCount;

    return true;
}


template<typename T>
bool DynamicVectorClass<T>::Delete(const T &object)
{
    int id = ID(object);

    if (id != -1) {
        return Delete(id);
    }

    return false;
}


template<typename T>
bool DynamicVectorClass<T>::Delete(int index)
{
    if (index < ActiveCount) {
        --ActiveCount;
        for (int i = index; i < ActiveCount; ++i) {
            (*this)[i] = (*this)[i + 1];
        }

        return true;
    }

    return false;
}


template<typename T>
void DynamicVectorClass<T>::Delete_All()
{
    int len = VectorMax;
    Clear();
    Resize(len);
}


template<typename T>
T *DynamicVectorClass<T>::Uninitialized_Add()
{
    if (ActiveCount >= VectorMax) {
        if (GrowthStep > 0) {
            if (!Resize(VectorMax + GrowthStep)) {
                return nullptr;
            }
        } else {
            return nullptr;
        }
    }

    return &((*this)[ActiveCount++]);
}


template<class T>
int Pointer_Vector_Add(T *ptr, VectorClass<T *> &vec)
{
    int id = 0;
    bool foundspot = false;
    for (int i = 0; i < vec.Length(); ++i) {
        if (vec[i] == nullptr) {
            id = i;
            foundspot = true;
            break;
        }
    }
    if (!foundspot) {
        id = vec.Length();
        vec.Resize((vec.Length() + 1) * 2);
        for (int i = id; i < vec.Length(); ++i) {
            vec[i] = nullptr;
        }
    }
    vec[id] = ptr;
    return id;
}


template<class T>
bool Pointer_Vector_Remove(const T *ptr, VectorClass<T *> &vec)
{
    int id = vec.ID((T *)ptr);
    if (id != -1) {
        vec[id] = nullptr;
        return true;
    }
    return false;
}


template<class T>
class SimpleVecClass
{
    public:
        SimpleVecClass(unsigned size = 0);
        virtual ~SimpleVecClass();

        virtual bool Resize(int newsize);
        virtual bool Uninitialised_Grow(int newsize);

        T &operator[](int index)
        {
            TSPP_ASSERT(index < VectorMax);
            return Vector[index];
        }
        T const &operator[](int index) const
        {
            TSPP_ASSERT(index < VectorMax);
            return Vector[index];
        }

        int Length() const { return VectorMax; }

        void Zero_Memory()
        {
            if (Vector != nullptr) {
                std::memset(Vector, 0, VectorMax * sizeof(T));
            }
        }

    protected:
        T *Vector;
        int VectorMax;
};


template<class T>
SimpleVecClass<T>::SimpleVecClass(unsigned size) :
    Vector(nullptr),
    VectorMax(0)
{
    if (size > 0) {
        Resize(size);
    }
}


template<class T>
SimpleVecClass<T>::~SimpleVecClass()
{
    if (Vector != nullptr) {
        delete[] Vector;
        Vector = nullptr;
        VectorMax = 0;
    }
}


template<class T>
bool SimpleVecClass<T>::Resize(int newsize)
{
    if (newsize == VectorMax) {
        return true;
    }

    if (newsize > 0) {
        T *newptr = new T[newsize];

        if (Vector != nullptr) {
            int copycount = (newsize < VectorMax) ? newsize : VectorMax;
            std::memcpy(newptr, Vector, copycount * sizeof(T));

            delete[] Vector;
            Vector = nullptr;
        }

        Vector = newptr;
        VectorMax = newsize;

    } else {
        VectorMax = 0;
        if (Vector != nullptr) {
            delete[] Vector;
            Vector = nullptr;
        }
    }
    return true;
}


template<class T>
bool SimpleVecClass<T>::Uninitialised_Grow(int newsize)
{
    if (newsize <= VectorMax) {
        return true;
    }

    if (newsize > 0) {
        delete[] Vector;
        Vector = new T[newsize];
        VectorMax = newsize;
    }
    return true;
}


template<class T>
class SimpleDynVecClass : public SimpleVecClass<T>
{
        using SimpleVecClass<T>::Vector;
        using SimpleVecClass<T>::VectorMax;
        using SimpleVecClass<T>::Length;

    public:
        SimpleDynVecClass(unsigned size = 0);
        virtual ~SimpleDynVecClass();

        virtual bool Resize(int newsize);

        T &operator[](int index)
        {
            TSPP_ASSERT(index < ActiveCount);
            return Vector[index];
        }
        const T &operator[](int index) const
        {
            TSPP_ASSERT(index < ActiveCount);
            return Vector[index];
        }

        int Count() const { return (ActiveCount); }

        bool Add(const T &object, int new_size_hint = 0);
        T *Add_Multiple(int number_to_add);

        bool Delete(int index, bool allow_shrink = true);
        bool Delete(const T &object, bool allow_shrink = true);
        bool Delete_Range(int start, int count, bool allow_shrink = true);
        void Delete_All(bool allow_shrink = true);

    protected:
        bool Grow(int new_size_hint);
        bool Shrink();

        int Find_Index(const T &object);

    protected:
        int ActiveCount;
};


template<class T>
SimpleDynVecClass<T>::SimpleDynVecClass(unsigned size) :
    SimpleVecClass<T>(size),
    ActiveCount(0)
{
}


template<class T>
SimpleDynVecClass<T>::~SimpleDynVecClass()
{
    if (Vector != nullptr) {
        delete[] Vector;
        Vector = nullptr;
    }
}


template<class T>
bool SimpleDynVecClass<T>::Resize(int newsize)
{
    if (SimpleVecClass<T>::Resize(newsize)) {
        if (Length() < ActiveCount) {
            ActiveCount = Length();
        }
        return true;
    }
    return false;
}


template<class T>
bool SimpleDynVecClass<T>::Add(const T &object, int new_size_hint)
{
    if (ActiveCount >= VectorMax) {
        if (!Grow(new_size_hint)) {
            return false;
        }
    }

    (*this)[ActiveCount++] = object;
    return true;
}


template<class T>
T *SimpleDynVecClass<T>::Add_Multiple(int number_to_add)
{
    int i = ActiveCount;
    ActiveCount += number_to_add;

    if (ActiveCount >= VectorMax) {
        Grow(ActiveCount);
    }

    return &Vector[i];
}


template<class T>
bool SimpleDynVecClass<T>::Delete(int index, bool allow_shrink)
{
    TSPP_ASSERT(index < ActiveCount);

    if (index < ActiveCount - 1) {
        std::memmove(&(Vector[index]), &(Vector[index + 1]), (ActiveCount - index - 1) * sizeof(T));
    }
    --ActiveCount;

    if (allow_shrink) {
        Shrink();
    }

    return true;
}


template<class T>
bool SimpleDynVecClass<T>::Delete(const T &object, bool allow_shrink)
{
    int id = Find_Index(object);
    if (id != -1) {
        return Delete(id, allow_shrink);
    }
    return false;
}


template<class T>
bool SimpleDynVecClass<T>::Delete_Range(int start, int count, bool allow_shrink)
{
    TSPP_ASSERT(start >= 0);
    TSPP_ASSERT(start <= ActiveCount - count);

    if (start < ActiveCount - count) {
        std::memmove(&(Vector[start]), &(Vector[start + count]), (ActiveCount - start - count) * sizeof(T));
    }

    ActiveCount -= count;

    if (allow_shrink) {
        Shrink();
    }

    return true;
}


template<class T>
void SimpleDynVecClass<T>::Delete_All(bool allow_shrink)
{
    ActiveCount = 0;
    if (allow_shrink) {
        Shrink();
    }
}


template<class T>
bool SimpleDynVecClass<T>::Grow(int new_size_hint)
{
    int new_size = std::max(Length() + Length() / 4, Length() + 4);
    new_size = std::max(new_size, new_size_hint);

    return Resize(new_size);
}


template<class T>
bool SimpleDynVecClass<T>::Shrink()
{
    // Shrink the array if it is wasting more than 25%.
    if (ActiveCount < VectorMax / 4) {
        return Resize(ActiveCount);
    }
    return true;
}


template<class T>
int SimpleDynVecClass<T>::Find_Index(const T &object)
{
    for (int i = 0; i < Count(); ++i) {
        if ((*this)[i] == object) {
            return i;
        }
    }
    return -1;
}
