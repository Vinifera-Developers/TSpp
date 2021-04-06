/*******************************************************************************
/*                     O P E N  S O U R C E  --  T S + +                      **
/*******************************************************************************
 *
 *  @project       TS++
 *
 *  @file          TSPP_DEFINITIONS.CPP
 *
 *  @authors       CCHyper
 *
 *  @brief         Main header file for the TS++ project.
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
#include "tspp.h"

#include "pipe.h"
#include "straw.h"
#include "rawfile.h"
#include "mixfile.h"
#include "wwkeyboard.h"
#include "options.h"
#include "buff.h"
#include "special.h"
#include "ramfile.h"
#include "bfiofile.h"
#include "cdfile.h"
#include "rules.h"
#include "surface.h"
#include "ccfile.h"
#include "wwmouse.h"
#include "wwcrc.h"
#include "xsurface.h"
#include "bsurface.h"
#include "dsurface.h"
#include "abstract.h"
#include "abstracttype.h"
#include "random.h"
#include "scenario.h"
#include "msglist.h"
#include "session.h"
#include "textprint.h"
#include "ini.h"
#include "ccini.h"
#include "objecttype.h"
#include "technotype.h"
#include "swizzle.h"
#include "buildingtype.h"
#include "rgb.h"
#include "hsv.h"
#include "palette.h"
#include "convert.h"
#include "lightconvert.h"
#include "isotiletype.h"
#include "command.h"
#include "tooltip.h"
#include "cctooltip.h"
#include "readline.h"
#include "filepcx.h"
#include "version.h"
#include "rle.h"
#include "cdctrl.h"
#include "wwfont.h"
#include "utracker.h"
#include "buildnum.h"
#include "link.h"
#include "counter.h"
#include "housetype.h"
#include "tracker.h"
#include "unittype.h"
#include "infantrytype.h"
#include "aircrafttype.h"
#include "combat.h"
#include "saveload.h"
#include "voxelanimtype.h"
#include "weapontype.h"
#include "bullettype.h"
#include "locomotion.h"
#include "wsproto.h"
#include "droppodlocomotion.h"
#include "quat.h"
#include "matrix3d.h"
#include "cell.h"
#include "warheadtype.h"
#include "tactical.h"
#include "fuse.h"
#include "overlaytype.h"
#include "base.h"
#include "event.h"
#include "queue.h"
#include "msgbox.h"
#include "spotlight.h"
#include "gscreen.h"
#include "crate.h"
#include "colorscheme.h"
#include "storage.h"
#include "scenarioini.h"
#include "map.h"
#include "layer.h"
#include "logic.h"
#include "gadget.h"
#include "control.h"


/**
 *  #NOTE:
 *  Any constructors defined here are because they are inlined in the games binary and
 *  redefining them in TS++ will cause the game to use the new virtual table, so to get
 *  around this we need to define the constructor then immediately override the virtual
 *  table pointer with the games table.
 *  
 */


/**
 *  Function definitions
 */
//DEFINE_IMPLEMENTATION_CONSTRUCTOR(Pipe::Pipe(), 0x);
Pipe::Pipe() : ChainTo(nullptr), ChainFrom(nullptr) { *((unsigned long *)this) = (unsigned long)0x006CDC84; }
DEFINE_IMPLEMENTATION(Pipe::~Pipe(), 0x005A9430);

//DEFINE_IMPLEMENTATION_CONSTRUCTOR(Straw::Straw(), 0x);
Straw::Straw() : ChainTo(nullptr), ChainFrom(nullptr) { *((unsigned long *)this) = (unsigned long)0x006CDC5C; }
DEFINE_IMPLEMENTATION(Straw::~Straw(), 0x0060AFC0);

