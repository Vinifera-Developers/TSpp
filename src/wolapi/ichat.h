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


// {4DD3BAF4-7579-11D1-B1C6-006097176556}
interface IChat : IUnknown
{
    virtual HRESULT _stdcall PumpMessages();
    virtual HRESULT _stdcall RequestServerList(unsigned long SKU, unsigned long current_version, LPSTR loginname, LPSTR password, int timeout);
    virtual HRESULT _stdcall RequestConnection(Server *server, int timeout, int domangle);
    virtual HRESULT _stdcall RequestChannelList(int channelType, int autoping);
    virtual HRESULT _stdcall RequestChannelCreate(Channel *channel);
    virtual HRESULT _stdcall RequestChannelJoin(Channel *channel);
    virtual HRESULT _stdcall RequestChannelLeave();
    virtual HRESULT _stdcall RequestUserList();
    virtual HRESULT _stdcall RequestPublicMessage(LPSTR message);
    virtual HRESULT _stdcall RequestPrivateMessage(User *users, LPSTR message);
    virtual HRESULT _stdcall RequestLogout();
    virtual HRESULT _stdcall RequestPrivateGameOptions(User *users, LPSTR options);
    virtual HRESULT _stdcall RequestPublicGameOptions(LPSTR options);
    virtual HRESULT _stdcall RequestPublicAction(LPSTR action);
    virtual HRESULT _stdcall RequestPrivateAction(User *users, LPSTR action);
    virtual HRESULT _stdcall RequestGameStart(User *users);
    virtual HRESULT _stdcall RequestChannelTopic(LPSTR topic);
    virtual HRESULT _stdcall GetVersion(unsigned long *version);
    virtual HRESULT _stdcall RequestUserKick(User *User);
    virtual HRESULT _stdcall RequestUserIP(User *User);
    virtual HRESULT _stdcall GetGametypeInfo(unsigned int gtype, int icon_size, unsigned char **bitmap, int *bmp_bytes, LPSTR *name, LPSTR *URL);
    virtual HRESULT _stdcall RequestFind(User *User);
    virtual HRESULT _stdcall RequestPage(User *User, LPSTR message);
    virtual HRESULT _stdcall SetFindPage(int findOn, int pageOn);
    virtual HRESULT _stdcall SetSquelch(User *User, int squelch);
    virtual HRESULT _stdcall GetSquelch(User *User);
    virtual HRESULT _stdcall SetChannelFilter(int channelType);
    virtual HRESULT _stdcall RequestGameEnd();
    virtual HRESULT _stdcall SetLangFilter(int onoff);
    virtual HRESULT _stdcall RequestChannelBan(LPSTR name, int ban);
    virtual HRESULT _stdcall GetGametypeList(LPSTR *list);
    virtual HRESULT _stdcall GetHelpURL(LPSTR *URL);
    virtual HRESULT _stdcall SetProductSKU(unsigned long SKU);
    virtual HRESULT _stdcall GetNick(int num, LPSTR *nick, LPSTR *pass);
    virtual HRESULT _stdcall SetNick(int num, LPSTR nick, LPSTR pass, int domangle);
    virtual HRESULT _stdcall GetLobbyCount(int* count);
    virtual HRESULT _stdcall RequestRawMessage(LPSTR ircmsg);
    virtual HRESULT _stdcall GetAttributeValue(LPSTR attrib, LPSTR *value);
    virtual HRESULT _stdcall SetAttributeValue(LPSTR attrib, LPSTR value);
    virtual HRESULT _stdcall SetChannelExInfo(LPSTR info);
    virtual HRESULT _stdcall StopAutoping();
    virtual HRESULT _stdcall RequestSquadInfo(unsigned long id);
    virtual HRESULT _stdcall RequestSetTeam(int team);
    virtual HRESULT _stdcall RequestSetLocale(Locale locale);
    virtual HRESULT _stdcall RequestUserLocale(User *users);
    virtual HRESULT _stdcall RequestUserTeam(User *users);
    virtual HRESULT _stdcall GetNickLocale(int nicknum, Locale *locale);
    virtual HRESULT _stdcall SetNickLocale(int nicknum, Locale locale);
    virtual HRESULT _stdcall GetLocaleString(LPSTR *loc_string, Locale locale);
    virtual HRESULT _stdcall GetLocaleCount(int* num);
    virtual HRESULT _stdcall SetClientVersion(unsigned long version);
    virtual HRESULT _stdcall SetCodepageFilter(int filter);
    virtual HRESULT _stdcall RequestBuddyList();
    virtual HRESULT _stdcall RequestBuddyAdd(User *newbuddy);
    virtual HRESULT _stdcall RequestBuddyDelete(User *buddy);
    virtual HRESULT _stdcall RequestPublicUnicodeMessage(unsigned short *message);
    virtual HRESULT _stdcall RequestPrivateUnicodeMessage(User *users, unsigned short *message);
    virtual HRESULT _stdcall RequestPublicUnicodeAction(unsigned short *action);
    virtual HRESULT _stdcall RequestPrivateUnicodeAction(User *users, unsigned short *action);
    virtual HRESULT _stdcall RequestUnicodePage(User *User, unsigned short *message);
    virtual HRESULT _stdcall RequestSetPlayerCount(unsigned int currentPlayers, unsigned int maxPlayers);
    virtual HRESULT _stdcall RequestServerTime();
    virtual HRESULT _stdcall RequestInsiderStatus(User *users);
    virtual HRESULT _stdcall RequestSetLocalIP();
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
