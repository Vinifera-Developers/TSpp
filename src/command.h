/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          COMMAND.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Keyboard command types.
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

#include "always.h"
#include "wwkeyboard.h"


class TechnoClass;

enum TeamControlType;


typedef enum CommandType {
    COMMAND_FOLLOW,
    COMMAND_VIEW1,
    COMMAND_VIEW2,
    COMMAND_VIEW3,
    COMMAND_VIEW4,
    COMMAND_SETVIEW1,
    COMMAND_SETVIEW2,
    COMMAND_SETVIEW3,
    COMMAND_SETVIEW4,
    COMMAND_OPTIONS,
    COMMAND_SCROLLNORTH,
    COMMAND_SCROLLSOUTH,
    COMMAND_SCROLLEAST,
    COMMAND_SCROLLWEST,
    COMMAND_SIDEBARUP,
    COMMAND_LEFTSIDEBARUP,
    COMMAND_RIGHTSIDEBARUP,
    COMMAND_SIDEBARDOWN,
    COMMAND_LEFTSIDEBARDOWN,
    COMMAND_RIGHTSIDEBARDOWN,
    COMMAND_SIDEBARPAGEUP,
    COMMAND_LEFTSIDEBARPAGEUP,
    COMMAND_RIGHTSIDEBARPAGEUP,
    COMMAND_SIDEBARPAGEDOWN,
    COMMAND_LEFTSIDEBARPAGEDOWN,
    COMMAND_RIGHTSIDEBARPAGEDOWN,
    COMMAND_CENTER_RADAR_EVENT,
    COMMAND_TOGGLE_RADAR,
    COMMAND_TOGGLE_POWER,
    COMMAND_TOGGLE_SELL,
    COMMAND_TOGGLE_REPAIR,
    COMMAND_SELECT_VIEW,
    COMMAND_ALLIANCE,
    COMMAND_CENTER_BASE,
    COMMAND_CENTER_VIEW,
    COMMAND_SCATTER_OBJECT,
    COMMAND_GUARD_OBJECT,
    COMMAND_STOP_OBJECT,
    COMMAND_DEPLOY_OBJECT,
    COMMAND_PREV_OBJECT,
    COMMAND_NEXT_OBJECT,
    COMMAND_CREATE_TEAM_01,
    COMMAND_CREATE_TEAM_02,
    COMMAND_CREATE_TEAM_03,
    COMMAND_CREATE_TEAM_04,
    COMMAND_CREATE_TEAM_05,
    COMMAND_CREATE_TEAM_06,
    COMMAND_CREATE_TEAM_07,
    COMMAND_CREATE_TEAM_08,
    COMMAND_CREATE_TEAM_09,
    COMMAND_SELECT_TEAM_01,
    COMMAND_SELECT_TEAM_02,
    COMMAND_SELECT_TEAM_03,
    COMMAND_SELECT_TEAM_04,
    COMMAND_SELECT_TEAM_05,
    COMMAND_SELECT_TEAM_06,
    COMMAND_SELECT_TEAM_07,
    COMMAND_SELECT_TEAM_08,
    COMMAND_SELECT_TEAM_09,
    COMMAND_ADD_TEAM_01,
    COMMAND_ADD_TEAM_02,
    COMMAND_ADD_TEAM_03,
    COMMAND_ADD_TEAM_04,
    COMMAND_ADD_TEAM_05,
    COMMAND_ADD_TEAM_06,
    COMMAND_ADD_TEAM_07,
    COMMAND_ADD_TEAM_08,
    COMMAND_ADD_TEAM_09,
    COMMAND_CENTER_TEAM_01,
    COMMAND_CENTER_TEAM_02,
    COMMAND_CENTER_TEAM_03,
    COMMAND_CENTER_TEAM_04,
    COMMAND_CENTER_TEAM_05,
    COMMAND_CENTER_TEAM_06,
    COMMAND_CENTER_TEAM_07,
    COMMAND_CENTER_TEAM_08,
    COMMAND_CENTER_TEAM_09,
    COMMAND_WAYPOINT,
    COMMAND_SCREEN_CAPTURE,
    COMMAND_PAGE_USER,
    COMMAND_SELECT_SAME_TYPE,
    COMMAND_DELETE_WAYPOINT,

    COMMAND_COUNT,

    COMMAND_NONE = -1,
    COMMAND_FIRST = COMMAND_FOLLOW
} CommandType;


class CommandClass
{
public:
    CommandClass();
    virtual ~CommandClass();

    virtual const char* Get_Name() const = 0;
    virtual const char* Get_UI_Name() const = 0;
    virtual const char* Get_Category() const = 0;
    virtual const char* Get_Description() const = 0;
    virtual bool Process() = 0;

public:
    static bool Activate_From_Name(const char* name);
    static CommandClass* From_Name(const char* name);
    static CommandClass* From_KeyNum(KeyNumType key);
    static bool Activate_From_Type(CommandType type);
    static CommandClass* From_Type(CommandType type);
};

inline void Do_Command(const char* name)
{
    CommandClass::Activate_From_Name(name);
}
