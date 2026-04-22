/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  A hash dictionary.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) Electronic Arts
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/

#pragma once

#include <cassert>
#include <cstddef>
#include <cstdio>
#include <iterator>
#include <tuple>
#include <utility>


/**
 *  Node stored in each hash bucket.
 */
template<class K, class V>
class DNode
{
public:
    K key;
    V value;
    DNode* hashNext;
};


template<std::size_t I, class K, class V>
decltype(auto) get(DNode<K, V>& node) noexcept
{
    static_assert(I < 2, "DNode only exposes key and value for structured bindings.");

    if constexpr (I == 0) {
        return (node.key);
    } else {
        return (node.value);
    }
}


template<std::size_t I, class K, class V>
decltype(auto) get(const DNode<K, V>& node) noexcept
{
    static_assert(I < 2, "DNode only exposes key and value for structured bindings.");

    if constexpr (I == 0) {
        return (node.key);
    } else {
        return (node.value);
    }
}


template<std::size_t I, class K, class V>
decltype(auto) get(DNode<K, V>&& node) noexcept
{
    static_assert(I < 2, "DNode only exposes key and value for structured bindings.");

    if constexpr (I == 0) {
        return std::move(node.key);
    } else {
        return std::move(node.value);
    }
}


template<std::size_t I, class K, class V>
decltype(auto) get(const DNode<K, V>&& node) noexcept
{
    static_assert(I < 2, "DNode only exposes key and value for structured bindings.");

    if constexpr (I == 0) {
        return std::move(node.key);
    } else {
        return std::move(node.value);
    }
}


namespace std
{
template<class K, class V>
struct tuple_size<DNode<K, V>> : integral_constant<std::size_t, 2> {
};

template<class K, class V>
struct tuple_element<0, DNode<K, V>> {
    using type = K;
};

template<class K, class V>
struct tuple_element<1, DNode<K, V>> {
    using type = V;
};
} // namespace std


template<class K, class V>
class Dictionary
{
public:
    /**
     *  Forward iterator over dictionary nodes.
     *
     *  Mutating the dictionary invalidates all iterators.
     */
    class iterator
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = DNode<K, V>;
        using difference_type = std::ptrdiff_t;
        using pointer = DNode<K, V>*;
        using reference = DNode<K, V>&;

        iterator() : Owner(nullptr), Bucket(0), Node(nullptr) {}

        reference operator*() const { return *Node; }
        pointer operator->() const { return Node; }

        iterator& operator++()
        {
            Advance();
            return *this;
        }

        iterator operator++(int)
        {
            iterator tmp(*this);
            Advance();
            return tmp;
        }

        bool operator==(const iterator& that) const { return Owner == that.Owner && Bucket == that.Bucket && Node == that.Node; }
        bool operator!=(const iterator& that) const { return !(*this == that); }

    private:
        friend class Dictionary;
        friend class const_iterator;

        iterator(Dictionary* owner, uint32_t bucket, DNode<K, V>* node) : Owner(owner), Bucket(bucket), Node(node) {}

        void Advance()
        {
            if (Owner == nullptr || Node == nullptr) {
                if (Owner != nullptr) {
                    Bucket = Owner->getSize();
                }
                Node = nullptr;
                return;
            }

            if (Node->hashNext != nullptr) {
                Node = Node->hashNext;
                return;
            }

            ++Bucket;
            while (Bucket < Owner->getSize() && Owner->table[Bucket] == nullptr) {
                ++Bucket;
            }

            Node = (Bucket < Owner->getSize()) ? Owner->table[Bucket] : nullptr;
        }

