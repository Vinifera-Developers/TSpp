/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Class that contains version info.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "always.h"


typedef enum CommProtocolEnum {
    COMM_PROTOCOL_SINGLE_NO_COMP = 0, // single frame with no compression.
    COMM_PROTOCOL_SINGLE_E_COMP,      // single frame with event compression.
    COMM_PROTOCOL_MULTI_E_COMP,       // multiple frame with event compression.
    COMM_PROTOCOL_COUNT,
    DEFAULT_COMM_PROTOCOL = COMM_PROTOCOL_MULTI_E_COMP
} CommProtocolType;


typedef struct VersionProtocolType {
    unsigned long Version;
    CommProtocolType Protocol;
} VersionProtocolType;


class VersionClass
{
public:
    VersionClass();
    virtual ~VersionClass();

    unsigned long Version_Number();
    unsigned short Major_Version();
    unsigned short Minor_Version();
    const char* Version_Name();
    const char* Version_Text() { return VersionText; }
    CommProtocolType Version_Protocol(unsigned long version);
    void Init_Clipping();
    unsigned long Clip_Version(unsigned long minver, unsigned long maxver);
    unsigned long Get_Clipped_Version() { return MaxClipVer; }
    unsigned long Min_Version();
    unsigned long Max_Version();

private:
    unsigned long Version;
    unsigned short MajorVer;
    unsigned short MinorVer;
    char VersionName[30];
    char VersionText[16];
    unsigned long MinClipVer;
    unsigned long MaxClipVer;
    unsigned VersionInit : 1;
    unsigned MajorInit : 1;
    unsigned MinorInit : 1;
    unsigned TextInit : 1;
};
