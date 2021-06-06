/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TIBSUN_GLOBALS.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Main header file which contains all the games globals.
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

#include "always.h"
#include "tibsun_defines.h"
#include "vector.h"
#include "search.h"
#include "queue.h"
#include "ttimer.h"
#include "ccfile.h"


/**
 *  This head contains all the game globals.
 * 
 *  #NOTE: Do not include any module here directly!
 */


/**
 *  Forward declarations.
 */
class WWKeyboardClass;
class OptionsClass;
class SpecialClass;
class RulesClass;
class WWMouseClass;
class DSurface;
class Random2Class;
class ScenarioClass;
class SessionClass;
class SwizzleManagerClass;
class ConvertClass;
class ToolTipManager;
class VersionClass;
class CDControlClass;
class WWFontClass;
class WinsockInterfaceClass;
class LightConvertClass;
class AbstractTypeClass;
class ObjectTypeClass;
class TechnoTypeClass;
class BuildingTypeClass;
class IsometricTileTypeClass;
class Tactical;
class LogicClass;
class MouseClass;
class DirectSoundAudioClass;
class ThemeClass;
class HouseTypeClass;
class UnitTypeClass;
class InfantryTypeClass;
class AircraftTypeClass;
class VoxelAnimTypeClass;
class WeaponTypeClass;
class BulletTypeClass;
class WarheadTypeClass;
class OverlayTypeClass;
class SpotlightClass;
class CommandClass;
struct VQHandle;
class SuperClass;
class SuperWeaponTypeClass;
class HouseClass;
class SideClass;
class ScriptClass;
class ScriptTypeClass;
class ObjectClass;
class TechnoClass;
class FootClass;
class BuildingClass;
class TeamTypeClass;
class TeamClass;
class TEventClass;
class TActionClass;
class TaskForceClass;
class AircraftClass;
class VocClass;
class IonBlastClass;
class AnimClass;
class AnimTypeClass;
class TerrainTypeClass;
class ParticleTypeClass;
class ParticleSystemTypeClass;
class VoxelAnimClass;
class AITriggerTypeClass;
class TagTypeClass;
class BuildingLightClass;
class LightSourceClass;
class SmudgeTypeClass;
class FactoryClass;
class SmudgeClass;
class OverlayClass;
class TiberiumClass;
class BulletClass;
class UnitClass;
class TerrainClass;
class TriggerTypeClass;
class TriggerClass;
class TagClass;
class WaypointPathClass;
class CampaignClass;
class WaveClass;
class ParticleClass;
class ParticleSystemClass;
class IsometricTileClass;
class RadarEventClass;
class InfantryClass;
class EventClass;
class MouseClass;
class Rect;
class PaletteClass;
class PKey;
class CCINIClass;
class SystemTimerClass;

enum KeyNumType;


/**
 *  Global externs (should be defined in tspp_defintions.cpp).
 */
