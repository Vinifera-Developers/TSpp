/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WWCRC.CPP
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Westwood CRC engine.
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
#include "wwcrc.h"


long CRCEngine::Value() const
{
    if (Buffer_Needs_Data()) {

        /**
         *  Pad the buffer.
         */
        ((char &)StagingBuffer.Buffer[Index]) = Index;
        for (int i = Index + 1; i < sizeof(long); ++i) {
            ((char &)StagingBuffer.Buffer[i]) = StagingBuffer.Buffer[0];
        }

        return CRC_Memory(&StagingBuffer, sizeof(long), CRC);
    }

    return CRC;
};
