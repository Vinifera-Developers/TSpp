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
 *  @brief         Unit game object class.
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
#include "ttimer.h"
#include "ftimer.h"
#include "tibsun_defines.h"


class UnitTypeClass;


class DECLSPEC_UUID("0E272DCA-9C0F-11D1-B709-00A024DDAFD1")
UnitClass : public FootClass
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
        UnitClass(UnitTypeClass *classof = nullptr, HouseClass *house = nullptr);
        UnitClass(const NoInitClass &noinit);
        virtual ~UnitClass();

        /**
         *  AbstractClass
         */
        virtual void Detach(TARGET target, bool all = true) override;
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;
        virtual void AI() override;

        /**
         *  ObjectClass
         */
        virtual ActionType What_Action(const ObjectClass *object, bool disallow_force = false) override;
        virtual ActionType What_Action(CellStruct &cell, bool check_fog = false, bool disallow_force = false) const override;
        virtual bool entry_80() const override;
        virtual ObjectTypeClass *const Class_Of() const override;
        virtual const char *Full_Name() const override;
        virtual bool Limbo() override;
        virtual bool Unlimbo(CoordStruct &coord, DirType dir = DIR_N) override;
        virtual void Record_The_Kill(const ObjectClass *source) override;
        virtual void Set_Occupy_Bit(CoordStruct &coord) override;
        virtual void Clear_Occupy_Bit(CoordStruct &coord) override;
        virtual bool Render(Rect &rect, bool force = false, bool a3 = false) override;
        virtual void Draw_It(Point2D &point, Rect &bounds) const override;
        virtual bool Active_Click_With(ActionType action, ObjectClass *target, bool a3) override;
        virtual bool Active_Click_With(ActionType action, CellStruct &cell, ObjectClass *target) override;
        virtual ResultType Take_Damage(int &damage, int distance, const WarheadTypeClass *warhead, const ObjectClass *source, bool forced = false, bool a6 = false) override;
        virtual void Scatter(CoordStruct &coord = CoordStruct{-1, -1, -1}, bool forced = false, bool nokidding = false) override;
        virtual void Per_Cell_Process(PCPType why) override;
        virtual RadioMessageType Receive_Message(RadioClass *from, RadioMessageType message, long &param) override;
        virtual MoveType Can_Enter_Cell(const CellClass *cell, FacingType facing = FACING_NONE, int cell_level = -1, const CellClass *a4 = nullptr, bool a5 = false) override;

        /**
         *  MissionClass
         */
        virtual bool Ready_To_Commence() const override;
        virtual int Mission_Attack() override;
        virtual int Mission_Guard() override;
        virtual int Mission_Guard_Area() override;
        virtual int Mission_Harvest() override;
        virtual int Mission_Hunt() override;
        virtual int Mission_Move() override;
        virtual int Mission_Unload() override;
        virtual int Mission_Repair() override;
        virtual int Mission_Patrol() override;

        /**
         *  TechnoClass
         */
        virtual bool entry_238() const override;
        virtual DirStruct Turret_Facing() const override;
        virtual double Tiberium_Load() const override;
        virtual double Weed_Load() const override;
        virtual int Pip_Count() const override;
        virtual FacingType Desired_Load_Dir(const ObjectClass *object, CellStruct &cell) const override;
        virtual DirStruct Fire_Direction() const override;
        virtual InfantryTypeClass *const Crew_Type() const override;
        virtual bool entry_2A4() const override;
        virtual int Get_Max_Speed() const override;
        virtual FireErrorType Can_Fire(const TechnoClass *object, WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const override;
        virtual int Greatest_Threat(ThreatType method, CoordStruct &coord, bool a3 = false) const override;
        virtual const BulletClass *Fire_At(TARGET target, WeaponSlotType weapon = WEAPON_SLOT_PRIMARY) const override;
        virtual bool Captured(HouseClass *house = nullptr) override;
        virtual void Assign_Destination(const TARGET target, bool a2 = true) const override;
        virtual bool Enter_Idle_Mode(bool inital = false, bool a2 = false) const override;

        /**
         *  FootClass
         */
        virtual bool entry_370() override;
        virtual void Overrun_Square(CellStruct &cell, bool threaten) override;
        virtual void Approach_Target() override;

        /**
         *  UnitClass
         */
        virtual void entry_3C0(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
        virtual void entry_3C4(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
        virtual void entry_3C8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9);

        void Tunnel_AI();
        void Rotation_AI();
        bool Edge_Of_World_AI();
        void Reload_AI();
        void Firing_AI();
        void Visceroid_AI();
        void Jellyfish_AI();
        bool Goto_Clear_Spot();
        bool Try_To_Deploy();
        bool Harvesting();
        bool Flag_Attach(HousesType house);
        bool Flag_Remove();
        void APC_Close_Door();
        void APC_Open_Door();
        int Credit_Load() const;
        bool Should_Crush_It(const TechnoClass *it) const;
        // 00659970
        // 0065B180
        // 0065B2F0
        // 0065B400

        static void Read_INI(CCINIClass &ini);
        static void Write_INI(CCINIClass &ini);

    public:
        int FiringSyncDelay;
        CDTimerClass<FrameTimerClass> Reload;
        UnitTypeClass *Class;
        TechnoClass *FollowingMe;
        HousesType Flagged;
        bool IsFollowing;
        bool IsDumping;
        bool IsHarvesting;
        bool field_36F; // uses terrain palette?
        FacingType VisceroidFacing;
        int CurrentCharge;
        int DeathCounter;
        int field_37C; // this only seems to be used for offsetting the size difference between TS and FS save games.
};
