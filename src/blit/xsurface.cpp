/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          XSURFACE.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Basic drawing surface.
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
#include "xsurface.h"
#include "bsurface.h"
#include "dsurface.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"
#include "spritecollection.h"


/**
 *  Copys image from the surface with a alpha mask applied.
 * 
 *  x_offset and y_offset are optional, and are for panning a sprite sheet
 *  alpha mask.
 * 
 *  @author: CCHyper
 */
bool XSurface::Copy_From_Alpha(Surface &fromsurface, Surface &alphasurface, int x_offset, int y_offset)
{
    /**
     *  Alpha mask must be the same size as the image for non-sprite sheet masks.
     */
    if (x_offset != 0 || y_offset != 0) {
        TSPP_ASSERT(fromsurface.Get_Width() == alphasurface.Get_Width());
        TSPP_ASSERT(fromsurface.Get_Height() == alphasurface.Get_Width());
    }

    return SpriteCollection.Draw_Alpha(Get_Rect(), *this, fromsurface, alphasurface, nullptr, false, x_offset, y_offset);
}


/**
 *  Copys image from the sprite surface.
 * 
 *  x_offset and y_offset are the offset within the sprite surface where the
 *  desired image is located.
 * 
 *  @author: CCHyper
 */
bool XSurface::Copy_From_Spritesheet(Surface &fromsurface, int sprite_width, int sprite_height, int x_offset, int y_offset)
{
    BSurface sprite_surface(sprite_width, sprite_height, fromsurface.Get_Bytes_Per_Pixel());

    Rect sprite_rect(
        x_offset, y_offset, sprite_width, sprite_height
    );

    return Copy_From(Get_Rect(), fromsurface, sprite_rect);
}


/**
 *  Copys image from the sprite surface with a alpha mask applied.
 * 
 *  x_offset and y_offset are the offset within the sprite surface AND the alpah
 *  mask where the desired image is located.
 * 
 *  @author: CCHyper
 */
bool XSurface::Copy_From_Spritesheet_Alpha(Surface &fromsurface, Surface &alphasurface, int sprite_width, int sprite_height, int x_offset, int y_offset)
{
    BSurface sprite_surface(sprite_width, sprite_height, fromsurface.Get_Bytes_Per_Pixel());

    Rect sprite_rect(
        x_offset, y_offset, sprite_width, sprite_height
    );

    sprite_surface.Copy_From(Get_Rect(), fromsurface, sprite_rect);

    return SpriteCollection.Draw_Alpha(Get_Rect(), *this, sprite_surface, alphasurface, nullptr, false, x_offset, y_offset);
}


/**
 *  Perform a fast gaussain blur on the input rect.
 * 
 *  @author: secsome, https://www.peterkovesi.com/papers/FastGaussianSmoothing.pdf, CCHyper
 */
