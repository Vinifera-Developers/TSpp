/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  File interface with cd drive search path support.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "bfiofile.h"


/**
 *  Return values from CDFileClass::Set_Search_Drives.
 */
enum {
    SET_OK,
    SET_NOT_FOUND,
    SET_EMPTY,
};


class CDFileClass : public BufferIOFileClass
{
public:
    CDFileClass();
    CDFileClass(const char* filename);
    CDFileClass(const Wstring& filename);
    virtual ~CDFileClass() {}

    virtual const char* Set_Name(const char* filename) override;
    virtual bool Open(const char* filename, FileAccessType rights = FILE_ACCESS_READ) override;
    virtual bool Open(FileAccessType rights = FILE_ACCESS_READ) override;

    void Searching(int on) { IsDisabled = !on; }

    static const char* Get_Search_Path(int index);
    static int Search_Drive_Count();

    static bool Is_There_Search_Drives() { return First != nullptr; }
    static int Set_Search_Drives(char* pathlist);
    static void Add_Search_Drive(char* path);
    static void Clear_Search_Drives();
    static void Refresh_Search_Drives();
    static void Set_CD_Drive(int drive);
    static int Get_CD_Drive() { return CurrentCDDrive; }
    static int Get_Last_CD_Drive() { return LastCDDrive; }

    static bool Find_First_File(char* filename);
    static bool Find_Next_File(char* filename);
    static void Find_Close();

    static void Reset_Raw_Path() { RawPath[0] = '\0'; }

public:
    bool IsDisabled;

    typedef struct {
        void* Next;
        const char* Path;
    } SearchDriveType;

    static char* RawPath;
    static SearchDriveType*& First;
    static int& CurrentCDDrive;
    static int& LastCDDrive;
};
