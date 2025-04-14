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


class MissionClass : public ObjectClass
{
    public:
        MissionClass();
        MissionClass(const NoInitClass &noinit);
        virtual ~MissionClass();

        /**
         *  AbstractClass
         */
        virtual void Object_CRC(CRCEngine &crc) const override;
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
        virtual void Override_Mission(MissionType mission, AbstractClass * tarcom = nullptr, AbstractClass * navcom = nullptr);
        virtual bool Restore_Mission();
        virtual bool Has_Suspended_Mission() const; // has suspended mission?

        void Shorten_Mission_Timer() { Timer = 0; }

        const MissionControlClass &Get_Current_Mission_Control() const;

        static bool Is_Recruitable_Mission(MissionType mission);

        static const char *Mission_Name(MissionType mission);
        static MissionType Mission_From_Name(const char *name);

    public:
        MissionType CurrentMission;
        MissionType SuspendedMission;
        MissionType MissionQueue;
        int Status;
        bool field_5C;      // set when closing apc door in UnitClass::Mission_Unload.	// is mission done?
        CDTimerClass<FrameTimerClass> Timer;
};


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
        MissionType Mission;
        bool IsNoThreat;
        bool IsZombie;
        bool IsRecruitable;
        bool IsParalyzed;
        bool IsRetaliate;
        bool IsScatter;
        double Rate;
        double AARate;
};