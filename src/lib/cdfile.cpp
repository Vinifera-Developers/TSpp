/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  File interface with cd drive search path support.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "cdfile.h"


/**
 *  Fetch the path for the requested search drive entry index.
 *
 *  @author: CCHyper
 */
const char* CDFileClass::Get_Search_Path(int index)
{
    if (First == nullptr) {
        return nullptr;
    }

    SearchDriveType* sd = First;

    /**
     *  We want to loop once, even if index == 0.
     */
    for (int i = 0; i <= index; i++) {

        if (i == index) {
            return sd->Path;
        }

        sd = (SearchDriveType*)sd->Next;
        if (sd == nullptr) {
            return nullptr;
        }
    }

    return nullptr;
}


/**
 *  Fetch the number of search paths defined.
 *
 *  @author: CCHyper
 */
int CDFileClass::Search_Drive_Count()
{
    int count = 0;

    SearchDriveType* srch = First;
    while (srch) {
        ++count;
        srch = (SearchDriveType*)srch->Next;
    }

    return count;
}
