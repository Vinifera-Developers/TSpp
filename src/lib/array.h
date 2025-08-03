/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          ARRAY.H
 *
 *  @authors       OmniBlade
 *
 *  @brief         Simple array container.
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


template<typename T, int N>
class Array
{
public:
    inline Array() {}

    inline Array(T val)
    {
        for (int i = 0; i < N; ++i) Data[i] = val;
    }

    inline const int Size() const { return N; }

    inline T& operator[](int idx) { return Data[idx]; }

    inline T operator[](int idx) const { return Data[idx]; }

private:
    T Data[N];
};