//DEFINE_IMPLEMENTATION_CONSTRUCTOR(RawFileClass::RawFileClass(), 0x);
RawFileClass::RawFileClass() : Rights(FILE_ACCESS_READ), BiasStart(0), BiasLength(-1), Handle(INVALID_HANDLE_VALUE), Filename(nullptr), Date(0), Time(0), Allocated(false) { *((unsigned long *)this) = (unsigned long)0x006D5E34; }
DEFINE_IMPLEMENTATION_CONSTRUCTOR(RawFileClass::RawFileClass(const char *), 0x005BE310);
DEFINE_IMPLEMENTATION(RawFileClass::~RawFileClass(), 0x005BE290);
DEFINE_IMPLEMENTATION(const char* RawFileClass::File_Name() const, 0x005BDE00);
DEFINE_IMPLEMENTATION(const char* RawFileClass::Set_Name(const char *), 0x005BDE10);
DEFINE_IMPLEMENTATION(bool RawFileClass::Create(), 0x005BDB90);
DEFINE_IMPLEMENTATION(bool RawFileClass::Delete(), 0x005BDBB0);
DEFINE_IMPLEMENTATION(bool RawFileClass::Is_Available(bool), 0x005BDBD0);
DEFINE_IMPLEMENTATION(bool RawFileClass::Is_Open() const, 0x005BDBE0);
DEFINE_IMPLEMENTATION(bool RawFileClass::Open(const char *, FileAccessType), 0x005BDBF0);
DEFINE_IMPLEMENTATION(bool RawFileClass::Open(FileAccessType), 0x005BDC00);
DEFINE_IMPLEMENTATION(long RawFileClass::Read(void *, int), 0x005BDC50);
DEFINE_IMPLEMENTATION(off_t RawFileClass::Seek(off_t, FileSeekType), 0x005BDCD0);
DEFINE_IMPLEMENTATION(off_t RawFileClass::Size(), 0x005BDD50);
DEFINE_IMPLEMENTATION(long RawFileClass::Write(const void *, int), 0x005BDD60);
DEFINE_IMPLEMENTATION(void RawFileClass::Close(), 0x005BDDF0);
DEFINE_IMPLEMENTATION(LONG RawFileClass::Get_Date_Time() const, 0x005BDE20);
DEFINE_IMPLEMENTATION(bool RawFileClass::Set_Date_Time(LONG), 0x005BDE30);
DEFINE_IMPLEMENTATION(void RawFileClass::Error(FileErrorType, bool, const char *), 0x005BDE40);
DEFINE_IMPLEMENTATION(void RawFileClass::Bias(off_t, int), 0x005BEB20);
DEFINE_IMPLEMENTATION(off_t RawFileClass::Raw_Seek(off_t, FileSeekType), 0x005BEB90);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(MixFileClass::MixFileClass(const char *, const PKey *), 0x00559A10);
DEFINE_IMPLEMENTATION(MixFileClass::~MixFileClass(), 0x00559D40);
DEFINE_IMPLEMENTATION(void MixFileClass::Free(), 0x0055A190);
DEFINE_IMPLEMENTATION(bool MixFileClass::Free(const char *), 0x00559C80);
DEFINE_IMPLEMENTATION(bool MixFileClass::Cache(const Buffer *), 0x00559F30);
DEFINE_IMPLEMENTATION(bool MixFileClass::Cache(const char *, Buffer const *), 0x00559E90);
DEFINE_IMPLEMENTATION(bool MixFileClass::Offset(const char *, void **, MixFileClass **, long *, long *), 0x0055A1C0);
DEFINE_IMPLEMENTATION(const void* MixFileClass::Retrieve(const char *), 0x00559DE0);
DEFINE_IMPLEMENTATION(MixFileClass* MixFileClass::Finder(const char *), 0x00559E00);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(WWKeyboardClass::WWKeyboardClass(), 0x004FADC0);
DEFINE_IMPLEMENTATION(WWKeyboardClass::~WWKeyboardClass(), 0x004FADB0);
DEFINE_IMPLEMENTATION(unsigned short WWKeyboardClass::Check() const, 0x004FAF30);
DEFINE_IMPLEMENTATION(unsigned short WWKeyboardClass::Get(), 0x004FAF80);
DEFINE_IMPLEMENTATION(bool WWKeyboardClass::Put(unsigned short), 0x004FB0C0);
DEFINE_IMPLEMENTATION(void WWKeyboardClass::Clear(), 0x004FB4F0);
DEFINE_IMPLEMENTATION(bool WWKeyboardClass::Down(unsigned short), 0x004FB390);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(OptionsClass::OptionsClass(), 0x00589960);
DEFINE_IMPLEMENTATION(void OptionsClass::One_Time(), 0x00589A20);
DEFINE_IMPLEMENTATION(void OptionsClass::Set_Socket(), 0x0058A3D0);
DEFINE_IMPLEMENTATION(void OptionsClass::Set_Shuffle(bool), 0x00589A30);
DEFINE_IMPLEMENTATION(void OptionsClass::Set_Repeat(bool), 0x00589A60);
DEFINE_IMPLEMENTATION(void OptionsClass::Set_Score_Volume(double, bool), 0x00589A90);
DEFINE_IMPLEMENTATION(void OptionsClass::Set_Sound_Volume(double, bool), 0x00589B10);
DEFINE_IMPLEMENTATION(void OptionsClass::Set_Voice_Volume(double, bool), 0x00589B70);
DEFINE_IMPLEMENTATION(int OptionsClass::Normalize_Delay(int) const, 0x0058A600);
DEFINE_IMPLEMENTATION(int OptionsClass::Normalize_Volume(int) const, 0x0058A630);
DEFINE_IMPLEMENTATION(void OptionsClass::Load_Settings(), 0x00589C10);
DEFINE_IMPLEMENTATION(void OptionsClass::Save_Settings(), 0x0058A140);
DEFINE_IMPLEMENTATION(void OptionsClass::Set(), 0x0058A4E0);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(Buffer::Buffer(char *, long), 0x00425C70);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(Buffer::Buffer(void *, long), 0x00425C30);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(Buffer::Buffer(const void *, long), 0x00425CB0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(Buffer::Buffer(long), 0x00425CF0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(Buffer::Buffer(const Buffer &), 0x00425D20);
DEFINE_IMPLEMENTATION(Buffer::~Buffer(), 0x00425D80);
DEFINE_IMPLEMENTATION(Buffer& Buffer::operator=(const Buffer &), 0x00425D40);
DEFINE_IMPLEMENTATION(void Buffer::Reset(), 0x00425DB0);

DEFINE_IMPLEMENTATION(void SpecialClass::Init(), 0x005FCAA0);
DEFINE_IMPLEMENTATION(void SpecialClass::Read_INI(CCINIClass &), 0x005FCC60);
DEFINE_IMPLEMENTATION(void SpecialClass::Write_INI(CCINIClass &) const, 0x005FCAF0);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(RAMFileClass::RAMFileClass(void *, int), 0x005BDB00);
DEFINE_IMPLEMENTATION(RAMFileClass::~RAMFileClass(), 0x005BDB50);
DEFINE_IMPLEMENTATION(const char *RAMFileClass::File_Name() const, 0x005BDE00);
DEFINE_IMPLEMENTATION(const char *RAMFileClass::Set_Name(const char *), 0x005BDE10);
DEFINE_IMPLEMENTATION(bool RAMFileClass::Create(), 0x005BDB90);
DEFINE_IMPLEMENTATION(bool RAMFileClass::Delete(), 0x005BDBB0);
DEFINE_IMPLEMENTATION(bool RAMFileClass::Is_Available(bool), 0x005BDBD0);
DEFINE_IMPLEMENTATION(bool RAMFileClass::Is_Open() const, 0x005BDBE0);
DEFINE_IMPLEMENTATION(bool RAMFileClass::Open(const char *, FileAccessType), 0x005BDBF0);
DEFINE_IMPLEMENTATION(bool RAMFileClass::Open(FileAccessType), 0x005BDC00);
DEFINE_IMPLEMENTATION(long RAMFileClass::Read(void *, int), 0x005BDC50);
DEFINE_IMPLEMENTATION(off_t RAMFileClass::Seek(off_t, FileSeekType), 0x005BDCD0);
DEFINE_IMPLEMENTATION(off_t RAMFileClass::Size(), 0x005BDD50);
DEFINE_IMPLEMENTATION(long RAMFileClass::Write(const void *, int), 0x005BDD60);
DEFINE_IMPLEMENTATION(void RAMFileClass::Close(), 0x005BDDF0);
DEFINE_IMPLEMENTATION(LONG RAMFileClass::Get_Date_Time() const, 0x005BDE20);
DEFINE_IMPLEMENTATION(bool RAMFileClass::Set_Date_Time(LONG), 0x005BDE30);
DEFINE_IMPLEMENTATION(void RAMFileClass::Error(FileErrorType, bool, const char *), 0x005BDE40);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(BufferIOFileClass::BufferIOFileClass(), 0x00420D30);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(BufferIOFileClass::BufferIOFileClass(const char *), 0x00420C40);
DEFINE_IMPLEMENTATION(BufferIOFileClass::~BufferIOFileClass(), 0x00420D90);
DEFINE_IMPLEMENTATION(const char *BufferIOFileClass::Set_Name(const char *), 0x00421090);
DEFINE_IMPLEMENTATION(bool BufferIOFileClass::Is_Available(bool), 0x00421120);
DEFINE_IMPLEMENTATION(bool BufferIOFileClass::Is_Open() const, 0x00421140);
DEFINE_IMPLEMENTATION(bool BufferIOFileClass::Open(const char *, FileAccessType), 0x00421160);
DEFINE_IMPLEMENTATION(bool BufferIOFileClass::Open(FileAccessType), 0x00421180);
DEFINE_IMPLEMENTATION(long BufferIOFileClass::Read(void *, int), 0x004214C0);
DEFINE_IMPLEMENTATION(off_t BufferIOFileClass::Seek(off_t, FileSeekType), 0x004216D0);
DEFINE_IMPLEMENTATION(off_t BufferIOFileClass::Size(), 0x004217C0);
DEFINE_IMPLEMENTATION(long BufferIOFileClass::Write(const void *, int), 0x00421270);
DEFINE_IMPLEMENTATION(void BufferIOFileClass::Close(), 0x004217E0);
DEFINE_IMPLEMENTATION(bool BufferIOFileClass::Cache(long, void *), 0x00420DD0);
DEFINE_IMPLEMENTATION(void BufferIOFileClass::Free(), 0x00420FA0);
DEFINE_IMPLEMENTATION(bool BufferIOFileClass::Commit(), 0x00420FE0);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(CDFileClass::CDFileClass(), 0x00450610);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(CDFileClass::CDFileClass(const char *), 0x004505E0);
DEFINE_IMPLEMENTATION(const char *CDFileClass::Set_Name(const char *), 0x004509D0);
DEFINE_IMPLEMENTATION(bool CDFileClass::Open(const char *, FileAccessType), 0x00450AD0);
DEFINE_IMPLEMENTATION(bool CDFileClass::Open(FileAccessType), 0x00450690);
DEFINE_IMPLEMENTATION(int CDFileClass::Set_Search_Drives(char *), 0x004506F0);
DEFINE_IMPLEMENTATION(void CDFileClass::Add_Search_Drive(char *), 0x00450910);
DEFINE_IMPLEMENTATION(void CDFileClass::Clear_Search_Drives(), 0x00450980);
DEFINE_IMPLEMENTATION(void CDFileClass::Refresh_Search_Drives(), 0x004506A0);
DEFINE_IMPLEMENTATION(void CDFileClass::Set_CD_Drive(int), 0x00450960);
DEFINE_IMPLEMENTATION(bool CDFileClass::Find_First_File(char *), 0x00450B30);
DEFINE_IMPLEMENTATION(bool CDFileClass::Find_Next_File(char *), 0x00450C80);
DEFINE_IMPLEMENTATION(void CDFileClass::Find_Close(), 0x00450CF0);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(RulesClass::RulesClass(), 0x005C4350);
DEFINE_IMPLEMENTATION(RulesClass::~RulesClass(), 0x005C59B0);
DEFINE_IMPLEMENTATION(void RulesClass::Process(CCINIClass &), 0x005C6710);
DEFINE_IMPLEMENTATION(void RulesClass::Initialize(CCINIClass &), 0x005C6130);
DEFINE_IMPLEMENTATION(void RulesClass::Code_Pointers(IStream *), 0x005CE410);
DEFINE_IMPLEMENTATION(void RulesClass::Decode_Pointers(IStream *), 0x005CEA60);
DEFINE_IMPLEMENTATION(int RulesClass::Get_Art_Unique_ID(), 0x005D1B00);
DEFINE_IMPLEMENTATION(int RulesClass::Get_AI_Unique_ID(), 0x005D1BE0);
DEFINE_IMPLEMENTATION(void RulesClass::Load_Art_INI(), 0x005D1C10);
DEFINE_IMPLEMENTATION(bool RulesClass::AudioVisual(CCINIClass &), 0x005C6CF0);
DEFINE_IMPLEMENTATION(bool RulesClass::CrateRules(CCINIClass &), 0x005C8600);
DEFINE_IMPLEMENTATION(bool RulesClass::CombatDamage(CCINIClass &), 0x005C8850);
DEFINE_IMPLEMENTATION(bool RulesClass::Colors(CCINIClass &), 0x005C9530);
DEFINE_IMPLEMENTATION(bool RulesClass::General(CCINIClass &), 0x005C9630);
DEFINE_IMPLEMENTATION(bool RulesClass::MPlayer(CCINIClass &), 0x005CC260);
DEFINE_IMPLEMENTATION(bool RulesClass::Heap_Maximums(CCINIClass &), 0x005CC3D0);
DEFINE_IMPLEMENTATION(bool RulesClass::Infantry(CCINIClass &), 0x005CC420);
DEFINE_IMPLEMENTATION(bool RulesClass::Houses(CCINIClass &), 0x005CC490);
DEFINE_IMPLEMENTATION(bool RulesClass::Vehicles(CCINIClass &), 0x005CC500);
DEFINE_IMPLEMENTATION(bool RulesClass::Aircraft(CCINIClass &), 0x005CC570);
DEFINE_IMPLEMENTATION(bool RulesClass::Sides(CCINIClass &), 0x005CC5E0);
DEFINE_IMPLEMENTATION(bool RulesClass::SuperWeapons(CCINIClass &), 0x005CC780);
DEFINE_IMPLEMENTATION(bool RulesClass::Buildings(CCINIClass &), 0x005CC7F0);
DEFINE_IMPLEMENTATION(bool RulesClass::Terrains(CCINIClass &), 0x005CC860);
DEFINE_IMPLEMENTATION(bool RulesClass::Teams(CCINIClass &), 0x005CC8D0);
DEFINE_IMPLEMENTATION(bool RulesClass::Smudges(CCINIClass &), 0x005CC960);
DEFINE_IMPLEMENTATION(bool RulesClass::Overlays(CCINIClass &), 0x005CC9D0);
DEFINE_IMPLEMENTATION(bool RulesClass::Animations(CCINIClass &), 0x005CCA40);
DEFINE_IMPLEMENTATION(bool RulesClass::VoxelAnims(CCINIClass &), 0x005CCAB0);
DEFINE_IMPLEMENTATION(bool RulesClass::Warheads(CCINIClass &), 0x005CCB20);
DEFINE_IMPLEMENTATION(bool RulesClass::Particles(CCINIClass &), 0x005CCB90);
DEFINE_IMPLEMENTATION(bool RulesClass::ParticleSystems(CCINIClass &), 0x005CCC00);
DEFINE_IMPLEMENTATION(bool RulesClass::AI(CCINIClass &), 0x005CCC70);
DEFINE_IMPLEMENTATION(bool RulesClass::Powerups(CCINIClass &), 0x005CDCA0);
DEFINE_IMPLEMENTATION(bool RulesClass::Land_Types(CCINIClass &), 0x005CDDD0);
DEFINE_IMPLEMENTATION(bool RulesClass::IQ(CCINIClass &), 0x005CDEB0);
DEFINE_IMPLEMENTATION(bool RulesClass::JumpjetControls(CCINIClass &), 0x005CE040);
DEFINE_IMPLEMENTATION(bool RulesClass::Difficulty(CCINIClass &), 0x005CE190);
DEFINE_IMPLEMENTATION(bool RulesClass::Movies(CCINIClass &), 0x005CE310);
DEFINE_IMPLEMENTATION(bool RulesClass::Objects(CCINIClass &), 0x005D1800);
DEFINE_IMPLEMENTATION(void Difficulty_Get(CCINIClass &, DifficultyClass &, char const *), 0x005CE1E0);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(Surface::Surface(int, int), 0x0047C1C0);
DEFINE_IMPLEMENTATION(bool Surface::Can_Lock(int, int) const, 0x00406D50);
DEFINE_IMPLEMENTATION(bool Surface::entry_64(int, int) const, 0x00406D60);
DEFINE_IMPLEMENTATION(Rect Surface::Get_Rect() const, 0x00406D70);
DEFINE_IMPLEMENTATION(int Surface::Get_Width() const, 0x00406DA0);
DEFINE_IMPLEMENTATION(int Surface::Get_Height() const, 0x00406DB0);
DEFINE_IMPLEMENTATION(bool Surface::entry_80() const, 0x00406E20);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(CCFileClass::CCFileClass(), 0x004497F0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(CCFileClass::CCFileClass(const char *), 0x004497B0);
DEFINE_IMPLEMENTATION(CCFileClass::~CCFileClass(), 0x004E8970);
DEFINE_IMPLEMENTATION(bool CCFileClass::Is_Available(bool), 0x004499C0);
DEFINE_IMPLEMENTATION(bool CCFileClass::Is_Open() const, 0x00449A00);
DEFINE_IMPLEMENTATION(bool CCFileClass::Open(const char *, FileAccessType), 0x00407270);
DEFINE_IMPLEMENTATION(bool CCFileClass::Open(FileAccessType), 0x00449A40);
DEFINE_IMPLEMENTATION(long CCFileClass::Read(void *, int), 0x00449880);
DEFINE_IMPLEMENTATION(off_t CCFileClass::Seek(off_t, FileSeekType), 0x00449910);
DEFINE_IMPLEMENTATION(off_t CCFileClass::Size(), 0x00449970);
DEFINE_IMPLEMENTATION(long CCFileClass::Write(const void *, int), 0x00449850);
DEFINE_IMPLEMENTATION(void CCFileClass::Close(), 0x00449A10);
DEFINE_IMPLEMENTATION(LONG CCFileClass::Get_Date_Time() const, 0x00449B70);
DEFINE_IMPLEMENTATION(bool CCFileClass::Set_Date_Time(LONG), 0x00449C20);
DEFINE_IMPLEMENTATION(void CCFileClass::Error(FileErrorType error, bool, const char *), 0x00449820);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(WWMouseClass::WWMouseClass(XSurface *, HWND), 0x006A5000);
DEFINE_IMPLEMENTATION(WWMouseClass::~WWMouseClass(), 0x006A5170);
DEFINE_IMPLEMENTATION(void WWMouseClass::Set_Cursor(Point2D *, void *, int), 0x006A52A0);
DEFINE_IMPLEMENTATION(bool WWMouseClass::Is_Locked() const, 0x006A6910);
DEFINE_IMPLEMENTATION(void WWMouseClass::Hide_Mouse(), 0x006A6140);
DEFINE_IMPLEMENTATION(void WWMouseClass::Show_Mouse(), 0x006A5FE0);
DEFINE_IMPLEMENTATION(void WWMouseClass::Release_Mouse(), 0x006A62F0);
DEFINE_IMPLEMENTATION(void WWMouseClass::Capture_Mouse(), 0x006A6250);
DEFINE_IMPLEMENTATION(bool WWMouseClass::Is_Captured() const, 0x006A6920);
DEFINE_IMPLEMENTATION(void WWMouseClass::Conditional_Hide_Mouse(int, int, int, int), 0x006A63A0);
DEFINE_IMPLEMENTATION(void WWMouseClass::Conditional_Show_Mouse(), 0x006A63B0);
DEFINE_IMPLEMENTATION(int WWMouseClass::Get_Mouse_State() const, 0x006A5270);
DEFINE_IMPLEMENTATION(int WWMouseClass::Get_Mouse_X() const, 0x006A6930);
DEFINE_IMPLEMENTATION(int WWMouseClass::Get_Mouse_Y() const, 0x006A6940);
DEFINE_IMPLEMENTATION(Point2D WWMouseClass::Get_Mouse_XY() const, 0x006A6950);
DEFINE_IMPLEMENTATION(void WWMouseClass::Draw_1(XSurface *, bool), 0x006A5990);
DEFINE_IMPLEMENTATION(void WWMouseClass::Draw_2(XSurface *, bool), 0x006A5B90);
DEFINE_IMPLEMENTATION(void WWMouseClass::Confine_Pos(int &, int &) const, 0x006A63C0);
DEFINE_IMPLEMENTATION(void WWMouseClass::Calc_Confining_Rect(), 0x006A51E0);

DEFINE_IMPLEMENTATION(long WWCRCEngine::Calculate_CRC32(void *, int), 0x004710A0);
DEFINE_IMPLEMENTATION(void WWCRCEngine::operator()(char), 0x00470CC0);
DEFINE_IMPLEMENTATION(void WWCRCEngine::operator()(const char *), 0x00470E60);
DEFINE_IMPLEMENTATION(long WWCRCEngine::operator()(const void *, int), 0x00470E90);
DEFINE_IMPLEMENTATION(long WWCRCEngine::Value() const, 0x00471060);

XSurface::XSurface() : Surface(), LockLevel(0), BytesPerPixel(0) { *((unsigned long *)this) = (unsigned long)0x006CAC04; }
DEFINE_IMPLEMENTATION_CONSTRUCTOR(XSurface::XSurface(int, int), 0x0047CCA0);
XSurface::XSurface(int width, int height, int bpp) : Surface(width, height), LockLevel(0), BytesPerPixel(bpp) { *((unsigned long *)this) = (unsigned long)0x006CAC04; }
DEFINE_IMPLEMENTATION(bool XSurface::Copy_From(Rect &, Rect &, Surface &, Rect &, Rect &, bool, bool), 0x006A82B0);
DEFINE_IMPLEMENTATION(bool XSurface::Copy_From(Rect &, Surface &, Rect &, bool, bool), 0x006A8150);
DEFINE_IMPLEMENTATION(bool XSurface::Copy_From(Surface &, bool, bool), 0x006A80B0);
DEFINE_IMPLEMENTATION(bool XSurface::Fill_Rect(Rect &, unsigned), 0x006A7610);
DEFINE_IMPLEMENTATION(bool XSurface::Fill_Rect(Rect &, Rect &, unsigned), 0x006A75E0);
DEFINE_IMPLEMENTATION(bool XSurface::Fill(unsigned), 0x006A8070);
DEFINE_IMPLEMENTATION(bool XSurface::Fill_Rect_Trans(Rect &, const RGBClass &, unsigned), 0x006A7900);
DEFINE_IMPLEMENTATION(bool XSurface::Draw_Ellipse(Point2D, int, int, Rect, unsigned), 0x006A7910);
DEFINE_IMPLEMENTATION(bool XSurface::Put_Pixel(Point2D &, unsigned), 0x006A7470);
DEFINE_IMPLEMENTATION(unsigned XSurface::Get_Pixel(Point2D &), 0x006A7420);
DEFINE_IMPLEMENTATION(bool XSurface::Draw_Line(Point2D &, Point2D &, unsigned), 0x006A6BB0);
DEFINE_IMPLEMENTATION(bool XSurface::Draw_Line(Rect &, Point2D &, Point2D &, unsigned), 0x006A6BE0);
DEFINE_IMPLEMENTATION(bool XSurface::Draw_Line_entry_34(Rect &, Point2D &, Point2D &, unsigned, int, int, bool), 0x006A7120);
DEFINE_IMPLEMENTATION(bool XSurface::Draw_Line_entry_38(Rect &, Point2D &, Point2D &, int, int, int, bool), 0x006A7130);
DEFINE_IMPLEMENTATION(bool XSurface::Draw_Line_entry_3C(Rect &, Point2D &, Point2D &, RGBClass &, int, int, bool, bool, bool, bool, float), 0x006A7140);
DEFINE_IMPLEMENTATION(bool XSurface::entry_40(Rect &, Point2D &, Point2D &, void(*)(Point2D &)), 0x006A7150);
DEFINE_IMPLEMENTATION(int XSurface::Draw_Dashed_Line(Point2D &, Point2D &, unsigned, bool[], int), 0x006A6E90);
DEFINE_IMPLEMENTATION(int XSurface::entry_48(Point2D &, Point2D &, unsigned, bool[], int, bool), 0x006A7100);
DEFINE_IMPLEMENTATION(bool XSurface::entry_4C(Point2D &, Point2D &, unsigned, bool), 0x006A7110);
DEFINE_IMPLEMENTATION(bool XSurface::Draw_Rect(Rect &, unsigned), 0x006A7350);
DEFINE_IMPLEMENTATION(bool XSurface::Draw_Rect(Rect &, Rect &, unsigned), 0x006A7380);
DEFINE_IMPLEMENTATION(void* XSurface::Lock(int, int), 0x00406DC0);
DEFINE_IMPLEMENTATION(bool XSurface::Unlock(), 0x00406DD0);
DEFINE_IMPLEMENTATION(bool XSurface::Is_Locked() const, 0x00406DE0);
DEFINE_IMPLEMENTATION(bool XSurface::entry_80() const, 0x00406DF0);
DEFINE_IMPLEMENTATION(bool XSurface::entry_84(Point2D &, unsigned, Rect &), 0x006A7550);
DEFINE_IMPLEMENTATION(unsigned XSurface::entry_88(Point2D &, Rect &), 0x006A74D0);
DEFINE_IMPLEMENTATION(void XSurface::Fill_Circle(const Point2D, unsigned, Rect, unsigned), 0x006A7EE0);

BSurface::BSurface() : XSurface(), BufferPtr() { *((unsigned long *)this) = (unsigned long)0x006CAB74; }
BSurface::BSurface(int width, int height, int bpp, void *buffer) : XSurface(width, height, bpp), BufferPtr((void *)buffer, int((height * width) * bpp)) { *((unsigned long *)this) = (unsigned long)0x006CAB74; }
BSurface::~BSurface() {}
DEFINE_IMPLEMENTATION(void *BSurface::Lock(int, int), 0x00406E50);
DEFINE_IMPLEMENTATION(int BSurface::Get_Bytes_Per_Pixel() const, 0x00406E90);
DEFINE_IMPLEMENTATION(int BSurface::Get_Pitch() const, 0x00406EA0);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(DSurface::DSurface(), 0x0048AD10);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(DSurface::DSurface(int, int, bool), 0x0048ABB0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(DSurface::DSurface(LPDIRECTDRAWSURFACE), 0x0048B250);
DEFINE_IMPLEMENTATION(DSurface::~DSurface(), 0x0048ACA0);
DEFINE_IMPLEMENTATION(bool DSurface::Copy_From(Rect &, Rect &, Surface &, Rect &, Rect &, bool, bool), 0x0048B5E0);
DEFINE_IMPLEMENTATION(bool DSurface::Copy_From(Rect &, Surface &, Rect &, bool, bool), 0x0048B590);
DEFINE_IMPLEMENTATION(bool DSurface::Copy_From(Surface &, bool, bool), 0x004901A0);
DEFINE_IMPLEMENTATION(bool DSurface::Fill_Rect(Rect &, unsigned), 0x0048BB00);
DEFINE_IMPLEMENTATION(bool DSurface::Fill_Rect(Rect &, Rect &, unsigned), 0x0048BB30);
DEFINE_IMPLEMENTATION(bool DSurface::Fill_Rect_Trans(Rect &, const RGBClass &, unsigned), 0x0048BCE0);
DEFINE_IMPLEMENTATION(bool DSurface::Draw_Line_entry_34(Rect &, Point2D &, Point2D &, unsigned, int, int, bool), 0x0048EA90);
DEFINE_IMPLEMENTATION(bool DSurface::Draw_Line_entry_38(Rect &, Point2D &, Point2D &, int, int, int, bool), 0x0048C150);
DEFINE_IMPLEMENTATION(bool DSurface::Draw_Line_entry_3C(Rect &, Point2D &, Point2D &, RGBClass &, int, int, bool, bool, bool, bool, float), 0x0048CC00);
DEFINE_IMPLEMENTATION(int DSurface::entry_48(Point2D &, Point2D &, unsigned, bool[], int, bool), 0x0048F4B0);
DEFINE_IMPLEMENTATION(bool DSurface::entry_4C(Point2D &, Point2D &, unsigned, bool), 0x0048FB90);
DEFINE_IMPLEMENTATION(void *DSurface::Lock(int, int), 0x0048B370);
DEFINE_IMPLEMENTATION(bool DSurface::Unlock(), 0x0048B4D0);
DEFINE_IMPLEMENTATION(bool DSurface::Can_Lock(int, int) const, 0x0048B450);
DEFINE_IMPLEMENTATION(int DSurface::Get_Bytes_Per_Pixel() const, 0x0048B350);
DEFINE_IMPLEMENTATION(int DSurface::Get_Pitch() const, 0x0048B360);
DEFINE_IMPLEMENTATION(bool DSurface::Draw_Line_entry_90(Rect &, Point2D &, Point2D &, RGBClass &, RGBClass &, float &, float &), 0x0048E4B0);
DEFINE_IMPLEMENTATION(bool DSurface::Can_Blit() const, 0x0048B4B0);
DEFINE_IMPLEMENTATION(DSurface *DSurface::Create_Primary(DSurface **), 0x0048AD60);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE AbstractClass::QueryInterface(REFIID, LPVOID *), 0x00405BF0);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE AbstractClass::AddRef(), 0x00405C90);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE AbstractClass::Release(), 0x00405CA0);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE AbstractClass::IsDirty(), 0x00405E00);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE AbstractClass::GetSizeMax(ULARGE_INTEGER *), 0x00405D80);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE AbstractClass::Abstract_Load(IStream *), 0x00405D10);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE AbstractClass::Abstract_Save(IStream *, BOOL), 0x00405CB0);
DEFINE_IMPLEMENTATION(int AbstractClass::What_Am_I(), 0x00405BA0);
DEFINE_IMPLEMENTATION(int AbstractClass::Fetch_ID(), 0x00405BB0);
DEFINE_IMPLEMENTATION(VOID AbstractClass::Create_ID(), 0x00405BC0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(AbstractClass::AbstractClass(), 0x00405B50);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(AbstractClass::AbstractClass(const NoInitClass &), 0x00405B70);
DEFINE_IMPLEMENTATION(AbstractClass::~AbstractClass(), 0x00405B90);
DEFINE_IMPLEMENTATION(void AbstractClass::Init(), 0x00405E20);
DEFINE_IMPLEMENTATION(void AbstractClass::Detach(TARGET, bool), 0x00405E30);
DEFINE_IMPLEMENTATION(int AbstractClass::entry_34() const, 0x00405E40);
DEFINE_IMPLEMENTATION(void AbstractClass::Compute_CRC(WWCRCEngine &) const, 0x00405DB0);
DEFINE_IMPLEMENTATION(int AbstractClass::Owner() const, 0x00405E50);
DEFINE_IMPLEMENTATION(HouseClass *AbstractClass::Owning_House() const, 0x00405E60);
DEFINE_IMPLEMENTATION(int AbstractClass::Get_Heap_ID() const, 0x00405E70);
DEFINE_IMPLEMENTATION(bool AbstractClass::Is_Inactive() const, 0x00405DE0);
DEFINE_IMPLEMENTATION(CoordStruct AbstractClass::Center_Coord() const, 0x00405E80);
DEFINE_IMPLEMENTATION(CoordStruct AbstractClass::Target_Coord() const, 0x00405EB0);
DEFINE_IMPLEMENTATION(bool AbstractClass::On_Ground() const, 0x00405EE0);
DEFINE_IMPLEMENTATION(bool AbstractClass::In_Air() const, 0x00405EF0);
DEFINE_IMPLEMENTATION(CoordStruct AbstractClass::entry_5C() const, 0x00405F00);
DEFINE_IMPLEMENTATION(void AbstractClass::AI(), 0x00405F30);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(AbstractTypeClass::AbstractTypeClass(const char *), 0x004061D0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(AbstractTypeClass::AbstractTypeClass(const NoInitClass &), 0x00406310);
DEFINE_IMPLEMENTATION(AbstractTypeClass::~AbstractTypeClass(), 0x00406330);
DEFINE_IMPLEMENTATION(void AbstractTypeClass::Compute_CRC(WWCRCEngine &) const, 0x00406460);
DEFINE_IMPLEMENTATION(void AbstractTypeClass::entry_64(), 0x00406490);
DEFINE_IMPLEMENTATION(bool AbstractTypeClass::Read_INI(CCINIClass &), 0x004063A0);
DEFINE_IMPLEMENTATION(bool AbstractTypeClass::Write_INI(CCINIClass &) const, 0x00406430);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(RandomClass::RandomClass(unsigned), 0x005BDEE0);
DEFINE_IMPLEMENTATION(int RandomClass::operator()(), 0x005BDEF0);
DEFINE_IMPLEMENTATION(int RandomClass::operator()(int, int), 0x005BDF10);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(Random2Class::Random2Class(unsigned), 0x005BDF80);
DEFINE_IMPLEMENTATION(int Random2Class::operator()(), 0x005BE030);
DEFINE_IMPLEMENTATION(int Random2Class::operator()(int, int), 0x005BE080);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(Random3Class::Random3Class(unsigned, unsigned), 0x005BE120);
DEFINE_IMPLEMENTATION(int Random3Class::operator()(), 0x005BE140);
DEFINE_IMPLEMENTATION(int Random3Class::operator()(int, int), 0x005BE1A0);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(ScenarioClass::ScenarioClass(), 0x005DABC0);
ScenarioClass::~ScenarioClass() {}

DEFINE_IMPLEMENTATION_CONSTRUCTOR(MessageListClass::MessageListClass(), 0x00572E00);
DEFINE_IMPLEMENTATION(MessageListClass::~MessageListClass(), 0x00572E80);
DEFINE_IMPLEMENTATION(void MessageListClass::Init(int, int, int, int, int, int, int, int, int, int, int), 0x00572EA0);
DEFINE_IMPLEMENTATION(TextLabelClass* MessageListClass::Add_Message(char const *, int, char const *, ColorSchemeType, TextPrintType, int), 0x00572FE0);
DEFINE_IMPLEMENTATION(bool MessageListClass::Concat_Message(char const *, int, char const *, int), 0x005734B0);
DEFINE_IMPLEMENTATION(char* MessageListClass::Get_Message(int), 0x00573450);
DEFINE_IMPLEMENTATION(TextLabelClass* MessageListClass::Get_Label(int), 0x00573480);
DEFINE_IMPLEMENTATION(TextLabelClass* MessageListClass::Add_Edit(ColorSchemeType, TextPrintType, char *, char, int), 0x005737D0);
DEFINE_IMPLEMENTATION(void MessageListClass::Remove_Edit(), 0x00573950);
DEFINE_IMPLEMENTATION(char* MessageListClass::Get_Edit_Buf(), 0x005739B0);
DEFINE_IMPLEMENTATION(void MessageListClass::Set_Edit_Color(ColorSchemeType), 0x005739C0);
DEFINE_IMPLEMENTATION(bool MessageListClass::Manage(), 0x005739E0);
DEFINE_IMPLEMENTATION(int MessageListClass::Input(KeyNumType &), 0x00573AC0);
DEFINE_IMPLEMENTATION(void MessageListClass::Draw(), 0x00573DC0);
DEFINE_IMPLEMENTATION(int MessageListClass::Num_Messages(), 0x00573EC0);
DEFINE_IMPLEMENTATION(void MessageListClass::Set_Width(int), 0x00573EF0);
DEFINE_IMPLEMENTATION(void MessageListClass::Set_Edit_Focus(), 0x005737A0);
DEFINE_IMPLEMENTATION(bool MessageListClass::Has_Edit_Focus(), 0x005737B0);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(SessionClass::SessionClass(), 0x005ECD00);
DEFINE_IMPLEMENTATION(SessionClass::~SessionClass(), 0x005ED1C0);

DEFINE_IMPLEMENTATION(int Format_Window_String(char *, WWFontClass *, int, int &, int &), 0x00474960);
DEFINE_IMPLEMENTATION(Point2D Simple_Text_Print(const char *, XSurface *, Rect *, Point2D *, ColorScheme *, unsigned, TextPrintType, int), 0x00474A50);
DEFINE_IMPLEMENTATION(Point2D Plain_Text_Print(int, XSurface *, Rect *, Point2D *, unsigned, unsigned, TextPrintType, ColorSchemeType, int), 0x00475170);
DEFINE_IMPLEMENTATION(Point2D Plain_Text_Print(char const *, XSurface *, Rect *, Point2D *, unsigned, unsigned, TextPrintType, ColorSchemeType, int), 0x004751D0);
DEFINE_IMPLEMENTATION(Point2D Fancy_Text_Print(int, XSurface *, Rect *, Point2D *, ColorScheme *, unsigned, TextPrintType, ...), 0x00474D90);
DEFINE_IMPLEMENTATION(Point2D Fancy_Text_Print(const char *, XSurface *, Rect *, Point2D *, ColorScheme *, unsigned, TextPrintType, ...), 0x00474E70);
DEFINE_IMPLEMENTATION(Point2D Conquer_Clip_Text_Print(const char *, XSurface *, Rect *, Point2D *, ColorScheme *, unsigned, TextPrintType, int, const int *), 0x00474F50);

INIClass::INIClass() : SectionList(), SectionIndex(), LineComments(nullptr) { *((unsigned long *)this) = (unsigned long)0x006D193C; }
INIClass::INIClass(FileClass &file, bool load_comments) : SectionList(), SectionIndex(), LineComments(nullptr) { Load(file, load_comments); *((unsigned long *)this) = (unsigned long)0x006D193C; }
DEFINE_IMPLEMENTATION(INIClass::~INIClass(), 0x004DB470);
DEFINE_IMPLEMENTATION(bool INIClass::Load(FileClass &, bool), 0x004DB780);
DEFINE_IMPLEMENTATION(bool INIClass::Load(Straw &, bool), 0x004DB7D0);
DEFINE_IMPLEMENTATION(int INIClass::Save(FileClass &, bool) const, 0x004DC180);
DEFINE_IMPLEMENTATION(int INIClass::Save(Pipe &, bool) const, 0x004DC1C0);
DEFINE_IMPLEMENTATION(bool INIClass::Clear(const char *, const char *), 0x004DB540);
DEFINE_IMPLEMENTATION(int INIClass::Entry_Count(const char *) const, 0x004DC6A0);
DEFINE_IMPLEMENTATION(const char *INIClass::Get_Entry(const char *, int) const, 0x004DC8D0);
DEFINE_IMPLEMENTATION(int INIClass::Get_String(const char *, const char *, const char *, char *, int) const, 0x004DDF60);
DEFINE_IMPLEMENTATION(bool INIClass::Put_String(const char *, const char *, const char *), 0x004DDBE0);
DEFINE_IMPLEMENTATION(int INIClass::Get_Int(const char *, const char *, int) const, 0x004DD140);
DEFINE_IMPLEMENTATION(bool INIClass::Put_Int(const char *, const char *, int, int), 0x004DD0C0);
DEFINE_IMPLEMENTATION(int INIClass::Get_Hex(const char *, const char *, int) const, 0x004DD880);
DEFINE_IMPLEMENTATION(bool INIClass::Put_Hex(const char *, const char *, int), 0x004DD830);
DEFINE_IMPLEMENTATION(bool INIClass::Get_Bool(const char *, const char *, bool) const, 0x004DE140);
DEFINE_IMPLEMENTATION(bool INIClass::Put_Bool(const char *, const char *, bool), 0x004DE100);
DEFINE_IMPLEMENTATION(double INIClass::Get_Double(const char *, const char *, double) const, 0x004DD9F0);
DEFINE_IMPLEMENTATION(bool INIClass::Put_Double(const char *, const char *, double), 0x004DDB90);
DEFINE_IMPLEMENTATION(int INIClass::Get_TextBlock(const char *, char *, int) const, 0x004DCDE0);
DEFINE_IMPLEMENTATION(bool INIClass::Put_TextBlock(const char *, const char *), 0x004DCCF0);
DEFINE_IMPLEMENTATION(int INIClass::Get_UUBlock(const char *, void *, int) const, 0x004DCAD0);
DEFINE_IMPLEMENTATION(bool INIClass::Put_UUBlock(const char *, const void *, int), 0x004DC9A0);
DEFINE_IMPLEMENTATION(const TRect<int> INIClass::Get_Rect(const char *, const char *, const TRect<int> &) const, 0x004DD610);
DEFINE_IMPLEMENTATION(bool INIClass::Put_Rect(const char *, const char *, const TRect<int> &), 0x004DD5C0);
DEFINE_IMPLEMENTATION(const TPoint2D<int> INIClass::Get_Point(const char *, const char *, const TPoint2D<int> &) const, 0x004DE340);
DEFINE_IMPLEMENTATION(bool INIClass::Put_Point(const char *, const char *, const TPoint2D<int> &), 0x004DE300);
DEFINE_IMPLEMENTATION(const TPoint3D<int> INIClass::Get_Point(const char *, const char *, const TPoint3D<int> &) const, 0x004DE520);
DEFINE_IMPLEMENTATION(bool INIClass::Put_Point(const char *, const char *, const TPoint3D<int> &), 0x004DE4D0);
DEFINE_IMPLEMENTATION(const TPoint3D<double> INIClass::Get_Point(const char *, const char *, const TPoint3D<double> &) const, 0x004DE730);
DEFINE_IMPLEMENTATION(bool INIClass::Put_Point(const char *, const char *, const TPoint3D<double> &), 0x004DE6D0);
DEFINE_IMPLEMENTATION(const CLSID INIClass::Get_UUID(const char *, const char *, const CLSID) const, 0x004DD320);
DEFINE_IMPLEMENTATION(bool INIClass::Put_UUID(const char *, const char *, const CLSID), 0x004DD540);
DEFINE_IMPLEMENTATION(PKey INIClass::Get_PKey(bool) const, 0x004DEA30);
DEFINE_IMPLEMENTATION(bool INIClass::Put_PKey(const PKey &), 0x004DEA90);
DEFINE_IMPLEMENTATION(const INIClass::INISection * INIClass::Find_Section(const char *) const, 0x004DC550);
DEFINE_IMPLEMENTATION(const INIClass::INIEntry * INIClass::Find_Entry(const char *, const char *) const, 0x004DC770);

CCINIClass::CCINIClass() : INIClass(), IsDigestPresent(false) { *((unsigned long *)this) = (unsigned long)0x006CA8BC; }
CCINIClass::CCINIClass(FileClass &file, bool load_comments) : INIClass(file, load_comments), IsDigestPresent(false) { *((unsigned long *)this) = (unsigned long)0x006CA8BC; }
CCINIClass::~CCINIClass() {}
DEFINE_IMPLEMENTATION(bool CCINIClass::Load(FileClass &, bool), 0x00449F30);
DEFINE_IMPLEMENTATION(int CCINIClass::Load(Straw &, bool), 0x0044A060);
DEFINE_IMPLEMENTATION(int CCINIClass::Save(FileClass &, bool) const, 0x0044A170);
DEFINE_IMPLEMENTATION(int CCINIClass::Save(Pipe &, bool) const, 0x0044A280);
DEFINE_IMPLEMENTATION(LEPTON CCINIClass::Get_Lepton(const char *, const char *, const LEPTON), 0x0044A360);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_Lepton(const char *, const char *, LEPTON), 0x0044A3A0);
DEFINE_IMPLEMENTATION(unsigned CCINIClass::Get_Degree(const char *, const char *, unsigned) const, 0x0044A420);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_Degree(const char *, const char *, unsigned), 0x0044A3D0);
DEFINE_IMPLEMENTATION(CellStruct CCINIClass::Get_Cell(const char *, const char *, const CellStruct &), 0x0044A480);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_Cell(const char *, const char *, CellStruct &), 0x0044A500);
DEFINE_IMPLEMENTATION(CoordStruct CCINIClass::Get_Coord(const char *, const char *, const CoordStruct &), 0x0044BDE0);
DEFINE_IMPLEMENTATION(MPHType CCINIClass::Get_MPHType(const char *, const char *, const MPHType), 0x0044A550);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_MPHType(const char *, const char *, MPHType), 0x0044A5B0);
DEFINE_IMPLEMENTATION(PipScaleType CCINIClass::Get_PipType(const char *, const char *, const PipType), 0x0044A5E0);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_PipType(const char *, const char *, PipType), 0x0044A650);
DEFINE_IMPLEMENTATION(PipScaleType CCINIClass::Get_PipScaleType(const char *, const char *, const PipScaleType), 0x0044A680);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_PipScaleType(const char *, const char *, PipScaleType), 0x0044A6F0);
DEFINE_IMPLEMENTATION(CategoryType CCINIClass::Get_CategoryType(const char *, const char *, const CategoryType), 0x0044A720);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_CategoryType(const char *, const char *, CategoryType), 0x0044A760);
DEFINE_IMPLEMENTATION(ColorSchemeType CCINIClass::Get_ColorSchemeType(const char *, const char *, const ColorSchemeType), 0x0044A7D0);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_ColorSchemeType(const char *, const char *, ColorSchemeType), 0x0044A860);
DEFINE_IMPLEMENTATION(RGBStruct CCINIClass::Get_RGB(const char *, const char *, const RGBStruct &), 0x0044A890);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_RGB(const char *, const char *, RGBStruct &), 0x0044A960);
DEFINE_IMPLEMENTATION(HSVStruct CCINIClass::Get_HSV(const char *, const char *, const HSVStruct &), 0x0044A9B0);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_HSV(const char *, const char *, RGBStruct &), 0x0044AA90);
DEFINE_IMPLEMENTATION(BSizeType CCINIClass::Get_BSizeType(const char *, const char *, const BSizeType), 0x0044AAE0);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_BSizeType(const char *, const char *, BSizeType), 0x0044AB50);
DEFINE_IMPLEMENTATION(MZoneType CCINIClass::Get_MZoneType(const char *, const char *, const MZoneType), 0x0044AB80);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_MZoneType(const char *, const char *, MZoneType), 0x0044ABF0);
DEFINE_IMPLEMENTATION(ActionType CCINIClass::Get_ActionType(const char *, const char *, const ActionType), 0x0044AC20);
DEFINE_IMPLEMENTATION(SuperType CCINIClass::Get_SuperType(const char *, const char *, const SuperType), 0x0044AC90);
DEFINE_IMPLEMENTATION(VoxType CCINIClass::Get_VoxType(const char *, const char *, const VoxType), 0x0044ACE0);
DEFINE_IMPLEMENTATION(RTTIType CCINIClass::Get_RTTIType(const char *, const char *, const RTTIType), 0x0044AD50);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_RTTIType(const char *, const char *, RTTIType), 0x0044AD90);
DEFINE_IMPLEMENTATION(long CCINIClass::Get_Owners(const char *, const char *, const long), 0x0044ADC0);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_Owners(const char *, const char *, long), 0x0044AE40);
DEFINE_IMPLEMENTATION(ArmorType CCINIClass::Get_ArmorType(const char *, const char *, const ArmorType), 0x0044AF50);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_ArmorType(const char *, const char *, ArmorType), 0x0044AFA0);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_VocType(const char *, const char *, VocType), 0x0044AFC0);
DEFINE_IMPLEMENTATION(LandType CCINIClass::Get_LandType(const char *, const char *, const LandType), 0x0044B010);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_LandType(const char *, const char *, LandType), 0x0044B070);
DEFINE_IMPLEMENTATION(HousesType CCINIClass::Get_HousesType(const char *, const char *, const HousesType), 0x0044B0A0);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_HousesType(const char *, const char *, HousesType), 0x0044B150);
DEFINE_IMPLEMENTATION(SideType CCINIClass::Get_SideType(const char *, const char *, const SideType), 0x0044B180);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_SideType(const char *, const char *, SideType), 0x0044B240);
DEFINE_IMPLEMENTATION(VQType CCINIClass::Get_VQType(const char *, const char *, const VQType), 0x0044B270);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_VQType(const char *, const char *, VQType), 0x0044B2C0);
DEFINE_IMPLEMENTATION(TheaterType CCINIClass::Get_TheaterType(const char *, const char *, const TheaterType), 0x0044B310);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_TheaterType(const char *, const char *, TheaterType), 0x0044B360);
DEFINE_IMPLEMENTATION(ThemeType CCINIClass::Get_ThemeType(const char *, const char *, const ThemeType), 0x0044B390);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_ThemeType(const char *, const char *, ThemeType), 0x0044B3F0);
DEFINE_IMPLEMENTATION(SourceType CCINIClass::Get_SourceType(const char *, const char *, const SourceType), 0x0044B420);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_SourceType(const char *, const char *, SourceType), 0x0044B470);
DEFINE_IMPLEMENTATION(CrateType CCINIClass::Get_CrateType(const char *, const char *, const CrateType), 0x0044B490);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_CrateType(const char *, const char *, CrateType), 0x0044B4E0);
DEFINE_IMPLEMENTATION(SpeedType CCINIClass::Get_SpeedType(const char *, const char *, const SpeedType), 0x0044CAA0);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_SpeedType(const char *, const char *, SpeedType), 0x0044CB00);
DEFINE_IMPLEMENTATION(AbilitiesStruct CCINIClass::Get_Ability(const char *, const char *, const AbilitiesStruct &), 0x0044CEF0);
DEFINE_IMPLEMENTATION_UNWIND(TypeList<RGBStruct> CCINIClass::Get_RGB_List(const char *, const char *, const TypeList<RGBStruct>), 0x0044C5C0);
DEFINE_IMPLEMENTATION_UNWIND(TypeList<int> CCINIClass::Get_Integer_List(const char *, const char *, const TypeList<int>), 0x0044B810);
DEFINE_IMPLEMENTATION_UNWIND(TypeList<TechnoTypeClass*> CCINIClass::Get_TechnoType_List(const char *, const char *, const TypeList<TechnoTypeClass *>), 0x0044BF90);
DEFINE_IMPLEMENTATION_UNWIND(bool CCINIClass::Put_TechnoType_List(const char *, const char *, const TypeList<TechnoTypeClass *>), 0x0044C190);
DEFINE_IMPLEMENTATION_UNWIND(TypeList<SideType> CCINIClass::Get_SideType_List(const char *, const char *, const TypeList<SideType>), 0x0044C260);
DEFINE_IMPLEMENTATION_UNWIND(TypeList<HousesType> CCINIClass::Get_HousesType_List(const char *, const char *, const TypeList<HousesType>), 0x0044C4C0);
DEFINE_IMPLEMENTATION(xTargetClass CCINIClass::Get_Target(const char *, const char *, const xTargetClass), 0x0044C950);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_Target(const char *, const char *, xTargetClass), 0x0044CA50);
DEFINE_IMPLEMENTATION(int CCINIClass::Get_Unique_ID() const, 0x0044C820);
DEFINE_IMPLEMENTATION(void CCINIClass::Calculate_Message_Digest(), 0x0044C8C0);
DEFINE_IMPLEMENTATION(void CCINIClass::Invalidate_Message_Digest(), 0x0044C940);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE ObjectTypeClass::GetSizeMax(ULARGE_INTEGER *), 0x00588FC0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE ObjectTypeClass::Load(IStream *), 0x00588DD0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE ObjectTypeClass::Save(IStream *, BOOL), 0x00588FA0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(ObjectTypeClass::ObjectTypeClass(const char *), 0x00587620);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(ObjectTypeClass::ObjectTypeClass(const NoInitClass &), 0x00587810);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(ObjectTypeClass::~ObjectTypeClass(), 0x005878B0);
DEFINE_IMPLEMENTATION(bool ObjectTypeClass::Read_INI(CCINIClass &), 0x00588A20);
DEFINE_IMPLEMENTATION(CoordStruct ObjectTypeClass::Coord_Fixup(CoordStruct *) const, 0x00410180);
DEFINE_IMPLEMENTATION(int ObjectTypeClass::Get_Ownable() const, 0x00419B90);
DEFINE_IMPLEMENTATION(int ObjectTypeClass::Max_Pips() const, 0x005879E0);
DEFINE_IMPLEMENTATION(Point3D ObjectTypeClass::Pixel_Dimensions() const, 0x005879F0);
DEFINE_IMPLEMENTATION(Point3D ObjectTypeClass::Lepton_Dimensions() const, 0x00587A10);
DEFINE_IMPLEMENTATION(int ObjectTypeClass::Cost_Of(HouseClass *) const, 0x00587A40);
DEFINE_IMPLEMENTATION(int ObjectTypeClass::Time_To_Build() const, 0x00587A50);
DEFINE_IMPLEMENTATION(CellStruct * ObjectTypeClass::Occupy_List(bool) const, 0x00587A70);
DEFINE_IMPLEMENTATION(BuildingClass * const ObjectTypeClass::Who_Can_Build_Me(bool, bool, bool, HouseClass *) const, 0x00587B20);
DEFINE_IMPLEMENTATION(ShapeFileStruct * const ObjectTypeClass::Get_Cameo_Data() const, 0x00587A60);
DEFINE_IMPLEMENTATION(ShapeFileStruct * const ObjectTypeClass::Get_Image_Data() const, 0x004101A0);
DEFINE_IMPLEMENTATION(ObjectTypeClass * ObjectTypeClass::From_Name(const char *), 0x00588FE0);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE TechnoTypeClass::GetSizeMax(ULARGE_INTEGER *), 0x0063E170);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TechnoTypeClass::Load(IStream *), 0x0063D8F0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TechnoTypeClass::Save(IStream *, BOOL), 0x0063DF00);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(TechnoTypeClass::TechnoTypeClass(const char *, SpeedType), 0x0063ADE0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(TechnoTypeClass::TechnoTypeClass(const NoInitClass &), 0x0063B480);
DEFINE_IMPLEMENTATION(TechnoTypeClass::~TechnoTypeClass(), 0x0063B5F0);
DEFINE_IMPLEMENTATION(int TechnoTypeClass::entry_34() const, 0x004101B0);
DEFINE_IMPLEMENTATION(void TechnoTypeClass::Compute_CRC(WWCRCEngine &) const, 0x0063E210);
DEFINE_IMPLEMENTATION(bool TechnoTypeClass::Read_INI(CCINIClass &), 0x0063B9B0);
DEFINE_IMPLEMENTATION(int TechnoTypeClass::Get_Ownable() const, 0x0063B890);
DEFINE_IMPLEMENTATION(int TechnoTypeClass::Max_Pips() const, 0x0063D460);
DEFINE_IMPLEMENTATION(int TechnoTypeClass::Cost_Of(HouseClass *) const, 0x0063B8D0);
DEFINE_IMPLEMENTATION(int TechnoTypeClass::Time_To_Build() const, 0x0063B8B0);
DEFINE_IMPLEMENTATION(ShapeFileStruct* const TechnoTypeClass::Get_Cameo_Data() const, 0x0063B910);
DEFINE_IMPLEMENTATION(bool TechnoTypeClass::Legal_Placement(CellStruct &, HouseClass *) const, 0x0063D320);
DEFINE_IMPLEMENTATION(int TechnoTypeClass::Raw_Cost() const, 0x0063B880);
DEFINE_IMPLEMENTATION(int TechnoTypeClass::Repair_Cost() const, 0x0063B920);
DEFINE_IMPLEMENTATION(int TechnoTypeClass::Repair_Step() const, 0x0063B970);
DEFINE_IMPLEMENTATION(int TechnoTypeClass::Flight_Level() const, 0x0063E700);
DEFINE_IMPLEMENTATION(bool TechnoTypeClass::Is_Two_Shooter() const, 0x0063B980);
DEFINE_IMPLEMENTATION(const WeaponControlStruct & TechnoTypeClass::Fetch_Weapon_Control(WeaponSlotType) const, 0x0063E6B0);
DEFINE_IMPLEMENTATION(bool TechnoTypeClass::In_Range(CoordStruct &, TARGET, WeaponTypeClass *), 0x0063D4C0);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE SwizzleManagerClass::QueryInterface(REFIID, LPVOID *), 0x0060DC60);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE SwizzleManagerClass::AddRef(), 0x0060DCE0);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE SwizzleManagerClass::Release(), 0x0060DCF0);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE SwizzleManagerClass::Reset(), 0x0060DA60);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE SwizzleManagerClass::Swizzle(void **), 0x0060DA70);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE SwizzleManagerClass::Fetch_Swizzle_ID(void *, LONG *), 0x0060DCC0);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE SwizzleManagerClass::Here_I_Am(LONG, void *), 0x0060DAF0);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE SwizzleManagerClass::Save_Interface(IStream *, IUnknown *), 0x0060DD00);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE SwizzleManagerClass::Load_Interface(IStream *, CLSID *, void **), 0x0060DD10);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE SwizzleManagerClass::Get_Save_Size(LONG *), 0x0060DC40);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(SwizzleManagerClass::SwizzleManagerClass(), 0x0060D9B0);
DEFINE_IMPLEMENTATION(SwizzleManagerClass::~SwizzleManagerClass(), 0x0060DA00);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE BuildingTypeClass::GetClassID(CLSID *), 0x004434F0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE BuildingTypeClass::Load(IStream *), 0x00443350);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE BuildingTypeClass::Save(IStream *, BOOL), 0x004434D0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(BuildingTypeClass::BuildingTypeClass(const char *), 0x0043F410);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(BuildingTypeClass::BuildingTypeClass(const NoInitClass &), 0x0043F8C0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(BuildingTypeClass::~BuildingTypeClass(), 0x0043F8F0);
DEFINE_IMPLEMENTATION(RTTIType BuildingTypeClass::Kind_Of() const, 0x00443FC0);
DEFINE_IMPLEMENTATION(int BuildingTypeClass::Size_Of(bool) const, 0x00443FD0);
DEFINE_IMPLEMENTATION(int BuildingTypeClass::entry_34() const, 0x00444000);
DEFINE_IMPLEMENTATION(void BuildingTypeClass::Compute_CRC(WWCRCEngine &) const, 0x00442F20);
DEFINE_IMPLEMENTATION(int BuildingTypeClass::Get_Heap_ID() const, 0x00444010);
DEFINE_IMPLEMENTATION(bool BuildingTypeClass::Read_INI(CCINIClass &), 0x00440AD0);
DEFINE_IMPLEMENTATION(CoordStruct BuildingTypeClass::Coord_Fixup(CoordStruct *) const, 0x00442E50);
DEFINE_IMPLEMENTATION(int BuildingTypeClass::Max_Pips() const, 0x0043FF90);
DEFINE_IMPLEMENTATION(Point3D BuildingTypeClass::Pixel_Dimensions() const, 0x0043FE50);
DEFINE_IMPLEMENTATION(Point3D BuildingTypeClass::Lepton_Dimensions() const, 0x00442ED0);
DEFINE_IMPLEMENTATION(bool BuildingTypeClass::Create_And_Place(CellStruct &, HouseClass *) const, 0x0043FA60);
DEFINE_IMPLEMENTATION(int BuildingTypeClass::Cost_Of(HouseClass *) const, 0x00440080);
DEFINE_IMPLEMENTATION(ObjectClass * const BuildingTypeClass::Create_One_Of(HouseClass *) const, 0x0043FED0);
DEFINE_IMPLEMENTATION(CellStruct * BuildingTypeClass::Occupy_List(bool) const, 0x0043FED0);
DEFINE_IMPLEMENTATION(ShapeFileStruct * const BuildingTypeClass::Get_Image_Data() const, 0x004402F0);
DEFINE_IMPLEMENTATION(bool BuildingTypeClass::Legal_Placement(CellStruct &, HouseClass *) const, 0x00442EA0);
DEFINE_IMPLEMENTATION(int BuildingTypeClass::Raw_Cost() const, 0x00440000);
DEFINE_IMPLEMENTATION(ShapeFileStruct *const BuildingTypeClass::Get_Buildup_Data(), 0x00443BC0);
DEFINE_IMPLEMENTATION(int BuildingTypeClass::Width() const, 0x0043FF40);
DEFINE_IMPLEMENTATION(int BuildingTypeClass::Height(bool) const, 0x0043FF50);
DEFINE_IMPLEMENTATION(void BuildingTypeClass::Init_Anim(BStateType, int, int, int) const, 0x0043FB10);

RGBClass::RGBClass() : Red(0), Green(0), Blue(0) {}
RGBClass::RGBClass(const RGBStruct &that) : Red(that.R), Green(that.G), Blue(that.B) {}
RGBClass::RGBClass(const RGBClass &that) : Red(that.Red), Green(that.Green), Blue(that.Blue) {}
RGBClass::RGBClass(unsigned char red, unsigned char green, unsigned char blue) : Red(red), Green(green), Blue(blue) {}
DEFINE_IMPLEMENTATION(RGBClass::operator HSVClass () const, 0x005C32E0);
DEFINE_IMPLEMENTATION(void RGBClass::Adjust(int, const RGBClass &), 0x005C3200);
DEFINE_IMPLEMENTATION(int RGBClass::Difference(const RGBClass &) const, 0x005C3290);
DEFINE_IMPLEMENTATION(RGBClass RGBClass::Average(const RGBClass &) const, 0x005C3200);
DEFINE_IMPLEMENTATION(RGBClass *RGBClass::Adjust_Brightness(RGBClass &, float), 0x005C30D0);
DEFINE_IMPLEMENTATION(RGBClass *RGBClass::Lerp(RGBClass &, RGBClass &, float), 0x005C2F60);

HSVClass::HSVClass() : Hue(0), Saturation(0), Value(0) {}
HSVClass::HSVClass(const HSVStruct &that) : Hue(that.H), Saturation(that.S), Value(that.V) {}
HSVClass::HSVClass(const HSVClass &that) : Hue(that.Hue), Saturation(that.Saturation), Value(that.Value) {}
HSVClass::HSVClass(unsigned char hue, unsigned char saturation, unsigned char value) : Hue(hue), Saturation(saturation), Value(value) {}
DEFINE_IMPLEMENTATION(HSVClass::operator RGBClass () const, 0x004D1C60);
DEFINE_IMPLEMENTATION(void HSVClass::Adjust(int, const HSVClass &), 0x004D1B80);
DEFINE_IMPLEMENTATION(int HSVClass::Difference(const HSVClass &) const, 0x004D1C10);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(PaletteClass::PaletteClass(const RGBClass &), 0x005A2810);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(PaletteClass::PaletteClass(const PaletteClass &), 0x005A2860);
PaletteClass::~PaletteClass() {}
DEFINE_IMPLEMENTATION(void PaletteClass::Adjust(int), 0x005A28E0);
DEFINE_IMPLEMENTATION(void PaletteClass::Adjust(int, const PaletteClass &), 0x005A2910);
DEFINE_IMPLEMENTATION(void PaletteClass::Partial_Adjust(int, char *), 0x005A2960);
DEFINE_IMPLEMENTATION(void PaletteClass::Partial_Adjust(int, const PaletteClass &, char *), 0x005A29A0);
DEFINE_IMPLEMENTATION(int PaletteClass::Closest_Color(RGBClass &) const, 0x005A29F0);

ConvertClass::ConvertClass() {}
DEFINE_IMPLEMENTATION_CONSTRUCTOR(ConvertClass::ConvertClass(PaletteClass *, PaletteClass *, XSurface *, int, bool), 0x00463C40);
DEFINE_IMPLEMENTATION(ConvertClass::~ConvertClass(), 0x00465970);
DEFINE_IMPLEMENTATION(void ConvertClass::Alloc_Blitters(), 0x00464100);
DEFINE_IMPLEMENTATION(void ConvertClass::Dealloc_Blitters(), 0x00465A00);
DEFINE_IMPLEMENTATION(Blitter *ConvertClass::Select_Blitter(int), 0x00466130);
DEFINE_IMPLEMENTATION(RLEBlitter *ConvertClass::Select_RLE_Blitter(int), 0x00466410);
DEFINE_IMPLEMENTATION(void ConvertClass::Recalc_Color_Remap_Tables(int, int, int, int), 0x004666C0);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(LightConvertClass::LightConvertClass(PaletteClass *, PaletteClass *, Surface *, int, int, int, bool, bool *, int), 0x00502A00);
LightConvertClass::~LightConvertClass() {}
DEFINE_IMPLEMENTATION(void LightConvertClass::Adjust(int, int, int, bool), 0x00502B90);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE IsometricTileTypeClass::GetClassID(CLSID *), 0x004F86B0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE IsometricTileTypeClass::Load(IStream *), 0x004F85B0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE IsometricTileTypeClass::Save(IStream *, BOOL), 0x004F8690);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(IsometricTileTypeClass::IsometricTileTypeClass(IsometricTileType, char, char, const char *, bool), 0x004F30A0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(IsometricTileTypeClass::IsometricTileTypeClass(const NoInitClass &), 0x004F32D0);
DEFINE_IMPLEMENTATION(IsometricTileTypeClass::~IsometricTileTypeClass(), 0x004F3330);
DEFINE_IMPLEMENTATION(RTTIType IsometricTileTypeClass::Kind_Of() const, 0x004F8A90);
DEFINE_IMPLEMENTATION(int IsometricTileTypeClass::Size_Of(bool) const, 0x004F8AA0);
DEFINE_IMPLEMENTATION(void IsometricTileTypeClass::Compute_CRC(WWCRCEngine &) const, 0x004F84A0);
DEFINE_IMPLEMENTATION(int IsometricTileTypeClass::Get_Heap_ID() const, 0x004F8AB0);
DEFINE_IMPLEMENTATION(CoordStruct IsometricTileTypeClass::Coord_Fixup(CoordStruct *) const, 0x004F8480);
DEFINE_IMPLEMENTATION(bool IsometricTileTypeClass::Create_And_Place(CellStruct &, HouseClass *) const, 0x004F83D0);
DEFINE_IMPLEMENTATION(ObjectClass *const IsometricTileTypeClass::Create_One_Of(HouseClass *) const, 0x004F8410);
DEFINE_IMPLEMENTATION(CellStruct *IsometricTileTypeClass::Occupy_List(bool) const, 0x004F35E0);
DEFINE_IMPLEMENTATION(ShapeFileStruct *const IsometricTileTypeClass::Get_Image_Data() const, 0x004F3570);

CommandClass::CommandClass() { *((unsigned long *)this) = (unsigned long)0x006D2AF4; }
CommandClass::~CommandClass() {}

DEFINE_IMPLEMENTATION_CONSTRUCTOR(ToolTipManager::ToolTipManager(HWND), 0x00647190);
DEFINE_IMPLEMENTATION(ToolTipManager::~ToolTipManager(), 0x00647240);
DEFINE_IMPLEMENTATION(bool ToolTipManager::Update(const ToolTipText *), 0x00647B60);
DEFINE_IMPLEMENTATION(void ToolTipManager::Reset(const ToolTipText *), 0x00647B70);
DEFINE_IMPLEMENTATION(void ToolTipManager::entry_C(bool), 0x00647C40);
DEFINE_IMPLEMENTATION(void ToolTipManager::Draw(const ToolTipText *), 0x00647C70);
DEFINE_IMPLEMENTATION(const char *ToolTipManager::ToolTip_Text(int), 0x00647C90);
DEFINE_IMPLEMENTATION(void ToolTipManager::Set_Active(bool), 0x00647330);
DEFINE_IMPLEMENTATION(void ToolTipManager::Message_Handler(MSG *), 0x00647390);
DEFINE_IMPLEMENTATION(int ToolTipManager::Get_Timer_Delay() const, 0x006475F0);
DEFINE_IMPLEMENTATION(void ToolTipManager::Set_Timer_Delay(int), 0x00647600);
DEFINE_IMPLEMENTATION(int ToolTipManager::Get_Lifetime() const, 0x00647610);
DEFINE_IMPLEMENTATION(void ToolTipManager::Set_Lifetime(int), 0x00647620);
DEFINE_IMPLEMENTATION(bool ToolTipManager::Find(int id, ToolTip *), 0x00647980);
DEFINE_IMPLEMENTATION(bool ToolTipManager::Add(const ToolTip *), 0x00647640);
DEFINE_IMPLEMENTATION(void ToolTipManager::Remove(int), 0x006477F0);
DEFINE_IMPLEMENTATION(int ToolTipManager::Get_Count() const, 0x00647630);

CCToolTip::CCToolTip(HWND hWnd) : ToolTipManager(hWnd), field_15C(false), Style(TPF_MAP) { Set_Timer_Delay(500); *((unsigned long *)this) = (unsigned long)0x006D9E4C; }
CCToolTip::~CCToolTip() {}
DEFINE_IMPLEMENTATION(bool CCToolTip::Update(const ToolTipText *), 0x0044E3B0);
DEFINE_IMPLEMENTATION(void CCToolTip::Reset(const ToolTipText *), 0x0044E530);
DEFINE_IMPLEMENTATION(void CCToolTip::entry_C(bool), 0x0044E590);
DEFINE_IMPLEMENTATION(void CCToolTip::Draw(const ToolTipText *), 0x0044E5B0);
DEFINE_IMPLEMENTATION(const char *CCToolTip::ToolTip_Text(int), 0x0044E720);

DEFINE_IMPLEMENTATION(int Read_Line(FileClass &, char *, int, bool &), 0x005BECA0);
DEFINE_IMPLEMENTATION(int Read_Line(Straw &, char *, int, bool &), 0x005BED50);

DEFINE_IMPLEMENTATION(Surface *Read_PCX_File(FileClass *, unsigned char *, void *, long), 0x005A79A0);
DEFINE_IMPLEMENTATION(bool Write_PCX_File(FileClass *, Surface &, unsigned char *), 0x0069FAE0);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(VersionClass::VersionClass(), 0x00663B30);
VersionClass::~VersionClass() {}
DEFINE_IMPLEMENTATION(unsigned long VersionClass::Version_Number(), 0x00663B60);
DEFINE_IMPLEMENTATION(unsigned short VersionClass::Major_Version(), 0x00663D60);
DEFINE_IMPLEMENTATION(unsigned short VersionClass::Minor_Version(), 0x00663E20);
DEFINE_IMPLEMENTATION(const char *VersionClass::Version_Name(), 0x00663ED0);
DEFINE_IMPLEMENTATION(CommProtocolType VersionClass::Version_Protocol(unsigned long), 0x00664130);
DEFINE_IMPLEMENTATION(void VersionClass::Init_Clipping(), 0x00664160);
DEFINE_IMPLEMENTATION(unsigned long VersionClass::Clip_Version(unsigned long, unsigned long), 0x00664170);
DEFINE_IMPLEMENTATION(unsigned long VersionClass::Min_Version(), 0x006641B0);
DEFINE_IMPLEMENTATION(unsigned long VersionClass::Max_Version(), 0x006641C0);

DEFINE_IMPLEMENTATION(int RLEClass::Compress(void *, void *, int), 0x005C3490);
DEFINE_IMPLEMENTATION(int RLEClass::Uncompress(void *, void *), 0x005C3540);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(CDControlClass::CDControlClass(), 0x0044ED90);
DEFINE_IMPLEMENTATION(CDControlClass::~CDControlClass(), 0x0044EDB0);
DEFINE_IMPLEMENTATION(bool CDControlClass::Eject_CD_Drive(UINT), 0x0044EDC0);
DEFINE_IMPLEMENTATION(bool CDControlClass::Lock_CD_Drive(UINT), 0x0044EF80);
DEFINE_IMPLEMENTATION(bool CDControlClass::Unlock_CD_Drive(UINT), 0x0044F150);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(WWFontClass::WWFontClass(const void *, bool, int), 0x006A43D0);
WWFontClass::~WWFontClass() {}
DEFINE_IMPLEMENTATION(int WWFontClass::Char_Pixel_Width(char) const, 0x006A4480);
DEFINE_IMPLEMENTATION(int WWFontClass::String_Pixel_Width(const char *) const, 0x006A44C0);
DEFINE_IMPLEMENTATION(void WWFontClass::String_Pixel_Rect(const char *, Rect *) const, 0x006A4520);
DEFINE_IMPLEMENTATION(int WWFontClass::Get_Char_Width() const, 0x006A45F0);
DEFINE_IMPLEMENTATION(int WWFontClass::Get_Char_Height() const, 0x006A4620);
DEFINE_IMPLEMENTATION(Point2D WWFontClass::Print(const char *, Surface *, Rect *, Point2D *, ConvertClass *, unsigned char[]), 0x006A46F0);
DEFINE_IMPLEMENTATION(int WWFontClass::Set_X_Spacing(int), 0x006A4650);
DEFINE_IMPLEMENTATION(int WWFontClass::Set_Y_Spacing(int), 0x006A46A0);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(UnitTrackerClass::UnitTrackerClass(int), 0x0065D5B0);
DEFINE_IMPLEMENTATION(UnitTrackerClass::~UnitTrackerClass(), 0x0065D600);
DEFINE_IMPLEMENTATION(void UnitTrackerClass::Increment_Unit_Total(int), 0x0065D610);
DEFINE_IMPLEMENTATION(void UnitTrackerClass::Decrement_Unit_Total(int), 0x0065D630);
DEFINE_IMPLEMENTATION(void UnitTrackerClass::Clear_Unit_Total(), 0x0065D660);
DEFINE_IMPLEMENTATION(long *UnitTrackerClass::Get_All_Totals(), 0x0065D650);
DEFINE_IMPLEMENTATION(void UnitTrackerClass::To_Network_Format(), 0x0065D680);
DEFINE_IMPLEMENTATION(void UnitTrackerClass::To_PC_Format(), 0x0065D6C0);

DEFINE_IMPLEMENTATION(uint32_t BuildInfoClass::Original_Get_Build_Number(), 0x006860B0);
DEFINE_IMPLEMENTATION(const char *BuildInfoClass::Original_Get_Build_Number_String(char *, unsigned), 0x00686090);
DEFINE_IMPLEMENTATION(const char *BuildInfoClass::Original_Get_Builder_Name_String(char *, unsigned), 0x006860C0);
DEFINE_IMPLEMENTATION(const char *BuildInfoClass::Original_Get_Build_Date_String(char *, unsigned), 0x00686020);
DEFINE_IMPLEMENTATION(const char *BuildInfoClass::Original_Get_Builder_Initials(char *), 0x006860E0);
DEFINE_IMPLEMENTATION(const char *BuildInfoClass::Original_Get_Build_Version_String(char *, unsigned), 0x00686110);

LinkClass::LinkClass() : Next(nullptr), Prev(nullptr) { *((unsigned long *)this) = (unsigned long)0x006D0874; }
LinkClass::LinkClass(const NoInitClass &) {}
DEFINE_IMPLEMENTATION_CONSTRUCTOR(LinkClass::LinkClass(const LinkClass &), 0x00503050);
DEFINE_IMPLEMENTATION(LinkClass::~LinkClass(), 0x00503090);
DEFINE_IMPLEMENTATION(LinkClass & LinkClass::operator=(const LinkClass &), 0x005030F0);
DEFINE_IMPLEMENTATION(LinkClass * LinkClass::Get_Next() const, 0x00503110);
DEFINE_IMPLEMENTATION(LinkClass * LinkClass::Get_Prev() const, 0x00503120);
DEFINE_IMPLEMENTATION(LinkClass & LinkClass::Add(LinkClass &), 0x00503190);
DEFINE_IMPLEMENTATION(LinkClass & LinkClass::Add_Tail(LinkClass &), 0x005031D0);
DEFINE_IMPLEMENTATION(LinkClass & LinkClass::Add_Head(LinkClass &), 0x005031B0);
DEFINE_IMPLEMENTATION(LinkClass & LinkClass::Head_Of_List(), 0x00503130);
DEFINE_IMPLEMENTATION(LinkClass & LinkClass::Tail_Of_List(), 0x00503160);
DEFINE_IMPLEMENTATION(void LinkClass::Zap(), 0x005030E0);
DEFINE_IMPLEMENTATION(LinkClass * LinkClass::Remove(), 0x00503200);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(CounterClass::CounterClass(), 0x0046E9F0);
DEFINE_IMPLEMENTATION(CounterClass::~CounterClass(), 0x0046EA10);
DEFINE_IMPLEMENTATION(void CounterClass::Clear(), 0x0046EB60);
DEFINE_IMPLEMENTATION(int CounterClass::Increment(int), 0x0046EA40);
DEFINE_IMPLEMENTATION(int CounterClass::Decrement(int), 0x0046EAA0);
DEFINE_IMPLEMENTATION(bool CounterClass::Grow(int), 0x0046EC90);
DEFINE_IMPLEMENTATION(int CounterClass::Count_Of(int), 0x0046EB00);
DEFINE_IMPLEMENTATION(int CounterClass::Total(), 0x0046EB80);
DEFINE_IMPLEMENTATION(HRESULT CounterClass::Load(IStream *), 0x0046EC00);
DEFINE_IMPLEMENTATION(HRESULT CounterClass::Save(IStream *), 0x0046EBA0);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE HouseTypeClass::QueryInterface(REFIID, LPVOID *), 0x004CE430);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE HouseTypeClass::AddRef(), 0x004CE5D0);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE HouseTypeClass::Release(), 0x004CE5E0);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE HouseTypeClass::GetClassID(CLSID *), 0x004CE4D0);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE HouseTypeClass::IsDirty(), 0x004CE310);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE HouseTypeClass::Load(IStream *), 0x004CE320);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE HouseTypeClass::Save(IStream *, BOOL), 0x004CE3A0);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE HouseTypeClass::GetSizeMax(ULARGE_INTEGER *), 0x004CE400);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(HouseTypeClass::HouseTypeClass(const char *), 0x004CDD10);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(HouseTypeClass::HouseTypeClass(const NoInitClass &), 0x004CDE60);
DEFINE_IMPLEMENTATION(HouseTypeClass::~HouseTypeClass(), 0x004CDE80);
DEFINE_IMPLEMENTATION(RTTIType HouseTypeClass::Kind_Of() const, 0x004CE5A0);
DEFINE_IMPLEMENTATION(int HouseTypeClass::Size_Of(bool) const, 0x004CE5B0);
DEFINE_IMPLEMENTATION(void HouseTypeClass::Compute_CRC(WWCRCEngine &) const, 0x004CE210);
DEFINE_IMPLEMENTATION(int HouseTypeClass::Get_Heap_ID() const, 0x004CE5C0);
DEFINE_IMPLEMENTATION(bool HouseTypeClass::Read_INI(CCINIClass &), 0x004CDF50);

