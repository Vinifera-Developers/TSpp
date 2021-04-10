/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          VETERANCY.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Unit veterancy level.
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
#include "tibsun_defines.h"


class NoInitClass;


class VeterancyClass
{
    public:
        VeterancyClass();
        VeterancyClass(const NoInitClass &noinit);
        ~VeterancyClass();

        void Gain_Experience(int cost, int value);

        bool Is_Veteran();
        bool Is_Rookie();
        bool Is_Dumbass();
        bool Is_Elite();

        double sub_664440(double a1);

        void Set_Rookie(bool dumbass);
        void sub_6644E0(bool a1);
        void Set_Veteran(bool force);
        void Set_Elite(bool force);

        // Used for Read/Write INI. 
        int To_Integer();
        void From_Integer(int value);

        VeterancyRankType Get_Rank()
        {
            if (Level >= 2.0) {
                return RANK_ELITE;
            }
            if (Level >= 1.0) {
                return RANK_VETERAN;
            }
            return RANK_ROOKIE;
        }

    private:
        double Level;
};
