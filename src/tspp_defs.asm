;/*******************************************************************************
;/*                     O P E N  S O U R C E  --  T S + +                      **
;/*******************************************************************************
; *
; *  @project       TS++
; *
; *  @file          TSPP_DEFINITIONS.ASM
; *
; *  @authors       CCHyper
; *
; *  @brief         Function definitions for the TS++ project.
; *
; *  @license       TS++ is free software: you can redistribute it and/or
; *                 modify it under the terms of the GNU General Public License
; *                 as published by the Free Software Foundation, either version
; *                 3 of the License, or (at your option) any later version.
; *
; *                 TS++ is distributed in the hope that it will be
; *                 useful, but WITHOUT ANY WARRANTY; without even the implied
; *                 warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
; *                 PURPOSE. See the GNU General Public License for more details.
; *
; *                 You should have received a copy of the GNU General Public
; *                 License along with this program.
; *                 If not, see <http://www.gnu.org/licenses/>.
; *
; ******************************************************************************/

.586
.model flat, C
option casemap :none
option prologue:none
option epilogue:none
option language: basic ; invalid language removes leading "_" from output name.


;
;  This file mostly contains the constructors what we need to jump to
;  without any additional code being rolled out.
;

.code

;
;  Implementation macro.
;
ASM_DEFINE_IMPLEMENTATION macro name, address
    name proc
        mov eax, address
        jmp eax
        ; ECHO Warning: MakeName("0x&address", "&name")
    name endp
    align 10h
endm