extern WWKeyboardClass *&WWKeyboard;
extern OptionsClass &Options;
extern SpecialClass &Special;
extern RulesClass *&Rule;
extern WWMouseClass *&WWMouse;
extern DSurface *&TileSurface;
extern DSurface *&SidebarSurface;
extern DSurface *&PrimarySurface;
extern DSurface *&HiddenSurface;
extern DSurface *&AlternateSurface;
extern DSurface *&TempSurface;
extern DSurface *&CompositeSurface;
extern Random2Class &NonCriticalRandomNumber;
extern long &Frame;
extern ScenarioClass *&Scen;
extern SessionClass &Session;
extern SwizzleManagerClass &SwizzleManager;
extern ConvertClass *&CameoDrawer;
extern ConvertClass *&ObjectDrawer;
extern ConvertClass *&VoxelDrawer;
extern ConvertClass *&TiberiumDrawer;
extern ConvertClass *&AnimDrawer;
extern ConvertClass *&NormalDrawer;
extern ConvertClass *&MouseDrawer;
extern ConvertClass *&SidebarDrawer;
extern ToolTipManager *&ToolTipHandler;
extern VersionClass &VerNum;
extern CDControlClass &CDControl;
extern WWFontClass *&Metal12FontPtr;
extern WWFontClass *&MapFontPtr;
extern WWFontClass *&Font6Ptr;
extern WWFontClass *&EditorFont;
extern WWFontClass *&Font8Ptr;
extern WWFontClass *&GradFont6Ptr;
extern WinsockInterfaceClass *&PacketTransport;
extern Tactical *&TacticalMap;
extern LogicClass &Logic;
extern MouseClass &Map;
extern DirectSoundAudioClass &Audio;
extern ThemeClass &Theme;
extern HWND &MainWindow;
extern HINSTANCE &ProgramInstance;
extern unsigned &ExceptionReturnBase;
extern unsigned &ExceptionReturnStack;
extern unsigned &ExceptionReturnAddress;
extern bool &CatchExceptions;
extern bool &Debug_Windowed;
extern bool &Debug_ScenarioFilenameSet;
extern char *Debug_ScenarioFilename; // [128]
extern bool &Debug_MotionCapture;
extern bool &Debug_AllowModeToggle;
extern bool &Debug_Quiet;
extern bool &Debug_Cheat;
extern bool &Debug_Remap;
extern bool &Debug_Icon;
extern bool &Debug_Flag;
extern bool &Debug_Lose;
extern bool &Debug_Win;
extern bool &Debug_Map;
extern bool &Debug_Passable;
extern bool &Debug_Unshroud;
extern bool &Debug_Threat;
extern bool &Debug_Find_Path;
extern bool &Debug_Check_Map;
extern bool &Debug_Playtest;
extern bool &Debug_Trap_Check_Heap;
extern bool &Debug_Modem_Dump;
extern bool &Debug_Print_Events;
extern HouseClass *&PlayerPtr;
extern Rect &SidebarRect;
extern Rect &TacticalRect;
extern Rect &ScreenRect;
extern unsigned &Seed;
extern unsigned &CustomSeed;
extern bool &UserInputLocked;
extern int &ScenarioInit;
extern bool &AllowVoice;
extern PaletteClass &BlackPalette;
extern PaletteClass &WaypointPalette;
extern PaletteClass &CCPalette;
extern PaletteClass &GamePalette;
extern PaletteClass &InGamePalette;
extern PaletteClass &WhitePalette;
extern PaletteClass &OriginalPalette;
extern PaletteClass &UnitPalette;
extern PaletteClass &VoxelPalette;
extern PKey &FastKey;
extern CCINIClass *&RuleINI;
extern CCINIClass &ConfigINI;
extern CCINIClass &AIINI;
extern CCINIClass &ArtINI;
extern CCINIClass &FSAIINI;
extern CCINIClass &FSRuleINI;
extern CDTimerClass<SystemTimerClass> &NetFrameTimer;
extern TTimerClass<SystemTimerClass> &TickCount;
extern CDTimerClass<SystemTimerClass> &FrameTimer;
extern DynamicVectorClass<MFCC *> &ExpansionMixFiles;
extern DynamicVectorClass<MFCC *> &SideMixFiles;
extern MFCC *&MultiMix;
extern MFCC *&TibSunMix;
extern MFCC *&TheaterMix;
extern MFCC *&TheaterCachedMix;
extern MFCC *&TheaterIsoMix;
extern MFCC *&MoviesMix;
extern MFCC *&ScoreMix;
extern MFCC *&MainMix;
extern MFCC *&ConquerMix;
extern MFCC *&CacheMix;
extern MFCC *&LocalMix;
extern MFCC *&MapsMix;
extern MFCC *&SpeechMix;
extern MFCC *&SoundsMix;
extern MFCC *&FSSoundsMix;
extern MFCC *&FSScoresMix;
extern MFCC *&SideCachedMix;
extern MFCC *&SideNotCachedMix;
extern MFCC *&SideCDMix;
extern bool &Cheat_Pengo;
extern bool &Cheat_TheTeam;
extern int &NewINIFormat;
extern bool &GameInFocus;
extern ParticleSystemClass *&GasCloudSys;

