/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Load, save and delete options dialogs.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"
#include "session.h"
#include "tibsun_defines.h"
#include "vector.h"


class FileEntryClass
{
public:
    char Descr[128]; // Save-game description.
    char Filename[32];
    unsigned Scenario; // Scenario #
    HousesType House;
    char Handle[64];
    int Campaign;      // The campaign internal id.
    FILETIME DateTime; // Date/time stamp of file.
    bool Valid;        // Is the scenario valid?
    bool Old;
    GameEnum Session; // Game session mode.
};


class LoadOptionsClass
{
public:
    /**
     *  This defines the mode of the dialog.
     */
    typedef enum OperationModeEnum {
        MODE_NONE,
        MODE_LOAD,
        MODE_SAVE,
        MODE_DELETE
    } OperationModeEnum;

public:
    LoadOptionsClass();
    virtual ~LoadOptionsClass();

    virtual bool Load_File(const char* filename);
    virtual bool Save_File(const char* filename, const char* description);
    virtual bool Delete_File(const char* filename);
    virtual bool Read_File(FileEntryClass* file, WIN32_FIND_DATA* filename);

    bool Load_Dialog();
    bool Save_Dialog(const char* description);
    bool Delete_Dialog();

    void Pick_Filename(char* buffer);
    void Clear_List();
    void Fill_List(HWND hWnd);
    bool Read_Save_Files();

private:
    OperationModeEnum Style;
    char* Extension;
    char* Description;
    int MinSpaceRequired; // min drive space requirement.
    void (*Callback)();
    enum LoadDialogState {
        STATE_PENDING = -1,    // Awaiting input
        STATE_OK = IDOK,       // OK pressed (confirmed action)
        STATE_CLOSE = IDCANCEL // Closed via ESC / system event
    } State;
    DynamicVectorClass<FileEntryClass*> Files;
};
