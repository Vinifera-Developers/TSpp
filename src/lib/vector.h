/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  VectorClass and DynamicVectorClass.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "tspp_assert.h"
#include <cstddef>
#include <cstring>
#include <initializer_list>
#include <memory>
#include <new>
#include <type_traits>
#include <utility>


class NoInitClass;


template<typename T>
class VectorClass
{
public:
    VectorClass(unsigned size = 0, const T* array = nullptr);
    // NoInitClass overload intentionally leaves members uninitialized; used
    // when the object overlays existing game memory.
    VectorClass(const NoInitClass& noinit) {}
    VectorClass(std::initializer_list<T> list);
    VectorClass(const VectorClass<T>& that);
    VectorClass(VectorClass<T>&& that) noexcept;
    virtual ~VectorClass();

    T& operator[](int index);
    const T& operator[](int index) const;

    VectorClass<T>& operator=(const VectorClass<T>& that);
    VectorClass<T>& operator=(VectorClass<T>&& that) noexcept;

    virtual bool operator==(const VectorClass<T>& that) const;

    virtual bool Resize(int newsize, const T* array = nullptr);
    virtual void Clear();
    virtual int ID(const T* ptr);
    virtual int ID(const T& ptr);

    T& at(int index);
    const T& at(int index) const;

    [[nodiscard]] int Length() const noexcept { return VectorMax; }
    [[nodiscard]] std::size_t size() const noexcept { return VectorMax > 0 ? static_cast<std::size_t>(VectorMax) : 0u; }
    [[nodiscard]] bool empty() const noexcept { return VectorMax <= 0; }
    [[nodiscard]] T* data() noexcept { return Vector; }
    [[nodiscard]] const T* data() const noexcept { return Vector; }

    [[nodiscard]] T* begin() noexcept { return (VectorMax > 0) ? &(*this)[0] : nullptr; }
    [[nodiscard]] T* end() noexcept { return (VectorMax > 0) ? ((&(*this)[VectorMax - 1]) + 1) : nullptr; }

    [[nodiscard]] const T* begin() const noexcept { return (VectorMax > 0) ? &(*this)[0] : nullptr; }
    [[nodiscard]] const T* end() const noexcept { return (VectorMax > 0) ? ((&(*this)[VectorMax - 1]) + 1) : nullptr; }

protected:
    T* Vector;
    int VectorMax;
    bool IsValid;
    bool IsAllocated;
    bool VectorClassPad[2];
};


template<typename T>
T& VectorClass<T>::operator[](int index)
{
    TSPP_ASSERT(unsigned(index) < unsigned(VectorMax));
    return Vector[index];
}


template<typename T>
const T& VectorClass<T>::operator[](int index) const
{
    TSPP_ASSERT(unsigned(index) < unsigned(VectorMax));
    return Vector[index];
}


template<typename T>
T& VectorClass<T>::at(int index)
{
    TSPP_ASSERT(index >= 0 && index < VectorMax);
    return Vector[index];
}


template<typename T>
const T& VectorClass<T>::at(int index) const
{
    TSPP_ASSERT(index >= 0 && index < VectorMax);
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
            // Construct into the caller-provided buffer element-wise to avoid
            // the array-new cookie that `new ((void*)array) T[size]` may reserve.
            Vector = const_cast<T*>(array);
            if constexpr (!std::is_trivially_default_constructible_v<T>) {
                for (unsigned i = 0; i < size; ++i) {
                    ::new (static_cast<void*>(&Vector[i])) T();
                }
            }
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
VectorClass<T>::VectorClass(std::initializer_list<T> list) :
    Vector(nullptr),
    VectorMax(static_cast<int>(list.size())),
    IsValid(true),
    IsAllocated(false)
{
    if (VectorMax > 0) {
        Vector = new T[VectorMax];
        IsAllocated = true;
        int i = 0;
        for (const T& item : list) {
            Vector[i++] = item;
        }
    }
}


template<typename T>
VectorClass<T>::VectorClass(const VectorClass<T>& that) :
    Vector(nullptr),
    VectorMax(0),
    IsValid(true),
    IsAllocated(false)
{
    *this = that;
}


template<typename T>
VectorClass<T>::VectorClass(VectorClass<T>&& that) noexcept :
    Vector(that.Vector),
    VectorMax(that.VectorMax),
    IsValid(that.IsValid),
    IsAllocated(that.IsAllocated)
{
    that.Vector = nullptr;
    that.VectorMax = 0;
    that.IsAllocated = false;
}


template<typename T>
VectorClass<T>& VectorClass<T>::operator=(const VectorClass<T>& that)
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

        IsValid = true;
    }

    return *this;
}


