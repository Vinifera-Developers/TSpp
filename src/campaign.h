/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CAMPAIGN.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Class for game campaign types.
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

#include "abstracttype.h"
#include "tibsun_defines.h"


class CCINIClass;


class DECLSPEC_UUID("FFDAC848-1517-11D2-8175-006008055BB5")
CampaignClass : public AbstractTypeClass
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
        CampaignClass(const char *ini_name = nullptr);
        CampaignClass(const NoInitClass &noinit);
        virtual ~CampaignClass();

        /**
         *  AbstractClass
         */
        virtual RTTIType Kind_Of() const override;
        virtual int Size_Of(bool firestorm = false) const override;
        virtual void Compute_CRC(WWCRCEngine &crc) const override;

        /**
         *  AbstractTypeClass
         */
        virtual bool Read_INI(CCINIClass &ini) override;

        static int Process(CCINIClass &ini);

        static const CampaignClass &As_Reference(CampaignType type);
        static const CampaignClass *As_Pointer(CampaignType type);
        static const CampaignClass &As_Reference(const char *name);
        static const CampaignClass *As_Pointer(const char *name);
        static CampaignType From_Name(const char *name);
        static const char *Name_From(CampaignType type);
        static const CampaignClass *Find_Or_Make(const char *name);

    public:
        DiskID WhichCD;
        char Scenario[512];
        VQType FinalMovie;
        char Description[128];
        AddonType RequiredAddon;
};
