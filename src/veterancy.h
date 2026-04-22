/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Unit veterancy level.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "tibsun_defines.h"


class NoInitClass;


class VeterancyClass
{
public:
    VeterancyClass();
    VeterancyClass(const NoInitClass& noinit);
    ~VeterancyClass();

    void Made_A_Kill(int cost, int value);

    bool Is_Veteran() const;
    bool Is_Rookie() const;
    bool Is_Dumbass() const;
    bool Is_Elite() const;

    __declspec(property(get = Is_Dumbass)) bool IsDumbass;
    __declspec(property(get = Is_Rookie)) bool IsRookie;
    __declspec(property(get = Is_Veteran)) bool IsVeteran;
    __declspec(property(get = Is_Elite)) bool IsElite;

    double Modify(double value);

    void Set_Dumbass(bool force = true);
    void Set_Rookie(bool force = true);
    void Set_Veteran(bool force = true);
    void Set_Elite(bool force = true);

    // Used for Read/Write INI.
    int To_Integer();
    void From_Integer(int value);

    VeterancyRankType Get_Rank() const
    {
        if (IsElite) {
            return RANK_ELITE;
        }
        if (IsVeteran) {
            return RANK_VETERAN;
        }
        return RANK_ROOKIE;
    }

private:
    double Experience;
};
