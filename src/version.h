/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          VERSION.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class that contains version info.
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
