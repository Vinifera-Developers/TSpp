/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Tiberium storage container class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "tibsun_defines.h"


class NoInitClass;


class StorageClass
{
public:
    StorageClass();
    StorageClass(const NoInitClass& noinit);
    ~StorageClass();

    int Get_Total_Value() const;
    int Get_Total_Amount() const;
    int Get_Amount(TiberiumType tib) const;
    int Increase_Amount(int by, TiberiumType tib);
    int Decrease_Amount(int by, TiberiumType tib);
    int First_Used_Slot() const;

    StorageClass operator+(StorageClass& that) const;
    StorageClass operator+=(StorageClass& that);
    StorageClass operator-(StorageClass& that) const;
    StorageClass operator-=(StorageClass& that);

private:
    int Types[TIBERIUM_COUNT];
};
