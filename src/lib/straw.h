/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          STRAW.H
 *
 *  @author        CCHyper
 *
 *  @brief         Basic demand driven data carrier.
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


class Straw
{
        Straw(const Straw &) = delete;
        Straw & operator = (const Straw &) = delete;

    public:
        Straw();
        virtual ~Straw();

        virtual void Get_From(Straw *pipe);
        virtual int Get(void *buffer, int slen);

        inline void Get_From(Straw &pipe) { Get_From(&pipe); }

    public:
        Straw *ChainTo;
        Straw *ChainFrom;
};
