/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class that handles the basic cargo logic.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "cargo.h"
#include "foot.h"


/**
 *  Counts how many objects of this type are in this cargo.
 *
 *  @author: ZivDero
 */
int CargoClass::How_Many(RTTIType rtti) const
{
    ObjectClass* object = CargoHold;
    int count = 0;

    while (object != nullptr) {
        if (object->RTTI == rtti) {
            count++;
        }
        object = object->Next;
    }

    return count;
}


/**
 *  Returns if there are any objects of this type are in this cargo.
 *
 *  @author: ZivDero
 */
bool CargoClass::Is_Something_Attached(RTTIType rtti) const
{
    return How_Many(rtti) > 0;
}


/**
 *  Fetches an attached object of this type.
 *
 *  @author: ZivDero
 */
FootClass* CargoClass::Attached_Object(RTTIType rtti) const
{
    FootClass* object = CargoHold;

    while (object != nullptr) {
        if (object->RTTI == rtti) {
            return object;
        }
        object = static_cast<FootClass*>(object->Next);
    }

    return nullptr;
}


/**
 *  Detaches an attached object of this type.
 *
 *  @author: ZivDero
 */
FootClass* CargoClass::Detach_Object(RTTIType rtti)
{
    FootClass* unit = Attached_Object(rtti);

    if (unit != nullptr) {
        Detach(unit);
        Quantity--;
    }

    return unit;
}
