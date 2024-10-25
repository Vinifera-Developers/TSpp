/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          LIGHTSOURCE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Light sources on the map.
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

#include "abstract.h"
#include "tibsun_defines.h"


class LightConvertClass;


class DECLSPEC_UUID("6F9C48F0-1207-11D2-8174-006008055BB5")
LightSourceClass : public AbstractClass
{
public:
    class PendingCellClass
    {
        public:
            PendingCellClass() :
                Drawer(nullptr),
                Intensity(65536),
                Ambient(0),
                RedTint(1000),
                GreenTint(1000),
                BlueTint(1000),
                Cell(0)
            {
            }

            ~PendingCellClass()
            {
            }

        public:
            LightConvertClass *Drawer;
            int Intensity;
            int Ambient;
            short RedTint;
            short GreenTint;
            short BlueTint;
            Cell Cell;
    };

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
    LightSourceClass();
    LightSourceClass(Coordinate coord, int visibility, int intensity, int red, int green, int blue);
    LightSourceClass(const NoInitClass &noinit);
    virtual ~LightSourceClass();
    
    /**
     *  AbstractClass
     */
    virtual RTTIType Kind_Of() const override;
    virtual int Size_Of(bool firestorm = false) const override;
    virtual void Compute_CRC(WWCRCEngine &crc) const override;

    void Enable(bool update = false);
    void Disable(bool update = false);
    void Process();

    const char *Name() const;

    static void Init_Clear();
    // 00501950

public:
    int Intensity;
    int RedTint;
    int GreenTint;
    int BlueTint;
    Coordinate Where;
    int Visibility;
    bool IsEnabled;

public:
    static bool& UpdateAllowed;

};


/**
 *  This must be here because we can't forward declare nested classes.
 */
extern DynamicVectorClass<LightSourceClass::PendingCellClass *> &PendingLightCells;
