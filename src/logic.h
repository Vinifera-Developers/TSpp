/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Game logic processing.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "layer.h"


class ObjectClass;
class AbstractClass;


class LogicClass : public LayerClass
{
public:
    LogicClass();
    virtual ~LogicClass();

    /**
     *  LogicClass
     */
    virtual bool Submit(ObjectClass const* object, bool sort = false);
    virtual void Init();
    virtual void One_Time();

    virtual void Detach(AbstractClass* target, bool all = true);

    void AI();
    void func_507210(); // looks like an older version of AI()?
    void Remove(ObjectClass* const object);

    static void func_507470();

public:
    static unsigned& FramesPerSecond;
};
