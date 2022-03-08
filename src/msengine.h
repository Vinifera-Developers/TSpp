/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          GRAPHICMENU.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Graphic menu instance class.
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
#include "tpoint.h"
#include "trect.h"
#include "ttimer.h"
#include "ftimer.h"
#include "vector.h"
#include "tibsun_defines.h"


class MSAnim;
class MSSfx;
class MSTextEntry;
class WWFontClass;
class ConvertClass;
class MovieClass;
class Surface;


class MapStage
{

};


class MapSelect
{
    public:
        MapSelect(); // 
        ~MapSelect(); // 

        // TODO

    protected:
};


class MapSelection
{
    public:
        MapSelection(); // 
        virtual ~MapSelection(); // 

        // TODO

    protected:
};


class MSEngine
{
    public:
        MSEngine(); // 
        virtual ~MSEngine(); // 

        // TODO

    protected:
        int field_4;
        VectorClass<TRect<int>> Rects;
        DynamicVectorClass<MSAnim *> Anims;
        DynamicVectorClass<MSSfx *> Sounds;
};


class MSChoice // unsure of name, maybe from YR?
{
    public:
        MSChoice(); // 0056E9F0
        virtual ~MSChoice(); // 0056EF20

        // TODO

    protected:
        char *Name;
        char *Scenario;
        char *MapVQ;
        char *VoiceOver;
        char *Description;
        int Overlays;
        char *ClickMap;
        DynamicVectorClass<Point2D> Target;
        DynamicVectorClass<MSTextEntry *> TextEntries;
        DynamicVectorClass<MapSelection *> field_54; // sub-map selections?
};


class MSAnim
{
    public:
        MSAnim(); // 
        virtual ~MSAnim(); // 

        // TODO

    protected:
        TPoint2D<int> Position;
        bool field_C;
        CDTimerClass<FrameTimerClass> RateTimer;
};


class MSSfx
{
    public:
        MSSfx(); // 
        virtual ~MSSfx(); // 

        // TODO

    protected:
        char *Name;
        void *FilePtr;
        bool IsLoaded;
};


class MSFont
{
    public:
        MSFont(); // 
        virtual ~MSFont(); // 

        // TODO

    protected:
        int Width;
        int Height;
        RGBStruct Color;
        unsigned PackedColor;
        WWFontClass *FontPtr;
        ConvertClass *Drawer;
        bool IsLoaded;
};


class MSFadeAnim : public MSShapeAnim
{
    public:
        MSFadeAnim(); // 
        virtual ~MSFadeAnim(); // 

        // TODO

    protected:
        int field_40;
};


class MSButtonAnim : public MSAnim
{
    public:
        MSButtonAnim(); // 
        virtual ~MSButtonAnim(); // 

        // TODO

    protected:
        int field_1C;
        bool field_20;
        bool field_21;
        Rect ButtonRect;
        int field_34;
        int field_38;
        int field_3C;
        int field_40;
        bool field_44;
};


class MSPrintAnim : public MSAnim
{
    public:
        MSPrintAnim(); // 
        virtual ~MSPrintAnim(); // 

        // TODO

    protected:
        int field_1C;
        int field_20;
        int field_24;
        int field_28;
        int field_2C;
        int field_30;
        int field_34;
        int field_38;
        int field_3C;
        int field_40;
        int field_44;
        int field_48;
        int field_49;
        int field_4C;
};


class MSWordAnim : public MSPrintAnim
{
    public:
        MSWordAnim(); // 
        virtual ~MSWordAnim(); // 

        // TODO

    protected:
        int field_50;
        int field_54;
        int field_58;
        int field_5C;
        int field_60;
};


class MSVersionTextAnim : public MSAnim
{
    public:
        MSVersionTextAnim(); // 
        virtual ~MSVersionTextAnim(); // 

        // TODO

    protected:
        int field_1C;        
        int field_1D;        
};


class MSVQAnim : public MSAnim
{
    public:
        MSVQAnim(); // 
        virtual ~MSVQAnim(); // 

        // TODO

    protected:
        MovieClass *Movie;
        Surface *MovieSurface;
        Surface *Background;
        bool field_2C;
        bool field_2D;
};


class MSShapeAnim : public MSAnim
{
    public:
        MSShapeAnim(); // 
        virtual ~MSShapeAnim(); // 

        // TODO

    protected:
        ShapeFileStruct *ShapeFile;
        void *Palette;
        int Rate;
        int field_2C;
        int ShapeFrameCount;
        bool Loops;
        int Scale;
        bool ShapeFileLoaded;
};


class MSPCXAnim : public MSAnim
{
    public:
        MSPCXAnim(); // 
        virtual ~MSPCXAnim(); // 

        // TODO

    protected:
        // TODO
};


class MSOverlayAnim : public MSFadeAnim
{
    public:
        MSOverlayAnim(); // 0056B9D0
        virtual ~MSOverlayAnim(); // 0056BA20

        // TODO

    protected:
        int field_40;
        bool field_44;
        int field_48;
};


class MSAnimEntry
{
    public:
        MSAnimEntry(); // 0056F1C0
        MSAnimEntry(const char *buffer); // 0056F110
        virtual ~MSAnimEntry(); // possibly inlined

    protected:
        char *Name;
        TPoint2D<int> Pos;
        int Rate;
};


class MSSfxEntry
{
    public:
        MSSfxEntry(); // possibly inlined
        MSSfxEntry(const char *buffer); // 0056F270
        virtual ~MSSfxEntry(); // 0056F3B0

        void Play() const; // 0056F3F0

    protected:
        char *Name;
        bool IsLoaded;
        void *FilePtr;
        int Volume;
};


class MSTextEntry
{
    public:
        MSTextEntry(); // possibly inlined
        virtual ~MSTextEntry(); // possibly inlined 0056EFB7

    protected:
        TPoint2D<int> Pos;
        int Time;
        char *TextString;
};