void XSurface::Gaussian_Blur_Rect(Rect rect, float blur_size)
{
    // Divide loop iterations to threads.
    #define ENABLE_OMP 0

    if (blur_size <= 0.0f) {
        return;
    }

    if (Get_Bytes_Per_Pixel() != 2) {
        return;
    }

    if (!rect.Is_Valid()) {
        return;
    }

    const Rect bound = rect.Intersect_With(Get_Rect());
    if (!bound.Is_Valid()) {
        return;
    }

    unsigned short *ptr = (unsigned short *)Lock(bound.X, bound.Y);
    if (!ptr) {
        return;
    }

    const unsigned int line_length = Get_Pitch() / sizeof(short);

    // init boxes
    int box[3];

    {
        int wl = (int)WWMath::Floor(std::sqrt(4 * blur_size * blur_size + 1));
        if (wl % 2 == 0) {
            --wl;
        }
        int wu = wl + 2;

        const int m = (int)WWMath::Round((12 * blur_size * blur_size - 3 * wl * wl - 12 * wl - 9) * 1.f / (-4 * wl - 4));
        for (int i = 0; i < 3; ++i) {
            box[i] = ((i < m ? wl : wu) - 1) / 2;
        }
    }

    auto box_blur = [&](BYTE *& in, BYTE *& out, int r)
    {
        constexpr int c = 3;
        const int w = bound.Width;
        const int h = bound.Height;
        {
            float iarr = 1.f / (r + r + 1);
#if ENABLE_OMP
#pragma omp parallel for
#endif
            for (int i = 0; i < h; i++) {
                int ti = i * w;
                int li = ti;
                int ri = ti + r;

                int fv[3] = { in[ti * c + 0], in[ti * c + 1], in[ti * c + 2] };
                int lv[3] = { in[(ti + w - 1) * c + 0], in[(ti + w - 1) * c + 1], in[(ti + w - 1) * c + 2] };
                int val[3] = { (r + 1) * fv[0], (r + 1) * fv[1], (r + 1) * fv[2] };

                for (int j = 0; j < r; j++) {
                    val[0] += in[(ti + j) * c + 0];
                    val[1] += in[(ti + j) * c + 1];
                    val[2] += in[(ti + j) * c + 2];
                }

                for (int j = 0; j <= r; j++, ri++, ti++) {
                    val[0] += in[ri * c + 0] - fv[0];
                    val[1] += in[ri * c + 1] - fv[1];
                    val[2] += in[ri * c + 2] - fv[2];
                    out[ti * c + 0] = static_cast<BYTE>(val[0] * iarr);
                    out[ti * c + 1] = static_cast<BYTE>(val[1] * iarr);
                    out[ti * c + 2] = static_cast<BYTE>(val[2] * iarr);
                }

                for (int j = r + 1; j < w - r; j++, ri++, ti++, li++) {
                    val[0] += in[ri * c + 0] - in[li * c + 0];
                    val[1] += in[ri * c + 1] - in[li * c + 1];
                    val[2] += in[ri * c + 2] - in[li * c + 2];
                    out[ti * c + 0] = static_cast<BYTE>(val[0] * iarr);
                    out[ti * c + 1] = static_cast<BYTE>(val[1] * iarr);
                    out[ti * c + 2] = static_cast<BYTE>(val[2] * iarr);
                }

                for (int j = w - r; j < w; j++, ti++, li++) {
                    val[0] += lv[0] - in[li * c + 0];
                    val[1] += lv[1] - in[li * c + 1];
                    val[2] += lv[2] - in[li * c + 2];
                    out[ti * c + 0] = static_cast<BYTE>(val[0] * iarr);
                    out[ti * c + 1] = static_cast<BYTE>(val[1] * iarr);
                    out[ti * c + 2] = static_cast<BYTE>(val[2] * iarr);
                }
            }
        } // horizonal blur

        std::swap(in, out);

        {
            float iarr = 1.f / (r + r + 1);
#if ENABLE_OMP
#pragma omp parallel for
#endif
            for (int i = 0; i < w; i++) {
                int ti = i;
                int li = ti;
                int ri = ti + r * w;

                int fv[3] = { in[ti * c + 0], in[ti * c + 1], in[ti * c + 2] };
                int lv[3] = { in[(ti + w * (h - 1)) * c + 0], in[(ti + w * (h - 1)) * c + 1], in[(ti + w * (h - 1)) * c + 2] };
                int val[3] = { (r + 1) * fv[0], (r + 1) * fv[1], (r + 1) * fv[2] };

                for (int j = 0; j < r; j++) {
                    val[0] += in[(ti + j * w) * c + 0];
                    val[1] += in[(ti + j * w) * c + 1];
                    val[2] += in[(ti + j * w) * c + 2];
                }

                for (int j = 0; j <= r; j++, ri += w, ti += w) {
                    val[0] += in[ri * c + 0] - fv[0];
                    val[1] += in[ri * c + 1] - fv[1];
                    val[2] += in[ri * c + 2] - fv[2];
                    out[ti * c + 0] = static_cast<BYTE>(val[0] * iarr);
                    out[ti * c + 1] = static_cast<BYTE>(val[1] * iarr);
                    out[ti * c + 2] = static_cast<BYTE>(val[2] * iarr);
                }

                for (int j = r + 1; j < h - r; j++, ri += w, ti += w, li += w) {
                    val[0] += in[ri * c + 0] - in[li * c + 0];
                    val[1] += in[ri * c + 1] - in[li * c + 1];
                    val[2] += in[ri * c + 2] - in[li * c + 2];
                    out[ti * c + 0] = static_cast<BYTE>(val[0] * iarr);
                    out[ti * c + 1] = static_cast<BYTE>(val[1] * iarr);
                    out[ti * c + 2] = static_cast<BYTE>(val[2] * iarr);
                }

                for (int j = h - r; j < h; j++, ti += w, li += w) {
                    val[0] += lv[0] - in[li * c + 0];
                    val[1] += lv[1] - in[li * c + 1];
                    val[2] += lv[2] - in[li * c + 2];
                    out[ti * c + 0] = static_cast<BYTE>(val[0] * iarr);
                    out[ti * c + 1] = static_cast<BYTE>(val[1] * iarr);
                    out[ti * c + 2] = static_cast<BYTE>(val[2] * iarr);
                }
            }
        } // total blur
    };

    size_t size = bound.Width * bound.Height * 3;
    BYTE *in = new BYTE[size];
    BYTE *out = new BYTE[size];

    // write surface data to "in".
    {
        unsigned char * d = in;
        unsigned short * p = ptr;
        for (int y = 0; y < bound.Height; ++y) {
            unsigned short * q = p;
            for (int x = 0; x < bound.Width; ++x) {
                Pixel_To_RGB(*q, d[0], d[1], d[2]);
                d += 3;
                ++q;
            }
            p += line_length;
        }
    }

    box_blur(in, out, box[0]);
    box_blur(out, in, box[1]);
    box_blur(in, out, box[2]);

    // write out to surface data.
    {
        unsigned char * d = out;
        unsigned short * p = ptr;
        for (int y = 0; y < bound.Height; ++y) {
            unsigned short * q = p;
            for (int x = 0; x < bound.Width; ++x) {
                *q = (WORD)RGB_To_Pixel(d[0], d[1], d[2]);
                d += 3;
                ++q;
            }
            p += line_length;
        }
    }

    delete[] in;
    delete[] out;

    Unlock();
}
