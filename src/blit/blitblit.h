/*******************************************************************************
/*               O P E N  S O U R C E -- P R O J E C T T S Y R                **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          BLITBLIT.H
 *
 *  @author        CCHyper
 *
 *  @contributors  tomsons26
 *
 *  @brief         Templated blitters.
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
#include "blitter.h"
#include "rleblitter.h"


typedef enum BlitterType {

    /**
     *  Standard blitters.
     */
    BLITTER_PLAINXLATPTR = 0,
    BLITTER_TRANSXLATPTR,
    BLITTER_TRANSDARKENPTR,
    BLITTER_TRANSZREMAPXLATPTR,
    BLITTER_TRANSLUCENT75PTR,
    BLITTER_TRANSLUCENT50PTR,
    BLITTER_TRANSLUCENT25PTR,
    BLITTER_PLAINXLATZREADPTR,
    BLITTER_TRANSXLATZREADPTR,
    BLITTER_TRANSDARKENZREADPTR,
    BLITTER_TRANSZREMAPXLATZREADPTR,
    BLITTER_TRANSLUCENT75ZREADPTR,
    BLITTER_TRANSLUCENT50ZREADPTR,
    BLITTER_TRANSLUCENT25ZREADPTR,
    BLITTER_TRANSLUCENT75ZREADWARPPTR,
    BLITTER_TRANSLUCENT50ZREADWARPPTR,
    BLITTER_TRANSLUCENT25ZREADWARPPTR,
    BLITTER_PLAINXLATZREADWRITEPTR,
    BLITTER_TRANSXLATZREADWRITEPTR,
    BLITTER_TRANSDARKENZREADWRITEPTR,
    BLITTER_TRANSZREMAPXLATZREADWRITEPTR,
    BLITTER_TRANSLUCENT75ZREADWRITEPTR,
    BLITTER_TRANSLUCENT50ZREADWRITEPTR,
    BLITTER_TRANSLUCENT25ZREADWRITEPTR,
    BLITTER_PLAINXLATALPHAPTR,
    BLITTER_TRANSXLATALPHAPTR,
    BLITTER_TRANSZREMAPXLATALPHAPTR,
    BLITTER_TRANSLUCENT75ALPHAPTR,
    BLITTER_TRANSLUCENT50ALPHAPTR,
    BLITTER_TRANSLUCENT25ALPHAPTR,
    BLITTER_TRANSXLATWRITEALPHAPTR,
    BLITTER_TRANSXLATMULTWRITEALPHAPTR,
    BLITTER_TRANSLUCENTWRITEALPHAPTR,
    BLITTER_TRANSLUCENT50NONZEROALPHAPTR,
    BLITTER_TRANSLUCENT50ZEROALPHAPTR,
    BLITTER_TRANSLUCENT75NONZEROALPHAPTR,
    BLITTER_TRANSLUCENT75ZEROALPHAPTR,
    BLITTER_PLAINXLATALPHA_2PTR,
    BLITTER_TRANSXLATALPHAZREADPTR,
    BLITTER_TRANSZREMAPXLATALPHAZREADPTR,
    BLITTER_TRANSLUCENT75ALPHAZREADPTR,
    BLITTER_TRANSLUCENT50ALPHAZREADPTR,
    BLITTER_TRANSLUCENT25ALPHAZREADPTR,
    BLITTER_TRANSLUCENT75ALPHAZREADWARPPTR,
    BLITTER_TRANSLUCENT50ALPHAZREADWARPPTR,
    BLITTER_TRANSLUCENT25ALPHAZREADWARPPTR,
    BLITTER_PLAINXLATALPHA_3PTR,
    BLITTER_TRANSXLATALPHAZREADWRITEPTR,
    BLITTER_TRANSZREMAPXLATALPHAZREADWRITEPTR,
    BLITTER_TRANSLUCENT75ALPHAZREADWRITEPTR,
    BLITTER_TRANSLUCENT50ALPHAZREADWRITEPTR,
    BLITTER_TRANSLUCENT25ALPHAZREADWRITEPTR,

    BLITTER_COUNT,


    /**
     *  Run-length encoded blitters.
     */
    RLEBLITTER_TRANSXLATPTR = 0,
    RLEBLITTER_TRANSDARKENPTR,
    RLEBLITTER_TRANSZREMAPXLATPTR,
    RLEBLITTER_TRANSLUCENT75PTR,
    RLEBLITTER_TRANSLUCENT50PTR,
    RLEBLITTER_TRANSLUCENT25PTR,
    RLEBLITTER_TRANSXLATZREADPTR,
    RLEBLITTER_TRANSZREMAPXLATZREADPTR,
    RLEBLITTER_TRANSDARKENZREADPTR,
    RLEBLITTER_TRANSLUCENT75ZREADPTR,
    RLEBLITTER_TRANSLUCENT50ZREADPTR,
    RLEBLITTER_TRANSLUCENT25ZREADPTR,
    RLEBLITTER_TRANSLUCENT75ZREADWARPPTR,
    RLEBLITTER_TRANSLUCENT50ZREADWARPPTR,
    RLEBLITTER_TRANSLUCENT25ZREADWARPPTR,
    RLEBLITTER_TRANSXLATZREADWRITEPTR,
    RLEBLITTER_TRANSZREMAPXLATZREADWRITEPTR,
    RLEBLITTER_TRANSDARKENZREADWRITEPTR,
    RLEBLITTER_TRANSLUCENT75ZREADWRITEPTR,
    RLEBLITTER_TRANSLUCENT50ZREADWRITEPTR,
    RLEBLITTER_TRANSLUCENT25ZREADWRITEPTR,
    RLEBLITTER_TRANSXLATALPHAPTR,
    RLEBLITTER_TRANSZREMAPXLATALPHAPTR,
    RLEBLITTER_TRANSLUCENT75ALPHAPTR,
    RLEBLITTER_TRANSLUCENT50ALPHAPTR,
    RLEBLITTER_TRANSLUCENT25ALPHAPTR,
    RLEBLITTER_TRANSXLATALPHAZREADPTR,
    RLEBLITTER_TRANSZREMAPXLATALPHAZREADPTR,
    RLEBLITTER_TRANSLUCENT75ALPHAZREADPTR,
    RLEBLITTER_TRANSLUCENT50ALPHAZREADPTR,
    RLEBLITTER_TRANSLUCENT25ALPHAZREADPTR,
    RLEBLITTER_TRANSLUCENT75ALPHAZREADWARPPTR,
    RLEBLITTER_TRANSLUCENT50ALPHAZREADWARPPTR,
    RLEBLITTER_TRANSLUCENT25ALPHAZREADWARPPTR,
    RLEBLITTER_TRANSXLATALPHAZREADWRITEPTR,
    RLEBLITTER_TRANSZREMAPXLATALPHAZREADWRITEPTR,
    RLEBLITTER_TRANSLUCENT75ALPHAZREADWRITEPTR,
    RLEBLITTER_TRANSLUCENT50ALPHAZREADWRITEPTR,
    RLEBLITTER_TRANSLUCENT25ALPHAZREADWRITEPTR,

    RLEBLITTER_COUNT

} BlitterType;
DEFINE_ENUMERATION_OPERATORS(BlitterType);


