/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Advanced version of the INI database manager which handles the C&C
 *          engine types and identifiers.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "ccini.h"
#include "aircrafttype.h"
#include "animtype.h"
#include "buildingtype.h"
#include "infantrytype.h"
#include "mission.h"
#include "overlaytype.h"
#include "particlesystype.h"
#include "particletype.h"
#include "tiberium.h"
#include "tibsun_functions.h"
#include "tibsun_globals.h"
#include "unittype.h"
#include "voc.h"
#include "warheadtype.h"
#include "weapontype.h"


/**
 *  Fetch a land identifier from the INI database.
 *
 *  @author: CCHyper
 */
LayerType CCINIClass::Get_LayerType(const char* section, const char* entry, LayerType defvalue) const
{
    char buffer[1024];

    if (Get_String(section, entry, Name_From_Layer(defvalue), buffer, sizeof(buffer)) > 0) {
        return Layer_From_Name(buffer);
    }

    return defvalue;
}


/**
 *  Store a land identifier to the INI database.
 *
 *  @author: CCHyper
 */
bool CCINIClass::Put_LayerType(const char* section, const char* entry, LayerType value)
{
    return Put_String(section, entry, Name_From_Layer(value));
}


/**
 *  Fetch the string list from the INI database.
 *
 *  @author: CCHyper
 */
DynamicVectorClass<std::string> CCINIClass::Get_Strings(const char* section, const char* entry, const DynamicVectorClass<std::string>& defvalue) const
{
    char buffer[1024];

    if (Get_String(section, entry, "", buffer, sizeof(buffer)) > 0) {

        DynamicVectorClass<std::string> list;

        char* name = std::strtok(buffer, ",");
        while (name) {
            list.Add(std::string(name));

            name = std::strtok(nullptr, ",");
        }

        return list;
    }

    return defvalue;
}


/**
 *  Store the stirng list to the INI database.
 *
 *  @author: CCHyper
 */
bool CCINIClass::Put_Strings(const char* section, const char* entry, const DynamicVectorClass<std::string>& value)
{
    char buffer[1024] = {'\0'};

    for (int index = 0; index < value.Count(); ++index) {
        if (buffer[0] != '\0') {
            std::strcat(buffer, ",");
        }
        std::strcat(buffer, value[index].c_str());
    }

    return Put_String(section, entry, buffer);
}