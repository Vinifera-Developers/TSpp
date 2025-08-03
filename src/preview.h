/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          PREVIEW.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Map preview functions.
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


class XSurface;
class CCINIClass;


typedef struct PreviewDataStruct {
    int Width;
    int Height;
    char Data[1];
} PreviewDataStruct;


class PreviewClass
{
public:
    PreviewClass();
    ~PreviewClass();

    void Render_Preview(HWND hWnd);
    void Draw_Map();
    bool Write_Preview_INI(CCINIClass& ini);
    bool Read_Preview_INI(CCINIClass& ini);
    bool Read_PCX_Preview(const char* filename);
    bool Read_INI_Preview(const char* filename);
    PreviewDataStruct* Create_Paletted_Preview(int a1, int& size_bytes);
    void Create_Preview_Surface(PreviewDataStruct* a1);

private:
    XSurface* ImageSurface;
};
