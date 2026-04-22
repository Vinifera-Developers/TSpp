/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Dropship unit loadout class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


class TechnoTypeClass;
class XSurface;
class ConvertClass;
class Blitter;


class DropshipLoadoutClass
{
public:
    DropshipLoadoutClass();
    ~DropshipLoadoutClass();

    bool Add(TechnoTypeClass* technotype);
    bool Remove(int index);
    void Remove_All();
    void Load();
    TechnoTypeClass* Fetch(int index);

public:
    int field_0;
    int field_4;
    int field_8;
    bool field_C;
    int EntryCount;
    TechnoTypeClass* field_14[5];
    int field_28;
};

int Dropship_Get_Allowable_Index(TechnoTypeClass* technotype);
void Dropship_Draw_Text(int a1, int a2, XSurface* surface, Point2D* xy, char* string, bool a6, ConvertClass* drawer, Blitter* blitter);
void Dropship_Draw_Info_Text(XSurface* surface, ConvertClass* drawer, TechnoTypeClass* technotype, bool a4);
void Dropship_Loadout();
