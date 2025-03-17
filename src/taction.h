/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TACTION.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Map trigger actions.
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
#include "tibsun_defines.h"


class ObjectClass;
class TriggerClass;
class HouseClass;
class TagTypeClass;
class TriggerTypeClass;
class TeamTypeClass;


class DECLSPEC_UUID("4F0EC392-0A55-11D2-ACA7-006008055BB5")
TActionClass : public AbstractClass
{
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
        TActionClass();
        TActionClass(const NoInitClass &noinit);
        ~TActionClass();

        /**
         *  AbstractClass
         */
        virtual void Detach(AbstractClass * target, bool all = false) override;
        virtual RTTIType Fetch_RTTI() const override;
        virtual int Get_Object_Size(bool firestorm = false) const override;
        virtual void Object_CRC(CRCEngine &crc) const override;
        virtual int Fetch_Heap_ID() const override;

        bool operator() (HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);

        void Read_INI();
        void Build_INI_Entry(char *buffer) const;

        Coordinate Waypoint_As_Coord();

        bool TAction_Deactivate_Firestorm_Defense(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Activate_Firestorm_Defense(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Lightning_Strike_At(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Remove_Particle_Anim_At(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Particle_Anim_At(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Wakeup_Self(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Vein_Growth(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Tiberium_Growth(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Ice_Growth(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Wakeup_Sleepers(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Wakeup_Harmless(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Wakeup_Group(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Annouce_Win(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Annouce_Lose(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Force_End(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Apply_100_Damage(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Small_Light_Flash_At(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Medium_Light_Flash_At(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Large_Light_Flash_At(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Sell_Building(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Go_Bezerk(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Turn_Off_Building(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Turn_On_Building(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Change_House(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Set_Group_ID(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_All_Change_House(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Text_Trigger(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Make_Ally(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Make_Enemy(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Preferred_Target(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Base_Building(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Creep_Shadow(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Global_Set(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Global_Clear(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Reveal_Area(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Reduce_Tiberium_At(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Reveal_Zone(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Reveal_Map(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Start_Timer(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Stop_Timer(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Add_Timer(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Sub_Timer(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Set_Timer(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Play_Movie(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Play_Ingame_Movie(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Play_Sound(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Play_Sound_At_Random_Waypoint(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Play_Sound_At(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Play_Music(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Play_Speech(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_One_Time_Special(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Full_Special(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Drop_Zone_Flare(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Win(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Lose(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Begin_Production(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Fire_Sale(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Begin_Autocreate(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Create_Team(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Destroy_Team(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Flash_Team(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Disable_Speech(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Enable_Speech(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Talk_Bubble(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Reinforcements(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Reinforcement_At(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_All_Hunt(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Destroy_Object(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Change_Zoom_Level(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Resize_Player_View(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Play_Anim_At(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Do_Explosion_At(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Meteor_Impact_At(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Ion_Storm_Start(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Ion_Storm_End(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Lock_Input(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Unlock_Input(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Center_Camera_At(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Zoom_In(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Zoom_Out(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Reshroud_Map(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Change_Spotlight_Behavior(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Destroy_Trigger(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Destroy_Tag(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Force_Trigger(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Enable_Trigger(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Disable_Trigger(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Create_Radar_Event(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Local_Set(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Local_Clear(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Meteor_Shower_At(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Set_Ambient_Step(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Set_Ambient_Rate(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Set_Ambient_Light(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Set_AI_Triggers_Begin(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Set_AI_Triggers_End(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Set_Ratio_Of_AI_Trigger_Teams(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Set_Ratio_Of_Team_Aircraft(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Set_Ratio_Of_Team_Infantry(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Set_Ratio_Of_Team_Units(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Ion_Cannon_Strike(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Nuke_Strike(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Chemical_Missile_Strike(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);
        bool TAction_Toggle_Train_Cargo(HouseClass *house, ObjectClass *object, TriggerClass *trigger, Cell &cell);

        static NeedType Needs(TActionType action);
        static AttachType Attaches_To(TActionType action);

        static const char *Action_Name(TActionType action);
        static const char *Action_Description(TActionType action);

    public:
        int ID;
        TActionClass *Next;
        TActionType Action;
        TeamTypeClass *Team;
        Rect Bounds;
        int Location;
        TagTypeClass *Tag;
        TriggerTypeClass *Trigger;

        union {
            ThemeType Theme;            // Musical theme.
            VocType Sound;              // Sound effect.
            VoxType Speech;             // Speech identifier.
            HousesType House;           // House to be affected.
            SuperWeaponType Special;  // Special weapon ability.
            QuarryType Quarry;          // Preferred target for attack.
            VQType Movie;               // The movie to play.
            bool Bool;                  // Boolean value.
            long Value;
        } Data;

    public:
        struct ActionDescriptionStruct
        {
            char const *Name;
            char const *Description;
        };

        static ActionDescriptionStruct ActionDescriptions[TACTION_COUNT];
};
