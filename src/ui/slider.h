/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Like a Windows Slider structure.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "gauge.h"


class ShapeButtonClass;


class SliderClass : public GaugeClass
{
public:
    SliderClass(unsigned id, int x, int y, int w, int h, bool belong_to_list = false);
    virtual ~SliderClass();

    virtual void Peer_To_Peer(unsigned flags, KeyNumType& key, ControlClass& whom) override;
    virtual bool Draw_Me(bool forced = false) override;
    virtual bool Action(unsigned flags, KeyNumType& key) override;

    virtual int Set_Maximum(int value);
    virtual int Set_Value(int value);
    virtual int Thumb_Pixels();
    virtual void Draw_Thumb();
    virtual void Set_Thumb_Size(int value);
    virtual int Bump(bool up);
    virtual int Step(bool up);

    void Recalc_Thumb();

protected:
    ShapeButtonClass* PlusGadget;
    ShapeButtonClass* MinusGadget;
    bool BelongToList;
    int Thumb;
    int ThumbSize;
    int ThumbStart;
};
