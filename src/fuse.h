/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          FUSE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         The fuse is used by projectiles.
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
#include "ttimer.h"
#include "ftimer.h"
#include "tibsun_defines.h"


class NoInitClass;
class FileClass;


enum FuseResultType
{
	FUSE_DONT_IGNITE,
	FUSE_IGNITE,
	FUSE_2,
};


class FuseClass {
	public:
		FuseClass();
		FuseClass(const NoInitClass &noinit);
		~FuseClass();

		void Arm_Fuse(Coord &location, Coord &target, int time = 255, int arming = 0);
		FuseResultType Fuse_Checkup(Coord &newlocation);

		Coord Fuse_Target()
		{
			return HeadTo;
		}

	public:
		CDTimerClass<FrameTimerClass> Timer;

	private:
		CDTimerClass<FrameTimerClass> Arming;
		Coord HeadTo;
		int Proximity;
};

