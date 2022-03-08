/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          BSURFACE.H
 *
 *  @authors       CCHyper
 *
 *  @brief         Buffered data surface class.
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

#include "xsurface.h"
#include "buff.h"


class BSurface : public XSurface
{
    public:
        BSurface();
        BSurface(int width, int height, int bpp, void *buffer = nullptr);
        virtual ~BSurface();

        virtual void *Lock(int x = 0, int y = 0) override;
        virtual int Get_Bytes_Per_Pixel() const override;
        virtual int Get_Pitch() const override;

    protected:
        void *Get_Buffer_Ptr() const { return BufferPtr.Get_Buffer(); }
        void *Get_Buffer_Ptr(int x, int y) { return (unsigned char *)BufferPtr.Get_Buffer() + (x * Get_Bytes_Per_Pixel()) + (y * Get_Pitch()); }

    protected:
        Buffer BufferPtr;
};
