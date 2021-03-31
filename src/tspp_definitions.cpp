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
