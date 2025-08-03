/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CD.H
 *
 *  @author        CCHyper
 *
 *  @brief         CD access interface.
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
#include "tibsun_defines.h"


class CD
{
public:
    CD();

    virtual bool Is_Available(DiskID disk);
    virtual bool Insert_Disk(DiskID disk);
    virtual bool Init_Swap(DiskID disk);

    bool Force_Available(DiskID disk);

    static DiskID Get_Volume_Index();
    static void Set_Required_CD(DiskID disk);

    static DiskID Get_CD_Index(int cd_drive, int timeout);

public:
    static bool& IsFilesLocal;
    static DiskID& RequiredCD;

public:
    ThemeType ThemePlaying;
};
