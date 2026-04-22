/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Map threat region tracker.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


class RegionClass
{
public:
    RegionClass() { Threat = 0; }
    ~RegionClass() {}

    int operator!=(RegionClass const& region) { return std::memcmp(this, &region, sizeof(RegionClass)); }
    int operator==(RegionClass const& region) { return !std::memcmp(this, &region, sizeof(RegionClass)); }
    int operator>(RegionClass const& region) { return std::memcmp(this, &region, sizeof(RegionClass)) > 0; }
    int operator<(RegionClass const& region) { return std::memcmp(this, &region, sizeof(RegionClass)) < 0; }

    void Reset_Threat() { Threat = 0; }
    void Adjust_Threat(int threat, int neg)
    {
        if (neg)
            Threat -= threat;
        else
            Threat += threat;
    }
    int Threat_Value() const { return Threat; }

protected:
    long Threat;
};
