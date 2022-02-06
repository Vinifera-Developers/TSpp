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


// {8B938192-EF3F-11D1-9808-00609706FA0C}
interface IChat2Event : IUnknown
{
    virtual HRESULT _stdcall OnNetStatus(HRESULT res);
    virtual HRESULT _stdcall OnMessage(HRESULT res, User *User, LPSTR message);
    virtual HRESULT _stdcall OnChannelList(HRESULT res, Channel *list);
    virtual HRESULT _stdcall OnChannelJoin(HRESULT res, Channel *chan, User *User);
    virtual HRESULT _stdcall OnLogin(HRESULT res);
    virtual HRESULT _stdcall OnUserList(HRESULT res, Channel *chan, User *users);
    virtual HRESULT _stdcall OnChannelLeave( HRESULT res, Channel *chan, User *User);
    virtual HRESULT _stdcall OnChannelCreate( HRESULT res, Channel *chan);
    virtual HRESULT _stdcall OnUnknownLine(HRESULT res, LPSTR line);
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