    private:
        Dictionary* Owner;
        uint32_t Bucket;
        DNode<K, V>* Node;
    };

    /**
     *  Constant forward iterator over dictionary nodes.
     *
     *  Mutating the dictionary invalidates all iterators.
     */
    class const_iterator
    {
    public:
        using iterator_category = std::forward_iterator_tag;
        using value_type = const DNode<K, V>;
        using difference_type = std::ptrdiff_t;
        using pointer = const DNode<K, V>*;
        using reference = const DNode<K, V>&;

        const_iterator() : Owner(nullptr), Bucket(0), Node(nullptr) {}
        const_iterator(const iterator& that) : Owner(that.Owner), Bucket(that.Bucket), Node(that.Node) {}

        reference operator*() const { return *Node; }
        pointer operator->() const { return Node; }

        const_iterator& operator++()
        {
            Advance();
            return *this;
        }

        const_iterator operator++(int)
        {
            const_iterator tmp(*this);
            Advance();
            return tmp;
        }

        bool operator==(const const_iterator& that) const { return Owner == that.Owner && Bucket == that.Bucket && Node == that.Node; }
        bool operator!=(const const_iterator& that) const { return !(*this == that); }

    private:
        friend class Dictionary;

        const_iterator(const Dictionary* owner, uint32_t bucket, const DNode<K, V>* node) : Owner(owner), Bucket(bucket), Node(node) {}

        void Advance()
        {
            if (Owner == nullptr || Node == nullptr) {
                if (Owner != nullptr) {
                    Bucket = Owner->getSize();
                }
                Node = nullptr;
                return;
            }

            if (Node->hashNext != nullptr) {
                Node = Node->hashNext;
                return;
            }

            ++Bucket;
            while (Bucket < Owner->getSize() && Owner->table[Bucket] == nullptr) {
                ++Bucket;
            }

            Node = (Bucket < Owner->getSize()) ? Owner->table[Bucket] : nullptr;
        }

    private:
        const Dictionary* Owner;
        uint32_t Bucket;
        const DNode<K, V>* Node;
    };

    /**
     *  Creates an empty hash dictionary.
     */
    Dictionary(uint32_t (*hash_fn)(const K& key));

    /**
     *  Dictionary instances are non-copyable.
     */
    Dictionary(const Dictionary&) = delete;
    Dictionary& operator=(const Dictionary&) = delete;

    /**
     *  Frees all dictionary storage.
     */
    ~Dictionary();

    /**
     *  Removes every entry from the dictionary.
     */
    void clear();

    /**
     *  Adds a key/value pair to the dictionary.
     *
     *  If the key already exists, its value is replaced.
     */
    bool add(const K& key, const V& value);

    /**
     *  Retrieves a copy of the value for the specified key.
     */
    bool getValue(const K& key, V& value) const;

    /**
     *  Retrieves a pointer to the internally stored value for the specified key.
     */
    bool getPointer(const K& key, V** value) const;

    /**
     *  Prints a simple bucket visualization of the dictionary.
     */
    void print(FILE* out) const;

    /**
     *  Returns the current bucket count.
     */
    uint32_t getSize() const;

    /**
     *  Returns the current number of stored entries.
     */
    uint32_t getEntries() const;

    /**
     *  Returns true if the dictionary contains no entries.
     */
    bool empty() const;

    /**
     *  Checks whether the specified key exists.
     */
    bool contains(const K& key) const;

    /**
     *  Replaces the value for an existing key.
     */
    bool updateValue(const K& key, const V& value);

    /**
     *  Removes the specified key and copies out its value.
     */
    bool remove(const K& key, V& value);

    /**
     *  Removes the specified key without returning its value.
     */
    bool remove(const K& key);

    /**
     *  Removes and returns any key/value pair from the dictionary.
     */
    bool removeAny(K& key, V& value);

    /**
     *  Iterates over all stored values.
     *
     *  Set both `index` and `offset` to `0`, then call until this returns `false`.
     */
    bool iterate(int& index, int& offset, V& value) const;

    /**
     *  Iterates over all stored key/value pairs.
     *
     *  Set both `index` and `offset` to `0`, then call until this returns `false`.
     */
    bool iterate(int& index, int& offset, K& key, V& value) const;

    /**
     *  Finds the specified key and returns an iterator to it.
     */
    iterator find(const K& key);

    /**
     *  Finds the specified key and returns a constant iterator to it.
     */
    const_iterator find(const K& key) const;

    /**
     *  Returns an iterator to the first node in the dictionary.
     */
    iterator begin();

    /**
     *  Returns an iterator one past the last node in the dictionary.
     */
    iterator end();

    /**
     *  Returns a constant iterator to the first node in the dictionary.
     */
    const_iterator begin() const;

    /**
     *  Returns a constant iterator one past the last node in the dictionary.
     */
    const_iterator end() const;

    /**
     *  Returns a constant iterator to the first node in the dictionary.
     */
    const_iterator cbegin() const;

    /**
     *  Returns a constant iterator one past the last node in the dictionary.
     */
    const_iterator cend() const;

private:
    /**
     *  Halves the number of hash buckets.
     */
    void shrink();

    /**
     *  Doubles the number of hash buckets.
     */
    void expand();

    /**
     *  Rebuilds the hash table using a new bucket count.
     */
    void resize(uint32_t new_size);

    /**
     *  Finds the node for the specified key.
     */
    DNode<K, V>* findNode(const K& key) const;

    /**
     *  Removes the node for the specified key and optionally copies out its value.
     */
    bool removeImpl(const K& key, V* value);

