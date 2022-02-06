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

#include <commctrl.h>
#include <winerror.h>
#include <ocidl.h>
#include <olectl.h>
#include <stdio.h>

// WOLAPI interfaces
#include "ichat.h"
#include "ichatevent.h"
#include "ichat2.h"
#include "ichat2event.h"
#include "idownload.h"
#include "idownloadevent.h"
#include "inetutil.h"
#include "inetutilevent.h"
#include "irtpatcher.h"
#include "irtpatcherevent.h"






//***********************************************************************************************
// For debugging chat defined hresults...
void ChatDefAsText( char* szDesc, HRESULT hRes );
void DebugChatDef( HRESULT hRes );

int iChannelLobbyNumber( const unsigned char* szChannelName );
#define REASONABLELOBBYINTERPRETEDNAMELEN 50
void InterpretLobbyNumber( char* szLobbyNameToSet, int iLobby );

class WolapiObject;

#define MAXCHATSENDLENGTH 71	//	Mainly aesthetic, and because of the length of edit line.

enum CHANNELFILTER
{
    CHANNELFILTER_NO,
    CHANNELFILTER_OFFICIAL,
    CHANNELFILTER_UNOFFICIAL,
    CHANNELFILTER_LOBBIES,
    CHANNELFILTER_LOCALLOBBYGAMES,
};

enum DISCONNECT_PING_STATUS
{
    PING_UNSTARTED,
    PING_WAITING,
    PING_GOOD,
    PING_BAD,
};
#define DISCONNECT_PING_COUNT 5






typedef enum GTYPE_WW
{
    SERVER,
    CHANNEL,
    CLIENT
} GTYPE_WW;

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






struct Server
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
};

struct Update
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
};

struct User
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
};

struct Channel
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
};

struct Group
{
    // TODO
};

struct Ladder
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
};

struct Squad
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
};

struct Highscore
{
    unsigned int SKU;
    unsigned int wins;
    unsigned int losses;
    unsigned int points;
    unsigned int rank;
    unsigned int accomplishments;
    Highscore *next;
    char login_name[40];
};





// {925CDEDE-71B9-11D1-B1C5-006097176556}
interface IRTPatcher : IUnknown
{
    virtual HRESULT _stdcall ApplyPatch(LPSTR destpath, LPSTR filename);
    virtual HRESULT _stdcall PumpMessages();
};

// {925CDEE3-71B9-11D1-B1C5-006097176556}
interface IRTPatcherEvent : IUnknown
{
    virtual HRESULT _stdcall OnProgress(LPSTR filename, int progress);
    virtual HRESULT _stdcall OnTermination(long success);
};




/**
 *  WOLAPI interfaces.
 */
interface DECLSPEC_UUID("4DD3BAF5-7579-11D1-B1C6-006097176556")
DECLSPEC_NOVTABLE Chat : public IChat, IChatEvent
{
};

interface DECLSPEC_UUID("8B938191-EF3F-11D1-9808-00609706FA0C")
DECLSPEC_NOVTABLE Chat2 : public IChat2, IChat2Event
{
};

interface DECLSPEC_UUID("x")
DECLSPEC_NOVTABLE Download : public IDownload, IDownloadEvent
{
};

interface DECLSPEC_UUID("B832B0AB-A7D3-11D1-97C3-00609706FA0C")
DECLSPEC_NOVTABLE NetUtil : public INetUtil, INetUtilEvent
{
};


/**
 *  Tiberian Sun WOLAPI implementations.
 */
class CChatEventSink : public IChatEvent
{
    public:
        CChatEventSink(WolapiObject *pOwner);
        virtual ~CChatEventSink();

        // IUnknown
        STDMETHOD(QueryInterface)(const IID &iid, void **ppv);
        STDMETHOD_(ULONG,AddRef)();
        STDMETHOD_(ULONG,Release)();

