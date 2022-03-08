/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          CONVERT.CPP
 *
 *  @authors       tomsons26
 *
 *  @brief         Palette drawer.
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
#include "convert.h"
#include "palette.h"
#include "mixfile.h"
#include "ccfile.h"


/**
 *  Creates a palette drawer.
 */
ConvertClass *ConvertClass::Create_Drawer(const char *pal_filename, PaletteClass *pal, XSurface *surface)
{
	const void *palfile = MFCC::Retrieve(pal_filename);
	if (!palfile) {
		return nullptr;
	}

	PaletteClass loaded_pal;
	std::memcpy(&loaded_pal, palfile, sizeof(PaletteClass));

	ConvertClass *drawer = new ConvertClass(&loaded_pal, pal, surface, 63, false);
	TSPP_ASSERT(drawer != nullptr);
	return drawer;
}
