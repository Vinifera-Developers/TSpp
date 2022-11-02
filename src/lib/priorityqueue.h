/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          PRIORITYQUEUE.H
 *
 *  @authors       Neijwiert
 *
 *  @brief         Provides a priority queue which is a collection that is
 *    			   ordered in either maximum or minimum order.
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


template<typename TElement, typename TPriority>
class PriorityQueueClassNode
{
    public:
        PriorityQueueClassNode();
        PriorityQueueClassNode(const TElement &element, const TPriority &priority);
        PriorityQueueClassNode(TElement &&element, const TPriority &priority);
        PriorityQueueClassNode(const TElement &element, TPriority &&priority);
        PriorityQueueClassNode(TElement &&element, TPriority &&priority);
        PriorityQueueClassNode(const PriorityQueueClassNode<TElement, TPriority> &that) = default;
        PriorityQueueClassNode(PriorityQueueClassNode<TElement, TPriority> &&that) noexcept = default;

        ~PriorityQueueClassNode() = default;

        PriorityQueueClassNode<TElement, TPriority> &operator=(const PriorityQueueClassNode<TElement, TPriority> &that) = default;
        PriorityQueueClassNode<TElement, TPriority> &operator=(PriorityQueueClassNode<TElement, TPriority> &&that) noexcept = default;

        const TElement &Get_Element() const { return Element; }
        TElement &Get_Element() { return Element; }

        const TPriority &Get_Priority() const { return Priority; }
        TPriority &Get_Priority() { return Priority; }

        void Set_Element(const TElement &element) { Element = element; }
        void Set_Element(TElement &&element) { Element = std::move(element); }

        void Set_Priority(const TPriority &priority) { Priority = priority; }
        void Set_Priority(TPriority &&priority) { Priority = std::move(priority); }

        static bool Compare_Priority(const TPriority &lhs, const TPriority &rhs) { return std::greater<TPriority>()(lhs, rhs); }

    private:
        TElement Element;
        TPriority Priority;
};


template<typename TElement, typename TPriority>
class PriorityQueueClass
{
    public:
        PriorityQueueClass(int size);
        PriorityQueueClass(const PriorityQueueClass<TElement, TPriority> &that);
        PriorityQueueClass(PriorityQueueClass<TElement, TPriority> &&that) noexcept;

        ~PriorityQueueClass();

        PriorityQueueClass<TElement, TPriority> &operator=(const PriorityQueueClass<TElement, TPriority> &that);
        PriorityQueueClass<TElement, TPriority> &operator=(PriorityQueueClass<TElement, TPriority> &&that) noexcept;

        PriorityQueueClassNode<TElement, TPriority> const *operator[](int index) const { TSPP_ASSERT(index < Get_Count()); return Heap[index]; }
        PriorityQueueClassNode<TElement, TPriority> *operator[](int index) { TSPP_ASSERT(index < Get_Count()); return Heap[index]; }

        int Get_Count() const;
        int Get_Size() const;
        void Clear();
        bool Is_Empty() const;

        bool Insert(PriorityQueueClassNode<TElement, TPriority> *node);
        PriorityQueueClassNode<TElement, TPriority> *Extract();
        void Resize(int new_size);
        PriorityQueueClassNode<TElement, TPriority> *Find(const TElement &element) const;
        bool Remove_Matching(const TElement &element);
        bool Update_Priority(const TElement &element, const TPriority &priority);
        bool Update_Priority(const TElement &element, TPriority &&priority);

    private:
        void Release_Heap();
        void Heapify_Up(int index);
        void Heapify_Down(int index);
        void Internal_Copy_Heap(const PriorityQueueClass<TElement, TPriority> &that);
        int Internal_Find(const TElement &element) const;

        static int Get_Parent_Index(int index);
        static int Get_Left_Index(int index);
        static int Get_Right_Index(int index);

    private:
        int Count;
        int Size;
        PriorityQueueClassNode<TElement, TPriority> **Heap;
        std::uintptr_t MaxNodePointer;
        std::uintptr_t MinNodePointer;
};


template<typename TElement, typename TPriority>
PriorityQueueClassNode<TElement, TPriority>::PriorityQueueClassNode()
    : Element(), Priority()
{
}


template<typename TElement, typename TPriority>
PriorityQueueClassNode<TElement, TPriority>::PriorityQueueClassNode(const TElement &element, const TPriority &priority)
    : Element(element), Priority(priority)
{
}


