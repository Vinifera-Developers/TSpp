/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          LISTNODE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Linked lists.
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


class GenericList;


class GenericNode
{
public:
    GenericNode() : NextNode(nullptr), PrevNode(nullptr) {}
    GenericNode(GenericNode& that) { that.Link(this); }
    virtual ~GenericNode() { Unlink(); }

    GenericNode& operator=(GenericNode& that)
    {
        if (this != &that) {
            that.Link(this);
        }
        return (*this);
    }

    void Unlink()
    {
        if (Is_Valid()) {
            PrevNode->NextNode = NextNode;
            NextNode->PrevNode = PrevNode;
            PrevNode = nullptr;
            NextNode = nullptr;
        }
    }

    GenericList* Main_List() const
    {
        const GenericNode* node = this;
        while (node->PrevNode != nullptr) {
            node = PrevNode;
        }
        return (GenericList*)(this);
    }

    void Link(GenericNode* node)
    {
        TSPP_ASSERT(node != nullptr);

        node->Unlink();
        node->NextNode = NextNode;
        node->PrevNode = this;
        if (NextNode != nullptr) {
            NextNode->PrevNode = node;
        }
        NextNode = node;
    }

    GenericNode* Next() const { return NextNode; }
    GenericNode* Next_Valid() const { return (NextNode != nullptr && NextNode->NextNode != nullptr) ? NextNode : nullptr; }
    GenericNode* Prev() const { return PrevNode; }
    GenericNode* Prev_Valid() const { return (PrevNode != nullptr && PrevNode->PrevNode != nullptr) ? PrevNode : nullptr; }

    bool Is_Valid() const { return (this != nullptr && NextNode != nullptr && PrevNode != nullptr); }

protected:
    GenericNode* NextNode;
    GenericNode* PrevNode;
};


class GenericList
{
private:
    GenericList(const GenericList&) = delete;
    GenericList& operator=(const GenericList&) = delete;

public:
    GenericList() { FirstNode.Link(&LastNode); }

    virtual ~GenericList()
    {
        while (FirstNode.Next()->Is_Valid()) {
            FirstNode.Next()->Unlink();
        }
    }

    GenericNode* First() const { return FirstNode.Next(); }
    GenericNode* First_Valid() const
    {
        GenericNode* node = FirstNode.Next();
        return (node->Next() ? node : nullptr);
    }

    GenericNode* Last() const { return LastNode.Prev(); }
    GenericNode* Last_Valid() const
    {
        GenericNode* node = LastNode.Prev();
        return (node->Prev() ? node : nullptr);
    }

    bool Is_Empty() const { return !FirstNode.Next()->Is_Valid(); }
    void Add_Head(GenericNode* node) { FirstNode.Link(node); }
    void Add_Tail(GenericNode* node) { LastNode.Prev()->Link(node); }

    int Get_Valid_Count() const
    {
        GenericNode* node = First_Valid();
        int counter = 0;
        while (node != nullptr) {
            ++counter;
            node = node->Next_Valid();
        }
        return counter;
    }

protected:
    GenericNode FirstNode;
    GenericNode LastNode;
};


template<class T>
class List;


template<class T>
class Node : public GenericNode
{
public:
    List<T>* Main_List() const { return reinterpret_cast<List<T>*>(GenericNode::Main_List()); }
    T Next() const { return reinterpret_cast<T>(GenericNode::Next()); }
    T Next_Valid() const { return reinterpret_cast<T>(GenericNode::Next_Valid()); }
    T Prev() const { return reinterpret_cast<T>(GenericNode::Prev()); }
    T Prev_Valid() const { return reinterpret_cast<T>(GenericNode::Prev_Valid()); }
    bool Is_Valid() const { return GenericNode::Is_Valid(); }
};


template<class T>
class List : public GenericList
{
private:
    List(const List<T>&) = delete;
    List<T> operator=(const List<T>&) = delete;

public:
    List() {}

    T First() const { return reinterpret_cast<T>(GenericList::First()); }
    T First_Valid() const { return reinterpret_cast<T>(GenericList::First_Valid()); }
    T Last() const { return reinterpret_cast<T>(GenericList::Last()); }
    T Last_Valid() const { return reinterpret_cast<T>(GenericList::Last_Valid()); }

    void Delete()
    {
        while (First()->Is_Valid()) {
            delete First();
        }
    }
};


template<class T>
class DataNode : public GenericNode
{
public:
    DataNode() {}
    DataNode(T value) { Set(value); }

    void Set(T value) { Value = value; }
    T Get() const { return Value; }

    DataNode<T>* Next() const { return reinterpret_cast<DataNode<T>*>(GenericNode::Next()); }
    DataNode<T>* Next_Valid() const { return reinterpret_cast<DataNode<T>*>(GenericNode::Next_Valid()); }
    DataNode<T>* Prev() const { return reinterpret_cast<DataNode<T>*>(GenericNode::Prev()); }
    DataNode<T>* Prev_Valid() const { return reinterpret_cast<DataNode<T>*>(GenericNode::Prev_Valid()); }

private:
    T Value;
};
