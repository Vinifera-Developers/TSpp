/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CRATE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Instance of a goodie crate on the map.
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

#include <always.h>
#include "ttimer.h"
#include "ftimer.h"
#include "tibsun_defines.h"


class CrateClass
{
	public:
		CrateClass();
		~CrateClass();

		void Init();
		bool Create_Crate(CellStruct &cell);
		bool Is_Here(CellStruct &cell) const;
		bool Remove_It();

		bool Is_Expired() const;
		bool Is_Valid() const;
		void Make_Invalid();

		static bool Put_Crate(CellStruct &cell);
		static bool Get_Crate(CellStruct &cell);

	private:
		CDTimerClass<FrameTimerClass> Timer;
		CellStruct Cell;
};