template<typename TElement, typename TPriority>
PriorityQueueClassNode<TElement, TPriority>::PriorityQueueClassNode(TElement &&element, const TPriority &priority)
    : Element(std::move(element)), Priority(priority)
{
}


template<typename TElement, typename TPriority>
PriorityQueueClassNode<TElement, TPriority>::PriorityQueueClassNode(const TElement &element, TPriority &&priority)
    : Element(element), Priority(std::move(priority))
{
}


template<typename TElement, typename TPriority>
PriorityQueueClassNode<TElement, TPriority>::PriorityQueueClassNode(TElement &&element, TPriority &&priority)
    : Element(std::move(element)), Priority(std::move(priority))
{
}


template<typename TElement, typename TPriority>
PriorityQueueClass<TElement, TPriority>::PriorityQueueClass(int size)
    : Count(0), Size(size), MaxNodePointer(std::numeric_limits<decltype(MaxNodePointer)>::min()), MinNodePointer(std::numeric_limits<decltype(MinNodePointer)>::max())
{
    TSPP_ASSERT(size >= 0);

    Heap = new PriorityQueueClassNode<TElement, TPriority> *[size + 1];
    TSPP_ASSERT(Heap != nullptr);
    std::memset(Heap, 0, (size + 1) * sizeof(PriorityQueueClassNode<TElement, TPriority> *));
}


template<typename TElement, typename TPriority>
PriorityQueueClass<TElement, TPriority>::PriorityQueueClass(const PriorityQueueClass<TElement, TPriority> &that)
    : Count(that.Count), Size(that.Size), Heap(nullptr), MaxNodePointer(that.MaxNodePointer), MinNodePointer(that.MinNodePointer)
{
    Internal_Copy_Heap(that);
}


template<typename TElement, typename TPriority>
PriorityQueueClass<TElement, TPriority>::PriorityQueueClass(PriorityQueueClass<TElement, TPriority> &&that) noexcept
    : Count(that.Count), Size(that.Size), Heap(that.Heap), MaxNodePointer(that.MaxNodePointer), MinNodePointer(that.MinNodePointer)
{
    that.Heap = nullptr;
}


template<typename TElement, typename TPriority>
PriorityQueueClass<TElement, TPriority>::~PriorityQueueClass()
{
    /**
     *  #OPTIMIZATION:
     *  Original called Clear here and then deleted the heap.
     *  Only releasing the heap suffices...
     */
    Release_Heap();
}


template<typename TElement, typename TPriority>
PriorityQueueClass<TElement, TPriority> &PriorityQueueClass<TElement, TPriority>::operator=(const PriorityQueueClass<TElement, TPriority> &that)
{
    if (this != &that) {
        Release_Heap();

        Count = that.Count;
        Size = that.Size;
        MaxNodePointer = that.MaxNodePointer;
        MinNodePointer = that.MinNodePointer;

        Internal_Copy_Heap(that);
    }

    return *this;
}


template<typename TElement, typename TPriority>
PriorityQueueClass<TElement, TPriority> &PriorityQueueClass<TElement, TPriority>::operator=(PriorityQueueClass<TElement, TPriority> &&that) noexcept
{
    if (this != &that) {
        Release_Heap();

        Count = that.Count;
        Size = that.Size;
        Heap = that.Heap;
        MaxNodePointer = that.MaxNodePointer;
        MinNodePointer = that.MinNodePointer;

        that.Heap = nullptr;
    }

    return *this;
}


template<typename TElement, typename TPriority>
int PriorityQueueClass<TElement, TPriority>::Get_Count() const
{
    return Count;
}


template<typename TElement, typename TPriority>
int PriorityQueueClass<TElement, TPriority>::Get_Size() const
{
    return Size;
}


template<typename TElement, typename TPriority>
void PriorityQueueClass<TElement, TPriority>::Clear()
{
    std::memset(Heap, 0, (Count + 1) * sizeof(PriorityQueueClassNode<TElement, TPriority> *));
    Count = 0;
}


template<typename TElement, typename TPriority>
bool PriorityQueueClass<TElement, TPriority>::Is_Empty() const
{
    return (Count <= 0);
}


template<typename TElement, typename TPriority>
bool PriorityQueueClass<TElement, TPriority>::Insert(PriorityQueueClassNode<TElement, TPriority> *node)
{
    TSPP_ASSERT(node != nullptr);

    int new_count = Count + 1;
    if (new_count >= Size) {
        return false;
    }
    ++Count;

    Heap[new_count] = node;

    Heapify_Up(new_count);

    MaxNodePointer = std::max(MaxNodePointer, reinterpret_cast<std::uintptr_t>(node));
    MinNodePointer = std::min(MinNodePointer, reinterpret_cast<std::uintptr_t>(node));

    return true;
}


