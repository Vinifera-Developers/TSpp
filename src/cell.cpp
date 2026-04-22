/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Representation of a cell on the game world map.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "cell.h"
#include "mouse.h"
#include "overlay.h"
#include "tiberium.h"
#include "tibsun_defines.h"
#include "tibsun_inline.h"


/**
 *  Spread Tiberium (of a specific type) from this cell to an adjacent (random) cell.
 *
 *  @author: 08/14/1996 JLB - Red Alert source code.
 *           CCHyper - Adjustments for Tiberian Sun.
 */
bool CellClass::Spread_Tiberium(TiberiumType tiberium, bool forced)
{
    if (!forced) {
        if (!Can_Tiberium_Spread()) {
            return false;
        }
    }

    if (forced) {
        if (tiberium == TIBERIUM_NONE) {
            tiberium = TIBERIUM_FIRST;
        }
    } else if (tiberium == TIBERIUM_NONE) {
        return false;
    }

    TiberiumClass* tib = Tiberiums[tiberium];
    FacingType offset = Random_Pick(FACING_N, FACING_NW);
    for (FacingType index = FACING_N; index < FACING_COUNT; ++index) {
        CellClass* newcell = &Adjacent_Cell(index + offset);

        if (newcell != nullptr && newcell->Can_Tiberium_Germinate(tib)) {
            return newcell->Place_Tiberium(tiberium, 3);
        }
    }

    return false;
}


/**
 *  Fetches the cell that owns the bridge that spans this cell.
 *
 *  @author: ZivDero
 */
CellClass* CellClass::Get_Bridge_Owner() const
{
    if (IsUnderBridge) {
        return &Map[IsBridgeOwner ? CellID : BridgeOwner->CellID];
    }
    return nullptr;
}
