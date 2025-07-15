/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          IONBLAST.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Ion cannon blast handler.
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

#include "tibsun_defines.h"


class IonBlastClass
{
    public:
        IonBlastClass(Coord coord);
        ~IonBlastClass();

        void AI();
        void Draw_It();

        static void Update_All();
        static void Draw_All();
        static void One_Time();
        static void Clear_All();

    public:
        Coord Position;
        int Lifetime;
};
