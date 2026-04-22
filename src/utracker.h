/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Unit count tracker used for multiplayer game statistics.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once


class UnitTrackerClass
{
public:
    UnitTrackerClass(int unit_count);
    ~UnitTrackerClass();

    void Increment_Unit_Total(int unit_type);
    void Decrement_Unit_Total(int unit_type);
    void Clear_Unit_Total();

    int Get_Unit_Total(int unit_type)
    {
        if (UnitTotals == nullptr) {
            return 0;
        }
        if (unit_type >= 0 && unit_type < UnitCount) {
            return UnitTotals[unit_type];
        }
        return 0;
    }

    long* Get_All_Totals();

    void To_Network_Format();
    void To_PC_Format();

    int Get_Total_Of_All()
    {
        int total = 0;
        for (int i = 0; i < UnitCount; ++i) {
            total += UnitTotals[i];
        }
        return total;
    }

protected:
    long* UnitTotals;
    int UnitCount;
    int InNetworkFormat;
};
