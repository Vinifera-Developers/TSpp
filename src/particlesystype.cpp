/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          PARTICLESYSTYPE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for particle system types.
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
