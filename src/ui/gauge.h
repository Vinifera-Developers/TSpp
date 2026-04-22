/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  *
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "gcntrl.h"


class GaugeClass : public ControlClass
{
public:
    GaugeClass(unsigned id, int x, int y, int w, int h);
    virtual ~GaugeClass();

    virtual bool Draw_Me(bool forced = false) override;
    virtual bool Action(unsigned flags, KeyNumType& key) override;

    virtual int Set_Maximum(int value);
    virtual int Set_Value(int value);
    virtual int Get_Value() const;
    virtual void Use_Thumb(int value);
    virtual int Thumb_Pixels();
    virtual void Draw_Thumb();
    virtual int Pixel_To_Value(int pixel);
    virtual int Value_To_Pixel(int value);

public:
    bool IsColorized;
    bool HasThumb;
    bool IsHorizontal;
    int MaxValue;
    int CurValue;
    int ClickDiff;
};


class TriColorGaugeClass : public GaugeClass
{
public:
    TriColorGaugeClass(unsigned id, int x, int y, int w, int h);
    virtual ~TriColorGaugeClass();

    virtual bool Draw_Me(bool forced = false) override;

    virtual int Set_Red_Limit(int value);
    virtual int Set_Yellow_Limit(int value);

public:
    int RedLimit;
    int YellowLimit;
};
