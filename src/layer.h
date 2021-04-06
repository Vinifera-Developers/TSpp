/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          LAYER.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Layer object tracker.
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

#include "vector.h"
#include "tibsun_defines.h"


class Straw;
class Pipe;
class ObjectClass;


class LayerClass : public DynamicVectorClass<ObjectClass *>
{
	using VectorClass<ObjectClass *>::Vector;
	using VectorClass<ObjectClass *>::VectorMax;
	using VectorClass<ObjectClass *>::IsAllocated;

	public:
		LayerClass();
		virtual ~LayerClass();

		virtual bool Submit(ObjectClass const *object, bool sort = false);
		virtual void Init();
		virtual void One_Time();

		void Sort();
		bool Sorted_Add(ObjectClass const *object);
		void Remove(ObjectClass *object);
};
