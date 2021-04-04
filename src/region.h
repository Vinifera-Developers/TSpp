/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          REGION.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Map threat region tracker.
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


class RegionClass
{
	public:
		RegionClass() { Threat = 0; }
		~RegionClass() {}

		int operator != (RegionClass const & region) { return std::memcmp(this, &region, sizeof(RegionClass)); }
		int operator == (RegionClass const & region) { return !std::memcmp(this, &region, sizeof(RegionClass)); }
		int operator > (RegionClass const & region) { return std::memcmp(this, &region, sizeof(RegionClass)) > 0; }
		int operator < (RegionClass const & region) { return std::memcmp(this, &region, sizeof(RegionClass)) < 0; }

		void Reset_Threat() { Threat = 0; }
		void Adjust_Threat(int threat, int neg) { if (neg) Threat -= threat; else Threat+= threat; }
		int Threat_Value() const { return Threat; }

	protected:
		long Threat;
};