private:
    DNode<K, V>** table; // Stores the linked list head for each bucket.

    uint32_t entries;   // Number of entries.
    uint32_t size;      // Bucket count.
    uint32_t tableBits; // Table is 2^tableBits buckets wide.
    uint32_t log2Size;  // Preserved for ABI compatibility with the original layout.
    char keepSize;      // If true, the table will not shrink or expand.

    uint32_t (*hashFunc)(const K& key); // User-provided hash function.

    /**
     *  Reduces a key hash to the current bucket range.
     */
    uint32_t keyHash(const K& key) const;

    const double SHRINK_THRESHOLD;
    const double EXPAND_THRESHOLD;
    const int MIN_TABLE_SIZE;
};


/**
 *  Creates an empty hash dictionary.
 */
template<class K, class V>
Dictionary<K, V>::Dictionary(uint32_t (*hash_fn)(const K& key)) :
    table(nullptr),
    entries(0),
    size(0),
    tableBits(0),
    log2Size(0),
    keepSize(0),
    hashFunc(hash_fn),
    SHRINK_THRESHOLD(0.20),
    EXPAND_THRESHOLD(0.80),
    MIN_TABLE_SIZE(128)
{
    assert(hashFunc != nullptr);

    log2Size = MIN_TABLE_SIZE;
    size = MIN_TABLE_SIZE;
    assert(size >= 4);

    tableBits = 0;
    while (log2Size != 0) {
        ++tableBits;
        log2Size >>= 1;
    }
    --tableBits;
    size = 1U << tableBits;

    table = new DNode<K, V>*[size]();
}


/**
 *  Frees all dictionary storage.
 */
template<class K, class V>
Dictionary<K, V>::~Dictionary()
{
    clear();
    delete[] table;
}


/**
 *  Removes all entries and releases their nodes.
 */
template<class K, class V>
void Dictionary<K, V>::clear()
{
    for (uint32_t i = 0; i < size; ++i) {
        DNode<K, V>* temp = table[i];
        while (temp != nullptr) {
            DNode<K, V>* del = temp;
            temp = temp->hashNext;
            delete del;
        }
        table[i] = nullptr;
    }

    entries = 0;

    while (getSize() > MIN_TABLE_SIZE && !keepSize) {
        shrink();
    }
}


/**
 *  Reduces a key hash to the current bucket range.
 */
template<class K, class V>
uint32_t Dictionary<K, V>::keyHash(const K& key) const
{
    const uint32_t retval = hashFunc(key) & ((1U << tableBits) - 1U);
    assert(retval < getSize());
    return retval;
}


/**
 *  Prints a simple bucket visualization of the dictionary.
 */
template<class K, class V>
void Dictionary<K, V>::print(FILE* out) const
{
    if (out == nullptr) {
        return;
    }

    fprintf(out, "--------------------\n");
    for (uint32_t i = 0; i < getSize(); ++i) {
        DNode<K, V>* temp = table[i];

        fprintf(out, " |\n");
        fprintf(out, "[ ]");

        while (temp != nullptr) {
            fprintf(out, "--[ ]");
            temp = temp->hashNext;
        }
        fprintf(out, "\n");
    }
    fprintf(out, "--------------------\n");
}


/**
 *  Iterates through all stored values.
 */
template<class K, class V>
bool Dictionary<K, V>::iterate(int& index, int& offset, V& value) const
{
    if (index < 0 || index >= static_cast<int>(getSize())) {
        return false;
    }

    DNode<K, V>* temp = table[index];
    while (temp == nullptr && ++index < static_cast<int>(getSize())) {
        temp = table[index];
        offset = 0;
    }

    if (temp == nullptr) {
        return false;
    }

    uint32_t i = 0;
    while (temp != nullptr && static_cast<int>(i) < offset) {
        temp = temp->hashNext;
        ++i;
    }

    if (temp == nullptr) {
        return false;
    }

    value = temp->value;
    if (temp->hashNext == nullptr) {
        ++index;
        offset = 0;
    } else {
        ++offset;
    }

    return true;
}


/**
 *  Iterates through all stored key/value pairs.
 */
