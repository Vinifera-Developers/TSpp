/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          BULLETTYPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for bullet types.
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

#include "objecttype.h"
#include "tibsun_defines.h"


class WeaponTypeClass;
class AnimTypeClass;


class DECLSPEC_UUID("5AF2CE77-0634-11D2-ACA4-006008055BB5")
BulletTypeClass : public ObjectTypeClass
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
        BulletTypeClass(const char *ini_name = nullptr);
        BulletTypeClass(const NoInitClass &noinit);
        virtual ~BulletTypeClass();

        /**
         *  AbstractClass
         */
        virtual void Detach(AbstractClass * target, bool all = true) override;
        virtual RTTIType Fetch_RTTI() const override;
        virtual int Get_Object_Size(bool firestorm = false) const override;
        virtual void Object_CRC(CRCEngine &crc) const override;

        /**
         *  AbstractTypeClass
         */
        virtual bool Read_INI(CCINIClass &ini) override;

        /**
         *  ObjectTypeClass
         */
        virtual Coord Coord_Fixup(Coord *coord) const override;
        virtual bool Create_And_Place(Cell &cell, HouseClass *house = nullptr) const override;
        virtual ObjectClass *const Create_One_Of(HouseClass *house = nullptr) const override;

        static BulletType From_Name(const char *name);
        static const char *Name_From(BulletType type);
        static const BulletTypeClass *Find_Or_Make(const char *name);

    public:
        bool IsAirburst;
        bool IsFloater;
        bool IsHigh;
        bool IsVeryHigh;
        bool IsShadow;
        bool IsArcing;
        bool IsDropping;
        bool IsInvisible;
        bool IsProximityArmed;
        bool IsFueled;
        bool IsFaceless;
        bool IsInaccurate;
        bool IsAntiAircraft;
        bool IsAntiGround;
        bool IsDegenerate;
        bool IsBouncy;
        bool IsAnimPalette;
        bool IsSplits;
        bool IsAntiVehicle;
        int Cluster;
        WeaponTypeClass *AirburstWeapon;
        double Elasticity;
        int Acceleration;
        ColorSchemeType Color;
        AnimTypeClass *Trailer;
        unsigned ROT;
        int RetargetAccuracy;
        int Arming;
        unsigned char AnimLow;
        unsigned char AnimHigh;
        unsigned char AnimRate;
};
