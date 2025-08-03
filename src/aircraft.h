/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          AIRCRAFT.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Flying objects class.
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

#include "foot.h"
#include "ftimer.h"
#include "iflycontrol.h"
#include "ttimer.h"


class AircraftTypeClass;


class DECLSPEC_UUID("0E272DC2-9C0F-11D1-B709-00A024DDAFD1")
AircraftClass : public FootClass, public IFlyControl
{
public:
    /**
     *  IUnknown
     */
    IFACEMETHOD(QueryInterface)(REFIID riid, LPVOID* ppvObj);
    IFACEMETHOD_(ULONG, AddRef)();
    IFACEMETHOD_(ULONG, Release)();

    /**
     *  IPersist
     */
    IFACEMETHOD(GetClassID)(CLSID* pClassID);

    /**
     *  IPersistStream
     */
    IFACEMETHOD(Load)(IStream* pStm);
    IFACEMETHOD(Save)(IStream* pStm, BOOL fClearDirty);

    /**
     *  IFlyControl
     */
    IFACEMETHOD_(LONG, Landing_Altitude)();
    IFACEMETHOD_(LONG, Landing_Direction)();
    IFACEMETHOD_(BOOL, Is_Loaded)();
    IFACEMETHOD_(LONG, Is_Strafe)();
    IFACEMETHOD_(LONG, Is_Locked)();

public:
    AircraftClass(AircraftTypeClass* classof = nullptr, HouseClass* house = nullptr);
    AircraftClass(const NoInitClass& noinit);
    virtual ~AircraftClass();

    /**
     *  AbstractClass
     */
    virtual void Init() override;
    virtual void Detach(AbstractClass* target, bool all = true) override;
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual void Object_CRC(CRCEngine& crc) const override;
    virtual void AI() override;

    /**
     *  ObjectClass
     */
    virtual ActionType What_Action(const ObjectClass* object, bool disallow_force = false) override;
    virtual ActionType What_Action(const Cell& cell, bool check_fog = false, bool disallow_force = false) const override;
    virtual LayerType In_Which_Layer() const override;
    virtual bool entry_80() const override;
    virtual const ObjectTypeClass* Class_Of() const override;
    virtual const char* Full_Name() const override;
    virtual bool Unlimbo(const Coord& coord, Dir256 dir = DIR_N) override;
    virtual ExitType Exit_Object(const TechnoClass* object) override;
    virtual void Draw_It(Point2D& point, Rect& bounds) const override;
    virtual void Look(bool incremental = false, bool a2 = false) override;
    virtual bool Active_Click_With(ActionType action, ObjectClass* target, bool a3 = false) override;
    virtual bool Active_Click_With(ActionType action, Cell& cell, bool a3 = false) override;
    virtual ResultType Take_Damage(int& damage, int distance, const WarheadTypeClass* warhead, const ObjectClass* source, bool forced = false, bool a6 = false) override;
    virtual void Scatter(const Coord& coord = Coord {-1, -1, -1}, bool forced = false, bool nokidding = false) override;
    virtual RadioMessageType Receive_Message(RadioClass* from, RadioMessageType message, long& param) override;
    virtual MoveType Can_Enter_Cell(const CellClass* cell, FacingType facing = FACING_NONE, int cell_level = -1, const CellClass* a4 = nullptr, bool a5 = true) override;

    /**
     *  MissionClass
     */
    virtual bool Commence() override;
    virtual bool Ready_To_Commence() const override;
    virtual int Mission_Attack() override;
    virtual int Mission_Guard() override;
    virtual int Mission_Guard_Area() override;
    virtual int Mission_Hunt() override;
    virtual int Mission_Move() override;
    virtual int Mission_Retreat() override;
    virtual int Mission_Unload() override;
    virtual int Mission_Enter() override;
    virtual int Mission_Patrol() override;

    /**
     *  TechnoClass
     */
    virtual DirType Turret_Facing() const override;
    virtual FacingType Desired_Load_Dir(const ObjectClass* object, Cell& cell) const override;
    virtual DirType Fire_Direction() const override;
    virtual void Player_Assign_Mission(MissionType order, AbstractClass* target = nullptr, AbstractClass* destination = nullptr) override;
    virtual void Reduce_Ammunition() override;
    virtual FireErrorType Can_Fire(AbstractClass* target, WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const override;
    virtual const BulletClass* Fire_At(AbstractClass* target, WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) override;
    virtual void Assign_Destination(const AbstractClass* target, bool a2 = true) override;
    virtual bool Enter_Idle_Mode(bool inital = false, bool a2 = false) override;

    /**
     *  FootClass
     */
    virtual bool entry_368() override;

    void Draw_Rotors(Point2D& xy, Rect& rect) const;
    int Paradrop_Cargo();
    int Drop_Off_Cargo();
    int Do_Mission_Move_Carryall();
    Dir256 Pose_Dir() const;
    CellClass* New_LZ(CellClass* oldlz);
    CellClass* Good_Fire_Location(AbstractClass* target) const;
    bool Cell_Seems_Ok(Cell& cell, bool strict) const;
    CellClass* Good_LZ();
    bool On_Death(ObjectClass* source);

    static void Read_INI(CCINIClass& ini);
    static void Write_INI(CCINIClass& ini);

    static bool Counts_As_Civ_Evac(const ObjectClass* candidate);

public:
    AircraftTypeClass* Class;
    bool field_358;
    bool Passenger;
    bool IsKamikaze;
    bool field_35B;
    bool IsLocked;
    CDTimerClass<FrameTimerClass> SightTimer;
    int AttacksRemaining;
    bool field_370;
    int field_374;
};
