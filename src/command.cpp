/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Keyboard command types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "command.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


bool CommandClass::Activate_From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);
    TSPP_ASSERT(Commands.Count() > 0);

    if (name != nullptr) {
        for (int index = 0; index < Commands.Count(); ++index) {
            CommandClass* cmd = const_cast<CommandClass*>(Commands[index]);
            // TSPP_ASSERT(cmd != nullptr);
            if (!strcasecmp(name, cmd->Get_Name())) {
                return cmd->Process();
            }
        }
    }
    return false;
}


CommandClass* CommandClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);
    TSPP_ASSERT(Commands.Count() > 0);

    if (name != nullptr) {
        for (int index = 0; index < Commands.Count(); ++index) {
            CommandClass* cmd = const_cast<CommandClass*>(Commands[index]);
            // TSPP_ASSERT(cmd != nullptr);
            if (!strcasecmp(name, cmd->Get_Name())) {
                return cmd;
            }
        }
    }
    return nullptr;
}


CommandClass* CommandClass::From_KeyNum(KeyNumType key)
{
    TSPP_ASSERT(Commands.Count() > 0);

    if (key != KN_NONE) {
        CommandClass* cmd = const_cast<CommandClass*>(HotkeyIndex[key]);
        // TSPP_ASSERT(cmd != nullptr);
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


CommandClass* CommandClass::From_Type(CommandType type)
{
    return CommandClass::From_Name(Commands[type]->Get_Name());
}
