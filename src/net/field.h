/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          FIELD.H
 *
 *  @author        Philip W. Gorrow (see notes below)
 *
 *  @contributors  CCHyper
 *
 *  @brief         This module takes care of maintaining the field list used
 *                 to process network packets.
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
 *  @note          This file contains heavily modified code from the source code
 *                 released by Electronic Arts for the C&C Remastered Collection
 *                 under the GPL3 license. Source:
 *                 https://github.com/ElectronicArts/CnC_Remastered_Collection
 *
 ******************************************************************************/
#pragma once


#include "always.h"


class PacketClass;


class FieldClass
{
	friend class PacketClass;

	public:
		FieldClass();
		FieldClass(char *id, char data);
		FieldClass(char *id, unsigned char data);
		FieldClass(char *id, short data);
		FieldClass(char *id, unsigned short data);
		FieldClass(char *id, long data);
		FieldClass(char *id, unsigned long data);
		FieldClass(char *id, char *data);
		FieldClass(char *id, void *data, int length);
		~FieldClass();

		void Host_To_Net();
		void Net_To_Host();

	private:
		char ID[4];
		unsigned short DataType;
		unsigned short Size;
		void *Data;
		FieldClass *Next;
};
