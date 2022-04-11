/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SPRITECOLLECTION.CPP
 *
 *  @authors       CCHyper, tomsons26
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
#include "spritecollection.h"
#include "tibsun_globals.h"
#include "filepcx.h"
#include "ccfile.h"
#include "wstring.h"
#include "bsurface.h"
//#include "tspp_debug.h"


/**
 *  Fetch a PCX image surface from the specified filename if it exists.
 *  
 *  @return      NULL if the PCX file was not found.
 * 
 *  @warning     The input filename must not contain an extension!
 * 
 *  @author: CCHyper
 */
BSurface *Get_PCX_Image_Surface(const char *filename)
{
    if (!filename || !std::strlen(filename)) {
        return nullptr;
    }

    if (std::strstr(filename, ".PCX")) {
        //TSPP_DEBUG_WARNING("invalid filename passed to Get_PCX_Image_Surface()!\n");
        return nullptr;
    }

    BSurface *surface = nullptr;

    Wstring fname = filename;
    fname += ".PCX";

    /**
     *  Image collection requires lowercase filename.
     */
    fname.To_Lower();

    CCFileClass pcxfile(fname.Peek_Buffer());
    if (!pcxfile.Is_Available()) {
        return nullptr;
    }

    PCX_HEADER pcxhdr;
    pcxfile.Read(&pcxhdr, sizeof(pcxhdr));

    /**
     *  We only support 8-bit PCX images.
     */
    if (pcxhdr.BitsPixelPlane != 8) {
        //TSPP_DEBUG_ERROR("File \"%s\" is an unsupported PCX format!\n", buff);
        return false;
    }

    /**
     *  Load the PCX image.
     */
    bool loaded = SpriteCollection.File_Loaded(fname.Peek_Buffer());
    if (!loaded) {

        /**
         *  PCX is paletted.
         */
         if (pcxhdr.NumberOfPlanes == 1) {
            loaded = SpriteCollection.Load_Paletted_PCX(fname.Peek_Buffer());

        } else {
            loaded = SpriteCollection.Load_PCX(fname.Peek_Buffer(), 1);
        }
    }

    if (!loaded) {
        //TSPP_DEBUG_WARNING("Failed to load PCX \"%s\"!\n", fname.Peek_Buffer());
        return false;
    }

    /**
     *  Was the PCX file loaded successfully? Return a pointer to the loaded image surface.
     */
    if (loaded) {
        BSurface *tmp = SpriteCollection.Get_Image_Surface(fname.Peek_Buffer());
        surface = new BSurface();
        surface->Copy_From(*tmp);
    }

    return surface;
}


/**
 *  Fetch a BMP image surface from the specified filename if it exists.
 *  
 *  @return      NULL if the BMP file was not found.
 * 
 *  @warning     The input filename must not contain an extension!
 * 
 *  @author: CCHyper
 */
BSurface *Get_BMP_Image_Surface(const char *filename)
{
    if (!filename || !std::strlen(filename)) {
        return nullptr;
    }

    if (std::strstr(filename, ".BMP")) {
        //TSPP_DEBUG_WARNING("invalid filename passed to Get_BMP_Image_Surface()!\n");
        return nullptr;
    }

    Wstring fname = filename;
    fname += ".BMP";

    /**
     *  Image collection requires lowercase filename.
     */
    fname.To_Lower();

    CCFileClass bmpfile(fname.Peek_Buffer());
    if (!bmpfile.Is_Available()) {
        return nullptr;
    }

    BSurface *surface = nullptr;

    // TODO

    return surface;
}