extern DynamicVectorClass<AbstractTypeClass *> &AbstractTypes;
extern DynamicVectorClass<ObjectTypeClass *> &ObjectTypes;
extern DynamicVectorClass<TechnoTypeClass *> &TechnoTypes;
extern DynamicVectorClass<BuildingTypeClass *> &BuildingTypes;
extern DynamicVectorClass<ConvertClass *> &Converts;
extern DynamicVectorClass<LightConvertClass *> &TileDrawers;
extern DynamicVectorClass<IsometricTileTypeClass *> &IsoTileTypes;
extern DynamicVectorClass<HouseTypeClass *> &HouseTypes;
extern DynamicVectorClass<UnitTypeClass *> &UnitTypes;
extern DynamicVectorClass<InfantryTypeClass *> &InfantryTypes;
extern DynamicVectorClass<AircraftTypeClass *> &AircraftTypes;
extern DynamicVectorClass<VoxelAnimTypeClass *> &VoxelAnimTypes;
extern DynamicVectorClass<WeaponTypeClass *> &WeaponTypes;
extern DynamicVectorClass<BulletTypeClass *> &BulletTypes;
extern DynamicVectorClass<WarheadTypeClass *> &WarheadTypes;
extern DynamicVectorClass<OverlayTypeClass *> &OverlayTypes;
extern DynamicVectorClass<SpotlightClass *> &Spotlights;
extern DynamicVectorClass<CommandClass *> &Commands;
extern DynamicVectorClass<VQHandle *> &IngameVQ;
extern DynamicVectorClass<SuperClass *> &Supers;
extern DynamicVectorClass<SuperWeaponTypeClass *> &SuperWeaponTypes;
extern DynamicVectorClass<HouseClass *> &Houses;
extern DynamicVectorClass<SideClass *> &Sides;
extern DynamicVectorClass<ScriptClass *> &Scripts;
extern DynamicVectorClass<ScriptTypeClass *> &ScriptTypes;
extern DynamicVectorClass<ObjectClass *> &Objects;
extern DynamicVectorClass<TechnoClass *> &Technos;
extern DynamicVectorClass<FootClass *> &Foots;
extern DynamicVectorClass<BuildingClass *> &Buildings;
extern DynamicVectorClass<TeamTypeClass *> &TeamTypes;
extern DynamicVectorClass<TeamClass *> &Teams;
extern DynamicVectorClass<TEventClass *> &TEvents;
extern DynamicVectorClass<TActionClass *> &TActions;
extern DynamicVectorClass<TaskForceClass *> &TaskForces;
extern DynamicVectorClass<AircraftClass *> &Aircrafts;
extern DynamicVectorClass<VocClass *> &Vocs;
extern DynamicVectorClass<IonBlastClass *> &IonBlasts;
extern DynamicVectorClass<AnimClass *> &Anims;
extern DynamicVectorClass<AnimTypeClass *> &AnimTypes;
extern DynamicVectorClass<TerrainTypeClass *> &TerrainTypes;
extern DynamicVectorClass<ParticleTypeClass *> &ParticleTypes;
extern DynamicVectorClass<ParticleSystemTypeClass *> &ParticleSystemTypes;
extern DynamicVectorClass<VoxelAnimClass *> &VoxelAnims;
extern DynamicVectorClass<AITriggerTypeClass *> &AITriggerTypes;
extern DynamicVectorClass<TagTypeClass *> &TagTypes;
extern DynamicVectorClass<BuildingLightClass *> &BuildingLights;
extern DynamicVectorClass<LightSourceClass *> &LightSources;
//extern DynamicVectorClass<LightSourceClass::PendingCellClass *> &PendingLightCells; // See lightsource.h
extern DynamicVectorClass<SmudgeTypeClass *> &SmudgeTypes;
extern DynamicVectorClass<FactoryClass *> &Factories;
extern DynamicVectorClass<SmudgeClass *> &Smudges;
extern DynamicVectorClass<OverlayClass *> &Overlays;
extern DynamicVectorClass<TiberiumClass *> &Tiberiums;
extern DynamicVectorClass<BulletClass *> &Bullets;
extern DynamicVectorClass<UnitClass *> &Units;
extern DynamicVectorClass<TerrainClass *> &Terrains;
extern DynamicVectorClass<TriggerTypeClass *> &TriggerTypes;
extern DynamicVectorClass<TriggerClass *> &Triggers;
extern DynamicVectorClass<TagClass *> &Tags;
extern DynamicVectorClass<WaypointPathClass *> &WaypointPaths;
extern DynamicVectorClass<CampaignClass *> &Campaigns;
extern DynamicVectorClass<WaveClass *> &Waves;
extern DynamicVectorClass<ParticleClass *> &Particles;
extern DynamicVectorClass<ParticleSystemClass *> &ParticleSystems;
extern DynamicVectorClass<IsometricTileClass *> &IsoTiles;
extern DynamicVectorClass<RadarEventClass *> &RadarEvents;
extern DynamicVectorClass<InfantryClass *> &Infantry;

extern DynamicVectorClass<ObjectClass *> &CurrentObjects;

extern DynamicVectorClass<TARGET> &vec_80F5E0;
extern DynamicVectorClass<TARGET> &vec_80F4C0;
extern DynamicVectorClass<TARGET> &vec_80F588;
extern DynamicVectorClass<TARGET> &vec_80F558;
extern DynamicVectorClass<TARGET> &vec_80F4E0;
extern DynamicVectorClass<TARGET> &vec_80F620;
extern DynamicVectorClass<TARGET> &vec_80F528;
extern DynamicVectorClass<TARGET> &vec_80F570;
extern DynamicVectorClass<TARGET> &vec_80F4F8;
extern DynamicVectorClass<TARGET> &vec_80F600;

extern DynamicVectorClass<ULONG> &ClassFactories;

extern IndexClass<KeyNumType, CommandClass *> &HotkeyIndex;

extern QueueClass<EventClass, MAX_EVENTS> &OutList;
extern QueueClass<EventClass, (MAX_EVENTS * 64)> &DoList;

extern const TheaterDataType *Theaters; 
