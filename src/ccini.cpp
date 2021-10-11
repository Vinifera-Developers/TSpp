/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CCINI.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Advanced version of the INI database manager which handles
 *                 the C&C engine types and identifiers.
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
#include "ccini.h"
#include "tibsun_globals.h"
#include "tibsun_functions.h"
#include "voc.h"
#include "unittype.h"
#include "animtype.h"
#include "buildingtype.h"
#include "particletype.h"
#include "tiberium.h"
#include "weapontype.h"


/**
 *  Store a vector3 to the INI database.
 * 
 *  @author: CCHyper
 */
const Vector3 CCINIClass::Get_Vector3(char const *section, char const *entry, const Vector3 defvalue) const
{
    char buffer[1024];
    char defbuff[1024];

    std::snprintf(defbuff, sizeof(defbuff), "%f,%f,%f", defvalue.X, defvalue.Y, defvalue.Z);

    if (Get_String(section, entry, defbuff, buffer, sizeof(buffer)) <= 0) {
        return defvalue;
    }

    float x = defvalue.X;
    float y = defvalue.Y;
    float z = defvalue.Z;

    /**
     *  Read formatted data from the buffer.
     */
    if (sscanf(buffer, "%f,%f,%f", &x, &y, &z) == 3) {
        return Vector3(x, y, z);
    }

    return defvalue;
}


/**
 *  Fetch a vector3 from the INI database.
 * 
 *  @author: CCHyper
 */
bool CCINIClass::Put_Vector3(char const *section, char const *entry, const Vector3 value)
{
    char buffer[1024];

    std::snprintf(buffer, sizeof(buffer), "%lf,%lf,%lf", value.X, value.Y, value.Z);

    return Put_String(section, entry, buffer);
}


/**
 *  Fetch a voc (sound effect) from the INI database.
 * 
 *  @author: CCHyper
 */
VocType CCINIClass::Get_VocType(const char *section, const char *entry, const VocType defvalue)
{
    char buffer[1024];

    if (INIClass::Get_String(section, entry, VocClass::INI_Name_From(defvalue), buffer, sizeof(buffer)) > 0) {
        return VocClass::From_Name(buffer);
    }

    return defvalue;
}


/**
 *  Fetch the unit type identifier from the INI database.
 * 
 *  @author: CCHyper
 */
const UnitTypeClass *CCINIClass::Get_Unit(const char *section, const char *entry, const UnitTypeClass *defvalue)
{
    char buffer[1024];

    if (INIClass::Get_String(section, entry, "", buffer, sizeof(buffer)) > 0) {
        return UnitTypeClass::Find_Or_Make(buffer);
    }

    return defvalue;
}


/**
 *  Store the unit type identifier to the INI database.
 * 
 *  @author: CCHyper
 */
bool CCINIClass::Put_Unit(const char *section, const char *entry, const UnitTypeClass *value)
{
    if (value) {
        return INIClass::Put_String(section, entry, value->Name());
    } else {
        return INIClass::Put_String(section, entry, "<none>");
    }
}


/**
 *  Fetch the anim type identifier from the INI database.
 * 
 *  @author: CCHyper
 */
const AnimTypeClass *CCINIClass::Get_Anim(const char *section, const char *entry, const AnimTypeClass *defvalue)
{
    char buffer[1024];

    if (INIClass::Get_String(section, entry, "", buffer, sizeof(buffer)) > 0) {
        return AnimTypeClass::Find_Or_Make(buffer);
    }

    return defvalue;
}


/**
 *  Store the anim type identifier to the INI database.
 * 
 *  @author: CCHyper
 */
bool CCINIClass::Put_Anim(const char *section, const char *entry, const AnimTypeClass *value)
{
    if (value) {
        return INIClass::Put_String(section, entry, value->Name());
    } else {
        return INIClass::Put_String(section, entry, "<none>");
    }
}


/**
 *  Fetch a unit list from the INI database.
 * 
 *  @author: CCHyper
 */
