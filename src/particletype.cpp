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
