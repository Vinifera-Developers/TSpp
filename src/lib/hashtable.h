/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          HASHTABLE.H
 *
 *  @authors       tomsons26, CCHyper
 *
 *  @brief         Hash table container.
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
#include "vector.h"


class HashString
{
    public:
        HashString() : Buffer() {}
        HashString(const char *string)
        {
            std::strncpy(Buffer, string, sizeof(Buffer));
            strupr(Buffer);
        }
        ~HashString() { Buffer[0] = '\0'; }

        bool operator != (const HashString & that) const { return std::strncmp(Buffer, that.Buffer, sizeof(Buffer)) != 0; }
        bool operator == (const HashString & that) const { return std::strncmp(Buffer, that.Buffer, sizeof(Buffer)) == 0; }

        bool operator ! () const { return Buffer[0] == '\0'; }

        HashString & operator=(const HashString & that)
        {
            std::strncpy(Buffer, that.Buffer, sizeof(Buffer));
            return *this;
        }

    private:
        char Buffer[256];
};


template<typename Key, typename Value>
struct HashObject
{
    HashObject() : First(), Second() {}
    ~HashObject() {}

    bool operator != (const HashObject & that) const { return First != that.First; }
    bool operator == (const HashObject & that) const { return First == that.First; }

    bool operator ! () const { return First == 0; }

    Key First;
    Value Second;
};


template<typename Key, typename Value>
class HashTableClass
{
    private:
        using ObjectType = HashObject<Key, Value>;
        using BucketType = DynamicVectorClass<ObjectType>;

    public:
        HashTableClass(int growth_step, int num_buckets, unsigned int (*hash_func)(const Key &));
        ~HashTableClass();

        Value * Find_Object(const Key & key);
        bool Add_Object(const Key & key, const Value & value);
        bool Remove_Object(const Value & key);

        bool Is_Present(const Key & key) { return Find_Object(key) != nullptr; }

    private:
        void Clear();

        /**
         *  A hash function, which hashes the key of the item pointed to
         *  by item to a bucket number between 0 and n-1.
         */
        inline unsigned int Hash(const Key & key) const { return HashFunction(key); }

    private:
        /**
         *  An array of pointers to head items in the linked lists of hash table buckets.
         */
        BucketType *Buckets;

        /**
         *  A pointer to the function for hashing an items key.
         */
        int (*HashFunction)(const Key &);

        /**
         *  The number of buckets in the hash table.
         */
        int NumBuckets;

        /**
         *  When a bucket has insufficient room left, it will grow by the number
         *  of objects specified by this value.
         */
        int GrowthStep;
};


template<typename Key, typename Value>
inline HashTableClass<Key, Value>::HashTableClass(int growth_step, int num_buckets, unsigned int (*hash_func)(const Key &)) :
    Buckets(nullptr),
    HashFunction(hash_func),
    NumBuckets(num_buckets),
    GrowthStep(growth_step)
{
    Buckets = new BucketType[num_buckets];

    if (NumBuckets > 0) {
        for (int index = 0; index < NumBuckets; ++index) {
            Buckets[index].Set_Growth_Step(growth_step);
        }
    }
}


template<typename Key, typename Value>
inline HashTableClass<Key, Value>::~HashTableClass()
{
    Clear();
}


template<typename Key, typename Value>
inline Value * HashTableClass<Key, Value>::Find_Object(const Key & key)
{
    BucketType &bucket = Buckets[Hash(key) % NumBuckets];

    for (int index = bucket.Count()-1; index >= 0; --index) {
        if (bucket[index].First == key) {
            return bucket[index].Second;
        }
    }

    return nullptr;
}


template<typename Key, typename Value>
inline bool HashTableClass<Key, Value>::Add_Object(const Key & key, const Value & value)
{
    BucketType &bucket = Buckets[Hash(key) % NumBuckets];

    for (int index = bucket.Count()-1; index >= 0; --index) {
        if (bucket[index].First == key) {
            return false;
        }
    }

    return bucket.Add(ObjectType(key, value));
}


template<typename Key, typename Value>
inline bool HashTableClass<Key, Value>::Remove_Object(const Value & value)
{
    BucketType &table = Buckets[Hash(key) % NumBuckets];

    return table.Delete(value);
}


template<typename Key, typename Value>
inline void HashTableClass<Key, Value>::Clear()
{
    delete [] Buckets;
    Buckets = nullptr;
}