TypeList<UnitTypeClass *> CCINIClass::Get_Units(const char *section, const char *entry, const TypeList<UnitTypeClass *> defvalue)
{
    char buffer[1024];

    if (INIClass::Get_String(section, entry, "", buffer, sizeof(buffer)) > 0) {

        TypeList<UnitTypeClass *> list;

        char *name = std::strtok(buffer, ",");
        while (name) {

            for (UnitType index = UNIT_FIRST; index < UnitTypes.Count(); ++index) {
                if (strcasecmp(name, UnitTypes[index]->Name()) == 0) {
                    list.Add(UnitTypes[index]);
                }
            }

            name = std::strtok(nullptr, ",");
        }

        return list;
    }

    return defvalue;
}


/**
 *  Store a unit list to the INI database.
 * 
 *  @author: CCHyper
 */
bool CCINIClass::Put_Units(const char *section, const char *entry, const TypeList<UnitTypeClass *> value)
{
    char buffer[1024] = { '\0' };

    for (int index = 0; index < value.Count(); ++index) {
        if (buffer[0] != '\0') {
            std::strcat(buffer, ",");
        }
        std::strcat(buffer, value[index]->Name());
    }

    return INIClass::Put_String(section, entry, buffer);
}


/**
 *  Fetch a unit list from the INI database.
 * 
 *  @author: CCHyper
 */
TypeList<BuildingTypeClass *> CCINIClass::Get_Buildings(const char *section, const char *entry, const TypeList<BuildingTypeClass *> defvalue)
{
    char buffer[1024];

    if (INIClass::Get_String(section, entry, "", buffer, sizeof(buffer)) > 0) {

        TypeList<BuildingTypeClass *> list;

        char *name = std::strtok(buffer, ",");
        while (name) {

            for (BuildingType index = BUILDING_FIRST; index < BuildingTypes.Count(); ++index) {
                if (strcasecmp(name, BuildingTypes[index]->Name()) == 0) {
                    list.Add(BuildingTypes[index]);
                }
            }

            name = std::strtok(nullptr, ",");
        }

        return list;
    }

    return defvalue;
}


/**
 *  Store a unit list to the INI database.
 * 
 *  @author: CCHyper
 */
bool CCINIClass::Put_Buildings(const char *section, const char *entry, const TypeList<BuildingTypeClass *> value)
{
    char buffer[1024] = { '\0' };

    for (int index = 0; index < value.Count(); ++index) {
        if (buffer[0] != '\0') {
            std::strcat(buffer, ",");
        }
        std::strcat(buffer, value[index]->Name());
    }

    return INIClass::Put_String(section, entry, buffer);
}


/**
 *  Fetch a land identifier from the INI database.
 * 
 *  @author: CCHyper
 */
LayerType CCINIClass::Get_LayerType(const char *section, const char *entry, const LayerType defvalue)
{
    char buffer[1024];

    if (INIClass::Get_String(section, entry, Name_From_Layer(defvalue), buffer, sizeof(buffer)) > 0) {
        return Layer_From_Name(buffer);
    }

    return defvalue;
}


/**
 *  Store a land identifier to the INI database.
 * 
 *  @author: CCHyper
 */
bool CCINIClass::Put_LayerType(const char *section, const char *entry, LayerType value)
{
    return Put_String(section, entry, Name_From_Layer(value));
}


/**
 *  Fetch a particle identifier from the INI database.
 * 
 *  @author: CCHyper
 */
ParticleType CCINIClass::Get_ParticleType(const char *section, const char *entry, const ParticleType defvalue)
{
    char buffer[1024];

    if (INIClass::Get_String(section, entry, ParticleTypeClass::Name_From(defvalue), buffer, sizeof(buffer)) > 0) {
        return ParticleTypeClass::From_Name(buffer);
    }

    return defvalue;
}


/**
 *  Store a particle identifier to the INI database.
 * 
 *  @author: CCHyper
 */
bool CCINIClass::Put_ParticleType(const char *section, const char *entry, ParticleType value)
{
    return Put_String(section, entry, ParticleTypeClass::Name_From(value));
}


