/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SEARCH.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Simple unique identifier indexer.
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
#include <cstdlib>


template<typename I, class T>
class IndexClass
{
    private:
        struct NodeElement
        {
            void operator=(const NodeElement &node) { ID = node.ID; Data = node.Data; }
            bool operator==(const NodeElement &node) const { return ID == node.ID; }
            bool operator<(const NodeElement &node) const { return ID < node.ID; }
            bool operator>(const NodeElement &node) const { return ID > node.ID; }

            I ID;
            T Data;
        };

    public:
        IndexClass();
        ~IndexClass();

        const T &operator[](const I &id) const
        {
            static T _x = (T());

            if (Is_Present(id)) {
                return Archive->Data;
            }
            return _x;
        }

        bool Add_Index(const I &id, const T &data);
        bool Remove_Index(const I &id);
        bool Is_Present(const I &id) const;
        int Count() const;
        T &Fetch_By_Position(int index);
        I Fetch_ID_By_Position(int index);
        void Clear();

        /**
         *  #NOTE:
         *  This function is for fetching an element based on the data, rather
         *  than the id and is not for general/consistent use!
         */
        I Fetch_ID_By_Data(const T &data)
        {
            if (Archive) {
                if (Archive->Data == data) {
                    return Archive->ID;
                }
            }
            for (int i = 0; i < IndexCount; ++i) {
                const NodeElement *node = &IndexTable[i];
                if (node->Data == data) {
                    return node->ID;
                }
            }
            return I(-1);
        }

        const NodeElement *Get_Archive() const
        {
            return Archive;
        }

    public:
        bool Increase_Table_Size(int amount);
        bool Is_Archive_Same(const I &id) const;
        void Invalidate_Archive();
        void Set_Archive(const NodeElement * node);
        bool Sort_Table();
        const NodeElement * Search_For_Node(const I &id) const;
        static int __cdecl search_compfunc(void const * ptr, void const * ptr2);

    private:
        NodeElement * IndexTable;
        int IndexCount;
        int IndexSize;
        bool IsSorted;
        const NodeElement * Archive;

    private:
        IndexClass(const IndexClass &) = delete;
        IndexClass * operator = (const IndexClass &) = delete;
};


template<typename I, class T>
IndexClass<I, T>::IndexClass() :
    IndexTable(nullptr),
    IndexCount(0),
    IndexSize(0),
    IsSorted(false),
    Archive(nullptr)
{
    Invalidate_Archive();
}


template<typename I, class T>
IndexClass<I, T>::~IndexClass()
{
    Clear();
}


template<typename I, class T>
void IndexClass<I, T>::Clear()
{
    delete [] IndexTable;
    IndexTable = nullptr;

    IndexCount = 0;
    IndexSize = 0;
    IsSorted = false;
    Invalidate_Archive();
}


template<typename I, class T>
bool IndexClass<I, T>::Increase_Table_Size(int amount)
{
    TSPP_ASSERT(amount > 0);

    if (amount < 0) return false;

    TSPP_ASSERT(IndexCount < IndexSize + amount);

    NodeElement * table = new NodeElement[IndexSize + amount];
    if (table != nullptr) {
        for (int index = 0; index < IndexCount; index++) {
            table[index] = IndexTable[index];
        }

        delete [] IndexTable;
        IndexTable = table;
        IndexSize += amount;
        Invalidate_Archive();

        return true;
    }

    return false;
}


template<typename I, class T>
int IndexClass<I, T>::Count() const
{
    return IndexCount;
}


template<typename I, class T>
bool IndexClass<I, T>::Is_Present(const I &id) const
{
    if (IndexCount == 0) {
        return false;
    }

    if (Is_Archive_Same(id)) {
        return true;
    }

    const NodeElement * nodeptr = Search_For_Node(id);

    if (nodeptr != nullptr) {
        const_cast<IndexClass<I, T> *>(this)->Set_Archive(nodeptr);
        return true;
    }

    return false;
}


template<typename I, class T>
T & IndexClass<I, T>::Fetch_By_Position(int index)
{
    TSPP_ASSERT(index < IndexCount);
    return IndexTable[index].Data;
}


template<typename I, class T>
I IndexClass<I, T>::Fetch_ID_By_Position(int index)
{
    TSPP_ASSERT(index < IndexCount);
    return IndexTable[index].ID;
}


template<typename I, class T>
bool IndexClass<I, T>::Is_Archive_Same(const I &id) const
{
    if (Archive != nullptr && Archive->ID == id) {
        return true;
    }
    return false;
}


template<typename I, class T>
void IndexClass<I, T>::Invalidate_Archive()
{
    Archive = nullptr;
}


template<typename I, class T>
void IndexClass<I, T>::Set_Archive(const NodeElement * node)
{
    Archive = node;
}


template<typename I, class T>
bool IndexClass<I, T>::Add_Index(const I &id, const T &data)
{
    for (int index = 0; index < IndexCount; ++index) {
        TSPP_ASSERT(IndexTable[index].ID != id);
    }

    if (IndexCount + 1 > IndexSize) {
        if (!Increase_Table_Size(IndexSize == 0 ? 10 : IndexSize)) {
            return false;
        }
    }

    IndexTable[IndexCount].ID = id;
    IndexTable[IndexCount].Data = data;
    IndexCount++;
    IsSorted = false;

    return true;
}


template<typename I, class T>
bool IndexClass<I, T>::Remove_Index(const I &id)
{
    const NodeElement *found = Search_For_Node(id);
    if (!found) {
        return false;
    }

    int found_index = found - IndexTable;
    TSPP_ASSERT(found_index >= 0 && found_index < IndexCount);

    if (found_index != -1) {

        for (int index = found_index+1; index < IndexCount; index++) {
            IndexTable[index-1] = IndexTable[index];
        }
        IndexCount--;

        NodeElement fake;
        fake.ID = I(0);
        fake.Data = T();
        IndexTable[IndexCount] = fake;

        Invalidate_Archive();
        return true;
    }

    return false;
}


template<typename I, class T>
int __cdecl IndexClass<I, T>::search_compfunc(void const * ptr1, void const * ptr2)
{
    const NodeElement *n1 = static_cast<const NodeElement *>(ptr1);
    const NodeElement *n2 = static_cast<const NodeElement *>(ptr2);

    if (n1->ID == n2->ID) {
        return 0;
    }
    if (n1->ID < n2->ID) {
        return -1;
    }
    return 1;
}


template<typename I, class T>
bool IndexClass<I, T>::Sort_Table()
{
    if (!IsSorted) {
        std::qsort(IndexTable, IndexCount, sizeof(NodeElement), search_compfunc);
        IsSorted = true;
        Invalidate_Archive();
        return true;
    }

    return false;
}


template<typename I, class T> 
const typename IndexClass<I, T>::NodeElement * IndexClass<I, T>::Search_For_Node(const I &id) const
{
    if (IndexCount == 0) {
        return nullptr;
    }

    const_cast<IndexClass<I, T> *>(this)->Sort_Table();

    NodeElement node;
    node.ID = id;
    return static_cast<const NodeElement *>(std::bsearch(&node, &IndexTable[0], IndexCount, sizeof(IndexTable[0]), search_compfunc));
}
