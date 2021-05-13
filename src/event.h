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

#include <always.h>
#include "special.h"
#include "target.h"
#include "tibsun_defines.h"


/*
**	This event class is used to contain all external game events (things that the player can
**	do at any time) so that these events can be transported between linked computers. This
**	encapsulation is required in order to ensure that each event affects all computers at the
**	same time (same game frame).
**	
**	NOTE: If you add or remove an event type, you must also update the globals
**	EventLength[] and EventNames[].
*/
class EventClass
{
	public:
		EventClass();
		EventClass(unsigned int house_id, SpecialClass data);
		EventClass(unsigned int house_id, EventType type, TargetClass target);
		EventClass(unsigned int house_id, EventType type);
		EventClass(unsigned int house_id, EventType type, CellStruct *cell);
		EventClass(unsigned int house_id, EventType type, TargetClass src, TargetClass dest);
		EventClass(unsigned int house_id, TargetClass src, MissionType mission, TargetClass target = TARGET_NONE, TargetClass destination = TARGET_NONE);
		EventClass(unsigned int house_id, TargetClass src, MissionType mission, TargetClass target, TargetClass destination, SpeedType speed, MPHType maxspeed);
		EventClass(unsigned int house_id, EventType type, RTTIType object, int id);
		EventClass(unsigned int house_id, EventType type, RTTIType object, CellStruct *cell);
		EventClass(unsigned int house_id, EventType type, int id, CellStruct *cell);
		EventClass(unsigned int house_id, AnimType anim, HousesType owner, Coordinate *coord);
		EventClass(unsigned int house_id, void *ptr, unsigned long size);

		int operator==(const EventClass &q) { return std::memcmp(this, &q, sizeof(q)) == 0; }
		int operator!=(const EventClass &q) { return std::memcmp(this, &q, sizeof(q)) != 0; }

		void Execute();

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
				xCellStruct Cell;
			} SellCell;

			struct {
				xTargetClass Whom;
			} Target;

			struct {
				AnimType What;
				HousesType Owner;
				xCoordinate Where;
			} Anim;
			struct {
				int Value;
			} General;

			struct {
				xTargetClass Whom;
				MissionType	Mission;
				xTargetClass Target;
				xTargetClass Destination;
			} MegaMission;

			struct {
				xTargetClass Whom;
				MissionType	Mission;
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
				xCoordinate Cell;
			} Place;

			struct {
				int ID;
				xCoordinate Cell;
			} Special;

			struct {
				unsigned long CRC;
				unsigned short CommandCount;
				unsigned char Delay;
			} FrameInfo;

			struct {
				void * Pointer;
				unsigned long Size;
			} Variable;

			struct {
				unsigned short DesiredFrameRate;
				unsigned short MaxAhead;
			} Timing;

			struct {
				unsigned short AverageTicks;
			} ProcessTime;

		} Data;
#pragma pack()
};
