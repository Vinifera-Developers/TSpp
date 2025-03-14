/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WEAPONTYPECLASS.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for weapon types.
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

#include "abstracttype.h"
#include "typelist.h"


class AnimTypeClass;
class ParticleSystemTypeClass;


class DECLSPEC_UUID("A8C54DA4-0F7B-11D2-8172-006008055BB5")
WarheadTypeClass : public AbstractTypeClass
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
        WarheadTypeClass(const char *ini_name = nullptr);
        WarheadTypeClass(const NoInitClass &noinit);
        virtual ~WarheadTypeClass();

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

        static const WarheadTypeClass &As_Reference(WarheadType type);
        static const WarheadTypeClass *As_Pointer(WarheadType type);
        static const WarheadTypeClass &As_Reference(const char *name);
        static const WarheadTypeClass *As_Pointer(const char *name);
        static WarheadType From_Name(const char *name);
        static const char *Name_From(WarheadType type);
        static const WarheadTypeClass *Find_Or_Make(const char *name);

    public:
        double Deform;
        double Modifier[ARMOR_COUNT];
        double ProneFactor;
        int DeformThreshhold;
        TypeList<AnimTypeClass *> AnimList;
        int InfantryDeath;
        int SpreadFactor;
        int WebDuration;
        int WebDurationVariation;
        int WebRadius;
        int LimpetFactor;
        ParticleSystemTypeClass *Particle;
        bool IsWallDestroyer;
        bool IsWebby;
        bool IsWoodDestroyer;
        bool IsTiberiumDestroyer;
        bool IsOrganic;
        bool IsSparky;
        bool IsFire;
        bool IsConventional;
        bool IsRocker;
        bool IsBright;
        bool IsEMEffect;
        bool IsVeinhole;
};
