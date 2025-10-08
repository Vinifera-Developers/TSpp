/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SESSION.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Game session values.
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
#include "ccfile.h"
#include "ipxaddr.h"
#include "msglist.h"
#include "special.h"
#include "tibsun_defines.h"
#include "vector.h"
#include "version.h"
#include <Unknwn.h>


class MultiMission;
class AircraftClass;
class AnimClass;
class BuildingClass;
class BulletClass;
class InfantryClass;
class UnitClass;
class CellClass;
class PhoneEntryClass;


#define MAX_IPX_PACKET_SIZE 508

#define MPLAYER_NAME_MAX 20
#define SERIAL_MAX               23
#define ENCRYPTION_STRING_LENGTH 128

#define MAX_MULTI_NAMES 8
#define MAX_MULTI_GAMES 4


/**
 *  Types of games.
 */
typedef enum GameEnum {
    GAME_NORMAL,     // Not multiplayer, (campaign)
    GAME_MODEM,      // modem game
    GAME_NULL_MODEM, // NULL-modem
    GAME_IPX,        // IPX Network game
    GAME_INTERNET,   // Internet H2H
    GAME_SKIRMISH,   // 1 plr vs. AI's
    GAME_WDT,        // World domination tour game
} GameType;


#pragma pack(1)
typedef struct NodeNameTag {
    char Name[MPLAYER_NAME_MAX]; // player or game name
    IPXAddressClass Address;
    union {
        struct {
            unsigned char IsOpen;
            unsigned char Addon;
            unsigned long LastTime;
        } Game;
        struct {
            char field_1E[23]; // game serial?
            HousesType House;
            PlayerColorType Color;
            HousesType ID;
            int ProcessTime;
            int field_45; // accepted game? (treated as bool?)
            int Clan;
        } Player;
        struct {
            unsigned long LastTime;
            unsigned char LastChance;
            PlayerColorType Color;
        } Chat;
    };
} NodeNameType;
#pragma pack()


typedef enum NetCommandType {
    NET_QUERY_GAME,      // Hey, what games are out there?
    NET_ANSWER_GAME,     // Yo, Here's my game's name!
    NET_QUERY_PLAYER,    // Hey, what players are in this game?
    NET_ANSWER_PLAYER,   // Yo, I'm in that game!
    NET_CHAT_ANNOUNCE,   // I'm at the chat screen
    NET_CHAT_REQUEST,    // Respond with a CHAT_ANNOUNCE, please.
    NET_QUERY_JOIN,      // Hey guys, can I play too?
    NET_CONFIRM_JOIN,    // Well, OK, if you really want to.
    NET_REJECT_JOIN,     // No, you can't join; sorry, dude.
    NET_GAME_OPTIONS,    // Hey, dudes, here's some new game options
    NET_SIGN_OFF,        // Bogus, dudes, my boss is coming; I'm outta here!
    NET_GO,              // OK, jump into the game loop!
    NET_MESSAGE,         // Here's a message
    NET_PING,            // I'm pinging you to take a time measurement
    NET_LOADGAME,        // start a game by loading a saved game
    NET_PROGRESS_REPORT, //
    NET_REQ_SCENARIO,    // Reqest that host sends the scenario file to the other players.
    NET_FILE_INFO,       // Info about the file that is going to be transferred
    NET_FILE_CHUNK,      // A chunk of scenario
    NET_READY_TO_GO,     // Sent in response to a 'GO' command
    NET_NO_SCENARIO,     // Scenario isnt available on remote machine so we cant play
    NET_FILE_INFO_ACK,   //
    NET_PUB_GAMEOPT,     //
    NET_PRIV_GAMEOPT,    //
    NET_PREVIEW_MODE,    //
    NET_PREVIEW_ACK,     //
    NET_REQ_PREVIEW,     //
    NET_PROPOSE_KICK,    //
} NetCommandType;


