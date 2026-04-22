/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class for game campaign types.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "campaign.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


CampaignType CampaignClass::From_Name(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return CAMPAIGN_NONE;
    }

    if (name != nullptr) {
        for (CampaignType index = CAMPAIGN_FIRST; index < Campaigns.Count(); ++index) {
            if (!strcasecmp(Campaigns[index]->Name(), name)) {
                return index;
            }
        }
    }

    return CAMPAIGN_NONE;
}


const char* CampaignClass::Name_From(CampaignType type)
{
    return (type != CAMPAIGN_NONE && type < Campaigns.Count() ? Campaigns[type]->Name() : "<none>");
}


CampaignClass* CampaignClass::Find_Or_Make(const char* name)
{
    TSPP_ASSERT(name != nullptr);

    if (!strcasecmp(name, "<none>") || !strcasecmp(name, "none")) {
        return nullptr;
    }

    for (CampaignType index = CAMPAIGN_FIRST; index < Campaigns.Count(); ++index) {
        if (!strcasecmp(Campaigns[index]->Name(), name)) {
            return Campaigns[index];
        }
    }

    CampaignClass* ptr = new CampaignClass(name);
    TSPP_ASSERT(ptr != nullptr);
    return ptr;
}
