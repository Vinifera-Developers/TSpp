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
#include "spritecollection.h"
#include "tibsun_globals.h"
#include "tspp_assert.h"


/**
 *  Copys image from the surface with a alpha mask applied.
 *
 *  x_offset and y_offset are optional, and are for panning a sprite sheet
 *  alpha mask.
 *
 *  @author: CCHyper
 */
bool XSurface::Copy_From_Alpha(Surface& fromsurface, Surface& alphasurface, int x_offset, int y_offset)
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
bool XSurface::Copy_From_Spritesheet(Surface& fromsurface, int sprite_width, int sprite_height, int x_offset, int y_offset)
{
    BSurface sprite_surface(sprite_width, sprite_height, fromsurface.Bytes_Per_Pixel());

    Rect sprite_rect(x_offset, y_offset, sprite_width, sprite_height);

    return Blit_From(Get_Rect(), fromsurface, sprite_rect);
}


/**
 *  Copys image from the sprite surface with a alpha mask applied.
 *
 *  x_offset and y_offset are the offset within the sprite surface AND the alpah
 *  mask where the desired image is located.
 *
 *  @author: CCHyper
 */
bool XSurface::Copy_From_Spritesheet_Alpha(Surface& fromsurface, Surface& alphasurface, int sprite_width, int sprite_height, int x_offset, int y_offset)
{
    BSurface sprite_surface(sprite_width, sprite_height, fromsurface.Bytes_Per_Pixel());

    Rect sprite_rect(x_offset, y_offset, sprite_width, sprite_height);

    sprite_surface.Blit_From(Get_Rect(), fromsurface, sprite_rect);

    return SpriteCollection.Draw_Alpha(Get_Rect(), *this, sprite_surface, alphasurface, nullptr, false, x_offset, y_offset);
}
