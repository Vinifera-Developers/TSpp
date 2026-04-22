/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Layer object tracker.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "tibsun_defines.h"
#include "vector.h"
#include <unknwn.h>


class Straw;
class Pipe;
class ObjectClass;


class LayerClass : public DynamicVectorClass<ObjectClass*>
{
    using VectorClass<ObjectClass*>::Vector;
    using VectorClass<ObjectClass*>::VectorMax;
    using VectorClass<ObjectClass*>::IsAllocated;

public:
    LayerClass();
    virtual ~LayerClass();

    void Sort();
    virtual bool Submit(ObjectClass const* object, bool sort = false);
    bool Sorted_Add(ObjectClass const* object);

    HRESULT Save(IStream* pStm);
    HRESULT Load(IStream* pStm);
};
