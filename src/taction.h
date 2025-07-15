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

        bool operator() (HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);

        void Read_INI();
        void Build_INI_Entry(char *buffer) const;

        Coord Get_Adjusted_Waypoint();

        bool Do_DEACTIVATE_FIRESTORM(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_ACTIVATE_FIRESTORM(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_ION_LIGHTNING_STRIKE(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_REMOVE_PARTICLE_ANIM(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_PARTICLE_ANIM(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_WAKEUP_SELF(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_VEIN_GROWTH(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_TIB_GROWTH(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_ICE_GROWTH(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_WAKEUP_ALL_SLEEP(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_WAKEUP_ALL_HARMLESS(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_WAKEUP_GROUP(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_ANNOUNCE_WIN(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_ANNOUNCE_LOSE(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_FORCE_END(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_DAMAGE(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_LIGHT_SMALL(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_LIGHT_MEDIUM(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_LIGHT_LARGE(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_SELL_ATTACHED(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_GO_BERZERK(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_TURN_OFF_ATTACHED(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_TURN_ON_ATTACHED(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_CHANGE_HOUSE(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_SET_GROUP_ID(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_ALL_CHANGE_HOUSE(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_TEXT_TRIGGER(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_MAKE_ALLY(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_MAKE_ENEMY(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_PREFERRED_TARGET(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_BASE_BUILDING(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_CREEP_SHADOW(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_SET_GLOBAL(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_CLEAR_GLOBAL(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_REVEAL_SOME(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_REDUCE_TIBERIUM(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_REVEAL_ZONE(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_REVEAL_ALL(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_START_TIMER(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_STOP_TIMER(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_ADD_TIMER(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_SUB_TIMER(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_SET_TIMER(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_PLAY_MOVIE(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_PLAY_INGAME_MOVIE(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_PLAY_SOUND(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_PLAY_SOUND_RANDOM(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_PLAY_SOUND_AT(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_PLAY_MUSIC(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_PLAY_SPEECH(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_1_SPECIAL(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_FULL_SPECIAL(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_DZ(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_WIN(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_LOSE(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_BEGIN_PRODUCTION(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_FIRE_SALE(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_AUTOCREATE(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_CREATE_TEAM(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_DESTROY_TEAM(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_FLASH_TEAM(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_DISABLE_SPEECH(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_ENABLE_SPEECH(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_TALK_BUBBLE(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_REINFORCEMENTS(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_REINFORCEMENTS_SPECIAL(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_ALL_HUNT(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_DESTROY_OBJECT(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_CHANGE_ZOOM(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_RESIZE_PLAYER_VIEW(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_PLAY_ANIM(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_DO_EXPLOSION(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_METEOR_IMPACT(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_ION_STORM_START(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_ION_STORM_STOP(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_LOCK_INPUT(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_UNLOCK_INPUT(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_CENTER_VIEWPOINT(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_ZOOM_IN(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_ZOOM_OUT(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_RESHROUD(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_CHANGE_SPOTLIGHT_BEHAVIOR(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_DESTROY_TRIGGER(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_DESTROY_TAG(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_FORCE_TRIGGER(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_ENABLE_TRIGGER(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_DISABLE_TRIGGER(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_RADAR_EVENT(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_SET_LOCAL(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_CLEAR_LOCAL(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_METEOR_SHOWER(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_SET_AMBIENT_STEP(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_SET_AMBIENT_RATE(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_SET_AMBIENT_LIGHT(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_BEGIN_AI_TRIGGERS(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_STOP_AI_TRIGGERS(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_SET_AI_TRIGGER_TEAM_RATIO(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_SET_TEAM_AIRCRAFT_RATIO(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_SET_TEAM_INFANTRY_RATIO(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_SET_TEAM_UNIT_RATIO(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_ION_CANNON(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_MULTI_MISSILE(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_CHEM_MISSILE(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);
        bool Do_TOGGLE_TRAIN_CARGO(HouseClass *house, ObjectClass *object, TriggerClass *trig, const Cell &cell);

        static const char *Action_Name(TActionType action);
        static const char *Action_Description(TActionType action);

    public:
        int HeapID;
        TActionClass *Next;
        TActionType Action;
        TeamTypeClass *Team;
        Rect TriggerRect;
        WaypointType EffectLocation;
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
            AnimType Anim;
            WeaponType Weapon;
            int /*LightBehaviorType*/ LightBehavior;
            VoxelAnimType VAnim;
            RadarEventType RadarEvent;
            int /*ScrollSpeedType*/ Speed;
            int /*MeteorShowerType*/ MeteorShower;
            ParticleSystemType PAnim;
            CrateType Crate;
            bool Bool;                  // Boolean value.
            long Value;
            float Float;
        } Data;

    public:
        struct ActionDescriptionStruct
        {
            char const *Name;
            char const *Description;
        };

        static ActionDescriptionStruct ActionDescriptions[TACTION_COUNT];
};

NeedType Action_Needs(TActionType action);
AttachType Attaches_To(TActionType action);

