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


// {B832B0AA-A7D3-11D1-97C3-00609706FA0C}
interface INetUtil : IUnknown
{
    virtual HRESULT _stdcall RequestGameresSend(LPSTR host, int port, unsigned char *data, int length);
    virtual HRESULT _stdcall RequestLadderSearch(LPSTR host, int port, LPSTR key, unsigned long SKU, int team, int cond, int sort, int number, int leading);
    virtual HRESULT _stdcall RequestLadderList(LPSTR host, int port, LPSTR keys, unsigned long SKU, int team, int cond, int sort);
    virtual HRESULT _stdcall RequestPing(LPSTR host, int timeout, int *handle);
    virtual HRESULT _stdcall PumpMessages();
    virtual HRESULT _stdcall GetAvgPing(unsigned long ip, int *avg);
    virtual HRESULT _stdcall RequestNewNick(LPSTR nick, LPSTR pass, LPSTR email, LPSTR parentEmail, int newsletter, int shareinfo);
    virtual HRESULT _stdcall RequestAgeCheck(int month, int day, int year, LPSTR email);
    virtual HRESULT _stdcall RequestWDTState(LPSTR host, int port, unsigned char request);
    virtual HRESULT _stdcall RequestLocaleLadderList(LPSTR host, int port, LPSTR keys, unsigned long SKU, int team, int cond, int sort, Locale locale);
    virtual HRESULT _stdcall RequestLocaleLadderSearch(LPSTR host, int port, LPSTR key, unsigned long SKU, int team, int cond, int sort, int number, int leading, Locale locale);
    virtual HRESULT _stdcall RequestHighscore(LPSTR host, int port, LPSTR keys, unsigned long SKU);
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
