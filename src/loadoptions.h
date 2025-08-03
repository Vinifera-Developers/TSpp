/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          LOADOPTIONS.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Load, save and delete options dialogs.
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
    OperationModeEnum Mode;
    char* FileExt;
    char* Description;
    int field_10; // min drive space requirement.
    int field_14;
    int field_18;
    DynamicVectorClass<FileEntryClass*> Files;
};
