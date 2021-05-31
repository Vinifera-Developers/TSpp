/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          PIPE.H
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


class Pipe
{
        Pipe(const Pipe &) = delete;
        Pipe & operator = (const Pipe &) = delete;

    public:
        Pipe();
        virtual ~Pipe();

        virtual int Flush();
        virtual int End();
        virtual void Put_To(Pipe *pipe);
        virtual int Put(const void *source, int slen);

        inline void Put_To(Pipe &pipe) { Put_To(&pipe); }

    public:
        Pipe *ChainTo;
        Pipe *ChainFrom;
};
