/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Hash table using a dictionary type.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "wstring.h"


class Dictionary
{
public:
    Dictionary();
    ~Dictionary();

    static unsigned CRC(Wstring& string);

public:
    void* Entries;  // 0x00
    int EntryCount; // 0x04
    int field_8;
    int field_0C;
    int field_10;
    bool field_14;
    void* CRC_Function; // 0x18
    int field_1C;
    double field_20;
    double field_28;
    double field_30;
};
