/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TIBSUN_FUNCTIONS.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Global and uncategorised functions.
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
#include "tibsun_functions.h"
#include "tibsun_globals.h"
#include "object.h"
#include "objecttype.h"
#include "ccfile.h"


/***************************************************************************
**	These are the ASCII names for the cell land types.
*/
static const char * const LayerName[LAYER_COUNT] =
{
	"Underground",
	"Surface",
	"Ground",
	"Air",
	"Top"
};


/***************************************************************************
**	These are the ASCII names for the basic unit facing types.
*/
static const char * const FacingName[FACING_COUNT] =
{
	"north",
	"north-east",
	"east",
	"south-east",
	"south",
	"south-west",
	"west",
	"north-west"
};


/**
 *  Converts ASCII name into LandType.
 * 
 *  @author: CCHyper
 */
LayerType Layer_From_Name(const char *name)
{
	if (name) {
		for (LayerType layer = LAYER_FIRST; layer < LAYER_COUNT; ++layer) {
			if (stricmp(LayerName[layer], name) == 0) {
				return layer;
			}
		}
	}
	return LAYER_NONE;
}


/**
 *  Retrieves the name for the given LandType.
 * 
 *  @author: CCHyper
 */
const char *Name_From_Layer(LayerType layer)
{
	if (layer != LAYER_NONE && layer < LAYER_COUNT) {
		return LayerName[layer];
	}
	return "<none>";
}


/**
 *  Converts ASCII name into FacingType.
 * 
 *  @author: CCHyper
 */
FacingType Facing_From_Name(const char *name)
{
	if (name) {
		for (FacingType facing = FACING_FIRST; facing < FACING_COUNT; ++facing) {
			if (stricmp(FacingName[facing], name) == 0) {
				return facing;
			}
		}
	}
	return FACING_NONE;
}


/**
 *  Retrieves the name for the given FacingType.
 * 
 *  @author: CCHyper
 */
const char *Name_From_Facing(FacingType facing)
{
	if (facing != FACING_NONE && facing < FACING_COUNT) {
		return FacingName[facing];
	}
	return "<none>";
}


/**
 *  Causes all selected objects to become unselected except the object specified.
 * 
 *  @author: CCHyper
 */
void Unselect_All_Except(ObjectClass *object)
{
	int index = 0;
	while (index < CurrentObjects.Count()) {

		if (CurrentObjects[index] == object) {
			++index;
			continue;
		}

		int count_before = CurrentObjects.Count();
		CurrentObjects[index]->Unselect();

		if (count_before <= CurrentObjects.Count()) {
			CurrentObjects.Delete(CurrentObjects[index]);
		}
	}
}


/**
 *  Causes all selected objects to become unselected except the objecttype specified.
 * 
 *  @author: CCHyper
 */
void Unselect_All_Except(ObjectTypeClass *objecttype)
{
	int index = 0;
	while (index < CurrentObjects.Count()) {

		if (CurrentObjects[index]->Class_Of() == objecttype) {
			++index;
			continue;
		}

		int count_before = CurrentObjects.Count();
		CurrentObjects[index]->Unselect();

		if (count_before <= CurrentObjects.Count()) {
			CurrentObjects.Delete(CurrentObjects[index]);
		}
	}
}


/**
 *  Causes all selected objects to become unselected except the object type specified.
 * 
 *  @author: CCHyper
 */
void Unselect_All_Except(RTTIType rtti)
{
	int index = 0;
	while (index < CurrentObjects.Count()) {

		if (CurrentObjects[index]->What_Am_I() == rtti) {
			++index;
			continue;
		}

		int count_before = CurrentObjects.Count();
		CurrentObjects[index]->Unselect();

		if (count_before <= CurrentObjects.Count()) {
			CurrentObjects.Delete(CurrentObjects[index]);
		}
	}
}


/**
 *  Loads and allocates buffer for a file.
 * 
 *  @author: 10/17/1994 JLB
 */
void *Load_Alloc_Data(char const *name, int flags)
{
	CCFileClass file(name);
	return Load_Alloc_Data(file);
}


/**
 *  Allocates a buffer and loads the file into it.
 * 
 *  @author: 10/17/1994 JLB
 */
void *Load_Alloc_Data(FileClass &file)
{
	void *ptr = 0;
	long size = file.Size();

	ptr = new char [size];
	if (ptr) {
		file.Read(ptr, size);
	}

	return ptr;
}
