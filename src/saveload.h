/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SAVELOAD.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Save game and load game functions.
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
#include "vector.h"
#include <ole2.h>


bool Save_Game(const char *file_name, const char *descr, bool bargraph = false);
bool Load_Game(const char *file_name);


template<class T>
HRESULT Save_Vector(LPSTREAM &pStm, DynamicVectorClass<T> &list)
{
    int count = list.Count();
    HRESULT hr = pStm->Write(&count, sizeof(count), nullptr);
    if (FAILED(hr)) {
        return hr;
    }

    if (count <= 0) {
        return hr;
    }

    for (int index = 0; index < count; ++index) {

        LPPERSISTSTREAM lpPS = nullptr;
        hr = list[index]->QueryInterface(__uuidof(IPersistStream), (LPVOID *)&lpPS);
        if (FAILED(hr)) {
            return hr;
        }

        hr = OleSaveToStream(lpPS, pStm);
        if (FAILED(hr)) {
            return hr;
        }

        hr = lpPS->Release();
        if (FAILED(hr)) {
            return hr;
        }

    }

    return hr;
}


template<class T>
HRESULT Load_Vector(LPSTREAM &pStm, DynamicVectorClass<T> &list)
{
    int count = 0;
    HRESULT hr = pStm->Read(&count, sizeof(count), nullptr);
    if (FAILED(hr)) {
        return hr;
    }

    if (count <= 0) {
        return hr;
    }

    for (int index = 0; index < count; ++index) {

        LPVOID obj;
        hr = OleLoadFromStream(pStm, __uuidof(IUnknown), ppvObj);
        if (FAILED(hr)) {
            return hr;
        }

    }

    return hr;
}
