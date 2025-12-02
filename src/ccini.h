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

#include "buildingtype.h"
#include "ini.h"
#include "tibsun_defines.h"
#include "typelist.h"
#include "voc.h"
#include "wstring.h"


class FileClass;
class Straw;
class Pipe;
class AircraftTypeClass;
class TechnoTypeClass;
class xTargetClass;
class UnitTypeClass;
class AnimTypeClass;
class BuildingTypeClass;
class WeaponTypeClass;
class WarheadTypeClass;
class ParticleSystemTypeClass;
class InfantryTypeClass;
class OverlayTypeClass;


typedef enum INIScopeType {
    SCOPE_LOCAL,
    SCOPE_GLOBAL
};

struct TargetStruct {
    long Value;
};

class CCINIClass : public INIClass
{
public:
    CCINIClass();

    int Load(FileClass& file, bool withdigest, bool loadcomments = false);
    int Load(Straw& file, bool withdigest, bool loadcomments = false);
    int Save(FileClass& file, bool withdigest) const;
    int Save(Pipe& pipe, bool withdigest) const;

    LEPTON Get_Lepton(char const* section, char const* entry, LEPTON defvalue) const;
    int Get_Angle(char const* section, char const* entry, int defvalue) const;
    Cell Get_Cell(char const* section, char const* entry, Cell const& defvalue) const;
    MPHType Get_MPHType(char const* section, char const* entry, MPHType defvalue) const;
    PipEnum Get_PipEnum(char const* section, char const* entry, PipEnum defvalue) const;
    PipScaleType Get_PipScaleType(char const* section, char const* entry, PipScaleType defvalue) const;
    CategoryType Get_CategoryType(char const* section, char const* entry, CategoryType defvalue) const;
    TargetStruct Get_xTarget(char const* section, char const* entry, TargetStruct defvalue) const;
    ColorSchemeType Get_Scheme_Index(char const* section, char const* entry, ColorSchemeType defvalue) const;
    RGBClass Get_RGBColor(char const* section, char const* entry, RGBClass const& defvalue) const;
    HSVClass Get_HSVColor(char const* section, char const* entry, HSVClass const& defvalue) const;
    BSizeType Get_BSizeType(char const* section, char const* entry, BSizeType defvalue) const;
    MZoneType Get_MZoneType(char const* section, char const* entry, MZoneType defvalue) const;
    ActionType Get_ActionType(char const* section, char const* entry, ActionType defvalue) const;
    SuperWeaponType Get_SuperWeaponType(char const* section, char const* entry, SuperWeaponType defvalue) const;
    VoxType Get_VoxType(char const* section, char const* entry, VoxType defvalue) const;
    RTTIType Get_RTTIType(char const* section, char const* entry, RTTIType defvalue) const;
    long Get_Owners(char const* section, char const* entry, long defvalue) const;
    ArmorType Get_ArmorType(char const* section, char const* entry, ArmorType defvalue) const;
    VocType Get_VocType(char const* section, char const* entry, VocType defvalue) const;
    LandType Get_LandType(char const* section, char const* entry, LandType defvalue) const;
    HousesType Get_HousesType(char const* section, char const* entry, HousesType defvalue) const;
    SideType Get_SideType(char const* section, char const* entry, SideType defvalue) const;
    VQType Get_VQType(char const* section, char const* entry, VQType defvalue) const;
    TheaterType Get_TheaterType(char const* section, char const* entry, TheaterType defvalue) const;
    ThemeType Get_ThemeType(char const* section, char const* entry, ThemeType defvalue) const;
    SourceType Get_SourceType(char const* section, char const* entry, SourceType defvalue) const;
    CrateType Get_CrateType(char const* section, char const* entry, CrateType defvalue) const;
    long Get_Buildings(char const* section, char const* entry, long defvalue) const;
    TypeList<int> Get_IntList(const char* section, const char* entry, TypeList<int> defvalue) const;
    TypeList<int> Get_GroundForces(const char* section, const char* entry, TypeList<int> defvalue) const; // This is TargetClass encoded value
    TPoint3D<float> Get_Vector(char const* section, char const* entry, TPoint3D<float> const& defvalue) const;
    TPoint3D<int> Get_Offset(char const* section, char const* entry, TPoint3D<int> const& defvalue) const;
    TypeList<TechnoTypeClass*> Get_TechnoType_List(const char* section, const char* entry, TypeList<TechnoTypeClass*> defvalue) const;
    TypeList<int> Get_Houses(const char* section, const char* entry, TypeList<int> defvalue) const;
    TypeList<RGBClass> Get_RGBColors(const char* section, const char* entry, TypeList<RGBClass> defvalue) const;
    TargetClass Get_Target(char const* section, char const* entry, TargetClass const& defvalue) const;
    SpeedType Get_SpeedType(char const* section, char const* entry, SpeedType defvalue) const;
    static TypeList<int> Get_Prerequisites(CCINIClass const& ini, char const* section, char const* entry, TypeList<int> defvalue);
    AbilityFlagsType Get_Abilities(char const* section, char const* entry, AbilityFlagsType const& defvalue) const;
    LayerType Get_LayerType(char const* section, char const* entry, LayerType defvalue) const;

