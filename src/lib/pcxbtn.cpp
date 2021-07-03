/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          PCXIMGBTN.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         PCX image button.
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
#include "pcxbtn.h"
#include "tibsun_defines.h"
#include "tibsun_globals.h"
#include "language.h"
#include "imagecollection.h"
#include "filepcx.h"
#include "dsurface.h"
#include "bsurface.h"


/**
 *  Default constructor for a pcx image button.
 * 
 *  @author: CCHyper
 */
PCXButtonClass::PCXButtonClass() :
    ToggleClass(0, 0, 0, 0, 0)
{
    Disable();
}


/**
 *  Constructor for a pcx image button.
 * 
 *  @author: CCHyper
 */
PCXButtonClass::PCXButtonClass(unsigned id, const char *image_fname, int x, int y, int w, int h) :
    ToggleClass(id, x, y, w, h)
{
    Disable();

    Load_Image(image_fname);
}


/**
 *  Default deconstructor for a pcx image button.
 * 
 *  @author: CCHyper
 */
PCXButtonClass::~PCXButtonClass()
{
    ImageSurface = nullptr;
}


/**
 *  Renders the pcx button's imagery.
 * 
 *  @author: CCHyper
 */
bool PCXButtonClass::Draw_Me(bool forced)
{
    if (IsDisabled) {
        return false;
    }

    if (!ImageSurface) {
        return false;
    }
    
    Rect hidden_rect = HiddenSurface->Get_Rect();

    /**
     *  Draw the pcx image.
     */
    Rect image_rect;
    image_rect.X = hidden_rect.X + X;
    image_rect.Y = hidden_rect.Y + Y;
    image_rect.Width = ImageSurface->Get_Width();
    image_rect.Height = ImageSurface->Get_Height();

    ImageCollection.Draw(image_rect, *HiddenSurface, *ImageSurface);

    return true;
}


/**
 *  Loads the buttons imagery from the input filename.
 * 
 *  @author: CCHyper
 */
bool PCXButtonClass::Load_Image(const char *filename)
{
    CCFileClass pcxfile(filename);
    if (!pcxfile.Is_Available()) {
        return false;
    }

    /**
     *  Image collection required lowercase filename.
     */
    Wstring lowerstr = filename;
    lowerstr.To_Lower();

    PCX_HEADER pcxhdr;
    pcxfile.Read(&pcxhdr, sizeof(pcxhdr));

    bool loaded = false;

    switch (pcxhdr.BitsPixelPlane) {
        case 8:
            loaded = ImageCollection.Load_Paletted_PCX(lowerstr.Peek_Buffer());
            break;

        case 16:
            loaded = ImageCollection.Load_PCX(lowerstr.Peek_Buffer(), 2);
            break;

        default:
            break;
    };

    if (loaded) {

        /**
         *  Fetch the pointer to the loaded images graphical surface.
         */
        ImageSurface = ImageCollection.Get_Image_Surface(lowerstr.Peek_Buffer());
    }

    return true;
}
