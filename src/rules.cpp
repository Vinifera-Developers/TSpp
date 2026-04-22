/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  General rules that control the game.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "rules.h"
#include "addon.h"
#include "ccfile.h"
#include "ccini.h"
#include "tibsun_globals.h"


/**
 *  Loads the contents of ARTFS.INI into the art ini database.
 *
 *  @author: CCHyper
 */
void RulesClass::Load_ArtFS_INI()
{
    if (!Addon_Installed(ADDON_FIRESTORM)) {
        return;
    }

    CCFileClass file("ARTFS.INI");
    if (file.Is_Available()) {
        ArtINI.Load(file, false);
    }
}


/**
 *  Loads the contents of FIRESTRM.INI into its ini database.
 *
 *  @author: CCHyper
 */
void RulesClass::Load_FSRule_INI()
{
    if (!Addon_Installed(ADDON_FIRESTORM)) {
        return;
    }

    CCFileClass file("FIRESTRM.INI");
    if (file.Is_Available()) {
        FSRuleINI.Load(file, false);
    }
}
