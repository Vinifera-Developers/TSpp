/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Westwood CRC engine.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "wwcrc.h"


long CRCEngine::Value() const
{
    if (Buffer_Needs_Data()) {

        /**
         *  Pad the buffer.
         */
        ((char&)StagingBuffer.Buffer[Index]) = Index;
        for (int i = Index + 1; i < sizeof(long); ++i) {
            ((char&)StagingBuffer.Buffer[i]) = StagingBuffer.Buffer[0];
        }

        return CRC_Memory(&StagingBuffer, sizeof(long), CRC);
    }

    return CRC;
};
