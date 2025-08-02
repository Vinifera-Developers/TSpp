/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CAMPAIGN.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for game campaign types.
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
#include "campaign.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


CampaignType CampaignClass::From_Name(const char *name)
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


const char *CampaignClass::Name_From(CampaignType type)
{
    return (type != CAMPAIGN_NONE && type < Campaigns.Count() ? Campaigns[type]->Name() : "<none>");
}


const CampaignClass *CampaignClass::Find_Or_Make(const char *name)
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

    CampaignClass *ptr = new CampaignClass(name);
    TSPP_ASSERT(ptr != nullptr);
    return ptr;
}