        // IChatEvent
        STDMETHOD(OnServerList)(HRESULT res, Server *servers);
        STDMETHOD(OnLogout)(HRESULT res, User *user);
        STDMETHOD(OnBusy)(HRESULT res);
        STDMETHOD(OnIdle)(HRESULT res);
        STDMETHOD(OnPageSend)(HRESULT res);
        STDMETHOD(OnPaged)(HRESULT res, User *user, LPCSTR message);
        STDMETHOD(OnFind)(HRESULT res, Channel *channel);
        STDMETHOD(OnConnection)(HRESULT res,LPCSTR motd);
        STDMETHOD(OnChannelCreate)(HRESULT res, Channel *channel);
        STDMETHOD(OnChannelModify)(HRESULT res, Channel *channel);
        STDMETHOD(OnChannelJoin)(HRESULT res, Channel *channel, User *user);
        STDMETHOD(OnChannelLeave)(HRESULT res, Channel *channel, User *user);
        STDMETHOD(OnChannelTopic)(HRESULT res, Channel *channel, LPCSTR topic);
        STDMETHOD(OnGroupList)(HRESULT res, Group *group);
        STDMETHOD(OnPublicMessage)(HRESULT res, Channel *channel, User *user, LPCSTR text);
        STDMETHOD(OnPrivateMessage)(HRESULT res, User *user, LPCSTR text);
        STDMETHOD(OnSystemMessage)(HRESULT res, LPCSTR message);
        STDMETHOD(OnNetStatus)(HRESULT res);
        STDMETHOD(OnChannelList)(HRESULT res, Channel *channels);
        STDMETHOD(OnUserList)(HRESULT res, Channel *channel, User *users);
        STDMETHOD(OnUpdateList)(HRESULT res, Update *updates);
        STDMETHOD(OnServerError)(HRESULT res);
        STDMETHOD(OnMessageOfTheDay)(HRESULT res, LPCSTR message);
        STDMETHOD(OnPrivateAction)(HRESULT res, User *user, LPCSTR message);
        STDMETHOD(OnPublicAction)(HRESULT res, Channel *channel, User *user, LPCSTR message);
        STDMETHOD(OnPrivateGameOptions)(HRESULT res, User *user, LPCSTR message);
        STDMETHOD(OnPublicGameOptions)(HRESULT res, Channel *channel, User *user, LPCSTR options);
        STDMETHOD(OnGameStart)(HRESULT res, Channel *channel, User *user, int gameid);
        STDMETHOD(OnUserKick)(HRESULT res, Channel *channel, User *kicked, User *kicker);
        STDMETHOD(OnUserIP)(HRESULT res, User *user);
        STDMETHOD(OnServerError)(HRESULT res, LPCSTR ircmsg);
        STDMETHOD(OnServerBannedYou)(HRESULT res, time_t bannedTill);
        STDMETHOD(OnUserFlags)(HRESULT res, LPCSTR name, unsigned int flags, unsigned int mask);
        STDMETHOD(OnChannelBan)(HRESULT res, LPCSTR name, int banned);
        STDMETHOD(OnSquadInfo)(HRESULT res, unsigned int id, Squad *squad);
        STDMETHOD(OnUserLocale)(HRESULT res, User *users);
        STDMETHOD(OnUserTeam)(HRESULT res, User *users);
        STDMETHOD(OnSetLocale)(HRESULT res, Locale locale);
        STDMETHOD(OnSetTeam)(HRESULT res, int team);
};

class CDownloadEventSink : public IDownloadEvent
{
    public:
        CDownloadEventSink();
        virtual ~CDownloadEventSink() {};

        // IUnknown
        STDMETHOD(QueryInterface)(const IID &iid, void **ppv);
        STDMETHOD_(ULONG,AddRef)();
        STDMETHOD_(ULONG,Release)();

        // IDownloadEvent
        STDMETHOD(OnEnd)(void);
        STDMETHOD(OnError)(int error);
        STDMETHOD(OnProgressUpdate)(int bytesread, int totalsize, int timetaken, int timeleft);
        STDMETHOD(OnStatusUpdate)(int status);
        STDMETHOD(OnQueryResume)(void);
};

class CNetUtilEventSink : public INetUtilEvent
{
    public:
        CNetUtilEventSink(WolapiObject *pOwner);
        virtual ~CNetUtilEventSink();

        // IUnknown
        STDMETHOD(QueryInterface)(const IID &iid, void **ppv);
        STDMETHOD_(ULONG,AddRef)();
        STDMETHOD_(ULONG,Release)();

        // INetUtilEvent
        STDMETHOD(OnGameresSent)(HRESULT res);
        STDMETHOD(OnLadderList)(HRESULT res, Ladder *list, int totalCount, long timeStamp, int keyRung);
        STDMETHOD(OnPing)(HRESULT res, int time, unsigned long ip, int handle);
};
