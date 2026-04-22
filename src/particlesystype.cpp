/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for particle system types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "particlesystype.h"
#include "findmake.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


ParticleSystemType ParticleSystemTypeClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return PARTICLESYS_NONE;
    }

    if (name != nullptr) {
        for (ParticleSystemType index = PARTICLESYS_FIRST; index < ParticleSystemTypes.Count(); ++index) {
            if (!strcasecmp(ParticleSystemTypes[index]->Name(), name)) {
                return index;
            }
        }
    }

    return PARTICLESYS_NONE;
}


const char* ParticleSystemTypeClass::Name_From(ParticleSystemType type)
{
    return (type != PARTICLESYS_NONE && type < ParticleSystemTypes.Count() ? ParticleSystemTypes[type]->Name() : "<none>");
}


ParticleSystemTypeClass* ParticleSystemTypeClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    return TFind_Or_Make(name, ParticleSystemTypes);
}