template<typename T>
VectorClass<T>& VectorClass<T>::operator=(VectorClass<T>&& that) noexcept
{
    if (this != &that) {
        Clear();
        Vector = that.Vector;
        VectorMax = that.VectorMax;
        IsValid = that.IsValid;
        IsAllocated = that.IsAllocated;

        that.Vector = nullptr;
        that.VectorMax = 0;
        that.IsAllocated = false;
    }

    return *this;
}


template<typename T>
bool VectorClass<T>::operator==(const VectorClass<T>& that) const
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
inline int VectorClass<T>::ID(const T* ptr)
{
    if (!IsValid) {
        return 0;
    }

    return static_cast<int>(ptr - Vector);
}


template<typename T>
int VectorClass<T>::ID(const T& object)
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
bool VectorClass<T>::Resize(int newsize, const T* array)
{
    if (newsize > 0) {
        T* newptr = nullptr;
        IsValid = false;

        if (array == nullptr) {
            newptr = new T[newsize];
        } else {
            // Construct element-wise into the caller buffer (see ctor comment).
            newptr = const_cast<T*>(array);
            if constexpr (!std::is_trivially_default_constructible_v<T>) {
                for (int i = 0; i < newsize; ++i) {
                    ::new (static_cast<void*>(&newptr[i])) T();
                }
            }
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
    DynamicVectorClass(unsigned size = 0, const T* array = nullptr);
    DynamicVectorClass(const NoInitClass& noinit) : VectorClass<T>(noinit) {}
    DynamicVectorClass(std::initializer_list<T> list);
    DynamicVectorClass(const DynamicVectorClass& that);
    DynamicVectorClass(DynamicVectorClass&& that) noexcept;
    virtual ~DynamicVectorClass() {}

    T& operator[](int index);
    const T& operator[](int index) const;

    DynamicVectorClass& operator=(const DynamicVectorClass& that);
    DynamicVectorClass& operator=(DynamicVectorClass&& that) noexcept;

    virtual bool Resize(int newsize, const T* array = nullptr) override;
    virtual void Clear() override;
    virtual int ID(const T* ptr) override { return VectorClass<T>::ID(ptr); }
    virtual int ID(const T& ptr) override;

    bool Add(const T& object);
    bool Add_Head(const T& object);

    T* Uninitialized_Add();
    bool Delete(const T& object);
    bool Delete(int index);
    void Delete_All();

    bool Insert(int index, const T& object);

    bool Is_Present(const T* ptr) const { return const_cast<DynamicVectorClass*>(this)->ID(ptr) != -1; }
    bool Is_Present(const T& ptr) const { return const_cast<DynamicVectorClass*>(this)->ID(ptr) != -1; }

    const T& Fetch_Head() const { TSPP_ASSERT(ActiveCount > 0); return (*this)[0]; }
    const T& Fetch_Tail() const { TSPP_ASSERT(ActiveCount > 0); return (*this)[ActiveCount - 1]; }

    void Reset_Active() noexcept { ActiveCount = 0; }
    void Set_Active(int count) noexcept { ActiveCount = count; }

    [[nodiscard]] int Count() const noexcept { return ActiveCount; }
    [[nodiscard]] std::size_t size() const noexcept { return ActiveCount > 0 ? static_cast<std::size_t>(ActiveCount) : 0u; }
    [[nodiscard]] bool empty() const noexcept { return ActiveCount <= 0; }
    [[nodiscard]] bool Empty() const noexcept { return ActiveCount <= 0; }

    int Set_Growth_Step(int step) noexcept { return GrowthStep = step; }
    [[nodiscard]] int Growth_Step() const noexcept { return GrowthStep; }

    [[nodiscard]] T* begin() noexcept { return (ActiveCount > 0) ? &(*this)[0] : nullptr; }
    [[nodiscard]] T* end() noexcept { return (ActiveCount > 0) ? &(*this)[ActiveCount] : nullptr; }

    [[nodiscard]] const T* begin() const noexcept { return (ActiveCount > 0) ? &(*this)[0] : nullptr; }
    [[nodiscard]] const T* end() const noexcept { return (ActiveCount > 0) ? &(*this)[ActiveCount] : nullptr; }

protected:
    int ActiveCount;
    int GrowthStep;
};


template<typename T>
DynamicVectorClass<T>::DynamicVectorClass(unsigned size, const T* array) :
    VectorClass<T>(size, array),
    ActiveCount(0),
    GrowthStep(10)
{
}


template<typename T>
DynamicVectorClass<T>::DynamicVectorClass(std::initializer_list<T> list) :
    VectorClass<T>(static_cast<unsigned>(list.size())),
    ActiveCount(0),
    GrowthStep(10)
{
    for (const T& item : list) {
        VectorClass<T>::Vector[ActiveCount++] = item;
    }
}


template<typename T>
DynamicVectorClass<T>::DynamicVectorClass(const DynamicVectorClass<T>& that) :
    VectorClass<T>(that),
    ActiveCount(0),
    GrowthStep(10)
{
    *this = that;
}


template<typename T>
DynamicVectorClass<T>::DynamicVectorClass(DynamicVectorClass<T>&& that) noexcept :
    VectorClass<T>(std::move(that)),
    ActiveCount(that.ActiveCount),
    GrowthStep(that.GrowthStep)
{
    that.ActiveCount = 0;
}


template<typename T>
T& DynamicVectorClass<T>::operator[](int index)
{
    // TSPP_ASSERT(unsigned(index) < unsigned(ActiveCount));
    return Vector[index];
}


template<typename T>
const T& DynamicVectorClass<T>::operator[](int index) const
{
    // TSPP_ASSERT(unsigned(index) < unsigned(ActiveCount));
    return Vector[index];
}


template<typename T>
void DynamicVectorClass<T>::Clear()
{
    ActiveCount = 0;
    VectorClass<T>::Clear();
}


template<typename T>
DynamicVectorClass<T>& DynamicVectorClass<T>::operator=(const DynamicVectorClass<T>& that)
{
    if (this != &that) {
        VectorClass<T>::operator=(that);
        ActiveCount = that.ActiveCount;
        GrowthStep = that.GrowthStep;
    }

    return *this;
}


template<typename T>
DynamicVectorClass<T>& DynamicVectorClass<T>::operator=(DynamicVectorClass<T>&& that) noexcept
{
    if (this != &that) {
        VectorClass<T>::operator=(std::move(that));
        ActiveCount = that.ActiveCount;
        GrowthStep = that.GrowthStep;
        that.ActiveCount = 0;
    }

    return *this;
}


template<typename T>
bool DynamicVectorClass<T>::Resize(int newsize, const T* array)
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
int DynamicVectorClass<T>::ID(const T& object)
{
    for (int i = 0; i < Count(); ++i) {
        if ((*this)[i] == object) {
            return i;
        }
    }

    return -1;
}


template<typename T>
bool DynamicVectorClass<T>::Add(const T& object)
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
bool DynamicVectorClass<T>::Add_Head(const T& object)
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
        if constexpr (std::is_trivially_copyable_v<T>) {
            std::memmove(&(*this)[1], &(*this)[0], ActiveCount * sizeof(T));
        } else {
            for (int i = ActiveCount; i > 0; --i) {
                (*this)[i] = std::move((*this)[i - 1]);
            }
        }
    }

    (*this)[0] = object;
    ++ActiveCount;

    return true;
}


template<typename T>
bool DynamicVectorClass<T>::Insert(int index, const T& object)
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
        if constexpr (std::is_trivially_copyable_v<T>) {
            std::memmove(&(*this)[index + 1], &(*this)[index], (ActiveCount - index) * sizeof(T));
        } else {
            for (int i = ActiveCount; i > index; --i) {
                (*this)[i] = std::move((*this)[i - 1]);
            }
        }
    }

    (*this)[index] = object;
    ++ActiveCount;

    return true;
}


template<typename T>
bool DynamicVectorClass<T>::Delete(const T& object)
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
    if (index >= 0 && index < ActiveCount) {
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
T* DynamicVectorClass<T>::Uninitialized_Add()
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
int Pointer_Vector_Add(T* ptr, VectorClass<T*>& vec)
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
bool Pointer_Vector_Remove(const T* ptr, VectorClass<T*>& vec)
{
    int id = vec.ID(const_cast<T*>(ptr));
    if (id != -1) {
        vec[id] = nullptr;
        return true;
    }
    return false;
}
