/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CCINI.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Advanced version of the INI database manager which handles
 *                 the C&C engine types and identifiers.
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

#include "ini.h"
#include "typelist.h"
#include "vector3.h"
#include "tibsun_defines.h"


class FileClass;
class Straw;
class Pipe;
class TechnoTypeClass;
class xTargetClass;
class UnitTypeClass;
class AnimTypeClass;
class BuildingTypeClass;


class CCINIClass : public INIClass
{
    public:
        CCINIClass();
        CCINIClass(FileClass &file, bool withdigest = false, bool load_comments = false);
        virtual ~CCINIClass();

        bool Load(FileClass & file, bool withdigest, bool load_comments = false);
        int Load(Straw & file, bool withdigest, bool load_comments = false);
        int Save(FileClass & file, bool withdigest) const;
        int Save(Pipe & pipe, bool withdigest) const;

        LEPTON Get_Lepton(const char *section, const char *entry, const LEPTON defvalue);
        bool Put_Lepton(const char *section, const char *entry, LEPTON value);

        unsigned Get_Degree(const char *section, const char *entry, unsigned defvalue = 0) const;
        bool Put_Degree(const char *section, const char *entry, unsigned value);

        Cell Get_Cell(const char *section, const char *entry, const Cell &defvalue);
        bool Put_Cell(const char *section, const char *entry, Cell &value);

        Coordinate Get_Coord(const char *section, const char *entry, const Coordinate &defvalue);

        MPHType Get_MPHType(const char *section, const char *entry, const MPHType defvalue);
        bool Put_MPHType(const char *section, const char *entry, MPHType value);

        PipScaleType Get_PipType(const char *section, const char *entry, const PipType defvalue);
        bool Put_PipType(const char *section, const char *entry, PipType value);

        PipScaleType Get_PipScaleType(const char *section, const char *entry, const PipScaleType defvalue);
        bool Put_PipScaleType(const char *section, const char *entry, PipScaleType value);

        CategoryType Get_CategoryType(const char *section, const char *entry, const CategoryType defvalue);
        bool Put_CategoryType(const char *section, const char *entry, CategoryType value);

        ColorSchemeType Get_ColorSchemeType(const char *section, const char *entry, const ColorSchemeType defvalue);
        bool Put_ColorSchemeType(const char *section, const char *entry, ColorSchemeType value);

        RGBStruct Get_RGB(const char *section, const char *entry, const RGBStruct &defvalue);
        bool Put_RGB(const char *section, const char *entry, RGBStruct &value);

        HSVStruct Get_HSV(const char *section, const char *entry, const HSVStruct &defvalue);
        bool Put_HSV(const char *section, const char *entry, RGBStruct &value);

        BSizeType Get_BSizeType(const char *section, const char *entry, const BSizeType defvalue);
        bool Put_BSizeType(const char *section, const char *entry, BSizeType value);

        MZoneType Get_MZoneType(const char *section, const char *entry, const MZoneType defvalue);
        bool Put_MZoneType(const char *section, const char *entry, MZoneType value);

        ActionType Get_ActionType(const char *section, const char *entry, const ActionType defvalue);

        SpecialWeaponType Get_SpecialWeaponType(const char *section, const char *entry, const SpecialWeaponType defvalue);

        VoxType Get_VoxType(const char *section, const char *entry, const VoxType defvalue);

        RTTIType Get_RTTIType(const char *section, const char *entry, const RTTIType defvalue);
        bool Put_RTTIType(const char *section, const char *entry, RTTIType value);

        long Get_Owners(const char *section, const char *entry, const long defvalue);
        bool Put_Owners(const char *section, const char *entry, long value);

        ArmorType Get_ArmorType(const char *section, const char *entry, const ArmorType defvalue);
        bool Put_ArmorType(const char *section, const char *entry, ArmorType value);

        bool Put_VocType(const char *section, const char *entry, VocType value);

        LandType Get_LandType(const char *section, const char *entry, const LandType defvalue);
        bool Put_LandType(const char *section, const char *entry, LandType value);

        HousesType Get_HousesType(const char *section, const char *entry, const HousesType defvalue);
        bool Put_HousesType(const char *section, const char *entry, HousesType value);