#pragma pack(1)
typedef struct GlobalPacketType {
    NetCommandType Command;
    char Name[MPLAYER_NAME_MAX];
    char Serial[SERIAL_MAX];
    union {
        struct {
            unsigned int IsOpen : 1;
            unsigned int IsFirestorm : 1;
        } GameInfo;
        struct {
            int House;
            int Color;
            unsigned long NameCRC;
            unsigned long MinVersion;
            unsigned long MaxVersion;
            int CheatCheck;
            int AICheatCheck;
            int ArtCheatCheck;
            int BuildNumber;
        } PlayerInfo;
        struct {
            char pad[0x83 - 0x2F];
            unsigned int FileLength;
            char ShortFileName[12];
            unsigned char FileDigest[32];

        } ScenarioInfo;
        struct {
            char Buf[400];
            PlayerColorType Color;
            unsigned long NameCRC;
        } Message;
        struct {
            int OneWay;
        } ResponseTime;
        struct {
            int Why;
        } Reject;
        struct {
            unsigned long ID;
            int Color;
        } Chat;
        struct {
            int Percent;
        } Progress;
        struct {
            unsigned long ID1;
            unsigned long ID2;
        } Kick;

        char padding[455 - sizeof(Command) - sizeof(Name) - sizeof(Serial)];
    };
} GlobalPacketType;
#pragma pack()

static_assert(sizeof(GlobalPacketType) == 455, "GlobalPacketType has wrong size!");

typedef enum SerialCommandType {
    SERIAL_CONNECT = 100,   // Are you there?  Hello?  McFly?
    SERIAL_GAME_OPTIONS,    // Hey, dudes, here's some new game options
    SERIAL_SIGN_OFF,        // Bogus, dudes, my boss is coming; I'm outta here!
    SERIAL_GO,              // OK, dudes, jump into the game loop!
    SERIAL_MESSAGE,         // Here's a message
    SERIAL_TIMING,          // timimg packet
    SERIAL_SCORE_SCREEN,    // player at score screen
    SERIAL_LOADGAME,        // Start the game, loading a saved game first
    SERIAL_PROGRESS_REPORT, //
    SERIAL_LAST_COMMAND,    // last command
    SERIAL_REQ_SCENARIO,    // Reqest that host sends the scenario file to the other players.
    SERIAL_FILE_INFO,       // Info about the file that is going to be transferred
    SERIAL_FILE_CHUNK,      // A chunk of scenario
    SERIAL_FILE_INFO_ACK,   //
    SERIAL_READY_TO_GO,     // Sent in response to a 'GO' command
    SERIAL_NO_SCENARIO,     // Scenario isnt available on remote machine so we cant play
    SERIAL_ACCEPT_OPTIONS,  //
    SERIAL_PREVIEW_MODE,    //
    SERIAL_PREVIEW_ACK,     //
    SERIAL_REQ_PREVIEW,     //
} SerialCommandType;

typedef struct {
    SerialCommandType Command;
    char Name[MPLAYER_NAME_MAX];
    unsigned char ID;
    union {
        struct {
            HousesType House;
            char Color;
            unsigned long MinVersion;
            unsigned long MaxVersion;
            char Scenario[DESCRIP_MAX];
            unsigned int Credits;
            unsigned int IsBases : 1;
            unsigned int IsBridgeDestruction : 1;
            unsigned int IsGoodies : 1;
            unsigned int IsGhosties : 1;
            unsigned int OfficialScenario : 1;
            int CheatCheck;
            unsigned char BuildLevel;
            unsigned char UnitCount;
            unsigned char AIPlayers;
            unsigned char AIDifficulty;
            unsigned int IsUnknownFlag1 : 1;
            unsigned int IsHarvTruce : 1;
            unsigned int IsMCVRedeploy : 1;
            unsigned int IsFogOfWar : 1;
            unsigned int IsShortGame : 1;
            unsigned int IsCrapEngineers : 1;
            unsigned int IsFirestorm : 1;
            int Seed;
            SpecialClass Special;
            unsigned long ResponseTime;
            unsigned int FileLength;
            unsigned char GameSpeed;
            char ShortFileName[13];
            unsigned char FileDigest[32];

            int AICheatCheck;
            int ArtCheatCheck;
            int BuildNumber;
        } ScenarioInfo;
        struct {
            char Message[MAX_MESSAGE_LENGTH + 10];
            PlayerColorType Color;
        } Message;
        struct {
            PlayerColorType Color;
        } Chat;
        struct {
            int Percent;
        } Progress;

        char padding[0xB0 - 4 - MPLAYER_NAME_MAX - 1];
    };
} SerialPacketType;

