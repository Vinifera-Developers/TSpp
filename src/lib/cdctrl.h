/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  CD Drive io control.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once


#include "always.h"


class CDControlClass
{
public:
    CDControlClass();
    ~CDControlClass();

    bool Force_CD_Eject(UINT drive_num);
    bool Lock_CD_Tray(UINT drive_num);
    bool Unlock_CD_Tray(UINT drive_num);

    bool Unlock_All_CD_Trays()
    {
        for (int drive_num = 0; drive_num <= std::size(LockCount); ++drive_num) {
            if (LockCount[drive_num] <= 0) {
                continue;
            }
            Unlock_CD_Tray(drive_num);
        }
        return true;
    }

private:
    int LockCount[26]; // Windows drives use the alphabet range (max 26 characters).
};
