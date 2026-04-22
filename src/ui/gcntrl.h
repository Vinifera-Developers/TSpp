/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  The gui region tracking class.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "gadget.h"


class ControlClass : public GadgetClass
{
public:
    ControlClass(unsigned id, int x, int y, int w, int h, unsigned flags = LEFTPRESS | RIGHTPRESS, bool sticky = false);
    ControlClass(const ControlClass& control);
    ControlClass(const NoInitClass& x);

    virtual void Make_Peer(GadgetClass& gadget);
    virtual bool Draw_Me(bool forced = false) override;
    virtual unsigned Get_ID() const override;
    virtual bool Action(unsigned flags, KeyNumType& key) override;

public:
    unsigned ID;
    GadgetClass* Peer;
};
