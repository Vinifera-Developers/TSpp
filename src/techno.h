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

#include "cargo.h"
#include "door.h"
#include "facing.h"
#include "flasher.h"
#include "ftimer.h"
#include "radio.h"
#include "search.h"
#include "stage.h"
#include "storage.h"
#include "ttimer.h"
#include "veterancy.h"
#include "voxelobj.h"


struct WeaponInfoStruct;
class BulletClass;
class WaveClass;
class ParticleSystemClass;
class InfantryTypeClass;
class BuildingTypeClass;
class WeaponTypeClass;


class TechnoClass : public RadioClass, public FlasherClass, public StageClass
{
public:
    /**
     *  IPersistStream
     */
    IFACEMETHOD(Load)(IStream* pStm);

public:
    TechnoClass(HouseClass* house);
    TechnoClass(const NoInitClass& noinit);
    virtual ~TechnoClass();

    /**
     *  AbstractClass
     */
    virtual void Init() override;
    virtual void Detach(AbstractClass* target, bool all = false) override;
    virtual void Object_CRC(CRCEngine& crc) const override;
    virtual HousesType Owner() const override;
    virtual HouseClass* Owner_HouseClass() const override;
    virtual void AI() override;

    /**
     *  ObjectClass
     */
    virtual bool Is_Players_Army() const override;
    virtual VisualType Visual_Character(bool flag = false, const HouseClass* house = nullptr);
    virtual ActionType What_Action(const Cell& cell, bool check_fog = false, bool disallow_force = false) const override;
    virtual ActionType What_Action(const ObjectClass* object, bool disallow_force = false) override;
    virtual const TechnoTypeClass* Techno_Type_Class() const override;
    virtual int Get_Ownable() const;
    virtual bool Can_Repair() const override;
    virtual bool Can_Player_Fire() const override;
    virtual bool Can_Player_Move() const override;
    virtual Coord Fire_Coord(WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const override;
    virtual bool Limbo() override;
    virtual bool Unlimbo(const Coord& coord, Dir256 dir = DIR_N) override;
    virtual void Record_The_Kill(const ObjectClass* source) override;
    virtual void Do_Shimmer() override;
    virtual ExitType Exit_Object(const TechnoClass* object);
    virtual void entry_F8(Point2D& point, Rect& bounds) const;
    virtual void entry_FC(Point2D& point, Rect& bounds) const;
    virtual void Hidden() override;
    virtual void Look(bool incremental = false, bool a2 = false) override;
    virtual bool Mark(MarkType mark = MARK_CHANGE) override;
    virtual void Clicked_As_Target(int flashes) override;
    virtual bool Select() override;
    virtual bool In_Range(Coord& coord, WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const override;
    virtual int Weapon_Range(WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const override;
    virtual ResultType Take_Damage(int& damage, int distance, const WarheadTypeClass* warhead, const ObjectClass* source, bool a5 = false, bool a6 = false) override;
    virtual int Value() const override;
    virtual void Per_Cell_Process(PCPType why) override;
    virtual RadioMessageType Receive_Message(RadioClass* from, RadioMessageType message, long& param) override;
    virtual bool Revealed(const HouseClass* house = nullptr) override;

    /**
     *  MissionClass
     */
    virtual void Override_Mission(MissionType mission, AbstractClass* tarcom = nullptr, AbstractClass* navcom = nullptr) override;
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
    virtual DirType Turret_Facing() const;
    virtual bool Is_Weapon_Equipped() const;
    virtual bool Is_On_Elevation() const;
    virtual double Tiberium_Load() const;
    virtual double Weed_Load() const;
    virtual int Pip_Count() const;
    virtual int Refund_Amount() const;
    virtual int Risk() const;
    virtual bool Is_In_Same_Zone_As(const ObjectClass* object) const;
    virtual DirType entry_268(const ObjectClass* object) const;
    virtual bool Is_In_Same_Zone(const Coord& cell) const;
    virtual int How_Many_Survivors() const;
    virtual void entry_274() const;
    virtual int entry_278() const;
    virtual int Get_Z_Adjustment() const;
    virtual ZGradientType Get_Z_Gradient() const;
    virtual BuildingClass* const Find_Docking_Bay(const BuildingTypeClass* buildingtype, bool friendly = false, bool evenoccupied = false) const;
    virtual Cell Find_Exit_Cell(const TechnoClass* object) const;
    virtual Coord entry_28C(WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const;
    virtual FacingType Desired_Load_Dir(const ObjectClass* object, Cell& cell) const;
    virtual DirType Fire_Direction() const;
    virtual InfantryTypeClass* const Crew_Type() const;
    virtual bool entry_29C() const;
    virtual bool Can_Deploy_Now() const;
    virtual bool Is_Immobilized() const;
    virtual int Get_Max_Speed() const;
    virtual int Rearm_Delay(WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const;
    virtual int Threat_Range(int control) const;
    virtual bool Is_Allowed_To_Leave_Map() const;
    virtual bool entry_2B8(int* a1) const;
    virtual bool entry_2BC() const;
    virtual bool entry_2C0(const HouseClass* house) const;
    virtual bool Is_Renovator() const;
    virtual void entry_2C8() const;
    virtual void Response_Select() const;
    virtual void Response_Move() const;
    virtual void Response_Attack() const;
    virtual void Player_Assign_Mission(MissionType order, AbstractClass* target = nullptr, AbstractClass* destination = nullptr);
    virtual void Reduce_Ammunition();
    virtual bool Target_Something_Nearby(Coord& coord, ThreatType threat);
    virtual void Stun();
    virtual bool In_Range_Of(AbstractClass* target, WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const;
    virtual void Death_Announcement(const TechnoClass* object = nullptr) const = 0;
    virtual FireErrorType Can_Fire(AbstractClass* target, WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const;
    virtual AbstractClass* Greatest_Threat(ThreatType method, const Coord& coord, bool a3 = false) const;
    virtual void Assign_Target(AbstractClass* target) const;
    virtual const BulletClass* Fire_At(AbstractClass* target, WeaponSlotType weapon = WEAPON_SLOT_PRIMARY);
    virtual bool Captured(HouseClass* house = nullptr);
    virtual void Laser_Zap(AbstractClass* target, int which, const WeaponTypeClass* weapontype, Coord& a4);
    virtual void Rock(const Coord& coord, float a2);
    virtual WeaponInfoStruct* const Get_Weapon(WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const;
    virtual bool Is_Turret_Equipped() const;
    virtual void Renovate() const;
    virtual void Cloaking_AI(bool a1 = false) const;
    virtual void entry_31C() const;
    virtual void entry_320() const;
    virtual void entry_324() const;
    virtual void Draw_Voxel(VoxelObject& voxeldata, unsigned int frame, int key, VoxelIndexClass& index, Rect& rect, Point2D& point, Matrix3D& matrix, int color, int flags) const;
    virtual void entry_32C(Point2D& point, Rect& rect) const;
    virtual void entry_330(Point2D& point, Rect& rect, bool a2) const;
    virtual void Draw_Pips(const Point2D& point1, const Point2D& point2, const Rect& rect) const;
    virtual void Draw_Text_Overlay(const Point2D& point1, const Point2D& point2, const Rect& rect) const;
    virtual void Do_Uncloak(bool silent = false);
    virtual void Do_Cloak(bool silent = false);
    virtual int entry_344(int a1) const;
    virtual bool Is_Ready_To_Random_Animate() const;
    virtual bool Random_Animate();
    virtual void Assign_Destination(const AbstractClass* target, bool a2 = true);
    virtual bool Enter_Idle_Mode(bool inital = false, bool a2 = false);
    virtual void entry_358();
    virtual void entry_35C();
    virtual void entry_360() const;
    virtual void entry_364(bool a1 = false);

    WeaponSlotType What_Weapon_Should_I_Use(AbstractClass* target) const;
    int Combat_Damage(int which = -1) const;
    int Time_To_Build() const;
    // 0062BEA0
    // 0062BFE0
    // 0062CD00
    double Area_Modify(Cell const& cell) const;
    bool Evaluate_Object(ThreatType method, int mask, int range, const TechnoClass* object, int& value, int zone, Coord& coord) const;
    bool Evaluate_Cell(ThreatType method, int mask, Cell& cell, int range, const TechnoClass** object, int& value, int zone) const;
    int Evaluate_Just_Cell(Cell& cell) const;
    // 006313D0
    // 00632730
    Cell Nearby_Location(const TechnoClass* techno = nullptr) const;
    bool Is_Z_Fudge_Bridge() const;
    // 00634110
    bool Is_Z_Fudge_Column() const;
    bool Is_Z_Fudge_Tunnel() const;
    bool Is_Z_Fudge_Cliff() const;
    // 00635860
    // 00635B00
    // 00635E20
    // 00635FA0
    // 00636280
    void Kill_Cargo(TechnoClass* source);
    void Base_Is_Attacked(const TechnoClass* enemy);
    bool Is_Allowed_To_Retaliate(const TechnoClass* source, const WarheadTypeClass* weapon) const;
    int Anti_Air() const;
    int Anti_Armor() const;
    int Anti_Infantry() const;
    Coord func_638AF0() const;
    // 00638C70
    void Assign_Archive_Target(AbstractClass* target);
    // 006391B0
    float Target_Threat(TechnoClass* target, Coord const& firing_coord) const;
    bool Has_Ability(AbilityType ability) const;
    // 00639C60
    static void Update_Mission_Targets(AbstractClass* target);
    // 00639F80
    // 0063A0C0
    // 0063A100
    // 0063A1D0
    // 0063A530

    inline WeaponTypeClass* Get_Primary_Weapon(void) const
    {
        const WeaponInfoStruct* wdata = Get_Weapon(WEAPON_SLOT_PRIMARY);
        return const_cast<WeaponTypeClass*>(wdata->Weapon);
    }
    inline WeaponTypeClass* Get_Secondary_Weapon(void) const
    {
        const WeaponInfoStruct* wdata = Get_Weapon(WEAPON_SLOT_SECONDARY);
        return const_cast<WeaponTypeClass*>(wdata->Weapon);
    }
    __declspec(property(get = Get_Primary_Weapon)) WeaponTypeClass* PrimaryWeapon;
    __declspec(property(get = Get_Secondary_Weapon)) WeaponTypeClass* SecondaryWeapon;

    void Techno_Draw_Object(const ShapeSet* shapefile, int shapenum, const Point2D& xy, const Rect& rect, Dir256 rotation = DIR_N, int scale = 256, int a7 = 0, int a8 = 0, bool a9 = false, int a10 = 0, const ShapeSet* z_shape = nullptr, int z_framenum = 0, Point2D z_off = Point2D(0, 0),
                            ShapeFlags_Type flags = SHAPE_NORMAL) const;

    static void Reset_Action_Line_Timer();
    static void Set_Action_Lines(bool set);

public:
    HousesType ActLike;
    CargoClass Cargo;
    VeterancyClass Crew;
    double ArmorBias;
    double FirepowerBias;
    CDTimerClass<FrameTimerClass> IdleTimer;
    CDTimerClass<FrameTimerClass> RadarFlashTimer;
    Point2D RadarPos;
    unsigned SpiedBy;
    unsigned int Group;
    AbstractClass* ArchiveTarget;
    HouseClass* House;
    CloakType Cloak;
    StageClass CloakingDevice;
    CDTimerClass<FrameTimerClass> CloakDelay;
    float field_118;
    AbstractClass* TarCom;
    AbstractClass* SuspendedTarCom;
    float PitchAngle;
    CDTimerClass<FrameTimerClass> Arm;
    int Ammo;
    int PurchasePrice;
    ParticleSystemClass* ParticleSystems[ATTACHED_PARTICLE_COUNT];
    WaveClass* Wave;
    float AngleRotatedSideways;
    float AngleRotatedForwards;
    float RockingSidewaysPerFrame;
    float RockingForwardsPerFrame;
    InfantryType EnteredByInfType;
    StorageClass Storage;
    DoorClass Door;
    FacingClass BarrelFacing;
    FacingClass PrimaryFacing;
    FacingClass SecondaryFacing;
    int BurstIndex;
    CDTimerClass<FrameTimerClass> TargetingLaserTimer;
    unsigned short SoundRandomSeed;
    short SinkingYOffset;
    bool IsSinking;
    bool IsNeedingRescue;
    bool IsUseless;
    bool IsTickedOff;
    bool IsCloakable;
    bool IsLeader;
    bool IsALoaner;
    bool IsLocked;
    bool IsInRecoilState;
    bool IsTethered;
    bool IsOwnedByPlayer;
    bool IsDiscoveredByPlayer;
    bool IsDiscoveredByComputer;
    bool IsALemon;
    unsigned char field_202;
    unsigned char field_203;
    unsigned char field_204;
    bool field_205;    // recruitable?
    bool field_206;    // ai recruitable?
    bool field_207;    // is tracked in radar?
    bool IsOnCarryall; // is being toted?
    bool field_209;
    bool field_20A; // is patroling?
    bool field_20B;
    AbstractClass* field_20C; // closet object to me?
    int EMPFramesRemaining;
    unsigned field_214;
    float LimpetSpeedFactor;
};
