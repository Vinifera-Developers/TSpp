/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          INFANTRYTYPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for infantry types.
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

#include "technotype.h"
#include "typelist.h"
#include "tibsun_defines.h"


class DECLSPEC_UUID("AE8B33D8-061C-11D2-ACA4-006008055BB5")
InfantryTypeClass : public TechnoTypeClass
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
        InfantryTypeClass(const char *ini_name = nullptr);
        InfantryTypeClass(const NoInitClass &noinit);
        virtual ~InfantryTypeClass();

        /**
         *  AbstractClass
         */
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;
        virtual int Get_Heap_ID() const override;

        /**
         *  AbstractTypeClass
         */
        virtual bool Read_INI(CCINIClass &ini) override;

        /**
         *  ObjectTypeClass
         */
        virtual Coordinate Coord_Fixup(Coordinate *coord) const override;
        virtual Point3D Lepton_Dimensions() const override;
        virtual bool Create_And_Place(Cell &cell, HouseClass *house = nullptr) const override;
        virtual ObjectClass *const Create_One_Of(HouseClass *house = nullptr) const override;
        virtual Cell *Occupy_List(bool placement = false) const;

        /**
         *  TechnoTypeClass
         */
		virtual int Repair_Cost() const override;
		virtual int Repair_Step() const override;

        void Sequence_Read_INI();

        static const InfantryTypeClass &As_Reference(InfantryType type);
        static const InfantryTypeClass *As_Pointer(InfantryType type);
        static const InfantryTypeClass &As_Reference(const char *name);
        static const InfantryTypeClass *As_Pointer(const char *name);
        static InfantryType From_Name(const char *name);
        static const char *Name_From(InfantryType type);
        static const InfantryTypeClass *Find_Or_Make(const char *name);

    public:
		InfantryType Type;
        PipType Pip;
        DoInfoStruct * DoControls;
        int FireLaunch;
        int ProneLaunch;
        TypeList<VocType> VoiceComment;
        bool IsCyborg;
        bool IsFearless;
        bool IsCrawling;
        bool IsCapture;
        bool IsFraidyCat;
        bool IsTiberiumProof;
        bool IsCivilian;
        bool IsBomber;
        bool IsEngineer;
        bool IsDisguised;
        bool IsAgent;
        bool IsThief;
        bool IsVehicleThief;
        bool IsDoggie;
        bool IsJumpJet;
        bool IsWebImmune;
};