template<typename TElement, typename TPriority>
PriorityQueueClassNode<TElement, TPriority> *PriorityQueueClass<TElement, TPriority>::Extract()
{
    if (Is_Empty()) {
        return nullptr;
    }

    PriorityQueueClassNode<TElement, TPriority> *root_node = Heap[1];
    Heap[1] = Heap[Count];
    Heap[Count] = nullptr;
    --Count;

    Heapify_Down(1);

    return root_node;
}


template<typename TElement, typename TPriority>
void PriorityQueueClass<TElement, TPriority>::Resize(int new_size)
{
    TSPP_ASSERT(new_size >= 0);

    if (Size == new_size) {
        return;
    }

    PriorityQueueClassNode<TElement, TPriority> **new_heap = new PriorityQueueClassNode<TElement, TPriority> *[new_size + 1];
    TSPP_ASSERT(new_heap != nullptr);
    std::memset(new_heap, 0, (new_size + 1) * sizeof(PriorityQueueClassNode<TElement, TPriority> *));

    std::memcpy(new_heap, Heap, (Count + 1) * sizeof(PriorityQueueClassNode<TElement, TPriority> *));
    Release_Heap();
    Heap = new_heap;
    Size = new_size;

    if (Count >= new_size) {

        Count = (new_size <= 0 ? 0 : new_size - 1);
        MaxNodePointer = std::numeric_limits<decltype(MaxNodePointer)>::min();
        MinNodePointer = std::numeric_limits<decltype(MinNodePointer)>::max();

        for (int i = 1; i <= Count; ++i) {
            PriorityQueueClassNode<TElement, TPriority> *current_node = Heap[i];
            TSPP_ASSERT(current_node != nullptr);

            MaxNodePointer = std::max(MaxNodePointer, reinterpret_cast<std::uintptr_t>(current_node));
            MinNodePointer = std::min(MinNodePointer, reinterpret_cast<std::uintptr_t>(current_node));
        }
    }
}


template<typename TElement, typename TPriority>
PriorityQueueClassNode<TElement, TPriority> *PriorityQueueClass<TElement, TPriority>::Find(const TElement &element) const
{
    int i = Internal_Find(element);
    return (i == -1 ? nullptr : Heap[i]);
}


template<typename TElement, typename TPriority>
bool PriorityQueueClass<TElement, TPriority>::Remove_Matching(const TElement &element)
{
    bool result = false;

    int i = Internal_Find(element);

    if (i != -1) {

        /**
         *  #BUGFIX:
         *  Set the last element to nullptr to keep our Heap clean.
         */
        std::swap(Heap[i], Heap[Count]);
        Heap[Count] = nullptr;
        --Count;

        if (i <= Count) {
            int parent_index = Get_Parent_Index(i);
            TSPP_ASSERT(i >= 0);
            TSPP_ASSERT(i <= Size);
            TSPP_ASSERT(i == 1 || Heap[i] != nullptr);
            TSPP_ASSERT(i == 1 || Heap[parent_index] != nullptr);
            if (i > 1 && PriorityQueueClassNode<TElement, TPriority>::Compare_Priority(Heap[i]->Get_Priority(), Heap[parent_index]->Get_Priority())) {
                Heapify_Up(i);
            } else {
                Heapify_Down(i);
            }
        }
    }

    return result;
}


template<typename TElement, typename TPriority>
bool PriorityQueueClass<TElement, TPriority>::Update_Priority(const TElement &element, const TPriority &priority)
{
    int i = Internal_Find(element);
    if (i == -1) {
        return false;
    }

    if (PriorityQueueClassNode<TElement, TPriority>::Compare_Priority(priority, Heap[i]->Get_Priority())) {
        Heap[i]->Set_Priority(priority);
        Heapify_Down(i);
    } else {
        Heap[i]->Set_Priority(priority);
        Heapify_Up(i);
    }

    return true;
}


template<typename TElement, typename TPriority>
bool PriorityQueueClass<TElement, TPriority>::Update_Priority(const TElement &element, TPriority &&priority)
{
    int i = Internal_Find(element);
    if (i == -1) {
        return false;
    }

    if (PriorityQueueClassNode<TElement, TPriority>::Compare_Priority(priority, Heap[i]->Get_Priority())) {
        Heap[i]->Set_Priority(std::move(priority));
        Heapify_Down(i);
    } else {
        Heap[i]->Set_Priority(std::move(priority));
        Heapify_Up(i);
    }

    return true;
}


