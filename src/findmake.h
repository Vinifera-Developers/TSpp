/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          FINDMAKE.H
 *
 *  @authors       ZivDero, tomsons26
 *
 *  @brief         Templated utility functions for finding/saving/loading
 *                 game classes.
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
#pragma once

#include "ccini.h"
#include "typelist.h"


/**
 *  Find an object with this name in the DVC.
 *
 *  @author: tomsons26, ZivDero
 */
template<class T>
T* TFind_Or_Make(const char* name, const DynamicVectorClass<T*>& vector)
{
    if (stricmp("<none>", name) && stricmp("none", name)) {
        for (int index = 0; index < vector.Count(); index++) {
            if (stricmp(vector[index]->IniName, name) == 0) {
                return vector[index];
            }
        }
        return new T(name);
    }
    return nullptr;
}


/**
 *  Fetch a type list from the INI database.
 *
 *  @author: CCHyper
 */
template<class T>
TypeList<T*> TGet_TypeList(CCINIClass const& ini, char const* section, char const* entry, TypeList<T*> const& defvalue)
{
    char buffer[1024];
    if (ini.Get_String(section, entry, "", buffer, sizeof(buffer)) != 0) {
        TypeList<T*> list;
        const char* token = strtok(buffer, ",");
        while (token != nullptr && token[0] != '\0') {
            T* ptr = const_cast<T*>(T::Find_Or_Make(token));
            if (ptr) {
                list.Add(ptr);
            }
            token = strtok(nullptr, ",");
        }
        return list;
    }
    return defvalue;
}


/**
 *  Reads a type from the INI database.
 *
 *  @author: ZivDero
 */
template<class T>
T* TGet_Class(CCINIClass const& ini, char const* section, char const* entry, T* defvalue)
{
    char buffer[1024];
    if (ini.Get_String(section, entry, "", buffer, sizeof(buffer)) != 0) {
        return T::Find_Or_Make(buffer);
    }
    return defvalue;
}


/**
 *  Writes a type to the INI database.
 *
 *  @author: ZivDero
 */
template<class T>
bool TPut_Class(CCINIClass& ini, char const* section, char const* entry, T const* value)
{
    return ini.Put_String(section, entry, value->Name());
}
