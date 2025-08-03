/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          UTRACKER.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Unit count tracker used for multiplayer game statistics.
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


class UnitTrackerClass
{
public:
    UnitTrackerClass(int unit_count);
    ~UnitTrackerClass();

    void Increment_Unit_Total(int unit_type);
    void Decrement_Unit_Total(int unit_type);
    void Clear_Unit_Total();

    int Get_Unit_Total(int unit_type)
    {
        if (UnitTotals == nullptr) {
            return 0;
        }
        if (unit_type >= 0 && unit_type < UnitCount) {
            return UnitTotals[unit_type];
        }
        return 0;
    }

    long* Get_All_Totals();

    void To_Network_Format();
    void To_PC_Format();

    int Get_Total_Of_All()
    {
        int total = 0;
        for (int i = 0; i < UnitCount; ++i) {
            total += UnitTotals[i];
        }
        return total;
    }

protected:
    long* UnitTotals;
    int UnitCount;
    int InNetworkFormat;
};
