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
#include "vector.h"


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
class AbstractTypeClass;
class ObjectTypeClass;


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

extern DynamicVectorClass<AbstractTypeClass *> &AbstractTypes;
extern DynamicVectorClass<ObjectTypeClass *> &ObjectTypes;