DEFINE_IMPLEMENTATION(void Detach_This_From_All(TARGET, bool), 0x006489B0);
DEFINE_IMPLEMENTATION(void Remove_All_Inactive(), 0x00648CD0);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE UnitTypeClass::GetClassID(CLSID *), 0x0065C430);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE UnitTypeClass::Load(IStream *), 0x0065C510);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE UnitTypeClass::Save(IStream *, BOOL), 0x0065C670);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(UnitTypeClass::UnitTypeClass(const char *), 0x0065B8F0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(UnitTypeClass::UnitTypeClass(const NoInitClass &), 0x0065BAA0);
DEFINE_IMPLEMENTATION(UnitTypeClass::~UnitTypeClass(), 0x0065BAC0);
DEFINE_IMPLEMENTATION(RTTIType UnitTypeClass::Kind_Of() const, 0x0065C760);
DEFINE_IMPLEMENTATION(int UnitTypeClass::Size_Of(bool) const, 0x0065C720);
DEFINE_IMPLEMENTATION(int UnitTypeClass::entry_34() const, 0x0065C750);
DEFINE_IMPLEMENTATION(void UnitTypeClass::Compute_CRC(WWCRCEngine &) const, 0x0065C470);
DEFINE_IMPLEMENTATION(int UnitTypeClass::Get_Heap_ID() const, 0x0065C770);
DEFINE_IMPLEMENTATION(bool UnitTypeClass::Read_INI(CCINIClass &), 0x0065BDD0);
DEFINE_IMPLEMENTATION(CoordStruct UnitTypeClass::Coord_Fixup(CoordStruct *) const, 0x0065C3B0);
DEFINE_IMPLEMENTATION(Point3D UnitTypeClass::Pixel_Dimensions() const, 0x0065BD30);
DEFINE_IMPLEMENTATION(Point3D UnitTypeClass::Lepton_Dimensions() const, 0x0065BD70);
DEFINE_IMPLEMENTATION(bool UnitTypeClass::Create_And_Place(CellStruct &, HouseClass *) const, 0x0065BC50);
DEFINE_IMPLEMENTATION(ObjectClass* const UnitTypeClass::Create_One_Of(HouseClass *) const, 0x0065BD00);
DEFINE_IMPLEMENTATION(int UnitTypeClass::Repair_Step() const, 0x0065C420);
DEFINE_IMPLEMENTATION(const TPoint3D<int> UnitTypeClass::Turret_Adjust(DirType, TPoint3D<int> &) const, 0x0065BDB0);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE InfantryTypeClass::GetClassID(CLSID *), 0x004DB000);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE InfantryTypeClass::Load(IStream *), 0x004DAE20);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE InfantryTypeClass::Save(IStream *, BOOL), 0x004DAF70);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(InfantryTypeClass::InfantryTypeClass(const char *), 0x004DA1E0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(InfantryTypeClass::InfantryTypeClass(const NoInitClass &), 0x004DA370);
DEFINE_IMPLEMENTATION(InfantryTypeClass::~InfantryTypeClass(), 0x004DA3A0);
DEFINE_IMPLEMENTATION(RTTIType InfantryTypeClass::Kind_Of() const, 0x004DB0D0);
DEFINE_IMPLEMENTATION(int InfantryTypeClass::Size_Of(bool) const, 0x004DB0E0);
DEFINE_IMPLEMENTATION(void InfantryTypeClass::Compute_CRC(WWCRCEngine &) const, 0x004DAD10);
DEFINE_IMPLEMENTATION(int InfantryTypeClass::Get_Heap_ID() const, 0x004DB110);
DEFINE_IMPLEMENTATION(bool InfantryTypeClass::Read_INI(CCINIClass &), 0x004DA960);
DEFINE_IMPLEMENTATION(CoordStruct InfantryTypeClass::Coord_Fixup(CoordStruct *) const, 0x004DACA0);
DEFINE_IMPLEMENTATION(Point3D InfantryTypeClass::Lepton_Dimensions() const, 0x004DAC50);
DEFINE_IMPLEMENTATION(bool InfantryTypeClass::Create_And_Place(CellStruct &, HouseClass *) const, 0x004DA490);
DEFINE_IMPLEMENTATION(ObjectClass *const InfantryTypeClass::Create_One_Of(HouseClass *) const, 0x004DA460);
DEFINE_IMPLEMENTATION(CellStruct *InfantryTypeClass::Occupy_List(bool) const, 0x004DA570);
DEFINE_IMPLEMENTATION(int InfantryTypeClass::Repair_Cost() const, 0x004DAC90);
DEFINE_IMPLEMENTATION(int InfantryTypeClass::Repair_Step() const, 0x004DAC80);
DEFINE_IMPLEMENTATION(void InfantryTypeClass::Sequence_Read_INI(), 0x004DA650);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE AircraftTypeClass::GetClassID(CLSID *), 0x0040FFE0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE AircraftTypeClass::Load(IStream *), 0x0040FF70);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE AircraftTypeClass::Save(IStream *, BOOL), 0x0040FFC0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(AircraftTypeClass::AircraftTypeClass(const char *), 0x0040FBC0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(AircraftTypeClass::AircraftTypeClass(const NoInitClass &), 0x0040FCA0);
DEFINE_IMPLEMENTATION(AircraftTypeClass::~AircraftTypeClass(), 0x0040FCC0);
DEFINE_IMPLEMENTATION(RTTIType AircraftTypeClass::Kind_Of() const, 0x004101C0);
DEFINE_IMPLEMENTATION(int AircraftTypeClass::Size_Of(bool) const, 0x004101D0);
DEFINE_IMPLEMENTATION(void AircraftTypeClass::Compute_CRC(WWCRCEngine &) const, 0x0040FF20);
DEFINE_IMPLEMENTATION(int AircraftTypeClass::Get_Heap_ID() const, 0x00410200);
DEFINE_IMPLEMENTATION(bool AircraftTypeClass::Read_INI(CCINIClass &), 0x0040FE80);
DEFINE_IMPLEMENTATION(Point3D AircraftTypeClass::Lepton_Dimensions() const, 0x0040FE50);
DEFINE_IMPLEMENTATION(bool AircraftTypeClass::Create_And_Place(CellStruct &, HouseClass *) const, 0x0040FE40);
DEFINE_IMPLEMENTATION(ObjectClass *const AircraftTypeClass::Create_One_Of(HouseClass *) const, 0x0040FDA0);
DEFINE_IMPLEMENTATION(CellStruct *AircraftTypeClass::Occupy_List(bool) const, 0x0040FDD0);

DEFINE_IMPLEMENTATION(int Modify_Damage(int, const WarheadTypeClass *, ArmorType, int), 0x0045EB60);
DEFINE_IMPLEMENTATION(void Chain_Reaction_Damage(CellStruct &), 0x0045EC30);
DEFINE_IMPLEMENTATION(void Explosion_Damage(const CoordStruct *, int, TechnoClass *, const WarheadTypeClass *, bool), 0x0045EEB0);
DEFINE_IMPLEMENTATION(const AnimTypeClass * Combat_Anim(int, const WarheadTypeClass *, LandType, const CoordStruct *), 0x00460340);
DEFINE_IMPLEMENTATION(void Do_Flash(int, WarheadTypeClass *, CoordStruct, bool), 0x00460460);
DEFINE_IMPLEMENTATION(void Wide_Area_Damage(const CoordStruct *, LEPTON, int, TechnoClass *, const WarheadTypeClass *), 0x004604D0);

DEFINE_IMPLEMENTATION(bool Save_Game(const char *, const char *, bool), 0x005D4FE0);
DEFINE_IMPLEMENTATION(bool Load_Game(const char *), 0x005D6910);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE VoxelAnimTypeClass::GetClassID(CLSID *), 0x0065FE30);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE VoxelAnimTypeClass::Load(IStream *), 0x0065FE70);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE VoxelAnimTypeClass::Save(IStream *, BOOL), 0x0065FF20);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(VoxelAnimTypeClass::VoxelAnimTypeClass(const char *), 0x0065F3B0);
VoxelAnimTypeClass::VoxelAnimTypeClass(const NoInitClass &) {}
DEFINE_IMPLEMENTATION(VoxelAnimTypeClass::~VoxelAnimTypeClass(), 0x0065F590);
DEFINE_IMPLEMENTATION(void VoxelAnimTypeClass::Detach(TARGET, bool), 0x0065FF40);
DEFINE_IMPLEMENTATION(RTTIType VoxelAnimTypeClass::Kind_Of() const, 0x00660040);
DEFINE_IMPLEMENTATION(int VoxelAnimTypeClass::Size_Of(bool) const, 0x00660050);
DEFINE_IMPLEMENTATION(void VoxelAnimTypeClass::Compute_CRC(WWCRCEngine &) const, 0x0065FCE0);
DEFINE_IMPLEMENTATION(bool VoxelAnimTypeClass::Read_INI(CCINIClass &), 0x0065F660);
DEFINE_IMPLEMENTATION(bool VoxelAnimTypeClass::Create_And_Place(CellStruct &, HouseClass *) const, 0x00660060);
DEFINE_IMPLEMENTATION(ObjectClass *const VoxelAnimTypeClass::Create_One_Of(HouseClass *) const, 0x00660070);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE WeaponTypeClass::GetClassID(CLSID *), 0x00681520);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE WeaponTypeClass::Load(IStream *), 0x00681560);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE WeaponTypeClass::Save(IStream *, BOOL), 0x00681730);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(WeaponTypeClass::WeaponTypeClass(const char *), 0x00680A60);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(WeaponTypeClass::WeaponTypeClass(const NoInitClass &), 0x00680C00);
DEFINE_IMPLEMENTATION(WeaponTypeClass::~WeaponTypeClass(), 0x00680C40);
DEFINE_IMPLEMENTATION(RTTIType WeaponTypeClass::Kind_Of() const, 0x006818D0);
DEFINE_IMPLEMENTATION(int WeaponTypeClass::Size_Of(bool) const, 0x006818B0);
DEFINE_IMPLEMENTATION(void WeaponTypeClass::Compute_CRC(WWCRCEngine &) const, 0x006813C0);
DEFINE_IMPLEMENTATION(bool WeaponTypeClass::Read_INI(CCINIClass &), 0x00680D30);
DEFINE_IMPLEMENTATION(void WeaponTypeClass::Set_Speed(), 0x006812C0);
DEFINE_IMPLEMENTATION(bool WeaponTypeClass::Is_Wall_Destroyer() const, 0x006813A0);
DEFINE_IMPLEMENTATION(ThreatType WeaponTypeClass::Allowed_Threats() const, 0x00681360);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE BulletTypeClass::GetClassID(CLSID *), 0x004485D0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE BulletTypeClass::Load(IStream *), 0x004484F0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE BulletTypeClass::Save(IStream *, BOOL), 0x004485B0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(BulletTypeClass::BulletTypeClass(const char *), 0x00447BC0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(BulletTypeClass::BulletTypeClass(const NoInitClass &), 0x00447D90);
DEFINE_IMPLEMENTATION(BulletTypeClass::~BulletTypeClass(), 0x00447DB0);
DEFINE_IMPLEMENTATION(void BulletTypeClass::Detach(TARGET, bool), 0x004486A0);
DEFINE_IMPLEMENTATION(RTTIType BulletTypeClass::Kind_Of() const, 0x004486C0);
DEFINE_IMPLEMENTATION(int BulletTypeClass::Size_Of(bool) const, 0x004486D0);
DEFINE_IMPLEMENTATION(void BulletTypeClass::Compute_CRC(WWCRCEngine &) const, 0x004483B0);
DEFINE_IMPLEMENTATION(bool BulletTypeClass::Read_INI(CCINIClass &), 0x00447E70);
DEFINE_IMPLEMENTATION(CoordStruct BulletTypeClass::Coord_Fixup(CoordStruct *) const, 0x00448340);
DEFINE_IMPLEMENTATION(bool BulletTypeClass::Create_And_Place(CellStruct &, HouseClass *) const, 0x004486F0);
DEFINE_IMPLEMENTATION(ObjectClass *const BulletTypeClass::Create_One_Of(HouseClass *) const, 0x00448700);

DEFINE_IMPLEMENTATION(HRESULT LocomotionClass::QueryInterface(REFIID, LPVOID *), 0x005064E0);
DEFINE_IMPLEMENTATION(ULONG LocomotionClass::AddRef(), 0x00506480);
DEFINE_IMPLEMENTATION(ULONG LocomotionClass::Release(), 0x005064A0);
DEFINE_IMPLEMENTATION(LONG LocomotionClass::IsDirty(), 0x00482280);
DEFINE_IMPLEMENTATION(HRESULT LocomotionClass::Save(IStream *, BOOL), 0x00506590);
DEFINE_IMPLEMENTATION(LONG LocomotionClass::GetSizeMax(ULARGE_INTEGER *), 0x00506660);
LocomotionClass::LocomotionClass() {}
LocomotionClass::LocomotionClass(const NoInitClass &) {}
LocomotionClass::~LocomotionClass() {}
DEFINE_IMPLEMENTATION(HRESULT LocomotionClass::Link_To_Object(void *), 0x00506250);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Is_Moving(), 0x00506800);
DEFINE_IMPLEMENTATION(CoordStruct LocomotionClass::Destination(), 0x00506790);
DEFINE_IMPLEMENTATION(CoordStruct LocomotionClass::Head_To_Coord(), 0x005067C0);
DEFINE_IMPLEMENTATION(MoveType LocomotionClass::Can_Enter_Cell(CellStruct), 0x00506710);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Is_To_Have_Shadow(), 0x00506700);
DEFINE_IMPLEMENTATION(Matrix3D LocomotionClass::Draw_Matrix(int *), 0x00506260);
DEFINE_IMPLEMENTATION(Matrix3D LocomotionClass::Shadow_Matrix(int *), 0x00506300);
DEFINE_IMPLEMENTATION(Point2D LocomotionClass::Draw_Point(), 0x005066F0);
DEFINE_IMPLEMENTATION(Point2D LocomotionClass::Shadow_Point(), 0x005063F0);
DEFINE_IMPLEMENTATION(VisualType LocomotionClass::Visual_Character(bool), 0x005066E0);
DEFINE_IMPLEMENTATION(int LocomotionClass::Z_Adjust(), 0x005066C0);
DEFINE_IMPLEMENTATION(ZGradientType LocomotionClass::Z_Gradient(), 0x5066D0);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Process(), 0x00506780);
DEFINE_IMPLEMENTATION(void LocomotionClass::Move_To(CoordStruct), 0x00506770);
DEFINE_IMPLEMENTATION(void LocomotionClass::Stop_Moving(), 0x00506760);
DEFINE_IMPLEMENTATION(void LocomotionClass::Do_Turn(DirStruct), 0x00506750);
DEFINE_IMPLEMENTATION(void LocomotionClass::Unlimbo(), 0x00506740);
DEFINE_IMPLEMENTATION(void LocomotionClass::Tilt_Pitch_AI(), 0x005066B0);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Power_On(), 0x00506420);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Power_Off(), 0x00506440);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Is_Powered(), 0x00506460);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Is_Ion_Sensitive(), 0x00506470);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Push(DirStruct), 0x00506690);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Shove(DirStruct), 0x005066A0);
DEFINE_IMPLEMENTATION(void LocomotionClass::Force_Track(int, CoordStruct), 0x00506730);
DEFINE_IMPLEMENTATION(void LocomotionClass::Force_Immediate_Destination(CoordStruct), 0x00506720);
DEFINE_IMPLEMENTATION(void LocomotionClass::Force_New_Slope(int), 0x00506810);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Is_Moving_Now(), 0x00483C60);
DEFINE_IMPLEMENTATION(int LocomotionClass::Apparent_Speed(), 0x00483C60);
DEFINE_IMPLEMENTATION(int LocomotionClass::Drawing_Code(), 0x00506820);
DEFINE_IMPLEMENTATION(FireErrorType LocomotionClass::Can_Fire(), 0x00506830);
DEFINE_IMPLEMENTATION(int LocomotionClass::Get_Status(), 0x004822B0);
DEFINE_IMPLEMENTATION(void LocomotionClass::Acquire_Hunter_Seeker_Target(), 0x004822C0);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Is_Surfacing(), 0x004822D0);
DEFINE_IMPLEMENTATION(void LocomotionClass::Mark_All_Occupation_Bits(int), 0x00483C70);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Is_Moving_Here(CoordStruct), 0x00483C80);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Will_Jump_Tracks(), 0x00483C90);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Is_Really_Moving_Now(), 0x004822A0);
DEFINE_IMPLEMENTATION(void LocomotionClass::Stop_Movement_Animation(), 0x004822E0);
DEFINE_IMPLEMENTATION(void LocomotionClass::Lock(), 0x00483CA0);
DEFINE_IMPLEMENTATION(void LocomotionClass::Unlock(), 0x00483CB0);
DEFINE_IMPLEMENTATION(int LocomotionClass::Get_Track_Number(), 0x00483CC0);
DEFINE_IMPLEMENTATION(int LocomotionClass::Get_Track_Index(), 0x00483CD0);
DEFINE_IMPLEMENTATION(int LocomotionClass::Get_Speed_Accum(), 0x00483CE0);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(WinsockInterfaceClass::WinsockInterfaceClass(), 0x006A0EB0);
DEFINE_IMPLEMENTATION(WinsockInterfaceClass::~WinsockInterfaceClass(), 0x006A0F60);
DEFINE_IMPLEMENTATION(void WinsockInterfaceClass::Close(), 0x006A0FE0);
DEFINE_IMPLEMENTATION(void WinsockInterfaceClass::Close_Socket(), 0x006A1010);
DEFINE_IMPLEMENTATION(bool WinsockInterfaceClass::Start_Listening(), 0x006A1030);
DEFINE_IMPLEMENTATION(void WinsockInterfaceClass::Stop_Listening(), 0x006A1080);
DEFINE_IMPLEMENTATION(void WinsockInterfaceClass::Discard_In_Buffers(), 0x006A10A0);
DEFINE_IMPLEMENTATION(void WinsockInterfaceClass::Discard_Out_Buffers(), 0x006A1110);
DEFINE_IMPLEMENTATION(bool WinsockInterfaceClass::Init(), 0x006A1180);
DEFINE_IMPLEMENTATION(void WinsockInterfaceClass::Build_Packet_CRC(WinsockInterfaceClass::WinsockBufferType *), 0x006A1280);
DEFINE_IMPLEMENTATION(bool WinsockInterfaceClass::Passes_CRC_Check(WinsockInterfaceClass::WinsockBufferType *) const, 0x006A1300);
DEFINE_IMPLEMENTATION(WinsockInterfaceClass::WinsockBufferType *WinsockInterfaceClass::Get_New_Out_Buffer(), 0x006A1390);
DEFINE_IMPLEMENTATION(WinsockInterfaceClass::WinsockBufferType *WinsockInterfaceClass::Get_New_In_Buffer(), 0x006A1430);
DEFINE_IMPLEMENTATION(int WinsockInterfaceClass::Read(void *, int &, void *, int &), 0x006A14D0);
DEFINE_IMPLEMENTATION(void WinsockInterfaceClass::WriteTo(void *, int, void *), 0x006A1580);
DEFINE_IMPLEMENTATION(void WinsockInterfaceClass::Broadcast(void *, int), 0x006A1640);
DEFINE_IMPLEMENTATION(void WinsockInterfaceClass::Clear_Socket_Error(SOCKET), 0x006A16F0);
DEFINE_IMPLEMENTATION(bool WinsockInterfaceClass::Set_Socket_Options(), 0x006A1740);
DEFINE_IMPLEMENTATION(bool WinsockInterfaceClass::Get_Host_Name(char *, int) const, 0x006A17D0);

