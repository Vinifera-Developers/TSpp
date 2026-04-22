/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  Network dialog.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#pragma once

#include "session.h"

bool Init_Network();
void Shutdown_Network();
void Destroy_Connection(int id, int error);
unsigned long Compute_Name_CRC(char* name);


//---------------------------------------------------------------------------
//	The possible states of the join-game dialog
//---------------------------------------------------------------------------
typedef enum {
    JOIN_REJECTED = -1,   // we've been rejected
    JOIN_NOTHING,         // we're not trying to join a game
    JOIN_WAIT_CONFIRM,    // we're asking to join, & waiting for confirmation
    JOIN_CONFIRMED,       // we've been confirmed
    JOIN_GAME_START,      // the game we've joined is starting
    JOIN_GAME_START_LOAD, // the game we've joined is starting; load saved game
} JoinStateType;

//---------------------------------------------------------------------------
//	The possible return codes from Get_Join_Responses()
//---------------------------------------------------------------------------
typedef enum {
    EV_NONE,           // nothing happened
    EV_STATE_CHANGE,   // Join dialog is in a new state
    EV_NEW_GAME,       // a new game formed, or is now open
    EV_NEW_PLAYER,     // a new player was detected
    EV_PLAYER_SIGNOFF, // a player has signed off
    EV_GAME_SIGNOFF,   // a gamed owner has signed off
    EV_GAME_OPTIONS,   // a game options packet was received
    EV_MESSAGE,        // a message was received
} JoinEventType;


//---------------------------------------------------------------------------
//	The possible reasons we're rejected from joining a game
//---------------------------------------------------------------------------
typedef enum {
    REJECT_DUPLICATE_NAME,   // player's name is a duplicate
    REJECT_GAME_FULL,        // game is full
    REJECT_VERSION_TOO_OLD,  // joiner's version is too old
    REJECT_VERSION_TOO_NEW,  // joiner's version is too new
    REJECT_BY_OWNER,         // game owner clicked "reject"
    REJECT_DISBANDED,        // game was disbanded
    REJECT_MISMATCH,         // "rules.ini" file mismatch.
    REJECT_DUPLICATE_SERIAL, // player's serial is a duplicate
} RejectType;
