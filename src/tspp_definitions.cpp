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
DynamicVectorClass<CommandClass *> &Commands = Make_Global<DynamicVectorClass<CommandClass *>>(0x007481A8);

IndexClass<KeyNumType, CommandClass *> &HotkeyIndex = Make_Global<IndexClass<KeyNumType, CommandClass *>>(0x007481C0);
