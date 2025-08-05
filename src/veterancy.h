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
    VeterancyClass(const NoInitClass& noinit);
    ~VeterancyClass();

    void Made_A_Kill(int cost, int value);

    bool Is_Veteran() const;
    bool Is_Rookie() const;
    bool Is_Dumbass() const;
    bool Is_Elite() const;

    __declspec(property(get = Is_Dumbass, put = Set_Dumbass)) bool IsDumbass;
    __declspec(property(get = Is_Rookie, put = Set_Rookie)) bool IsRookie;
    __declspec(property(get = Is_Veteran, put = Set_Veteran)) bool IsVeteran;
    __declspec(property(get = Is_Elite, put = Set_Elite)) bool IsElite;

    double Modify(double value);

    void Set_Dumbass(bool dumbass);
    void Set_Rookie(bool a1);
    void Set_Veteran(bool force);
    void Set_Elite(bool force);

    // Used for Read/Write INI.
    int To_Integer();
    void From_Integer(int value);

    VeterancyRankType Get_Rank() const
    {
        if (Is_Elite()) {
            return RANK_ELITE;
        }
        if (Is_Veteran()) {
            return RANK_VETERAN;
        }
        return RANK_ROOKIE;
    }

private:
    double Experience;
};