typedef enum DetectPortType {
    PORT_VALID = 0,
    PORT_INVALID,
    PORT_IRQ_INUSE
} DetectPortType;

typedef enum DialStatusType {
    DIAL_CONNECTED = 0,
    DIAL_NO_CARRIER,
    DIAL_BUSY,
    DIAL_ERROR,
    DIAL_NO_DIAL_TONE,
    DIAL_TIMEOUT,
    DIAL_CANCELED
} DialStatusType;

typedef enum DialMethodType {
    DIAL_TOUCH_TONE = 0,
    DIAL_PULSE,
    DIAL_METHODS
} DialMethodType;

typedef enum CallWaitStringType {
    CALL_WAIT_TONE_1 = 0,
    CALL_WAIT_TONE_2,
    CALL_WAIT_PULSE,
    CALL_WAIT_CUSTOM,
    CALL_WAIT_STRINGS_NUM
} CallWaitStringType;

typedef enum ModemGameType {
    MODEM_NULL_HOST = 0,
    MODEM_NULL_JOIN,
    MODEM_DIALER,
    MODEM_ANSWERER
} ModemGameType;

typedef struct {
    int Port;
    int IRQ;
    int Baud;
    DialMethodType DialMethod;
    int InitStringIndex;
    int CallWaitStringIndex;
    int Compression;
    int ErrorCorrection;
    char CallWaitString[16];
    char ModemName[63];
} SerialSettingsType;

typedef struct MPlayerScoreType {
    char Name[MPLAYER_NAME_MAX];
    PlayerColorType Color;
    int Wins;
    int Lost[MAX_MULTI_GAMES];
    int Kills[MAX_MULTI_GAMES];
    int Economy[MAX_MULTI_GAMES];
    int Score[MAX_MULTI_GAMES];
} MPlayerScoreType;


typedef struct MPStatsType {
    char Name[64];
    int MaxRoundTrip;
    int Resends;
    int Lost;
    int PercentLost;
    int MaxAvgRoundTrip;
    int FrameSyncStalls;
    int CommandCountStalls;
    IPXAddressClass Address;
} MPStatsType;


typedef struct GameOptionsType {
    int ScenarioIndex;
    bool Bases;
    int Credits;
    bool BridgeDestruction;
    bool Goodies;
    bool ShortGame;
    int GameSpeed;
    bool CrapEngineers;
    bool Ghosts;
    int UnitCount;
    int AIPlayers;
    int AIDifficulty;
    bool AlliesAllowed;
    bool HarvesterTruce;
    bool CaptureTheFlag;
    bool FogOfWar;
    bool RedeployMCV;
    char ScenarioDescription[DESCRIP_MAX];

    bool Save(IStream* pStm);
    bool Load(IStream* pStm);
} GameOptionsType;


typedef struct TrapObjectType {
    union {
        AircraftClass* Aircraft;
        AnimClass* Anim;
        BuildingClass* Building;
        BulletClass* Bullet;
        InfantryClass* Infantry;
        UnitClass* Unit;
        void* All;
    } Ptr;
} TrapObjectType;


class SessionClass
{
public:
    SessionClass();
    ~SessionClass();