template<class K, class V>
bool Dictionary<K, V>::iterate(int& index, int& offset, K& key, V& value) const
{
    if (index < 0 || index >= static_cast<int>(getSize())) {
        return false;
    }

    DNode<K, V>* temp = table[index];
    while (temp == nullptr && ++index < static_cast<int>(getSize())) {
        temp = table[index];
        offset = 0;
    }

    if (temp == nullptr) {
        return false;
    }

    uint32_t i = 0;
    while (temp != nullptr && static_cast<int>(i) < offset) {
        temp = temp->hashNext;
        ++i;
    }

    if (temp == nullptr) {
        return false;
    }

    value = temp->value;
    key = temp->key;
    if (temp->hashNext == nullptr) {
        ++index;
        offset = 0;
    } else {
        ++offset;
    }

    return true;
}


/**
 *  Returns an iterator to the first node in the dictionary.
 */
template<class K, class V>
typename Dictionary<K, V>::iterator Dictionary<K, V>::begin()
{
    for (uint32_t i = 0; i < getSize(); ++i) {
        if (table[i] != nullptr) {
            return iterator(this, i, table[i]);
        }
    }

    return end();
}


/**
 *  Returns an iterator one past the last node in the dictionary.
 */
template<class K, class V>
typename Dictionary<K, V>::iterator Dictionary<K, V>::end()
{
    return iterator(this, getSize(), nullptr);
}


/**
 *  Returns a constant iterator to the first node in the dictionary.
 */
template<class K, class V>
typename Dictionary<K, V>::const_iterator Dictionary<K, V>::begin() const
{
    return cbegin();
}


/**
 *  Returns a constant iterator one past the last node in the dictionary.
 */
template<class K, class V>
typename Dictionary<K, V>::const_iterator Dictionary<K, V>::end() const
{
    return cend();
}


/**
 *  Returns a constant iterator to the first node in the dictionary.
 */
template<class K, class V>
typename Dictionary<K, V>::const_iterator Dictionary<K, V>::cbegin() const
{
    for (uint32_t i = 0; i < getSize(); ++i) {
        if (table[i] != nullptr) {
            return const_iterator(this, i, table[i]);
        }
    }

    return cend();
}


/**
 *  Returns a constant iterator one past the last node in the dictionary.
 */
template<class K, class V>
typename Dictionary<K, V>::const_iterator Dictionary<K, V>::cend() const
{
    return const_iterator(this, getSize(), nullptr);
}


/**
 *  Returns the current bucket count.
 */
template<class K, class V>
uint32_t Dictionary<K, V>::getSize() const
{
    return size;
}


/**
 *  Returns the current number of stored entries.
 */
template<class K, class V>
uint32_t Dictionary<K, V>::getEntries() const
{
    return entries;
}


/**
 *  Returns true if the dictionary contains no entries.
 */
template<class K, class V>
bool Dictionary<K, V>::empty() const
{
    return entries == 0;
}


/**
 *  Checks whether the specified key exists.
 */
template<class K, class V>
bool Dictionary<K, V>::contains(const K& key) const
{
    return findNode(key) != nullptr;
}


/**
 *  Finds the specified key and returns an iterator to it.
 */
template<class K, class V>
typename Dictionary<K, V>::iterator Dictionary<K, V>::find(const K& key)
{
    DNode<K, V>* node = findNode(key);
    if (node == nullptr) {
        return end();
    }

    return iterator(this, keyHash(key), node);
}


/**
 *  Finds the specified key and returns a constant iterator to it.
 */
template<class K, class V>
typename Dictionary<K, V>::const_iterator Dictionary<K, V>::find(const K& key) const
{
    DNode<K, V>* node = findNode(key);
    if (node == nullptr) {
        return cend();
    }

    return const_iterator(this, keyHash(key), node);
}


/**
 *  Replaces the value for an existing key.
 */
template<class K, class V>
bool Dictionary<K, V>::updateValue(const K& key, const V& value)
{
    if (!remove(key)) {
        return false;
    }

    add(key, value);
    return true;
}


/**
 *  Adds a key/value pair to the dictionary.
 */
template<class K, class V>
bool Dictionary<K, V>::add(const K& key, const V& value)
{
    DNode<K, V>* item = new DNode<K, V>;
    item->key = key;
    item->value = value;
    item->hashNext = nullptr;

    remove(key);

    const uint32_t offset = keyHash(key);
    item->hashNext = table[offset];
    table[offset] = item;

    ++entries;

    const float percent = static_cast<float>(entries) / static_cast<float>(getSize());
    if (percent >= EXPAND_THRESHOLD) {
        expand();
    }

    return true;
}


/**
 *  Removes an item from the dictionary and copies out its value.
 */