/**
 *  Fetch a unit list from the INI database.
 * 
 *  @author: CCHyper
 */
TypeList<VocType> CCINIClass::Get_VocType_List(const char *section, const char *entry, const TypeList<VocType> defvalue)
{
    char buffer[1024];

    if (INIClass::Get_String(section, entry, "", buffer, sizeof(buffer)) > 0) {

        TypeList<VocType> list;

        char *name = std::strtok(buffer, ",");
        while (name) {

            VocClass *voc = VocClass::Voc_From_Name(name);
            if (voc) {
                list.Add(VocClass::VocType_From_Voc(voc));
            }

            name = std::strtok(nullptr, ",");
        }

        return list;
    }

    return defvalue;
}


/**
 *  Store a unit list to the INI database.
 * 
 *  @author: CCHyper
 */
bool CCINIClass::Put_VocType_List(const char *section, const char *entry, const TypeList<VocType> value)
{
    char buffer[1024] = { '\0' };

    for (int index = 0; index < value.Count(); ++index) {
        if (buffer[0] != '\0') {
            std::strcat(buffer, ",");
        }
        std::strcat(buffer, VocClass::INI_Name_From(value[index]));
    }

    return INIClass::Put_String(section, entry, buffer);
}


/**
 *  Fetch the techno type identifier from the INI database.
 * 
 *  @author: CCHyper
 */
const TechnoTypeClass *CCINIClass::Get_Techno(const char *section, const char *entry, const TechnoTypeClass *defvalue)
{
    char buffer[1024];

    if (INIClass::Get_String(section, entry, "", buffer, sizeof(buffer)) > 0) {

        if (!strcasecmp(buffer, "<none>") || !strcasecmp(buffer, "none")) {
            return nullptr;
        }

        for (int index = 0; index < TechnoTypes.Count(); ++index) {
            if (!strcasecmp(TechnoTypes[index]->Name(), buffer)) {
                return TechnoTypes[index];
            }
        }

    }

    return defvalue;
}


/**
 *  Store the techno type identifier to the INI database.
 * 
 *  @author: CCHyper
 */
bool CCINIClass::Put_Techno(const char *section, const char *entry, const TechnoTypeClass *value)
{
    if (value) {
        return INIClass::Put_String(section, entry, value->Name());
    } else {
        return INIClass::Put_String(section, entry, "<none>");
    }
}


/**
 *  Store a tiberium identifier to the INI database.
 * 
 *  @author: CCHyper
 */
bool CCINIClass::Put_TiberiumType(const char *section, const char *entry, TiberiumType value)
{
    return Put_String(section, entry, TiberiumClass::Name_From(value));
}


/**
 *  Fetch a tiberium identifier from the INI database.
 * 
 *  @author: CCHyper
 */
TiberiumType CCINIClass::Get_TiberiumType(const char *section, const char *entry, const TiberiumType defvalue)
{
    char buffer[1024];

    if (INIClass::Get_String(section, entry, TiberiumClass::Name_From(defvalue), buffer, sizeof(buffer)) > 0) {
        return TiberiumClass::From_Name(buffer);
    }

    return defvalue;
}


/**
 *  Fetch the weapon type identifier from the INI database.
 * 
 *  @author: CCHyper
 */
const WeaponTypeClass *CCINIClass::Get_Weapon(const char *section, const char *entry, const WeaponTypeClass *defvalue)
{
    char buffer[1024];

    if (INIClass::Get_String(section, entry, "", buffer, sizeof(buffer)) > 0) {
        return WeaponTypeClass::Find_Or_Make(buffer);
    }

    return defvalue;
}


/**
 *  Store the weapon type identifier to the INI database.
 * 
 *  @author: CCHyper
 */
bool CCINIClass::Put_Weapon(const char *section, const char *entry, const WeaponTypeClass *value)
{
    if (value) {
        return INIClass::Put_String(section, entry, value->Name());
    } else {
        return INIClass::Put_String(section, entry, "<none>");
    }
}
