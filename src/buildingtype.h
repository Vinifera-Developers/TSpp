/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          BUILDINGTYPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for building types.
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

#include "point.h"
#include "rect.h"
#include "technotype.h"
#include "tibsun_defines.h"


class OverlayTypeClass;
class IsometricTileTypeClass;
class UnitTypeClass;


class DECLSPEC_UUID("AE8B33DB-061C-11D2-ACA4-006008055BB5")
BuildingTypeClass : public TechnoTypeClass
{
public:
    /**
     *  IPersist
     */
    IFACEMETHOD(GetClassID)(CLSID* pClassID);

    /**
     *  IPersistStream
     */
    IFACEMETHOD(Load)(IStream* pStm);
    IFACEMETHOD(Save)(IStream* pStm, BOOL fClearDirty);

public:
    BuildingTypeClass(const char* ini_name = nullptr);
    BuildingTypeClass(const NoInitClass& noinit);
    virtual ~BuildingTypeClass();

    /**
     *  AbstractClass
     */
    virtual RTTIType Fetch_RTTI() const override;
    virtual int Get_Object_Size(bool firestorm = false) const override;
    virtual int Get_Object_Size_Delta() const override;
    virtual void Object_CRC(CRCEngine& crc) const override;
    virtual int Fetch_Heap_ID() const override;

    /**
     *  AbstractTypeClass
     */
    virtual bool Read_INI(CCINIClass& ini) override;

    /**
     *  ObjectTypeClass
     */
    virtual Coord Coord_Fixup(Coord* coord) const override;
    virtual int Max_Pips() const override;
    virtual Point3D Pixel_Dimensions() const override;
    virtual Point3D Lepton_Dimensions() const override;
    virtual bool Create_And_Place(Cell& cell, HouseClass* house = nullptr) const override;
    virtual int Cost_Of(HouseClass* house = nullptr) const override;
    virtual ObjectClass* const Create_One_Of(HouseClass* house = nullptr) const override;
    virtual Cell* Occupy_List(bool placement = false) const override;
    virtual ShapeSet* const Get_Image_Data() const override;

    /**
     *  TechnoTypeClass
     */
    virtual bool Legal_Placement(Cell& pos, HouseClass* house = nullptr) const override;
    virtual int Raw_Cost() const override;

    /**
     *  BuildingTypeClass
     */
    virtual ShapeSet* const Get_Buildup_Data();

    int Width() const;
    int Height(bool bib = false) const;
    int Flush_For_Placement(Cell& cell, HouseClass* house) const;

    void Init_Anim(BStateType state, int start, int count, int rate) const;
    void Set_Base_Defense_Values();
    bool Is_Deployable();

    void Fetch_Building_Normal_Image(TheaterType theater);
    void Fetch_Building_Voxel_Image();

    static void One_Time();
    static void Init(TheaterType theater);

    static StructType From_Name(const char* name);
    static const char* Name_From(StructType type);
    static const BuildingTypeClass* Find_Or_Make(const char* name);
    static void Fetch_ToTile_Types();

    static const ShapeSet*& BuildingZShape;

public:
    StructType HeapID;
    Cell* OccupyList;
    ShapeSet* BuildupData;
    TPoint3D<int> HalfDamageSmokeLocation1;
    TPoint3D<int> HalfDamageSmokeLocation2;
    double GateCloseDelay;
    int LightVisibility;
    int LightIntensity;
    int LightRedTint;
    int LightGreenTint;
    int LightBlueTint;
    TPoint2D<int> PrimaryFirePixelOffset;
    TPoint2D<int> SecondaryFirePixelOffset;
    OverlayTypeClass* ToOverlay;
    IsometricTileTypeClass* ToTile;
    char BuildupFilename[12 + 4];
    char PowersUpBuilding[20 + 4];
    UnitTypeClass* FreeUnit;
    FacingType FoundationFace;
    int Adjacent;
    RTTIType ToBuild;
    Coord ExitCoordinate;
    Cell* ExitList;
    Dir256 StartFace;
    int Power;
    int Drain;
    BSizeType Size;
    int ZHeight;
    int MidPoint;
    int DoorStages;

    struct AnimControlStruct {
        int Start;
        int Count;
        int Rate;
    } Anims[BSTATE_COUNT];

    struct Anim2Struct {
        char Anim[12 + 4];
        char AnimDamaged[12 + 4];
        TPoint2D<int> Location;
        char ZAdjust;
        char YSort;
        bool Powered;
        bool PoweredLight;
    } field_580[BANIM_COUNT];

    int Upgrades;
    const ShapeSet* DeployingAnim;
    const ShapeSet* UnderDoorAnim;
    const ShapeSet* DoorAnim;
    const ShapeSet* SpecialZOverlay;
    int SpecialZOverlayZAdjust;
    const ShapeSet* BibShape;
    int NormalZAdjust;
    int AntiAirValue;
    int AntiArmorValue;
    int AntiInfantryValue;
    TPoint2D<int> ZShapePointMove;
    TRect<int> field_7F0;
    short ExtraLight;
    bool IsCanTogglePower;
    bool IsHasSpotlight;
    bool IsTemple;
    bool IsPlug;
    bool IsHoverPad;
    bool IsBase;
    bool IsBibbed;
    bool IsWall;
    bool IsCaptureable;
    bool IsPowered;
    bool IsUnsellable;
    bool IsRadar;
    bool IsHasChargeAnim;
    bool IsSiloDamage;
    bool IsCanUnitRepair;
    bool IsCanUnitReload;
    bool IsFlat;
    bool IsDockUnload;
    bool IsRecoilless;
    bool IsHasStupidGuardMode;
    bool IsBridgeRepairHut;
    bool IsGate;
    bool IsSAM;
    bool IsConstructionYard;
    bool IsNukeSilo;
    bool IsRefinery;
    bool IsWeeder;
    bool IsWeaponsFactory;
    bool IsLaserFencePost;
    bool IsLaserFence;
    bool IsFirestormWall;
    bool IsHospital;
    bool IsArmory;
    bool IsEMPulseCannon;
    bool IsTickTank;
    bool IsTurretAnimAVoxel;
    bool IsCloakGenerator;
    bool IsSensorArray;
    bool IsICBMLauncher;
    bool IsArtillary;
    bool IsHelipad;
    bool IsGDIBarracks;
    bool IsNODBarracks;
    SuperWeaponType SuperWeapon;
    SuperWeaponType SuperWeapon2;
    int GateStages;
    int PowersUpToLevel;
    char VoxelBarrelFile[12 + 4];
    double VoxelBarrelScale;
    const TPoint3D<int> VoxelBarrelOffsetToPitchPivotPoint;
    const TPoint3D<int> VoxelBarrelOffsetToRotatePivotPoint;
    const TPoint3D<int> VoxelBarrelOffsetToBuildingPivotPoint;
    const TPoint3D<int> VoxelBarrelOffsetToBarrelEnd;
    int TurretChargeAnimRate;
    Dir256 StartPitch;
    bool IsLimpetMine;
    bool IsMobileWar;
    bool IsMobileStealth;
    bool IsJuggernaut;
    bool IsCoreDefender;
    bool IsBarrelAnimAVoxel;
    bool IsTurretAnimExclusive;
    bool field_897;
    bool IsDamagedDoor;
    bool IsInvisibleInGame;
    bool IsTerrainPalette;
    bool IsCanPlaceAnywhere;
    bool IsExtraDamageStage;
    bool CanAIBuildThis;
    bool IsBaseDefense;
    char CloakRadiusInCells;
    bool IsDemandLoad;
    bool IsDemandLoadBuildup;
    bool IsFreeBuildup;
    bool IsThreatRatingNode;
    char TheaterImageFile[16 + 4];
};
