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
class EventClass;

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
extern LogicClass *&Logic;
extern MouseClass &Map;
extern DirectSoundAudioClass &Audio;
extern ThemeClass &Theme;

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

extern IndexClass<KeyNumType, CommandClass *> &HotkeyIndex;

extern QueueClass<EventClass, MAX_EVENTS> &OutList;
extern QueueClass<EventClass, (MAX_EVENTS * 64)> &DoList;
