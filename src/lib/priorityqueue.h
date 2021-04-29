/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          PRIORITYQUEUE.H
 *
 *  @authors       tomsons26, CCHyper
 *
 *  @brief         Priority queue class.
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


template<typename T>
class PriorityQueueClass
{
    public:
        PriorityQueueClass(int capacity = 0);
        ~PriorityQueueClass();

        void Clear();
        //void Heapify(unsigned index);
        //T *Extract_Min();
        //bool Insert(T *);
        //void Resize_Max(unsigned);

    public:
        int HeapSize;
        int Capacity;
        T *Heap;
        int field_10;
        int field_14;
};


template <typename T>
PriorityQueueClass<T>::PriorityQueueClass(int capacity = 0) :
    HeapSize(0),
    Capacity(capacity),
    Heap(new int [capacity + 4]),
    field_10(0),
    field_14(-1),
{
    for (int i = 0; i < capacity; ++i) {
        Heap[i] = 0;
    }
}


template <typename T>
PriorityQueueClass<T>::~PriorityQueueClass()
{
    Clear();
    delete [] Heap;
}


template <typename T>
void PriorityQueueClass<T>::Clear()
{
    for (int i = 0; i < HeapSize; ++i) {
        Heap[i] = 0;
    }
    HeapSize = 0;
}
