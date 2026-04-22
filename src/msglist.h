/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Editable message handler (used for ingame chat).
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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
