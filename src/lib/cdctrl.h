/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CDCTRL.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         CD Drive io control.
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


class CDControlClass
{
    public:
        CDControlClass();
        ~CDControlClass();

        bool Eject_CD_Drive(UINT drive_num);
        bool Load_CD_Drive(UINT drive_num);
        bool Lock_CD_Drive(UINT drive_num);
        bool Unlock_CD_Drive(UINT drive_num);

        bool Unlock_All_CD_Drives()
        {
            for (UINT drive_num = 0; drive_num <= std::size(LockCount); ++drive_num) {

                if (LockCount[drive_num] <= 0) {
                    continue;
                }

                if (LockCount[drive_num] == 0) {
                    continue;
                }

                Unlock_CD_Drive(drive_num);
            }

            return true;
        }

    private:
        int LockCount[26]; // Windows drives use the alphabet range (max 26 characters).
};
