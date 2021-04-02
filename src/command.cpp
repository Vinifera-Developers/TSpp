/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          COMMAND.CPP
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
#include "command.h"
#include "tibsun_globals.h"
#include <cassert>


bool CommandClass::Activate_From_Name(const char *name)
{
    assert(name != nullptr);
    assert(Commands.Count() > 0);

    if (name != nullptr) {
        for (int index = 0; index < Commands.Count(); ++index) {
            CommandClass *cmd = const_cast<CommandClass *>(Commands[index]);
            //assert(cmd != nullptr);
            if (!strcasecmp(name, cmd->Get_Name())) {
                return cmd->Process();
            }
        }
    }
    return false;
}


CommandClass *CommandClass::From_Name(const char *name)
{
    assert(name != nullptr);
    assert(Commands.Count() > 0);

    if (name != nullptr) {
        for (int index = 0; index < Commands.Count(); ++index) {
            CommandClass *cmd = const_cast<CommandClass *>(Commands[index]);
            //assert(cmd != nullptr);
            if (!strcasecmp(name, cmd->Get_Name())) {
                return cmd;
            }
        }
    }
    return nullptr;
}


CommandClass *CommandClass::From_KeyNum(KeyNumType key)
{
    assert(Commands.Count() > 0);

    if (key != KN_NONE) {
        CommandClass *cmd = const_cast<CommandClass *>(HotkeyIndex[key]);
        //assert(cmd != nullptr);
        if (cmd != nullptr) {
            return cmd;
        }
    }
    return nullptr;
}


bool CommandClass::Activate_From_Type(CommandType type)
{
    return CommandClass::Activate_From_Name(Commands[type]->Get_Name());
}


CommandClass *CommandClass::From_Type(CommandType type)
{
    return CommandClass::From_Name(Commands[type]->Get_Name());
}
