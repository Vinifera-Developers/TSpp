/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TEAM.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Unit team object class.
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

#include "abstract.h"
#include "ttimer.h"
#include "ftimer.h"
#include "vector.h"


class ScriptMissionClass;
class BuildingTypeClass;
class TechnoTypeClass;
class TeamTypeClass;
class ScriptClass;
class HouseClass;
class FootClass;
class TechnoClass;
class TagClass;


class DECLSPEC_UUID("0E272DCF-9C0F-11D1-B709-00A024DDAFD1")
TeamClass : public AbstractClass
{
	public:
		typedef enum TeamClassEnums {
			MAX_TEAM_CLASSCOUNT = 6
		};

    public:
        /**
         *  IPersist
         */
        IFACEMETHOD(GetClassID)(CLSID *pClassID);

        /**
         *  IPersistStream
         */
        IFACEMETHOD(Load)(IStream *pStm);
        IFACEMETHOD(Save)(IStream *pStm, BOOL fClearDirty);

    public:
        TeamClass(TeamTypeClass *classof = nullptr, HouseClass *house = nullptr, void *a3 = nullptr);
        TeamClass(const NoInitClass &noinit);
        virtual ~TeamClass();

        /**
         *  AbstractClass
         */
        virtual void Detach(TARGET target, bool all = false) override;
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;
        virtual void AI() override;

		void Assign_Mission_Target(TARGET new_target);
		// 00623360
		// 006233B0
		// 00623680
		bool Add(FootClass *obj);
		bool Can_Add(FootClass *obj, int &typeindex) const;
		bool Remove(FootClass *obj, int typeindex = -1);
		int Recruit(int typeindex);
		void Calc_Center(TARGET &center, TARGET &close_member) const;
		void Took_Damage(FootClass *obj, ResultType result, TechnoClass *source);
		void Coordinate_Attack();
		bool Coordinate_Regroup();
		void Coordinate_Move();
		bool Lagging_Units();
		bool Coordinate_Conscript(FootClass *unit);
		bool Is_A_Member(const FootClass *who) const;
		bool Is_Leaving_Map() const;
		bool Has_Entered_Map() const;
		void Scan_Limit();
		FootClass *Fetch_A_Leader() const;
		void TMission_Go_to_Shroud(ScriptMissionClass *mission, bool a3);
		void TMission_Move_To_Cell(ScriptMissionClass *mission, bool a3);
		void TMission_Move_To_Waypoint(ScriptMissionClass *mission, bool a3);
		void TMission_Attack_Waypoint(ScriptMissionClass *mission, bool a3);
		void TMission_Patrol(ScriptMissionClass *mission, bool a3);
		void TMission_Spy(ScriptMissionClass *mission, bool a3);
		void TMission_Scatter(ScriptMissionClass *mission, bool a3);
		void TMission_Change_House(ScriptMissionClass *mission, bool a3);
		void TMission_Change_Team(ScriptMissionClass *mission, bool a3);
		void TMission_Change_Script(ScriptMissionClass *mission, bool a3);
		void TMission_Attack(ScriptMissionClass *mission, bool a3);
		void TMission_Load(ScriptMissionClass *mission, bool a3);
		void TMission_Deploy(ScriptMissionClass *mission, bool a3);
		void TMission_Guard(ScriptMissionClass *mission, bool a3);
		void TMission_Do(ScriptMissionClass *mission, bool a3);
		void TMission_Set_Global(ScriptMissionClass *mission, bool a3);
		void TMission_Clear_Global(ScriptMissionClass *mission, bool a3);
		void TMission_Set_Local(ScriptMissionClass *mission, bool a3);
		void TMission_Clear_Local(ScriptMissionClass *mission, bool a3);
		void TMission_Follow(ScriptMissionClass *mission, bool a3);
		void TMission_Unpanic(ScriptMissionClass *mission, bool a3);
		void TMission_Force_Facing(ScriptMissionClass *mission, bool a3);
		void TMission_Panic(ScriptMissionClass *mission, bool a3);
		void TMission_Go_Berzerk(ScriptMissionClass *mission, bool a3);
		void TMission_Idle_Anim(ScriptMissionClass *mission, bool a3);
		void TMission_Loop(ScriptMissionClass *mission, bool a3);
		void TMission_Player_Wins(ScriptMissionClass *mission, bool a3);
		void TMission_Player_Loses(ScriptMissionClass *mission, bool a3);
		void TMission_Play_Speech(ScriptMissionClass *mission, bool a3);
		void TMission_Play_Sound(ScriptMissionClass *mission, bool a3);
		void TMission_Play_Movie(ScriptMissionClass *mission, bool a3);
		void TMission_Play_Music(ScriptMissionClass *mission, bool a3);
		void TMission_Reduce_Tiberium(ScriptMissionClass *mission, bool a3);
		void TMission_Begin_Production(ScriptMissionClass *mission, bool a3);
		void TMission_Fire_Sale(ScriptMissionClass *mission, bool a3);
		void TMission_Self_Destruct(ScriptMissionClass *mission, bool a3);
		void TMission_Delete_Members(ScriptMissionClass *mission, bool a3);
		void TMission_Ion_Storm_Start(ScriptMissionClass *mission, bool a3);
		void TMission_Ion_Storm_End(ScriptMissionClass *mission, bool a3);
		void TMission_Center_View_On_Team(ScriptMissionClass *mission, bool a3);
		void TMission_Reshroud_Map(ScriptMissionClass *mission, bool a3);
		void TMission_Reveal_Map(ScriptMissionClass *mission, bool a3);
		void TMission_Wait_Until_Loaded(ScriptMissionClass *mission, bool a3);
		void TMission_Truck_Unload(ScriptMissionClass *mission, bool a3);
		void TMission_Truck_Load(ScriptMissionClass *mission, bool a3);
		void TMission_Attack_Enemy_Building(ScriptMissionClass *mission, bool a3);
		void TMission_Move_To_Enemy_Building(ScriptMissionClass *mission, bool a3);
		void TMission_Scout(ScriptMissionClass *mission, bool a3);
		void TMission_Unload(ScriptMissionClass *mission, bool a3);
		void TMission_Success(ScriptMissionClass *mission, bool a3);
		void TMission_Flash(ScriptMissionClass *mission, bool a3);
		void TMission_Play_Animation(ScriptMissionClass *mission, bool a3);
		void TMission_Talk_Bubble(ScriptMissionClass *mission, bool a3);
		void Flash_For(int count);
		bool func_6277A0();
		void func_627800(DynamicVectorClass<const TechnoTypeClass *> &vec);
		bool func_627A20();

		static void func_6271F0(BuildingTypeClass *a1, HouseClass *a2, FootClass *a3, int a4, bool a5);
		static void Suspend_Teams(int priority, const HouseClass *house);

	public:
		TeamTypeClass *Class;
		ScriptClass *Script;
		HouseClass *House;
		HouseClass *field_20;
		TARGET Zone;
		TARGET ClosestMember;
		TARGET MissionTarget;
		TARGET Target;
		void *field_34;
		int Total;
		int Risk;
		int field_40;
		FootClass *Member;
		CDTimerClass<FrameTimerClass> TimeOut;
		CDTimerClass<FrameTimerClass> SuspendTimer;
		TagClass *Tag;
		bool field_64;
		bool field_65;
		bool field_66;
		bool IsForcedActive;
		bool IsHasBeen;
		bool IsFullStrength;
		bool IsUnderStrength;
		bool IsReforming;
		bool IsLagging;
		bool IsAltered;
		bool JustAltered;
		bool IsMoving;
		bool IsNextMission;
		bool IsLeaveMap;
		bool Suspended;
		bool Succeeded;
		unsigned char Quantity[MAX_TEAM_CLASSCOUNT];
};


bool Is_It_Breathing(const FootClass *object);
bool Is_It_Playing(const FootClass *object);
