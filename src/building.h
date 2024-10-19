/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          BUILDING.H
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

#include "techno.h"
#include "ttimer.h"
#include "ftimer.h"
#include "buildingtype.h"
#include "tibsun_defines.h"


#define BUILDING_UPGRADE_MAX 3


class BuildingLightClass;
class LightSourceClass;
class FactoryClass;
class AnimClass;


class DECLSPEC_UUID("0E272DC6-9C0F-11D1-B709-00A024DDAFD1")
BuildingClass : public TechnoClass
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
        BuildingClass(BuildingTypeClass *classof = nullptr, HouseClass *house = nullptr);
        BuildingClass(NoInitClass &noinit);
        virtual ~BuildingClass();

        /**
         *  AbstractClass
         */
        virtual void Init() override;
        virtual void Detach(TARGET target, bool all = false) override;
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;
        virtual Coordinate Center_Coord() const override;
        virtual Coordinate entry_50() const override;
        virtual void AI() override;

        /**
         *  ObjectClass
         */
        virtual VisualType Visual_Character(bool raw = false, const HouseClass *house = nullptr) override;
        virtual ShapeFileStruct *const Get_Image_Data() const override;
        virtual ActionType What_Action(const ObjectClass *object, bool disallow_force = false) override;
        virtual ActionType What_Action(Cell &cell, bool check_fog = false, bool disallow_force = false) const override;
        virtual bool entry_80() const override;
        virtual ObjectTypeClass *const Class_Of() const override;
        virtual const char *Full_Name() const override;
        virtual bool Can_Repair() const override;
        virtual bool Can_Demolish() const override;
        virtual bool Can_Player_Move() const override;
        virtual Coordinate Target_Coord() const override;
        virtual Coordinate Docking_Coord() const override;
        virtual Coordinate Render_Coord() const override;
        virtual Coordinate Fire_Coord(WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const override;
        virtual Coordinate Exit_Coord() const override;
        virtual int Sort_Y() const override;
        virtual bool Limbo() override;
        virtual bool Unlimbo(Coordinate &coord, DirType dir = DIR_N) override;
        virtual void Detach_All(bool all = false) override;
        virtual void Set_Occupy_Bit(Coordinate &coord) override;
        virtual void Clear_Occupy_Bit(Coordinate &coord) override;
        virtual ExitType Exit_Object(const TechnoClass *object) override;
        virtual bool Render(Rect &rect, bool force = false, bool a3 = false) override;
        virtual void Draw_It(Point2D &point, Rect &bounds) const override;
        virtual void Placement_Draw_It(Point2D &point, Rect &bounds) const override;
        virtual bool Mark(MarkType mark = MARK_CHANGE) override;
        virtual Rect entry_118() const override;
        virtual void Draw_Radial_Indicator() const override;
        virtual bool Active_Click_With(ActionType action, ObjectClass *target, bool a3 = false) override;
        virtual bool Active_Click_With(ActionType action, Cell &cell, bool a3 = false) override;
        virtual void Clicked_As_Target(int frames) override;
        virtual ResultType Take_Damage(int &damage, int distance, const WarheadTypeClass *warhead, const ObjectClass *source, bool forced = false, bool a6 = false) override;
        virtual RadioMessageType Receive_Message(RadioClass *from, RadioMessageType message, long &param) override;
        virtual bool Revealed(const HouseClass *house = nullptr) override;
        virtual void Repair(int control) override;
        virtual void Sell_Back(int control) override;
        virtual MoveType Can_Enter_Cell(const CellClass *cell, FacingType facing = FACING_NONE, int cell_level = -1, const CellClass *a4 = nullptr, bool a5 = true) override;

        /**
         *  MissionClass
         */
        virtual bool Ready_To_Commence() const override;
        virtual int Mission_Attack() override;
        virtual int Mission_Guard() override;
        virtual int Mission_Guard_Area() override;
        virtual int Mission_Harvest() override;
        virtual int Mission_Unload() override;
        virtual int Mission_Construction() override;
        virtual int Mission_Deconstruction() override;
        virtual int Mission_Repair() override;
        virtual int Mission_Missile() override;
        virtual int Mission_Open() override;

        /**
         *  TechnoClass
         */
        virtual bool entry_220() const override;
        virtual bool entry_23C() const override;
        virtual bool entry_240() const override;
        virtual DirStruct Turret_Facing() const override;
        virtual int Pip_Count() const override;
        virtual DirStruct entry_268(const ObjectClass *object) const override;
        virtual int How_Many_Survivors() const override;
        virtual void entry_274() const override;
        virtual int entry_278() const override;
        virtual int Get_Z_Adjustment() const override;
        virtual Cell Find_Exit_Cell(const TechnoClass *object) const override;
        virtual Coordinate entry_28C(WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const override;
        virtual DirStruct Fire_Direction() const override;
        virtual InfantryTypeClass *const Crew_Type() const override;
        virtual bool entry_2B8(int *a1) const override;
        virtual void Death_Announcement(const TechnoClass *object = nullptr) const override;
        virtual FireErrorType Can_Fire(TARGET target, WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const override;
        virtual TARGET Greatest_Threat(ThreatType method, Coordinate &coord, bool a3 = false) const override;
        virtual void Assign_Target(TARGET target) const;
        virtual bool Captured(HouseClass *house = nullptr) override;
        virtual WeaponInfoStruct *const Get_Weapon(WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const override;
        virtual bool Is_Turret_Equipped() const override;
        virtual void Cloaking_AI(bool a1 = false) const override;
        virtual int entry_344(int a1) const override;
        virtual void Assign_Destination(const TARGET target, bool a2 = true) override;
        virtual bool Enter_Idle_Mode(bool inital = false, bool a2 = false);
        virtual void entry_358() override;
        virtual void entry_35C() override;
        virtual void entry_360() const override;

        /**
         *  BuildingClass
         */
        virtual void Grand_Opening(bool captured = false);
        virtual void Update_Buildables();
        virtual void entry_370(Point2D &point, Rect &rect);
        virtual DirStruct entry_374(TARGET target);
        virtual void entry_378(TechnoClass *a1, TechnoClass *source, bool a3, Cell *a4);
        virtual bool Toggle_Primary();
        virtual unsigned entry_380();

        operator BuildingType () const;

        void Draw_Overlays(Point2D& coord, Rect& rect);
        // 00429070
        // 00429100
        int Shape_Number() const;
        void Drop_Debris(TARGET source);
        void Assign_Rally_Point(Cell &cell);
        void Begin_Mode(BStateType bstate);
        // 0042FF70
        // 004305C0
        // 00433A20
        int Power_Output() const;
        int Power_Drain() const;
        bool Flush_For_Placement(TechnoClass *techno, Cell &cell);
        Cell Check_Point(CheckPointType cp) const;
        void Update_Radar_Spied();
        void Build_INI_Entry(CCINIClass &ini) const;
        void Factory_AI();
        void Charging_AI();
        void Repair_AI();
        void Animation_AI();
        // 00435E60
        // 00436020
        // 004360E0
        // 00436140
        // 00436200
        // 00436410
        // 004364A0
        // 00436500
        // 00436580
        // 00436610
        // 00436730
        // 00436790
        // 00436890
        // 00436950
        // 004369D0
        // 00436A80
        // 00436B20
        // 00436B90
        // 00436CF0
        // 00436D50
        // 00436EC0
        // 00437050
        // 004370D0
        // 00437370
        // 00437550
        // 00437680
        // 004376B0
        // 00437E30
        // 00438590
        // 004388D0
        // 00438910
        // 00438950
        bool Is_Powered_On() const;
        // 004392F0
        // 00439500
        // 004396D0
        // 00439750
        // 00439A90
        // 00439D40
        // 00439E90
        // 0043A180
        // 0043A4D0
        // 0043A520
        // 0043A570
        void Update_Spied(HouseClass *house);
        // 0043AE50
        // 0043AF60
        // 0043AFC0
        // 0043B340
        // 0043B3D0
        // 0043B5C0
        // 0043B770
        // 0043B810

        BuildingTypeClass::AnimControlStruct const * Fetch_Anim_Control() { return &Class->Anims[BState]; }

        static void Read_INI(CCINIClass &ini);
        static void Write_INI(CCINIClass &ini);

    public:
        BuildingTypeClass *Class;
        FactoryClass *Factory;
        CDTimerClass<FrameTimerClass> CountDown;
        BStateType BState;
        BStateType QueueBState;
        HousesType WhoLastHurtMe;
        TARGET WhomToRepay;
        int LastStrength;
        TARGET AnimToTrack;
        CDTimerClass<FrameTimerClass> PlacementDelay;
        AnimClass *Anims[BANIM_COUNT];
        BuildingTypeClass *Upgrades[BUILDING_UPGRADE_MAX];
        int field_298; // special weapon index?
        int field_29C; // maybe BAnimType? turret anim loaded or played?.
        BuildingLightClass *BuildingLight;
        CDRateTimerClass<FrameTimerClass> GateTimer;
        LightSourceClass *LightSource;
        int LaserFenceFrame;
        int FirestormWallFrame; // Current frame of the firestorm wall animation.
        StageClass field_2C0;
        TRect<int> field_2D8;
        Coordinate field_2E8;
        TPoint2D<int> field_2F4; // some radar pos.
        bool IsPowerOn; // energy support?
        bool IsNominal;
        bool IsToRebuild;
        bool IsToRepair;
        bool IsAllowedToSell;
        bool IsReadyToCommence;
        bool IsWrenchVisible;
        bool IsGoingToBlow;
        bool IsSurvivorless;
        bool IsCharging;
        bool IsCharged;
        bool IsCaptured;
        bool HasOpened;
        bool field_309;
        bool field_30A; // taken damage and play anim?
        bool IsFogged;
        bool IsRepairing;
        bool field_30D; // buildup anim free'd?
        bool field_30E; // is online?
        char field_30F; // cloaking flags?
        bool HasCloakRadius; // if CloakRadiusInCells is greater that 0, this is set.
        char TranslucencyLevel;
        unsigned short TintColor; // when flashing?
        char UpgradeLevel;
        char GateFrame;

    public:
        static const ShapeFileStruct*& WrenchShape;
        static const ShapeFileStruct*& PowerOffShape;

};
