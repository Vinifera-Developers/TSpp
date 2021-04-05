/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          INI.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Tiberium storage container class.
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


class StorageClass
{
    public:
        StorageClass();
        StorageClass(const NoInitClass &noinit);
        ~StorageClass();

        int Get_Total_Value() const;
        int Get_Total_Amount() const;
        int Get_Amount(TiberiumType tib) const;
        int Increase_Amount(int by, TiberiumType tib);
        int Decrease_Amount(int by, TiberiumType tib);
        int First_Used_Slot() const;

        StorageClass operator+(StorageClass &that) const;
        StorageClass operator+=(StorageClass &that);
        StorageClass operator-(StorageClass &that) const;
        StorageClass operator-=(StorageClass &that);

    private:
        int Types[TIBERIUM_COUNT];
};