template<class K, class V>
bool Dictionary<K, V>::remove(const K& key, V& value)
{
    return removeImpl(key, &value);
}


/**
 *  Removes an item from the dictionary without copying out its value.
 */
template<class K, class V>
bool Dictionary<K, V>::remove(const K& key)
{
    return removeImpl(key, nullptr);
}


/**
 *  Removes and returns any key/value pair from the dictionary.
 */
template<class K, class V>
bool Dictionary<K, V>::removeAny(K& key, V& value)
{
    if (entries == 0) {
        return false;
    }

    int offset = -1;
    for (uint32_t i = 0; i < getSize(); ++i) {
        if (table[i] != nullptr) {
            offset = static_cast<int>(i);
            break;
        }
    }

    if (offset == -1) {
        return false;
    }

    DNode<K, V>* node = table[offset];
    key = node->key;
    value = node->value;

    table[offset] = node->hashNext;
    delete node;
    --entries;

    const float percent = static_cast<float>(entries) / static_cast<float>(getSize());
    if (percent <= SHRINK_THRESHOLD) {
        shrink();
    }

    return true;
}


/**
 *  Retrieves a copy of the value for the specified key.
 */
template<class K, class V>
bool Dictionary<K, V>::getValue(const K& key, V& value) const
{
    V* valptr = nullptr;
    const bool retval = getPointer(key, &valptr);
    if (retval && valptr != nullptr) {
        value = *valptr;
    }
    return retval;
}


/**
 *  Retrieves a pointer to the internally stored value for the specified key.
 */
template<class K, class V>
bool Dictionary<K, V>::getPointer(const K& key, V** valptr) const
{
    if (valptr == nullptr) {
        return false;
    }

    *valptr = nullptr;

    DNode<K, V>* node = findNode(key);
    if (node == nullptr) {
        return false;
    }

    *valptr = &node->value;
    return true;
}


/**
 *  Halves the number of hash buckets.
 */
template<class K, class V>
void Dictionary<K, V>::shrink()
{
    if (size <= MIN_TABLE_SIZE || keepSize) {
        return;
    }

    resize(size / 2);
}


/**
 *  Doubles the number of hash buckets.
 */
template<class K, class V>
void Dictionary<K, V>::expand()
{
    if (keepSize) {
        return;
    }

    resize(size * 2);
}


/**
 *  Rebuilds the hash table using a new bucket count.
 */
template<class K, class V>
void Dictionary<K, V>::resize(uint32_t new_size)
{
    DNode<K, V>** oldtable = table;
    const uint32_t oldsize = size;

    size = new_size;
    tableBits = 0;
    log2Size = size;
    while (log2Size != 0) {
        ++tableBits;
        log2Size >>= 1;
    }
    --tableBits;
    table = new DNode<K, V>*[size]();

    for (uint32_t i = 0; i < oldsize; ++i) {
        DNode<K, V>* temp = oldtable[i];
        while (temp != nullptr) {
            const uint32_t offset = keyHash(temp->key);
            DNode<K, V>* next = temp->hashNext;

            temp->hashNext = table[offset];
            table[offset] = temp;
            temp = next;
        }
    }

    delete[] oldtable;
}


/**
 *  Finds the node for the specified key.
 */
template<class K, class V>
DNode<K, V>* Dictionary<K, V>::findNode(const K& key) const
{
    if (entries == 0) {
        return nullptr;
    }

    DNode<K, V>* node = table[keyHash(key)];
    while (node != nullptr && !(node->key == key)) {
        node = node->hashNext;
    }

    return node;
}


/**
 *  Removes the node for the specified key and optionally copies out its value.
 */
template<class K, class V>
bool Dictionary<K, V>::removeImpl(const K& key, V* value)
{
    if (entries == 0) {
        return false;
    }

    const uint32_t offset = keyHash(key);
    DNode<K, V>* node = table[offset];
    DNode<K, V>* previous = nullptr;

    while (node != nullptr && !(node->key == key)) {
        previous = node;
        node = node->hashNext;
    }

    if (node == nullptr) {
        return false;
    }

    if (value != nullptr) {
        *value = node->value;
    }

    if (previous == nullptr) {
        table[offset] = node->hashNext;
    } else {
        previous->hashNext = node->hashNext;
    }

    delete node;
    --entries;

    const float percent = static_cast<float>(entries) / static_cast<float>(getSize());
    if (percent <= SHRINK_THRESHOLD) {
        shrink();
    }

    return true;
}
