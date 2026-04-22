/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Dummy Parameter to a constructor that does absolutely no
 *          initialization to the object being constructed.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once


class NoInitClass
{
public:
    void operator()() const {}
};
