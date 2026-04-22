/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Dial gadget with 8 directions.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "gcntrl.h"


class Dial8Class : public ControlClass
{
public:
    Dial8Class(int id, int x, int y, int w, int h, Dir256 dir);
    virtual ~Dial8Class();

    virtual bool Draw_Me(bool forced = false) override;
    virtual bool Action(unsigned flags, KeyNumType& key) override;

    Dir256 Get_Direction() const;
    void Set_Direction(Dir256 dir);

public:
    int FaceX;
    int FaceY;
    int FacePoint[8][2];
    int FaceLine[8][2];
    Dir256 Direction;
    FacingType Facing;
    FacingType OldFacing;
};
