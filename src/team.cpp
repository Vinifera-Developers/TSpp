/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TEAM.cPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Unit team object class.
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
#include "team.h"
#include "foot.h"
#include "tibsun_globals.h"


/**
 *  Checks to see if unit is an active team member.
 * 
 *  @author: 03/11/1996 JLB
 */
bool Is_It_Breathing(const FootClass *object)
{
	if (object == nullptr || !object->IsActive || object->Strength == 0) {
		return false;
	}

	if (!ScenarioInit && object->IsInLimbo) {
		return false;
	}

	return true;
}


/**
 *  Determines if unit is active and an initiated team member.
 * 
 *  @author: 03/11/1996 JLB
 */
bool Is_It_Playing(const FootClass *object)
{
	if (!Is_It_Breathing(object)) {
		return false;
	}

	if (!object->IsInitiated && object->Fetch_RTTI() != RTTI_AIRCRAFT) {
		return false;
	}

	return true;
}
