/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *  @brief  PCX image button.
 *
 *  SPDX-License-Identifier: GPL-3.0-or-later
 *  Copyright (c) 2020-2026 Vinifera contributors
 ******************************************************************************/
#include "pcxbtn.h"
#include "bsurface.h"
#include "dsurface.h"
#include "filepcx.h"
#include "language.h"
#include "spritecollection.h"
#include "tibsun_defines.h"
#include "tibsun_globals.h"


/**
 *  Default constructor for a pcx image button.
 *
 *  @author: CCHyper
 */
PCXButtonClass::PCXButtonClass() : ToggleClass(0, 0, 0, 0, 0)
{
    Disable();
}


/**
 *  Constructor for a pcx image button.
 *
 *  @author: CCHyper
 */
PCXButtonClass::PCXButtonClass(unsigned id, const char* image_fname, int x, int y, int w, int h) : ToggleClass(id, x, y, w, h)
{
    Disable();

    Load_Image(image_fname);
}


/**
 *  Default destructor for a pcx image button.
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

    SpriteCollection.Draw(image_rect, *HiddenSurface, *ImageSurface);

    return true;
}


/**
 *  Loads the buttons imagery from the input filename.
 *
 *  @author: CCHyper
 */
bool PCXButtonClass::Load_Image(const char* filename)
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
        loaded = SpriteCollection.Load_Paletted_PCX(lowerstr.Peek_Buffer());
        break;

    case 16:
        loaded = SpriteCollection.Load_PCX(lowerstr.Peek_Buffer(), 2);
        break;

    default:
        break;
    };

    if (loaded) {

        /**
         *  Fetch the pointer to the loaded images graphical surface.
         */
        ImageSurface = SpriteCollection.Get_Image_Surface(lowerstr.Peek_Buffer());
    }

    return true;
}
