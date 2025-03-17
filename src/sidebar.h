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
#include "shapebtn.h"
#include "stage.h"


class FactoryClass;
class InitClass {};


class SidebarClass : public PowerClass
{
    public:
        enum SideBarClassEnums
        {
            COLUMNS = 2,			// Number of side strips on sidebar.
            SIDE_WIDTH = 168,
            COLUMN_ONE_X = 24,
            COLUMN_ONE_Y = 26,
            COLUMN_TWO_Y = 26,
            COLUMN_TWO_X = 92,
            BUTTON_REPAIR_X_OFFSET = 31,
            BUTTON_REPAIR_Y_OFFSET = -9,
            BUTTON_SELL_X_OFFSET = 27,
            BUTTON_POWER_X_OFFSET = BUTTON_SELL_X_OFFSET,
            BUTTON_WAYPOINT_X_OFFSET = BUTTON_POWER_X_OFFSET,
        };

        typedef enum ButtonNumberType {
            BUTTON_RADAR = 100,
            BUTTON_REPAIR,
            BUTTON_POWER,
            BUTTON_SELL,
            BUTTON_WAYPOINT = 105,
        } ButtonNumberType;

    public:

        static const ShapeFileStruct*& SidebarShape;
        static const ShapeFileStruct*& SidebarMiddleShape;
        static const ShapeFileStruct*& SidebarBottomShape;
        static const ShapeFileStruct*& SidebarAddonShape;

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
        virtual void Set_Dimensions() override;

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
        void Blit_Sidebar(bool complete);
        void Recalc();
        bool Activate(int control);
        bool Abandon_Production(RTTIType type, FactoryClass *factory);

        bool Is_On_Sidebar(RTTIType type, int id)
        {
            int column = Which_Column(type);
            return Column[column].Is_On_Sidebar(type, id);
        }

        void Redraw_Sidebar() { IsToRedraw = true; Flag_To_Redraw(false); }
        void Redraw_Strip(int column) { IsToRedraw = true; Column[column].Flag_To_Redraw(); }

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
                ShapeFileStruct const *Get_Special_Cameo(SuperWeaponType type);
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
                void Set_Dimensions();
                // 005F6620
                // 005F6670

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

                enum SideBarGeneralEnums {
                    BUTTON_UP = 200,
                    BUTTON_DOWN = 210,
                    BUTTON_SELECT = 220,
                    MAX_BUILDABLES = 75,			                            // Maximum number of object types in sidebar. //ts
                    OBJECT_HEIGHT = 51,				                            // Pixel height of each buildable object. //ts
                    OBJECT_WIDTH = 64,				                            // Pixel width of each buildable object. //ts
                    OBJECT_NAME_OFFSET = 41,		                            // Offset of the cameo text from the cameo
                    //STRIP_WIDTH = 35,				                            // Width of strip (not counting border lines).
                    MAX_VISIBLE = 4,				                            // Number of object slots visible at any one time. //ts
                    SCROLL_RATE = 51,				                            // The pixel jump while scrolling (larger is faster). //ts
                    UP_X_OFFSET = 5,				                            // Scroll up arrow coordinates.
                    UP_Y_OFFSET = 25,
                    DOWN_X_OFFSET = UP_X_OFFSET,				                            // Scroll down arrow coordinates.
                    DOWN_Y_OFFSET = UP_Y_OFFSET,                                //BGint(MAX_VISIBLE)*int(OBJECT_HEIGHT)+1,
                    //SBUTTON_WIDTH = 16,				                            // Width of the mini-scroll button.
                    //SBUTTON_HEIGHT = 12,			                            // Height of the mini-scroll button.
                    //LEFT_EDGE_OFFSET = 2,			                            // Offset from left edge for building shapes.
                    TEXT_X_OFFSET = 30,				                            // X offset to print "ready" text.
                    TEXT_Y_OFFSET = 2,				                            // Y offset to print "ready" text.
                    QUEUE_COUNT_X_OFFSET = 60,				                    // X offset to print the queued unit count.
                };

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

                /*
                **	Pointer to the shape data for small versions of the logos. These are used as
                **	placeholder pieces on the side bar.
                */
                static const ShapeFileStruct*& LogoShape;

                /*
                **	This points to the animation sequence of frames used to mark the passage of time
                **	as an object is undergoing construction.
                */
                static const ShapeFileStruct*& ClockShape;
                static const ShapeFileStruct*& RechargeClockShape;

                static const ShapeFileStruct*& DarkenShape;

                static ShapeButtonClass (&UpButton)[COLUMNS];
                static ShapeButtonClass (&DownButton)[COLUMNS];
                static SelectClass (&SelectButton)[COLUMNS][20];

        } Column[COLUMNS];

        bool field_1CD4;                // toggles cameo text?
        bool IsSidebarActive;
        bool IsToRedraw;
        bool IsToFullRedraw;                // another redraw flag?
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

    static ShapeButtonClass& Repair;
    static ShapeButtonClass& Sell;
    static ShapeButtonClass& Power;
    static ShapeButtonClass& Waypoint;
    static SBGadgetClass& Background;
};

void Print_Cameo_Text(const char* string, Point2D& pos, Rect& bounds, int max_width);