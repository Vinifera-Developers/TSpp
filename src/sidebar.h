/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          SIDEBAR.H
 *
 *  @authors       CCHyper, tomsons26
 *
 *  @brief         Class for the game sidebar interface.
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


#include "power.h"
#include "gcntrl.h"
#include "stage.h"


class FactoryClass;
class InitClass {};


class SidebarClass : public PowerClass
{
    public:
        enum {
            OBJECT_HEIGHT = 51,		// Pixel height of each buildable object.
		    OBJECT_WIDTH = 64,		// Pixel width of each buildable object.
            COLUMNS = 2,			// Number of side strips on sidebar.
            MAX_BUILDABLES = 75,	// Maximum number of object types in sidebar.
            SIDE_WIDTH = 168
        };

    public:
        SidebarClass();
        SidebarClass(const NoInitClass &x);
        ~SidebarClass();

        /**
         *  GScreenClass
         */
        virtual void One_Time() override;
        virtual void Init_Clear() override;
        virtual void Init_IO() override;
        virtual void AI(KeyNumType &input, Point2D &xy) override;
        virtual void Draw_It(bool forced = false) override;

        /**
         *  DisplayClass
         */
        virtual HRESULT Load(IStream *pStm) override;
        virtual HRESULT Save(IStream *pStm) override;
        virtual const char *Help_Text(int text) override;
        virtual void entry_84() override;

		/**
		 *  RadarClass
		 */
        virtual void Init_For_House() override;

        // 005F25E0
        void Reload_Sidebar();
        int Which_Column(RTTIType type);
        bool Factory_Link(FactoryClass *factory, RTTIType type, int id);
        bool Activate_Repair(int control);
        bool Activate_Upgrade(int control);
        bool Activate_Demolish(int control);
        bool Add(RTTIType type, int id);
        bool Scroll(bool up, int column);
        bool Scroll_Page(bool up, int column);
        // 005F38C0
        void Recalc();
        bool Activate(int control);
        bool Abandon_Production(RTTIType type, FactoryClass *factory);

        bool Is_On_Sidebar(RTTIType type, int id)
        {
            int column = Which_Column(type);
            return Column[column].Is_On_Sidebar(type, id);
        }

        void Redraw_Sidebar() { IsToRedraw = true; Flag_To_Redraw(false); }

    public:
        class StripClass : public StageClass
        {
            public:
                class SelectClass : public ControlClass
                {
                    public:
                        SelectClass();
                        SelectClass(const NoInitClass &x);

                        virtual bool Action(unsigned flags, KeyNumType &key) override;

                        void Set_Owner(StripClass &strip, int index);

                    public:
                        StripClass *Strip;
                        int Index;
                };

            public:
                StripClass();
                StripClass(const InitClass &);
                StripClass(const NoInitClass &);

                void One_Time(int id);
                ShapeFileStruct const *Get_Special_Cameo(SpecialWeaponType type);
                void Init_Clear();
                void Init_IO(int id);
                void Activate();
                void Deactivate();
                bool Add(RTTIType type, int id);
                bool Scroll(bool up);
                bool Scroll_Page(bool up);
                void Flag_To_Redraw();
                bool AI(KeyNumType &input, Point2D &xy);
                const char *Help_Text(int text);
                void Draw_It(bool complete);
                bool Recalc();
                bool Factory_Link(FactoryClass *factory, RTTIType type, int id);
                bool Abandon_Production(FactoryClass *factory);
                // 005F6030
                // 005F6080
                // 005F6620
                // 005F6670
                // 005F66E0

                bool Is_On_Sidebar(RTTIType type, int id) const
                {
                    for (int i = 0; i < BuildableCount; ++i) {
                        BuildType build = Buildables[i];
                        if (build.BuildableType == type && build.BuildableID == id) {
                            return true;
                        }
                    }
                    return false;
                }

            public:
                int X;
                int Y;
                Rect Size;
                int ID;
                bool IsToRedraw;
                bool IsBuilding;
                bool IsScrollingDown;
                bool IsScrolling;
                int Flasher;
                int TopIndex;
                int Scroller;
                int Slid;
                int LastSlid;
                int BuildableCount;

                typedef struct BuildType
                {
                    int BuildableID;
                    RTTIType BuildableType;
                    FactoryClass *Factory;
                } BuildType;
                BuildType Buildables[MAX_BUILDABLES];

        } Column[COLUMNS];

        bool field_1CD4;                // toggles cameo text?
        bool IsSidebarActive;
        bool IsToRedraw;
        bool field_1CD7;                // another redraw flag?
        bool field_1CD8;
        bool IsRepairActive;
        bool IsUpgradeActive;
        bool IsDemolishActive;

    public:
        class SBGadgetClass : public GadgetClass
        {
            public:
                SBGadgetClass();

                virtual bool Action(unsigned flags, KeyNumType &key) override;
        };
};
