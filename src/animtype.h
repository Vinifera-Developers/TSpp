/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          ANIMTYPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for animation types.
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


class WarheadTypeClass;
class OverlayTypeClass;


class DECLSPEC_UUID("AE8B33DA-061C-11D2-ACA4-006008055BB5")
AnimTypeClass : public ObjectTypeClass
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
        AnimTypeClass(const char *ini_name = nullptr);
        AnimTypeClass(const NoInitClass &noinit);
        virtual ~AnimTypeClass();

        /**
         *  AbstractClass
         */
        virtual void Detach(TARGET target, bool all = true);
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;
        virtual int Get_Heap_ID() const override;

        /**
         *  AbstractTypeClass
         */
        virtual void entry_64() override;
        virtual bool Read_INI(CCINIClass &ini) override;

        /**
         *  ObjectTypeClass
         */
        virtual bool Create_And_Place(CellStruct &cell, HouseClass *house = nullptr) const override;
        virtual ObjectClass *const Create_One_Of(HouseClass *house = nullptr) const override;
        virtual ShapeFileStruct *const Get_Image_Data() const override;

        /**
         *  AnimTypeClass
         */
        virtual void Load_Image(const char *filename);

        void Free_Image();

        static void Init(TheaterType theater);

        static const AnimTypeClass &As_Reference(AnimType type);
        static const AnimTypeClass *As_Pointer(AnimType type);
        static const AnimTypeClass &As_Reference(const char *name);
        static const AnimTypeClass *As_Pointer(const char *name);
        static AnimType From_Name(const char *name);
        static const char *Name_From(AnimType type);
        static const AnimTypeClass *Find_Or_Make(const char *name);

    public:
		AnimType Type;
        int Biggest;
        double Damage;
        int Delay;
        int Start;
        int LoopStart;
        int LoopEnd;
        int Stages;
        unsigned Loops;
        VocType Sound;
        AnimTypeClass *ChainTo;
        int DetailLevel;
        int TranslucencyDetailLevel;
        int RandomLoopDelayMin;
        int RandomLoopDelayMax;
        int RandomRateMin;
        int RandomRateMax;
        int Translucency;
        AnimTypeClass *Spawns;
        int SpawnCount;
        VocType StartSound;
        VocType BounceSound;
        VocType ExpireSound;
        AnimTypeClass *BounceAnim;
        AnimTypeClass *ExpireAnim;
        AnimTypeClass *TrailerAnim;
        int TrailerSeperation;
        double Elasticity;
        double MinZVel;
        double MaxZVel;
        double MaxXYVel;
        WarheadTypeClass *Warhead;
        int DamageRadius;
        OverlayTypeClass *TiberiumSpawnType;
        int TiberiumSpreadRadius;
        int YSortAdjust;
        int YDrawOffset;
        int RunningFrames;
        bool IsFlamingGuy;
        bool IsVeins;
        bool IsMeteor;
        bool TiberiumChainReaction;
        bool IsTiberium;
        bool IsBouncer;
        bool IsTiled;
        bool ShouldUseCellDrawer;
        bool UseNormalLight;
        bool IsDemandLoad;
        bool FreeAfterPlaying;
        bool IsAnimatedTiberium;
        bool IsAltPalette;
        bool IsNormalized;
        bool IsSurface;
        bool IsFlat;
        bool IsTranslucent;
        bool IsScorcher;
        bool IsFlameThrower;
        bool IsCraterForming;
        bool IsSticky;
        bool IsPingPong;
        bool IsReverse;
        bool IsShouldFogRemove;
};