template<typename TElement, typename TPriority>
void PriorityQueueClass<TElement, TPriority>::Release_Heap()
{
    delete[] Heap;
    Heap = nullptr;
}


template<typename TElement, typename TPriority>
void PriorityQueueClass<TElement, TPriority>::Heapify_Up(int index)
{
    TSPP_ASSERT(index > 0);
    TSPP_ASSERT(index <= Size);

    while (index > 1) {
        int parent_index = Get_Parent_Index(index);
        TSPP_ASSERT(parent_index >= 0);
        TSPP_ASSERT(parent_index <= Size);

        PriorityQueueClassNode<TElement, TPriority> *current_node = Heap[index];
        TSPP_ASSERT(current_node != nullptr);
        PriorityQueueClassNode<TElement, TPriority> *parent_node = Heap[parent_index];
        TSPP_ASSERT(parent_node != nullptr);

        if (PriorityQueueClassNode<TElement, TPriority>::Compare_Priority(current_node->Get_Priority(), parent_node->Get_Priority())) {
            break;
        }

        std::swap(Heap[index], Heap[parent_index]);
        index = parent_index;
    }
}


template<typename TElement, typename TPriority>
void PriorityQueueClass<TElement, TPriority>::Heapify_Down(int index)
{
    TSPP_ASSERT(index > 0);
    TSPP_ASSERT(index <= Size);

    for (;;) {
        int absolute_node_index = index;

        int left_index = Get_Left_Index(index);
        if (left_index <= Count) {
            TSPP_ASSERT(Heap[index] != nullptr);
            TSPP_ASSERT(Heap[left_index] != nullptr);
            if (PriorityQueueClassNode<TElement, TPriority>::Compare_Priority(Heap[index]->Get_Priority(), Heap[left_index]->Get_Priority())) {
                absolute_node_index = left_index;
            }
        }

        int right_index = Get_Right_Index(index);
        if (right_index <= Count) {
            TSPP_ASSERT(Heap[absolute_node_index] != nullptr);
            TSPP_ASSERT(Heap[right_index] != nullptr);
            if (PriorityQueueClassNode<TElement, TPriority>::Compare_Priority(Heap[absolute_node_index]->Get_Priority(), Heap[right_index]->Get_Priority())) {
                absolute_node_index = right_index;
            }
        }

        if (absolute_node_index == index) {
            break;
        }

        std::swap(Heap[index], Heap[absolute_node_index]);
        index = absolute_node_index;
    }
}


template<typename TElement, typename TPriority>
void PriorityQueueClass<TElement, TPriority>::Internal_Copy_Heap(const PriorityQueueClass<TElement, TPriority> &that)
{
    TSPP_ASSERT(Heap == nullptr);
    TSPP_ASSERT(that.Heap != nullptr);
    TSPP_ASSERT(that.Size >= 0);
    TSPP_ASSERT(that.Count >= 0);

    Heap = new PriorityQueueClassNode<TElement, TPriority> *[Size + 1];
    TSPP_ASSERT(Heap != nullptr);
    std::memset(Heap, 0, (Size + 1) * sizeof(PriorityQueueClassNode<TElement, TPriority> *));

    std::memcpy(Heap, that.Heap, (Count + 1) * sizeof(PriorityQueueClassNode<TElement, TPriority> *));
}


template<typename TElement, typename TPriority>
int PriorityQueueClass<TElement, TPriority>::Internal_Find(const TElement &element) const
{
    int i = 1;
    for (; i <= Count; ++i) {
        TSPP_ASSERT(Heap[i] != nullptr);
        if (Heap[i]->Get_Element() == element) {
            return i;
        }
    }

    return -1;
}


template<typename TElement, typename TPriority>
int PriorityQueueClass<TElement, TPriority>::Get_Parent_Index(int index)
{
    TSPP_ASSERT(index > 0);
    return (index / 2);
}


template<typename TElement, typename TPriority>
int PriorityQueueClass<TElement, TPriority>::Get_Left_Index(int index)
{
    TSPP_ASSERT(index > 0);
    return (index * 2);
}


template<typename TElement, typename TPriority>
int PriorityQueueClass<TElement, TPriority>::Get_Right_Index(int index)
{
    TSPP_ASSERT(index > 0);
    return (index * 2 + 1);
}