    bool Put_Lepton(char const* section, char const* entry, LEPTON value);
    bool Put_Angle(char const* section, char const* entry, int value);
    bool Put_Cell(char const* section, char const* entry, Cell const& value);
    bool Put_MPHType(char const* section, char const* entry, MPHType value);
    bool Put_PipEnum(char const* section, char const* entry, PipEnum value);
    bool Put_PipScaleType(char const* section, char const* entry, PipScaleType value);
    bool Put_CategoryType(char const* section, char const* entry, CategoryType value);
    bool Put_xTarget(char const* section, char const* entry, TargetStruct value);
    bool Put_Scheme_Index(char const* section, char const* entry, ColorSchemeType value);
    bool Put_RGBColor(char const* section, char const* entry, RGBClass const& value);
    bool Put_HSVColor(char const* section, char const* entry, HSVClass const& value);
    bool Put_BSizeType(char const* section, char const* entry, BSizeType value);
    bool Put_MZoneType(char const* section, char const* entry, MZoneType value);
    bool Put_RTTIType(char const* section, char const* entry, RTTIType value);
    bool Put_Owners(char const* section, char const* entry, long value);
    bool Put_ArmorType(char const* section, char const* entry, ArmorType value);
    bool Put_VocType(char const* section, char const* entry, VocType value);
    bool Put_LandType(char const* section, char const* entry, LandType value);
    bool Put_HousesType(char const* section, char const* entry, HousesType value);
    bool Put_SideType(char const* section, char const* entry, SideType value);
    bool Put_VQType(char const* section, char const* entry, VQType value);
    bool Put_TheaterType(char const* section, char const* entry, TheaterType value);
    bool Put_ThemeType(char const* section, char const* entry, ThemeType value);
    bool Put_SourceType(char const* section, char const* entry, SourceType value);
    bool Put_CrateType(char const* section, char const* entry, CrateType value);
    bool Put_Buildings(char const* section, char const* entry, long value);
    bool Put_VocTypes(char const* section, char const* entry, TypeList<int> value);
    bool Put_IntList(char const* section, char const* entry, TypeList<int> const& value);
    bool Put_GroundForces(const char* section, const char* entry, TypeList<long> const& value);
    bool Put_TechnoType_List(char const* section, char const* entry, TypeList<TechnoTypeClass*> const& value);
    bool Put_Houses(char const* section, char const* entry, TypeList<HousesType> value);
    bool Put_Target(char const* section, char const* entry, TargetClass const& value);
    bool Put_SpeedType(char const* section, char const* entry, SpeedType value);
    bool Put_LayerType(char const* section, char const* entry, LayerType value);

    int Get_Unique_ID() const;

private:
    void Calculate_Message_Digest();
    void Invalidate_Message_Digest();

private:
    bool IsDigestPresent;

    /**
     *  This is the message digest (SHA) of the INI database that was embedded as part of
     *  the INI file.
     */
    unsigned char Digest[20];
};


inline VocType CCINIClass::Get_VocType(char const* section, char const* entry, VocType defvalue) const
{
    char buffer[128];

    if (Get_String(section, entry, "", buffer, sizeof(buffer)) == 0) {
        return defvalue;
    }
    VocType voc = VocClass::From_Name(buffer);
    if (voc == VOC_NONE) {
        return defvalue;
    }
    return voc;
}

TypeList<VocType> Get_VocTypes(CCINIClass const& ini, const char* section, const char* entry, TypeList<VocType> defvalue);
