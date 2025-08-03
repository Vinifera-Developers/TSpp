/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          IBLOCKCIPHER.H
 *
 *  @authors       CCHyper
 *
 *  @brief         IBlockCipher interface.
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
#include <unknwn.h>


/*******************************************************************************
 *  @class   IBlockCipher
 *
 *  @brief   Block encryptor/decryptor interface.
 */
DECLARE_INTERFACE_IID_(IBlockCipher, IUnknown, "E0113100-6A7C-11D1-B6F9-00A024DDAFD1")
{
    /**
     *  Sets encryption/decryption key.
     */
    STDMETHOD(Submit_Key)(int length, void* key) PURE;

    /**
     *  Maximum key length allowed.
     */
    STDMETHOD(Max_Key_Length)(LONG* key_length) PURE;

    /**
     *  Size of encryption block.
     */
    STDMETHOD(Block_Size)(LONG* key_length) PURE;

    /**
     *  Encrypt data buffer.
     */
    STDMETHOD(Encrypt)(int length, void* plain_text, void* cypher_text) PURE;

    /**
     *  Decrypt data buffer.
     */
    STDMETHOD(Decrypt)(int length, void* cypher_text, void* plain_text) PURE;
};