DEFINE_IMPLEMENTATION(HRESULT DropPodLocomotionClass::QueryInterface(REFIID, LPVOID *), 0x00483AD0);
DEFINE_IMPLEMENTATION(ULONG DropPodLocomotionClass::AddRef(), 0x00483CF0);
DEFINE_IMPLEMENTATION(ULONG DropPodLocomotionClass::Release(), 0x00483D00);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE DropPodLocomotionClass::GetClassID(CLSID *), 0x00483860);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE DropPodLocomotionClass::Load(IStream *), 0x004838A0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE DropPodLocomotionClass::Save(IStream *, BOOL), 0x00483920);
DEFINE_IMPLEMENTATION(bool DropPodLocomotionClass::Is_Moving(), 0x00483170);
DEFINE_IMPLEMENTATION(CoordStruct DropPodLocomotionClass::Destination(), 0x00483180);
DEFINE_IMPLEMENTATION(bool DropPodLocomotionClass::Process(), 0x004831B0);
DEFINE_IMPLEMENTATION(void DropPodLocomotionClass::Move_To(CoordStruct), 0x00483620);
DEFINE_IMPLEMENTATION(void DropPodLocomotionClass::Stop_Moving(), 0x00483A00);
DEFINE_IMPLEMENTATION(LayerType DropPodLocomotionClass::In_Which_Layer(), 0x00483B30);
DEFINE_IMPLEMENTATION(int DropPodLocomotionClass::Drawing_Code(), 0x00483C50);
DEFINE_IMPLEMENTATION(HRESULT DropPodLocomotionClass::Begin_Piggyback(ILocomotion *), 0x00483A10);
DEFINE_IMPLEMENTATION(HRESULT DropPodLocomotionClass::End_Piggyback(ILocomotion **), 0x00483A60);
DEFINE_IMPLEMENTATION(bool DropPodLocomotionClass::Is_Ok_To_End(), 0x00483AA0);
DEFINE_IMPLEMENTATION(HRESULT DropPodLocomotionClass::Piggyback_CLSID(CLSID *), 0x00483B40);
DEFINE_IMPLEMENTATION(bool DropPodLocomotionClass::Is_Piggybacking(), 0x00483D10);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(DropPodLocomotionClass::DropPodLocomotionClass(), 0x004830F0);
DropPodLocomotionClass::DropPodLocomotionClass(const NoInitClass &) { *((unsigned long *)this) = (unsigned long)0x006CFBBC; *((unsigned long *)this+4) = (unsigned long)0x006CFAF4; *((unsigned long *)this+8) = (unsigned long)0x006CFAD4; }
DEFINE_IMPLEMENTATION(DropPodLocomotionClass::~DropPodLocomotionClass(), 0x00483140);
DEFINE_IMPLEMENTATION(int DropPodLocomotionClass::Size_Of(bool) const, 0x00483D30);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(Quaternion::Quaternion(float, float, float, float), 0x005AFE70);
DEFINE_IMPLEMENTATION(void Quaternion::Set(float, float, float, float), 0x005AFE90);
DEFINE_IMPLEMENTATION(void Quaternion::Normalize(), 0x005AFEB0);
DEFINE_IMPLEMENTATION(void Quaternion::Scale(float), 0x005AFF10);
DEFINE_IMPLEMENTATION(float & Quaternion::operator[](int), 0x005AFF40);
DEFINE_IMPLEMENTATION(const float & Quaternion::operator[](int) const, 0x005AFF50);
DEFINE_IMPLEMENTATION(Quaternion Quaternion::operator=(const Quaternion &), 0x005AFF60);
DEFINE_IMPLEMENTATION(Quaternion & Quaternion::func_5AFFA0(Quaternion &), 0x005AFFA0);
DEFINE_IMPLEMENTATION(Quaternion Quaternion_5B0110(Quaternion &, Quaternion &), 0x005B0110);
DEFINE_IMPLEMENTATION(Quaternion Quaternion_5B0280(Quaternion &, Quaternion &), 0x005B0280);
DEFINE_IMPLEMENTATION(Quaternion Inverse(const Quaternion &), 0x005B0300);
DEFINE_IMPLEMENTATION(Quaternion Conjugate(const Quaternion &), 0x005B0350);
DEFINE_IMPLEMENTATION(Quaternion Trackball(float, float, float, float, float), 0x005B03A0);
DEFINE_IMPLEMENTATION(Quaternion Axis_To_Quat(const Vector3 &, float), 0x005B06C0);
DEFINE_IMPLEMENTATION(Quaternion Slerp(Quaternion &, Quaternion &, float), 0x005B07D0);
DEFINE_IMPLEMENTATION(Quaternion Build_Quaternion(const Matrix3D &), 0x005B0970);
DEFINE_IMPLEMENTATION(Matrix3D Build_Matrix3D(const Quaternion &), 0x005B0BC0);

