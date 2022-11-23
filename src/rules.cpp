/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          RULES.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         General rules that control the game.
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
#include "rules.h"
#include "tibsun_globals.h"
#include "addon.h"
#include "ccfile.h"
#include "ccini.h"


/**
 *  Loads the contents of ARTFS.INI into the art ini database.
 * 
 *  @author: CCHyper
 */
void RulesClass::Load_ArtFS_INI()
{
    CCFileClass file("ARTFS.INI");
    if (file.Is_Available()) {
        ArtINI.Load(file, false);
    }
}
