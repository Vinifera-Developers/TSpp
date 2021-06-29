/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CELL.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Representation of a cell on the game world map.
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
#include "ccfile.h"


class NewMenuClass
{
    public:
        NewMenuClass();
        //~NewMenuClass();

        static void Blit();
        static NewMenuClass *Get();

        bool Is_Loaded() const { return Mix != nullptr; }
        const char *Background_Image() const { return BackgroundImage; }

    public:
        MFCC *Mix;
        int GameMode;
        const char * BackgroundImage;
};
