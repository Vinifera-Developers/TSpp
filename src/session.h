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

#include <always.h>
#include "tibsun_defines.h"
#include "vector.h"
#include "msglist.h"
#include "special.h"
#include "ccfile.h"
#include "ipxaddr.h"
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


#define    MAX_IPX_PACKET_SIZE    508

#define    MPLAYER_NAME_MAX 20

#define    MAX_MULTI_NAMES    8
#define    MAX_MULTI_GAMES    4


/**
 *  Types of games.
 */
typedef enum GameEnum
{
    GAME_NORMAL,        // Not multiplayer, (campaign)
    GAME_MODEM,            // modem game
    GAME_NULL_MODEM,    // NULL-modem
    GAME_IPX,            // IPX Network game
    GAME_INTERNET,        // Internet H2H
    GAME_SKIRMISH,        // 1 plr vs. AI's
    GAME_WDT,            // World domination tour game
} GameType;


#pragma pack(1)
typedef struct NodeNameTag
{
    char Name[MPLAYER_NAME_MAX];        // player or game name
    IPXAddressClass Address;
    union {
        struct {
            unsigned char IsOpen;
            unsigned char Addon;
            unsigned long LastTime;
        } Game;
        struct {
            char field_1E[23];            // game serial?
            HousesType House;
            PlayerColorType Color;
            HousesType ID;
            int ProcessTime;
            int field_45;                // accepted game? (treated as bool?)
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


#pragma pack(1)
typedef struct GlobalPacketType
{
    char padding[455];
} GlobalPacketType;
#pragma pack()


typedef struct MPlayerScoreType
{
    char Name[MPLAYER_NAME_MAX];
    PlayerColorType Color;
    int Wins;
    int Lost[MAX_MULTI_GAMES];
    int Kills[MAX_MULTI_GAMES];
    int Economy[MAX_MULTI_GAMES];
    int Score[MAX_MULTI_GAMES];
} MPlayerScoreType;


typedef struct MPStatsType
{
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


typedef struct GameOptionsType
{
    int ScenarioIndex;
    int Bases;
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

    bool Save(IStream *pStm);
    bool Load(IStream *pStm);
} GameOptionsType;


typedef struct TrapObjectType {
    union {
        AircraftClass *Aircraft;
        AnimClass *Anim;
        BuildingClass *Building;
        BulletClass *Bullet;
        InfantryClass *Infantry;
        UnitClass *Unit;
        void *All;
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
        ColorSchemeType Player_Color_To_Scheme_Color(PlayerColorType playercolor) const;
        void Setup_Squads();
        void Loading_Callback(int progress); // 005EF930

        bool Singleplayer_Game() const { return Type == GAME_NORMAL || Type == GAME_SKIRMISH; }

        static unsigned Compute_Unique_ID();

    public:
        GameType Type;                       // The type of session being played.
        bool field_4;
        void * field_8;
        int CommProtocol;                    // CommProtocolType
        GameOptionsType Options;
        unsigned long UniqueID;
        char Handle[MPLAYER_NAME_MAX];
        PlayerColorType PrefColor;
        PlayerColorType ColorIdx;
        HousesType House;
        int ObiWan;
        int Solo;
        const char * PreferredServer;
        int Locale;
        int Locale2;
        bool StoreNick;
        int LastNickSlot;
        bool IsGDI;
        int MaxPlayers;
        int NumPlayers;
        unsigned long MaxAhead;
        unsigned long FrameSendRate;
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
        DynamicVectorClass<MultiMission *> Scenarios;
        char ScenarioFileName[_MAX_FNAME+_MAX_EXT+2];
        char ScenarioDigest[32+2];
        unsigned int ScenarioFileLength;
        bool ScenarioIsOfficial;
        char ScenarioRequests[MAX_MULTI_NAMES];
        int RequestCount;
        IPXAddressClass HostAddress;
        DynamicVectorClass<GlobalPacketType *> field_6A4;
        int field_6BC[8];
        char field_6DC[32][8];
        MessageListClass Messages;
        IPXAddressClass MessageAddress;
        char LastMessage[MAX_MESSAGE_LENGTH];
        unsigned WWChat:1;
        MPlayerScoreType Score[MAX_MULTI_NAMES];
        int GamesPlayed;
        int NumScores;
        int Winner;
        int CurGame;
        CCFileClass RecordFile;
        unsigned Record:1;
        unsigned Play:1;
        unsigned Attract:1;
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
        DynamicVectorClass<NodeNameType *> Games;
        DynamicVectorClass<NodeNameType *> Players;
        DynamicVectorClass<NodeNameType *> Chat;
        int field_1A68;
        unsigned ModemService:1;
        int CurPhoneIdx;
        char SerialDefaults[112];            // SerialSettingsType
        int ModemType;                       // ModemGameType
        DynamicVectorClass<PhoneEntryClass *> PhoneBook;
        DynamicVectorClass<char *> InitStrings;
        DynamicVectorClass<char *> CallWaitStrings;
        int field_1B30[8];
        int LatencyFudge;
        long TrapFrame;
        RTTIType TrapObjType;
        TrapObjectType TrapObject;
        Coordinate TrapCoord;
        int TrapThis;
        TARGET TrapTarget;
        CellClass * TrapCell;
        int TrapCheckHeap;
        long TrapPrintCRC;
};
