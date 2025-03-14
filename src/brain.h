/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          BRAIN.H
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

#include "abstract.h"
#include "vector.h"


class NeuronClass;


class BrainClass
{
    public:
        BrainClass();
        virtual ~BrainClass();

        // 0x004255B0
        // 0x004255F0
        // 0x00425640
        // 0x004256B0
        // 0x00425720

    public:
        DynamicVectorClass<NeuronClass *> Neurons;
        NeuronClass * field_1C; // head neuron?
        int Max;
};


class DECLSPEC_UUID("241AB316-4CF5-11D2-BC26-00104B8FB04D")
NeuronClass : public AbstractClass
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
        NeuronClass();
        virtual ~NeuronClass();
        
        /**
         *  AbstractClass
         */
        virtual RTTIType Fetch_RTTI() const override;
        virtual int Get_Object_Size(bool a1 = false) const override;
        virtual void Object_CRC(CRCEngine &crc) const override;

    public:
        void * field_14;
        void * field_18;
        BrainClass *Brain;
        int CreationFrame;
        int field_24;
};