template<typename T>
class BlitPlain : public Blitter
{
public:
    BlitPlain();
    virtual ~BlitPlain();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTrans : public Blitter
{
public:
    BlitTrans();
    virtual ~BlitTrans();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitPlainXlat : public Blitter
{
public:
    BlitPlainXlat();
    virtual ~BlitPlainXlat();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitPlainXlatAlpha : public Blitter
{
public:
    BlitPlainXlatAlpha();
    virtual ~BlitPlainXlatAlpha();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitPlainXlatZRead : public Blitter
{
public:
    BlitPlainXlatZRead();
    virtual ~BlitPlainXlatZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitPlainXlatZReadWrite : public Blitter
{
public:
    BlitPlainXlatZReadWrite();
    virtual ~BlitPlainXlatZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransDarken : public Blitter
{
public:
    BlitTransDarken();
    virtual ~BlitTransDarken();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransDarkenZRead : public Blitter
{
public:
    BlitTransDarkenZRead();
    virtual ~BlitTransDarkenZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransDarkenZReadWrite : public Blitter
{
public:
    BlitTransDarkenZReadWrite();
    virtual ~BlitTransDarkenZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransLucent25 : public Blitter
{
public:
    BlitTransLucent25();
    virtual ~BlitTransLucent25();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransLucent25Alpha : public Blitter
{
public:
    BlitTransLucent25Alpha();
    virtual ~BlitTransLucent25Alpha();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransLucent25AlphaZRead : public Blitter
{
public:
    BlitTransLucent25AlphaZRead();
    virtual ~BlitTransLucent25AlphaZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransLucent25AlphaZReadWarp : public Blitter
{
public:
    BlitTransLucent25AlphaZReadWarp();
    virtual ~BlitTransLucent25AlphaZReadWarp();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransLucent25AlphaZReadWrite : public Blitter
{
public:
    BlitTransLucent25AlphaZReadWrite();
    virtual ~BlitTransLucent25AlphaZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransLucent25ZRead : public Blitter
{
public:
    BlitTransLucent25ZRead();
    virtual ~BlitTransLucent25ZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransLucent25ZReadWarp : public Blitter
{
public:
    BlitTransLucent25ZReadWarp();
    virtual ~BlitTransLucent25ZReadWarp();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransLucent25ZReadWrite : public Blitter
{
public:
    BlitTransLucent25ZReadWrite();
    virtual ~BlitTransLucent25ZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransLucent50 : public Blitter
{
public:
    BlitTransLucent50();
    virtual ~BlitTransLucent50();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransLucent50Alpha : public Blitter
{
public:
    BlitTransLucent50Alpha();
    virtual ~BlitTransLucent50Alpha();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransLucent50AlphaZRead : public Blitter
{
public:
    BlitTransLucent50AlphaZRead();
    virtual ~BlitTransLucent50AlphaZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransLucent50AlphaZReadWarp : public Blitter
{
public:
    BlitTransLucent50AlphaZReadWarp();
    virtual ~BlitTransLucent50AlphaZReadWarp();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransLucent50AlphaZReadWrite : public Blitter
{
public:
    BlitTransLucent50AlphaZReadWrite();
    virtual ~BlitTransLucent50AlphaZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransLucent50ZRead : public Blitter
{
public:
    BlitTransLucent50ZRead();
    virtual ~BlitTransLucent50ZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransLucent50ZReadWarp : public Blitter
{
public:
    BlitTransLucent50ZReadWarp();
    virtual ~BlitTransLucent50ZReadWarp();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransLucent50ZReadWrite : public Blitter
{
public:
    BlitTransLucent50ZReadWrite();
    virtual ~BlitTransLucent50ZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransLucent75 : public Blitter
{
public:
    BlitTransLucent75();
    virtual ~BlitTransLucent75();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransLucent75Alpha : public Blitter
{
public:
    BlitTransLucent75Alpha();
    virtual ~BlitTransLucent75Alpha();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransLucent75AlphaZRead : public Blitter
{
public:
    BlitTransLucent75AlphaZRead();
    virtual ~BlitTransLucent75AlphaZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransLucent75AlphaZReadWarp : public Blitter
{
public:
    BlitTransLucent75AlphaZReadWarp();
    virtual ~BlitTransLucent75AlphaZReadWarp();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransLucent75AlphaZReadWrite : public Blitter
{
public:
    BlitTransLucent75AlphaZReadWrite();
    virtual ~BlitTransLucent75AlphaZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransLucent75ZRead : public Blitter
{
public:
    BlitTransLucent75ZRead();
    virtual ~BlitTransLucent75ZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransLucent75ZReadWarp : public Blitter
{
public:
    BlitTransLucent75ZReadWarp();
    virtual ~BlitTransLucent75ZReadWarp();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransLucent75ZReadWrite : public Blitter
{
public:
    BlitTransLucent75ZReadWrite();
    virtual ~BlitTransLucent75ZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransRemapDest : public Blitter
{
public:
    BlitTransRemapDest();
    virtual ~BlitTransRemapDest();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransRemapXlat : public Blitter
{
public:
    BlitTransRemapXlat();
    virtual ~BlitTransRemapXlat();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransXlat : public Blitter
{
public:
    BlitTransXlat();
    virtual ~BlitTransXlat();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransXlatAlpha : public Blitter
{
public:
    BlitTransXlatAlpha();
    virtual ~BlitTransXlatAlpha();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransXlatAlphaZRead : public Blitter
{
public:
    BlitTransXlatAlphaZRead();
    virtual ~BlitTransXlatAlphaZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransXlatAlphaZReadWrite : public Blitter
{
public:
    BlitTransXlatAlphaZReadWrite();
    virtual ~BlitTransXlatAlphaZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransXlatMultWriteAlpha : public Blitter
{
public:
    BlitTransXlatMultWriteAlpha();
    virtual ~BlitTransXlatMultWriteAlpha();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransXlatWriteAlpha : public Blitter
{
public:
    BlitTransXlatWriteAlpha();
    virtual ~BlitTransXlatWriteAlpha();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransXlatZRead : public Blitter
{
public:
    BlitTransXlatZRead();
    virtual ~BlitTransXlatZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransXlatZReadWrite : public Blitter
{
public:
    BlitTransXlatZReadWrite();
    virtual ~BlitTransXlatZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransZRemapXlat : public Blitter
{
public:
    BlitTransZRemapXlat();
    virtual ~BlitTransZRemapXlat();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransZRemapXlatAlpha : public Blitter
{
public:
    BlitTransZRemapXlatAlpha();
    virtual ~BlitTransZRemapXlatAlpha();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransZRemapXlatAlphaZRead : public Blitter
{
public:
    BlitTransZRemapXlatAlphaZRead();
    virtual ~BlitTransZRemapXlatAlphaZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransZRemapXlatAlphaZReadWrite : public Blitter
{
public:
    BlitTransZRemapXlatAlphaZReadWrite();
    virtual ~BlitTransZRemapXlatAlphaZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransZRemapXlatZRead : public Blitter
{
public:
    BlitTransZRemapXlatZRead();
    virtual ~BlitTransZRemapXlatZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTransZRemapXlatZReadWrite : public Blitter
{
public:
    BlitTransZRemapXlatZReadWrite();
    virtual ~BlitTransZRemapXlatZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTranslucent50NonzeroAlpha : public Blitter
{
public:
    BlitTranslucent50NonzeroAlpha();
    virtual ~BlitTranslucent50NonzeroAlpha();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTranslucent50ZeroAlpha : public Blitter
{
public:
    BlitTranslucent50ZeroAlpha();
    virtual ~BlitTranslucent50ZeroAlpha();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTranslucent75NonzeroAlpha : public Blitter
{
public:
    BlitTranslucent75NonzeroAlpha();
    virtual ~BlitTranslucent75NonzeroAlpha();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTranslucent75ZeroAlpha : public Blitter
{
public:
    BlitTranslucent75ZeroAlpha();
    virtual ~BlitTranslucent75ZeroAlpha();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};


template<typename T>
class BlitTranslucentWriteAlpha : public Blitter
{
public:
    BlitTranslucentWriteAlpha();
    virtual ~BlitTranslucentWriteAlpha();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000, int warp_offset = 0) override;
    virtual void entry_8(void* dest, void* source, unsigned length, unsigned short z_min = 0x8000, int* z_buff = nullptr, int* alpha_buff = nullptr, int alpha_level = 1000) override;
};

template<typename T>
class RLEBlitTransDarken : public RLEBlitter
{
public:
    RLEBlitTransDarken();
    virtual ~RLEBlitTransDarken();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransDarkenZRead : public RLEBlitter
{
public:
    RLEBlitTransDarkenZRead();
    virtual ~RLEBlitTransDarkenZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransDarkenZReadWrite : public RLEBlitter
{
public:
    RLEBlitTransDarkenZReadWrite();
    virtual ~RLEBlitTransDarkenZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransLucent25 : public RLEBlitter
{
public:
    RLEBlitTransLucent25();
    virtual ~RLEBlitTransLucent25();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransLucent25Alpha : public RLEBlitter
{
public:
    RLEBlitTransLucent25Alpha();
    virtual ~RLEBlitTransLucent25Alpha();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransLucent25AlphaZRead : public RLEBlitter
{
public:
    RLEBlitTransLucent25AlphaZRead();
    virtual ~RLEBlitTransLucent25AlphaZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransLucent25AlphaZReadWarp : public RLEBlitter
{
public:
    RLEBlitTransLucent25AlphaZReadWarp();
    virtual ~RLEBlitTransLucent25AlphaZReadWarp();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransLucent25AlphaZReadWrite : public RLEBlitter
{
public:
    RLEBlitTransLucent25AlphaZReadWrite();
    virtual ~RLEBlitTransLucent25AlphaZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransLucent25ZRead : public RLEBlitter
{
public:
    RLEBlitTransLucent25ZRead();
    virtual ~RLEBlitTransLucent25ZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransLucent25ZReadWarp : public RLEBlitter
{
public:
    RLEBlitTransLucent25ZReadWarp();
    virtual ~RLEBlitTransLucent25ZReadWarp();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransLucent25ZReadWrite : public RLEBlitter
{
public:
    RLEBlitTransLucent25ZReadWrite();
    virtual ~RLEBlitTransLucent25ZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransLucent50 : public RLEBlitter
{
public:
    RLEBlitTransLucent50();
    virtual ~RLEBlitTransLucent50();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransLucent50Alpha : public RLEBlitter
{
public:
    RLEBlitTransLucent50Alpha();
    virtual ~RLEBlitTransLucent50Alpha();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransLucent50AlphaZRead : public RLEBlitter
{
public:
    RLEBlitTransLucent50AlphaZRead();
    virtual ~RLEBlitTransLucent50AlphaZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransLucent50AlphaZReadWarp : public RLEBlitter
{
public:
    RLEBlitTransLucent50AlphaZReadWarp();
    virtual ~RLEBlitTransLucent50AlphaZReadWarp();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransLucent50AlphaZReadWrite : public RLEBlitter
{
public:
    RLEBlitTransLucent50AlphaZReadWrite();
    virtual ~RLEBlitTransLucent50AlphaZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransLucent50ZRead : public RLEBlitter
{
public:
    RLEBlitTransLucent50ZRead();
    virtual ~RLEBlitTransLucent50ZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransLucent50ZReadWarp : public RLEBlitter
{
public:
    RLEBlitTransLucent50ZReadWarp();
    virtual ~RLEBlitTransLucent50ZReadWarp();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransLucent50ZReadWrite : public RLEBlitter
{
public:
    RLEBlitTransLucent50ZReadWrite();
    virtual ~RLEBlitTransLucent50ZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransLucent75 : public RLEBlitter
{
public:
    RLEBlitTransLucent75();
    virtual ~RLEBlitTransLucent75();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransLucent75Alpha : public RLEBlitter
{
public:
    RLEBlitTransLucent75Alpha();
    virtual ~RLEBlitTransLucent75Alpha();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransLucent75AlphaZRead : public RLEBlitter
{
public:
    RLEBlitTransLucent75AlphaZRead();
    virtual ~RLEBlitTransLucent75AlphaZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransLucent75AlphaZReadWarp : public RLEBlitter
{
public:
    RLEBlitTransLucent75AlphaZReadWarp();
    virtual ~RLEBlitTransLucent75AlphaZReadWarp();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransLucent75AlphaZReadWrite : public RLEBlitter
{
public:
    RLEBlitTransLucent75AlphaZReadWrite();
    virtual ~RLEBlitTransLucent75AlphaZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransLucent75ZRead : public RLEBlitter
{
public:
    RLEBlitTransLucent75ZRead();
    virtual ~RLEBlitTransLucent75ZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransLucent75ZReadWarp : public RLEBlitter
{
public:
    RLEBlitTransLucent75ZReadWarp();
    virtual ~RLEBlitTransLucent75ZReadWarp();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransLucent75ZReadWrite : public RLEBlitter
{
public:
    RLEBlitTransLucent75ZReadWrite();
    virtual ~RLEBlitTransLucent75ZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransRemapDest : public RLEBlitter
{
public:
    RLEBlitTransRemapDest();
    virtual ~RLEBlitTransRemapDest();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransRemapDestZRead : public RLEBlitter
{
public:
    RLEBlitTransRemapDestZRead();
    virtual ~RLEBlitTransRemapDestZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransRemapDestZReadWrite : public RLEBlitter
{
public:
    RLEBlitTransRemapDestZReadWrite();
    virtual ~RLEBlitTransRemapDestZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransRemapXlat : public RLEBlitter
{
public:
    RLEBlitTransRemapXlat();
    virtual ~RLEBlitTransRemapXlat();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransRemapXlatZRead : public RLEBlitter
{
public:
    RLEBlitTransRemapXlatZRead();
    virtual ~RLEBlitTransRemapXlatZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransRemapXlatZReadWrite : public RLEBlitter
{
public:
    RLEBlitTransRemapXlatZReadWrite();
    virtual ~RLEBlitTransRemapXlatZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransXlat : public RLEBlitter
{
public:
    RLEBlitTransXlat();
    virtual ~RLEBlitTransXlat();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransXlatAlpha : public RLEBlitter
{
public:
    RLEBlitTransXlatAlpha();
    virtual ~RLEBlitTransXlatAlpha();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransXlatAlphaZRead : public RLEBlitter
{
public:
    RLEBlitTransXlatAlphaZRead();
    virtual ~RLEBlitTransXlatAlphaZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransXlatAlphaZReadWrite : public RLEBlitter
{
public:
    RLEBlitTransXlatAlphaZReadWrite();
    virtual ~RLEBlitTransXlatAlphaZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransXlatZRead : public RLEBlitter
{
public:
    RLEBlitTransXlatZRead();
    virtual ~RLEBlitTransXlatZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransXlatZReadWrite : public RLEBlitter
{
public:
    RLEBlitTransXlatZReadWrite();
    virtual ~RLEBlitTransXlatZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransZRemapXlat : public RLEBlitter
{
public:
    RLEBlitTransZRemapXlat();
    virtual ~RLEBlitTransZRemapXlat();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransZRemapXlatAlpha : public RLEBlitter
{
public:
    RLEBlitTransZRemapXlatAlpha();
    virtual ~RLEBlitTransZRemapXlatAlpha();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransZRemapXlatAlphaZRead : public RLEBlitter
{
public:
    RLEBlitTransZRemapXlatAlphaZRead();
    virtual ~RLEBlitTransZRemapXlatAlphaZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransZRemapXlatAlphaZReadWrite : public RLEBlitter
{
public:
    RLEBlitTransZRemapXlatAlphaZReadWrite();
    virtual ~RLEBlitTransZRemapXlatAlphaZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransZRemapXlatZRead : public RLEBlitter
{
public:
    RLEBlitTransZRemapXlatZRead();
    virtual ~RLEBlitTransZRemapXlatZRead();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};


template<typename T>
class RLEBlitTransZRemapXlatZReadWrite : public RLEBlitter
{
public:
    RLEBlitTransZRemapXlatZReadWrite();
    virtual ~RLEBlitTransZRemapXlatZReadWrite();

    virtual void entry_4(void* dest, void* source, unsigned length, unsigned rle_length, int a5, int a6, int a7, int a8, int a9, int a10) override;
};