    void One_Time();
    void Init();
    int Create_Connections();
    bool Am_I_Master();
    void Read_MultiPlayer_Settings();
    // 005EE190
    void Write_MultiPlayer_Settings();
    void Read_Scenario_Descriptions();
    void Free_Scenario_Descriptions();
    void Trap_Object();
    ColorSchemeType Scheme_From_Color_ID(PlayerColorType playercolor) const;
    void Setup_Squads();
    void Loading_Callback(int progress); // 005EF930

    bool Singleplayer_Game() const { return Type == GAME_NORMAL || Type == GAME_SKIRMISH; }

    static unsigned Compute_Unique_ID();

public:
    GameType Type; // The type of session being played.
    bool field_4;
    void* field_8;
    int CommProtocol; // CommProtocolType
    GameOptionsType Options;
    unsigned long UniqueID;
    char Handle[MPLAYER_NAME_MAX];
    PlayerColorType PrefColor;
    PlayerColorType ColorIdx;
    HousesType House;
    int ObiWan;
    int Solo;
    const char* PreferredServer;
    int Locale;
    int Locale2;
    bool StoreNick;
    int LastNickSlot;
    bool IsGDI;
    int MaxPlayers;
    int NumPlayers;
    int MaxAhead;
    int FrameSendRate;
    int DesiredFrameRate;
    int ProcessTimer;
    int ProcessTicks;
    int ProcessFrames;
    int MaxMaxAhead;
    int PrecalcMaxAhead;
    int PrecalcDesiredFrameRate;
    MPStatsType Stats[MAX_MULTI_NAMES];
    char field_418[24];
    int field_430;
    bool MPlayerDebug;
    int LoadGame;
    int EmergencySave;
    bool field_440;
    bool SawCompletion;
    bool field_442;
    int field_444;
    DynamicVectorClass<MultiMission*> Scenarios;
    char ScenarioFileName[_MAX_FNAME + _MAX_EXT + 2];
    char ScenarioDigest[32 + 2];
    unsigned int ScenarioFileLength;
    bool ScenarioIsOfficial;
    char ScenarioRequests[MAX_MULTI_NAMES];
    int RequestCount;
    IPXAddressClass HostAddress;
    DynamicVectorClass<GlobalPacketType*> field_6A4;
    int field_6BC[8];
    char field_6DC[32][8];
    MessageListClass Messages;
    IPXAddressClass MessageAddress;
    char LastMessage[MAX_MESSAGE_LENGTH];
    unsigned WWChat : 1;
    MPlayerScoreType Score[MAX_MULTI_NAMES];
    int GamesPlayed;
    int NumScores;
    int Winner;
    int CurGame;
    CCFileClass RecordFile;
    unsigned Record : 1;
    unsigned Play : 1;
    unsigned Attract : 1;
    int IsBridge;
    IPXAddressClass BridgeNet;
    bool NetStealth;
    bool NetProtect;
    bool NetOpen;
    char GameName[MPLAYER_NAME_MAX];
    GlobalPacketType GPacket;
    int GPacketlen;
    IPXAddressClass GAddress;
    unsigned short GProductID;
    char MetaPacket[MAX_IPX_PACKET_SIZE];
    int MetaSize;
    DynamicVectorClass<NodeNameType*> Games;
    DynamicVectorClass<NodeNameType*> Players;
    DynamicVectorClass<NodeNameType*> Chat;
    int Suspended;
    unsigned ModemService : 1;
    int CurPhoneIdx;
    char SerialDefaults[112]; // SerialSettingsType
    int ModemType;            // ModemGameType
    DynamicVectorClass<PhoneEntryClass*> PhoneBook;
    DynamicVectorClass<char*> InitStrings;
    DynamicVectorClass<char*> CallWaitStrings;
    int field_1B30[8];
    int LatencyFudge;
    long TrapFrame;
    RTTIType TrapObjType;
    TrapObjectType TrapObject;
    Coord TrapCoord;
    int TrapThis;
    AbstractClass* TrapTarget;
    CellClass* TrapCell;
    int TrapCheckHeap;
    long TrapPrintCRC;
};
