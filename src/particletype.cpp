/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for particle types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "particletype.h"
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


ParticleType ParticleTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return PARTICLE_NONE;
    }

    if (name != nullptr) {
        for (ParticleType index = PARTICLE_FIRST; index < ParticleTypes.Count(); ++index) {
            if (!strcasecmp(ParticleTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return PARTICLE_NONE;
}


const char* ParticleTypeClass::Name_From(ParticleType type)
{
    return (type != PARTICLE_NONE && type < ParticleTypes.Count() ? ParticleTypes[type]->Name() : "<none>");
}


ParticleTypeClass* ParticleTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, ParticleTypes);
}
