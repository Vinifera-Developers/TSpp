/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          WDTTERR.H
 *
 *  @authors       CCHyper
 *
 *  @brief         
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
#include "point.h"


class MSAnim;


class WDTTerritory
{
    public:
        WDTTerritory(); // 00677D50
        ~WDTTerritory(); // 00677DE0

        // 00677DF0 - uknown, creates something ox 0x58.

    public:
        int TerritoryNum; // Looks to be the index of this territory in the array (set by State::NumTerritories).
        unsigned short Seed;
        unsigned char UnitCount;
        unsigned char TechLevel;
        unsigned short StartingCredits;
        unsigned char Width;
        unsigned char Height;
        unsigned char NumPlayers;
        unsigned char Veinholes;
        unsigned char Biome;
        unsigned char Time;
        unsigned char CliffsMin;
        unsigned char CliffsMax;
        unsigned char CliffsDefault;
        unsigned char AccessibilityMin;
        unsigned char AccessibilityMax;
        unsigned char AccessibilityDefault;
        unsigned char HillsMin;
        unsigned char HillsMax;
        unsigned char HillsDefault;
        unsigned char WaterMin;
        unsigned char WaterMax;
        unsigned char WaterDefault;
        unsigned char TiberiumAmountMin;
        unsigned char TiberiumAmountMax;
        unsigned char TiberiumAmountDefault;
        unsigned char Tiberium_Fields_Min;
        unsigned char TiberiumFieldsMax;
        unsigned char TiberiumFieldsDefault;
        unsigned char VegetationMin;
        unsigned char VegetationMax;
        unsigned char VegetationDefault;
        unsigned char CitiesMin;
        unsigned char CitiesMax;
        unsigned char CitiesDefault;

        // TODO confirm
        //unsigned int BitfieldFlags;
        unsigned int TiberiumCreatures : 1;
        unsigned int Allies : 1;
        unsigned int HarvesterTruce : 1;
        unsigned int Bases : 1;
        unsigned int RedeployMCV : 1;
        unsigned int FogOfWar : 1;
        unsigned int DestroyableBridges : 1;
        unsigned int Crates : 1;
        unsigned int BlueTiberium : 1;

        int field_2C; // no idea, possibly bitfield.
};


namespace WorldDominationTour
{
    
    class Territory
    {
        public:
            Territory();
            ~Territory();

        protected:
            int ID;
            char Name[64];
            char Description[128];
            Point2D Target;
            MSAnim *Overlay1;
            MSAnim *Overlay2;
            int field_D4;
    };

};
