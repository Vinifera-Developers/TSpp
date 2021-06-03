/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          LANGUAGE.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Header with defines for the games string table.
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
#include "fetchres.h"
#include "tibsun_defines.h"


/**
 *  String id's.
 */
#define TXT_NONE                        0
#define TXT_COPYRIGHT					1     // \xA9 2000 Electronic Arts, All Rights Reserved
#define TXT_TIME_FORMAT_HOURS   		2     // Time:%02d:%02d:%02d
#define TXT_TIME_FORMAT_NO_HOURS		3     // Time:%02d:%02d
#define TXT_MONEY_FORMAT_1				4     // $%d
#define TXT_MONEY_FORMAT_2				5     // %s ($%d)
#define TXT_READY						6     // Ready
#define TXT_HOLD						7     // On Hold
#define TXT_PRIMARY						8     // Primary
#define TXT_PRI							9     // Pri.
#define TXT_OK							10    // OK
#define TXT_YES							11    // Yes
#define TXT_NO							12    // No
#define TXT_SCENARIO_WON				13    // Mission Accomplished
#define TXT_SCENARIO_LOST				14    // Mission Failed
#define TXT_CANCEL						15    // Cancel
#define TXT_IGNORE						16    // Ignore
#define TXT_CLICK_CONTINUE				17    // Click to Continue
#define TXT_MISSION_EFFICIENCY			18    // MISSION EFFICIENCY
#define TXT_MISSION_TIME_LAPSE			19    // MISSION TIME LAPSE
#define TXT_CURRENCY					20    // CURRENCY
#define TXT_CASUALTIES					21    // CASUALTIES
#define TXT_BEST_SCORES					22    // Best Scores
#define TXT_STRUCTURES					23    // Structures
#define TXT_RESUME_MISSION				24    // Resume Mission
#define TXT_VIDEO						25    // Video
#define TXT_MORE						26    // -- More --
#define TXT_INTERFACE					27    // Interface
#define TXT_TEAM						28    // Team
#define TXT_SELECTION					29    // Selection
#define TXT_CONTROL						30    // Control
#define TXT_CREATE_TEAM					31    // Create Team %2d
#define TXT_CREATE_TEAM_DESC			32    // Creates Team %d from currently selected units.
#define TXT_SELECT_TEAM					33    // Select Team %2d
#define TXT_SELECT_TEAM_DESC			34    // Select members of team %d.
#define TXT_ADD_SELECT_TEAM				35    // Add Select Team %2d
#define TXT_ADD_SELECT_TEAM_DESC		36    // Select members of team %d without unselecting other units.
#define TXT_CENTER_TEAM					37    // Center Team %2d
#define TXT_CENTER_TEAM_DESC			38    // Select and center view about team %d.
#define TXT_NEXT_OBJECT					39    // Next Object
#define TXT_NEXT_OBJECT_DESC			40    // Select the next object.
#define TXT_PREV_OBJECT					41    // Previous Object
#define TXT_PREV_OBJECT_DESC			42    // Select the previous object.
#define TXT_STOP_OBJECT					43    // Stop Object
#define TXT_STOP_OBJECT_DESC			44    // Stop the selected object(s).
#define TXT_GUARD						45    // Guard
#define TXT_GUARD_DESC					46    // Set the selected object(s) into 'guard area' mode.
#define TXT_VICTORIOUS					47    // You Are Victorious!
#define TXT_CD_ERROR1					48    // Tiberian Sun is unable to detect your CD ROM drive.
#define TXT_DLL_INVALID					49    // Tiberian Sun requires %s version %d.%d or newer.\n\nPlease consult the read me for instructions on how to\nobtain a newer version of %s.
#define TXT_ENEMY_SOLDIER				50    // Enemy Soldier
#define TXT_ENEMY_VEHICLE				51    // Enemy Unit
#define TXT_ENEMY_STRUCTURE				52    // Enemy Structure
#define TXT_INITGAME_FAILED				53    // Failed to initialize. Please reinstall.
#define TXT_PREPARECOM_FAILED			54    // One or more DLL files were missing\nor damaged. Please reinstall.
#define TXT_NO_SOUND_CARD				55    // No Sound Card Detected
#define TXT_INVALIDMODE					56    // This product requires a 16bit pixel depth!
#define TXT_LOST						57    // Game Over
#define TXT_MOUSE_REQUIRED				58    // A mouse is required for playing Tiberian Sun.
#define TXT_DSOUND_ACCESS				59    // Unable to play Direct Sound primary buffer.
#define TXT_DDRAW_UNKNOWN				60    // Unrecognized Direct Draw result code.
#define TXT_VIDEO_ERROR					61    // Error - Unable to set the video mode.
#define TXT_SHORT_TITLE					62    // Tiberian Sun
#define TXT_CRITICALLY_LOW				63    // Warning - you are critically low on free disk space for saving games. Do you want to play Tiberian Sun anyway?
#define TXT_DISK_NAME					64    // Tiberian Sun Disk %d
#define TXT_CONFIRM_SAVE				65    // Overwrite existing save game?
#define TXT_DISKFULL					66    // Warning - you are critically low on free disk space for saving games.
#define TXT_SIGNOFF						67    // Signing off - Please Wait...
#define TXT_CD_DIALOG_1					68    // Please insert a Tiberian Sun CD into the CD-ROM drive.
#define TXT_CD_DIALOG_2					69    // Please insert CD %d (%s) into the CD-ROM drive.
#define TXT_NAMES						70    // Players
#define TXT_LOSSES						71    // Losses
#define TXT_ECONOMY						72    // Economy
#define TXT_SCORE						73    // Score
#define TXT_KILLS						74    // Kills
#define TXT_RESET_HOTKEYS				75    // Are you sure you want to reset the hotkey assignments?
#define TXT_DSOUND_CANT_CREATE			76    // Warning - Unable to create Direct Sound Object.
#define TXT_DSOUND_NO_COOP				77    // Warning - Unable to set Direct Sound cooperative level.
#define TXT_DSOUND_NO_PRIMARY			78    // Warning - Unable to create Direct Sound primary buffer.
#define TXT_DSOUND_INCOMPAT				79    // Warning - Your sound card does not meet the product's audio requirements.
#define TXT_MISMATCH					80    // Game versions incompatible. To make sure you have the latest version, visit www.westwood.com
#define TXT_NO_EXPANSION_SCENARIO		81    // Error - other player does not have this expansion scenario.
#define TXT_SCENARIO_ERROR				82    // Incompatable scenario file detected. The scenario may be corrupt.
#define TXT_INVALID						83    // Invalid option switch.
#define TXT_OPTION_HELP_01				84    // Tiberian Sun \xA9 1999, Westwood Studios\n
#define TXT_OPTION_HELP_02				85    // Parameters:\n
#define TXT_OPTION_HELP_03				86    //   -DESTNET = Specify Network Number of destination system\n
#define TXT_OPTION_HELP_04				87    //   -SOCKET = Network Socket ID (0 - 16383)\n
#define TXT_OPTION_HELP_05				88    //   -STEALTH = Hide multiplayer names (\Boss mode\)\n
#define TXT_OPTION_HELP_06				89    //   -MESSAGES = Allow messages from outside this game.\n
#define TXT_MAP_ERROR					90    // Map Error!
#define TXT_SCATTER						91    // Scatter
#define TXT_SCATTER_DESC				92    // Scatter selected object(s).
#define TXT_CENTER_VIEW					93    // Center View
#define TXT_CENTER_VIEW_DESC			94    // Center the view about selected object(s).
#define TXT_CENTER_BASE					95    // Center Base
#define TXT_CENTER_BASE_DESC			96    // Center the view about the player's base.
#define TXT_ALLIANCE					97    // Alliance
#define TXT_ALLIANCE_DESC				98    // Toggle alliance with owner of selected object.
#define TXT_SELECT_VIEW					99    // Select View
#define TXT_SELECT_VIEW_DESC			100   // Select all owned objects in the current view.
#define TXT_REPAIR_MODE					101   // Repair Mode
#define TXT_REPAIR_MODE_DESC			102   // Toggle repair mode on / off.
#define TXT_SELL_MODE					103   // Sell Mode
#define TXT_SELL_MODE_DESC				104   // Toggle sell mode on / off.
#define TXT_POWER_MODE					105   // Power Mode
#define TXT_POWER_MODE_DESC				106   // Toggle power mode on / off.
#define TXT_RADAR_EVENT					107   // Goto Radar Event
#define TXT_RADAR_EVENT_DESC			108   // Center the tactical view on the last radar event.
#define TXT_RADAR_TOGGLE				109   // Radar Toggle
#define TXT_RADAR_TOGGLE_DESC			110   // Toggle radar display mode on / off.
#define TXT_SIDEBAR_UP					111   // Sidebar Up
#define TXT_SIDEBAR_UP_DESC				112   // Scrolls sidebar selection list upward.
#define TXT_LSIDEBAR_UP					113   // Structure List up
#define TXT_LSIDEBAR_UP_DESC			114   // Scroll sidebar structure selection list upward.
#define TXT_RSIDEBAR_UP					115   // Unit List Up
#define TXT_RSIDEBAR_UP_DESC			116   // Scroll sidebar unit selection list upward.
#define TXT_SIDEBAR_PGUP				117   // Sidebar PageUp
#define TXT_SIDEBAR_PGUP_DESC			118   // Page sidebar selection list upward.
#define TXT_LSIDEBAR_PGUP				119   // Structure List PageUp
#define TXT_LSIDEBAR_PGUP_DESC			120   // Page sidebar structure selection list upward.
#define TXT_RSIDEBAR_PGUP				121   // Unit List PageUp
#define TXT_RSIDEBAR_PGUP_DESC			122   // Page sidebar unit selection list upward.
#define TXT_SIDEBAR_DOWN				123   // Sidebar Down
#define TXT_SIDEBAR_DOWN_DESC			124   // Scroll sidebar selection list downward.
#define TXT_LSIDEBAR_DOWN				125   // Structure List Down
#define TXT_LSIDEBAR_DOWN_DESC			126   // Scroll sidebar structure selection list downward.
//
#define TXT_TAB_SIDEBAR					128   // Sidebar
#define TXT_TAB_BUTTON_CONTROLS			129   // Options
#define TXT_SHADOW						130   // Unrevealed Terrain
#define TXT_OPTIONS_MENU				131   // Options Menu
#define TXT_STOP						132   // Stop
#define TXT_DEPLOY_OBJECT				133   // Deploy Object
#define TXT_DEPLOY_OBJECT_DESC			134   // Deploy selected object(s).
#define TXT_WAYPOINTMODE				135   // Waypoint Mode
#define TXT_WAYPOINTMODE_DESC			136   // Toggle waypoint placement mode on / off.
#define TXT_ON							137   // On
#define TXT_OFF							138   // Off
#define TXT_MULTIPLAYER_GAME			139   // Multiplayer Game
#define TXT_SCRNCAP						140   // Screen Capture
#define TXT_SCRNCAP_DESC				141   // Take a snapshot of the game screen. (Saved as 'SCRNxxxx.PCX' file in Tiberian Sun run directory.)
#define TXT_SENDING_GO					142   // Sending GO request - Please Wait...
#define TXT_WAITING_GO					143   // Waiting for GO response - Please Wait...
#define TXT_SENDING_GO_ACK				144   // Sending GO acknowlegement - Please Wait...
#define TXT_CWAIT_STAR70				145   // *70
#define TXT_CWAIT_70NUM					146   // 70#
#define TXT_CWAIT_1170					147   // 1170
#define TXT_EASY						148   // Easy
#define TXT_NORMAL						149   // Normal
#define TXT_HARD						150   // Hard
#define TXT_HIGH						151   // High
#define TXT_LOW							152   // Low
#define TXT_FASTEST						153   // Fastest
#define TXT_FASTER						154   // Faster
#define TXT_SLOWER						155   // Slower
#define TXT_SLOWEST						156   // Slowest
#define TXT_SLOW						157   // Slow
#define TXT_MEDIUM						158   // Medium
#define TXT_FAST						159   // Fast
#define TXT_UNABLE_READ_SCENARIO		160   // Unable to read scenario!
#define TXT_ERROR_LOADING_GAME			161   // Error loading game!
#define TXT_OBSOLETE_SAVEGAME			162   // [OBSOLETE]
#define TXT_MUSTENTER_DESCRIPTION		163   // You must enter a description!
#define TXT_ERROR_SAVING_GAME			164   // Error saving mission!
#define TXT_DELETE_FILE_QUERY			165   // Delete this file?
#define TXT_EMPTY_SLOT					166   // [EMPTY SLOT]
#define TXT_MAP							167   // Map: %s
//#define =								168   // Firestorm
//
//
//
//
//
//
//
//
//
//
#define TXT_REQUEST_DENIED				179   // Request denied.
#define TXT_UNABLE_PLAY_WAAUGH			180   // Unable to play; scenario not found.
#define TXT_NOTHING_TO_JOIN				181   // Nothing to join!
#define TXT_NAME_ERROR					182   // You must enter a name!
#define TXT_YOURGAME_OUTDATED			183   // Your game version is outdated.
#define TXT_DESTGAME_OUTDATED			184   // Destination game version is outdated.
#define TXT_THATGUYS_GAME				185   // %s's Game
#define TXT_THATGUYS_GAME_BRACKET		186   // [%s's Game]
#define TXT_REJECT						187   // Reject
#define TXT_CANT_REJECT_SELF			188   // You can't reject yourself!
#define TXT_SELECT_PLAYER_REJECT		189   // You must select a player to reject.
//
//
//
#define TXT_CREDITS_COLON				193   // Credits:
#define TXT_ONLY_ONE					194   // Only one player?
#define TXT_OOPS						195   // Oops!
//#define TXT_FROM
#define TXT_TO							196   // To %s:
#define TXT_TO_ALL						197   // To All:
#define TXT_MESSAGE						198   // Message:
#define TXT_CONNECTION_LOST				199   // Connection to %s lost!
#define TXT_LEFT_GAME					200   // %s has left the game.
#define TXT_PLAYER_DEFEATED				201   // %s has been defeated!
//
//
//
//
//
#define TXT_COMPUTER					207   // Computer
#define TXT_NONAME						208   // [NONAME]
#define TXT_DEFAULT						209   // Default
#define TXT_SETTINGS					210   // Settings
#define TXT_NAME_COLON					211   // Name:
#define TXT_OUT_OF_SYNC					212   // Reconnection Error!
#define TXT_PACKET_TOO_LATE				213   // Packet received too late!
//
//
//
#define TXT_USER_SIGNED_OFF				217   // User signed off!
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
#define TXT_POWER_DRAIN					249   // Power = %d\rDrain = %d
//
//
#define TXT_STAND_BY					252   // Please Stand By...
//
//
#define TXT_LOW_POWER					255   // Low Power
#define TXT_KILLS_COLON					256   // Kills:
#define TXT_SPY_INFO					257   // Spy Info
//
#define TXT_INFANTRY					259   // Infantry
#define TXT_BUILDNGS					260   // Buildings
#define TXT_CIVILIAN_BUILDING			261   // Civilian Building
#define TXT_TECHNICIAN					262   // Technician
#define TXT_UNITS						263   // Units
#define TXT_TO_REPLAY					264   // Would you like to replay this mission?
#define TXT_SURRENDER					265   // Surrender
#define TXT_GAMENAME_MUSTBE_UNIQUE		266   // Your game name must be unique.
#define TXT_GAME_IS_CLOSED				267   // Game is closed.
#define TXT_NAME_MUSTBE_UNIQUE			268   // Your name must be unique.
#define TXT_RECONNECTING_TO				269   // Connection to %s has been interrupted. Attempting to reconnect.
#define TXT_WAITING_FOR_CONNECTIONS		270   // Waiting for all players to enter the game....
#define TXT_TIME_ALLOWED				271   // Time allowed: %02d seconds
//
#define TXT_JUST_YOU_AND_ME				273   // From Computer: It's just you and me now!
//
#define TXT_HAS_ALLIED					275   // %s has allied with %s
#define TXT_AT_WAR						276   // %s declares war on %s
//
//
//
#define TXT_SCENARIOS_DO_NOT_MATCH		280   // Scenarios don't match.
//
//
#define TXT_CONTINUE					283   // Continue
#define TXT_QUEUE_FULL					284   // Data Queue Overflow
#define TXT_SPECIAL_WARNING				285   // %s changed game options!
//
//
//
//
//
#define TXT_WAITING_FOR_OPPONENT		291   // Waiting for Opponent
//
#define TXT_GAME_WAS_SAVED				293   // Mission Saved
#define TXT_SPACE_CANT_SAVE				294   // Insufficient disk space to save a game.  Please delete a previous saved games to free up some disk space and try again.
//
//
//
//
//
#define TXT_LOADING						300   // Mission is loading. Please wait...
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
#define TXT_LOBBY						326   // Lobby
//
#define TXT_SAVING_GAME					328   // Mission saving - Please Wait...
#define TXT_GAME_FULL					329   // Game is full.
#define TXT_MUST_SELECT_GAME			330   // You must select a game!
#define TXT_S_PLAYING_S					331   // %s playing %s
#define TXT_ONLY_HOST_CAN_MODIFY		332   // Only the host can modify this option.
#define TXT_GAME_CANCELLED				333   // Game was cancelled.
#define TXT_S_FORMED_NEW_GAME			334   // %s has formed a new game.
#define TXT_GAME_NOW_IN_PROGRESS		335   // %s's game is now in progress.
//
//
//
//
//
//
#define TXT_RSIDEBAR_DOWN				342   // Unit List Down
#define TXT_RSIDEBAR_DOWN_DESC			343   // Scroll sidebar unit selection list downward.
#define TXT_SIDEBAR_PGDN				344   // Sidebar PageDown
#define TXT_SIDEBAR_PGDN_DESC			345   // Page sidebar selection list downward.
#define TXT_LSIDEBAR_PGDN				346   // Structure List PageDown
#define TXT_LSIDEBAR_PGDN_DESC			347   // Page sidebar structure selection list downward.
#define TXT_RSIDEBAR_PGDN				348   // Unit List PageDown
#define TXT_RSIDEBAR_PGDN_DESC			349   // Page sidebar unit selection list downward.
#define TXT_OPTIONS						350   // Options Menu
#define TXT_OPTIONS_DESC				351   // Display game options dialog.
#define TXT_SCROLL_N					352   // Scroll North
#define TXT_SCROLL_N_DESC				353   // Scroll tactical map to the north.
#define TXT_SCROLL_S					354   // Scroll South
#define TXT_SCROLL_S_DESC				355   // Scroll tactical map to the south.
#define TXT_SCROLL_E					356   // Scroll East
#define TXT_SCROLL_E_DESC				357   // Scroll tactical map to the east.
#define TXT_SCROLL_W					358   // Scroll West
#define TXT_SCROLL_W_DESC				359   // Scroll tactical map to the west.
#define TXT_VIEW_BOOKMARK1				360   // View Bookmark 1
#define TXT_VIEW_BOOKMARK1_DESC			361   // View bookmarked map position 1.
#define TXT_VIEW_BOOKMARK2				362   // View Bookmark 2
#define TXT_VIEW_BOOKMARK2_DESC			363   // View bookmarked map position 2.
#define TXT_VIEW_BOOKMARK3				364   // View Bookmark 3
#define TXT_VIEW_BOOKMARK3_DESC			365   // View bookmarked map position 3.
#define TXT_VIEW_BOOKMARK4				366   // View Bookmark 4
#define TXT_VIEW_BOOKMARK4_DESC			367   // View bookmarked map position 4.
#define TXT_SET_BOOKMARK1				368   // Set Bookmark 1
#define TXT_SET_BOOKMARK1_DESC			369   // Set view bookmark map position 1.
#define TXT_SET_BOOKMARK2				370   // Set Bookmark 2
#define TXT_SET_BOOKMARK2_DESC			371   // Set view bookmark map position 2.
#define TXT_SET_BOOKMARK3				372   // Set Bookmark 3
#define TXT_SET_BOOKMARK3_DESC			373   // Set view bookmark map position 3.
#define TXT_SET_BOOKMARK4				374   // Set Bookmark 4
#define TXT_SET_BOOKMARK4_DESC			375   // Set view bookmark map position 4.
#define TXT_FOLLOW						376   // Follow
#define TXT_FOLLOW_DESC					377   // Toggle follow state of selected object(s).
#define TXT_DEL_WAYPOINT				378   // Delete Waypoint
#define TXT_DEL_WAYPOINT_DESC			379   // Delete selected waypoint.
#define TXT_PAGEUSER					380   // Page User
#define TXT_PAGEUSER_DESC				381   // Page a Westwood Online user. (Internet play only)
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
#define TXT_NO_DIAL_TONE				416   // No dial tone. Ensure your modem is connected to the phone line and try again.
#define TXT_CONNECTING					417   // Connecting...
#define TXT_SELECT_SETTINGS				418   // Please select 'Settings' to setup default configuration
#define TXT_ANSWERING					419   // Answering...
#define TXT_INITIALIZING_MODEM			420   // Initializing Modem...Standby
#define TXT_ERROR_NO_INIT				421   // Error - Modem did not respond to initialisation string.
#define TXT_ERROR_NO_DISABLE			422   // Error - Unable to disable modem auto answer.
#define TXT_ERROR_TOO_MANY				423   // Error - Too many errors initialising modem - Aborting.
#define TXT_ERROR_ERROR					424   // Error - Modem returned error status.
#define TXT_ERROR_TIMEOUT				425   // Error - TIme out waiting for connect.
//
#define TXT_RECEIVING_SCENARIO			427   // Receiving scenario from host.
#define TXT_SENDING_SCENARIO			428   // Sending scenario to remote players.
#define TXT_NO_FLOW_CONTROL_RESPONSE	429   // Error - Modem failed to respond to flow control command. Your Windows configuration may be incorrect.
#define TXT_NO_COMP_DISABLE_RESPONSE	430   // Error - Modem failed to respond to compression disable command. Your Windows configuration may be incorrect.
#define TXT_NO_EC_DISABLE_RESPONSE		431   // Error - Modem failed to respond to error correction disable command. Your Windows configuration may be incorrect.
#define TXT_UNABLE_TO_OPEN_PORT			432   // Invalid Port or Port is in use
#define TXT_INVALID_PORT_ADDRESS		433   // Invalid Port/Address. COM 1-4 OR ADDRESS
#define TXT_IRQ_ALREADY_IN_USE			434   // IRQ already in use
#define TXT_ERROR_IN_INITSTRING			435   // Error in the InitString
#define TXT_MODEM_OR_LOOPBACK			436   // Not a Null Modem Cable Attached! It is a modem or loopback cable.
#define TXT_UNABLE_FIND_MODEM			437   // Unable to find modem. Check power and cables.
#define TXT_NULL_CONNERR_CHECK_CABLES	438   // Connection error! Check your cables. Attempting to Reconnect...
#define TXT_MODEM_CONNERR_REDIALING		439   // Connection error! Redialing...
#define TXT_MODEM_CONNERR_WAITING		440   // Connection error! Waiting for Call...
#define TXT_WAITING_CONNECT				441   // Waiting to Connect...
#define TXT_CUSTOM						442   // CUSTOM -
#define TXT_COM1						443   // COM1 - 3F8
#define TXT_COM2						444   // COM2 - 2F8
#define TXT_COM3						445   // COM3 - 3E8
#define TXT_COM4						446   // COM4 - 2E8
#define TXT_NO_CARRIER					447   // No carrier.
#define TXT_LINE_BUSY					448   // Line busy.
#define TXT_NUMBER_INVALID				449   // Number invalid.
#define TXT_DIALING						450   // Dialing...
#define TXT_DIALING_CANCELED			451   // Dialing Canceled
#define TXT_WAITING_FOR_CALL			452   // Waiting for Call...
#define TXT_ANSWERING_CANCELED			453   // Answering Canceled
#define TXT_SYSTEM_NOT_RESPONDING		454   // Other system not responding!
#define TXT_NO_COMP_ENABLE_RESPONSE		455   // Error - Modem failed to respond to compression enable command. Your Windows configuration may be incorect.
#define TXT_NO_EC_ENABLE_RESPONSE		456   // Error - Modem failed to respond to error correction enable command. Your Windows configuration may be incorrect.
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
#define TXT_SHIP_01						547   // +Full Name:---------Coord:---Hgt:-Str:-Ace:-Spd:-Ammo-Arm:-Grp:-Cloak:-Price:-+
#define TXT_SHIP_02						548   // ¦                  ¦        ¦    ¦    ¦    ¦    ¦    ¦    ¦    ¦      ¦       ¦
#define TXT_SHIP_03						549   // +Owner:------------+Trigger:+TarCom:--STarCom:-PFace:+Path:--------Try:-Delay:¦
#define TXT_SHIP_04						550   // ¦                  ¦        ¦        ¦        ¦      ¦            ¦    ¦      ¦
#define TXT_SHIP_05						551   // +Cargo:----Target:-+Next:---+NavCom:-+SNavCom:+SFace:+PBrk:-HeadTo:--Archive:-¦
#define TXT_SHIP_06						552   // ¦         ¦        ¦        ¦        ¦        ¦      ¦     ¦        ¦         ¦
#define TXT_SHIP_07						553   // +Tmr:-St:-Rt:-Stage+Radio:--+Radio Message History:---------------------------¦
#define TXT_SHIP_08						554   // ¦    ¦   ¦   ¦     ¦        ¦                                                 ¦
#define TXT_SHIP_09						555   // +Mission:-------Queue:------¦                                                 ¦
#define TXT_SHIP_10						556   // ¦              ¦            ¦                                                 ¦
#define TXT_SHIP_11						557   // +-----------------------------------------------------------------------------¦
#define TXT_SHIP_12						558   // ¦                                                                             ¦
#define TXT_SHIP_13						559   // +-----------------------------------------------------------------------------¦
#define TXT_SHIP_14						560   // ¦Is Down     ¦AnimAttached¦Primary     ¦Player Owned¦Initiated   ¦Repairing   ¦
#define TXT_SHIP_15						561   // ¦To Damage   ¦Falling [  ]¦Loaner      ¦Player Aware¦Deploying   ¦ToSelfRepair¦
#define TXT_SHIP_16						562   // ¦To Display  ¦Useless     ¦Locked      ¦AI Aware    ¦Firing      ¦            ¦
#define TXT_SHIP_17						563   // ¦In Limbo    ¦Ticked Off  ¦Recoil      ¦Lemon       ¦Rotating    ¦            ¦
#define TXT_SHIP_18						564   // ¦Selected    ¦Cloakable   ¦Tethered    ¦Invul [    ]¦Driving     ¦            ¦
#define TXT_SHIP_19						565   // ¦To Look     ¦Unloading   ¦Formation   ¦            ¦            ¦            ¦
#define TXT_SHIP_20						566   // ¦Team:----Mmbrs:-Qnt:-Center:--Target:-+Formation:--+------------+------------¦
#define TXT_SHIP_21						567   // ¦        ¦      ¦    ¦        ¦        ¦            ¦Understrngth¦Moving      ¦
#define TXT_SHIP_22						568   // +Mission:---------------------+---------------------¦FullStrength¦ForcedActive¦
#define TXT_SHIP_23						569   // ¦                             ¦                     ¦HasBeen     ¦Reforming   ¦
#define TXT_SHIP_24						570   // +-----------------------------------------------------------------------------+
#define TXT_SHIP_25						571   // <- F11                        Ship                                       F12 ->
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
#define TXT_NUCLEAR_BOMB				682   // Atom Bomb
#define TXT_ION_CANNON					683   // Ion Cannon
#define TXT_FIRESTORM					684   // Firestorm Defense Toggle
#define TXT_ION_STORM_APPROACHING		685   // Warning: Ion Storm approaching.
#define TXT_ION_STORM					686   // Warning: Ion Storm here!
#define TXT_EM_PULSE					687   // EM Pulse
//
//
#define TXT_FIRESTORM_ON				690   // Activated
#define TXT_CHARGING					691   // Charging...
#define TXT_YELLOW						692   // Yellow
#define TXT_GRAY						693   // Gray
#define TXT_RED							694   // Red
#define TXT_PURPLE						695   // Purple
#define TXT_BLUE						696   // Blue
#define TXT_CYAN						697   // Cyan
#define TXT_TAN							698   // Tan
#define TXT_GREEN						699   // Green
#define TXT_MODE						700   // Mode
#define TXT_RANK						701   // Rank
#define TXT_BACK						702   // Back
#define TXT_NOT_IN_LADDER				703   // Sorry, that player or rank is not in the ladder.
#define TXT_BYTES_W_TIME				704   // Bytes read: %d / %d.    Time left: %d seconds
#define TXT_BYTES_WO_TIME				705   // Bytes read: %d / %d.
#define TXT_FINDING_PATCH				706   // Finding Patch...
#define TXT_NO_SERV_LIST				707   // Couldn't get the server list
#define TXT_UPGRADEREQUIRED				708   // An upgrade is required for this game\nDo you want to download it now?\n \n \nWarning: use of \trainers\, third-party cheat programs, or any other modification of Tiberian Sun may cause the automatic update procedure to fail. Please remove any such programs or reinstall Tiberian Sun before continuing.
#define TXT_DOWNLOADING_X_OF_Y			709   // Downloading file %d of %d...
#define TXT_SERVER_ERROR				710   // Chat Server Error
#define TXT_LOGIN_USED					711   // That login is already being used.
#define TXT_BADPASS						712   // That login or password was incorrect.
#define TXT_BANNED						713   // You've been temporarily banned. Would you like to open your web browser to get more information?
#define TXT_CANT_CONNECT				714   // Could not connect to Westwood Online, check your Internet connection.
#define TXT_CHANCREATE_FAILED			715   // Could not create the channel
#define TXT_CREATED_CHAN				716   // Created channel: %s
#define TXT_CANT_JOINCHAN				717   // Error joining channel %X
#define TXT_PAGESENT					718   // Page was successful.
#define TXT_PAGEDISABLED				719   // User has pages disabled
#define TXT_PAGEUSERGONE				720   // User isn't logged in
#define TXT_PAGEFAILED					721   // Couldn't page user
#define TXT_FINDOK						722   // User is in channel %s
#define TXT_FINDNONE					723   // User isn't in any channels
#define TXT_FINDGONE					724   // User isn't logged in
#define TXT_FINDDISABLED				725   // User has find disabled
#define TXT_FINDFAILED					726   // Find failed
#define TXT_YOURE_DISCON				727   // You've been disconnected from the server
#define TXT_BANNEDTILL					728   // You've been banned from Westwood Online until %s
#define TXT_CHAN_BAN					729   // %s has been banned from the channel
#define TXT_CHAN_UNBAN					730   // The channel ban on %s has been removed
#define TXT_YOURE_KICKED				731   // You were kicked out of channel %s by %s
#define TXT_USER_KICKED					732   // User %s was kicked out of channel %s by %s
#define TXT_YOULEFT						733   // You left channel %s
#define TXT_FETCHING_SERVLIST			734   // Fetching server list
#define TXT_CONNECTING_SERVER			735   // Connecting to Westwood Online
#define TXT_REQ_CHANLIST				736   // Requesting channel list
#define TXT_JOINLOB						737   // Joining Lobby
#define TXT_JOININGCHAN					738   // Joining channel: %s
#define TXT_SEARCHING					739   // SEARCHING...
#define TXT_SEARCHING_FOR				740   // Searching for %s....
#define TXT_ACCEPTFIRST					741   // All users must accept before the game can start.
#define TXT_NO_BOUND_NET_CARD			742   // IPX not available
#define TXT_INVALID_SOCKET				743   // Socket number must be between 0 and 16383
#define TXT_DESTNET_ADDR_ERROR			744   // Destination network address must be in the format xx.xx.xx.xx
#define TXT_ABOUT_TO_TRY_MODE			745   // The display mode will be changed. If there is a problem with the new display mode then wait and the old mode will be restored.
//
//
//
//
#define TXT_APIMISSING					750   // The Westwood online support library is either missing or invalid. Please reinstall the shared internet components from your CD.
#define TXT_APIWRONGVERSION				751   // The installed version of the Westwood Online support library is too old. Please reinstall the shared internet components from your CD.
#define TXT_NOTCHANOP					752   // You must be a channel operator to do this.
#define TXT_NOSQUAD						753   // You are not in a Tiberian Sun squad.
#define TXT_LAUNCHBROWSER				754   // Would you like to launch your web browser to visit this page?
#define TXT_NOBROWSER					755   // You don't have a web browser associated with HTML files.
#define TXT_BAD_CHANNAME				756   // You can't make a channel with this name.  Try removing spaces and other punctuation.
#define TXT_BAD_CHANKEY					757   // You can't make a channel with this password. Try removing spaces and other punctuation.
#define TXT_CANTCREATE_CHAN				758   // You cannot create this channel.
#define TXT_NAME_BLANK					759   // Your player name is blank, please enter a name.
#define TXT_GAME_CLOSED					760   // That game channel has closed
#define TXT_CHANNEL_FULL				761   // That channel is full
#define TXT_JOINBAN						762   // You've been banned from this channel
#define TXT_ENTER_MESSAGE				763   // Please enter a message to send
#define TXT_NOT_IN_CHAN					764   // You can't send a message when you're not in a channel
#define TXT_WOL_CONNLOST				765   // Lost connection to Westwood Online, outside users will not be able to page you.
#define TXT_DSOUND_PROCEED				766   // Proceeding with audio disabled.
#define TXT_REQ_NICK					767   // Requesting new login...
//#define =								768   // Destroy all enemy units
//#define =								769   // The Nod forces that attacked our Phoenix base are in this sector.  Their base must be destroyed in order to secure the region.  However, there is a significant civilian population requiring evacuation.  GDI transports will evacuate the civilians once all Nod SAM sites are destroyed.  The Nod base can then be safely terminated.
//#define =								770   // It is highly probable that the Brotherhood will attempt to remove technology from the crash site and store it at the technology center.  Locate and secure the crash site, then capture the technology center.
//#define =								771   // Destroying the base in this sector will prevent further removal of artifacts from the crash site.  In addition, Nod will not be able to reinforce the site from this location.
//#define =								772   // Be advised, the Brotherhood will attempt to destroy the impact site.  GDI reinforcements are en route.  Protect the site until they arrive.
//#define =								773   // A sensor net protects the valley where Tratos is being held.  To facilitate his rescue, we must disable the array that controls this highly sensitive net.  Once down, it will be much easier to get Tratos out of the valley.
//#define =								774   // Tratos is being held in a hospital prison facility within this sector.  Avoid detection and rescue Tratos from the facility.  Once he is out, a transport will be sent in to evacuate him.  Once Tratos is clear, destroy all Nod forces in the area to prevent further experimentation.
//#define =								775   // The large dams that power Vega's base lie in this sector.  Destroying them will temporarily drain power from his base.  To aid you in your objective, attack his island facility before he can bring new generators online.  The dam can be destroyed by disabling the two regulator stations in this sector.  GDI air support will be available if you can find a way to contact them and confirm your target. 
//#define =								776   // Vega's base is secreted on an island in this sector.  Reaching it will be difficult, as there is only one overland access.  Your best chance of success lies in the use of amphibious APCs to land on the island and penetrate Vega's defenses.  Once on the island, destroy Vega's facility and command center.
//#define =								777   // Nod has taken over much of our Hammerfest base in their search for the disrupter. Nod has reactivated the perimeter to prevent GDI from attacking.  Water assault remains your only option.  Find the Firestorm Defense structure generating the perimeter and deactivate it.  Only then can reinforcements arrive.  Proceed to destroy Nod's primary base, and prevent them from attacking again.
//#define =								778   // It is imperative that you prevent the train from reaching the Nod base.  Remember, destroying the locomotive will immediately stop the train.  Recent ice melts in the region have disabled the only train bridge.  You must move quickly as Nod engineers are on their way to repair it.  The crystals can be recovered easily if you get to the train before Nod can repair the bridge.  Otherwise, we will need to attack the base in order to reclaim the crystals.
//#define =								779   // The mutants are being held on an island in this sector.  We can spare a small force to attempt a rescue.  The area leading to the island is heavily guarded.  If you are detected, more Nod forces will arrive.  Avoiding Nod patrols is advised.  You must rescue all ten mutants and lead them to the dust-off zone.  Periodic airstrikes will be available.
//#define =								780   // Destroying the supply base here will prevent the missile complex from receiving reinforcements.
//#define =								781   // The train transporting the mutants is headed to this power grid.  The grid powers the missile complex.  Merely destroying the grid is inadequate: Nod will compensate by building more power plants at the base.  Use all the mutants to plant C4 charges on all the power plants.  We'll detonate the C4 when we attack the missile complex.
//#define =								782   // Complete destruction of the missile complex is essential.  Be advised, Nod will use their Tiberium missiles and their new fighter prototypes against you.
//#define =								783   // One of two possible locations for the fighter production facility.  Use the mutants to locate its whereabouts while remaining undetected.  If detected, Nod will cloak the factory and deploy more troops.  Hide the mutants, and Nod will once again uncloak their base.  After the base location is recorded, GDI dropships will immediately arrive with reinforcements.
//#define =								784   // Another possible location of the fighter production facility.  Use the mutants to locate the position of the fighter production facility.  They must remain undetected. If Nod suspects enemy forces, they will cloak their production facility and deploy troops.  If the mutants can hide from the Nod troops for a short period, Nod will assume the area is clear, and uncloak the base.  Once we have recorded the location of the base, the mission will be complete.
//#define =								785   // Be advised: Kane is determined to destroy you.  The ion storm has grounded the Kodiak.  We must protect it until the storm abates.  Production will be limited.  There is a high probability of equipment malfunction.  Caution is advised.
//#define =								786   // Impulse signatures emanating from Cairo suggest Kane will launch his world-altering missile within hours.  You must destroy the pyramid temple before he has the chance to launch.  There are no alternatives.
//#define =								787   // Destroy all enemy units.
//#define =								788   // Hassan communicates to the Brotherhood through a nearby TV station.  With the Brotherhood in chaos, the opportunity to divide Hassan from his followers presents itself.  Capture the TV station and those once loyal to Kane's technology of peace will return to the fold.  And as for Hassan's pathetic guards -- crush them.
//#define =								789   // The infidel Hassan has been tracked to this region of Cairo.  Build a base and remove the usurper.
//#define =								790   // We have become aware of an imprisoned commander in this region who WAS loyal to Hassan.  Free him and his forces and they should be sympathetic to our cause -- and help in the capture of Hassan.  The commander may have information vital to my.......your movement.
//#define =								791   // Taking out this weak GDI position will allow us to reclaim our Sarajevo temple without interruption.  Move to an open area and build your base.  GDI patrols are known to be in the area.  Do not mar the brotherhood's name any further.
//#define =								792   // The alien craft is located in this region - find it!  You must utilize your stealth advantage, as the area is infested with GDI.  Once the craft is located, get an engineer inside to retrieve the Tacitus.  Should you encounter Vega's forces, consider them expendable.
//#define =								793   // Control of the mutants is in our grasp.  Their headquarters is located to the north of your drop-off position.  The GDI units you will need to implicate in this deception occupy a small base to the southwest.  Do not mar the Brotherhood's name any further.  Allow the blame to fall squarely on Solomon's shoulders.
//#define =								794   // You must reach the medical colony in the region without being prematurely detected by GDI and forcing a base evacuation.  To prevent this, consider first destroying the 3 sensor towers protecting the base.  Our new artillery unit should be sufficient for the job, even in your hands.  Once inside the base, the capture of the mutant female should be simple.
//#define =								795   // The mutant female may be trying to reach the underground railway system located in New Detroit.  Move in and control the station before she arrives.  If she boards the train, you must stop it immediately.  This may be our last chance of capturing the abomination.
//#define =								796   // The informant must make contact with the mutants south of the GDI base.  Use the mutants to protect the informant and to eliminate GDI patrols.  Reinforcements will arrive after you have secured the railway tunnel here.  Use them to locate and destroy the research facility.  The mutants, of course, are expendable.
//#define =								797   // Use the cyborg commando and his team to locate the bio-toxin tanker trucks.  Both trucks must reach the convoy point here if they are to arrive in time to aid you in your assault against the research facility.  GDI patrols are known to be in the area.
//#define =								798   // A cyborg commando has been sent to retrieve you.  Once free, rendezvous with your rescue team to the south.  Use them to locate and free Oxanna before she is transported to the main GDI facility.  After she has been freed, capture a GDI transport to make your escape.  
//#define =								799   // In this sector lies a Nod base overrun with tiberium-based lifeforms.  Find the base, reactivate it, and use the tiberium life to fill our missiles.  When you have enough of the tiberium substance, launch the missile against the GDI base and destroy it.
//#define =								800   // Enter the sector and deploy your base.  Once you have established a tiberium waste facility, convoys of tiberium waste will begin arriving.  Protect the convoys at all cost.  Once we have enough tiberium waste, the missile will be ready for use against GDI.  Destroying their base, once it is infected, will be a simple matter.
//#define =								801   // We must destroy GDI's new weapon.  They will, of course, build more in the future but it will buy us valuable time.  We know GDI is testing the Mammoth somewhere in this sector.  Use a chameleon spy to infiltrate a GDI comm center and locate the test site.  Your fighter prototype should be all you need to obliterate the nuisance.
//#define =								802   // The GDI defense perimeter is located here.  Do not destroy any GDI factories during your assault - you will need them to build GDI units under our control.  Once Jake McNeil's inspection detail is in our converted base, attack!  Kill all but McNeil.  Use the special toxin soldiers provided to control McNeil.  Once he has been \persuaded\ to help us in our cause, EVAC him as directed.  If he detects the trap, capture him before he can flee the sector.   
//#define =								803   // Kane's vision is at hand.  Unfortunately GDI's orbital station, the Philadelphia, can stop the missile that will take us into the future.   We must destroy the Philadelphia at all costs!  The Philadelphia will require three orbits over this sector before it can locate our missile.  You must get three ICBM launchers into position before the Philadelphia's final orbit is complete.  With the ICBMs in place, we can bring GDI's command station down.  All this remains contingent, of course, on McNeil's helpfulness.  You must pretend to pursue him back towards the GDI base.  They will open the perimeter to let him in.  Once he is in, he will deactivate the perimeter shortly thereafter.
//#define =								804   // We suggest that the brotherhood should not suffer the indignations of the past.  In order to prevent history from repeating itself, you must steal the firing codes for GDI's ion cannon.    Paranoid security measures prevent GDI from storing the entire code in one place.  Therefore, use a chameleon spy to infiltrate three different comm centers.  Once we have the codes and the spy is safely evacuated, we will be able to use GDI's ion cannon against them in the final assault.  Unfortunately GDI will have to use the ion cannon once before we can use the codes.
#define TXT_JANUARY						805   // January
#define TXT_FEBRUARY					806   // February
#define TXT_MARCH						807   // March
#define TXT_APRIL						808   // April
#define TXT_MAY							809   // May
#define TXT_JUNE						810   // June
#define TXT_JULY						811   // July
#define TXT_AUGUST						812   // August
#define TXT_SEPTEMBER					813   // September
#define TXT_OCTOBER						814   // October
#define TXT_NOVEMBER					815   // November
#define TXT_DECEMBER					816   // December
#define TXT_RELEASE_THE_HOUNDS			817   // Release
//#define =								818   // Analyzing combat zone topography...
//#define =								819   // Compiling wartime conventions...
//#define =								820   // Gathering intel on involved factions...
//#define =								821   // Creating theories on likely enemy plan...
//#define =								822   // Secondary check of combat zone...
//#define =								823   // Deploying forces to combat zone...
//#define =								824   // Final analysis of outcome...
#define TXT_RECONNECT_HELP1				825   // Click on a name to propose removing that player from the game.
#define TXT_RECONNECT_HELP2				826   // If all other players have connection times in the red then you have probably been
#define TXT_RECONNECT_HELP3				827   // Check your connection to the internet.  If you were disconnected from the internet
#define TXT_RECONNECT_HELP4				828   // disconnected from the network.
#define TXT_RECONNECT_HELP5				829   // Click cancel to abort this game and return to the lobby.
#define TXT_RECONNECT_HELP2B			830   // disconnected from your internet service provider.
#define TXT_RECONNECT_HELP3B			831   // you can re-dial your provider and continue the game as normal provided the other
#define TXT_RECONNECT_HELP3C			832   // players don't elect to remove you from the game..
#define TXT_RECONNECT_KICK_SELF			833   // You can't propose removing yourself. Click cancel to leave the game.
#define TXT_RECONNECT_KICK_RECEIVED		834   // %s proposes kicking %s from the game.
#define TXT_BIOME_TUNDRA				835   // Tundra
#define TXT_BIOME_TAIGA					836   // Taiga
#define TXT_BIOME_TEMPERATE				837   // Temperate
#define TXT_BIOME_DESERT				838   // Desert
#define TXT_TIME_MORNING				839   // Morning
#define TXT_TIME_AFTERNOON				840   // Afternoon
#define TXT_TIME_DUSK					841   // Dusk
#define TXT_TIME_NIGHT					842   // Night
#define TXT_MAPSIZE_SMALL				843   // Small
#define TXT_MAPSIZE_MEDIUM				844   // Medium
#define TXT_MAPSIZE_LARGE				845   // Large
#define TXT_MAPSIZE_VERY_LARGE			846   // V.Large
#define TXT_RANDOM_MAP_DESCRIPTION		847   // Random Map
#define TXT_LOADING_GAME1B				848   // Compensating for ambient light values...
#define TXT_CONSENT_REQUIRED			849   // Since you are under the age of 13 our privacy policy requires that you send us a parental consent form to continue.  Press 'yes' to open your web browser to this page.
#define TXT_CLAN_NOSTART				850   // To start a BattleClan tournament game there needs to be an even number of people from two clans.  Everyone in the game must be in a clan.
#define TXT_DISABLED					851   // Your account has been temporarily disabled.  Make sure the Email address you registered with is correct.  Would you like to open your web browser to get more information?
#define TXT_SERIALBANNED				852   // (NOT USED ANYMORE)
#define TXT_SERIALDUP					853   // Your Serial number is currently in use.  Would you like to open your web browser to get more information?
//#define =								854   // Taking out this weak GDI position will allow us to reclaim our Sarajevo temple without interruption.  Move in under the cover of an ion storm when GDI's communications will be down.  Take out the comm center before the storm subsides.
#define TXT_SEL_USER					855   // You must select a user to kick/ignore/ban them.
#define TXT_GOLD						856   // Gold
#define TXT_ORANGE						857   // Orange
#define TXT_SKY_BLUE					858   // Sky Blue
#define TXT_PINK						859   // Pink
#define TXT_COLOR_IN_USE				860   // The requested color is already taken.
#define TXT_NO_CLAN						861   // You must be in a BattleClan to join this game.
#define TXT_LANGCODE					862   // 0
#define TXT_SERIAL_DUP					863   // There are already 2 players with your serial# in that game.
#define TXT_SCENARIO_TOO_SMALL			864   // This map has a %d player max.  The max includes human and AI players.
#define TXT_DOWNLOAD_FAILED				865   // The download failed, please check your connection and try again later.
#define TXT_GAME_RESTART				866   // Tiberian Sun will now restart to update itself.
#define TXT_PASSWORD_TOO_SHORT			867   // Your password must be exactly 8 letters long.
#define TXT_PASSWORD_VERIFY				868   // You need to enter the same password twice.
#define TXT_LOB_1						869   // GDI Barracks
#define TXT_LOB_2						870   // NOD Barracks
#define TXT_LOB_3						871   // GDI Comm. Center
#define TXT_LOB_4						872   // Temple of NOD
#define TXT_LOB_5						873   // GDI Tech Center
#define TXT_LOB_6						874   // Hand of NOD
#define TXT_NEW_GAME					875   // New Game
#define TXT_NEW_CHAT					876   // New Chat
#define TXT_NEW							877   // New
#define TXT_GAME_CHAN					878   // Tiberian Sun game channels
#define TXT_OTHER_GAME					879   // Other game channels
#define TXT_OFFICIAL_CHAT				880   // Official chat channels
#define TXT_USER_CHAT					881   // User chat channels
#define TXT_GAME_PASSWORD				882   // Game has a password
#define TXT_LEAVE						883   // Leave
#define TXT_JOIN						884   // Join
#define TXT_OPER						885   // Channel Operator
#define TXT_VOICE						886   // Voice
#define TXT_IGNOREUSER					887   // Ignore User
#define TXT_ACCEPTED					888   // Accepted
#define TXT_JOINED_S					889   // You joined channel %s
#define TXT_REQUIRED_FIELD				890   // A required field is missing, or invalid.
#define TXT_SCENARIO_COLON				891   // Scenario:
#define TXT_TOURNEY_COLON				892   // Tournament:
#define TXT_BATTLE_CLAN					893   // BattleClan
#define TXT_HOST_RANK					894   // Host Rank:
#define TXT_UNRANKED					895   // Unranked
#define TXT_CANT_KICK					896   // You cannot kick a player from a tournament game.
//#define =								897   // The host has changed game options, press accept if you're ready.
#define TXT_GDI							898   // GDI
#define TXT_NOD							899   // Nod
#define TXT_GAME_ID						900   // Game# %d
#define TXT_TOURNAMENT_GAME				901   // Tournament Game
#define TXT_BATTLECLAN_GAME				902   // BattleClan Game
#define TXT_GAME						903   // Game: %d
//#define =								904   // %s\n%s
//#define =								905   // \nGDI: %2d%%\nNod: %2d%%
//#define =								906   // Reviewing History\n
//#define =								907   // Day : %d
//#define =								908   // Mutated
//#define =								909   // Invalid/Missing
//#define =								910   // The World Domination Tour information was either not downloaded or is corrupt.
//#define =								911   // %s\n%s\nRank : %d
//#define =								912   // Cancel
//#define =								913   // Web Page
//#define =								914   // %s\nRank : %d
#define TXT_BAD_MAP_01					915   // The host has selected
#define TXT_BAD_MAP_02					916   // a modified map.
#define TXT_BAD_MAP_03					917   // This may give the host
#define TXT_BAD_MAP_04					918   // an unfair advantage.
#define TXT_BAD_MAP_05					919   // No preview available.
//#define =								920   // Very Few
//#define =								921   // Few
//#define =								922   // Many
//#define =								923   // Very Many
//#define =								924   // Very Low
//#define =								925   // Low
//#define =								926   // High
//#define =								927   // Very High
//#define =								928   // Very Scarce
//#define =								929   // Scarce
//#define =								930   // Abundant
//#define =								931   // Very Abundant
//#define =								932   // Very Sparse
//#define =								933   // Sparse
//#define =								934   // Heavy
//#define =								935   // Very Heavy
//#define =								936   // Harvester Truce
//#define =								937   // Starting Bases
//#define =								938   // No Starting Bases
//#define =								939   // Redeployable MCV
//#define =								940   // Fog of War
//#define =								941   // Bridges Destroyable
//#define =								942   // Indestructable Bridges
//#define =								943   // Goodie Crates
//#define =								944   // No Goodie Crates
//#define =								945   // Time of Day Transitions
//#define =								946   // %s Cliffs
//#define =								947   // %s Accessibility
//#define =								948   // %s Hills
//#define =								949   // %s Tiberium
//#define =								950   // %s Tiberium Fields
//#define =								951   // %s Water
//#define =								952   // %s Vegetation
//#define =								953   // %s Cities
//#define =								954   // Tiberium Lifeforms
//#define =								955   // Veinholes
//#define =								956   // Tech Level %d
//#define =								957   // %d Starting Units
//#define =								958   // %d Credits
//#define =								959   // MCV Not Redeployable
//#define =								960   // Short Game
//#define =								961   // Unlimited Game Length
//#define =								962   // Two Player Only
//#define =								963   // Four Player Only
//#define =								964   // Tiny Map
//#define =								965   // Small Map
//#define =								966   // Narrow Map
//#define =								967   // Tall & Narrow Map
//#define =								968   // Short Map
//#define =								969   // Large Map
//#define =								970   // Short & Wide Map
//#define =								971   // Huge Map
//#define =								972   // Fetching squad information
//#define =								973   // Fetching ladder information
//#define =								974   // Could not connect to the World Domination Tour server, or there is no server available
//#define =								975   // There are no more free slots in that game for your side
//#define =								976   // The active World Domination Tour territories have changed.  Relocating to new front line...
#define TXT_FETCHING_WDT				977   // Fetching World Domination Tour information
//#define =								978   // Please Choose Map
#define TXT_WOL_LOGGING_OUT				979   // Logging off Westwood Online
//
//
#define TXT_PLAYER_CHANGED_LATENCY		982   // Player %s has changed the connection speed setting.
#define TXT_PLAYER_CHANGED_SPEED		983   // Player %s has changed the game speed setting.
#define TXT_WORST_CONNECTION			984   // Bad
#define TXT_POOR_CONNECTION				985   // Poor
#define TXT_GOOD_CONNECTION				986   // Normal
#define TXT_BEST_CONNECTION				987   // Fast
#define TXT_WARNING_LOCALE_UNKNOWN		988   // You have not set your location. Click OK to continue anyway or cancel to go back and set your location.
#define TXT_DELETE_USER					989   // Are you sure you want to remove user '%s' from the login list?
//#define =								990   // All Locations
//#define =								991   // Tiberian Sun Players
//#define =								992   // Tiberian Sun BattleClans
//#define =								993   // Firestorm Players
//#define =								994   // Firestorm BattleClans
//#define =								995   // WDT Nod Players
//#define =								996   // WDT GDI Players
#define TXT_SELECT_TYPE					997   // Select Same Type
#define TXT_SELECT_TYPE_DESC			998   // Selects all units of the same type as currently selected.
//#define =								999   // Firestorm required to join this game.
//#define =								1000  // Firestorm must be enabled to join this game.
//#define =								1001  // Unable to join original Tiberian Sun game with Firestorm enabled.
//#define =								1002  // Your serial number was not found.  This is most likely due to a mistyped serial number during installation.  You must reinstall the game, specifying a valid serial number, to play online.
//#define =								1003  // Your serial number is associated with a product other than Tiberian Sun.  You must reinstall the game, specifying a valid Tiberian Sun serial number, to play online.
//#define =								1004  // Very Scarce Tiberium
//#define =								1005  // Scarce Tiberium
//#define =								1006  // Abundant Tiberium
//#define =								1007  // Very Abundant Tiberium
//#define =								1008  // Very Few Tiberium Fields
//#define =								1009  // Few Tiberium Fields
//#define =								1010  // Many Tiberium Fields
//#define =								1011  // Numerous Tiberium Fields
//#define =								1012  // Very Low Accessibility
//#define =								1013  // Low Accessibility
//#define =								1014  // High Accessibility
//#define =								1015  // Very High Accessibility
//#define =								1016  // Very Few Cliffs
//#define =								1017  // Few Cliffs
//#define =								1018  // Many Cliffs
//#define =								1019  // Numerous Cliffs
//#define =								1020  // Very Few Hills
//#define =								1021  // Few Hills
//#define =								1022  // Many Hills
//#define =								1023  // Numerous Hills
//#define =								1024  // Very Scarce Water
//#define =								1025  // Scarce Water
//#define =								1026  // Abundant Water
//#define =								1027  // Very Abundant Water
//#define =								1028  // Very Sparse Vegetation
//#define =								1029  // Sparse Vegetation
//#define =								1030  // Heavy Vegetation
//#define =								1031  // Very Heavy Vegetation
//#define =								1032  // Very Few Cities
//#define =								1033  // Few Cities
//#define =								1034  // Many Cities
//#define =								1035  // Numerous Cities
//#define =								1036  // Multi-Engineers
//#define =								1037  // Normal Engineers
//#define =								1038  // You need %d players to start the game.
//#define =								1039  // You must have an equal number of GDI and Nod players to start the game.
//#define =								1040  // You cannot change alliances in a World Domination Tour game.
//#define =								1041  // Unknown Status
#define TXT_UNKNOWN_PING				1042  // Unknown Ping


/**
 *  Convert a text number into a text pointer.
 * 
 *  string      The text number to extract a pointer to.
 * 
 *  @returns    Returns with a pointer to the text that represents the text number specified.
 * 
 *  @author: CCHyper
 */
#ifndef NDEBUG
__forceinline const char *Text_String(int string, const char *_file = __FILE__, int _line = __LINE__)
{
    const char *str = Fetch_String(string);
    if (!str) {
        //DEBUG_WARNING("Missing text string '%s'!");
        //DEBUG_WARNING("  File: %s.\n", _file);
        //DEBUG_WARNING("  Line: %d.\n", _line);
    }
    return str;
}
#else
__forceinline const char *Text_String(int string)
{
    return Fetch_String(string);
}
#endif
