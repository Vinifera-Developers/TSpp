/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SHAPESET.H
 *
 *  @author        Joe L. Bostic (see notes below)
 *
 *  @contributors  tomsons26, ZivDero
 *
 *  @brief         ShapeSet class.
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
 *  @note          This file contains modified code from the C&C Generals source code
 *                 released by Electronic Arts under the GPL3 license. Source:
 *                 https://github.com/electronicarts/CnC_Generals_Zero_Hour
 *
 ******************************************************************************/
#pragma once

#include "rgb.h"
#include "tibsun_globals.h"


/*
**  This is the header that appears at the beginning of the ShapeSet file. The header
**  is a multiple of 8 bytes long to facilitate data alignment. The shape header is
**  immediately followed by an N length array of ShapeRecord objects. The actual
**  shape data follows this array.
*/
#pragma pack(push, 4)
class ShapeSet
{
public:
    /*
    **  Fetch pointer to raw shape data (NULL if not present or empty).
    */
    void* Get_Data(int shape) const;

    /*
    **  Fetch sub-rectangle that the shape data represents.
    */
    Rect Get_Rect(int shape) const;


    RGBClass Get_Color(int shape) const;

    /*
    **  Are there any transparent pixels within the shape?
    */
    bool Is_Transparent(int shape) const;

    /*
    **  Determines if the specified shape is RLE compressed.
    */
    bool Is_RLE_Compressed(int shape) const;

    /*
    **  Logical width of the shape set.
    */
    int Get_Width() const { return Width; }

    /*
    **  Logical height of the shape set.
    */
    int Get_Height() const { return Height; }

    /*
    **  Number of shapes in this shape set.
    */
    int Get_Count() const { return Count; }

protected:
    /*
    **  QShape information flags.
    */
    short Flags;

    /*
    **  The nominal width and height of the shape (in pixels).
    */
    short Width;
    short Height;

    /*
    **  The total number of shapes in the file.
    */
    short Count;

    class ShapeRecord
    {
    public:
        /*
        **  The sub-offset (relative to logical 0,0 at upper left corner) for this
        **  shape's data.
        */
        short X;
        short Y;

        /*
        **  The dimensions of this shape's data.
        */
        short Width;
        short Height;

        /*
        **  Flags that indicate some aspect of this particular shape image.
        */
        short Flags;
        enum {
            SFLAG_TRANSPARENT = 0x01, // Are there are any transparent pixels present?
            SFLAG_RLE = 0x02          // Is it RLE compressed?
        };

        unsigned char Color[3];
        unsigned char Unused[5];

        bool Is_Transparent() const { return (Flags & SFLAG_TRANSPARENT) != 0; }
        bool Is_RLE_Compressed() const { return (Flags & SFLAG_RLE) != 0; }

        void Flag_Transparent() { Flags |= SFLAG_TRANSPARENT; }
        void Flag_RLE_Compressed() { Flags |= SFLAG_RLE; }

        long Data;
    };

    bool Is_Shape_Index_Valid(int index) const { return static_cast<unsigned>(index) < static_cast<unsigned>(Count); }

    ShapeRecord const* Fetch_Record_Pointer(int shape) const
    {
        if (Is_Shape_Index_Valid(shape)) {
            return reinterpret_cast<ShapeRecord const*>((char*)this + sizeof(ShapeSet) + sizeof(ShapeRecord) * shape);
        }
        return nullptr;
    }

public:
    /*
    **  Prevents a shape object from being constructed illegally.
    */
    ShapeSet() = delete;
    ShapeSet(ShapeSet const& rvalue) = delete;
    ShapeSet& operator=(ShapeSet const& rvalue) = delete;
};
#pragma pack(pop)


/***********************************************************************************************
 * ShapeSet::Get_Data -- Fetches pointer to raw shape data.                                    *
 *                                                                                             *
 *    This routine will return a pointer to the shape data. The data is actually a sub-        *
 *    rectangle within the logical shape rectangle. The sub-rectangle holds the non-           *
 *    transparent pixels. This fact, as retrieved by the Fetch_Rect function must be used      *
 *    for proper rendering of the shape.                                                       *
 *                                                                                             *
 * INPUT:   shape -- The shape number to extract the pointer for.                              *
 *                                                                                             *
 * OUTPUT:  Returns with a pointer to the raw shape data. If the shape does not exist in the   *
 *          data file, the returned value will be NULL. If the shape contains no pixels, then  *
 *          NULL is also returned.                                                             *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   02/26/1997 JLB : Created.                                                                 *
 *=============================================================================================*/
inline void* ShapeSet::Get_Data(int shape) const
{
    ShapeRecord const* record = Fetch_Record_Pointer(shape);
    if (record != nullptr && record->Data != 0) return (char*)this + record->Data;
    return nullptr;
}


/***********************************************************************************************
 * ShapeSet::Get_Rect -- Fetch the sub-rectangle of a shape.                                   *
 *                                                                                             *
 *    This routine will fetch the sub-rectangle for a particular shape. This rectangle is      *
 *    used to properly position the shape when rendering.                                      *
 *                                                                                             *
 * INPUT:   shape -- The shape number to fetch the rectangle for.                              *
 *                                                                                             *
 * OUTPUT:  Returns with the rectangle of the shape number specified.                          *
 *                                                                                             *
 * WARNINGS:   If the shape number is invalid or the shape has no pixels, the returned         *
 *             rectangle will not pass the Is_Valid() test.                                    *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   02/26/1997 JLB : Created.                                                                 *
 *=============================================================================================*/
inline Rect ShapeSet::Get_Rect(int shape) const
{
    ShapeRecord const* record = Fetch_Record_Pointer(shape);
    if (record != nullptr) {
        return {record->X, record->Y, record->Width, record->Height};
    }
    return RECT_NONE;
}


inline RGBClass ShapeSet::Get_Color(int shape) const
{
    ShapeRecord const* record = Fetch_Record_Pointer(shape);
    if (record != nullptr) {
        return {record->Color[0], record->Color[1], record->Color[2]};
    }
    return {0, 0, 0};
}


/***********************************************************************************************
 * ShapeSet::Is_Transparent -- Is the specified shape containing transparent pixels?           *
 *                                                                                             *
 *    This routine will check to see if the specified shape has any transparent pixels. If it  *
 *    doesn't, then faster blitting code can be used.                                          *
 *                                                                                             *
 * INPUT:   shape -- The shape to examine.                                                     *
 *                                                                                             *
 * OUTPUT:  bool; Does the shape contain any transparent pixels? The answer is also false if   *
 *                the shape number is invalid.                                                 *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   02/26/1997 JLB : Created.                                                                 *
 *=============================================================================================*/
inline bool ShapeSet::Is_Transparent(int shape) const
{
    ShapeRecord const* record = Fetch_Record_Pointer(shape);
    if (record != nullptr) {
        return record->Is_Transparent();
    }
    return false;
}


inline bool ShapeSet::Is_RLE_Compressed(int shape) const
{
    ShapeRecord const* record = Fetch_Record_Pointer(shape);
    if (record != nullptr) {
        return record->Is_RLE_Compressed();
    }
    return false;
}
