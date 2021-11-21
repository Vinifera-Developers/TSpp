/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          MISSION.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Class that handles order assignment and tracking.
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

#include "object.h"
#include "ttimer.h"
#include "ftimer.h"


class CCINIClass;
class MissionControlClass;


/*******************************************************************************
 *	This handles order assignment and tracking. The order is used to guide
 *	overall AI processing.
 */
class MissionClass : public ObjectClass
{
    public:
		MissionClass();
        MissionClass(const NoInitClass &noinit);
        virtual ~MissionClass();

        /**
         *  AbstractClass
         */
        virtual void Compute_CRC(WWCRCEngine &crc) const override;
        virtual void AI() override;

        /**
         *  ObjectClass
         */
        virtual MissionType Get_Mission() const override;
        virtual void Assign_Mission(MissionType order) override;

        /**
         *  MissionClass
         */
        virtual bool Commence();
        virtual bool Ready_To_Commence() const;

        /**
         *  Support functions.
         */
        virtual int Mission_Sleep();
        virtual int Mission_Harmless();
        virtual int Mission_Ambush();
        virtual int Mission_Attack();
        virtual int Mission_Capture();
        virtual int Mission_Guard();
        virtual int Mission_Guard_Area();
        virtual int Mission_Harvest();
        virtual int Mission_Hunt();
        virtual int Mission_Move();
        virtual int Mission_Retreat();
        virtual int Mission_Return();
        virtual int Mission_Stop();
        virtual int Mission_Unload();
        virtual int Mission_Enter();
        virtual int Mission_Construction();
        virtual int Mission_Deconstruction();
        virtual int Mission_Repair();
        virtual int Mission_Missile();
        virtual int Mission_Open();
        virtual int Mission_Rescue();
        virtual int Mission_Patrol();
        virtual void Set_Mission(MissionType mission);
        virtual void Override_Mission(MissionType mission, TARGET tarcom = nullptr, TARGET navcom = nullptr);
        virtual bool Restore_Mission();
        virtual bool entry_214() const; // has suspended mission?

		void Shorten_Mission_Timer() { Timer = 0; }

		const MissionControlClass &Get_Current_Mission_Control();

		static bool Is_Recruitable_Mission(MissionType mission);

        static const char *Mission_Name(MissionType mission);
        static MissionType Mission_From_Name(const char *name);

    public:
        /**
         *  This the tactical strategy to use. It is used by the unit script. This
         *  is a general guide for unit AI processing.
         */
		MissionType Mission;
		MissionType SuspendedMission;

        /**
         *  The order queue is used for orders that should take effect when the
         *  vehicle has reached the center point of a cell. The queued order
         *  number is +1 when stored here so that 0 will indicated there is
         *  no queued order.
         */
		MissionType MissionQueue;

		int Status;

		bool field_5C;      // set when closing apc door in UnitClass::Mission_Unload.	// is mission done?

        /**
         *  This the thread processing timer. When this value counts down to zero, then
         *  more script processing may occur.
         */
		CDTimerClass<FrameTimerClass> Timer;
};


/*******************************************************************************
 *	This is the mission control (pun) that controls how each mission behaves
 *	when it comes to interacting with the game world. Example; some
 *	missions allow the object to scatter from threats, while others require
 *	the object to remain in place. This kind of characteristics are specfied
 *	by this class.
 */
class MissionControlClass
{
	public:
		MissionControlClass();
		~MissionControlClass() {}

		const char *Name() const;

		int Normal_Delay() const { return TICKS_PER_MINUTE * Rate; }
		int AA_Delay() const { return TICKS_PER_MINUTE * AARate; }

		bool Read_INI(CCINIClass &ini);

	public:
        /**
         *  This is the mission identifier that this mission represents.
         */
		MissionType Mission;

        /**
         *  If the object should not be considered a threat when it
         *  comes to target scanning, then this will be true.
         */
		bool IsNoThreat;

        /**
         *  If objects in this mission should avoid targeting the enemy and
         *  also avoid responding to the enemy, then this will be true.
         */
		bool IsZombie;

        /**
         *  An ojbect that can be recruited into a team must be on a mission
         *  of this type.
         */
		bool IsRecruitable;

        /**
         *  If the object can behave normally except that it cannot
         *  move to another location, then this flag will be true.
         */
		bool IsParalyzed;

        /**
         *  If an object on this mission is damaged, it is allowed to
         *  retaliate?
         */
		bool IsRetaliate;

        /**
         *  Is the object allowed to scatter from immediate threats?
         */
		bool IsScatter;

        /**
         *  This specifies the time to delay between calls to the mission
         *  handler for those cases where the delay could be indefinate. The
         *  exception would be when timing is critical. Typical use of this
         *  would be to regulate the delay between mundane mission processing
         *  in order to achieve less game overhead.
         */
		double Rate;

        /**
         *  Anti-Aircraft buildings (and units) in guard or guard area mode
         *  will use this override delay interval instead of the normal "Rate" value.
         */
		double AARate;
};