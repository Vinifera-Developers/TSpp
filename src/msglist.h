/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          MSGLIST.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Editable message handler (used for ingame chat).
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
#include "textprint.h"
#include "tibsun_defines.h"
#include "wwkeyboard.h"


class TextLabelClass;


#define MAX_MESSAGE_LENGTH 112
#define MAX_NUM_MESSAGES   14


class MessageListClass
{
public:
    MessageListClass();
    ~MessageListClass();

    void Init(int x, int y, int max_msg, int maxchars, int height, int edit_x, int edit_y, int overflow_on, int over_start, int over_end, int width = 640);
    TextLabelClass* Add_Message(char const* name, int id, char const* txt, ColorSchemeType color, TextPrintType style, int timeout);
    bool Concat_Message(char const* name, int id, char const* txt, int timeout);
    char* Get_Message(int id);
    TextLabelClass* Get_Label(int id);
    TextLabelClass* Add_Edit(ColorSchemeType color, TextPrintType style, char* to, char cursor = 0, int width = 640);
    void Remove_Edit();
    char* Get_Edit_Buf();
    char* Get_Overflow_Buf() { return OverflowBuf; }
    void Clear_Overflow_Buf() { OverflowBuf[0] = '\0'; }
    int Is_Edit() { return IsEdit; }
    void Set_Edit_Color(ColorSchemeType color);
    bool Manage();
    int Input(KeyNumType& input);
    void Draw();
    int Num_Messages();
    void Set_Width(int width);
    void Set_Edit_Focus();
    bool Has_Edit_Focus();

public:
    TextLabelClass* MessageList;
    int MessageX;
    int MessageY;
    int MaxMessages;
    int MaxChars;
    int Height;
    bool EnableOverflow;
    bool IsEdit;
    bool AdjustEdit;
    int EditX;
    int EditY;
    TextLabelClass* EditLabel;
    char EditBuf[MAX_MESSAGE_LENGTH + 50];
    char OverflowBuf[MAX_MESSAGE_LENGTH + 50];
    int EditCurPos;
    int EditInitPos;
    char CursorChar;
    int OverflowStart;
    int OverflowEnd;
    int Width;
    char MessageBuffers[MAX_NUM_MESSAGES][MAX_MESSAGE_LENGTH + 50];
    char BufferAvail[MAX_NUM_MESSAGES];
};