DEFINE_IMPLEMENTATION(Matrix3D::Matrix3D(const Matrix3D &), 0x005546F0);
DEFINE_IMPLEMENTATION(Matrix3D::Matrix3D(float, float, float, float, float, float, float, float, float, float, float, float), 0x00554740);
DEFINE_IMPLEMENTATION(void Matrix3D::Set(const Vector3 &, const Vector3 &, const Vector3 &, const Vector3 &), 0x005547A0);
DEFINE_IMPLEMENTATION(void Matrix3D::Set(float, float), 0x00554800);
DEFINE_IMPLEMENTATION(void Matrix3D::Set(const Vector3 &, float), 0x00554860);
DEFINE_IMPLEMENTATION(void Matrix3D::Make_Identity(), 0x00554970);
DEFINE_IMPLEMENTATION(void Matrix3D::Translate(float, float, float), 0x005549A0);
DEFINE_IMPLEMENTATION(void Matrix3D::Translate(const Vector3 &), 0x00554A00);
DEFINE_IMPLEMENTATION(void Matrix3D::Translate_X(float), 0x00554A90);
DEFINE_IMPLEMENTATION(void Matrix3D::Translate_Y(float), 0x00554AC0);
DEFINE_IMPLEMENTATION(void Matrix3D::Translate_Z(float), 0x00554AF0);
DEFINE_IMPLEMENTATION(void Matrix3D::Scale(float), 0x00554B20);
DEFINE_IMPLEMENTATION(void Matrix3D::Scale(float,float,float), 0x00554B80);
DEFINE_IMPLEMENTATION(void Matrix3D::Scale_X(float), 0x00554BE0);
DEFINE_IMPLEMENTATION(void Matrix3D::Scale_Y(float), 0x00554C00);
DEFINE_IMPLEMENTATION(void Matrix3D::Scale_Z(float), 0x00554C30);
DEFINE_IMPLEMENTATION(void Matrix3D::Shear_YZ(float, float), 0x00554C60);
DEFINE_IMPLEMENTATION(void Matrix3D::Shear_XY(float, float), 0x00554CB0);
DEFINE_IMPLEMENTATION(void Matrix3D::Shear_XZ(float, float), 0x00554D00);
DEFINE_IMPLEMENTATION(void Matrix3D::Rotate_X(float), 0x00555070);
DEFINE_IMPLEMENTATION(void Matrix3D::Rotate_X(float, float), 0x00555110);
DEFINE_IMPLEMENTATION(void Matrix3D::Rotate_Y(float), 0x00555190);
DEFINE_IMPLEMENTATION(void Matrix3D::Rotate_Y(float, float), 0x00555230);
DEFINE_IMPLEMENTATION(void Matrix3D::Rotate_Z(float), 0x005552B0);
DEFINE_IMPLEMENTATION(void Matrix3D::Rotate_Z(float, float), 0x00555350);
DEFINE_IMPLEMENTATION(float Matrix3D::Get_X(), 0x005553D0);
DEFINE_IMPLEMENTATION(float Matrix3D::Get_Y(), 0x00555420);
DEFINE_IMPLEMENTATION(float Matrix3D::Get_Z(), 0x00555470);
DEFINE_IMPLEMENTATION(float Matrix3D::Get_X_Rotation() const, 0x005554C0);
DEFINE_IMPLEMENTATION(float Matrix3D::Get_Y_Rotation() const, 0x00555520);
DEFINE_IMPLEMENTATION(float Matrix3D::Get_Z_Rotation() const, 0x00555580);
DEFINE_IMPLEMENTATION(Vector3 Matrix3D::Rotate_Vector(const Vector3 &) const, 0x005555E0);
DEFINE_IMPLEMENTATION(void Matrix3D::Look_At_1(Vector3 &, Vector3 &, float), 0x00555660);
DEFINE_IMPLEMENTATION(void Matrix3D::Look_At_2(Vector3 &, Vector3 &, float), 0x00555820);
DEFINE_IMPLEMENTATION(Matrix3D operator*(const Matrix3D &, const Matrix3D &), 0x00555A90);
DEFINE_IMPLEMENTATION(Matrix3D func_555D30(Matrix3D &), 0x00555D30);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE CellClass::GetClassID(CLSID *), 0x0045AE50);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE CellClass::Load(IStream *), 0x004597E0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE CellClass::Save(IStream *, BOOL), 0x00459990);
DEFINE_IMPLEMENTATION(int STDMETHODCALLTYPE CellClass::What_Am_I(), 0x0045D770);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(CellClass::CellClass(), 0x004517C0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(CellClass::CellClass(const NoInitClass &x), 0x00450F60);
DEFINE_IMPLEMENTATION(CellClass::~CellClass(), 0x00451750);
DEFINE_IMPLEMENTATION(RTTIType CellClass::Kind_Of() const, 0x0045D780);
DEFINE_IMPLEMENTATION(int CellClass::Size_Of(bool) const, 0x0045D790);
DEFINE_IMPLEMENTATION(CoordStruct CellClass::Center_Coord() const, 0x0045C4E0);
DEFINE_IMPLEMENTATION(CoordStruct CellClass::entry_5C() const, 0x0045C530);
DEFINE_IMPLEMENTATION(int CellClass::Get_Height(const CoordStruct &) const, 0x00450F90);
DEFINE_IMPLEMENTATION(ObjectClass *CellClass::Cell_Find_Object(RTTIType, bool) const, 0x00452110);
DEFINE_IMPLEMENTATION(ObjectClass *const CellClass::Cell_Object(const Point2D &, bool) const, 0x004521D0);
DEFINE_IMPLEMENTATION(TechnoClass *const CellClass::Cell_Techno(const Point2D &, bool, TechnoClass *) const, 0x00452020);
DEFINE_IMPLEMENTATION(UnitClass *const CellClass::Cell_Unit(bool) const, 0x00454AC0);
DEFINE_IMPLEMENTATION(AircraftClass *const CellClass::Cell_Aircraft(bool) const, 0x00454B00);
DEFINE_IMPLEMENTATION(InfantryClass *const CellClass::Cell_Infantry(bool) const, 0x00454B40);
DEFINE_IMPLEMENTATION(BuildingClass *const CellClass::Cell_Building(bool) const, 0x00452160);
DEFINE_IMPLEMENTATION(TerrainClass *const CellClass::Cell_Terrain(bool) const, 0x00452190);
DEFINE_IMPLEMENTATION(bool CellClass::Is_Clear_To_Build(SpeedType, const BuildingTypeClass *, const HouseClass *), 0x00452250);
DEFINE_IMPLEMENTATION(void CellClass::Recalc_Attributes(int), 0x00453240);
DEFINE_IMPLEMENTATION(void CellClass::Occupy_Down(ObjectClass *, bool), 0x00454810);
DEFINE_IMPLEMENTATION(void CellClass::Occupy_Up(ObjectClass *, bool), 0x004549D0);
DEFINE_IMPLEMENTATION(void CellClass::Wall_Update(bool), 0x004567A0);
DEFINE_IMPLEMENTATION(CoordStruct CellClass::Cell_Coord() const, 0x00456BA0);
DEFINE_IMPLEMENTATION(int CellClass::Reduce_Tiberium(int), 0x00456BF0);
DEFINE_IMPLEMENTATION(int CellClass::Reduce_Wall(int), 0x00456E90);
DEFINE_IMPLEMENTATION(int CellClass::Spot_Index(CoordStruct &), 0x00457280);
DEFINE_IMPLEMENTATION(bool CellClass::Is_Spot_Free(int, bool) const, 0x00457310);
DEFINE_IMPLEMENTATION(CoordStruct CellClass::Closest_Free_Spot(CoordStruct &, bool, bool) const, 0x00457360);
DEFINE_IMPLEMENTATION(void CellClass::Incoming(CoordStruct &, bool, bool, bool), 0x004577D0);
DEFINE_IMPLEMENTATION(CellClass &CellClass::Adjacent_Cell(FacingType) const, 0x00457970);
DEFINE_IMPLEMENTATION(void CellClass::Adjust_Threat(HousesType, int), 0x004579D0);
DEFINE_IMPLEMENTATION(long CellClass::Tiberium_Adjust(bool), 0x00457A50);
DEFINE_IMPLEMENTATION(bool CellClass::Goodie_Check(FootClass *), 0x00457C00);
DEFINE_IMPLEMENTATION(bool CellClass::Flag_Place(HousesType), 0x00459040);
DEFINE_IMPLEMENTATION(bool CellClass::Flag_Remove(), 0x00459090);
DEFINE_IMPLEMENTATION(void CellClass::Shimmer(), 0x004590C0);
DEFINE_IMPLEMENTATION(bool CellClass::Is_Clear_To_Move(SpeedType, bool, bool, int, MZoneType, int, bool), 0x004590E0);
DEFINE_IMPLEMENTATION(bool CellClass::Is_Bridge_Here() const, 0x00459240);
DEFINE_IMPLEMENTATION(bool CellClass::Can_Tiberium_Grow() const, 0x00459250);
DEFINE_IMPLEMENTATION(bool CellClass::Can_Tiberium_Spread() const, 0x00459300);
DEFINE_IMPLEMENTATION(bool CellClass::Grow_Tiberium(), 0x004593C0);
DEFINE_IMPLEMENTATION(bool CellClass::Spread_Tiberium(bool), 0x004594D0);
DEFINE_IMPLEMENTATION(bool CellClass::Can_Tiberium_Germinate(TiberiumClass *) const, 0x004596C0);
DEFINE_IMPLEMENTATION(void CellClass::Detach(TARGET), 0x0045AD80);
DEFINE_IMPLEMENTATION(void CellClass::Attach_Tag(TagClass *), 0x0045AEA0);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE WarheadTypeClass::GetClassID(CLSID *), 0x0066F6B0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE WarheadTypeClass::Load(IStream *), 0x0066F6F0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE WarheadTypeClass::Save(IStream *, BOOL), 0x0066F8A0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(WarheadTypeClass::WarheadTypeClass(const char *), 0x0066ED40);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(WarheadTypeClass::WarheadTypeClass(const NoInitClass &), 0x0066EF00);
DEFINE_IMPLEMENTATION(WarheadTypeClass::~WarheadTypeClass(), 0x0066EF60);
DEFINE_IMPLEMENTATION(void WarheadTypeClass::Detach(TARGET, bool), 0x0066F9A0);
DEFINE_IMPLEMENTATION(RTTIType WarheadTypeClass::Kind_Of() const, 0x0066FA70);
DEFINE_IMPLEMENTATION(int WarheadTypeClass::Size_Of(bool) const, 0x0066FA50);
DEFINE_IMPLEMENTATION(void WarheadTypeClass::Compute_CRC(WWCRCEngine &) const, 0x0066F580);
DEFINE_IMPLEMENTATION(bool WarheadTypeClass::Read_INI(CCINIClass &), 0x0066F060);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE Tactical::GetClassID(CLSID *), 0x00617EE0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE Tactical::Load(IStream *), 0x00617F20);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE Tactical::Save(IStream *, BOOL), 0x00617F80);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(Tactical::Tactical(), 0x0060EEC0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(Tactical::Tactical(const NoInitClass &), 0x0060F090);
DEFINE_IMPLEMENTATION(Tactical::~Tactical(), 0x0060F0D0);
DEFINE_IMPLEMENTATION(void Tactical::Detach(TARGET, bool), 0x00616920);
DEFINE_IMPLEMENTATION(RTTIType Tactical::Kind_Of() const, 0x00617FF0);
DEFINE_IMPLEMENTATION(int Tactical::Size_Of(bool) const, 0x00618000);
DEFINE_IMPLEMENTATION(void Tactical::AI(), 0x0060F960);
DEFINE_IMPLEMENTATION(bool Tactical::entry_64(Rect &, Rect &, unsigned, bool), 0x00617CD0);
DEFINE_IMPLEMENTATION(Point2D Tactical::func_60F150(const CoordStruct &) const, 0x0060F150);
DEFINE_IMPLEMENTATION(Point2D Tactical::func_60F270(const CellStruct &) const, 0x0060F270);
DEFINE_IMPLEMENTATION(Point2D Tactical::func_60F350(const CoordStruct &) const, 0x0060F350);
DEFINE_IMPLEMENTATION(int Tactical::func_60F3C0() const, 0x0060F3C0);
DEFINE_IMPLEMENTATION(bool Tactical::Coord_To_Pixel(const CoordStruct &, Point2D &) const, 0x0060F4B0);
DEFINE_IMPLEMENTATION(CoordStruct Tactical::Pixel_To_Coord(const Point2D &) const, 0x0060F660);
DEFINE_IMPLEMENTATION(CoordStruct Tactical::func_60F740(const Point2D &) const, 0x0060F740);
DEFINE_IMPLEMENTATION(void Tactical::func_60F800(const CoordStruct &, int), 0x0060F800);
DEFINE_IMPLEMENTATION(void Tactical::Set_Caption_Text(int), 0x00611C00);
DEFINE_IMPLEMENTATION(void Tactical::Clear_Caption_Text(), 0x00611C50);
DEFINE_IMPLEMENTATION(void Tactical::Draw_Screen_Text(const char *), 0x00611C60);
DEFINE_IMPLEMENTATION(int Tactical::Cell_Shadow(CellStruct &, bool), 0x00614F90);
DEFINE_IMPLEMENTATION(Point2D Tactical::func_60F0F0(int, int), 0x0060F0F0);
DEFINE_IMPLEMENTATION(int Tactical::func_60F450(int), 0x0060F450);
DEFINE_IMPLEMENTATION(void Tactical::func_60FBB0(Rect &, bool), 0x0060FBB0);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(FuseClass::FuseClass(), 0x004E1100);
FuseClass::FuseClass(const NoInitClass &) {}
FuseClass::~FuseClass() {}
DEFINE_IMPLEMENTATION(void FuseClass::Arm_Fuse(CoordStruct &, CoordStruct &, int, int), 0x004E1130);
DEFINE_IMPLEMENTATION(FuseResultType FuseClass::Fuse_Checkup(CoordStruct &), 0x004E11F0);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE OverlayTypeClass::GetClassID(CLSID *), 0x0058D900);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE OverlayTypeClass::Load(IStream *), 0x0058D7F0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE OverlayTypeClass::Save(IStream *, BOOL), 0x0058D8E0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(OverlayTypeClass::OverlayTypeClass(const char *), 0x0058CFF0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(OverlayTypeClass::OverlayTypeClass(const NoInitClass &), 0x0058D140);
DEFINE_IMPLEMENTATION(OverlayTypeClass::~OverlayTypeClass(), 0x0058D160);
DEFINE_IMPLEMENTATION(RTTIType OverlayTypeClass::Kind_Of() const, 0x0058DC20);
DEFINE_IMPLEMENTATION(int OverlayTypeClass::Size_Of(bool) const, 0x0058DC30);
DEFINE_IMPLEMENTATION(void OverlayTypeClass::Compute_CRC(WWCRCEngine &) const, 0x0058D750);
DEFINE_IMPLEMENTATION(int OverlayTypeClass::Get_Heap_ID() const, 0x0058DC40);
DEFINE_IMPLEMENTATION(bool OverlayTypeClass::Read_INI(CCINIClass &), 0x0058D490);
DEFINE_IMPLEMENTATION(CoordStruct OverlayTypeClass::Coord_Fixup(CoordStruct *) const, 0x0058D730);
DEFINE_IMPLEMENTATION(bool OverlayTypeClass::Create_And_Place(CellStruct &, HouseClass *) const, 0x0058D2B0);
DEFINE_IMPLEMENTATION(ObjectClass *const OverlayTypeClass::Create_One_Of(HouseClass *) const, 0x0058D2E0);
DEFINE_IMPLEMENTATION(ShapeFileStruct *const OverlayTypeClass::Get_Image_Data() const, 0x0058DB20);
DEFINE_IMPLEMENTATION(void OverlayTypeClass::Draw_It(Point2D &, Rect &, int) const, 0x0058D310);
DEFINE_IMPLEMENTATION(void OverlayTypeClass::Init(TheaterType), 0x0058D3A0);
DEFINE_IMPLEMENTATION(RGBStruct OverlayTypeClass::Get_Radar_Color(int), 0x0058D9D0);

DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE BaseClass::Load(IStream *), 0x0041FB90);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE BaseClass::Save(IStream *, BOOL), 0x0041FDB0);
DEFINE_IMPLEMENTATION(void BaseClass::Compute_CRC(WWCRCEngine &) const, 0x0041FEB0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(BaseClass::BaseClass(), 0x0041F4C0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(BaseClass::BaseClass(const NoInitClass &), 0x0041FF10);
BaseClass::~BaseClass() {}
DEFINE_IMPLEMENTATION(bool BaseClass::Is_Built(int) const, 0x0041F550);
DEFINE_IMPLEMENTATION(BuildingClass * BaseClass::Get_Building(int) const, 0x0041F5D0);
DEFINE_IMPLEMENTATION(bool BaseClass::Is_Node(const BuildingClass *), 0x0041F750);
DEFINE_IMPLEMENTATION(BaseNodeClass * BaseClass::Get_Node(const BuildingClass *), 0x0041F7E0);
DEFINE_IMPLEMENTATION(BaseNodeClass * BaseClass::Get_Node(CellStruct &), 0x0041F860);
DEFINE_IMPLEMENTATION(BaseNodeClass * BaseClass::Next_Buildable(BuildingType), 0x0041F8B0);
DEFINE_IMPLEMENTATION(int BaseClass::Next_Buildable_Index(BuildingType), 0x0041F8B0);
DEFINE_IMPLEMENTATION(void BaseClass::Read_INI(CCINIClass &, const char *), 0x0041F970);
DEFINE_IMPLEMENTATION(void BaseClass::Write_INI(const CCINIClass &, const char *), 0x0041FAC0);

EventClass::EventClass() : ID(-1), Type(EMPTY) {}
DEFINE_IMPLEMENTATION_CONSTRUCTOR(EventClass::EventClass(unsigned int, SpecialClass), 0x00493CC0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(EventClass::EventClass(unsigned int, EventType, TargetClass), 0x00493D00);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(EventClass::EventClass(unsigned int, EventType), 0x00493DE0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(EventClass::EventClass(unsigned int, EventType, CellStruct *), 0x00493D70);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(EventClass::EventClass(unsigned int, EventType, TargetClass, TargetClass), 0x00493EB0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(EventClass::EventClass(unsigned int, TargetClass, MissionType, TargetClass, TargetClass), 0x00493FA0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(EventClass::EventClass(unsigned int, TargetClass, MissionType, TargetClass, TargetClass, SpeedType, MPHType), 0x00494010);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(EventClass::EventClass(unsigned int, EventType, RTTIType, int), 0x004940A0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(EventClass::EventClass(unsigned int, EventType, RTTIType, CellStruct *), 0x00494110);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(EventClass::EventClass(unsigned int, EventType, int, CellStruct *), 0x00494190);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(EventClass::EventClass(unsigned int, AnimType, HousesType, CoordStruct *), 0x00493F30);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(EventClass::EventClass(unsigned int, void *, unsigned long), 0x00494210);
DEFINE_IMPLEMENTATION(void EventClass::Execute(), 0x00494280);

WWMessageBox::WWMessageBox(int caption) { Caption = caption; }
DEFINE_IMPLEMENTATION(int WWMessageBox::Process(const char *, const char *, const char *, const char *, bool), 0x005727F0);
DEFINE_IMPLEMENTATION(int WWMessageBox::Process(int, int, int, int, bool), 0x00572B20);
DEFINE_IMPLEMENTATION(int WWMessageBox::Process(char const *, int, int, int, bool), 0x00572B70);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(SpotlightClass::SpotlightClass(CoordStruct, int), 0x0058DFD0);
DEFINE_IMPLEMENTATION(SpotlightClass::~SpotlightClass(), 0x0058E050);
DEFINE_IMPLEMENTATION(void SpotlightClass::Remove_If_Large(), 0x0058E0A0);
DEFINE_IMPLEMENTATION(void SpotlightClass::AI(), 0x0058E110);
DEFINE_IMPLEMENTATION(void SpotlightClass::One_Time(), 0x0058E1A0);
DEFINE_IMPLEMENTATION(void SpotlightClass::Clear_All(), 0x0058E580);
DEFINE_IMPLEMENTATION(void SpotlightClass::Draw_It(), 0x0058E5D0);
DEFINE_IMPLEMENTATION(void SpotlightClass::Draw_All(), 0x0058EA20);

DEFINE_IMPLEMENTATION(HRESULT GScreenClass::QueryInterface(REFIID, LPVOID *), 0x004B9390);
DEFINE_IMPLEMENTATION(ULONG GScreenClass::AddRef(), 0x00402AD0);
DEFINE_IMPLEMENTATION(ULONG GScreenClass::Release(), 0x00402AE0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(GScreenClass::GScreenClass(), 0x004B9370);
GScreenClass::GScreenClass(const NoInitClass &) { *((unsigned long *)this) = (unsigned long)0x006D1A5C; }
GScreenClass::~GScreenClass() {}
DEFINE_IMPLEMENTATION(void GScreenClass::One_Time(), 0x004B93F0);
DEFINE_IMPLEMENTATION(void GScreenClass::Init_Theater(TheaterType), 0x004B9400);
DEFINE_IMPLEMENTATION(void GScreenClass::Init_Clear(), 0x004B9420);
DEFINE_IMPLEMENTATION(void GScreenClass::Init_IO(), 0x004B9430);
DEFINE_IMPLEMENTATION(void GScreenClass::Input(KeyNumType &, int &, int &), 0x004B9470);
DEFINE_IMPLEMENTATION(void GScreenClass::AI(KeyNumType &, Point2D &), 0x004B9A70);
DEFINE_IMPLEMENTATION(void GScreenClass::Add_A_Button(GadgetClass &), 0x004B9540);
DEFINE_IMPLEMENTATION(void GScreenClass::Remove_A_Button(GadgetClass &), 0x004B9580);
DEFINE_IMPLEMENTATION(void GScreenClass::Flag_To_Redraw(bool), 0x004B9440);
DEFINE_IMPLEMENTATION(void GScreenClass::Render(), 0x004B95A0);
DEFINE_IMPLEMENTATION(void GScreenClass::Draw_It(bool), 0x0047C180);
DEFINE_IMPLEMENTATION(void GScreenClass::Blit_Display(), 0x004B96B0);
DEFINE_IMPLEMENTATION(void GScreenClass::Blit(bool, Surface *, int), 0x004B96C0);

CrateClass::CrateClass() : Timer(), Cell(-1, -1) {}
CrateClass::~CrateClass() {}
void CrateClass::Init() { Make_Invalid(); }
DEFINE_IMPLEMENTATION(bool CrateClass::Create_Crate(CellStruct &), 0x00470820);
bool CrateClass::Is_Here(CellStruct &cell) const { return Is_Valid() && cell == Cell; }
DEFINE_IMPLEMENTATION(bool CrateClass::Remove_It(), 0x004707B0);
bool CrateClass::Is_Expired() const { return Is_Valid() && Timer.Expired(); }
bool CrateClass::Is_Valid() const { return Cell.X > 0 && Cell.Y > 0; }
DEFINE_IMPLEMENTATION(bool CrateClass::Put_Crate(CellStruct &), 0x00470950);
DEFINE_IMPLEMENTATION(bool CrateClass::Get_Crate(CellStruct &), 0x00470B60);
void CrateClass::Make_Invalid() { Cell = CellStruct(-1, -1); Timer.Stop(); }

DEFINE_IMPLEMENTATION_CONSTRUCTOR(ColorScheme::ColorScheme(), 0x005E2430);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(ColorScheme::ColorScheme(const char *, HSVClass *, PaletteClass *, PaletteClass *, int), 0x005E24F0);
DEFINE_IMPLEMENTATION(ColorScheme::~ColorScheme(), 0x005E26C0);
DEFINE_IMPLEMENTATION(void ColorScheme::func_5E2650(PaletteClass *, PaletteClass *, int, int, int), 0x005E2650);
DEFINE_IMPLEMENTATION(ConvertClass * ColorScheme::func_68C3B0(HSVClass *, PaletteClass *, PaletteClass *, PaletteClass *, Surface *, int, int, int, int, bool *), 0x005E2190);
DEFINE_IMPLEMENTATION(ConvertClass * ColorScheme::func_68C500(HSVClass *, PaletteClass *, PaletteClass *, Surface *, PaletteClass *), 0x005E22E0);
DEFINE_IMPLEMENTATION(ColorScheme *ColorScheme::Find_Or_Make(const char *, PaletteClass *, PaletteClass *, int), 0x005E27B0);
DEFINE_IMPLEMENTATION(ColorScheme *ColorScheme::As_Pointer(const char *, int), 0x005E2840);
DEFINE_IMPLEMENTATION(ColorSchemeType ColorScheme::From_Name(const char *, int), 0x005E28A0);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(StorageClass::StorageClass(), 0x0060AD60);
StorageClass::StorageClass(const NoInitClass &noinit) {}
StorageClass::~StorageClass() {}
DEFINE_IMPLEMENTATION(int StorageClass::Get_Total_Value() const, 0x0060AD80);
DEFINE_IMPLEMENTATION(int StorageClass::Get_Total_Amount() const, 0x0060ADB0);
DEFINE_IMPLEMENTATION(int StorageClass::Get_Amount(TiberiumType) const, 0x0060ADD0);
DEFINE_IMPLEMENTATION(int StorageClass::Increase_Amount(int, TiberiumType), 0x0060ADE0);
DEFINE_IMPLEMENTATION(int StorageClass::Decrease_Amount(int, TiberiumType), 0x0060AE00);
DEFINE_IMPLEMENTATION(StorageClass StorageClass::operator+(StorageClass &) const, 0x0060AE20);
DEFINE_IMPLEMENTATION(StorageClass StorageClass::operator+=(StorageClass &), 0x0060AE90);
DEFINE_IMPLEMENTATION(StorageClass StorageClass::operator-(StorageClass &) const, 0x0060AEE0);
DEFINE_IMPLEMENTATION(StorageClass StorageClass::operator-=(StorageClass &), 0x0060AF50);
DEFINE_IMPLEMENTATION(int StorageClass::First_Used_Slot() const, 0x0060AFA0);

DEFINE_IMPLEMENTATION(bool Read_Scenario_INI(const char *, bool), 0x005DD4C0);
DEFINE_IMPLEMENTATION(void Write_Scenario_INI(const char *, bool), 0x005DDFE0);

DEFINE_IMPLEMENTATION(BOOL STDMETHODCALLTYPE MapClass::Is_Visible(CellStruct), 0x0050F1B0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(MapClass::MapClass(), 0x0050EAD0);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(MapClass::MapClass(const NoInitClass &), 0x0050EBE0);
DEFINE_IMPLEMENTATION(MapClass::~MapClass(), 0x0050ED30);
DEFINE_IMPLEMENTATION(void MapClass::One_Time(), 0x0050F2E0);
DEFINE_IMPLEMENTATION(void MapClass::Init_Clear(), 0x0050F4D0);
DEFINE_IMPLEMENTATION(void MapClass::Alloc_Cells(), 0x0050F590);
DEFINE_IMPLEMENTATION(void MapClass::Free_Cells(), 0x0050F5F0);
DEFINE_IMPLEMENTATION(void MapClass::Init_Cells(), 0x0050F6B0);
DEFINE_IMPLEMENTATION(void MapClass::Detach(TARGET, bool), 0x0051DE80);
DEFINE_IMPLEMENTATION(bool MapClass::entry_64() const, 0x0047C190);
DEFINE_IMPLEMENTATION(void MapClass::Logic(), 0x00514300);
DEFINE_IMPLEMENTATION(void MapClass::Set_Map_Dimensions(Rect &, bool, int, bool), 0x0050F700);
DEFINE_IMPLEMENTATION(void MapClass::entry_70(), 0x00510A20);
DEFINE_IMPLEMENTATION(CellClass & MapClass::operator [] (const CellStruct &), 0x0050F280);
DEFINE_IMPLEMENTATION(const CellClass & MapClass::operator [] (const CellStruct &) const, 0x0050F280);
DEFINE_IMPLEMENTATION(CellClass & MapClass::operator [] (const CoordStruct &), 0x0050F210);
DEFINE_IMPLEMENTATION(const CellClass & MapClass::operator [] (const CoordStruct &) const, 0x0050F210);
DEFINE_IMPLEMENTATION(void MapClass::Sight_From(CellStruct &, int, HouseClass *, bool, bool, bool, bool), 0x00510B60);
DEFINE_IMPLEMENTATION(void MapClass::Place_Down(CellStruct &, ObjectClass *), 0x00511070);
DEFINE_IMPLEMENTATION(void MapClass::Pick_Up(CellStruct &, ObjectClass *), 0x005111B0);
DEFINE_IMPLEMENTATION(long MapClass::Overpass(), 0x005112F0);
DEFINE_IMPLEMENTATION(int MapClass::Cell_Region(CellStruct &), 0x00514460);
DEFINE_IMPLEMENTATION(int MapClass::Cell_Threat(CellStruct &, HouseClass *), 0x00514490);
DEFINE_IMPLEMENTATION(bool MapClass::Place_Random_Crate(), 0x00514500);
DEFINE_IMPLEMENTATION(bool MapClass::Remove_Crate(CellStruct &), 0x005145D0);
DEFINE_IMPLEMENTATION(int MapClass::MapClass::Validate(), 0x005147E0);
DEFINE_IMPLEMENTATION(ObjectClass *MapClass::Close_Object(CoordStruct &) const, 0x005147F0);
DEFINE_IMPLEMENTATION(CellStruct MapClass::Nearby_Location(CellStruct &, SpeedType, int, MZoneType, bool, int, int, bool, bool, bool, bool, CellStruct) const, 0x005161A0);
DEFINE_IMPLEMENTATION(bool MapClass::Base_Region(CellStruct &, HousesType &, ZoneType &) const, 0x00516CB0);
DEFINE_IMPLEMENTATION(const CellStruct MapClass::Pick_Random_Location(), 0x0051DFB0);
DEFINE_IMPLEMENTATION(void MapClass::Shroud_The_Map(), 0x0051E010);
DEFINE_IMPLEMENTATION(void MapClass::Reveal_The_Map(), 0x0051E0A0);
DEFINE_IMPLEMENTATION(bool MapClass::In_Radar(CellStruct &, bool) const, 0x0051E380);
DEFINE_IMPLEMENTATION(bool MapClass::In_Radar(CellClass &, bool) const, 0x0051E460);
DEFINE_IMPLEMENTATION(bool MapClass::In_Radar(CoordStruct &) const, 0x0051E510);

LayerClass::LayerClass() : DynamicVectorClass() { *((unsigned long *)this) = (unsigned long)0x006CDAE0; }
LayerClass::~LayerClass() {}
DEFINE_IMPLEMENTATION(bool LayerClass::Submit(ObjectClass const *, bool), 0x004FCD70);
DEFINE_IMPLEMENTATION(void LayerClass::Init(), 0x00402480);
DEFINE_IMPLEMENTATION(void LayerClass::One_Time(), 0x00402490);
DEFINE_IMPLEMENTATION(void LayerClass::Sort(), 0x004FCDF0);
DEFINE_IMPLEMENTATION(bool LayerClass::Sorted_Add(ObjectClass const *), 0x004FCE50);
void LayerClass::Remove(ObjectClass *object) { DynamicVectorClass<ObjectClass *>::Delete(object); }

LogicClass::LogicClass() : LayerClass() { *((unsigned long *)this) = (unsigned long)0x006CA704; }
LogicClass::~LogicClass() {}
DEFINE_IMPLEMENTATION(bool LogicClass::Submit(ObjectClass const *, bool), 0x00507600);
DEFINE_IMPLEMENTATION(void LogicClass::Init(), 0x00402480);
DEFINE_IMPLEMENTATION(void LogicClass::One_Time(), 0x00402490);
DEFINE_IMPLEMENTATION(void LogicClass::Detach(TARGET, bool), 0x00507400);
DEFINE_IMPLEMENTATION(void LogicClass::AI(), 0x00506AB0);
DEFINE_IMPLEMENTATION(void LogicClass::func_507210(), 0x00507210);
DEFINE_IMPLEMENTATION(void LogicClass::Remove(ObjectClass *const), 0x00507630);
DEFINE_IMPLEMENTATION(void LogicClass::func_507470(), 0x00507470);

GadgetClass::GadgetClass() : X(0), Y(0), Width(0), Height(0), IsToRepaint(false), IsSticky(false), IsDisabled(false), Flags(0) { *((unsigned long *)this) = (unsigned long)0x006D07F4; }
DEFINE_IMPLEMENTATION_CONSTRUCTOR(GadgetClass::GadgetClass(int, int, int, int, unsigned, bool), 0x004A9BF0);
GadgetClass::GadgetClass(const NoInitClass &x) : LinkClass(x) { *((unsigned long *)this) = (unsigned long)0x006D07F4; }
DEFINE_IMPLEMENTATION_CONSTRUCTOR(GadgetClass::GadgetClass(const GadgetClass &), 0x004A9C40);
DEFINE_IMPLEMENTATION(GadgetClass::~GadgetClass(), 0x004A9C90);
DEFINE_IMPLEMENTATION(GadgetClass *GadgetClass::Get_Next() const, 0x004A9D90);
DEFINE_IMPLEMENTATION(GadgetClass *GadgetClass::Get_Prev() const, 0x004A9DA0);
DEFINE_IMPLEMENTATION(GadgetClass *GadgetClass::Remove(), 0x004A9D70);
DEFINE_IMPLEMENTATION(KeyNumType GadgetClass::Input(), 0x004A9E70);
DEFINE_IMPLEMENTATION(void GadgetClass::Draw_All(bool), 0x004A9E40);
DEFINE_IMPLEMENTATION(void GadgetClass::Delete_List(), 0x004A9DB0);
DEFINE_IMPLEMENTATION(ControlClass *GadgetClass::Extract_Gadget(unsigned), 0x004AA070);
DEFINE_IMPLEMENTATION(void GadgetClass::Flag_List_To_Redraw(), 0x0045DFA0);
DEFINE_IMPLEMENTATION(void GadgetClass::Disable(), 0x004A9D60);
DEFINE_IMPLEMENTATION(void GadgetClass::Enable(), 0x004A9D50);
DEFINE_IMPLEMENTATION(unsigned GadgetClass::Get_ID() const, 0x0047C150);
DEFINE_IMPLEMENTATION(void GadgetClass::Flag_To_Redraw(), 0x004AA0B0);
DEFINE_IMPLEMENTATION(void GadgetClass::Peer_To_Peer(unsigned, KeyNumType &, ControlClass &), 0x00463B50);
DEFINE_IMPLEMENTATION(void GadgetClass::Set_Focus(), 0x004AA0F0);
DEFINE_IMPLEMENTATION(void GadgetClass::Clear_Focus(), 0x004AA120);
DEFINE_IMPLEMENTATION(bool GadgetClass::Has_Focus(), 0x004AA140);
DEFINE_IMPLEMENTATION(bool GadgetClass::Is_List_To_Redraw(), 0x004AA150);
DEFINE_IMPLEMENTATION(bool GadgetClass::Is_To_Redraw(), 0x0045DFB0);
DEFINE_IMPLEMENTATION(void GadgetClass::Set_Position(int, int), 0x004AA170);
DEFINE_IMPLEMENTATION(void GadgetClass::Set_Size(int, int), 0x004AA190);
DEFINE_IMPLEMENTATION(bool GadgetClass::Draw_Me(bool), 0x004A9E20);
DEFINE_IMPLEMENTATION(void GadgetClass::Sticky_Process(unsigned), 0x004AA0C0);
DEFINE_IMPLEMENTATION(bool GadgetClass::Action(unsigned, KeyNumType &), 0x004A9E00);
DEFINE_IMPLEMENTATION(bool GadgetClass::Clicked_On(KeyNumType &, unsigned, int, int), 0x004A9CF0);
DEFINE_IMPLEMENTATION(ColorSchemeType GadgetClass::Get_Color_Scheme(), 0x004A9BD0);

DEFINE_IMPLEMENTATION_CONSTRUCTOR(ControlClass::ControlClass(unsigned, int, int, int, int, unsigned, bool), 0x00463A20);
DEFINE_IMPLEMENTATION_CONSTRUCTOR(ControlClass::ControlClass(const ControlClass &), 0x00463A70);
ControlClass::ControlClass(const NoInitClass &x) : GadgetClass(x) { *((unsigned long *)this) = (unsigned long)0x006CD1AC; }
DEFINE_IMPLEMENTATION(void ControlClass::Make_Peer(GadgetClass &), 0x00463B00);
DEFINE_IMPLEMENTATION(bool ControlClass::Draw_Me(bool), 0x00463B20);
DEFINE_IMPLEMENTATION(unsigned ControlClass::Get_ID() const, 0x00463B10);
DEFINE_IMPLEMENTATION(bool ControlClass::Action(unsigned, KeyNumType &), 0x00463AA0);


/**
 *  Global definitions
 */
WWKeyboardClass *&WWKeyboard = Make_Global<WWKeyboardClass *>(0x007482C0);
OptionsClass &Options = Make_Global<OptionsClass>(0x007E4720);
SpecialClass &Special = Make_Global<SpecialClass>(0x007E4540);
WWMouseClass *&WWMouse = Make_Global<WWMouseClass *>(0x0074C8F0);
DSurface *&TileSurface = Make_Global<DSurface *>(0x0074C5CC);
DSurface *&SidebarSurface = Make_Global<DSurface *>(0x0074C5D0);
DSurface *&PrimarySurface = Make_Global<DSurface *>(0x0074C5D8);
DSurface *&HiddenSurface = Make_Global<DSurface *>(0x0074C5DC);
DSurface *&AlternateSurface = Make_Global<DSurface *>(0x0074C5E0);
DSurface *&TempSurface = Make_Global<DSurface *>(0x0074C5E4);
DSurface *&CompositeSurface = Make_Global<DSurface *>(0x0074C5EC);
Random2Class &NonCriticalRandomNumber = Make_Global<Random2Class>(0x0074BE40);
long &Frame = Make_Global<long>(0x0074BE40);
ScenarioClass *&Scen = Make_Global<ScenarioClass *>(0x007E2438);
SessionClass &Session = Make_Global<SessionClass>(0x007E2458);
SwizzleManagerClass &SwizzleManager = Make_Global<SwizzleManagerClass>(0x0080CD50);
ConvertClass *&CameoDrawer = Make_Global<ConvertClass *>(0x007481F0);
ConvertClass *&ObjectDrawer = Make_Global<ConvertClass *>(0x007481F4);
ConvertClass *&VoxelDrawer = Make_Global<ConvertClass *>(0x007481F8);
ConvertClass *&TiberiumDrawer = Make_Global<ConvertClass *>(0x007481FC);
ConvertClass *&AnimDrawer = Make_Global<ConvertClass *>(0x00748200);
ConvertClass *&NormalDrawer = Make_Global<ConvertClass *>(0x0087F6C4);
ConvertClass *&MouseDrawer = Make_Global<ConvertClass *>(0x00748208);
ConvertClass *&SidebarDrawer = Make_Global<ConvertClass *>(0x0074820C);
ToolTipManager *&ToolTipHandler = Make_Global<ToolTipManager *>(0x0074C638);
VersionClass &VerNum = Make_Global<VersionClass>(0x007E4880);
CDControlClass &CDControl = Make_Global<CDControlClass>(0x007608B8);
WWFontClass *&Metal12FontPtr = Make_Global<WWFontClass *>(0x0074821C);
WWFontClass *&MapFontPtr = Make_Global<WWFontClass *>(0x00748228);
WWFontClass *&Font6Ptr = Make_Global<WWFontClass *>(0x00748220);
WWFontClass *&EditorFont = Make_Global<WWFontClass *>(0x00748214);
WWFontClass *&Font8Ptr = Make_Global<WWFontClass *>(0x00748224);
WWFontClass *&GradFont6Ptr = Make_Global<WWFontClass *>(0x00748218);
WinsockInterfaceClass *&PacketTransport = Make_Global<WinsockInterfaceClass *>(0x0074C8D8);
Tactical *&TacticalMap = Make_Global<Tactical  *>(0x0074C5F4);
LogicClass *&Logic = Make_Global<LogicClass *>(0x007482C8);


/**
 *  Class/namespaced static definitions.
 */
unsigned &DSurface::RedLeft = Make_Global<unsigned>(0x007A2C88);
unsigned &DSurface::RedRight = Make_Global<unsigned>(0x007A2C8C);
unsigned &DSurface::GreenLeft = Make_Global<unsigned>(0x007A2C98);
unsigned &DSurface::GreenRight = Make_Global<unsigned>(0x007A2C9C);
unsigned &DSurface::BlueLeft = Make_Global<unsigned>(0x007A2C90);
unsigned &DSurface::BlueRight = Make_Global<unsigned>(0x007A2C94);
unsigned short &DSurface::ColorGrey = Make_Global<unsigned short>(0x007A2CA0);
unsigned short &DSurface::ColorMidGrey = Make_Global<unsigned short>(0x007A2CA2);
unsigned short &DSurface::ColorDarkGrey = Make_Global<unsigned short>(0x007A2CA4);
int &DSurface::RGBPixelFormat = Make_Global<int>(0x006F9808);
bool &DSurface::AllowStretchBlits = Make_Global<bool>(0x007A2CA6);
bool &DSurface::AllowHardwareBlitFills = Make_Global<bool>(0x006F980C);
GadgetClass *&GScreenClass::Buttons = Make_Global<GadgetClass *>(0x007E4ABC);
GadgetClass *&GadgetClass::StuckOn = Make_Global<GadgetClass *>(0x007B3388);
GadgetClass *&GadgetClass::LastList = Make_Global<GadgetClass *>(0x007B338C);
GadgetClass *&GadgetClass::Focused = Make_Global<GadgetClass *>(0x007B3390);
char *&GadgetClass::GadgetColorScheme = Make_Global<char *>(0x006FB4FC);


/**
 *  Global vectors and heaps.
 */
DynamicVectorClass<AbstractTypeClass *> &AbstractTypes = Make_Global<DynamicVectorClass<AbstractTypeClass *>>(0x007E4550);
DynamicVectorClass<ObjectTypeClass *> &ObjectTypes = Make_Global<DynamicVectorClass<ObjectTypeClass *>>(0x008087C0);
DynamicVectorClass<TechnoTypeClass *> &TechnoTypes = Make_Global<DynamicVectorClass<TechnoTypeClass *>>(0x007E46C0);
DynamicVectorClass<BuildingTypeClass *> &BuildingTypes = Make_Global<DynamicVectorClass<BuildingTypeClass *>>(0x007E21A0);
DynamicVectorClass<ConvertClass *> &Converts = Make_Global<DynamicVectorClass<ConvertClass *>>(0x00761120);
DynamicVectorClass<LightConvertClass *> &TileDrawers = Make_Global<DynamicVectorClass<LightConvertClass *>>(0x00761120);
DynamicVectorClass<IsometricTileTypeClass *> &IsoTileTypes = Make_Global<DynamicVectorClass<IsometricTileTypeClass *>>(0x007E48C8);
DynamicVectorClass<HouseTypeClass *> &HouseTypes = Make_Global<DynamicVectorClass<HouseTypeClass *>>(0x007E21D0);
DynamicVectorClass<UnitTypeClass *> &UnitTypes = Make_Global<DynamicVectorClass<UnitTypeClass *>>(0x007E2218);
DynamicVectorClass<InfantryTypeClass *> &InfantryTypes = Make_Global<DynamicVectorClass<InfantryTypeClass *>>(0x007E4010);
DynamicVectorClass<AircraftTypeClass *> &AircraftTypes = Make_Global<DynamicVectorClass<AircraftTypeClass *>>(0x007E2420);
DynamicVectorClass<VoxelAnimTypeClass *> &VoxelAnimTypes = Make_Global<DynamicVectorClass<VoxelAnimTypeClass *>>(0x007E46F0);
DynamicVectorClass<WeaponTypeClass *> &WeaponTypes = Make_Global<DynamicVectorClass<WeaponTypeClass *>>(0x0074C828);
DynamicVectorClass<BulletTypeClass *> &BulletTypes = Make_Global<DynamicVectorClass<BulletTypeClass *>>(0x007E21B8);
DynamicVectorClass<WarheadTypeClass *> &WarheadTypes = Make_Global<DynamicVectorClass<WarheadTypeClass *>>(0x0074C798);
DynamicVectorClass<OverlayTypeClass *> &OverlayTypes = Make_Global<DynamicVectorClass<OverlayTypeClass *>>(0x007E22A0);
DynamicVectorClass<SpotlightClass *> &Spotlights = Make_Global<DynamicVectorClass<SpotlightClass *>>(0x008089A8);
DynamicVectorClass<CommandClass *> &Commands = Make_Global<DynamicVectorClass<CommandClass *>>(0x007481A8);

IndexClass<KeyNumType, CommandClass *> &HotkeyIndex = Make_Global<IndexClass<KeyNumType, CommandClass *>>(0x007481C0);

QueueClass<EventClass, MAX_EVENTS> &OutList = Make_Global< QueueClass<EventClass, MAX_EVENTS> >(0x007E15F8);
QueueClass<EventClass, (MAX_EVENTS * 64)> &DoList = Make_Global< QueueClass<EventClass, (MAX_EVENTS * 64)> >(0x007B3530);


/**
 *  Various global definitions, constants and strings.
 */
const CoordStruct AdjacentCoord[FACING_COUNT] = { // 0x007611A8
    CoordStruct(0,    -256, 0),  // NORTH
    CoordStruct(256,  -256, 0),  // NORTH EAST
    CoordStruct(256,  0,    0),  // EAST
    CoordStruct(256,  256,  0),  // SOUTH EAST
    CoordStruct(0,    256,  0),  // SOUTH
    CoordStruct(-256, 256,  0),  // SOUTH WEST
    CoordStruct(-256, 0,    0),  // WEST
    CoordStruct(-256, -256, 0),  // NORTH WEST
};

const CellStruct AdjacentCell[FACING_COUNT] = { // 0x00761148
    CellStruct(0,  -1),  // NORTH
    CellStruct(1,  -1),  // NORTH EAST
    CellStruct(1,  0),   // EAST
    CellStruct(1,  1),   // SOUTH EAST
    CellStruct(0,  1),   // SOUTH
    CellStruct(-1, 1),   // SOUTH WEST
    CellStruct(-1, 0),   // WEST
    CellStruct(-1, -1),  // NORTH WEST
};
