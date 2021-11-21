/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TECHNO.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Buildable game object class.
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

#include "radio.h"
#include "flasher.h"
#include "stage.h"
#include "cargo.h"
#include "door.h"
#include "veterancy.h"
#include "storage.h"
#include "facing.h"
#include "ttimer.h"
#include "ftimer.h"
#include "search.h"


struct WeaponInfoStruct;
class BulletClass;
class WaveClass;
class ParticleSystemClass;
class InfantryTypeClass;
class BuildingTypeClass;
class WeaponTypeClass;


/*******************************************************************************
 *	This is the common data between building and units.
 */
class TechnoClass : public RadioClass, public FlasherClass, public StageClass
{
    public:
        /**
         *  IPersistStream
         */
        IFACEMETHOD(Load)(IStream *pStm);

    public:
        TechnoClass(HouseClass *house);
        TechnoClass(const NoInitClass &noinit);
        virtual ~TechnoClass();

        /**
         *  AbstractClass
         */
        virtual void Init() override;
        virtual void Detach(TARGET target, bool all = false) override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;
        virtual int Owner() const override;
        virtual HouseClass *Owning_House() const override;
        virtual void AI() override;

        /**
         *  ObjectClass
         */
        virtual bool Is_Players_Army() const override;
        virtual VisualType Visual_Character(bool flag = false, const HouseClass *house = nullptr);
        virtual ActionType What_Action(Cell &cell, bool check_fog = false, bool disallow_force = false) const override;
        virtual ActionType What_Action(const ObjectClass *object, bool disallow_force = false) override;
        virtual TechnoTypeClass *const Techno_Type_Class() const override;
        virtual int Get_Ownable() const;
        virtual bool Can_Repair() const override;
        virtual bool Can_Player_Fire() const override;
        virtual bool Can_Player_Move() const override;
        virtual Coordinate Fire_Coord(WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const override;
        virtual bool Limbo() override;
        virtual bool Unlimbo(Coordinate &coord, DirType dir = DIR_N) override;
        virtual void Record_The_Kill(const ObjectClass *source) override;
        virtual void Do_Shimmer() override;
        virtual ExitType Exit_Object(const TechnoClass *object);
        virtual void entry_F8(Point2D &point, Rect &bounds) const;
        virtual void entry_FC(Point2D &point, Rect &bounds) const;
        virtual void Hidden() override;
        virtual void Look(bool incremental = false, bool a2 = false) override;
        virtual bool Mark(MarkType mark = MARK_CHANGE) override;
        virtual void Clicked_As_Target(int flashes) override;
        virtual bool Select() override;
        virtual bool In_Range(Coordinate &coord, WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const override;
        virtual int Weapon_Range(WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const override;
        virtual ResultType Take_Damage(int &damage, int distance, const WarheadTypeClass *warhead, const ObjectClass *source, bool a5 = false, bool a6 = false) override;
        virtual int Value() const override;
        virtual void Per_Cell_Process(PCPType why) override;
        virtual RadioMessageType Receive_Message(RadioClass *from, RadioMessageType message, long &param) override;
        virtual bool Revealed(const HouseClass *house = nullptr) override;

        /**
         *  MissionClass
         */
        virtual void Override_Mission(MissionType mission, TARGET tarcom = nullptr, TARGET navcom = nullptr) override;
        virtual bool Restore_Mission() override;

        /**
         *  TechnoClass
         */
        virtual bool entry_220() const;
        virtual bool Is_Allowed_To_Recloak() const;
        virtual bool entry_228() const;
        virtual bool entry_22C() const;
        virtual bool entry_230() const;
        virtual bool entry_234() const;
        virtual bool entry_238() const;
        virtual bool entry_23C() const;
        virtual bool entry_240() const;
        virtual DirStruct Turret_Facing() const;
        virtual bool Is_Weapon_Equipped() const;
        virtual bool entry_24C() const;
        virtual double Tiberium_Load() const;
        virtual double Weed_Load() const;
        virtual int Pip_Count() const;
        virtual int Refund_Amount() const;
        virtual int Risk() const;
        virtual bool Is_In_Same_Zone_As(const ObjectClass *object) const;
        virtual DirStruct entry_268(const ObjectClass *object) const;
        virtual bool Is_In_Same_Zone(const Coordinate &cell) const;
        virtual int How_Many_Survivors() const;
        virtual void entry_274() const;
        virtual int entry_278() const;
        virtual int Get_Z_Adjustment() const;
        virtual ZGradientType Get_Z_Gradient() const;
        virtual BuildingClass *const Find_Docking_Bay(const BuildingTypeClass *buildingtype, bool a2 = false, bool a3 = false) const;
        virtual Cell Find_Exit_Cell(const TechnoClass *object) const;
        virtual Coordinate entry_28C(WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const;
        virtual FacingType Desired_Load_Dir(const ObjectClass *object, Cell &cell) const;
        virtual DirStruct Fire_Direction() const;
        virtual InfantryTypeClass *const Crew_Type() const;
        virtual bool entry_29C() const;
        virtual bool entry_2A0() const;
        virtual bool entry_2A4() const;
        virtual int Get_Max_Speed() const;
        virtual int Rearm_Delay(WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const;
        virtual int Threat_Range(int control) const;
        virtual bool Is_Allowed_To_Leave_Map() const;
        virtual bool entry_2B8(int *a1) const;
        virtual bool entry_2BC() const;
        virtual bool entry_2C0(const HouseClass *house) const;
        virtual bool Is_Renovator() const;
        virtual void entry_2C8() const;
        virtual void Response_Select() const;
        virtual void Response_Move() const;
        virtual void Response_Attack() const;
        virtual void Player_Assign_Mission(MissionType order, TARGET target = nullptr, TARGET destination = nullptr);
        virtual void Reduce_Ammunition() const;
        virtual bool Target_Something_Nearby(Coordinate &coord, ThreatType threat);
        virtual void Stun();
        virtual bool In_Range_Of(const ObjectClass *object, WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const;
        virtual void Death_Announcement(const TechnoClass *object = nullptr) const = 0;
        virtual FireErrorType Can_Fire(const TechnoClass *object, WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const;
        virtual int Greatest_Threat(ThreatType method, Coordinate &coord, bool a3 = false) const;
        virtual void Assign_Target(TARGET target) const;
        virtual const BulletClass *Fire_At(TARGET target, WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const;
        virtual bool Captured(HouseClass *house = nullptr);
        virtual void Laser_Zap(TARGET target, int which, const WeaponTypeClass *weapontype, Coordinate &a4);
        virtual void entry_308(Coordinate &coord, float a2);
        virtual WeaponInfoStruct *const Get_Weapon(WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const;
        virtual bool Is_Turret_Equipped() const;
        virtual void Renovate() const;
        virtual void Cloaking_AI(bool a1 = false) const;
        virtual void entry_31C() const;
        virtual void entry_320() const;
        virtual void entry_324() const;
        virtual void entry_328(int a1, int a2, int a3, IndexClass<int, int> *a4, Rect *a5, int a6, int a7, int a8, int a9) const;
        virtual void entry_32C(Point2D &point, Rect &rect) const;
        virtual void entry_330(Point2D &point, Rect &rect, bool a2) const;
        virtual void Draw_Pips(Point2D &point1, Point2D &point2, Rect &rect) const;
        virtual void entry_338(Point2D &point1, Point2D &point2, Rect &rect) const;
        virtual void Do_Uncloak(bool play_sfx = true);
        virtual void Do_Cloak(bool play_sfx = true);
        virtual int entry_344(int a1) const;
        virtual bool Is_Ready_To_Random_Animate() const;
        virtual bool Random_Animate();
        virtual void Assign_Destination(const TARGET target, bool a2 = true) const;
        virtual bool Enter_Idle_Mode(bool inital = false, bool a2 = false) const;
        virtual void entry_358();
        virtual void entry_35C();
        virtual void entry_360() const;
        virtual void entry_364(bool a1 = false);

        WeaponSlotType What_Weapon_Should_I_Use(TARGET target) const;
        int Combat_Damage(int which = -1) const;
        int Time_To_Build() const;
        // 0062BEA0
        // 0062BFE0
        // 0062CD00
        double Area_Modify(Cell &cell) const;
        bool Evaluate_Object(ThreatType method, int mask, int range, const TechnoClass *object, int &value, int zone, Coordinate &coord) const;
        bool Evaluate_Cell(ThreatType method, int mask, Cell &cell, int range, const TechnoClass **object, int &value, int zone) const;
        int Evaluate_Just_Cell(Cell &cell) const;
        // 006313D0
        // 00632730
        Cell Nearby_Location(const TechnoClass *techno = nullptr) const;
        // 00633F60
        // 00634110
        // 006342C0
        // 00634450
        // 00634690
        // 00635860
        // 00635B00
        // 00635E20
        // 00635FA0
        // 00636280
        void Kill_Cargo(TechnoClass *source);
        void Base_Is_Attacked(const TechnoClass *enemy);
        bool Is_Allowed_To_Retaliate(const TechnoClass *source, const WarheadTypeClass *weapon) const;
        int Anti_Air() const;
        int Anti_Armor() const;
        int Anti_Infantry() const;
        // 00638AF0
        // 00638C70
        // 00639130
        // 006391B0
        // 00639810
        // 00639BB0
        // 00639C60
        // 00639EF0
        // 00639F80
        // 0063A0C0
        // 0063A100
        // 0063A1D0
        // 0063A530

		void Techno_Draw_Object(const ShapeFileStruct *shapefile,
            int shapenum,
            Point2D &xy,
            Rect &rect,
            DirType rotation = DIR_N,
            int scale = 256,
            int a7 = 0,
            int a8 = 0,
            bool a9 = false,
            int a10 = 0,
	        ShapeFileStruct *z_shape = nullptr,
	        int z_framenum = 0,
	        int z_xoff = 0,
	        int z_yoff = 0,
            ShapeFlagsType flags = SHAPE_NORMAL) const;

        static void Reset_Action_Line_Timer();
        static void Set_Action_Lines(bool set);

    public:
        SideType ActLike;
        CargoClass Cargo;
        VeterancyClass Veterancy;

        /**
         *  This is the firepower and armor modifiers for this techno object. Normally,
         *  these values are fixed at 0x0100, but they can be modified by certain
         *  crate powerups.
         */
        double ArmorBias;
        double FirepowerBias;

        /**
         *  Idle animations (if any are supported by the object type) are
         *  regulated by this timer. When the timer expires an idle animation
         *  occurs. Then the timer is reinitialized to some random (bounded) setting.
         */
        CDTimerClass<FrameTimerClass> IdleTimer;

        CDTimerClass<FrameTimerClass> RadarFlashTimer;
        Point2D RadarPos;

        /**
         *  This is a list of bits of which houses are spying on this building,
         *  if in fact this is a building.
         */
		unsigned SpiedBy;

        /**
         *  If this object is part of a pseudo-team that the player is managing,
         *  then this will be set to the team number (0 - 9). If it is not part
         *  of any pseudo-team, then the number will be -1.
         */
        unsigned int Group;

        /**
         *  For units in area guard mode, this is the recorded home position.
         *  The guarding unit will try to stay near this location in the course
         *  of it's maneuvers. This is also used to record a pending transport
         *  for those passengers that are waiting for the transport to become
         *  available. It is also used by harvesters so that they know where to
         *  head back to after unloading.
         */
        TARGET ArchiveTarget;

        /**
         *  This is the house that the unit belongs to.
         */
        HouseClass *House;

        /**
         *  This records the current cloak state for this vehicle.
         */
		CloakType Cloak;
		StageClass CloakingDevice;
		CDTimerClass<FrameTimerClass> CloakDelay;

        float field_118;

        /**
         *  (Targeting Computer)
         *  This is the target value for the item that this vehicle should ATTACK.
         *  If this is a vehicle with a turret, then it may differ from its
         *  movement destination.
         */
        TARGET TarCom;
        TARGET SuspendedTarCom;

        float PitchAngle;

        /**
         *  This is the arming countdown. It represents the time necessary
         *  to reload the weapon.
         */
		CDTimerClass<FrameTimerClass> Arm;

        /**
         *  The number of shot this object can fire before running out of ammo.
         *  If this value is zero, then firing is not allowed. If -1, then there
         *  is no ammunition limit.
         */
		int Ammo;

        /**
         *  This is the amount of money spent to produce this object. This value
         *  really only comes into play for the case of buildings that have
         *  special "free" objects available when purchased at the more expensive rate.
         */
        int PurchasePrice;

        ParticleSystemClass *ParticleSystems[5];
        WaveClass *Wave;
        float AngleRotatedSideways;
        float AngleRotatedForwards;
        float RockingSidewaysPerFrame;
        float RockingForwardsPerFrame;
        InfantryType EnteredByInfType;
        StorageClass Storage;
        DoorClass Door;
        FacingClass BarrelFacing;

        /**
         *  This is the visible facing for the unit or building.
         */
		FacingClass PrimaryFacing;

        /**
         *  This is the facing of the turret. It can be, and usually is,
         *  rotated independently of the body it is attached to.
         */
        FacingClass SecondaryFacing;

        int CurrentBurstIndex;
        CDTimerClass<FrameTimerClass> TargetingLaserTimer;
        unsigned short SoundRandomSeed;
        short SinkingYOffset;
        bool IsSinking;
        bool IsNeedingRescue;

        /**
         *  If this techno object has detected that it has outlived its purpose,
         *  then this flag will be true. Such object will either be sold or
         *  sacrificed at the first opportunity.
         */
		bool IsUseless;

        /**
         *  This flag will be true if the object has been damaged with malice.
         *  Damage received due to friendly fire or wear and tear does not count.
         *  The computer is not allowed to sell a building unless it has been
         *  damaged with malice.
         */
        bool IsTickedOff;

        /**
         *  If this object has inherited the ability to cloak, then this bit will
         *  be set to true.
         */
        bool IsCloakable;

        /**
         *  If this object is designated as special then this flag will be true. For
         *  buildings, this means that it is the primary factory. For units, it means
         *  that the unit is the team leader.
         */
        bool IsLeader;

        /**
         *  Certain units are flagged as "loaners".  These units are typically
         *  transports that are created solely for the purpose of delivering
         *  reinforcements.  Such "loaner" units are not owned by the player
         *  and thus cannot be directly controlled.  These units will leave the
         *  game as soon as they have fulfilled their purpose.
         */
        bool IsALoaner;

        /**
         *  Once a unit enters the map, then this flag is set. This flag is used
         *  to make sure that a unit doesn't leave the map once it enters the map.
         */
        bool IsLocked;

        /**
         *  Buildings and units with turrets usually have a recoil animation when
         *  they fire. If this flag is true, then the next rendering of the object
         *  will be in the "recoil state". The flag will then be cleared pending
         *  the next firing event.
         */
        bool IsInRecoilState;

        /**
         *  If this unit is "loosely attached" to another unit it is given special
         *  processing. A unit is in such a condition when it is in the process of
         *  unloading from a transport type object. During the unloading process
         *  the transport object must stay still until the unit is free and clear.
         *  At that time it radios the transport object and the "tether" is broken -
         *  freeing both the unit and the transport object.
         */
        bool IsTethered;

        /**
         *  Is this object owned by the player?  If not, then it is owned by the
         *  computer or remote opponent. This flag facilitates the many logic
         *  differences when dealing with player's or computer's units or buildings.
         */
        bool IsOwnedByPlayer;

        /**
         *  The more sophisticated game objects must keep track of whether they
         *  are discovered or not. This is because the state of discovery can
         *  often control how the object behaves. In addition, this fact is used
         *  in radar and user I/O processing.
         */
        bool IsDiscoveredByPlayer;

        /**
         *  This is used to control the computer recognizing this object.
         */
        bool IsDiscoveredByComputer;

        /**
         *  Some game objects can be of the "lemon" variety. This means that they
         *  take damage even when everything is ok. This adds a little variety to
         *  the game.
         */
        bool IsALemon;

        unsigned char field_202;
        unsigned char field_203;
        unsigned char field_204;
        bool field_205; // recruitable?
        bool field_206; // ai recruitable?
        bool field_207; // is tracked in radar?
        bool IsOnCarryall; // is being toted?
        bool field_209;
        bool field_20A; // is patroling?
        bool field_20B;
        TARGET field_20C; // closet object to me?
        int EMPFramesRemaining;
        unsigned field_214;
        float LimpetSpeedFactor;
};
