/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          ABSTRACTTYPE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Base class for all type objects.
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


class CCINIClass;


class AbstractTypeClass : public AbstractClass
{
    public:
        AbstractTypeClass(const char *ini_name = nullptr);
        AbstractTypeClass(const NoInitClass &noinit);
        virtual ~AbstractTypeClass();

        bool operator==(const char *their_name) const { return strcasecmp(IniName, their_name) == 0; }
        bool operator!=(const char *their_name) const { return strcasecmp(IniName, their_name) != 0; }

        /**
         *  AbstractClass
         */
        virtual void Object_CRC(CRCEngine &crc) const override;

        /**
         *  AbstractTypeClass
         */
        virtual void entry_64();
        virtual bool Read_INI(CCINIClass &ini);
        virtual bool Write_INI(CCINIClass &ini) const;

		char const * Name() const { return IniName; }
		void Set_Name(const char * buf) const
		{
			std::strncpy((char *)IniName, buf, sizeof(IniName));
			((char &)IniName[sizeof(IniName)-1]) = '\0';
		};

        char const * Full_Name() const { return FullName; }

    public:
        char IniName[24 + 1];
        char FullName[48 + 1];

    private:
        // Copy and assignment not implemented; prevent their use by declaring as private.
        AbstractTypeClass(const AbstractTypeClass &);
        AbstractTypeClass &operator=(const AbstractTypeClass &);
};
