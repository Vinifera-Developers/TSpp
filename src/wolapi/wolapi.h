/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WOLAPI.H
 *
 *  @author        Adam J. Weissman (see notes below)
 *
 *  @contributors  CCHyper, tomsons26
 *
 *  @brief         Core WOLAPI interface functions.
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
 *  @note          This file contains heavily modified code from the source code
 *                 released by Electronic Arts for the C&C Remastered Collection
 *                 under the GPL3 license. Source:
 *                 https://github.com/ElectronicArts/CnC_Remastered_Collection
 *
 ******************************************************************************/
#pragma once

#include "always.h"


namespace WOL
{
    #define CHAT_E_OK 0

    #define CHAT_S_OK 0
    #define CHAT_S_CON_CONNECTING 0x4012C
    #define CHAT_S_CON_CONNECTED 0x4012D
    #define CHAT_S_CON_DISCONNECTING 0x4012E
    #define CHAT_S_CON_DISCONNECTED 0x4012F
    #define CHAT_S_FIND_NOTHERE 0x40130
    #define CHAT_S_FIND_NOCHAN 0x40131
    #define CHAT_S_FIND_OFF 0x40132
    #define CHAT_S_PAGE_NOTHERE 0x40133
    #define CHAT_S_PAGE_OFF 0x40134

    #define CHAT_E_NICKINUSE 0x80040064
    #define CHAT_E_BADPASS  0x80040065
    #define CHAT_E_NONESUCH 0x80040066
    #define CHAT_E_CON_NETDOWN 0x80040067
    #define CHAT_E_CON_LOOKUP_FAILED 0x80040068
    #define CHAT_E_CON_ERROR 0x80040069
    #define CHAT_E_TIMEOUT 0x8004006A
    #define CHAT_E_MUSTPATCH 0x8004006B
    #define CHAT_E_STATUSERROR 0x8004006C
    #define CHAT_E_UNKNOWNRESPONSE 0x8004006D
    #define CHAT_E_CHANNELFULL 0x8004006E
    #define CHAT_E_CHANNELEXISTS 0x8004006F
    #define CHAT_E_CHANNELDOESNOTEXIST 0x80040070
    #define CHAT_E_BADCHANNELPASSWORD 0x80040071
    #define CHAT_E_BANNED 0x80040072
    #define CHAT_E_NOT_OPER 0x80040073
    #define CHAT_E_DISABLED 0x80040074
    #define CHAT_E_SERIALBANNED 0x80040075
    #define CHAT_E_SERIALDUP 0x80040076
    #define CHAT_E_SERIALUNKNOWN 0x80040077
    #define CHAT_E_SKUSERIALMISMATCH 0x80040078

    #define CHAT_E_0x80040100 0x80040100

    #define CHAT_E_NOTCONNECTED 0x800401F4
    #define CHAT_E_NOCHANNEL 0x800401F5
    #define CHAT_E_NOTIMPLEMENTED 0x800401F6
    #define CHAT_E_PENDINGREQUEST 0x800401F7
    #define CHAT_E_PARAMERROR 0x800401F8
    #define CHAT_E_800401F9 0x800401F9
    #define CHAT_E_800401FA 0x800401FA
    #define CHAT_E_800401FB 0x800401FB
    #define CHAT_E_LEAVECHANNEL 0x800401FC
    #define CHAT_E_JOINCHANNEL 0x800401FD
    #define CHAT_E_UNKNOWNCHANNEL 0x800401FE

    #define CHAT_USER_MYSELF 0x8000

    typedef enum Locale
    {
        LOC_UNKNOWN,
        LOC_OTHER,
        LOC_USA,
        LOC_CANADA,
        LOC_UK,
        LOC_GERMANY,
        LOC_FRANCE,
        LOC_SPAIN,
        LOC_NETHERLANDS,
        LOC_BELGIUM,
        LOC_AUSTRIA,
        LOC_SWITZERLAND,
        LOC_ITALY,
        LOC_DENMARK,
        LOC_SWEDEN,
        LOC_NORWAY,
        LOC_FINLAND,
        LOC_ISRAEL,
        LOC_SOUTH_AFRICA,
        LOC_JAPAN,
        LOC_SOUTH_KOREA,
        LOC_CHINA,
        LOC_SINGAPORE,
        LOC_TAIWAN,
        LOC_MALAYSIA,
        LOC_AUSTRALIA,
        LOC_NEW_ZEALAND,
        LOC_BRAZIL,
        LOC_THAILAND,
        LOC_ARGENTINA,
        LOC_PHILIPPINES,
        LOC_GREECE,
        LOC_IRELAND,
        LOC_POLAND,
        LOC_PORTUGAL,
        LOC_MEXICO,
        LOC_RUSSIA,
        LOC_TURKEY
    } Locale;

    typedef enum Tournament
    {
        TOURNAMENT_0,
        TOURNAMENT_1,
        TOURNAMENT_2,
    } Tournament;

    typedef struct Server
    {
        int gametype;
        int chattype;
        int timezone;
        float longitude;
        float lattitude;
        Server *next;
        char name[71];
        char connlabel[5];
        char conndata[128];
        char login[10];
        char password[10];
    } Server;

    typedef struct Update
    {
        unsigned long SKU;
        unsigned long version;
        int required;
        Update *next;
        char Server[65];
        char patchpath[256];
        char patchfile[33];
        char login[33];
        char password[65];
        char localpath[256];
    } Update;

    typedef struct User
    {
        unsigned int flags;
        int group;
        unsigned long reserved;
        unsigned long reserved2;
        unsigned long reserved3;
        unsigned long squadID;
        unsigned long ipaddr;
        unsigned long squad_icon;
        User *next;
        char name[10];
        char squadname[41];
        char squadabbrev[10];
        Locale locale;
        int team;
    } User;

    typedef struct Channel
    {
        int type;
        unsigned int minUsers;
        unsigned int maxUsers;
        unsigned int currentUsers;
        unsigned int official;
        unsigned int tournament;
        unsigned int ingame;
        unsigned int flags;
        unsigned long reserved;
        unsigned long ipaddr;
        int latency;
        int hidden;
        Channel *next;
        char name[17];
        char topic[81];
        char location[65];
        char key[9];
        char exInfo[41];
    } Channel;

    typedef struct Group
    {
        // TODO
    } Group;

    typedef struct Ladder
    {
        unsigned int SKU;
        unsigned int team_no;
        unsigned int wins;
        unsigned int losses;
        unsigned int points;
        unsigned int kills;
        unsigned int rank;
        unsigned int rung;
        unsigned int disconnects;
        unsigned int team_rung;
        unsigned int provisional;
        unsigned int last_game_date;
        unsigned int win_streak;
        unsigned int reserved1;
        unsigned int reserved2;
        Ladder *next;
        char login_name[40];
        Locale locale;
    } Ladder;

    typedef struct Squad
    {
        unsigned long id;
        int SKU;
        int members;
        int color1;
        int color2;
        int color3;
        int icon1;
        int icon2;
        int icon3;
        Squad *next;
        int rank;
        int team;
        int status;
        char email[81];
        char icq[17];
        char motto[81];
        char URL[129];
        char name[41];
        char abbreviation[41];
    } Squad;

    typedef struct Highscore
    {
        unsigned int SKU;
        unsigned int wins;
        unsigned int losses;
        unsigned int points;
        unsigned int rank;
        unsigned int accomplishments;
        Highscore *next;
        char login_name[40];
    } Highscore;
};

