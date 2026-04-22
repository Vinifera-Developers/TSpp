/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Save game and load game functions.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "vector.h"
#include <ole2.h>


bool Save_Game(const char* file_name, const char* descr, bool bargraph = false);
bool Load_Game(const char* file_name);

HRESULT Save_Misc_Values(IStream* pStm);
HRESULT Load_Misc_Values(IStream* pStm);

bool Put_All(IStream* pStm, bool save_net);
bool Get_All(IStream* pStm, bool load_net);

void Post_Load_Game();


template<class T>
HRESULT Save_Vector(LPSTREAM& pStm, DynamicVectorClass<T>& list)
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
        hr = list[index]->QueryInterface(__uuidof(IPersistStream), (LPVOID*)&lpPS);
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
HRESULT Load_Vector(LPSTREAM& pStm, DynamicVectorClass<T>& list)
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
        hr = OleLoadFromStream(pStm, __uuidof(IUnknown), &obj);
        if (FAILED(hr)) {
            return hr;
        }
    }

    return hr;
}
