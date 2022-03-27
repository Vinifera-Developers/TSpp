/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CDFILE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         File interface with cd drive search path support.
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
#include "cdfile.h"


/**
 *  Fetch the path for the requested search drive entry index.
 * 
 *  @author: CCHyper
 */
const char *CDFileClass::Get_Search_Path(int index)
{
    if (First == nullptr) {
        return nullptr;
    }

    SearchDriveType *sd = First;

    /**
     *  We want to loop once, even if index == 0.
     */
    for (int i = 0; i <= index; i++) {

        if (i == index) {
            return sd->Path;
        }

        sd = (SearchDriveType *)sd->Next;
        if (sd == nullptr) {
            return nullptr;
        }
    }

    return nullptr;
}
