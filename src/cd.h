/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  CD access interface.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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
