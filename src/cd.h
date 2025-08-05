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


class DiskSwap
{
public:
    virtual bool ForceAvailable(DiskID disk);
    virtual bool RequestDisk(DiskID disk);
    virtual bool Swap(DiskID disk);

    static DiskID GetDiskID(int cd_drive, int timeout);

public:
    //static DiskID& DesiredDisk;
};


class CD : public DiskSwap
{
public:
    virtual bool ForceAvailable(DiskID disk) override;
    virtual bool RequestDisk(DiskID disk) override;
    virtual bool Swap(DiskID disk) override;

    static DiskID GetCurrentDisk();

    static bool ForceAvailable() { return CD().ForceAvailable(RequiredCD); }

    static void SetRequiredDisk(DiskID disk);
    static DiskID GetRequiredDisk() { return RequiredCD; }

    static void OverrideSwap(bool state) { _OverrideSwap = state; }
    static bool IsOverrideSwap() { return _OverrideSwap; }

public:
    ThemeType ThemePlaying;

    static DiskID& RequiredCD;
    static bool& _OverrideSwap;
};
