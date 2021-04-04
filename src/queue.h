/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          QUEUE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         FIFO queue for events.
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


template<class T, int size>
class QueueClass
{
	public:
		QueueClass();
        ~QueueClass() {}

		T & operator[](int index);

		T & First();
		void Init();
		int Next();
        bool Add(const T &q);

		int Get_Head();
		int Get_Tail();
		T * Get_Array();

	public:
		int Count;

	private:
		int Head;
		int Tail;
		T Array[size];
};


template<class T, int size>
inline QueueClass<T, size>::QueueClass() :
    Count(0)
{
	Init();
}


template<class T, int size>
inline void QueueClass<T, size>::Init()
{
	Count = 0;
	Head = 0;
	Tail = 0;
}


template<class T, int size>
inline bool QueueClass<T, size>::Add(const T &q)
{
	if (Count >= size) {
        //OutputDebugString("QueueClass::Add() - Failed! (Count:%d, Capacity:%d, Tail:%d, Head:%d).\n", Count, size, Tail, Head);
        return false;
    }

	if (Count < size) {
		Array[Tail] = q;
		Tail = (Tail + 1) & (size-1);
		Count = Count + 1;
		return true;
	}
	return false;
}


template<class T, int size>
inline int QueueClass<T, size>::Next()
{
	if (Count) {
		Head = (Head + 1) & (size-1);
		Count = Count - 1;
	}
	return Count;
}


template<class T, int size>
inline T & QueueClass<T, size>::operator[](int index)
{
	return Array[(Head + index) & (size-1)];
}


template<class T, int size>
inline T & QueueClass<T, size>::First()
{
	return Array[Head];
}


template<class T, int size>
inline int QueueClass<T, size>::Get_Head()
{
	return Head;
}


template<class T, int size>
inline int QueueClass<T, size>::Get_Tail()
{
	return Tail;
}


template<class T, int size>
inline T * QueueClass<T, size>::Get_Array()
{
	return Array;
}
