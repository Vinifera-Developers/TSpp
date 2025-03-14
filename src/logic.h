/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          LOGIC.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Game logic processing.
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

#include "layer.h"


class ObjectClass;
class AbstractClass;


class LogicClass : public LayerClass
{
	public:
		LogicClass();
		virtual ~LogicClass();

		/**
		 *  LogicClass
		 */
		virtual bool Submit(ObjectClass const *object, bool sort = false);
		virtual void Init();
		virtual void One_Time();

		virtual void Detach(AbstractClass * target, bool all = true);

		void AI();
		void func_507210(); // looks like an older version of AI()?
		void Remove(ObjectClass *const object);

		static void func_507470();

	public:
		static unsigned &FramesPerSecond;
};
