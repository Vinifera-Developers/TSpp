/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          STATICHEAP.H
 *
 *  @authors       tomsons26, CCHyper
 *
 *  @brief         Static heap container.
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


template <typename T>
class DynamicArrayClass<T>
{
    public:
        DynamicArrayClass();
        ~DynamicArrayClass();

        bool Push(T* data);
        bool Pop(T* data);

        bool Replace_Something(T* data);

        bool Get(T* data, int index);

        int Get_Count();

        void Clear();

    private:
        bool Internal_Push(T* data, int index);
        bool Internal_Pop(T* data, int index);
        bool Replace_Something(T* data, int index);

        bool Internal_Remove(int index);

        bool Grow();
        bool Shrink();

    private:
        int Count;
        int MaxCount;
        T* Data;
};


template <typename T>
DynamicArrayClass<T>::DynamicArrayClass()
{
    Count = 0;
    MaxCount = 0;
    Data = nullptr;
}


template <typename T>
DynamicArrayClass<T>::~DynamicArrayClass()
{
    Clear();
    delete Data;
}


template <typename T>
bool DynamicArrayClass<T>::Push(T* data)
{
    return Internal_Push(data, Get_Count());
}


template <typename T>
bool DynamicArrayClass<T>::Pop(T* data)
{
    return Internal_Pop(data, 0);
}

//weird
template <typename T>
bool DynamicArrayClass<T>::Replace_Something(T* data)
{
    return Internal_Push(data, 0);
}


template <typename T>
bool DynamicArrayClass<T>::Get(T* data, int index)
{
    if (index < 0 || index >= Count) {
        return false;
    }

    data = Data[index];
    return true;
}


template <typename T>
int DynamicArrayClass<T>::Get_Count()
{
    return Count;
}


template <typename T>
void DynamicArrayClass<T>::Clear()
{
    for (int i = 0; i < Count; ++i) {
        delete data[i];
    }

    Count = 0;
}


//some sort of static helper thats part of the class.......
template <typename T>
int __cdecl sub_100107F0(int a1, int a2)
{
    return a2;
}


template <typename T>
bool DynamicArrayClass<T>::Internal_Push(T* data, int index)
{
    if (index > Count) {
        index = Count;
    }

    if (index >= MaxCount) {
        Grow();
    }

    if (index < Count) {
        memcpy(&Data[index + 1], &Data[index], sizeof(T) * (Count - index));
    }

    void* d = (void *)sub_10002784(sizeof(T), (int)&Data[index]);
    if (d != nullptr) {
        *d = *data;
    }

    ++Count;

    return true;
}


template <typename T>
bool DynamicArrayClass<T>::Internal_Pop(T* data, int index)
{
    if (Get(data, index)) {
        return Internal_Remove(index);
    }

    return false;
}


template <typename T>
bool DynamicArrayClass<T>::Internal_Remove(int index)
{
    if (Count == 0) {
        return false;
    }

    if (index < 0) {
        index = 0;
    }

    if (index >= Count) {
        index = Count - 1;
    }

    delete Data[index];

    memcpy(&Data[index], &Data[index + 1], sizeof(T) * (Count - index - 1));
    
    --Count;
    
    if (3 * Count <= MaxCount) {
        Shrink();
    }

    return true;
}


template <typename T>
bool DynamicArrayClass<T>::Grow()
{
    if (Count < MaxCount) {
        return false;
    }

    int new_max = 2 * Count;
    if (new_max < 10) {
        new_max = 10;
    }

    void* new_data = new T[new_max];

    if (Data != nullptr) {
        memcpy(new_data, Data, sizeof(T) * Count);
    }

    delete[] Data;

    Data = new_data;
    MaxCount = new_max;

    return true;
}


template <typename T>
bool DynamicArrayClass<T>::Shrink()
{
    if (3 * Count > MaxCount) {
        return 0;
    }

    new_max = MaxCount / 2;

    if (new_max < 10) {
        new_max = 10;
    }

    if (new_max >= MaxCount) {
        return false;
    }

    void* new_data = new T[new_max];

    if (Data != nullptr) {
        memcpy(new_data, Data, sizeof(T) * Count);
    }

    delete[] Data;

    Data = new_data;
    MaxCount = new_max;

    return true;
}