        SideType Get_SideType(const char *section, const char *entry, const SideType defvalue);
        bool Put_SideType(const char *section, const char *entry, SideType value);

        VQType Get_VQType(const char *section, const char *entry, const VQType defvalue);
        bool Put_VQType(const char *section, const char *entry, VQType value);

        TheaterType Get_TheaterType(const char *section, const char *entry, const TheaterType defvalue);
        bool Put_TheaterType(const char *section, const char *entry, TheaterType value);

        ThemeType Get_ThemeType(const char *section, const char *entry, const ThemeType defvalue);
        bool Put_ThemeType(const char *section, const char *entry, ThemeType value);

        SourceType Get_SourceType(const char *section, const char *entry, const SourceType defvalue);
        bool Put_SourceType(const char *section, const char *entry, SourceType value);

        CrateType Get_CrateType(const char *section, const char *entry, const CrateType defvalue);
        bool Put_CrateType(const char *section, const char *entry, CrateType value);

        SpeedType Get_SpeedType(const char *section, const char *entry, const SpeedType defvalue);
        bool Put_SpeedType(const char *section, const char *entry, SpeedType value);

        AbilitiesStruct Get_Ability(const char *section, const char *entry, const AbilitiesStruct &defvalue);

        TypeList<RGBStruct> Get_RGB_List(const char *section, const char *entry, const TypeList<RGBStruct> defvalue);

        TypeList<int> Get_Integer_List(const char *section, const char *entry, const TypeList<int> defvalue);
        bool Put_Integer_List(const char *section, const char *entry, const TypeList<int> value);
        
        TypeList<TechnoTypeClass *> Get_TechnoType_List(const char *section, const char *entry, const TypeList<TechnoTypeClass *> defvalue);
        bool Put_TechnoType_List(const char *section, const char *entry, const TypeList<TechnoTypeClass *> value);

        TypeList<SideType> Get_SideType_List(const char *section, const char *entry, const TypeList<SideType> defvalue);
        bool Put_HousesType_List(const char *section, const char *entry, const TypeList<SideType> value);
        
        xTargetClass Get_Target(const char *section, const char *entry, const xTargetClass &defvalue);
        bool Put_Target(const char *section, const char *entry, xTargetClass &value);

        int Get_Unique_ID() const;

        const Vector3 Get_Vector3(char const *section, char const *entry, const Vector3 defvalue) const;
        bool Put_Vector3(char const *section, char const *entry, const Vector3 value);

        VocType Get_VocType(const char *section, const char *entry, const VocType defvalue);

        const UnitTypeClass *Get_Unit(const char *section, const char *entry, const UnitTypeClass *defvalue);
        bool Put_Unit(const char *section, const char *entry, const UnitTypeClass *value);

        const AnimTypeClass *Get_Anim(const char *section, const char *entry, const AnimTypeClass *defvalue);
        bool Put_Anim(const char *section, const char *entry, const AnimTypeClass *value);

        TypeList<UnitTypeClass *> Get_Units(const char *section, const char *entry, const TypeList<UnitTypeClass *> defvalue);
        bool Put_Units(const char *section, const char *entry, const TypeList<UnitTypeClass *> value);

        TypeList<BuildingTypeClass *> Get_Buildings(const char *section, const char *entry, const TypeList<BuildingTypeClass *> defvalue);
        bool Put_Buildings(const char *section, const char *entry, const TypeList<BuildingTypeClass *> value);

        LayerType Get_LayerType(const char *section, const char *entry, const LayerType defvalue);
        bool Put_LayerType(const char *section, const char *entry, LayerType value);

        ParticleType Get_ParticleType(const char *section, const char *entry, const ParticleType defvalue);
        bool Put_ParticleType(const char *section, const char *entry, ParticleType value);

        //static TypeList<VocType> Get_VocType_List(const char *section, const char *entry, const TypeList<VocType> defvalue);

        TypeList<VocType> Get_VocType_List(const char *section, const char *entry, const TypeList<VocType> defvalue);
        bool Put_VocType_List(const char *section, const char *entry, const TypeList<VocType> value);

    private:
        void Calculate_Message_Digest();
        void Invalidate_Message_Digest();

    private:
        bool IsDigestPresent;
        unsigned char Digest[20];
};
