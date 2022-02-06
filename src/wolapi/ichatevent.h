/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          .H
 *
 *  @authors       CCHyper
 *
 *  @brief          interface.
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
#include <unknwn.h>


// {4DD3BAF6-7579-11D1-B1C6-006097176556}
interface IChatEvent : IUnknown
{
    virtual HRESULT _stdcall OnServerList(HRESULT res, Server *servers);
    virtual HRESULT _stdcall OnUpdateList(HRESULT res, Update *updates);
    virtual HRESULT _stdcall OnServerError(HRESULT res, LPSTR ircmsg);
    virtual HRESULT _stdcall OnConnection(HRESULT res, LPSTR motd);
    virtual HRESULT _stdcall OnMessageOfTheDay(HRESULT res, LPSTR motd);
    virtual HRESULT _stdcall OnChannelList(HRESULT res, Channel *channels);
    virtual HRESULT _stdcall OnChannelCreate(HRESULT res, Channel *channel);
    virtual HRESULT _stdcall OnChannelJoin(HRESULT res, Channel *channel, User *User);
    virtual HRESULT _stdcall OnChannelLeave(HRESULT res, Channel *channel, User *User);
    virtual HRESULT _stdcall OnChannelTopic(HRESULT res, Channel *channel, LPSTR topic);
    virtual HRESULT _stdcall OnPrivateAction(HRESULT res, User *User, LPSTR action);
    virtual HRESULT _stdcall OnPublicAction(HRESULT res, Channel *channel, User *User, LPSTR action);
    virtual HRESULT _stdcall OnUserList(HRESULT res, Channel *channel, User *users);
    virtual HRESULT _stdcall OnPublicMessage(HRESULT res, Channel *channel, User *User, LPSTR message);
    virtual HRESULT _stdcall OnPrivateMessage(HRESULT res, User *User, LPSTR message);
    virtual HRESULT _stdcall OnSystemMessage(HRESULT res, LPSTR message);
    virtual HRESULT _stdcall OnNetStatus(HRESULT res);
    virtual HRESULT _stdcall OnLogout(HRESULT status, User *User);
    virtual HRESULT _stdcall OnPrivateGameOptions(HRESULT res, User *User, LPSTR options);
    virtual HRESULT _stdcall OnPublicGameOptions(HRESULT res, Channel *channel, User *User, LPSTR options);
    virtual HRESULT _stdcall OnGameStart(HRESULT res, Channel *channel, User *users, int gameid);
    virtual HRESULT _stdcall OnUserKick(HRESULT res, Channel *channel, User *kicked, User *kicker);
    virtual HRESULT _stdcall OnUserIP(HRESULT res, User *User);
    virtual HRESULT _stdcall OnFind(HRESULT res, Channel *chan);
    virtual HRESULT _stdcall OnPageSend(HRESULT res);
    virtual HRESULT _stdcall OnPaged(HRESULT res, User *User, LPSTR message);
    virtual HRESULT _stdcall OnServerBannedYou(HRESULT res, long bannedTill);
    virtual HRESULT _stdcall OnUserFlags(HRESULT res, LPSTR name, unsigned int flags, unsigned int mask);
    virtual HRESULT _stdcall OnChannelBan(HRESULT res, LPSTR name, int banned);
    virtual HRESULT _stdcall OnSquadInfo(HRESULT res, unsigned long id, Squad *Squad);
    virtual HRESULT _stdcall OnUserLocale(HRESULT res, User *users);
    virtual HRESULT _stdcall OnUserTeam(HRESULT res, User *users);
    virtual HRESULT _stdcall OnSetLocale(HRESULT res, Locale newlocale);
    virtual HRESULT _stdcall OnSetTeam(HRESULT res, int newteam);
    virtual HRESULT _stdcall OnBuddyList(HRESULT res, User *buddy_list);
    virtual HRESULT _stdcall OnBuddyAdd(HRESULT res, User *buddy_added);
    virtual HRESULT _stdcall OnBuddyDelete(HRESULT res, User *buddy_deleted);
    virtual HRESULT _stdcall OnPublicUnicodeMessage(HRESULT res, Channel *channel, User *User, unsigned short *message);
    virtual HRESULT _stdcall OnPrivateUnicodeMessage(HRESULT res, User *User, unsigned short *message);
    virtual HRESULT _stdcall OnPrivateUnicodeAction(HRESULT res, User *User, unsigned short *action);
    virtual HRESULT _stdcall OnPublicUnicodeAction(HRESULT res, Channel *channel, User *User, unsigned short *action);
    virtual HRESULT _stdcall OnPagedUnicode(HRESULT res, User *User, unsigned short *message);
    virtual HRESULT _stdcall OnServerTime(HRESULT res, long stime);
    virtual HRESULT _stdcall OnInsiderStatus(HRESULT res, User *users);
    virtual HRESULT _stdcall OnSetLocalIP(HRESULT res, LPSTR message);
};


/*******************************************************************************
 *  @class   INetUtilEvent
 *
 *  @brief   
 */
DECLARE_INTERFACE_IID_(INetUtilEvent, IUnknown, "B832B0AC-A7D3-11D1-97C3-00609706FA0C")
{   
    STDMETHOD(OnPing)(HRESULT res, int time, unsigned long ip, int handle) PURE;
    STDMETHOD(OnLadderList)(HRESULT res, Ladder *list, int totalCount, long timeStamp, int keyRung) PURE;
    STDMETHOD(OnGameresSent)(HRESULT res) PURE;
    STDMETHOD(OnNewNick)(HRESULT res, LPSTR message, LPSTR nick, LPSTR pass) PURE;
    STDMETHOD(OnAgeCheck)(HRESULT res, int years, int consent) PURE;
    STDMETHOD(OnWDTState)(HRESULT res, unsigned char *state, int length) PURE;
    STDMETHOD(OnHighscore)(HRESULT res, Highscore *list, int totalCount, long timeStamp, int keyRung) PURE;

};
