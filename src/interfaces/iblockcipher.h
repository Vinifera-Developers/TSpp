/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  IBlockCipher interface.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
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
