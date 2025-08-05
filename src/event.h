/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          EVENT.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Event class is used to contain all game events that are
 *                 transferred between computers in multiplayer games.
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
#include "house.h"
#include "special.h"
#include "target.h"
#include "tibsun_defines.h"


/**
 *  This event class is used to contain all external game events (things that the player can
 *  do at any time) so that these events can be transported between linked computers. This
 *  encapsulation is required in order to ensure that each event affects all computers at the
 *  same time (same game frame).
 */
class EventClass
{
public:
    EventClass();
    EventClass(int index, SpecialClass data);
    EventClass(int index, EventType type, TargetClass target);
    EventClass(int index, EventType type);
    EventClass(int index, EventType type, int val);
    EventClass(int index, EventType type, const Cell& cell);
    EventClass(int index, EventType type, TargetClass src, TargetClass dest);
    EventClass(int index, TargetClass src, MissionType mission, TargetClass target = TargetClass(), TargetClass destination = TargetClass());
    EventClass(int index, TargetClass src, MissionType mission, TargetClass target, TargetClass destination, SpeedType speed, MPHType maxspeed);
    EventClass(int index, EventType type, RTTIType object, int id);
    EventClass(int index, EventType type, RTTIType object, Cell const& cell);
    EventClass(int index, EventType type, int id, const Cell& cell);
    EventClass(int index, AnimType anim, HousesType owner, const Coord& coord);
    EventClass(int index, EventType type, void* ptr, unsigned long size);

    EventClass(EventType type, unsigned long hi, unsigned long lo)
    {
        ID = PlayerPtr->HeapID;
        Type = type;
        Frame = ::Frame;
        Data.LongLong.Hi = hi;
        Data.LongLong.Lo = lo;
    }

    EventClass(EventType type, unsigned long hi, unsigned long lo, unsigned long extra)
    {
        ID = PlayerPtr->HeapID;
        Type = type;
        Frame = ::Frame;
        Data.LongLongExtra.Hi = hi;
        Data.LongLongExtra.Lo = lo;
        Data.LongLongExtra.Extra = extra;
    }

    int operator==(const EventClass& q) { return std::memcmp(this, &q, sizeof(q)) == 0; }
    int operator!=(const EventClass& q) { return std::memcmp(this, &q, sizeof(q)) != 0; }

    void Execute();

    static const char* Event_Name(EventType event);
    static unsigned char Event_Length(EventType event);

#pragma pack(1) // We need this so bools/bits are not aligned.
public:
    EventType Type;
    unsigned Frame;
    bool IsExecuted;
    int ID;

    union {
        struct {
            SpecialClass Data;
        } Options;

        struct {
            xCell Cell;
        } SellCell;

        struct {
            xTargetClass Whom;
        } Target;

        struct {
            AnimType What;
            HousesType Owner;
            xCoord Where;
        } Anim;
        struct {
            int Value;
        } General;

        struct {
            xTargetClass Whom;
            MissionType Mission;
            xTargetClass Target;
            xTargetClass Destination;
        } MegaMission;

        struct {
            xTargetClass Whom;
            MissionType Mission;
            xTargetClass Target;
            xTargetClass Destination;
            SpeedType Speed;
            MPHType MaxSpeed;
        } MegaMission_F;

        struct {
            xTargetClass Whom;
            MissionType Mission;
        } Mission;

        struct {
            xTargetClass Whom;
            xTargetClass Where;
        } NavCom;

        struct {
            xTargetClass Whom;
            xTargetClass Target;
        } TarCom;

        struct {
            RTTIType Type;
            int ID;
        } Specific;

        struct {
            RTTIType Type;
            xCell Cell;
        } Place;

        struct {
            int ID;
            Cell Cell;
        } Special;

        struct {
            unsigned long CRC;
            unsigned short CommandCount;
            unsigned char Delay;
        } FrameInfo;

        struct {
            void* Pointer;
            unsigned long Size;
        } Variable;

        struct {
            unsigned short DesiredFrameRate;
            unsigned short MaxAhead;
            unsigned char FrameSendRate;
        } Timing;

        struct {
            unsigned short AverageTicks;
        } ProcessTime;

        struct { // For 64-bit integers.
            unsigned long Hi;
            unsigned long Lo;
        } LongLong;

        struct { // For 64-bit integers with additional 32-bit value.
            unsigned long Hi;
            unsigned long Lo;
            unsigned long Extra;
        } LongLongExtra;

        // Used for direct byte access to this events data, in debug cases only!
        struct {
            unsigned char Byte[1];
        } Array;

    } Data;
#pragma pack()
};
