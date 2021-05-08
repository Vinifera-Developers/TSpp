/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          HOUSE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Player/AI instance class.
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
#include "ihouse.h"
#include "ipublichouse.h"
#include "iaihouse.h"
#include "ipowerevents.h"
#include "vector.h"
#include "storage.h"
#include "counter.h"
#include "region.h"
#include "base.h"
#include "ttimer.h"
#include "ftimer.h"
#include "typelist.h"
#include "dropship.h"
#include "tibsun_defines.h"
#include <ocidl.h> // for IConnectionPointContainer.


#define DROPSHIP_LOADOUT_MAX 3
#define HOUSE_NAME_MAX    20 // 12
#define MAX_WAYPOINT_PATHS    12


class CCINIClass;
class HouseTypeClass;
class WaypointPathClass;
class SuperClass;
class UnitTrackerClass;
class FactoryClass;
class TagClass;
class ObjectClass;
class FootClass;
class UnitClass;
class BuildingClass;
class TechnoTypeClass;
class ObjectTypeClass;
class TechnoClass;
class TeamTypeClass;


class DECLSPEC_UUID("D9D4A910-87C6-11D1-B707-00A024DDAFD1")
HouseClass : public AbstractClass, public IHouse, public IPublicHouse, public IConnectionPointContainer
{
    public:
        class HouseStaticClass
        {
            public:
                HouseStaticClass();
                HouseStaticClass(const HouseStaticClass &that);
                HouseStaticClass(const NoInitClass &noinit);
                ~HouseStaticClass();

                void Add_Ally(HousesType house) { Allies |= 1 << house; }
                void Remove_Ally(HousesType house) { Allies &= ~(1 << house); }

            public:
                int IQ;
                int TechLevel;
                unsigned Allies;
                long InitialCredits;
                SourceType Edge;
        };

    public:
        /**
         *  IUnknown
         */
        IFACEMETHOD(QueryInterface)(REFIID riid, LPVOID *ppvObj);
        IFACEMETHOD_(ULONG, AddRef)();
        IFACEMETHOD_(ULONG, Release)();

        /**
         *  IPersist
         */
        IFACEMETHOD(GetClassID)(CLSID *pClassID);

        /**
         *  IPersistStream
         */
        IFACEMETHOD(Load)(IStream *pStm);
        IFACEMETHOD(Save)(IStream *pStm, BOOL fClearDirty);
        
        /**
         *  IHouse
         */
        IFACEMETHOD_(LONG, ID_Number)();
        IFACEMETHOD_(BSTR, Name)();
        IFACEMETHOD_(IApplication *, Get_Application)();
        IFACEMETHOD_(LONG, Available_Money)();
        IFACEMETHOD_(LONG, Available_Storage)();
        IFACEMETHOD_(LONG, Power_Output)();
        IFACEMETHOD_(LONG, Power_Drain)();
        IFACEMETHOD_(LONG, Category_Quantity)(CategoryType category);
        IFACEMETHOD_(LONG, Category_Power)(CategoryType category);
        IFACEMETHOD_(CellStruct, Base_Center)();
        IFACEMETHOD_(LONG, Fire_Sale)();
        IFACEMETHOD_(LONG, All_To_Hunt)();
        
        /**
         *  IPublicHouse
         */
        IFACEMETHOD_(LONG, Apparent_Category_Quantity)(CategoryType category);
        IFACEMETHOD_(LONG, Apparent_Category_Power)(CategoryType category);
        IFACEMETHOD_(CellStruct, Apparent_Base_Center)();
        IFACEMETHOD_(bool, Is_Powered)();

        /**
         *  IConnectionPointContainer
         */
        IFACEMETHOD(EnumConnectionPoints)(IEnumConnectionPoints **ppEnum);
        IFACEMETHOD(FindConnectionPoint)(REFIID riid, IConnectionPoint **ppCP);

    public:
        HouseClass(const HouseTypeClass *classof = nullptr);
        HouseClass(const NoInitClass &noinit);
        virtual ~HouseClass();

        /**
         *  AbstractClass
         */
        virtual void Detach(TARGET target, bool all = true) override;
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;
        virtual int Get_Heap_ID() const override;
        virtual void AI() override;

        // 004BAED0
        float Tiberium_Fraction() const;
        DiffType Assign_Handicap(DiffType handicap);
        bool Can_Build(const ObjectTypeClass *type, bool a2 = false, bool a3 = false) const;
        FactoryClass *Factory_Building_This(const ObjectTypeClass *type) const;
        void Super_Weapon_Handler();
        void Attacked(BuildingClass *source);
        void Tiberium_Harvested(unsigned amount, TiberiumType type);
        void Weed_Harvested(unsigned amount, TiberiumType type);
        float Weed_Fraction() const;
        void Spend_Money(unsigned money);
        void Refund_Money(unsigned money);
        void Silo_Redraw_Check(long oldtib, long oldcap);
        bool Is_Ally(HousesType house) const;
        bool Is_Ally(const HouseClass *house) const;
        bool Is_Ally(const ObjectClass *object) const;
        bool Is_Ally(const TARGET target) const;
        void Make_Ally(HousesType house);
        void Make_Ally(HouseClass *house);
        void Make_Enemy(HousesType house);
        void Make_Enemy(HouseClass *house);
        TypeList<const TeamTypeClass *> Suggested_New_Team(bool alertcheck = false);
        void Adjust_Threat(int region, int threat);
        ProdFailType Begin_Production(RTTIType type, int id, bool a3);
        ProdFailType Suspend_Production(RTTIType type);
        ProdFailType Abandon_Production(RTTIType type, int a1);
        bool Special_Weapon_AI(SpecialWeaponType id);
        bool Place_Special_Blast(SpecialWeaponType id, CellStruct &cell);
        bool Place_Object(RTTIType type, CellStruct &cell);
        void Just_Built(TechnoClass *techno); 
        bool Manual_Place(BuildingClass *builder, BuildingClass *object);
        void Clobber_All();
        bool Does_Enemy_Building_Exist(BuildingType btype) const;
        const TechnoTypeClass *Suggest_New_Object(RTTIType objecttype, bool kennel = false) const;
        bool Flag_Remove(TARGET target, bool set_home = false);
        bool Flag_Attach(CellStruct &cell, bool set_home = false);
        bool Flag_Attach(UnitClass *object, bool set_home = false);
        void MPlayer_Defeated();
        void Blowup_All();
        bool Flag_To_Die();
        bool Flag_To_Win(bool a1 = true);
        bool Flag_To_Lose(bool a1 = true);
        // 004BFFB0
        void Init_Data(ColorSchemeType color, HousesType house, int credits);
        float Power_Fraction() const;
        void Sell_Wall(CellStruct &cell, bool quiet = true);
        const BuildingTypeClass * Suggest_New_Building() const;
        BuildingClass * Find_Building(BuildingType type, ZoneType zone = ZONE_NONE) const;
        CoordStruct Find_Build_Location(BuildingClass *building) const;
        void Recalc_Center();
        int Expert_AI();
        UrgencyType Check_Fire_Sale() const;
        UrgencyType Check_Raise_Money() const;
        bool AI_Fire_Sale(UrgencyType urgency);
        bool AI_Raise_Money(UrgencyType urgency);
        int AI_Building();
        int AI_Unit();
        int AI_Infantry();
        int AI_Aircraft();
        void Production_Begun(const TechnoClass *rtti);
        void Tracking_Remove(const TechnoClass *techno);
        void Tracking_Add(const TechnoClass *techno);
        int * Factory_Counter(RTTIType rtti);
        void Active_Remove(const TechnoClass *techno);
        void Active_Add(const TechnoClass *techno);
        ZoneType Which_Zone(CoordStruct &coord) const;
        ZoneType Which_Zone(const ObjectClass * object) const;
        ZoneType Which_Zone(CellStruct &cell) const;
        CellStruct Zone_Cell(ZoneType zone) const;
        CellStruct Where_To_Go(const FootClass *object) const;
        TARGET Find_Juicy_Target(CoordStruct &coord) const;
        FactoryClass *Fetch_Factory(RTTIType rtti) const;
        void Set_Factory(RTTIType rtti, FactoryClass * factory);
        int Factory_Count(RTTIType rtti) const;
        // 004C2E40
        void Read_INI(CCINIClass &ini);
        // 004C31B0
        void Write_INI(CCINIClass &ini) const;
        bool Is_Allowed_To_Ally(HouseClass *house) const;
        void Adjust_Power(int adjust);
        void Adjust_Drain(int adjust);
        void Update_Spied_Power_Plants();
        CellStruct Find_Cell_In_Zone(const TechnoClass * techno, ZoneType zone) const;
        CellStruct Random_Cell_In_Zone(ZoneType zone) const;
        void Make_Ally(TechnoClass *techno);
        void Make_Enemy(TechnoClass *techno);
        // 004C3FC0
        // 004C40F0
        // 004C4150
        // 004C4210
        // 004C42C0
        // 004C4450
        // 004C45D0
        // 004C5320
        // 004C5360
        // 004C5370
        // 004C53C0
        // 004C5510
        // 004C56A0
        // 004C5770
        // 004C5840
        // 004C5880
        // 004C58B0
        // 004C5920
        // 004C5BB0
        // 004C68E0
        // 004C6930
        // 004C6A10
        // 004C7300
        // 004C7310
        // 004C7320
        // 004C7470
        // 004C74F0
        // 004C7690
        // 004C83F0
        // 004C85A0
        // 004C8750
        // 004C8900
        // 004C8920
        // 004C93F0
        // 004C9560
        // 004C96A0
        // 004C96F0
        // 004C9730
        void Update_Factories(RTTIType rtti); // 004C9740
        void Update_Radar_Spied(HouseClass *house); // 004C98E0
        void Update_Anger(HouseClass *house); // 004C9990
        void Recalc_Threat_Regions(); // 004C99D0
        // 004C9B80
        // 004C9BC0
        // 004C9CB0
        // 004C9EA0
        // 004C9FB0
        // 004CA450
        // 004CA4A0
        // 004CA600
        // 004CA760
        // 004CA880
        // 004CB2D0
        // 004CB5B0
        // 004CB720
        bool Is_Player_Control() const;
        bool Is_Human_Control() const;
        // 004CB9C0
        void Init_Remap_Color();
        // 004CBB30

        static void One_Time();
        static void Computer_Paranoid();

        static HouseClass *As_Pointer(HousesType house);
        static HouseClass &As_Reference(HousesType house) { return *As_Pointer(house); }

    public:
        int ID;
        HouseTypeClass *Class;
        DynamicVectorClass<TagClass *> field_28;
        DynamicVectorClass<BuildingClass *> field_40;
        DiffType Difficulty;
        double FirepowerBias;
        double GroundspeedBias;
        double AirspeedBias;
        double ArmorBias;
        double ROFBias;
        double CostBias;
        double BuildSpeedBias;
        double RepairDelay;
        double BuildDelay;
        HouseStaticClass Control;
        int field_BC;
        SideType ActLike;
        bool IsHuman;
        bool IsPlayerControl;
        bool IsStarted;
        bool IsAlerted;
        bool field_C8; // set when ai triggers begin action.
        bool IsBaseBuilding;
        bool IsDiscovered;
        bool IsDefeated;
        bool IsToDie;
        bool IsToWin;
        bool IsToLose;
        bool IsCivEvacuated;
        bool field_D0;
        bool field_D1;
        bool IsRecalcNeeded;
        int field_D4;
        int Clan;
        bool field_DC;
        int field_E0; // selected waypoint path index?
        WaypointPathClass *WaypointPaths[MAX_WAYPOINT_PATHS];
        bool IsVisionary;
        bool IsTiberiumShort;
        bool IsSpied;
        bool IsThieved;
        bool DidRepair;
        bool IsBuiltSomething;
        bool IsResigner;
        bool IsGiverUpper;
        bool field_11C;
        bool IsParanoid;
        bool IsToLook;
        int IQ;
        StateType State;
        DynamicVectorClass<SuperClass *> SuperWeapon;
        BuildingType JustBuiltStructure;
        InfantryType JustBuiltInfantry;
        UnitType JustBuiltUnit;
        AircraftType JustBuiltAircraft;
        int Blockage;
        CDTimerClass<FrameTimerClass> RepairTimer;
        CDTimerClass<FrameTimerClass> AlertTime;
        CDTimerClass<FrameTimerClass> BorrowedTime;
        unsigned CreditsSpent;
        unsigned HarvestedCredits;
        int StolenBuildingsCredits;
        unsigned CurUnits;
        unsigned CurBuildings;
        unsigned CurInfantry;
        unsigned CurAircraft;
        StorageClass Tiberium;
        long Credits;
        long Capacity;
        StorageClass Weed;
        long field_1BC;
        UnitTrackerClass *AircraftTotals;
        UnitTrackerClass *InfantryTotals;
        UnitTrackerClass *UnitTotals;
        UnitTrackerClass *BuildingTotals;
        UnitTrackerClass *DestroyedAircraft;
        UnitTrackerClass *DestroyedInfantry;
        UnitTrackerClass *DestroyedUnits;
        UnitTrackerClass *DestroyedBuildings;
        UnitTrackerClass *CapturedBuildings;
        UnitTrackerClass *TotalCrates;
        int AircraftFactories;
        int InfantryFactories;
        int UnitFactories;
        int BuildingFactories;
        int Power;
        int Drain;
        FactoryClass *AircraftFactory;
        FactoryClass *InfantryFactory;
        FactoryClass *UnitFactory;
        FactoryClass *BuildingFactory;
        AbstractClass *FlagLocation;
        CellStruct FlagHome;
        unsigned UnitsKilled[20];
        unsigned UnitsLost;
        unsigned BuildingsKilled[20];
        unsigned BuildingsLost;
        HousesType WhoLastHurtMe;
        CoordStruct Center;
        int Radius;

        struct {
            int AirDefense;
            int ArmorDefense;
            int InfantryDefense;
        } ZoneInfo[ZONE_COUNT];

        int LATime;
        HousesType LAEnemy;
        AbstractClass * ToCapture;
        int RadarSpied;
        int PointTotal;
        QuarryType PreferredTarget;
        TCounterClass<BuildingType> BQuantity;
        TCounterClass<UnitType> UQuantity;
        TCounterClass<InfantryType> IQuantity;
        TCounterClass<AircraftType> AQuantity;
        TCounterClass<BuildingType> ActiveBQuantity;
        TCounterClass<UnitType> ActiveUQuantity;
        TCounterClass<InfantryType> ActiveIQuantity;
        TCounterClass<AircraftType> ActiveAQuantity;
        TCounterClass<BuildingType> FactoryBQuantity;
        TCounterClass<UnitType> FactoryUQuantity;
        TCounterClass<InfantryType> FactoryIQuantity;
        TCounterClass<AircraftType> FactoryAQuantity;
        CDTimerClass<FrameTimerClass> Attack;
        int InitalAttack;
        HousesType Enemy;
        DynamicVectorClass<AngerStruct> AngerNodes;
        DynamicVectorClass<ScoutStruct> ScoutNodes;
        CDTimerClass<FrameTimerClass> AITimer;
        CDTimerClass<FrameTimerClass> ExpertAITimer;
        BuildingType BuildStructure;
        UnitType BuildUnit;
        InfantryType BuildInfantry;
        AircraftType BuildAircraft;
        int RatioAITriggerTeam;
        int RatioTeamAircraft;
        int RatioTeamInfantry;
        int RatioTeamUnits;
        int BaseDefenseTeamCount;
        DropshipLoadoutClass DropshipLoadouts[DROPSHIP_LOADOUT_MAX];
        int field_4EC;
        bool field_4F0;
        RGBStruct RemapColorRGB;
        BaseClass Base;
        bool field_56C;
        bool field_56D;
        CellStruct field_56E;
        CellStruct NukeDest;
        unsigned Allies;
        CDTimerClass<FrameTimerClass> DamageTime;
        CDTimerClass<FrameTimerClass> TeamTime;
        CDTimerClass<FrameTimerClass> TriggerTime;
        CDTimerClass<FrameTimerClass> SpeakAttackDelay;
        CDTimerClass<FrameTimerClass> SpeakPowerDelay;
        CDTimerClass<FrameTimerClass> SpeakMoneyDelay;
        CDTimerClass<FrameTimerClass> SpeakMaxedDelay;
        IAIHouse *AIGeneral;
        RegionClass Regions[MAP_TOTAL_REGIONS];
        char IniName[HOUSE_NAME_MAX+1];
        ColorSchemeType RemapColor;
        int field_10E00;
        DynamicVectorClass<IConnectionPoint *> field_10E04;
        IConnectionPoint *PowerEvents;
        int field_10E20;
        double field_10E28;
        double field_10E30;
        int field_10E38;
        float field_10E3C;
        float field_10E40;
        float field_10E44;
        int field_10E48;

    private:
        // copy and assignment not implemented; prevent their use by declaring as private.
        HouseClass(const HouseClass &) = delete;
        HouseClass &operator=(const HouseClass &) = delete;
};
