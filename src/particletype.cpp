/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          PARTICLETYPE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for particle types.
 *
 *  @license       TS++ is free software: you can redistribute it and/or
 *                 modify it under the terms of the GNU General Public License
 *                 as published by the Free Software Foundation, either version
 *                 3 of the License, or (at your option) any later version.
 *
 *                 TS++ is distributed in the hope that it will be
 *                 useful, but WITHOUT ANY WARRANTY; without even the implied
 *                 warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *                 PURPOSE. See the GNU General Public License for more details.
 *
 *                 You should have received a copy of the GNU General Public
 *                 License along with this program.
 *                 If not, see <http://www.gnu.org/licenses/>.
 *
 ******************************************************************************/
#include "particletype.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


const ParticleTypeClass &ParticleTypeClass::As_Reference(ParticleType type)
{
    TSPP_ASSERT(type != PARTICLE_NONE && type < ParticleTypes.Count());
    return *ParticleTypes[type];
}


const ParticleTypeClass *ParticleTypeClass::As_Pointer(ParticleType type)
{
    TSPP_ASSERT(type != PARTICLE_NONE && type < ParticleTypes.Count());
    return type != PARTICLE_NONE && type < ParticleTypes.Count() ? ParticleTypes[type] : nullptr;
}


const ParticleTypeClass &ParticleTypeClass::As_Reference(const char *name)
{
    return As_Reference(From_Name(name));
}


const ParticleTypeClass *ParticleTypeClass::As_Pointer(const char *name)
{
    return As_Pointer(From_Name(name));
}


ParticleType ParticleTypeClass::From_Name(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return PARTICLE_NONE;
    }

    if (name != nullptr) {
        for (ParticleType index = PARTICLE_FIRST; index < ParticleTypes.Count(); ++index) {
            if (!strcasecmp(As_Reference(index).Name(), name)) {
                return index;
            }
        }
    }

    return PARTICLE_NONE;
}


const char *ParticleTypeClass::Name_From(ParticleType type)
{
    return (type != PARTICLE_NONE && type < ParticleTypes.Count() ? As_Reference(type).Name() : "<none>");
}


const ParticleTypeClass *ParticleTypeClass::Find_Or_Make(const char *name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return nullptr;
    }

    for (ParticleType index = PARTICLE_FIRST; index < ParticleTypes.Count(); ++index) {
        if (!strcasecmp(ParticleTypes[index]->Name(), name)) {
            return ParticleTypes[index];
        }
    }

    ParticleTypeClass *ptr = new ParticleTypeClass(name);
    TSPP_ASSERT(ptr != nullptr);
    return ptr;
}