ASM_DEFINE_IMPLEMENTATION ??0AbstractTypeClass@@QAE@PBD@Z 004061D0h
ASM_DEFINE_IMPLEMENTATION ??0AbstractTypeClass@@QAE@ABVNoInitClass@@@Z 00406310h
ASM_DEFINE_IMPLEMENTATION ??0SideClass@@QAE@PBD@Z 005F1A30h
ASM_DEFINE_IMPLEMENTATION ??0ScriptClass@@QAE@PAVScriptTypeClass@@@Z 005F1A30h
ASM_DEFINE_IMPLEMENTATION ??0ScriptTypeClass@@QAE@PBD@Z 005E7AC0h
ASM_DEFINE_IMPLEMENTATION ??0ObjectTypeClass@@QAE@PBD@Z 00587620h
ASM_DEFINE_IMPLEMENTATION ??0ObjectTypeClass@@QAE@ABVNoInitClass@@@Z 00587810h
ASM_DEFINE_IMPLEMENTATION ??0TechnoTypeClass@@QAE@PBDW4SpeedType@@@Z 0063ADE0h
ASM_DEFINE_IMPLEMENTATION ??0TechnoTypeClass@@QAE@ABVNoInitClass@@@Z 0063B480h
ASM_DEFINE_IMPLEMENTATION ??0BuildingTypeClass@@QAE@PBD@Z 0043F410h
ASM_DEFINE_IMPLEMENTATION ??0BuildingTypeClass@@QAE@ABVNoInitClass@@@Z 0043F8C0h
ASM_DEFINE_IMPLEMENTATION ??0ConvertClass@@QAE@PAVPaletteClass@@0PAVXSurface@@H_N@Z 00463C40h
ASM_DEFINE_IMPLEMENTATION ??0LightConvertClass@@QAE@PAVPaletteClass@@0PAVSurface@@HHH_NPA_NH@Z 00502A00h
ASM_DEFINE_IMPLEMENTATION ??0IsometricTileTypeClass@@QAE@W4IsometricTileType@@DDPBD_N@Z 004F30A0h
ASM_DEFINE_IMPLEMENTATION ??0IsometricTileTypeClass@@QAE@ABVNoInitClass@@@Z 004F32D0h
ASM_DEFINE_IMPLEMENTATION ??0HouseTypeClass@@QAE@PBD@Z 004CDD10h
ASM_DEFINE_IMPLEMENTATION ??0HouseTypeClass@@QAE@ABVNoInitClass@@@Z 004CDE60h
ASM_DEFINE_IMPLEMENTATION ??0UnitTypeClass@@QAE@PBD@Z 0065B8F0h
ASM_DEFINE_IMPLEMENTATION ??0UnitTypeClass@@QAE@ABVNoInitClass@@@Z 0065BAA0h
ASM_DEFINE_IMPLEMENTATION ??0InfantryTypeClass@@QAE@PBD@Z 004DA1E0h
ASM_DEFINE_IMPLEMENTATION ??0InfantryTypeClass@@QAE@ABVNoInitClass@@@Z 004DA370h
ASM_DEFINE_IMPLEMENTATION ??0AircraftTypeClass@@QAE@PBD@Z 0040FBC0h
ASM_DEFINE_IMPLEMENTATION ??0AircraftTypeClass@@QAE@ABVNoInitClass@@@Z 0040FCA0h
ASM_DEFINE_IMPLEMENTATION ??0VoxelAnimTypeClass@@QAE@PBD@Z 0065F3B0h
ASM_DEFINE_IMPLEMENTATION ??0WeaponTypeClass@@QAE@PBD@Z 00680A60h
ASM_DEFINE_IMPLEMENTATION ??0WeaponTypeClass@@QAE@ABVNoInitClass@@@Z 00680C00h
ASM_DEFINE_IMPLEMENTATION ??0BulletTypeClass@@QAE@PBD@Z 00447BC0h
ASM_DEFINE_IMPLEMENTATION ??0BulletTypeClass@@QAE@ABVNoInitClass@@@Z 00447D90h
ASM_DEFINE_IMPLEMENTATION ??0CellClass@@QAE@XZ 004517C0h
ASM_DEFINE_IMPLEMENTATION ??0CellClass@@QAE@ABVNoInitClass@@@Z 00450F60h
ASM_DEFINE_IMPLEMENTATION ??0WarheadTypeClass@@QAE@PBD@Z 0066ED40h
ASM_DEFINE_IMPLEMENTATION ??0WarheadTypeClass@@QAE@ABVNoInitClass@@@Z 0066EF00h
ASM_DEFINE_IMPLEMENTATION ??0Tactical@@QAE@XZ 0060EEC0h
ASM_DEFINE_IMPLEMENTATION ??0Tactical@@QAE@ABVNoInitClass@@@Z 0060F090h
ASM_DEFINE_IMPLEMENTATION ??0OverlayTypeClass@@QAE@PBD@Z 0058CFF0h
ASM_DEFINE_IMPLEMENTATION ??0OverlayTypeClass@@QAE@ABVNoInitClass@@@Z 0058D140h
ASM_DEFINE_IMPLEMENTATION ??0SuperWeaponTypeClass@@QAE@PBD@Z 0060CF70h
ASM_DEFINE_IMPLEMENTATION ??0SuperWeaponTypeClass@@QAE@ABVNoInitClass@@@Z 0060D060h
ASM_DEFINE_IMPLEMENTATION ??0HouseClass@@QAE@PBVHouseTypeClass@@@Z 004BA0B0h
ASM_DEFINE_IMPLEMENTATION ??0HouseClass@@QAE@ABVNoInitClass@@@Z 004B9EF0h
ASM_DEFINE_IMPLEMENTATION ??0ObjectClass@@QAE@XZ 005847D0h
ASM_DEFINE_IMPLEMENTATION ??0ObjectClass@@QAE@ABVNoInitClass@@@Z 005849A0h
ASM_DEFINE_IMPLEMENTATION ??0MissionClass@@QAE@XZ 00558E40h
ASM_DEFINE_IMPLEMENTATION ??0MissionClass@@QAE@ABVNoInitClass@@@Z 0063A600h
ASM_DEFINE_IMPLEMENTATION ??0TechnoClass@@QAE@PAVHouseClass@@@Z 00629CB0h
ASM_DEFINE_IMPLEMENTATION ??0TechnoClass@@QAE@ABVNoInitClass@@@Z 0062A7F0h
ASM_DEFINE_IMPLEMENTATION ??0FootClass@@QAE@PAVHouseClass@@@Z 004A00F0h
ASM_DEFINE_IMPLEMENTATION ??0FootClass@@QAE@ABVNoInitClass@@@Z 004A0390h
ASM_DEFINE_IMPLEMENTATION ??0BuildingClass@@QAE@PAVBuildingTypeClass@@PAVHouseClass@@@Z 00426190h
ASM_DEFINE_IMPLEMENTATION ??0BuildingClass@@QAE@AAVNoInitClass@@@Z 00426140h
ASM_DEFINE_IMPLEMENTATION ??0TeamTypeClass@@QAE@PBD@Z 00627D90h
ASM_DEFINE_IMPLEMENTATION ??0TeamClass@@QAE@PAVTeamTypeClass@@PAVHouseClass@@PAX@Z 00622100h
ASM_DEFINE_IMPLEMENTATION ??0TaskForceClass@@QAE@PBD@Z 00621420h
ASM_DEFINE_IMPLEMENTATION ??0TaskForceClass@@QAE@ABVNoInitClass@@@Z 006214D0h
ASM_DEFINE_IMPLEMENTATION ??0AircraftClass@@QAE@PAVAircraftTypeClass@@PAVHouseClass@@@Z 004085D0h
ASM_DEFINE_IMPLEMENTATION ??0InfantryClass@@QAE@PAVInfantryTypeClass@@PAVHouseClass@@@Z 004D1FD0h
ASM_DEFINE_IMPLEMENTATION ??0AnimClass@@QAE@XZ 00414170h
ASM_DEFINE_IMPLEMENTATION ??0AnimClass@@QAE@PBVAnimTypeClass@@AAUCoordStruct@@IIIH@Z 00413AE0h
ASM_DEFINE_IMPLEMENTATION ??0AnimTypeClass@@QAE@PBD@Z 004184C0h
ASM_DEFINE_IMPLEMENTATION ??0AnimTypeClass@@QAE@ABVNoInitClass@@@Z 004187A0h
ASM_DEFINE_IMPLEMENTATION ??0TerrainTypeClass@@QAE@PBD@Z 006414E0h
ASM_DEFINE_IMPLEMENTATION ??0TerrainTypeClass@@QAE@ABVNoInitClass@@@Z 00641620h
ASM_DEFINE_IMPLEMENTATION ??0ParticleTypeClass@@QAE@PBD@Z 005AEF00h
ASM_DEFINE_IMPLEMENTATION ??0ParticleTypeClass@@QAE@ABVNoInitClass@@@Z 005AF0E0h
ASM_DEFINE_IMPLEMENTATION ??0ParticleSystemTypeClass@@QAE@PBD@Z 005AE3D0h
ASM_DEFINE_IMPLEMENTATION ??0ParticleSystemTypeClass@@QAE@ABVNoInitClass@@@Z 005AE540h
ASM_DEFINE_IMPLEMENTATION ??0VoxelAnimClass@@QAE@XZ 0065DE30h
ASM_DEFINE_IMPLEMENTATION ??0VoxelAnimClass@@QAE@PBVVoxelAnimTypeClass@@AAUCoordStruct@@PAVHouseClass@@@Z 0065D950h
ASM_DEFINE_IMPLEMENTATION ??0AITriggerTypeClass@@QAE@PBD@Z 004104E0h
ASM_DEFINE_IMPLEMENTATION ??0TagTypeClass@@QAE@PBD@Z 0061F030h
ASM_DEFINE_IMPLEMENTATION ??0BuildingLightClass@@QAE@PAVTechnoClass@@@Z 00421AE0h
ASM_DEFINE_IMPLEMENTATION ??0LightSourceClass@@QAE@XZ 00501510h
ASM_DEFINE_IMPLEMENTATION ??0LightSourceClass@@QAE@UCoordStruct@@HHHHH@Z 00501460h
ASM_DEFINE_IMPLEMENTATION ??0SmudgeTypeClass@@QAE@PBD@Z 005FB1E0h
ASM_DEFINE_IMPLEMENTATION ??0SmudgeTypeClass@@QAE@ABVNoInitClass@@@Z 005FB2E0h
ASM_DEFINE_IMPLEMENTATION ??0FactoryClass@@QAE@XZ 00496C60h
ASM_DEFINE_IMPLEMENTATION ??0SmudgeClass@@QAE@PAVSmudgeTypeClass@@AAUCoordStruct@@W4HousesType@@@Z 005FA9E0h
ASM_DEFINE_IMPLEMENTATION ??0OverlayClass@@QAE@PAVOverlayTypeClass@@AAUCellStruct@@W4HousesType@@@Z 0058B460h
ASM_DEFINE_IMPLEMENTATION ??0TiberiumClass@@QAE@PBD@Z 00644890h
ASM_DEFINE_IMPLEMENTATION ??0BulletClass@@QAE@XZ 004444A0h
ASM_DEFINE_IMPLEMENTATION ??0UnitClass@@QAE@PAVUnitTypeClass@@PAVHouseClass@@@Z 0064D4B0h
ASM_DEFINE_IMPLEMENTATION ??0TerrainClass@@QAE@XZ 0063F710h
ASM_DEFINE_IMPLEMENTATION ??0TerrainClass@@QAE@PAVTerrainTypeClass@@AAUCellStruct@@@Z 0063F500h
ASM_DEFINE_IMPLEMENTATION ??0TriggerTypeClass@@QAE@PBD@Z 00649CA0h
ASM_DEFINE_IMPLEMENTATION ??0TriggerClass@@QAE@PAVTriggerTypeClass@@@Z 00649040h
ASM_DEFINE_IMPLEMENTATION ??0TagClass@@QAE@PAVTagTypeClass@@@Z 0061E330h
ASM_DEFINE_IMPLEMENTATION ??0CampaignClass@@QAE@PBD@Z 00448A10h
ASM_DEFINE_IMPLEMENTATION ??0WaveClass@@QAE@XZ 006700B0h
ASM_DEFINE_IMPLEMENTATION ??0WaveClass@@QAE@AAUCoordStruct@@0PAVAbstractClass@@W4WaveType@@1@Z 0066FDE0h
ASM_DEFINE_IMPLEMENTATION ??0ParticleClass@@QAE@XZ 005A3170h
ASM_DEFINE_IMPLEMENTATION ??0ParticleClass@@QAE@PAVParticleTypeClass@@AAUCoordStruct@@1PAVParticleSystemClass@@@Z 005A2C90h
ASM_DEFINE_IMPLEMENTATION ??0ParticleSystemClass@@QAE@XZ 005A5580h
ASM_DEFINE_IMPLEMENTATION ??0ParticleSystemClass@@QAE@PAVParticleSystemTypeClass@@AAUCoordStruct@@PAVAbstractClass@@21@Z 005A5300h
ASM_DEFINE_IMPLEMENTATION ??0IsometricTileClass@@QAE@W4IsometricTileType@@AAUCellStruct@@@Z 004F2070h
ASM_DEFINE_IMPLEMENTATION ??0TubeClass@@QAE@AAUCellStruct@@W4FacingType@@@Z 0064AED0h
ASM_DEFINE_IMPLEMENTATION ??0SessionClass@@QAE@XZ 005ECD00h
ASM_DEFINE_IMPLEMENTATION ??0UDPInterfaceClass@@QAE@XZ 006A1E70h
ASM_DEFINE_IMPLEMENTATION ??0EnumConnectionPointsClass@@QAE@XZ 0046FC70h
ASM_DEFINE_IMPLEMENTATION ??0EnumConnectionPointsClass@@QAE@ABV?$DynamicVectorClass@PAUIConnectionPoint@@@@@Z 0046FD30h
ASM_DEFINE_IMPLEMENTATION ??0ThemeClass@@QAE@XZ 00643D60h
ASM_DEFINE_IMPLEMENTATION ??0ToolTipManager@@QAE@PAUHWND__@@@Z 00647190h
ASM_DEFINE_IMPLEMENTATION ??0WinsockInterfaceClass@@QAE@XZ 006A0EB0h
ASM_DEFINE_IMPLEMENTATION ??0LoadOptionsClass@@QAE@XZ 005047B0h
ASM_DEFINE_IMPLEMENTATION ??0MapClass@@QAE@XZ 0050EAD0h
ASM_DEFINE_IMPLEMENTATION ??0MapClass@@QAE@ABVNoInitClass@@@Z 0050EBE0h
ASM_DEFINE_IMPLEMENTATION ??0WaypointPathClass@@QAE@XZ 006733D0h
ASM_DEFINE_IMPLEMENTATION ??0WaypointPathClass@@QAE@H@Z 006734A0h
ASM_DEFINE_IMPLEMENTATION ??0WaypointPathClass@@QAE@ABVNoInitClass@@@Z 00673470h
ASM_DEFINE_IMPLEMENTATION ??0RadarClass@@QAE@XZ 005B8830h
ASM_DEFINE_IMPLEMENTATION ??0ConnectionPointClass@@QAE@ABU_GUID@@PAUIUnknown@@@Z 0046F8C0h
ASM_DEFINE_IMPLEMENTATION ??0EnumConnectionsClass@@QAE@ABV?$DynamicVectorClass@UtagCONNECTDATA@@@@@Z 0046F300h
ASM_DEFINE_IMPLEMENTATION ??0EnumConnectionsClass@@QAE@ABV0@@Z 0046F3D0h
ASM_DEFINE_IMPLEMENTATION ??0SwizzleManagerClass@@QAE@XZ 0060D9B0h
ASM_DEFINE_IMPLEMENTATION ??0ScenarioClass@@QAE@XZ 005DABC0h
ASM_DEFINE_IMPLEMENTATION ??0RulesClass@@QAE@XZ 005C4350h
ASM_DEFINE_IMPLEMENTATION ??0RulesClass@@QAE@ABVNoInitClass@@@Z 005C3E00h


end
