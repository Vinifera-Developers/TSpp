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
 *  @brief         Function definitions for the TS++ project.
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

#include "abstract.h"
#include "abstracttype.h"
#include "abuffer.h"
#include "addon.h"
#include "ahandle.h"
#include "aircraft.h"
#include "aircrafttype.h"
#include "aitrigtype.h"
#include "alphashape.h"
#include "anim.h"
#include "animtype.h"
#include "b64pipe.h"
#include "b64straw.h"
#include "base.h"
#include "base64.h"
#include "bfiofile.h"
#include "blitblit.h"
#include "bounce.h"
#include "brain.h"
#include "bsurface.h"
#include "buff.h"
#include "buffpipe.h"
#include "buffstraw.h"
#include "building.h"
#include "buildinglight.h"
#include "buildingtype.h"
#include "buildnum.h"
#include "bullet.h"
#include "bullettype.h"
#include "campaign.h"
#include "cargo.h"
#include "ccfile.h"
#include "ccini.h"
#include "cctooltip.h"
#include "cd.h"
#include "cdctrl.h"
#include "cdfile.h"
#include "cell.h"
#include "checkbox.h"
#include "cheklist.h"
#include "clipline.h"
#include "colorscheme.h"
#include "colrlist.h"
#include "combat.h"
#include "command.h"
#include "connpoint.h"
#include "convert.h"
#include "coord.h"
#include "counter.h"
#include "crate.h"
#include "crcpipe.h"
#include "crcstraw.h"
#include "credits.h"
#include "cstraw.h"
#include "cstream.h"
#include "dial8.h"
#include "dict.h"
#include "display.h"
#include "door.h"
#include "drawbuff.h"
#include "drawshape.h"
#include "drivelocomotion.h"
#include "drop.h"
#include "droppodlocomotion.h"
#include "dropship.h"
#include "dsaudio.h"
#include "dsurface.h"
#include "edit.h"
#include "empulse.h"
#include "environment.h"
#include "event.h"
#include "facing.h"
#include "factory.h"
#include "fastmath.h"
#include "fatal.h"
#include "fetchres.h"
#include "field.h"
#include "filepcx.h"
#include "filepipe.h"
#include "filestraw.h"
#include "flylocomotion.h"
#include "foggedobject.h"
#include "foot.h"
#include "ftimer.h"
#include "fuse.h"
#include "gadget.h"
#include "gametime.h"
#include "gauge.h"
#include "gcntrl.h"
#include "gscreen.h"
#include "house.h"
#include "housetype.h"
#include "hoverlocomotion.h"
#include "hsv.h"
#include "infantry.h"
#include "infantrytype.h"
#include "ini.h"
#include "ionblast.h"
#include "ionstorm.h"
#include "ipxmgr.h"
#include "isotile.h"
#include "isotiletype.h"
#include "jumpjetlocomotion.h"
#include "laserdraw.h"
#include "layer.h"
#include "lcw.h"
#include "lcwpipe.h"
#include "lcwstraw.h"
#include "levitatelocomotion.h"
#include "lightconvert.h"
#include "lightsource.h"
#include "link.h"
#include "list.h"
#include "loadoptions.h"
#include "locomotion.h"
#include "logic.h"
#include "lzo.h"
#include "lzopipe.h"
#include "lzostraw.h"
#include "map.h"
#include "matrix3d.h"
#include "mechlocomotion.h"
#include "mission.h"
#include "mixfile.h"
#include "mono.h"
#include "motionlib.h"
#include "mouse.h"
#include "msgbox.h"
#include "msglist.h"
#include "multimiss.h"
#include "multiscore.h"
#include "newdel.h"
#include "newmenu.h"
#include "object.h"
#include "objecttype.h"
#include "options.h"
#include "overlay.h"
#include "overlaytype.h"
#include "ownrdraw.h"
#include "packet.h"
#include "palette.h"
#include "particle.h"
#include "particlesys.h"
#include "particlesystype.h"
#include "particletype.h"
#include "pipe.h"
#include "pk.h"
#include "playmovie.h"
#include "power.h"
#include "preview.h"
#include "progressscreen.h"
#include "quat.h"
#include "queue.h"
#include "radar.h"
#include "radarevent.h"
#include "radio.h"
#include "ramfile.h"
#include "random.h"
#include "rawfile.h"
#include "readline.h"
#include "reinf.h"
#include "restate.h"
#include "rgb.h"
#include "rle.h"
#include "rules.h"
#include "saveload.h"
#include "savever.h"
#include "scenario.h"
#include "script.h"
#include "scripttype.h"
#include "scroll.h"
#include "sendfile.h"
#include "session.h"
#include "sha.h"
#include "shapebtn.h"
#include "shapeset.h"
#include "shapipe.h"
#include "shastraw.h"
#include "side.h"
#include "sidebar.h"
#include "slider.h"
#include "smudge.h"
#include "smudgetype.h"
#include "special.h"
#include "spotlight.h"
#include "sprite.h"
#include "spritecollection.h"
#include "statbtn.h"
#include "staticbuffer.h"
#include "stimer.h"
#include "storage.h"
#include "straw.h"
#include "super.h"
#include "supertype.h"
#include "surface.h"
#include "swizzle.h"
#include "tab.h"
#include "tactical.h"
#include "taction.h"
#include "tag.h"
#include "tagtype.h"
#include "target.h"
#include "taskforce.h"
#include "tclassfactory.h"
#include "team.h"
#include "teamtype.h"
#include "techno.h"
#include "technotype.h"
#include "teleportlocomotion.h"
#include "terrain.h"
#include "terraintype.h"
#include "tevent.h"
#include "textbtn.h"
#include "textfile.h"
#include "textprint.h"
#include "theme.h"
#include "tiberium.h"
#include "tibsun_functions.h"
#include "toggle.h"
#include "tooltip.h"
#include "tracker.h"
#include "trigger.h"
#include "triggertype.h"
#include "ttimer.h"
#include "tube.h"
#include "txtlabel.h"
#include "unit.h"
#include "unittype.h"
#include "utracker.h"
#include "vector3.h"
#include "veinholemonster.h"
#include "version.h"
#include "veterancy.h"
#include "voc.h"
#include "vox.h"
#include "voxelanim.h"
#include "voxelanimtype.h"
#include "voxellib.h"
#include "voxelpal.h"
#include "vqa.h"
#include "walklocomotion.h"
#include "warheadtype.h"
#include "wave.h"
#include "waypoint.h"
#include "waypointpath.h"
#include "weapontype.h"
#include "windialog.h"
#include "winfont.h"
#include "wolapi.h"
#include "wspipx.h"
#include "wsproto.h"
#include "wspudp.h"
#include "wstring.h"
#include "wwcrc.h"
#include "wwfont.h"
#include "wwkeyboard.h"
#include "wwmouse.h"
#include "xmp.h"
#include "xsurface.h"
#include "zbuffer.h"


std::vector<TSPP_SymbolEntry> TSPP_Symbols;
std::vector<TSPP_ModuleEntry> TSPP_Modules;


/**
 *  #NOTE:
 *  Any constructors defined here are because they are inlined in the games binary and
 *  redefining them in TS++ will cause the game to use the new table, so to get
 *  around this we need to define the constructor then immediately the virtual
 *  table pointer with the games table.
 *
 */


/**
 *  Function definitions
 */
Pipe::Pipe() : ChainTo(nullptr), ChainFrom(nullptr) { *((unsigned long*)this) = (unsigned long)0x006CDC84; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(Pipe::~Pipe(), 0x005A9430);
DEFINE_IMPLEMENTATION(int Pipe::Flush(), 0x005A94E0);
DEFINE_IMPLEMENTATION(int Pipe::End(), 0x0044CFF0);
DEFINE_IMPLEMENTATION(void Pipe::Put_To(Pipe*), 0x005A9470);
DEFINE_IMPLEMENTATION(int Pipe::Put(const void*, int), 0x005A94C0);

Straw::Straw() : ChainTo(nullptr), ChainFrom(nullptr) { *((unsigned long*)this) = (unsigned long)0x006CDC5C; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(Straw::~Straw(), 0x0060AFC0);
DEFINE_IMPLEMENTATION(void Straw::Get_From(Straw*), 0x0060B000);
DEFINE_IMPLEMENTATION(int Straw::Get(void*, int), 0x0060B050);

FilePipe::FilePipe(FileClass* file) : File(file), HasOpened(false) {}
FilePipe::FilePipe(FileClass& file) : File(&file), HasOpened(false) {}
FilePipe::~FilePipe() {}
DEFINE_IMPLEMENTATION(int FilePipe::Put(const void*, int), 0x006A6A50);
DEFINE_IMPLEMENTATION(int FilePipe::End(), 0x006A6A20);

FileStraw::FileStraw(FileClass* file) : File(file), HasOpened(false) {}
FileStraw::FileStraw(FileClass& file) : File(&file), HasOpened(false) {}
FileStraw::~FileStraw() {}
DEFINE_IMPLEMENTATION(int FileStraw::Get(void*, int), 0x006A6B00);

RawFileClass::RawFileClass() : Rights(FILE_ACCESS_READ), BiasStart(0), BiasLength(-1), Handle(INVALID_HANDLE_VALUE), Filename(nullptr), Date(0), Time(0), Allocated(false) { *((unsigned long*)this) = (unsigned long)0x006D5E34; }
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(RawFileClass::RawFileClass(const char *), 0x005BE310);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(RawFileClass::~RawFileClass(), 0x005BE290);
DEFINE_IMPLEMENTATION(const char* RawFileClass::File_Name() const, 0x00407230);
DEFINE_IMPLEMENTATION(const char* RawFileClass::Set_Name(const char*), 0x005BE340);
DEFINE_IMPLEMENTATION(bool RawFileClass::Create(), 0x005BE9C0);
DEFINE_IMPLEMENTATION(bool RawFileClass::Delete(), 0x005BEA00);
DEFINE_IMPLEMENTATION(bool RawFileClass::Is_Available(bool), 0x005BE470);
DEFINE_IMPLEMENTATION(bool RawFileClass::Is_Open() const, 0x005BEC90);
DEFINE_IMPLEMENTATION(bool RawFileClass::Open(const char*, FileAccessType), 0x005BE3B0);
DEFINE_IMPLEMENTATION(bool RawFileClass::Open(FileAccessType), 0x005BE3D0);
DEFINE_IMPLEMENTATION(long RawFileClass::Read(void*, int), 0x005BE560);
DEFINE_IMPLEMENTATION(off_t RawFileClass::Seek(off_t, FileSeekType), 0x005BE770);
DEFINE_IMPLEMENTATION(off_t RawFileClass::Size(), 0x005BE940);
DEFINE_IMPLEMENTATION(long RawFileClass::Write(const void*, int), 0x005BE640);
DEFINE_IMPLEMENTATION(void RawFileClass::Close(), 0x005BE520);
DEFINE_IMPLEMENTATION(LONG RawFileClass::Get_Date_Time() const, 0x005BEA60);
DEFINE_IMPLEMENTATION(bool RawFileClass::Set_Date_Time(LONG), 0x005BEAB0);
DEFINE_IMPLEMENTATION(void RawFileClass::Error(FileErrorType, bool, const char*), 0x005BE300);
DEFINE_IMPLEMENTATION(void RawFileClass::Bias(off_t, int), 0x005BEB20);
DEFINE_IMPLEMENTATION(off_t RawFileClass::Raw_Seek(off_t, FileSeekType), 0x005BEB90);
RawFileClass::RawFileClass(const Wstring& filename) : Rights(FILE_ACCESS_READ), BiasStart(0), BiasLength(-1), Handle(INVALID_HANDLE_VALUE), Filename((char*)filename.Peek_Buffer()), Date(0), Time(0), Allocated(false) { *((unsigned long*)this) = (unsigned long)0x006D5E34; }

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(MixFileClass::MixFileClass(const char *, const PKey *), 0x00559A10);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(MixFileClass::~MixFileClass(), 0x00559D40);
DEFINE_IMPLEMENTATION(void MixFileClass::Free(), 0x0055A190);
DEFINE_IMPLEMENTATION(bool MixFileClass::Free(const char*), 0x00559C80);
DEFINE_IMPLEMENTATION(bool MixFileClass::Cache(const Buffer*), 0x00559F30);
DEFINE_IMPLEMENTATION(bool MixFileClass::Cache(const char*, Buffer const*), 0x00559E90);
DEFINE_IMPLEMENTATION(bool MixFileClass::Offset(const char*, void**, MixFileClass**, long*, long*), 0x0055A1C0);
DEFINE_IMPLEMENTATION(const void* MixFileClass::Retrieve(const char*), 0x00559DE0);
DEFINE_IMPLEMENTATION(MixFileClass* MixFileClass::Finder(const char*), 0x00559E00);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(WWKeyboardClass::WWKeyboardClass(), 0x004FADC0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(WWKeyboardClass::~WWKeyboardClass(), 0x004FADB0);
DEFINE_IMPLEMENTATION(unsigned short WWKeyboardClass::Check() const, 0x004FAF30);
DEFINE_IMPLEMENTATION(unsigned short WWKeyboardClass::Get(), 0x004FAF80);
DEFINE_IMPLEMENTATION(bool WWKeyboardClass::Put(unsigned short), 0x004FB0C0);
DEFINE_IMPLEMENTATION(void WWKeyboardClass::Clear(), 0x004FB4F0);
DEFINE_IMPLEMENTATION(bool WWKeyboardClass::Down(unsigned short), 0x004FB390);
DEFINE_IMPLEMENTATION(char WWKeyboardClass::To_ASCII(unsigned short), 0x004FB2E0);
DEFINE_IMPLEMENTATION(BOOL WWKeyboardClass::Message_Handler(HWND, UINT, UINT, LONG), 0x004FB560);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(OptionsClass::OptionsClass(), 0x00589960);
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

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(Buffer::Buffer(char *, long), 0x00425C70);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(Buffer::Buffer(void *, long), 0x00425C30);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(Buffer::Buffer(const void *, long), 0x00425CB0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(Buffer::Buffer(long), 0x00425CF0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(Buffer::Buffer(const Buffer &), 0x00425D20);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(Buffer::~Buffer(), 0x00425D80);
DEFINE_IMPLEMENTATION(Buffer& Buffer::operator=(const Buffer&), 0x00425D40);
DEFINE_IMPLEMENTATION(void Buffer::Reset(), 0x00425DB0);

DEFINE_IMPLEMENTATION(int BufferPipe::Put(const void*, int), 0x006A6990);

DEFINE_IMPLEMENTATION(int BufferStraw::Get(void*, int), 0x006A6AA0);

DEFINE_IMPLEMENTATION(void SpecialClass::Init(), 0x005FCAA0);
DEFINE_IMPLEMENTATION(void SpecialClass::Read_INI(CCINIClass&), 0x005FCC60);
DEFINE_IMPLEMENTATION(void SpecialClass::Write_INI(CCINIClass&) const, 0x005FCAF0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(RAMFileClass::RAMFileClass(void *, int), 0x005BDB00);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(RAMFileClass::~RAMFileClass(), 0x005BDB50);
DEFINE_IMPLEMENTATION(const char* RAMFileClass::File_Name() const, 0x005BDE00);
DEFINE_IMPLEMENTATION(const char* RAMFileClass::Set_Name(const char*), 0x005BDE10);
DEFINE_IMPLEMENTATION(bool RAMFileClass::Create(), 0x005BDB90);
DEFINE_IMPLEMENTATION(bool RAMFileClass::Delete(), 0x005BDBB0);
DEFINE_IMPLEMENTATION(bool RAMFileClass::Is_Available(bool), 0x005BDBD0);
DEFINE_IMPLEMENTATION(bool RAMFileClass::Is_Open() const, 0x005BDBE0);
DEFINE_IMPLEMENTATION(bool RAMFileClass::Open(const char*, FileAccessType), 0x005BDBF0);
DEFINE_IMPLEMENTATION(bool RAMFileClass::Open(FileAccessType), 0x005BDC00);
DEFINE_IMPLEMENTATION(long RAMFileClass::Read(void*, int), 0x005BDC50);
DEFINE_IMPLEMENTATION(off_t RAMFileClass::Seek(off_t, FileSeekType), 0x005BDCD0);
DEFINE_IMPLEMENTATION(off_t RAMFileClass::Size(), 0x005BDD50);
DEFINE_IMPLEMENTATION(long RAMFileClass::Write(const void*, int), 0x005BDD60);
DEFINE_IMPLEMENTATION(void RAMFileClass::Close(), 0x005BDDF0);
DEFINE_IMPLEMENTATION(LONG RAMFileClass::Get_Date_Time() const, 0x005BDE20);
DEFINE_IMPLEMENTATION(bool RAMFileClass::Set_Date_Time(LONG), 0x005BDE30);
DEFINE_IMPLEMENTATION(void RAMFileClass::Error(FileErrorType, bool, const char*), 0x005BDE40);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(BufferIOFileClass::BufferIOFileClass(), 0x00420D30);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(BufferIOFileClass::BufferIOFileClass(const char *), 0x00420C40);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(BufferIOFileClass::~BufferIOFileClass(), 0x00420D90);
DEFINE_IMPLEMENTATION(const char* BufferIOFileClass::Set_Name(const char*), 0x00421090);
DEFINE_IMPLEMENTATION(bool BufferIOFileClass::Is_Available(bool), 0x00421120);
DEFINE_IMPLEMENTATION(bool BufferIOFileClass::Is_Open() const, 0x00421140);
DEFINE_IMPLEMENTATION(bool BufferIOFileClass::Open(const char*, FileAccessType), 0x00421160);
DEFINE_IMPLEMENTATION(bool BufferIOFileClass::Open(FileAccessType), 0x00421180);
DEFINE_IMPLEMENTATION(long BufferIOFileClass::Read(void*, int), 0x004214C0);
DEFINE_IMPLEMENTATION(off_t BufferIOFileClass::Seek(off_t, FileSeekType), 0x004216D0);
DEFINE_IMPLEMENTATION(off_t BufferIOFileClass::Size(), 0x004217C0);
DEFINE_IMPLEMENTATION(long BufferIOFileClass::Write(const void*, int), 0x00421270);
DEFINE_IMPLEMENTATION(void BufferIOFileClass::Close(), 0x004217E0);
DEFINE_IMPLEMENTATION(bool BufferIOFileClass::Cache(long, void*), 0x00420DD0);
DEFINE_IMPLEMENTATION(void BufferIOFileClass::Free(), 0x00420FA0);
DEFINE_IMPLEMENTATION(bool BufferIOFileClass::Commit(), 0x00420FE0);
BufferIOFileClass::BufferIOFileClass(const Wstring& filename) :
    RawFileClass(filename),
    IsOpen(false),
    IsDiskOpen(false),
    IsCached(false),
    IsChanged(false),
    UseBuffer(false),
    BufferRights(0),
    BufferPtr(0),
    BufferSize(0),
    BufferPos(0),
    BufferFilePos(0),
    BufferChangeBeg(-1),
    BufferChangeEnd(-1),
    FileSize(0),
    FilePos(0),
    TrueFileStart(0)
{
    *((unsigned long*)this) = (unsigned long)0x006CBF68;
    BufferIOFileClass::Set_Name(filename.Peek_Buffer());
}

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(CDFileClass::CDFileClass(), 0x00450610);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(CDFileClass::CDFileClass(const char *), 0x004505E0);
DEFINE_IMPLEMENTATION(const char* CDFileClass::Set_Name(const char*), 0x004509D0);
DEFINE_IMPLEMENTATION(bool CDFileClass::Open(const char*, FileAccessType), 0x00450AD0);
DEFINE_IMPLEMENTATION(bool CDFileClass::Open(FileAccessType), 0x00450690);
DEFINE_IMPLEMENTATION(int CDFileClass::Set_Search_Drives(char*), 0x004506F0);
DEFINE_IMPLEMENTATION(void CDFileClass::Add_Search_Drive(char*), 0x00450910);
DEFINE_IMPLEMENTATION(void CDFileClass::Clear_Search_Drives(), 0x00450980);
DEFINE_IMPLEMENTATION(void CDFileClass::Refresh_Search_Drives(), 0x004506A0);
DEFINE_IMPLEMENTATION(void CDFileClass::Set_CD_Drive(int), 0x00450960);
DEFINE_IMPLEMENTATION(bool CDFileClass::Find_First_File(char*), 0x00450B30);
DEFINE_IMPLEMENTATION(bool CDFileClass::Find_Next_File(char*), 0x00450C80);
DEFINE_IMPLEMENTATION(void CDFileClass::Find_Close(), 0x00450CF0);
CDFileClass::CDFileClass(const Wstring& filename) : BufferIOFileClass(filename), IsDisabled(false) { *((unsigned long*)this) = (unsigned long)0x006CAD1C; }

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(RulesClass::RulesClass(), 0x005C4350);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(RulesClass::RulesClass(const NoInitClass &), 0x005C3E00);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(RulesClass::~RulesClass(), 0x005C59B0);
DEFINE_IMPLEMENTATION(void RulesClass::Process(CCINIClass&), 0x005C6710);
DEFINE_IMPLEMENTATION(void RulesClass::Initialize(CCINIClass&), 0x005C6130);
DEFINE_IMPLEMENTATION(void RulesClass::Save(IStream*), 0x005CE410);
DEFINE_IMPLEMENTATION(void RulesClass::Load(IStream*), 0x005CEA60);
DEFINE_IMPLEMENTATION(void RulesClass::Detach(AbstractClass*, bool), 0x005D0C40);
DEFINE_IMPLEMENTATION(int RulesClass::Get_Art_Unique_ID(), 0x005D1B00);
DEFINE_IMPLEMENTATION(int RulesClass::Get_AI_Unique_ID(), 0x005D1BE0);
DEFINE_IMPLEMENTATION(void RulesClass::Load_Art_INI(), 0x005D1C10);
DEFINE_IMPLEMENTATION(bool RulesClass::SpecialWeapons(CCINIClass&), 0x005C6A60);
DEFINE_IMPLEMENTATION(bool RulesClass::AudioVisual(CCINIClass&), 0x005C6CF0);
DEFINE_IMPLEMENTATION(bool RulesClass::CrateRules(CCINIClass&), 0x005C8600);
DEFINE_IMPLEMENTATION(bool RulesClass::CombatDamage(CCINIClass&), 0x005C8850);
DEFINE_IMPLEMENTATION(bool RulesClass::Colors(CCINIClass&), 0x005C9530);
DEFINE_IMPLEMENTATION(bool RulesClass::General(CCINIClass&), 0x005C9630);
DEFINE_IMPLEMENTATION(bool RulesClass::MPlayer(CCINIClass&), 0x005CC260);
DEFINE_IMPLEMENTATION(bool RulesClass::Heap_Maximums(CCINIClass&), 0x005CC3D0);
DEFINE_IMPLEMENTATION(bool RulesClass::Infantry(CCINIClass&), 0x005CC420);
DEFINE_IMPLEMENTATION(bool RulesClass::Houses(CCINIClass&), 0x005CC490);
DEFINE_IMPLEMENTATION(bool RulesClass::Vehicles(CCINIClass&), 0x005CC500);
DEFINE_IMPLEMENTATION(bool RulesClass::Aircraft(CCINIClass&), 0x005CC570);
DEFINE_IMPLEMENTATION(bool RulesClass::Sides(CCINIClass&), 0x005CC5E0);
DEFINE_IMPLEMENTATION(bool RulesClass::SuperWeapons(CCINIClass&), 0x005CC780);
DEFINE_IMPLEMENTATION(bool RulesClass::Buildings(CCINIClass&), 0x005CC7F0);
DEFINE_IMPLEMENTATION(bool RulesClass::Terrains(CCINIClass&), 0x005CC860);
DEFINE_IMPLEMENTATION(bool RulesClass::Teams(CCINIClass&), 0x005CC8D0);
DEFINE_IMPLEMENTATION(bool RulesClass::Smudges(CCINIClass&), 0x005CC960);
DEFINE_IMPLEMENTATION(bool RulesClass::Overlays(CCINIClass&), 0x005CC9D0);
DEFINE_IMPLEMENTATION(bool RulesClass::Animations(CCINIClass&), 0x005CCA40);
DEFINE_IMPLEMENTATION(bool RulesClass::VoxelAnims(CCINIClass&), 0x005CCAB0);
DEFINE_IMPLEMENTATION(bool RulesClass::Warheads(CCINIClass&), 0x005CCB20);
DEFINE_IMPLEMENTATION(bool RulesClass::Particles(CCINIClass&), 0x005CCB90);
DEFINE_IMPLEMENTATION(bool RulesClass::ParticleSystems(CCINIClass&), 0x005CCC00);
DEFINE_IMPLEMENTATION(bool RulesClass::AI(CCINIClass&), 0x005CCC70);
DEFINE_IMPLEMENTATION(bool RulesClass::Powerups(CCINIClass&), 0x005CDCA0);
DEFINE_IMPLEMENTATION(bool RulesClass::Land_Types(CCINIClass&), 0x005CDDD0);
DEFINE_IMPLEMENTATION(bool RulesClass::IQ(CCINIClass&), 0x005CDEB0);
DEFINE_IMPLEMENTATION(bool RulesClass::JumpjetControls(CCINIClass&), 0x005CE040);
DEFINE_IMPLEMENTATION(bool RulesClass::Difficulty(CCINIClass&), 0x005CE190);
DEFINE_IMPLEMENTATION(bool RulesClass::Movies(CCINIClass&), 0x005CE310);
DEFINE_IMPLEMENTATION(bool RulesClass::Objects(CCINIClass&), 0x005D1800);
DEFINE_IMPLEMENTATION(void Difficulty_Get(CCINIClass&, DifficultyClass&, char const*), 0x005CE1E0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(Surface::Surface(int, int), 0x0047C1C0);
DEFINE_IMPLEMENTATION(bool Surface::Can_Lock(int, int) const, 0x00406D50);
DEFINE_IMPLEMENTATION(bool Surface::entry_64(int, int) const, 0x00406D60);
DEFINE_IMPLEMENTATION(Rect Surface::Get_Rect() const, 0x00406D70);
DEFINE_IMPLEMENTATION(int Surface::Get_Width() const, 0x00406DA0);
DEFINE_IMPLEMENTATION(int Surface::Get_Height() const, 0x00406DB0);
DEFINE_IMPLEMENTATION(bool Surface::entry_80() const, 0x00406E20);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(CCFileClass::CCFileClass(), 0x004497F0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(CCFileClass::CCFileClass(const char *), 0x004497B0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(CCFileClass::~CCFileClass(), 0x004E8970);
DEFINE_IMPLEMENTATION(bool CCFileClass::Is_Available(bool), 0x004499C0);
DEFINE_IMPLEMENTATION(bool CCFileClass::Is_Open() const, 0x00449A00);
DEFINE_IMPLEMENTATION(bool CCFileClass::Open(const char*, FileAccessType), 0x00407270);
DEFINE_IMPLEMENTATION(bool CCFileClass::Open(FileAccessType), 0x00449A40);
DEFINE_IMPLEMENTATION(long CCFileClass::Read(void*, int), 0x00449880);
DEFINE_IMPLEMENTATION(off_t CCFileClass::Seek(off_t, FileSeekType), 0x00449910);
DEFINE_IMPLEMENTATION(off_t CCFileClass::Size(), 0x00449970);
DEFINE_IMPLEMENTATION(long CCFileClass::Write(const void*, int), 0x00449850);
DEFINE_IMPLEMENTATION(void CCFileClass::Close(), 0x00449A10);
DEFINE_IMPLEMENTATION(LONG CCFileClass::Get_Date_Time() const, 0x00449B70);
DEFINE_IMPLEMENTATION(bool CCFileClass::Set_Date_Time(LONG), 0x00449C20);
DEFINE_IMPLEMENTATION(void CCFileClass::Error(FileErrorType error, bool, const char*), 0x00449820);
CCFileClass::CCFileClass(const Wstring& filename) : CDFileClass(filename), Data(), Position(0) { *((unsigned long*)this) = (unsigned long)0x006CAD64; }

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(WWMouseClass::WWMouseClass(XSurface *, HWND), 0x006A5000);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(WWMouseClass::~WWMouseClass(), 0x006A5170);
DEFINE_IMPLEMENTATION(void WWMouseClass::Set_Cursor(Point2D*, const ShapeSet*, int), 0x006A52A0);
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
DEFINE_IMPLEMENTATION(void WWMouseClass::Draw_1(XSurface*, bool), 0x006A5990);
DEFINE_IMPLEMENTATION(void WWMouseClass::Draw_2(XSurface*, bool), 0x006A5B90);
DEFINE_IMPLEMENTATION(void WWMouseClass::Confine_Pos(int&, int&) const, 0x006A63C0);
DEFINE_IMPLEMENTATION(void WWMouseClass::Calc_Confining_Rect(), 0x006A51E0);

DEFINE_IMPLEMENTATION(void CRCEngine::operator()(char), 0x00470CC0);
DEFINE_IMPLEMENTATION(void CRCEngine::operator()(const char*), 0x00470E60);
DEFINE_IMPLEMENTATION(long CRCEngine::operator()(const void*, int), 0x00470E90);
DEFINE_IMPLEMENTATION(long CRCEngine::CRC_Memory(const void*, int, int), 0x00471060);
DEFINE_IMPLEMENTATION(long CRCEngine::CRC_String(const char*, int), 0x004710A0);

DEFINE_IMPLEMENTATION(int CRCStraw::Get(void*, int), 0x00471160);
DEFINE_IMPLEMENTATION(long CRCStraw::Result() const, 0x004711A0);

DEFINE_IMPLEMENTATION(int CRCPipe::Put(const void*, int), 0x004710E0);
DEFINE_IMPLEMENTATION(long CRCPipe::Result() const, 0x00471110);

XSurface::XSurface() : Surface(), LockLevel(0), BytesPerPixel(0) { *((unsigned long*)this) = (unsigned long)0x006CAC04; }
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(XSurface::XSurface(int, int), 0x0047CCA0);
XSurface::XSurface(int width, int height, int bpp) : Surface(width, height), LockLevel(0), BytesPerPixel(bpp) { *((unsigned long*)this) = (unsigned long)0x006CAC04; }
DEFINE_IMPLEMENTATION(bool XSurface::Copy_From(Rect&, Rect&, Surface&, Rect&, Rect&, bool, bool), 0x006A82B0);
DEFINE_IMPLEMENTATION(bool XSurface::Copy_From(Rect&, Surface&, Rect&, bool, bool), 0x006A8150);
DEFINE_IMPLEMENTATION(bool XSurface::Copy_From(Surface&, bool, bool), 0x006A80B0);
DEFINE_IMPLEMENTATION(bool XSurface::Fill_Rect(Rect&, unsigned), 0x006A75E0);
DEFINE_IMPLEMENTATION(bool XSurface::Fill_Rect(Rect&, Rect&, unsigned), 0x006A7610);
DEFINE_IMPLEMENTATION(bool XSurface::Fill(unsigned), 0x006A8070);
DEFINE_IMPLEMENTATION(bool XSurface::Fill_Rect_Trans(Rect&, const RGBClass&, unsigned), 0x006A7900);
DEFINE_IMPLEMENTATION(bool XSurface::Draw_Ellipse(Point2D, int, int, Rect, unsigned), 0x006A7910);
DEFINE_IMPLEMENTATION(bool XSurface::Put_Pixel(Point2D&, unsigned), 0x006A7470);
DEFINE_IMPLEMENTATION(unsigned XSurface::Get_Pixel(Point2D&), 0x006A7420);
DEFINE_IMPLEMENTATION(bool XSurface::Draw_Line(Point2D&, Point2D&, unsigned), 0x006A6BB0);
DEFINE_IMPLEMENTATION(bool XSurface::Draw_Line(Rect&, Point2D&, Point2D&, unsigned), 0x006A6BE0);
DEFINE_IMPLEMENTATION(bool XSurface::Draw_Line_entry_34(Rect&, Point2D&, Point2D&, unsigned, int, int, bool), 0x006A7120);
DEFINE_IMPLEMENTATION(bool XSurface::Draw_Line_entry_38(Rect&, Point2D&, Point2D&, int, int, int, bool), 0x006A7130);
DEFINE_IMPLEMENTATION(bool XSurface::Draw_Line_entry_3C(Rect&, Point2D&, Point2D&, RGBClass&, int, int, bool, bool, bool, bool, float), 0x006A7140);
DEFINE_IMPLEMENTATION(bool XSurface::entry_40(Rect&, Point2D&, Point2D&, void (*)(Point2D&)), 0x006A7150);
DEFINE_IMPLEMENTATION(int XSurface::Draw_Dashed_Line(Point2D&, Point2D&, unsigned, bool[], int), 0x006A6E90);
DEFINE_IMPLEMENTATION(int XSurface::entry_48(Point2D&, Point2D&, unsigned, bool[], int, bool), 0x006A7100);
DEFINE_IMPLEMENTATION(bool XSurface::entry_4C(Point2D&, Point2D&, unsigned, bool), 0x006A7110);
DEFINE_IMPLEMENTATION(bool XSurface::Draw_Rect(Rect&, unsigned), 0x006A7350);
DEFINE_IMPLEMENTATION(bool XSurface::Draw_Rect(Rect&, Rect&, unsigned), 0x006A7380);
DEFINE_IMPLEMENTATION(void* XSurface::Lock(int, int), 0x00406DC0);
DEFINE_IMPLEMENTATION(bool XSurface::Unlock(), 0x00406DD0);
DEFINE_IMPLEMENTATION(bool XSurface::Is_Locked() const, 0x00406DE0);
DEFINE_IMPLEMENTATION(bool XSurface::entry_80() const, 0x00406DF0);
DEFINE_IMPLEMENTATION(bool XSurface::entry_84(Point2D&, unsigned, Rect&), 0x006A7550);
DEFINE_IMPLEMENTATION(unsigned XSurface::entry_88(Point2D&, Rect&), 0x006A74D0);
DEFINE_IMPLEMENTATION(void XSurface::Fill_Circle(const Point2D, unsigned, Rect, unsigned), 0x006A7EE0);

BSurface::BSurface() : XSurface(), BufferPtr() { *((unsigned long*)this) = (unsigned long)0x006CAB74; }
BSurface::BSurface(int width, int height, int bpp, void* buffer) : XSurface(width, height, bpp), BufferPtr((void*)buffer, int((height * width) * bpp)) { *((unsigned long*)this) = (unsigned long)0x006CAB74; }
BSurface::~BSurface() {}
DEFINE_IMPLEMENTATION(void* BSurface::Lock(int, int), 0x00406E50);
DEFINE_IMPLEMENTATION(int BSurface::Get_Bytes_Per_Pixel() const, 0x00406E90);
DEFINE_IMPLEMENTATION(int BSurface::Get_Pitch() const, 0x00406EA0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(DSurface::DSurface(), 0x0048AD10);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(DSurface::DSurface(int, int, bool), 0x0048ABB0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(DSurface::DSurface(LPDIRECTDRAWSURFACE), 0x0048B250);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(DSurface::~DSurface(), 0x0048ACA0);
DEFINE_IMPLEMENTATION(bool DSurface::Copy_From(Rect&, Rect&, Surface&, Rect&, Rect&, bool, bool), 0x0048B5E0);
DEFINE_IMPLEMENTATION(bool DSurface::Copy_From(Rect&, Surface&, Rect&, bool, bool), 0x0048B590);
DEFINE_IMPLEMENTATION(bool DSurface::Copy_From(Surface&, bool, bool), 0x004901A0);
DEFINE_IMPLEMENTATION(bool DSurface::Fill_Rect(Rect&, unsigned), 0x0048BB00);
DEFINE_IMPLEMENTATION(bool DSurface::Fill_Rect(Rect&, Rect&, unsigned), 0x0048BB30);
DEFINE_IMPLEMENTATION(bool DSurface::Fill_Rect_Trans(Rect&, const RGBClass&, unsigned), 0x0048BCE0);
DEFINE_IMPLEMENTATION(bool DSurface::Draw_Line_entry_34(Rect&, Point2D&, Point2D&, unsigned, int, int, bool), 0x0048EA90);
DEFINE_IMPLEMENTATION(bool DSurface::Draw_Line_entry_38(Rect&, Point2D&, Point2D&, int, int, int, bool), 0x0048C150);
DEFINE_IMPLEMENTATION(bool DSurface::Draw_Line_entry_3C(Rect&, Point2D&, Point2D&, RGBClass&, int, int, bool, bool, bool, bool, float), 0x0048CC00);
DEFINE_IMPLEMENTATION(int DSurface::entry_48(Point2D&, Point2D&, unsigned, bool[], int, bool), 0x0048F4B0);
DEFINE_IMPLEMENTATION(bool DSurface::entry_4C(Point2D&, Point2D&, unsigned, bool), 0x0048FB90);
DEFINE_IMPLEMENTATION(void* DSurface::Lock(int, int), 0x0048B370);
DEFINE_IMPLEMENTATION(bool DSurface::Unlock(), 0x0048B4D0);
DEFINE_IMPLEMENTATION(bool DSurface::Can_Lock(int, int) const, 0x0048B450);
DEFINE_IMPLEMENTATION(int DSurface::Get_Bytes_Per_Pixel() const, 0x0048B350);
DEFINE_IMPLEMENTATION(int DSurface::Get_Pitch() const, 0x0048B360);
DEFINE_IMPLEMENTATION(bool DSurface::Draw_Line_entry_90(Rect&, Point2D&, Point2D&, RGBClass&, RGBClass&, float&, float&), 0x0048E4B0);
DEFINE_IMPLEMENTATION(bool DSurface::Can_Blit() const, 0x0048B4B0);
DEFINE_IMPLEMENTATION(DSurface* DSurface::Create_Primary(DSurface**), 0x0048AD60);

DEFINE_IMPLEMENTATION(long Surface_Size_Of_Region(XSurface&, int, int), 0x00423330);
DEFINE_IMPLEMENTATION(bool Surface_To_Buffer(XSurface&, Rect&, Buffer&), 0x00423350);
DEFINE_IMPLEMENTATION(bool Buffer_To_Surface(XSurface&, Rect&, Buffer&), 0x00423410);
DEFINE_IMPLEMENTATION(bool Copy_To_Surface(XSurface&, Rect&, XSurface&, Rect&, Blitter&, int, ZGradientType, int, int), 0x004234D0);
DEFINE_IMPLEMENTATION(bool Copy_To_Surface(XSurface&, Rect&, Rect&, XSurface&, Rect&, Rect&, Blitter&, int, ZGradientType, int, int), 0x00423530);
DEFINE_IMPLEMENTATION(bool Copy_To_Surface_RLE(XSurface&, Rect&, XSurface&, Rect&, RLEBlitter&, int, ZGradientType, int, int), 0x00423A50);
DEFINE_IMPLEMENTATION(bool Copy_To_Surface_RLE(XSurface&, Rect&, Rect&, XSurface&, Rect&, Rect&, RLEBlitter&, int, ZGradientType, int, int, XSurface*, int, int), 0x00423AB0);

DEFINE_IMPLEMENTATION(void __cdecl Brighten_555(unsigned char*, unsigned short*, int, int, int, int), 0x006C857A);
DEFINE_IMPLEMENTATION(void __cdecl Brighten_556(unsigned char*, unsigned short*, int, int, int, int), 0x006C8657);
DEFINE_IMPLEMENTATION(void __cdecl Brighten_565(unsigned char*, unsigned short*, int, int, int, int), 0x006C8734);
DEFINE_IMPLEMENTATION(void __cdecl Brighten_655(unsigned char*, unsigned short*, int, int, int, int), 0x006C8811);

template<> BlitPlain<unsigned char>::BlitPlain() : Blitter() {}
template<> BlitPlain<unsigned char>::~BlitPlain() {}
DEFINE_IMPLEMENTATION(void BlitPlain<unsigned char>::entry_4(void*, void*, unsigned, unsigned short, int*, int*, int, int), 0x006A8CB0);
DEFINE_IMPLEMENTATION(void BlitPlain<unsigned char>::entry_8(void*, void*, unsigned, unsigned short, int*, int*, int), 0x006A8CE0);
template<> BlitPlain<unsigned short>::BlitPlain() : Blitter() {}
template<> BlitPlain<unsigned short>::~BlitPlain() {}
DEFINE_IMPLEMENTATION(void BlitPlain<unsigned short>::entry_4(void*, void*, unsigned, unsigned short, int*, int*, int, int), 0x006A8D00);
DEFINE_IMPLEMENTATION(void BlitPlain<unsigned short>::entry_8(void*, void*, unsigned, unsigned short, int*, int*, int), 0x006A8D30);
template<> BlitTrans<unsigned char>::BlitTrans() : Blitter() {}
template<> BlitTrans<unsigned char>::~BlitTrans() {}
DEFINE_IMPLEMENTATION(void BlitTrans<unsigned char>::entry_4(void*, void*, unsigned, unsigned short, int*, int*, int, int), 0x006A8BD0);
DEFINE_IMPLEMENTATION(void BlitTrans<unsigned char>::entry_8(void*, void*, unsigned, unsigned short, int*, int*, int), 0x006A8C80);
template<> BlitTrans<unsigned short>::BlitTrans() : Blitter() {}
template<> BlitTrans<unsigned short>::~BlitTrans() {}
DEFINE_IMPLEMENTATION(void BlitTrans<unsigned short>::entry_4(void*, void*, unsigned, unsigned short, int*, int*, int, int), 0x006A8D50);
DEFINE_IMPLEMENTATION(void BlitTrans<unsigned short>::entry_8(void*, void*, unsigned, unsigned short, int*, int*, int), 0x006A8D80);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE AbstractClass::QueryInterface(REFIID, LPVOID*), 0x00405BF0);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE AbstractClass::AddRef(), 0x00405C90);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE AbstractClass::Release(), 0x00405CA0);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE AbstractClass::IsDirty(), 0x00405E00);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE AbstractClass::GetSizeMax(ULARGE_INTEGER*), 0x00405D80);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE AbstractClass::Abstract_Load(IStream*), 0x00405D10);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE AbstractClass::Abstract_Save(IStream*, BOOL), 0x00405CB0);
DEFINE_IMPLEMENTATION(int AbstractClass::What_Am_I() const, 0x00405BA0);
DEFINE_IMPLEMENTATION(int AbstractClass::Fetch_ID() const, 0x00405BB0);
DEFINE_IMPLEMENTATION(VOID AbstractClass::Create_ID(), 0x00405BC0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(AbstractClass::AbstractClass(), 0x00405B50);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(AbstractClass::AbstractClass(const NoInitClass &), 0x00405B70);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(AbstractClass::~AbstractClass(), 0x00405B90);
DEFINE_IMPLEMENTATION(void AbstractClass::Init(), 0x00405E20);
DEFINE_IMPLEMENTATION(void AbstractClass::Detach(AbstractClass*, bool), 0x00405E30);
DEFINE_IMPLEMENTATION(int AbstractClass::Get_Object_Size_Delta() const, 0x00405E40);
DEFINE_IMPLEMENTATION(void AbstractClass::Object_CRC(CRCEngine&) const, 0x00405DB0);
DEFINE_IMPLEMENTATION(HousesType AbstractClass::Owner() const, 0x00405E50);
DEFINE_IMPLEMENTATION(HouseClass* AbstractClass::Owner_HouseClass() const, 0x00405E60);
DEFINE_IMPLEMENTATION(int AbstractClass::Fetch_Heap_ID() const, 0x00405E70);
DEFINE_IMPLEMENTATION(bool AbstractClass::Is_Inactive() const, 0x00405DE0);
DEFINE_IMPLEMENTATION(Coord AbstractClass::Center_Coord() const, 0x00405E80);
DEFINE_IMPLEMENTATION(Coord AbstractClass::entry_50() const, 0x00405EB0);
DEFINE_IMPLEMENTATION(bool AbstractClass::On_Ground() const, 0x00405EE0);
DEFINE_IMPLEMENTATION(bool AbstractClass::In_Air() const, 0x00405EF0);
DEFINE_IMPLEMENTATION(Coord AbstractClass::entry_5C() const, 0x00405F00);
DEFINE_IMPLEMENTATION(void AbstractClass::AI(), 0x00405F30);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(AbstractTypeClass::AbstractTypeClass(const char *), AbstractClass, 0x004061D0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(AbstractTypeClass::AbstractTypeClass(const NoInitClass &), AbstractClass, 0x00406310);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(AbstractTypeClass::~AbstractTypeClass(), 0x00406330);
DEFINE_IMPLEMENTATION(void AbstractTypeClass::Object_CRC(CRCEngine&) const, 0x00406460);
DEFINE_IMPLEMENTATION(void AbstractTypeClass::entry_64(), 0x00406490);
DEFINE_IMPLEMENTATION(bool AbstractTypeClass::Read_INI(CCINIClass&), 0x004063A0);
DEFINE_IMPLEMENTATION(bool AbstractTypeClass::Write_INI(CCINIClass&) const, 0x00406430);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(RandomClass::RandomClass(unsigned), 0x005BDEE0);
DEFINE_IMPLEMENTATION(int RandomClass::operator()(), 0x005BDEF0);
DEFINE_IMPLEMENTATION(int RandomClass::operator()(int, int), 0x005BDF10);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(Random2Class::Random2Class(unsigned), 0x005BDF80);
DEFINE_IMPLEMENTATION(int Random2Class::operator()(), 0x005BE030);
DEFINE_IMPLEMENTATION(int Random2Class::operator()(int, int), 0x005BE080);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(Random3Class::Random3Class(unsigned, unsigned), 0x005BE120);
DEFINE_IMPLEMENTATION(int Random3Class::operator()(), 0x005BE140);
DEFINE_IMPLEMENTATION(int Random3Class::operator()(int, int), 0x005BE1A0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(ScenarioClass::ScenarioClass(), 0x005DABC0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(MessageListClass::MessageListClass(), 0x00572E00);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(MessageListClass::~MessageListClass(), 0x00572E80);
DEFINE_IMPLEMENTATION(void MessageListClass::Init(int, int, int, int, int, int, int, int, int, int, int), 0x00572EA0);
DEFINE_IMPLEMENTATION(TextLabelClass* MessageListClass::Add_Message(char const*, int, char const*, ColorSchemeType, TextPrintType, int), 0x00572FE0);
DEFINE_IMPLEMENTATION(bool MessageListClass::Concat_Message(char const*, int, char const*, int), 0x005734B0);
DEFINE_IMPLEMENTATION(char* MessageListClass::Get_Message(int), 0x00573450);
DEFINE_IMPLEMENTATION(TextLabelClass* MessageListClass::Get_Label(int), 0x00573480);
DEFINE_IMPLEMENTATION(TextLabelClass* MessageListClass::Add_Edit(ColorSchemeType, TextPrintType, char*, char, int), 0x005737D0);
DEFINE_IMPLEMENTATION(void MessageListClass::Remove_Edit(), 0x00573950);
DEFINE_IMPLEMENTATION(char* MessageListClass::Get_Edit_Buf(), 0x005739B0);
DEFINE_IMPLEMENTATION(void MessageListClass::Set_Edit_Color(ColorSchemeType), 0x005739C0);
DEFINE_IMPLEMENTATION(bool MessageListClass::Manage(), 0x005739E0);
DEFINE_IMPLEMENTATION(int MessageListClass::Input(KeyNumType&), 0x00573AC0);
DEFINE_IMPLEMENTATION(void MessageListClass::Draw(), 0x00573DC0);
DEFINE_IMPLEMENTATION(int MessageListClass::Num_Messages(), 0x00573EC0);
DEFINE_IMPLEMENTATION(void MessageListClass::Set_Width(int), 0x00573EF0);
DEFINE_IMPLEMENTATION(void MessageListClass::Set_Edit_Focus(), 0x005737A0);
DEFINE_IMPLEMENTATION(bool MessageListClass::Has_Edit_Focus(), 0x005737B0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(SessionClass::SessionClass(), 0x005ECD00);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(SessionClass::~SessionClass(), 0x005ED1C0);
DEFINE_IMPLEMENTATION(void SessionClass::One_Time(), 0x005ED470);
DEFINE_IMPLEMENTATION(void SessionClass::Init(), 0x005ED500);
DEFINE_IMPLEMENTATION(int SessionClass::Create_Connections(), 0x005ED510);
DEFINE_IMPLEMENTATION(bool SessionClass::Am_I_Master(), 0x005ED6C0);
DEFINE_IMPLEMENTATION(void SessionClass::Read_MultiPlayer_Settings(), 0x005ED760);
// 005EE190
DEFINE_IMPLEMENTATION(void SessionClass::Write_MultiPlayer_Settings(), 0x005EE470);
DEFINE_IMPLEMENTATION(void SessionClass::Read_Scenario_Descriptions(), 0x005EE7D0);
DEFINE_IMPLEMENTATION(void SessionClass::Free_Scenario_Descriptions(), 0x005EEE60);
DEFINE_IMPLEMENTATION(void SessionClass::Trap_Object(), 0x005EEF60);
DEFINE_IMPLEMENTATION(ColorSchemeType SessionClass::Player_Color_To_Scheme_Color(PlayerColorType) const, 0x005EEF70);
DEFINE_IMPLEMENTATION(void SessionClass::Setup_Squads(), 0x005EFBF0);
DEFINE_IMPLEMENTATION(void SessionClass::Loading_Callback(int), 0x005EF930);
DEFINE_IMPLEMENTATION(unsigned SessionClass::Compute_Unique_ID(), 0x005EEF90);
DEFINE_IMPLEMENTATION(bool GameOptionsType::Save(IStream*), 0x005EFFA0);
DEFINE_IMPLEMENTATION(bool GameOptionsType::Load(IStream*), 0x005EFFF0);

DEFINE_IMPLEMENTATION(int Format_Window_String(char*, WWFontClass*, int, int&, int&), 0x00474960);
DEFINE_IMPLEMENTATION(Point2D Simple_Text_Print(const char*, XSurface*, Rect*, Point2D*, ColorScheme*, unsigned, TextPrintType, int), 0x00474A50);
DEFINE_IMPLEMENTATION(Point2D Plain_Text_Print(int, XSurface*, Rect*, Point2D*, unsigned, unsigned, TextPrintType, ColorSchemeType, int), 0x00475170);
DEFINE_IMPLEMENTATION(Point2D Plain_Text_Print(char const*, XSurface*, Rect*, Point2D*, unsigned, unsigned, TextPrintType, ColorSchemeType, int), 0x004751D0);
DEFINE_IMPLEMENTATION(Point2D Fancy_Text_Print(int, XSurface*, Rect*, Point2D*, ColorScheme*, unsigned, TextPrintType, ...), 0x00474D90);
DEFINE_IMPLEMENTATION(Point2D Fancy_Text_Print(const char*, XSurface*, Rect*, Point2D*, ColorScheme*, unsigned, TextPrintType, ...), 0x00474E70);
DEFINE_IMPLEMENTATION(Point2D Conquer_Clip_Text_Print(const char*, XSurface*, Rect*, Point2D*, ColorScheme*, unsigned, TextPrintType, int, const int*), 0x00474F50);

INIClass::INIClass() : SectionList(), SectionIndex(), LineComments(nullptr) { *((unsigned long*)this) = (unsigned long)0x006D193C; }
INIClass::INIClass(FileClass& file, bool load_comments) : SectionList(), SectionIndex(), LineComments(nullptr) { Load(file, load_comments); *((unsigned long*)this) = (unsigned long)0x006D193C; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(INIClass::~INIClass(), 0x004DB470);
DEFINE_IMPLEMENTATION(bool INIClass::Load(FileClass&, bool), 0x004DB780);
DEFINE_IMPLEMENTATION(bool INIClass::Load(Straw&, bool), 0x004DB7D0);
DEFINE_IMPLEMENTATION(int INIClass::Save(FileClass&, bool) const, 0x004DC180);
DEFINE_IMPLEMENTATION(int INIClass::Save(Pipe&, bool) const, 0x004DC1C0);
DEFINE_IMPLEMENTATION(bool INIClass::Clear(const char*, const char*), 0x004DB540);
DEFINE_IMPLEMENTATION(int INIClass::Entry_Count(const char*) const, 0x004DC6A0);
DEFINE_IMPLEMENTATION(const char* INIClass::Get_Entry(const char*, int) const, 0x004DC8D0);
DEFINE_IMPLEMENTATION(int INIClass::Get_String(const char*, const char*, const char*, char*, int) const, 0x004DDF60);
DEFINE_IMPLEMENTATION(bool INIClass::Put_String(const char*, const char*, const char*), 0x004DDBE0);
DEFINE_IMPLEMENTATION(int INIClass::Get_Int(const char*, const char*, int) const, 0x004DD140);
DEFINE_IMPLEMENTATION(bool INIClass::Put_Int(const char*, const char*, int, INIClass::IntegerFormatMode), 0x004DD0C0);
DEFINE_IMPLEMENTATION(int INIClass::Get_Hex(const char*, const char*, int) const, 0x004DD880);
DEFINE_IMPLEMENTATION(bool INIClass::Put_Hex(const char*, const char*, int), 0x004DD830);
DEFINE_IMPLEMENTATION(bool INIClass::Get_Bool(const char*, const char*, bool) const, 0x004DE140);
DEFINE_IMPLEMENTATION(bool INIClass::Put_Bool(const char*, const char*, bool), 0x004DE100);
DEFINE_IMPLEMENTATION(double INIClass::Get_Double(const char*, const char*, double) const, 0x004DD9F0);
DEFINE_IMPLEMENTATION(bool INIClass::Put_Double(const char*, const char*, double), 0x004DDB90);
DEFINE_IMPLEMENTATION(int INIClass::Get_TextBlock(const char*, char*, int) const, 0x004DCDE0);
DEFINE_IMPLEMENTATION(bool INIClass::Put_TextBlock(const char*, const char*), 0x004DCCF0);
DEFINE_IMPLEMENTATION(int INIClass::Get_UUBlock(const char*, void*, int) const, 0x004DCAD0);
DEFINE_IMPLEMENTATION(bool INIClass::Put_UUBlock(const char*, const void*, int), 0x004DC9A0);
DEFINE_IMPLEMENTATION(const TRect<int> INIClass::Get_Rect(const char*, const char*, const TRect<int>&) const, 0x004DD610);
DEFINE_IMPLEMENTATION(bool INIClass::Put_Rect(const char*, const char*, const TRect<int>&), 0x004DD5C0);
DEFINE_IMPLEMENTATION(const TPoint2D<int> INIClass::Get_Point(const char*, const char*, const TPoint2D<int>&) const, 0x004DE340);
DEFINE_IMPLEMENTATION(bool INIClass::Put_Point(const char*, const char*, const TPoint2D<int>&), 0x004DE300);
DEFINE_IMPLEMENTATION(const TPoint3D<int> INIClass::Get_Point(const char*, const char*, const TPoint3D<int>&) const, 0x004DE520);
DEFINE_IMPLEMENTATION(bool INIClass::Put_Point(const char*, const char*, const TPoint3D<int>&), 0x004DE4D0);
DEFINE_IMPLEMENTATION(const TPoint3D<double> INIClass::Get_Point(const char*, const char*, const TPoint3D<double>&) const, 0x004DE730);
DEFINE_IMPLEMENTATION(bool INIClass::Put_Point(const char*, const char*, const TPoint3D<double>&), 0x004DE6D0);
DEFINE_IMPLEMENTATION(const CLSID INIClass::Get_UUID(const char*, const char*, const CLSID) const, 0x004DD320);
DEFINE_IMPLEMENTATION(bool INIClass::Put_UUID(const char*, const char*, const CLSID), 0x004DD540);
DEFINE_IMPLEMENTATION(PKey INIClass::Get_PKey(bool) const, 0x004DEA30);
DEFINE_IMPLEMENTATION(bool INIClass::Put_PKey(const PKey&), 0x004DEA90);
DEFINE_IMPLEMENTATION(const INIClass::INISection* INIClass::Find_Section(const char*) const, 0x004DC550);
DEFINE_IMPLEMENTATION(const INIClass::INIEntry* INIClass::Find_Entry(const char*, const char*) const, 0x004DC770);

CCINIClass::CCINIClass() : INIClass(), IsDigestPresent(false) { *((unsigned long*)this) = (unsigned long)0x006CA8BC; }
CCINIClass::CCINIClass(FileClass& file, bool widthdigest, bool load_comments) : INIClass(file, load_comments), IsDigestPresent(widthdigest) { *((unsigned long*)this) = (unsigned long)0x006CA8BC; }
CCINIClass::~CCINIClass() {}
DEFINE_IMPLEMENTATION(bool CCINIClass::Load(FileClass&, bool, bool), 0x00449F30);
DEFINE_IMPLEMENTATION(int CCINIClass::Load(Straw&, bool, bool), 0x0044A060);
DEFINE_IMPLEMENTATION(int CCINIClass::Save(FileClass&, bool) const, 0x0044A170);
DEFINE_IMPLEMENTATION(int CCINIClass::Save(Pipe&, bool) const, 0x0044A280);
DEFINE_IMPLEMENTATION(LEPTON CCINIClass::Get_Lepton(const char*, const char*, const LEPTON), 0x0044A360);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_Lepton(const char*, const char*, LEPTON), 0x0044A3A0);
DEFINE_IMPLEMENTATION(unsigned CCINIClass::Get_Degree(const char*, const char*, unsigned) const, 0x0044A420);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_Degree(const char*, const char*, unsigned), 0x0044A3D0);
DEFINE_IMPLEMENTATION(Cell CCINIClass::Get_Cell(const char*, const char*, const Cell&), 0x0044A480);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_Cell(const char*, const char*, Cell&), 0x0044A500);
DEFINE_IMPLEMENTATION(Coord CCINIClass::Get_Coord(const char*, const char*, const Coord&), 0x0044BDE0);
DEFINE_IMPLEMENTATION(MPHType CCINIClass::Get_MPHType(const char*, const char*, const MPHType), 0x0044A550);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_MPHType(const char*, const char*, MPHType), 0x0044A5B0);
DEFINE_IMPLEMENTATION(PipScaleType CCINIClass::Get_PipType(const char*, const char*, const PipType), 0x0044A5E0);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_PipType(const char*, const char*, PipType), 0x0044A650);
DEFINE_IMPLEMENTATION(PipScaleType CCINIClass::Get_PipScaleType(const char*, const char*, const PipScaleType), 0x0044A680);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_PipScaleType(const char*, const char*, PipScaleType), 0x0044A6F0);
DEFINE_IMPLEMENTATION(CategoryType CCINIClass::Get_CategoryType(const char*, const char*, const CategoryType), 0x0044A720);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_CategoryType(const char*, const char*, CategoryType), 0x0044A760);
DEFINE_IMPLEMENTATION(ColorSchemeType CCINIClass::Get_ColorSchemeType(const char*, const char*, const ColorSchemeType), 0x0044A7D0);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_ColorSchemeType(const char*, const char*, ColorSchemeType), 0x0044A860);
DEFINE_IMPLEMENTATION(RGBStruct CCINIClass::Get_RGB(const char*, const char*, const RGBStruct&), 0x0044A890);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_RGB(const char*, const char*, RGBStruct&), 0x0044A960);
DEFINE_IMPLEMENTATION(HSVStruct CCINIClass::Get_HSV(const char*, const char*, const HSVStruct&), 0x0044A9B0);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_HSV(const char*, const char*, RGBStruct&), 0x0044AA90);
DEFINE_IMPLEMENTATION(BSizeType CCINIClass::Get_BSizeType(const char*, const char*, const BSizeType), 0x0044AAE0);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_BSizeType(const char*, const char*, BSizeType), 0x0044AB50);
DEFINE_IMPLEMENTATION(MZoneType CCINIClass::Get_MZoneType(const char*, const char*, const MZoneType), 0x0044AB80);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_MZoneType(const char*, const char*, MZoneType), 0x0044ABF0);
DEFINE_IMPLEMENTATION(ActionType CCINIClass::Get_ActionType(const char*, const char*, const ActionType), 0x0044AC20);
DEFINE_IMPLEMENTATION(SuperWeaponType CCINIClass::Get_SpecialWeaponType(const char*, const char*, const SuperWeaponType), 0x0044AC90);
DEFINE_IMPLEMENTATION(VoxType CCINIClass::Get_VoxType(const char*, const char*, const VoxType), 0x0044ACE0);
DEFINE_IMPLEMENTATION(RTTIType CCINIClass::Get_RTTIType(const char*, const char*, const RTTIType), 0x0044AD50);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_RTTIType(const char*, const char*, RTTIType), 0x0044AD90);
DEFINE_IMPLEMENTATION(long CCINIClass::Get_Owners(const char*, const char*, const long), 0x0044ADC0);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_Owners(const char*, const char*, long), 0x0044AE40);
DEFINE_IMPLEMENTATION(ArmorType CCINIClass::Get_ArmorType(const char*, const char*, const ArmorType), 0x0044AF50);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_ArmorType(const char*, const char*, ArmorType), 0x0044AFA0);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_VocType(const char*, const char*, VocType), 0x0044AFC0);
DEFINE_IMPLEMENTATION(LandType CCINIClass::Get_LandType(const char*, const char*, const LandType), 0x0044B010);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_LandType(const char*, const char*, LandType), 0x0044B070);
DEFINE_IMPLEMENTATION(HousesType CCINIClass::Get_HousesType(const char*, const char*, const HousesType), 0x0044B0A0);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_HousesType(const char*, const char*, HousesType), 0x0044B150);
DEFINE_IMPLEMENTATION(SideType CCINIClass::Get_SideType(const char*, const char*, const SideType), 0x0044B180);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_SideType(const char*, const char*, SideType), 0x0044B240);
DEFINE_IMPLEMENTATION(VQType CCINIClass::Get_VQType(const char*, const char*, const VQType), 0x0044B270);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_VQType(const char*, const char*, VQType), 0x0044B2C0);
DEFINE_IMPLEMENTATION(TheaterType CCINIClass::Get_TheaterType(const char*, const char*, const TheaterType), 0x0044B310);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_TheaterType(const char*, const char*, TheaterType), 0x0044B360);
DEFINE_IMPLEMENTATION(ThemeType CCINIClass::Get_ThemeType(const char*, const char*, const ThemeType), 0x0044B390);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_ThemeType(const char*, const char*, ThemeType), 0x0044B3F0);
DEFINE_IMPLEMENTATION(SourceType CCINIClass::Get_SourceType(const char*, const char*, const SourceType), 0x0044B420);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_SourceType(const char*, const char*, SourceType), 0x0044B470);
DEFINE_IMPLEMENTATION(CrateType CCINIClass::Get_CrateType(const char*, const char*, const CrateType), 0x0044B490);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_CrateType(const char*, const char*, CrateType), 0x0044B4E0);
DEFINE_IMPLEMENTATION(SpeedType CCINIClass::Get_SpeedType(const char*, const char*, const SpeedType), 0x0044CAA0);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_SpeedType(const char*, const char*, SpeedType), 0x0044CB00);
DEFINE_IMPLEMENTATION(AbilitiesStruct CCINIClass::Get_Ability(const char*, const char*, const AbilitiesStruct&), 0x0044CEF0);
DEFINE_IMPLEMENTATION(TypeList<RGBStruct> CCINIClass::Get_RGBs(const char*, const char*, const TypeList<RGBStruct>), 0x0044C5C0);
DEFINE_IMPLEMENTATION(TypeList<int> CCINIClass::Get_Integers(const char*, const char*, const TypeList<int>), 0x0044B810);
DEFINE_IMPLEMENTATION(TypeList<TechnoTypeClass*> CCINIClass::Get_TechnoTypes(const char*, const char*, const TypeList<TechnoTypeClass*>), 0x0044BF90);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_TechnoTypes(const char*, const char*, const TypeList<TechnoTypeClass*>), 0x0044C190);
DEFINE_IMPLEMENTATION(TypeList<SideType> CCINIClass::Get_SideTypes(const char*, const char*, const TypeList<SideType>), 0x0044C260);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_HousesTypes(const char*, const char*, const TypeList<SideType>), 0x0044C4C0);
// DEFINE_IMPLEMENTATION(TypeList<VocType> CCINIClass::Get_VocTypes(const char *, const char *, const TypeList<VocType>), 0x004DB290);
DEFINE_IMPLEMENTATION(xTargetClass CCINIClass::Get_Target(const char*, const char*, const xTargetClass&), 0x0044C950);
DEFINE_IMPLEMENTATION(bool CCINIClass::Put_Target(const char*, const char*, xTargetClass&), 0x0044CA50);
DEFINE_IMPLEMENTATION(int CCINIClass::Get_Unique_ID() const, 0x0044C820);
DEFINE_IMPLEMENTATION(void CCINIClass::Calculate_Message_Digest(), 0x0044C8C0);
DEFINE_IMPLEMENTATION(void CCINIClass::Invalidate_Message_Digest(), 0x0044C940);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE ObjectTypeClass::GetSizeMax(ULARGE_INTEGER*), 0x00588FC0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE ObjectTypeClass::Load(IStream*), 0x00588DD0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE ObjectTypeClass::Save(IStream*, BOOL), 0x00588FA0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(ObjectTypeClass::ObjectTypeClass(const char *), AbstractTypeClass, 0x00587620);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(ObjectTypeClass::ObjectTypeClass(const NoInitClass &), AbstractTypeClass, 0x00587810);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(ObjectTypeClass::~ObjectTypeClass(), 0x005878B0);
DEFINE_IMPLEMENTATION(bool ObjectTypeClass::Read_INI(CCINIClass&), 0x00588A20);
DEFINE_IMPLEMENTATION(Coord ObjectTypeClass::Coord_Fixup(Coord*) const, 0x00410180);
DEFINE_IMPLEMENTATION(int ObjectTypeClass::Get_Ownable() const, 0x00419B90);
DEFINE_IMPLEMENTATION(int ObjectTypeClass::Max_Pips() const, 0x005879E0);
DEFINE_IMPLEMENTATION(Point3D ObjectTypeClass::Pixel_Dimensions() const, 0x005879F0);
DEFINE_IMPLEMENTATION(Point3D ObjectTypeClass::Lepton_Dimensions() const, 0x00587A10);
DEFINE_IMPLEMENTATION(int ObjectTypeClass::Cost_Of(HouseClass*) const, 0x00587A40);
DEFINE_IMPLEMENTATION(int ObjectTypeClass::Time_To_Build() const, 0x00587A50);
DEFINE_IMPLEMENTATION(Cell* ObjectTypeClass::Occupy_List(bool) const, 0x00587A70);
DEFINE_IMPLEMENTATION(BuildingClass* const ObjectTypeClass::Who_Can_Build_Me(bool, bool, bool, HouseClass*) const, 0x00587B20);
DEFINE_IMPLEMENTATION(ShapeSet* const ObjectTypeClass::Get_Cameo_Data() const, 0x00587A60);
DEFINE_IMPLEMENTATION(ShapeSet* const ObjectTypeClass::Get_Image_Data() const, 0x004101A0);
DEFINE_IMPLEMENTATION(void ObjectTypeClass::Theater_Naming_Convention(char*, TheaterType), 0x00588D00);
DEFINE_IMPLEMENTATION(void ObjectTypeClass::Fetch_Normal_Image(), 0x005888B0);
DEFINE_IMPLEMENTATION(const ObjectTypeClass* ObjectTypeClass::From_Name(const char*), 0x00588FE0);
DEFINE_IMPLEMENTATION(void ObjectTypeClass::Clear_Voxel_Indexes(), 0x00589030);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE TechnoTypeClass::GetSizeMax(ULARGE_INTEGER*), 0x0063E170);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TechnoTypeClass::Load(IStream*), 0x0063D8F0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TechnoTypeClass::Save(IStream*, BOOL), 0x0063DF00);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(TechnoTypeClass::TechnoTypeClass(const char *, SpeedType), ObjectTypeClass, 0x0063ADE0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(TechnoTypeClass::TechnoTypeClass(const NoInitClass &), ObjectTypeClass, 0x0063B480);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(TechnoTypeClass::~TechnoTypeClass(), 0x0063B5F0);
DEFINE_IMPLEMENTATION(int TechnoTypeClass::Get_Object_Size_Delta() const, 0x004101B0);
DEFINE_IMPLEMENTATION(void TechnoTypeClass::Object_CRC(CRCEngine&) const, 0x0063E210);
DEFINE_IMPLEMENTATION(bool TechnoTypeClass::Read_INI(CCINIClass&), 0x0063B9B0);
DEFINE_IMPLEMENTATION(int TechnoTypeClass::Get_Ownable() const, 0x0063B890);
DEFINE_IMPLEMENTATION(int TechnoTypeClass::Max_Pips() const, 0x0063D460);
DEFINE_IMPLEMENTATION(int TechnoTypeClass::Cost_Of(HouseClass*) const, 0x0063B8D0);
DEFINE_IMPLEMENTATION(int TechnoTypeClass::Time_To_Build() const, 0x0063B8B0);
DEFINE_IMPLEMENTATION(ShapeSet* const TechnoTypeClass::Get_Cameo_Data() const, 0x0063B910);
DEFINE_IMPLEMENTATION(bool TechnoTypeClass::Legal_Placement(Cell&, HouseClass*) const, 0x0063D320);
DEFINE_IMPLEMENTATION(int TechnoTypeClass::Raw_Cost() const, 0x0063B880);
DEFINE_IMPLEMENTATION(int TechnoTypeClass::Repair_Cost() const, 0x0063B920);
DEFINE_IMPLEMENTATION(int TechnoTypeClass::Repair_Step() const, 0x0063B970);
DEFINE_IMPLEMENTATION(int TechnoTypeClass::Flight_Level() const, 0x0063E700);
DEFINE_IMPLEMENTATION(bool TechnoTypeClass::Is_Two_Shooter() const, 0x0063B980);
DEFINE_IMPLEMENTATION(const WeaponInfoStruct& TechnoTypeClass::Fetch_Weapon_Info(WeaponSlotType) const, 0x0063E6B0);
DEFINE_IMPLEMENTATION(bool TechnoTypeClass::In_Range(Coord&, AbstractClass*, WeaponTypeClass*), 0x0063D4C0);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE SwizzleManagerClass::QueryInterface(REFIID, LPVOID*), 0x0060DC60);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE SwizzleManagerClass::AddRef(), 0x0060DCE0);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE SwizzleManagerClass::Release(), 0x0060DCF0);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE SwizzleManagerClass::Reset(), 0x0060DA60);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE SwizzleManagerClass::Swizzle(void**), 0x0060DA70);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE SwizzleManagerClass::Fetch_Swizzle_ID(void*, LONG*), 0x0060DCC0);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE SwizzleManagerClass::Here_I_Am(LONG, void*), 0x0060DAF0);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE SwizzleManagerClass::Save_Interface(IStream*, IUnknown*), 0x0060DD00);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE SwizzleManagerClass::Load_Interface(IStream*, CLSID*, void**), 0x0060DD10);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE SwizzleManagerClass::Get_Save_Size(LONG*), 0x0060DC40);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(SwizzleManagerClass::SwizzleManagerClass(), 0x0060D9B0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(SwizzleManagerClass::~SwizzleManagerClass(), 0x0060DA00);
DEFINE_IMPLEMENTATION(void SwizzleManagerClass::Process_Tables(), 0x0060DB80);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE BuildingTypeClass::GetClassID(CLSID*), 0x004434F0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE BuildingTypeClass::Load(IStream*), 0x00443350);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE BuildingTypeClass::Save(IStream*, BOOL), 0x004434D0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(BuildingTypeClass::BuildingTypeClass(const char *), TechnoTypeClass, 0x0043F410);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(BuildingTypeClass::BuildingTypeClass(const NoInitClass &), TechnoTypeClass, 0x0043F8C0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(BuildingTypeClass::~BuildingTypeClass(), 0x0043F8F0);
DEFINE_IMPLEMENTATION(RTTIType BuildingTypeClass::Fetch_RTTI() const, 0x00443FC0);
DEFINE_IMPLEMENTATION(int BuildingTypeClass::Get_Object_Size(bool) const, 0x00443FD0);
DEFINE_IMPLEMENTATION(int BuildingTypeClass::Get_Object_Size_Delta() const, 0x00444000);
DEFINE_IMPLEMENTATION(void BuildingTypeClass::Object_CRC(CRCEngine&) const, 0x00442F20);
DEFINE_IMPLEMENTATION(int BuildingTypeClass::Fetch_Heap_ID() const, 0x00444010);
DEFINE_IMPLEMENTATION(bool BuildingTypeClass::Read_INI(CCINIClass&), 0x00440AD0);
DEFINE_IMPLEMENTATION(Coord BuildingTypeClass::Coord_Fixup(Coord*) const, 0x00442E50);
DEFINE_IMPLEMENTATION(int BuildingTypeClass::Max_Pips() const, 0x0043FF90);
DEFINE_IMPLEMENTATION(Point3D BuildingTypeClass::Pixel_Dimensions() const, 0x0043FE50);
DEFINE_IMPLEMENTATION(Point3D BuildingTypeClass::Lepton_Dimensions() const, 0x00442ED0);
DEFINE_IMPLEMENTATION(bool BuildingTypeClass::Create_And_Place(Cell&, HouseClass*) const, 0x0043FA60);
DEFINE_IMPLEMENTATION(int BuildingTypeClass::Cost_Of(HouseClass*) const, 0x00440080);
DEFINE_IMPLEMENTATION(ObjectClass* const BuildingTypeClass::Create_One_Of(HouseClass*) const, 0x0043FAE0);
DEFINE_IMPLEMENTATION(Cell* BuildingTypeClass::Occupy_List(bool) const, 0x0043FED0);
DEFINE_IMPLEMENTATION(ShapeSet* const BuildingTypeClass::Get_Image_Data() const, 0x004402F0);
DEFINE_IMPLEMENTATION(bool BuildingTypeClass::Legal_Placement(Cell&, HouseClass*) const, 0x00442EA0);
DEFINE_IMPLEMENTATION(int BuildingTypeClass::Raw_Cost() const, 0x00440000);
DEFINE_IMPLEMENTATION(ShapeSet* const BuildingTypeClass::Get_Buildup_Data(), 0x00443BC0);
DEFINE_IMPLEMENTATION(int BuildingTypeClass::Width() const, 0x0043FF40);
DEFINE_IMPLEMENTATION(int BuildingTypeClass::Height(bool) const, 0x0043FF50);
DEFINE_IMPLEMENTATION(void BuildingTypeClass::Init_Anim(BStateType, int, int, int) const, 0x0043FB10);
DEFINE_IMPLEMENTATION(void BuildingTypeClass::Set_Base_Defense_Values(), 0x00443D20);
DEFINE_IMPLEMENTATION(bool BuildingTypeClass::Is_Deployable(), 0x00443EC0);
DEFINE_IMPLEMENTATION(void BuildingTypeClass::Fetch_Building_Normal_Image(TheaterType theater), 0x00440370);
DEFINE_IMPLEMENTATION(void BuildingTypeClass::Fetch_Building_Voxel_Image(), 0x00440720);
DEFINE_IMPLEMENTATION(int BuildingTypeClass::Flush_For_Placement(Cell&, HouseClass*) const, 0x00440120);
DEFINE_IMPLEMENTATION(void BuildingTypeClass::One_Time(), 0x0043F9B0);
DEFINE_IMPLEMENTATION(void BuildingTypeClass::Init(TheaterType), 0x0043FC40);
DEFINE_IMPLEMENTATION(void BuildingTypeClass::Fetch_ToTile_Types(), 0x00443E30);

RGBClass::RGBClass() : Red(0), Green(0), Blue(0) {}
RGBClass::RGBClass(const RGBStruct& that) : Red(that.R), Green(that.G), Blue(that.B) {}
RGBClass::RGBClass(const RGBClass& that) : Red(that.Red), Green(that.Green), Blue(that.Blue) {}
RGBClass::RGBClass(unsigned char red, unsigned char green, unsigned char blue) : Red(red), Green(green), Blue(blue) {}
DEFINE_IMPLEMENTATION(RGBClass::operator HSVClass() const, 0x005C32E0);
DEFINE_IMPLEMENTATION(void RGBClass::Adjust(int, const RGBClass&), 0x005C3200);
DEFINE_IMPLEMENTATION(int RGBClass::Difference(const RGBClass&) const, 0x005C3290);
DEFINE_IMPLEMENTATION(RGBClass RGBClass::Adjust_Brightness(RGBClass&, float), 0x005C30D0);
DEFINE_IMPLEMENTATION(RGBClass RGBClass::Lerp(RGBClass&, RGBClass&, float), 0x005C2F60);

HSVClass::HSVClass() : Hue(0), Saturation(0), Value(0) {}
HSVClass::HSVClass(const HSVStruct& that) : Hue(that.H), Saturation(that.S), Value(that.V) {}
HSVClass::HSVClass(const HSVClass& that) : Hue(that.Hue), Saturation(that.Saturation), Value(that.Value) {}
HSVClass::HSVClass(unsigned char hue, unsigned char saturation, unsigned char value) : Hue(hue), Saturation(saturation), Value(value) {}
DEFINE_IMPLEMENTATION(HSVClass::operator RGBClass() const, 0x004D1C60);
DEFINE_IMPLEMENTATION(void HSVClass::Adjust(int, const HSVClass&), 0x004D1B80);
DEFINE_IMPLEMENTATION(int HSVClass::Difference(const HSVClass&) const, 0x004D1C10);

PaletteClass::PaletteClass() : Palette() {}
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(PaletteClass::PaletteClass(const RGBClass &), 0x005A2810);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(PaletteClass::PaletteClass(const PaletteClass &), 0x005A2860);
PaletteClass::PaletteClass(const char* filename) : Palette()
{
    std::memcpy(this, (void*)MFCD::Retrieve(filename), sizeof(*this));
    for (int i = 0; i < COLOR_COUNT; ++i) {
        Palette[i].Red *= 4;
        Palette[i].Green *= 4;
        Palette[i].Blue *= 4;
    }
}
PaletteClass::~PaletteClass() {}
DEFINE_IMPLEMENTATION(void PaletteClass::Adjust(int), 0x005A28E0);
DEFINE_IMPLEMENTATION(void PaletteClass::Adjust(int, const PaletteClass&), 0x005A2910);
DEFINE_IMPLEMENTATION(void PaletteClass::Partial_Adjust(int, char*), 0x005A2960);
DEFINE_IMPLEMENTATION(void PaletteClass::Partial_Adjust(int, const PaletteClass&, char*), 0x005A29A0);
DEFINE_IMPLEMENTATION(int PaletteClass::Closest_Color(RGBClass&) const, 0x005A29F0);

ConvertClass::ConvertClass() {}
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(ConvertClass::ConvertClass(PaletteClass *, PaletteClass *, XSurface *, int, bool), 0x00463C40);
ConvertClass::ConvertClass(const NoInitClass& noinit) { *((unsigned long*)this) = (unsigned long)0x006CD268; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(ConvertClass::~ConvertClass(), 0x00465970);
DEFINE_IMPLEMENTATION(void ConvertClass::Create_Blitters(), 0x00464100);
DEFINE_IMPLEMENTATION(void ConvertClass::Destroy_Blitters(), 0x00465A00);
DEFINE_IMPLEMENTATION(Blitter* ConvertClass::Blitter_From_Flags(int), 0x00466130);
DEFINE_IMPLEMENTATION(RLEBlitter* ConvertClass::RLEBlitter_From_Flags(int), 0x00466410);
DEFINE_IMPLEMENTATION(void ConvertClass::Recalc_Color_Remap_Tables(int, int, int, int), 0x004666C0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(LightConvertClass::LightConvertClass(PaletteClass *, PaletteClass *, Surface *, int, int, int, bool, bool *, int), ConvertClass, 0x00502A00);
LightConvertClass::LightConvertClass(const NoInitClass& noinit) { *((unsigned long*)this) = (unsigned long)0x006D3954; }
LightConvertClass::~LightConvertClass() {}
DEFINE_IMPLEMENTATION(void LightConvertClass::Apply_Tint(int, int, int, bool), 0x00502B90);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE IsometricTileTypeClass::GetClassID(CLSID*), 0x004F86B0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE IsometricTileTypeClass::Load(IStream*), 0x004F85B0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE IsometricTileTypeClass::Save(IStream*, BOOL), 0x004F8690);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(IsometricTileTypeClass::IsometricTileTypeClass(IsometricTileType, char, char, const char *, bool), ObjectTypeClass, 0x004F30A0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(IsometricTileTypeClass::IsometricTileTypeClass(const NoInitClass &), ObjectTypeClass, 0x004F32D0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(IsometricTileTypeClass::~IsometricTileTypeClass(), 0x004F3330);
DEFINE_IMPLEMENTATION(void IsometricTileTypeClass::Detach(AbstractClass*, bool), 0x004F86F0);
DEFINE_IMPLEMENTATION(RTTIType IsometricTileTypeClass::Fetch_RTTI() const, 0x004F8A90);
DEFINE_IMPLEMENTATION(int IsometricTileTypeClass::Get_Object_Size(bool) const, 0x004F8AA0);
DEFINE_IMPLEMENTATION(void IsometricTileTypeClass::Object_CRC(CRCEngine&) const, 0x004F84A0);
DEFINE_IMPLEMENTATION(int IsometricTileTypeClass::Fetch_Heap_ID() const, 0x004F8AB0);
DEFINE_IMPLEMENTATION(Coord IsometricTileTypeClass::Coord_Fixup(Coord*) const, 0x004F8480);
DEFINE_IMPLEMENTATION(bool IsometricTileTypeClass::Create_And_Place(Cell&, HouseClass*) const, 0x004F83D0);
DEFINE_IMPLEMENTATION(ObjectClass* const IsometricTileTypeClass::Create_One_Of(HouseClass*) const, 0x004F8410);
DEFINE_IMPLEMENTATION(Cell* IsometricTileTypeClass::Occupy_List(bool) const, 0x004F35E0);
DEFINE_IMPLEMENTATION(ShapeSet* const IsometricTileTypeClass::Get_Image_Data() const, 0x004F3570);
DEFINE_IMPLEMENTATION(void IsometricTileTypeClass::Load_Image_Data(), 0x004F5940);

CommandClass::CommandClass() { *((unsigned long*)this) = (unsigned long)0x006D2AF4; }
CommandClass::~CommandClass() {}

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(ToolTipManager::ToolTipManager(HWND), 0x00647190);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(ToolTipManager::~ToolTipManager(), 0x00647240);
DEFINE_IMPLEMENTATION(bool ToolTipManager::Update(const ToolTipText*), 0x00647B60);
DEFINE_IMPLEMENTATION(void ToolTipManager::Reset(const ToolTipText*), 0x00647B70);
DEFINE_IMPLEMENTATION(void ToolTipManager::Force_Redraw(bool), 0x00647C40);
DEFINE_IMPLEMENTATION(void ToolTipManager::Draw(const ToolTipText*), 0x00647C70);
DEFINE_IMPLEMENTATION(const char* ToolTipManager::ToolTip_Text(int), 0x00647C90);
DEFINE_IMPLEMENTATION(void ToolTipManager::Set_Active(bool), 0x00647330);
DEFINE_IMPLEMENTATION(void ToolTipManager::Message_Handler(MSG*), 0x00647390);
DEFINE_IMPLEMENTATION(int ToolTipManager::Get_Timer_Delay() const, 0x006475F0);
DEFINE_IMPLEMENTATION(void ToolTipManager::Set_Timer_Delay(int), 0x00647600);
DEFINE_IMPLEMENTATION(int ToolTipManager::Get_Lifetime() const, 0x00647610);
DEFINE_IMPLEMENTATION(void ToolTipManager::Set_Lifetime(int), 0x00647620);
DEFINE_IMPLEMENTATION(bool ToolTipManager::Find(int id, ToolTip*), 0x00647980);
DEFINE_IMPLEMENTATION(bool ToolTipManager::Add(const ToolTip*), 0x00647640);
DEFINE_IMPLEMENTATION(void ToolTipManager::Remove(int), 0x006477F0);
DEFINE_IMPLEMENTATION(int ToolTipManager::Get_Count() const, 0x00647630);
DEFINE_IMPLEMENTATION(ToolTip* ToolTipManager::Find_From_Pos(Point2D&), 0x00647AF0);
DEFINE_IMPLEMENTATION(bool ToolTipManager::Process(), 0x00647B90);

CCToolTip::CCToolTip(HWND hWnd) : ToolTipManager(hWnd), DrawOnSidebar(false), Style(TPF_MAP) { Set_Timer_Delay(500); *((unsigned long*)this) = (unsigned long)0x006D9E4C; }
CCToolTip::~CCToolTip() {}
DEFINE_IMPLEMENTATION(bool CCToolTip::Update(const ToolTipText*), 0x0044E3B0);
DEFINE_IMPLEMENTATION(void CCToolTip::Reset(const ToolTipText*), 0x0044E530);
DEFINE_IMPLEMENTATION(void CCToolTip::Force_Redraw(bool), 0x0044E590);
DEFINE_IMPLEMENTATION(void CCToolTip::Draw(const ToolTipText*), 0x0044E5B0);
DEFINE_IMPLEMENTATION(const char* CCToolTip::ToolTip_Text(int), 0x0044E720);

DEFINE_IMPLEMENTATION(int Read_Line(FileClass&, char*, int, bool&), 0x005BECA0);
DEFINE_IMPLEMENTATION(int Read_Line(Straw&, char*, int, bool&), 0x005BED50);

DEFINE_IMPLEMENTATION(Surface* Read_PCX_File(FileClass*, unsigned char*, void*, long), 0x005A79A0);
DEFINE_IMPLEMENTATION(bool Write_PCX_File(FileClass*, Surface&, unsigned char*), 0x0069FAE0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(VersionClass::VersionClass(), 0x00663B30);
VersionClass::~VersionClass() {}
DEFINE_IMPLEMENTATION(unsigned long VersionClass::Version_Number(), 0x00663B60);
DEFINE_IMPLEMENTATION(unsigned short VersionClass::Major_Version(), 0x00663D60);
DEFINE_IMPLEMENTATION(unsigned short VersionClass::Minor_Version(), 0x00663E20);
DEFINE_IMPLEMENTATION(const char* VersionClass::Version_Name(), 0x00663ED0);
DEFINE_IMPLEMENTATION(CommProtocolType VersionClass::Version_Protocol(unsigned long), 0x00664130);
DEFINE_IMPLEMENTATION(void VersionClass::Init_Clipping(), 0x00664160);
DEFINE_IMPLEMENTATION(unsigned long VersionClass::Clip_Version(unsigned long, unsigned long), 0x00664170);
DEFINE_IMPLEMENTATION(unsigned long VersionClass::Min_Version(), 0x006641B0);
DEFINE_IMPLEMENTATION(unsigned long VersionClass::Max_Version(), 0x006641C0);

DEFINE_IMPLEMENTATION(int RLEClass::Compress(void*, void*, int), 0x005C3490);
DEFINE_IMPLEMENTATION(int RLEClass::Uncompress(void*, void*), 0x005C3540);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(CDControlClass::CDControlClass(), 0x0044ED90);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(CDControlClass::~CDControlClass(), 0x0044EDB0);
DEFINE_IMPLEMENTATION(bool CDControlClass::Eject_CD_Drive(UINT), 0x0044EDC0);
DEFINE_IMPLEMENTATION(bool CDControlClass::Lock_CD_Drive(UINT), 0x0044EF80);
DEFINE_IMPLEMENTATION(bool CDControlClass::Unlock_CD_Drive(UINT), 0x0044F150);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(WWFontClass::WWFontClass(const void *, bool, int), 0x006A43D0);
WWFontClass::~WWFontClass() {}
DEFINE_IMPLEMENTATION(int WWFontClass::Char_Pixel_Width(char) const, 0x006A4480);
DEFINE_IMPLEMENTATION(int WWFontClass::String_Pixel_Width(const char*) const, 0x006A44C0);
DEFINE_IMPLEMENTATION(void WWFontClass::String_Pixel_Rect(const char*, Rect*) const, 0x006A4520);
DEFINE_IMPLEMENTATION(int WWFontClass::Get_Char_Width() const, 0x006A45F0);
DEFINE_IMPLEMENTATION(int WWFontClass::Get_Char_Height() const, 0x006A4620);
DEFINE_IMPLEMENTATION(Point2D WWFontClass::Print(const char*, Surface*, Rect*, Point2D*, ConvertClass*, unsigned char[]), 0x006A46F0);
DEFINE_IMPLEMENTATION(int WWFontClass::Set_X_Spacing(int), 0x006A4650);
DEFINE_IMPLEMENTATION(int WWFontClass::Set_Y_Spacing(int), 0x006A46A0);
DEFINE_IMPLEMENTATION(WWFontClass* Font_Ptr(TextPrintType), 0x00474D30);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(UnitTrackerClass::UnitTrackerClass(int), 0x0065D5B0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(UnitTrackerClass::~UnitTrackerClass(), 0x0065D600);
DEFINE_IMPLEMENTATION(void UnitTrackerClass::Increment_Unit_Total(int), 0x0065D610);
DEFINE_IMPLEMENTATION(void UnitTrackerClass::Decrement_Unit_Total(int), 0x0065D630);
DEFINE_IMPLEMENTATION(void UnitTrackerClass::Clear_Unit_Total(), 0x0065D660);
DEFINE_IMPLEMENTATION(long* UnitTrackerClass::Get_All_Totals(), 0x0065D650);
DEFINE_IMPLEMENTATION(void UnitTrackerClass::To_Network_Format(), 0x0065D680);
DEFINE_IMPLEMENTATION(void UnitTrackerClass::To_PC_Format(), 0x0065D6C0);

DEFINE_IMPLEMENTATION(uint32_t BuildInfoClass::Original_Get_Build_Number(), 0x006860B0);
DEFINE_IMPLEMENTATION(const char* BuildInfoClass::Original_Get_Build_Number_String(char*, unsigned), 0x00686090);
DEFINE_IMPLEMENTATION(const char* BuildInfoClass::Original_Get_Builder_Name_String(char*, unsigned), 0x006860C0);
DEFINE_IMPLEMENTATION(const char* BuildInfoClass::Original_Get_Build_Date_String(char*, unsigned), 0x00686020);
DEFINE_IMPLEMENTATION(const char* BuildInfoClass::Original_Get_Builder_Initials(char*), 0x006860E0);
DEFINE_IMPLEMENTATION(const char* BuildInfoClass::Original_Get_Build_Version_String(char*, unsigned), 0x00686110);

LinkClass::LinkClass() : Next(nullptr), Prev(nullptr) { *((unsigned long*)this) = (unsigned long)0x006D0874; }
LinkClass::LinkClass(const NoInitClass&) {}
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(LinkClass::LinkClass(const LinkClass &), 0x00503050);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(LinkClass::~LinkClass(), 0x00503090);
DEFINE_IMPLEMENTATION(LinkClass& LinkClass::operator=(const LinkClass&), 0x005030F0);
DEFINE_IMPLEMENTATION(LinkClass* LinkClass::Get_Next() const, 0x00503110);
DEFINE_IMPLEMENTATION(LinkClass* LinkClass::Get_Prev() const, 0x00503120);
DEFINE_IMPLEMENTATION(LinkClass& LinkClass::Add(LinkClass&), 0x00503190);
DEFINE_IMPLEMENTATION(LinkClass& LinkClass::Add_Tail(LinkClass&), 0x005031D0);
DEFINE_IMPLEMENTATION(LinkClass& LinkClass::Add_Head(LinkClass&), 0x005031B0);
DEFINE_IMPLEMENTATION(LinkClass& LinkClass::Head_Of_List(), 0x00503130);
DEFINE_IMPLEMENTATION(LinkClass& LinkClass::Tail_Of_List(), 0x00503160);
DEFINE_IMPLEMENTATION(void LinkClass::Zap(), 0x005030E0);
DEFINE_IMPLEMENTATION(LinkClass* LinkClass::Remove(), 0x00503200);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(CounterClass::CounterClass(), 0x0046E9F0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(CounterClass::~CounterClass(), 0x0046EA10);
DEFINE_IMPLEMENTATION(void CounterClass::Clear(), 0x0046EB60);
DEFINE_IMPLEMENTATION(int CounterClass::Increment(int), 0x0046EA40);
DEFINE_IMPLEMENTATION(int CounterClass::Decrement(int), 0x0046EAA0);
DEFINE_IMPLEMENTATION(bool CounterClass::Grow(int), 0x0046EC90);
DEFINE_IMPLEMENTATION(int CounterClass::Value(int) const, 0x0046EB00);
DEFINE_IMPLEMENTATION(int CounterClass::Total() const, 0x0046EB80);
DEFINE_IMPLEMENTATION(HRESULT CounterClass::Load(IStream*), 0x0046EC00);
DEFINE_IMPLEMENTATION(HRESULT CounterClass::Save(IStream*), 0x0046EBA0);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE HouseTypeClass::QueryInterface(REFIID, LPVOID*), 0x004CE430);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE HouseTypeClass::AddRef(), 0x004CE5D0);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE HouseTypeClass::Release(), 0x004CE5E0);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE HouseTypeClass::GetClassID(CLSID*), 0x004CE4D0);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE HouseTypeClass::IsDirty(), 0x004CE310);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE HouseTypeClass::Load(IStream*), 0x004CE320);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE HouseTypeClass::Save(IStream*, BOOL), 0x004CE3A0);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE HouseTypeClass::GetSizeMax(ULARGE_INTEGER*), 0x004CE400);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(HouseTypeClass::HouseTypeClass(const char *), AbstractTypeClass, 0x004CDD10);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(HouseTypeClass::HouseTypeClass(const NoInitClass &), AbstractTypeClass, 0x004CDE60);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(HouseTypeClass::~HouseTypeClass(), 0x004CDE80);
DEFINE_IMPLEMENTATION(RTTIType HouseTypeClass::Fetch_RTTI() const, 0x004CE5A0);
DEFINE_IMPLEMENTATION(int HouseTypeClass::Get_Object_Size(bool) const, 0x004CE5B0);
DEFINE_IMPLEMENTATION(void HouseTypeClass::Object_CRC(CRCEngine&) const, 0x004CE210);
DEFINE_IMPLEMENTATION(int HouseTypeClass::Fetch_Heap_ID() const, 0x004CE5C0);
DEFINE_IMPLEMENTATION(bool HouseTypeClass::Read_INI(CCINIClass&), 0x004CDF50);

DEFINE_IMPLEMENTATION(void Detach_This_From_All(AbstractClass*, bool), 0x006489B0);
DEFINE_IMPLEMENTATION(void Remove_All_Inactive(), 0x00648CD0);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE UnitTypeClass::GetClassID(CLSID*), 0x0065C430);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE UnitTypeClass::Load(IStream*), 0x0065C510);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE UnitTypeClass::Save(IStream*, BOOL), 0x0065C670);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(UnitTypeClass::UnitTypeClass(const char *), TechnoTypeClass, 0x0065B8F0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(UnitTypeClass::UnitTypeClass(const NoInitClass &), TechnoTypeClass, 0x0065BAA0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(UnitTypeClass::~UnitTypeClass(), 0x0065BAC0);
DEFINE_IMPLEMENTATION(RTTIType UnitTypeClass::Fetch_RTTI() const, 0x0065C760);
DEFINE_IMPLEMENTATION(int UnitTypeClass::Get_Object_Size(bool) const, 0x0065C720);
DEFINE_IMPLEMENTATION(int UnitTypeClass::Get_Object_Size_Delta() const, 0x0065C750);
DEFINE_IMPLEMENTATION(void UnitTypeClass::Object_CRC(CRCEngine&) const, 0x0065C470);
DEFINE_IMPLEMENTATION(int UnitTypeClass::Fetch_Heap_ID() const, 0x0065C770);
DEFINE_IMPLEMENTATION(bool UnitTypeClass::Read_INI(CCINIClass&), 0x0065BDD0);
DEFINE_IMPLEMENTATION(Coord UnitTypeClass::Coord_Fixup(Coord*) const, 0x0065C3B0);
DEFINE_IMPLEMENTATION(Point3D UnitTypeClass::Pixel_Dimensions() const, 0x0065BD30);
DEFINE_IMPLEMENTATION(Point3D UnitTypeClass::Lepton_Dimensions() const, 0x0065BD70);
DEFINE_IMPLEMENTATION(bool UnitTypeClass::Create_And_Place(Cell&, HouseClass*) const, 0x0065BC50);
DEFINE_IMPLEMENTATION(ObjectClass* const UnitTypeClass::Create_One_Of(HouseClass*) const, 0x0065BD00);
DEFINE_IMPLEMENTATION(int UnitTypeClass::Repair_Step() const, 0x0065C420);
DEFINE_IMPLEMENTATION(const TPoint3D<int> UnitTypeClass::Turret_Adjust(Dir256, TPoint3D<int>&) const, 0x0065BDB0);
DEFINE_IMPLEMENTATION(void UnitTypeClass::One_Time(), 0x0065BB80);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE InfantryTypeClass::GetClassID(CLSID*), 0x004DB000);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE InfantryTypeClass::Load(IStream*), 0x004DAE20);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE InfantryTypeClass::Save(IStream*, BOOL), 0x004DAF70);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(InfantryTypeClass::InfantryTypeClass(const char *), TechnoTypeClass, 0x004DA1E0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(InfantryTypeClass::InfantryTypeClass(const NoInitClass &), TechnoTypeClass, 0x004DA370);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(InfantryTypeClass::~InfantryTypeClass(), 0x004DA3A0);
DEFINE_IMPLEMENTATION(RTTIType InfantryTypeClass::Fetch_RTTI() const, 0x004DB0D0);
DEFINE_IMPLEMENTATION(int InfantryTypeClass::Get_Object_Size(bool) const, 0x004DB0E0);
DEFINE_IMPLEMENTATION(void InfantryTypeClass::Object_CRC(CRCEngine&) const, 0x004DAD10);
DEFINE_IMPLEMENTATION(int InfantryTypeClass::Fetch_Heap_ID() const, 0x004DB110);
DEFINE_IMPLEMENTATION(bool InfantryTypeClass::Read_INI(CCINIClass&), 0x004DA960);
DEFINE_IMPLEMENTATION(Coord InfantryTypeClass::Coord_Fixup(Coord*) const, 0x004DACA0);
DEFINE_IMPLEMENTATION(Point3D InfantryTypeClass::Lepton_Dimensions() const, 0x004DAC50);
DEFINE_IMPLEMENTATION(bool InfantryTypeClass::Create_And_Place(Cell&, HouseClass*) const, 0x004DA490);
DEFINE_IMPLEMENTATION(ObjectClass* const InfantryTypeClass::Create_One_Of(HouseClass*) const, 0x004DA460);
DEFINE_IMPLEMENTATION(Cell* InfantryTypeClass::Occupy_List(bool) const, 0x004DA570);
DEFINE_IMPLEMENTATION(int InfantryTypeClass::Repair_Cost() const, 0x004DAC90);
DEFINE_IMPLEMENTATION(int InfantryTypeClass::Repair_Step() const, 0x004DAC80);
DEFINE_IMPLEMENTATION(void InfantryTypeClass::Sequence_Read_INI(), 0x004DA650);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE AircraftTypeClass::GetClassID(CLSID*), 0x0040FFE0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE AircraftTypeClass::Load(IStream*), 0x0040FF70);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE AircraftTypeClass::Save(IStream*, BOOL), 0x0040FFC0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(AircraftTypeClass::AircraftTypeClass(const char *), TechnoTypeClass, 0x0040FBC0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(AircraftTypeClass::AircraftTypeClass(const NoInitClass &), TechnoTypeClass, 0x0040FCA0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(AircraftTypeClass::~AircraftTypeClass(), 0x0040FCC0);
DEFINE_IMPLEMENTATION(RTTIType AircraftTypeClass::Fetch_RTTI() const, 0x004101C0);
DEFINE_IMPLEMENTATION(int AircraftTypeClass::Get_Object_Size(bool) const, 0x004101D0);
DEFINE_IMPLEMENTATION(void AircraftTypeClass::Object_CRC(CRCEngine&) const, 0x0040FF20);
DEFINE_IMPLEMENTATION(int AircraftTypeClass::Fetch_Heap_ID() const, 0x00410200);
DEFINE_IMPLEMENTATION(bool AircraftTypeClass::Read_INI(CCINIClass&), 0x0040FE80);
DEFINE_IMPLEMENTATION(Point3D AircraftTypeClass::Lepton_Dimensions() const, 0x0040FE50);
DEFINE_IMPLEMENTATION(bool AircraftTypeClass::Create_And_Place(Cell&, HouseClass*) const, 0x0040FE40);
DEFINE_IMPLEMENTATION(ObjectClass* const AircraftTypeClass::Create_One_Of(HouseClass*) const, 0x0040FDA0);
DEFINE_IMPLEMENTATION(Cell* AircraftTypeClass::Occupy_List(bool) const, 0x0040FDD0);

DEFINE_IMPLEMENTATION(int Modify_Damage(int, const WarheadTypeClass*, ArmorType, int), 0x0045EB60);
DEFINE_IMPLEMENTATION(void Chain_Reaction_Damage(const Cell&), 0x0045EC30);
DEFINE_IMPLEMENTATION(void Explosion_Damage(const Coord&, int, TechnoClass*, const WarheadTypeClass*, bool), 0x0045EEB0);
DEFINE_IMPLEMENTATION(const AnimTypeClass* Combat_Anim(int, const WarheadTypeClass*, LandType, const Coord*), 0x00460340);
DEFINE_IMPLEMENTATION(void Combat_Lighting(Coord, int, const WarheadTypeClass*, bool), 0x00460460);
DEFINE_IMPLEMENTATION(void Wide_Area_Damage(const Coord&, LEPTON, int, TechnoClass*, const WarheadTypeClass*), 0x004604D0);
DEFINE_IMPLEMENTATION(int Get_Explosion_Z(Coord), 0x00460B40);

DEFINE_IMPLEMENTATION(bool Save_Game(const char*, const char*, bool), 0x005D4FE0);
DEFINE_IMPLEMENTATION(bool Load_Game(const char*), 0x005D6910);
DEFINE_IMPLEMENTATION(HRESULT Save_Misc_Values(IStream*), 0x005D7910);
DEFINE_IMPLEMENTATION(HRESULT Load_Misc_Values(IStream*), 0x005D7AF0);
DEFINE_IMPLEMENTATION(bool Put_All(IStream*, bool), 0x005D54A0);
DEFINE_IMPLEMENTATION(bool Get_All(IStream*, bool), 0x005D6BE0);
DEFINE_IMPLEMENTATION(void Post_Load_Game(), 0x005DC470);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE VoxelAnimTypeClass::GetClassID(CLSID*), 0x0065FE30);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE VoxelAnimTypeClass::Load(IStream*), 0x0065FE70);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE VoxelAnimTypeClass::Save(IStream*, BOOL), 0x0065FF20);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(VoxelAnimTypeClass::VoxelAnimTypeClass(const char *), ObjectTypeClass, 0x0065F3B0);
VoxelAnimTypeClass::VoxelAnimTypeClass(const NoInitClass& noinit) : ObjectTypeClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D9228; *((unsigned long*)this + 1) = (unsigned long)0x006D920C; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(VoxelAnimTypeClass::~VoxelAnimTypeClass(), 0x0065F590);
DEFINE_IMPLEMENTATION(void VoxelAnimTypeClass::Detach(AbstractClass*, bool), 0x0065FF40);
DEFINE_IMPLEMENTATION(RTTIType VoxelAnimTypeClass::Fetch_RTTI() const, 0x00660040);
DEFINE_IMPLEMENTATION(int VoxelAnimTypeClass::Get_Object_Size(bool) const, 0x00660050);
DEFINE_IMPLEMENTATION(void VoxelAnimTypeClass::Object_CRC(CRCEngine&) const, 0x0065FCE0);
DEFINE_IMPLEMENTATION(bool VoxelAnimTypeClass::Read_INI(CCINIClass&), 0x0065F660);
DEFINE_IMPLEMENTATION(bool VoxelAnimTypeClass::Create_And_Place(Cell&, HouseClass*) const, 0x00660060);
DEFINE_IMPLEMENTATION(ObjectClass* const VoxelAnimTypeClass::Create_One_Of(HouseClass*) const, 0x00660070);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE WeaponTypeClass::GetClassID(CLSID*), 0x00681520);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE WeaponTypeClass::Load(IStream*), 0x00681560);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE WeaponTypeClass::Save(IStream*, BOOL), 0x00681730);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(WeaponTypeClass::WeaponTypeClass(const char *), AbstractTypeClass, 0x00680A60);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(WeaponTypeClass::WeaponTypeClass(const NoInitClass &), AbstractTypeClass, 0x00680C00);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(WeaponTypeClass::~WeaponTypeClass(), 0x00680C40);
DEFINE_IMPLEMENTATION(RTTIType WeaponTypeClass::Fetch_RTTI() const, 0x006818D0);
DEFINE_IMPLEMENTATION(int WeaponTypeClass::Get_Object_Size(bool) const, 0x006818B0);
DEFINE_IMPLEMENTATION(void WeaponTypeClass::Object_CRC(CRCEngine&) const, 0x006813C0);
DEFINE_IMPLEMENTATION(bool WeaponTypeClass::Read_INI(CCINIClass&), 0x00680D30);
DEFINE_IMPLEMENTATION(void WeaponTypeClass::Set_Speed(), 0x006812C0);
DEFINE_IMPLEMENTATION(bool WeaponTypeClass::Is_Wall_Destroyer() const, 0x006813A0);
DEFINE_IMPLEMENTATION(ThreatType WeaponTypeClass::Allowed_Threats() const, 0x00681360);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE BulletTypeClass::GetClassID(CLSID*), 0x004485D0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE BulletTypeClass::Load(IStream*), 0x004484F0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE BulletTypeClass::Save(IStream*, BOOL), 0x004485B0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(BulletTypeClass::BulletTypeClass(const char *), ObjectTypeClass, 0x00447BC0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(BulletTypeClass::BulletTypeClass(const NoInitClass &), ObjectTypeClass, 0x00447D90);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(BulletTypeClass::~BulletTypeClass(), 0x00447DB0);
DEFINE_IMPLEMENTATION(void BulletTypeClass::Detach(AbstractClass*, bool), 0x004486A0);
DEFINE_IMPLEMENTATION(RTTIType BulletTypeClass::Fetch_RTTI() const, 0x004486C0);
DEFINE_IMPLEMENTATION(int BulletTypeClass::Get_Object_Size(bool) const, 0x004486D0);
DEFINE_IMPLEMENTATION(void BulletTypeClass::Object_CRC(CRCEngine&) const, 0x004483B0);
DEFINE_IMPLEMENTATION(bool BulletTypeClass::Read_INI(CCINIClass&), 0x00447E70);
DEFINE_IMPLEMENTATION(Coord BulletTypeClass::Coord_Fixup(Coord*) const, 0x00448340);
DEFINE_IMPLEMENTATION(bool BulletTypeClass::Create_And_Place(Cell&, HouseClass*) const, 0x004486F0);
DEFINE_IMPLEMENTATION(ObjectClass* const BulletTypeClass::Create_One_Of(HouseClass*) const, 0x00448700);

DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE LocomotionClass::QueryInterface(REFIID, LPVOID*), 0x005064E0);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE LocomotionClass::AddRef(), 0x00506480);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE LocomotionClass::Release(), 0x005064A0);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE LocomotionClass::IsDirty(), 0x00482280);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE LocomotionClass::Save(IStream*, BOOL), 0x00506590);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE LocomotionClass::GetSizeMax(ULARGE_INTEGER*), 0x00506660);
LocomotionClass::LocomotionClass() {}
LocomotionClass::LocomotionClass(const NoInitClass&) {}
LocomotionClass::~LocomotionClass() {}
DEFINE_IMPLEMENTATION(HRESULT LocomotionClass::Link_To_Object(void*), 0x00506250);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Is_Moving(), 0x00506800);
DEFINE_IMPLEMENTATION(Coord LocomotionClass::Destination(), 0x00506790);
DEFINE_IMPLEMENTATION(Coord LocomotionClass::Head_To_Coord(), 0x005067C0);
DEFINE_IMPLEMENTATION(MoveType LocomotionClass::Can_Enter_Cell(Cell), 0x00506710);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Is_To_Have_Shadow(), 0x00506700);
DEFINE_IMPLEMENTATION(Matrix3D LocomotionClass::Draw_Matrix(int*), 0x00506260);
DEFINE_IMPLEMENTATION(Matrix3D LocomotionClass::Shadow_Matrix(int*), 0x00506300);
DEFINE_IMPLEMENTATION(Point2D LocomotionClass::Draw_Point(), 0x005066F0);
DEFINE_IMPLEMENTATION(Point2D LocomotionClass::Shadow_Point(), 0x005063F0);
DEFINE_IMPLEMENTATION(VisualType LocomotionClass::Visual_Character(bool), 0x005066E0);
DEFINE_IMPLEMENTATION(int LocomotionClass::Z_Adjust(), 0x005066C0);
DEFINE_IMPLEMENTATION(ZGradientType LocomotionClass::Z_Gradient(), 0x5066D0);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Process(), 0x00506780);
DEFINE_IMPLEMENTATION(void LocomotionClass::Move_To(Coord), 0x00506770);
DEFINE_IMPLEMENTATION(void LocomotionClass::Stop_Moving(), 0x00506760);
DEFINE_IMPLEMENTATION(void LocomotionClass::Do_Turn(DirType), 0x00506750);
DEFINE_IMPLEMENTATION(void LocomotionClass::Unlimbo(), 0x00506740);
DEFINE_IMPLEMENTATION(void LocomotionClass::Tilt_Pitch_AI(), 0x005066B0);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Power_On(), 0x00506420);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Power_Off(), 0x00506440);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Is_Powered(), 0x00506460);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Is_Ion_Sensitive(), 0x00506470);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Push(DirType), 0x00506690);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Shove(DirType), 0x005066A0);
DEFINE_IMPLEMENTATION(void LocomotionClass::Force_Track(int, Coord), 0x00506730);
DEFINE_IMPLEMENTATION(void LocomotionClass::Force_Immediate_Destination(Coord), 0x00506720);
DEFINE_IMPLEMENTATION(void LocomotionClass::Force_New_Slope(TileRampType), 0x00506810);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Is_Moving_Now(), 0x00483C60);
DEFINE_IMPLEMENTATION(int LocomotionClass::Apparent_Speed(), 0x00506840);
DEFINE_IMPLEMENTATION(int LocomotionClass::Drawing_Code(), 0x00506820);
DEFINE_IMPLEMENTATION(FireErrorType LocomotionClass::Can_Fire(), 0x00506830);
DEFINE_IMPLEMENTATION(int LocomotionClass::Get_Status(), 0x004822B0);
DEFINE_IMPLEMENTATION(void LocomotionClass::Acquire_Hunter_Seeker_Target(), 0x004822C0);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Is_Surfacing(), 0x004822D0);
DEFINE_IMPLEMENTATION(void LocomotionClass::Mark_All_Occupation_Bits(MarkType), 0x00483C70);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Is_Moving_Here(Coord), 0x00483C80);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Will_Jump_Tracks(), 0x00483C90);
DEFINE_IMPLEMENTATION(bool LocomotionClass::Is_Really_Moving_Now(), 0x004822A0);
DEFINE_IMPLEMENTATION(void LocomotionClass::Stop_Movement_Animation(), 0x004822E0);
DEFINE_IMPLEMENTATION(void LocomotionClass::Lock(), 0x00483CA0);
DEFINE_IMPLEMENTATION(void LocomotionClass::Unlock(), 0x00483CB0);
DEFINE_IMPLEMENTATION(int LocomotionClass::Get_Track_Number(), 0x00483CC0);
DEFINE_IMPLEMENTATION(int LocomotionClass::Get_Track_Index(), 0x00483CD0);
DEFINE_IMPLEMENTATION(int LocomotionClass::Get_Speed_Accum(), 0x00483CE0);
FootClass* LocomotionClass::Linked_To() const { return dynamic_cast<FootClass*>(LinkedTo); }
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE LocomotionClass::Locomotion_Load(IStream*), 0x005065F0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(WinsockInterfaceClass::WinsockInterfaceClass(), 0x006A0EB0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(WinsockInterfaceClass::~WinsockInterfaceClass(), 0x006A0F60);
DEFINE_IMPLEMENTATION(void WinsockInterfaceClass::Close(), 0x006A0FE0);
DEFINE_IMPLEMENTATION(void WinsockInterfaceClass::Close_Socket(), 0x006A1010);
DEFINE_IMPLEMENTATION(bool WinsockInterfaceClass::Start_Listening(), 0x006A1030);
DEFINE_IMPLEMENTATION(void WinsockInterfaceClass::Stop_Listening(), 0x006A1080);
DEFINE_IMPLEMENTATION(void WinsockInterfaceClass::Discard_In_Buffers(), 0x006A10A0);
DEFINE_IMPLEMENTATION(void WinsockInterfaceClass::Discard_Out_Buffers(), 0x006A1110);
DEFINE_IMPLEMENTATION(bool WinsockInterfaceClass::Init(), 0x006A1180);
DEFINE_IMPLEMENTATION(void WinsockInterfaceClass::Build_Packet_CRC(WinsockInterfaceClass::WinsockBufferType*), 0x006A1280);
DEFINE_IMPLEMENTATION(bool WinsockInterfaceClass::Passes_CRC_Check(WinsockInterfaceClass::WinsockBufferType*) const, 0x006A1300);
DEFINE_IMPLEMENTATION(WinsockInterfaceClass::WinsockBufferType* WinsockInterfaceClass::Get_New_Out_Buffer(), 0x006A1390);
DEFINE_IMPLEMENTATION(WinsockInterfaceClass::WinsockBufferType* WinsockInterfaceClass::Get_New_In_Buffer(), 0x006A1430);
DEFINE_IMPLEMENTATION(int WinsockInterfaceClass::Read(void*, int&, void*, int&), 0x006A14D0);
DEFINE_IMPLEMENTATION(void WinsockInterfaceClass::WriteTo(void*, int, void*), 0x006A1580);
DEFINE_IMPLEMENTATION(void WinsockInterfaceClass::Broadcast(void*, int), 0x006A1640);
DEFINE_IMPLEMENTATION(void WinsockInterfaceClass::Clear_Socket_Error(SOCKET), 0x006A16F0);
DEFINE_IMPLEMENTATION(bool WinsockInterfaceClass::Set_Socket_Options(), 0x006A1740);
DEFINE_IMPLEMENTATION(bool WinsockInterfaceClass::Get_Host_Name(char*, int) const, 0x006A17D0);
DEFINE_IMPLEMENTATION(void WinsockInterfaceClass::Set_Broadcast_Address(void*), 0x006A0BD0);
DEFINE_IMPLEMENTATION(void WinsockInterfaceClass::Clear_Broadcast_Addresses(), 0x006A0BE0);
DEFINE_IMPLEMENTATION(ProtocolEnum WinsockInterfaceClass::Get_Protocol(), 0x006A1820);
DEFINE_IMPLEMENTATION(int WinsockInterfaceClass::Protocol_Event_Message(), 0x006A1830);
DEFINE_IMPLEMENTATION(bool WinsockInterfaceClass::Open_Socket(SOCKET socket), 0x006A1840);
DEFINE_IMPLEMENTATION(LRESULT WinsockInterfaceClass::Message_Handler(HWND, UINT, UINT, LONG), 0x006A1850);
DEFINE_IMPLEMENTATION(int WinsockInterfaceClass::Local_Addresses_Count() const, 0x006A0BF0);
DEFINE_IMPLEMENTATION(unsigned char* WinsockInterfaceClass::Get_Local_Address(int) const, 0x006A0C00);
DEFINE_IMPLEMENTATION(void WinsockInterfaceClass::Set_NetCard(int), 0x006A0C10);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(IPXManagerClass::IPXManagerClass(int, int, int, int, unsigned short, unsigned short), 0x004F0320);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(IPXManagerClass::~IPXManagerClass(), 0x004F0410);
DEFINE_IMPLEMENTATION(int IPXManagerClass::Init(), 0x004F0480);
DEFINE_IMPLEMENTATION(int IPXManagerClass::Is_IPX(), 0x004F05A0);
DEFINE_IMPLEMENTATION(void IPXManagerClass::Set_Timing(unsigned long, unsigned long, unsigned long, bool), 0x004F05B0);
DEFINE_IMPLEMENTATION(void IPXManagerClass::Set_External_Timing(unsigned long, unsigned long, unsigned long), 0x004F0640);
DEFINE_IMPLEMENTATION(void IPXManagerClass::Set_Bridge(NetNumType), 0x004F1930);
DEFINE_IMPLEMENTATION(int IPXManagerClass::Create_Connection(int, char*, IPXAddressClass*), 0x004F0670);
DEFINE_IMPLEMENTATION(int IPXManagerClass::Delete_Connection(int), 0x004F0720);
DEFINE_IMPLEMENTATION(int IPXManagerClass::Num_Connections(), 0x004F07B0);
DEFINE_IMPLEMENTATION(int IPXManagerClass::Connection_ID(int), 0x004F07C0);
DEFINE_IMPLEMENTATION(char* IPXManagerClass::Connection_Name(int), 0x004F07E0);
DEFINE_IMPLEMENTATION(IPXAddressClass* IPXManagerClass::Connection_Address(int), 0x004F0820);
DEFINE_IMPLEMENTATION(int IPXManagerClass::Connection_Index(int), 0x004F0860);
DEFINE_IMPLEMENTATION(void IPXManagerClass::Set_Connection_Parms(int, int, char*), 0x004F0890);
DEFINE_IMPLEMENTATION(int IPXManagerClass::Send_Global_Message(void*, int, int, IPXAddressClass*), 0x004F08E0);
DEFINE_IMPLEMENTATION(int IPXManagerClass::Get_Global_Message(void*, int*, IPXAddressClass*, unsigned short*), 0x004F0960);
DEFINE_IMPLEMENTATION(int IPXManagerClass::Send_Private_Message(void*, int, int, int), 0x004F09A0);
DEFINE_IMPLEMENTATION(int IPXManagerClass::Get_Private_Message(void*, int*, int*), 0x004F0A80);
DEFINE_IMPLEMENTATION(int IPXManagerClass::Service(), 0x004F0B10);
DEFINE_IMPLEMENTATION(int IPXManagerClass::Get_Bad_Connection(), 0x004F0DB0);
DEFINE_IMPLEMENTATION(int IPXManagerClass::Global_Num_Send(), 0x004F0DC0);
DEFINE_IMPLEMENTATION(int IPXManagerClass::Global_Num_Receive(), 0x004F0DE0);
DEFINE_IMPLEMENTATION(int IPXManagerClass::Private_Num_Send(int), 0x004F0E00);
DEFINE_IMPLEMENTATION(int IPXManagerClass::Private_Num_Receive(int), 0x004F0E70);
DEFINE_IMPLEMENTATION(void IPXManagerClass::Set_Socket(unsigned short), 0x004F0EE0);
DEFINE_IMPLEMENTATION(unsigned long IPXManagerClass::Response_Time(), 0x004F0F00);
DEFINE_IMPLEMENTATION(unsigned long IPXManagerClass::Global_Response_Time(), 0x004F0F60);
DEFINE_IMPLEMENTATION(void IPXManagerClass::Reset_Response_Time(bool), 0x004F1850);
DEFINE_IMPLEMENTATION(unsigned long IPXManagerClass::Avg_Response_Time(int), 0x004F0F40);
DEFINE_IMPLEMENTATION(void IPXManagerClass::Store_Multiplayer_Stats(), 0x004F0F80);
DEFINE_IMPLEMENTATION(void* IPXManagerClass::Oldest_Send(), 0x004F18A0);
DEFINE_IMPLEMENTATION(void IPXManagerClass::Configure_Debug(int, int, int, char**, int, int), 0x004F1950);
DEFINE_IMPLEMENTATION(void IPXManagerClass::Mono_Debug_Print(int, int), 0x004F19B0);
DEFINE_IMPLEMENTATION(void IPXManagerClass::Multiplayer_Debug_Print(), 0x004F10B0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(ConnectionClass::ConnectionClass(int, int, int, unsigned short, unsigned long, unsigned long, unsigned long, int), 0x00461D00);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(ConnectionClass::~ConnectionClass(), 0x00461D80);
DEFINE_IMPLEMENTATION(void ConnectionClass::Init(), 0x00461DB0);
DEFINE_IMPLEMENTATION(int ConnectionClass::Send_Packet(void*, int, int), 0x00461DE0);
DEFINE_IMPLEMENTATION(int ConnectionClass::Receive_Packet(void*, int), 0x00461E80);
DEFINE_IMPLEMENTATION(int ConnectionClass::Get_Packet(void*, int*), 0x004620A0);
DEFINE_IMPLEMENTATION(int ConnectionClass::Service(), 0x00462130);
DEFINE_IMPLEMENTATION(unsigned long ConnectionClass::Time(), 0x00462350);
DEFINE_IMPLEMENTATION(char* ConnectionClass::Command_Name(int), 0x00462380);
DEFINE_IMPLEMENTATION(int ConnectionClass::Service_Send_Queue(), 0x00462160);
DEFINE_IMPLEMENTATION(int ConnectionClass::Service_Receive_Queue(), 0x004622F0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(IPXConnClass::IPXConnClass(int, int, int, unsigned short, IPXAddressClass*, int, char*, int), 0x004EF450);
DEFINE_IMPLEMENTATION(void IPXConnClass::Init(), 0x004EF510);
DEFINE_IMPLEMENTATION(void IPXConnClass::Configure(unsigned short, int, ECBType*, ECBType*, IPXHeaderType*, IPXHeaderType*, char*, char*, long, int), 0x004EF520);
DEFINE_IMPLEMENTATION(int IPXConnClass::Start_Listening(), 0x004EF570);
DEFINE_IMPLEMENTATION(int IPXConnClass::Stop_Listening(), 0x004EF5E0);
DEFINE_IMPLEMENTATION(int IPXConnClass::Send(char*, int, void*, int), 0x004EF600);
DEFINE_IMPLEMENTATION(int IPXConnClass::Open_Socket(unsigned short), 0x004EF6D0);
DEFINE_IMPLEMENTATION(void IPXConnClass::Close_Socket(unsigned short), 0x004EF710);
DEFINE_IMPLEMENTATION(int IPXConnClass::Send_To(char*, int, IPXAddressClass*, NetNodeType), 0x004EF730);
DEFINE_IMPLEMENTATION(int IPXConnClass::Broadcast(char*, int), 0x004EF7C0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(IPXGlobalConnClass::IPXGlobalConnClass(int, int, int, unsigned short), 0x004EFA60);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(IPXGlobalConnClass::~IPXGlobalConnClass(), 0x004EFB91);
DEFINE_IMPLEMENTATION(int IPXGlobalConnClass::Send_Packet(void*, int, IPXAddressClass*, int), 0x004EFBA0);
DEFINE_IMPLEMENTATION(int IPXGlobalConnClass::Receive_Packet(void*, int, IPXAddressClass*), 0x004EFC50);
DEFINE_IMPLEMENTATION(int IPXGlobalConnClass::Get_Packet(void*, int*, IPXAddressClass*, unsigned short*), 0x004EFE30);
DEFINE_IMPLEMENTATION(void IPXGlobalConnClass::Set_Bridge(NetNumType), 0x004EFF70);
DEFINE_IMPLEMENTATION(int IPXGlobalConnClass::Send(char*, int, void*, int), 0x004EFEC0);
DEFINE_IMPLEMENTATION(int IPXGlobalConnClass::Service_Receive_Queue(), 0x004EFF30);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(CommBufferClass::CommBufferClass(int, int, int, int), 0x00460BC0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(CommBufferClass::~CommBufferClass(), 0x00460CD0);
DEFINE_IMPLEMENTATION(void CommBufferClass::Init(), 0x00460D80);
DEFINE_IMPLEMENTATION(void CommBufferClass::Init_Send_Queue(), 0x00460E60);
DEFINE_IMPLEMENTATION(int CommBufferClass::Queue_Send(void*, int, void*, int), 0x00460ED0);
DEFINE_IMPLEMENTATION(int CommBufferClass::UnQueue_Send(void*, int*, int, void*, int*), 0x00461020);
DEFINE_IMPLEMENTATION(int CommBufferClass::Queue_Receive(void*, int, void*, int), 0x004611C0);
DEFINE_IMPLEMENTATION(int CommBufferClass::UnQueue_Receive(void*, int*, int, void*, int*), 0x004612C0);
DEFINE_IMPLEMENTATION(void CommBufferClass::Add_Delay(unsigned long), 0x00461440);
DEFINE_IMPLEMENTATION(unsigned long CommBufferClass::Avg_Response_Time(), 0x004614B0);
DEFINE_IMPLEMENTATION(unsigned long CommBufferClass::Max_Response_Time(), 0x004614C0);
DEFINE_IMPLEMENTATION(void CommBufferClass::Reset_Response_Time(), 0x004614D0);
DEFINE_IMPLEMENTATION(void CommBufferClass::Configure_Debug(int, int, char**, int, int), 0x00461500);
DEFINE_IMPLEMENTATION(void CommBufferClass::Mono_Debug_Print(int), 0x00461530);
DEFINE_IMPLEMENTATION(void CommBufferClass::Mono_Debug_Print2(int), 0x00461810);

DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE DropPodLocomotionClass::QueryInterface(REFIID, LPVOID*), 0x00483AD0);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE DropPodLocomotionClass::AddRef(), 0x00483CF0);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE DropPodLocomotionClass::Release(), 0x00483D00);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE DropPodLocomotionClass::GetClassID(CLSID*), 0x00483860);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE DropPodLocomotionClass::Load(IStream*), 0x004838A0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE DropPodLocomotionClass::Save(IStream*, BOOL), 0x00483920);
DEFINE_IMPLEMENTATION(bool DropPodLocomotionClass::Is_Moving(), 0x00483170);
DEFINE_IMPLEMENTATION(Coord DropPodLocomotionClass::Destination(), 0x00483180);
DEFINE_IMPLEMENTATION(bool DropPodLocomotionClass::Process(), 0x004831B0);
DEFINE_IMPLEMENTATION(void DropPodLocomotionClass::Move_To(Coord), 0x00483620);
DEFINE_IMPLEMENTATION(void DropPodLocomotionClass::Stop_Moving(), 0x00483A00);
DEFINE_IMPLEMENTATION(LayerType DropPodLocomotionClass::In_Which_Layer(), 0x00483B30);
DEFINE_IMPLEMENTATION(int DropPodLocomotionClass::Drawing_Code(), 0x00483C50);
DEFINE_IMPLEMENTATION(HRESULT DropPodLocomotionClass::Begin_Piggyback(ILocomotion*), 0x00483A10);
DEFINE_IMPLEMENTATION(HRESULT DropPodLocomotionClass::End_Piggyback(ILocomotion**), 0x00483A60);
DEFINE_IMPLEMENTATION(bool DropPodLocomotionClass::Is_Ok_To_End(), 0x00483AA0);
DEFINE_IMPLEMENTATION(HRESULT DropPodLocomotionClass::Piggyback_CLSID(CLSID*), 0x00483B40);
DEFINE_IMPLEMENTATION(bool DropPodLocomotionClass::Is_Piggybacking(), 0x00483D10);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(DropPodLocomotionClass::DropPodLocomotionClass(), 0x004830F0);
DropPodLocomotionClass::DropPodLocomotionClass(const NoInitClass& noinit) : LocomotionClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006CFBBC; *((unsigned long*)this + 1) = (unsigned long)0x006CFAF4; *((unsigned long*)this + 2) = (unsigned long)0x006CFAD4; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(DropPodLocomotionClass::~DropPodLocomotionClass(), 0x00483140);
DEFINE_IMPLEMENTATION(int DropPodLocomotionClass::Get_Object_Size(bool) const, 0x00483D30);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(Quaternion::Quaternion(float, float, float, float), 0x005AFE70);
DEFINE_IMPLEMENTATION(void Quaternion::Set(float, float, float, float), 0x005AFE90);
DEFINE_IMPLEMENTATION(void Quaternion::Normalize(), 0x005AFEB0);
DEFINE_IMPLEMENTATION(void Quaternion::Scale(float), 0x005AFF10);
DEFINE_IMPLEMENTATION(float& Quaternion::operator[](int), 0x005AFF40);
DEFINE_IMPLEMENTATION(const float& Quaternion::operator[](int) const, 0x005AFF50);
DEFINE_IMPLEMENTATION(Quaternion Quaternion::operator=(const Quaternion&), 0x005AFF60);
DEFINE_IMPLEMENTATION(Quaternion& Quaternion::func_5AFFA0(Quaternion&), 0x005AFFA0);
DEFINE_IMPLEMENTATION(Quaternion Quaternion_5B0110(Quaternion&, Quaternion&), 0x005B0110);
DEFINE_IMPLEMENTATION(Quaternion Quaternion_5B0280(Quaternion&, Quaternion&), 0x005B0280);
DEFINE_IMPLEMENTATION(Quaternion Inverse(const Quaternion&), 0x005B0300);
DEFINE_IMPLEMENTATION(Quaternion Conjugate(const Quaternion&), 0x005B0350);
DEFINE_IMPLEMENTATION(Quaternion Trackball(float, float, float, float, float), 0x005B03A0);
DEFINE_IMPLEMENTATION(Quaternion Axis_To_Quat(const Vector3&, float), 0x005B06C0);
DEFINE_IMPLEMENTATION(Quaternion Slerp(Quaternion&, Quaternion&, float), 0x005B07D0);
DEFINE_IMPLEMENTATION(Quaternion Build_Quaternion(const Matrix3D&), 0x005B0970);
DEFINE_IMPLEMENTATION(Matrix3D Build_Matrix3D(const Quaternion&), 0x005B0BC0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(Matrix3D::Matrix3D(const Matrix3D &), 0x005546F0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(Matrix3D::Matrix3D(float, float, float, float, float, float, float, float, float, float, float, float), 0x00554740);
DEFINE_IMPLEMENTATION(void Matrix3D::Set(const Vector3&, const Vector3&, const Vector3&, const Vector3&), 0x005547A0);
DEFINE_IMPLEMENTATION(void Matrix3D::Set(float, float), 0x00554800);
DEFINE_IMPLEMENTATION(void Matrix3D::Set(const Vector3&, float), 0x00554860);
DEFINE_IMPLEMENTATION(void Matrix3D::Make_Identity(), 0x00554970);
DEFINE_IMPLEMENTATION(void Matrix3D::Translate(float, float, float), 0x005549A0);
DEFINE_IMPLEMENTATION(void Matrix3D::Translate(const Vector3&), 0x00554A00);
DEFINE_IMPLEMENTATION(void Matrix3D::Translate_X(float), 0x00554A90);
DEFINE_IMPLEMENTATION(void Matrix3D::Translate_Y(float), 0x00554AC0);
DEFINE_IMPLEMENTATION(void Matrix3D::Translate_Z(float), 0x00554AF0);
DEFINE_IMPLEMENTATION(void Matrix3D::Scale(float), 0x00554B20);
DEFINE_IMPLEMENTATION(void Matrix3D::Scale(float, float, float), 0x00554B80);
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
DEFINE_IMPLEMENTATION(Vector3 Matrix3D::Rotate_Vector(const Vector3&) const, 0x005555E0);
DEFINE_IMPLEMENTATION(void Matrix3D::Look_At_1(Vector3&, Vector3&, float), 0x00555660);
DEFINE_IMPLEMENTATION(void Matrix3D::Look_At_2(Vector3&, Vector3&, float), 0x00555820);
DEFINE_IMPLEMENTATION(Matrix3D operator*(const Matrix3D&, const Matrix3D&), 0x00555A90);
DEFINE_IMPLEMENTATION(Matrix3D func_555D30(Matrix3D&), 0x00555D30);

DEFINE_IMPLEMENTATION(int _XMP_Byte_Precision(unsigned long), 0x00564DA0);
DEFINE_IMPLEMENTATION(void xmp_memrev(char*, size_t), 0x00567420);
DEFINE_IMPLEMENTATION(int __cdecl xmp_pfunc(const void*, const void*), 0x00567440);
DEFINE_IMPLEMENTATION(int XMP_Significance(const xmp_digit*, int), 0x00565140);
DEFINE_IMPLEMENTATION(void XMP_Inc(xmp_digit*, int), 0x00565160);
DEFINE_IMPLEMENTATION(void XMP_Dec(xmp_digit*, int), 0x00565180);
DEFINE_IMPLEMENTATION(void XMP_Neg(xmp_digit*, int), 0x005651A0);
DEFINE_IMPLEMENTATION(void XMP_Abs(xmp_digit*, int), 0x005651D0);
DEFINE_IMPLEMENTATION(void XMP_Shift_Right_Bits(xmp_digit*, int, int), 0x00565210);
DEFINE_IMPLEMENTATION(void XMP_Shift_Left_Bits(xmp_digit*, int, int), 0x00565350);
DEFINE_IMPLEMENTATION(bool XMP_Rotate_Left(xmp_digit*, bool, int), 0x00565490);
DEFINE_IMPLEMENTATION(void XMP_Not(xmp_digit* xmp_digit_ptr, int), 0x005654D0);
DEFINE_IMPLEMENTATION(void XMP_Init(xmp_digit*, xmp_digit, int), 0x005654F0);
DEFINE_IMPLEMENTATION(unsigned XMP_Count_Bits(const xmp_digit*, int), 0x00565510);
DEFINE_IMPLEMENTATION(int XMP_Count_Bytes(const xmp_digit*, int), 0x00565550);
DEFINE_IMPLEMENTATION(void XMP_Move(xmp_digit*, xmp_digit const*, int), 0x00565570);
DEFINE_IMPLEMENTATION(int XMP_Compare(const xmp_digit*, const xmp_digit*, int), 0x00565590);
DEFINE_IMPLEMENTATION(bool XMP_Add(xmp_digit*, const xmp_digit*, const xmp_digit*, bool, int), 0x005655E0);
DEFINE_IMPLEMENTATION(bool XMP_Add_Int(xmp_digit*, const xmp_digit*, xmp_digit, bool, int), 0x00565650);
DEFINE_IMPLEMENTATION(bool XMP_Sub(xmp_digit*, const xmp_digit*, const xmp_digit*, bool, int), 0x005656B0);
DEFINE_IMPLEMENTATION(bool XMP_Sub_Int(xmp_digit*, const xmp_digit*, xmp_digit16, bool, int), 0x00565710);
DEFINE_IMPLEMENTATION(int XMP_Unsigned_Mult(xmp_digit*, const xmp_digit*, const xmp_digit*, int), 0x00565770);
DEFINE_IMPLEMENTATION(int XMP_Unsigned_Mult_Int(xmp_digit*, const xmp_digit*, xmp_signeddigit16, int), 0x00565940);
DEFINE_IMPLEMENTATION(int XMP_Signed_Mult_Int(xmp_digit*, const xmp_digit*, xmp_signeddigit16, int), 0x00565980);
DEFINE_IMPLEMENTATION(int XMP_Signed_Mult(xmp_digit*, const xmp_digit*, const xmp_digit*, int), 0x00565B90);
DEFINE_IMPLEMENTATION(xmp_digit16 XMP_Unsigned_Div_Int(xmp_digit*, xmp_digit const*, xmp_digit16, int), 0x00565D90);
DEFINE_IMPLEMENTATION(int XMP_Unsigned_Div(xmp_digit*, xmp_digit*, xmp_digit const*, xmp_digit const*, int), 0x00565EC0);
DEFINE_IMPLEMENTATION(void XMP_Signed_Div(xmp_digit*, xmp_digit*, xmp_digit const*, xmp_digit const*, int), 0x005660D0);
DEFINE_IMPLEMENTATION(int XMP_Reciprocal(xmp_digit*, const xmp_digit*, int), 0x00566540);
DEFINE_IMPLEMENTATION(void XMP_Decode_ASCII(char const*, xmp_digit*, int), 0x00566750);
// DEFINE_IMPLEMENTATION(void xmp_single_mul(xmp_digit16 *, xmp_digit16 *, xmp_digit16, int), 0x);
DEFINE_IMPLEMENTATION(void XMP_Double_Mul(xmp_digit*, const xmp_digit*, const xmp_digit*, int), 0x005669B0);
// DEFINE_IMPLEMENTATION(int xmp_stage_modulus(const xmp_digit *, int), 0x);
DEFINE_IMPLEMENTATION(int XMP_Mod_Mult(xmp_digit*, const xmp_digit*, const xmp_digit*, int), 0x00566C50);
DEFINE_IMPLEMENTATION(void XMP_Mod_Mult_Clear(int), 0x00566F70);
DEFINE_IMPLEMENTATION(xmp_digit16 xmp_quo_digit(xmp_digit16*), 0x00567020);
DEFINE_IMPLEMENTATION(int xmp_exponent_mod(xmp_digit*, const xmp_digit*, const xmp_digit*, const xmp_digit*, int), 0x005670B0);
DEFINE_IMPLEMENTATION(bool XMP_Is_Small_Prime(const xmp_digit* candidate, int), 0x00567460);
DEFINE_IMPLEMENTATION(bool XMP_Small_Divisors_Test(const xmp_digit* candidate, int), 0x005674E0);
DEFINE_IMPLEMENTATION(bool XMP_Fermat_Test(const xmp_digit* candidate_prime, unsigned, int), 0x00567530);
DEFINE_IMPLEMENTATION(void XMP_Inverse_A_Mod_B(xmp_digit*, xmp_digit const*, xmp_digit const*, int), 0x005662F0);
DEFINE_IMPLEMENTATION(void XMP_Signed_Decode(xmp_digit*, const unsigned char*, int, int), 0x005650B0);
DEFINE_IMPLEMENTATION(void XMP_Unsigned_Decode(xmp_digit*, const unsigned char*, int, int), 0x00565100);
DEFINE_IMPLEMENTATION(unsigned XMP_Encode(unsigned char*, xmp_digit const*, int), 0x00565040);
DEFINE_IMPLEMENTATION(unsigned XMP_Encode_Bounded(unsigned char*, unsigned, xmp_digit const*, int), 0x00564FA0);
DEFINE_IMPLEMENTATION(void XMP_Randomize(xmp_digit*, Straw&, int, int), 0x00567980);
DEFINE_IMPLEMENTATION(void XMP_Randomize_Bounded(xmp_digit*, Straw&, xmp_digit const*, xmp_digit const*, int), 0x005679F0);
DEFINE_IMPLEMENTATION(bool XMP_Is_Prime(xmp_digit const*, int), 0x00567BD0);
DEFINE_IMPLEMENTATION(bool XMP_Rabin_Miller_Test(Straw&, xmp_digit const*, int, int), 0x00567660);
DEFINE_IMPLEMENTATION(int XMP_DER_Length_Encode(unsigned long, unsigned char*), 0x00564DE0);
DEFINE_IMPLEMENTATION(int XMP_DER_Encode(xmp_digit const*, unsigned char*, int), 0x00564E60);
DEFINE_IMPLEMENTATION(void XMP_DER_Decode(xmp_digit*, unsigned char const*, int), 0x00564F20);
DEFINE_IMPLEMENTATION(xmp_digit16* XMP_Fetch_Prime_Table(), 0x00564D80);
DEFINE_IMPLEMENTATION(int XMP_Prime_Table_Size(), 0x00564D90);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE CellClass::GetClassID(CLSID*), 0x0045AE50);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE CellClass::Load(IStream*), 0x004597E0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE CellClass::Save(IStream*, BOOL), 0x00459990);
DEFINE_IMPLEMENTATION(int STDMETHODCALLTYPE CellClass::What_Am_I(), 0x0045D770);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(CellClass::CellClass(), AbstractClass, 0x004517C0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(CellClass::CellClass(const NoInitClass &x), AbstractClass, 0x00450F60);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(CellClass::~CellClass(), 0x00451750);
DEFINE_IMPLEMENTATION(RTTIType CellClass::Fetch_RTTI() const, 0x0045D780);
DEFINE_IMPLEMENTATION(int CellClass::Get_Object_Size(bool) const, 0x0045D790);
DEFINE_IMPLEMENTATION(Coord CellClass::Center_Coord() const, 0x0045C4E0);
DEFINE_IMPLEMENTATION(Coord CellClass::entry_5C() const, 0x0045C530);
DEFINE_IMPLEMENTATION(int CellClass::Get_Height(const Coord&) const, 0x00450F90);
DEFINE_IMPLEMENTATION(int CellClass::Preview_Cell_Color(void*, bool), 0x00451900);
DEFINE_IMPLEMENTATION(void CellClass::Cell_Color(RGBClass&, RGBClass&), 0x00451AF0);
DEFINE_IMPLEMENTATION(ObjectClass* CellClass::Cell_Find_Object(RTTIType, bool) const, 0x00452110);
DEFINE_IMPLEMENTATION(ObjectClass* const CellClass::Cell_Object(const Point2D&, bool) const, 0x004521D0);
DEFINE_IMPLEMENTATION(TechnoClass* const CellClass::Cell_Techno(const Point2D&, bool, TechnoClass*) const, 0x00452020);
DEFINE_IMPLEMENTATION(UnitClass* const CellClass::Cell_Unit(bool) const, 0x00454AC0);
DEFINE_IMPLEMENTATION(AircraftClass* const CellClass::Cell_Aircraft(bool) const, 0x00454B00);
DEFINE_IMPLEMENTATION(InfantryClass* const CellClass::Cell_Infantry(bool) const, 0x00454B40);
DEFINE_IMPLEMENTATION(BuildingClass* const CellClass::Cell_Building() const, 0x00452160);
DEFINE_IMPLEMENTATION(TerrainClass* const CellClass::Cell_Terrain(bool) const, 0x00452190);
DEFINE_IMPLEMENTATION(bool CellClass::Is_Clear_To_Build(SpeedType, const BuildingTypeClass*, const HouseClass*), 0x00452250);
DEFINE_IMPLEMENTATION(void CellClass::Recalc_Attributes(int), 0x00453240);
DEFINE_IMPLEMENTATION(void CellClass::Occupy_Down(ObjectClass*, bool), 0x00454810);
DEFINE_IMPLEMENTATION(void CellClass::Occupy_Up(ObjectClass*, bool), 0x004549D0);
DEFINE_IMPLEMENTATION(Rect CellClass::Get_Overlay_Rect() const, 0x00455B30);
DEFINE_IMPLEMENTATION(Rect CellClass::Get_Rect() const, 0x004560B0);
DEFINE_IMPLEMENTATION(void CellClass::Wall_Update(bool), 0x004567A0);
DEFINE_IMPLEMENTATION(Coord CellClass::Cell_Coord() const, 0x00456BA0);
DEFINE_IMPLEMENTATION(int CellClass::Reduce_Tiberium(int), 0x00456BF0);
DEFINE_IMPLEMENTATION(int CellClass::Reduce_Wall(int), 0x00456E90);
DEFINE_IMPLEMENTATION(int CellClass::Spot_Index(Coord&), 0x00457280);
DEFINE_IMPLEMENTATION(bool CellClass::Is_Spot_Free(int, bool) const, 0x00457310);
DEFINE_IMPLEMENTATION(Coord CellClass::Closest_Free_Spot(Coord&, bool, bool) const, 0x00457360);
DEFINE_IMPLEMENTATION(int CellClass::Clear_Icon(IsometricTileType, int), 0x00457650);
DEFINE_IMPLEMENTATION(void CellClass::Incoming(Coord&, bool, bool, bool), 0x004577D0);
DEFINE_IMPLEMENTATION(CellClass& CellClass::Adjacent_Cell(FacingType) const, 0x00457970);
DEFINE_IMPLEMENTATION(void CellClass::Adjust_Threat(HousesType, int), 0x004579D0);
DEFINE_IMPLEMENTATION(long CellClass::Tiberium_Adjust(bool), 0x00457A50);
DEFINE_IMPLEMENTATION(bool CellClass::Goodie_Check(FootClass*), 0x00457C00);
DEFINE_IMPLEMENTATION(bool CellClass::Flag_Place(HousesType), 0x00459040);
DEFINE_IMPLEMENTATION(bool CellClass::Flag_Remove(), 0x00459090);
DEFINE_IMPLEMENTATION(void CellClass::Shimmer(), 0x004590C0);
DEFINE_IMPLEMENTATION(bool CellClass::Is_Clear_To_Move(SpeedType, bool, bool, int, MZoneType, int, bool), 0x004590E0);
DEFINE_IMPLEMENTATION(bool CellClass::Is_Bridge_Here() const, 0x00459240);
DEFINE_IMPLEMENTATION(bool CellClass::Can_Tiberium_Grow() const, 0x00459250);
DEFINE_IMPLEMENTATION(bool CellClass::Can_Tiberium_Spread() const, 0x00459300);
DEFINE_IMPLEMENTATION(bool CellClass::Grow_Tiberium(), 0x004593C0);
DEFINE_IMPLEMENTATION(bool CellClass::Spread_Tiberium(bool), 0x004594D0);
DEFINE_IMPLEMENTATION(bool CellClass::Can_Tiberium_Germinate(TiberiumClass*) const, 0x004596C0);
DEFINE_IMPLEMENTATION(bool CellClass::Has_Tunnel(void) const, 0x0045A6A0);
DEFINE_IMPLEMENTATION(bool CellClass::Is_Near_Tunnel_NW(void) const, 0x0045A6D0);
DEFINE_IMPLEMENTATION(bool CellClass::Is_Near_Tunnel_ES(void) const, 0x0045A930);
DEFINE_IMPLEMENTATION(TiberiumType CellClass::Tiberium_Type_Here(), 0x0045AC10);
DEFINE_IMPLEMENTATION(int CellClass::Get_Tiberium_Value() const, 0x0045AC70)
DEFINE_IMPLEMENTATION(int CellClass::Occupier_Height() const, 0x0045ACD0);
DEFINE_IMPLEMENTATION(void CellClass::Detach(AbstractClass*), 0x0045AD80);
DEFINE_IMPLEMENTATION(void CellClass::Attach_Tag(TagClass*), 0x0045AEA0);
DEFINE_IMPLEMENTATION(void CellClass::Trigger_Veins(), 0x0045C5C0);
DEFINE_IMPLEMENTATION(unsigned CellClass::Toggle_Occupied_By(HousesType), 0x0045CA20);
DEFINE_IMPLEMENTATION(void CellClass::Redraw_Overlay(), 0x0045CB00);
DEFINE_IMPLEMENTATION(bool CellClass::Cloaked_By(HousesType) const, 0x0045CD30);
DEFINE_IMPLEMENTATION(bool CellClass::Sensed_By(HousesType) const, 0x0045CD50);
DEFINE_IMPLEMENTATION(void CellClass::Set_Cloaked_By(HousesType), 0x0045CD70);
DEFINE_IMPLEMENTATION(void CellClass::Clear_Cloaked_By(HousesType), 0x0045CD90);
DEFINE_IMPLEMENTATION(void CellClass::Set_Sensed_By(HousesType), 0x0045CDB0);
DEFINE_IMPLEMENTATION(void CellClass::Clear_Sensed_By(HousesType), 0x0045CDD0);
DEFINE_IMPLEMENTATION(bool CellClass::Place_Tiberium(TiberiumType, int), 0x0045CDF0);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE WarheadTypeClass::GetClassID(CLSID*), 0x0066F6B0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE WarheadTypeClass::Load(IStream*), 0x0066F6F0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE WarheadTypeClass::Save(IStream*, BOOL), 0x0066F8A0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(WarheadTypeClass::WarheadTypeClass(const char *), AbstractTypeClass, 0x0066ED40);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(WarheadTypeClass::WarheadTypeClass(const NoInitClass &), AbstractTypeClass, 0x0066EF00);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(WarheadTypeClass::~WarheadTypeClass(), 0x0066EF60);
DEFINE_IMPLEMENTATION(void WarheadTypeClass::Detach(AbstractClass*, bool), 0x0066F9A0);
DEFINE_IMPLEMENTATION(RTTIType WarheadTypeClass::Fetch_RTTI() const, 0x0066FA70);
DEFINE_IMPLEMENTATION(int WarheadTypeClass::Get_Object_Size(bool) const, 0x0066FA50);
DEFINE_IMPLEMENTATION(void WarheadTypeClass::Object_CRC(CRCEngine&) const, 0x0066F580);
DEFINE_IMPLEMENTATION(bool WarheadTypeClass::Read_INI(CCINIClass&), 0x0066F060);
DEFINE_IMPLEMENTATION(float Percent_String_To_Float(const char*), 0x0066ED00);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE Tactical::GetClassID(CLSID*), 0x00617EE0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE Tactical::Load(IStream*), 0x00617F20);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE Tactical::Save(IStream*, BOOL), 0x00617F80);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(Tactical::Tactical(), AbstractClass, 0x0060EEC0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(Tactical::Tactical(const NoInitClass &), AbstractClass, 0x0060F090);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(Tactical::~Tactical(), 0x0060F0D0);
DEFINE_IMPLEMENTATION(void Tactical::Detach(AbstractClass*, bool), 0x00616920);
DEFINE_IMPLEMENTATION(RTTIType Tactical::Fetch_RTTI() const, 0x00617FF0);
DEFINE_IMPLEMENTATION(int Tactical::Get_Object_Size(bool) const, 0x00618000);
DEFINE_IMPLEMENTATION(void Tactical::AI(), 0x0060F960);
DEFINE_IMPLEMENTATION(bool Tactical::entry_64(Rect&, Rect&, unsigned, bool), 0x00617CD0);
DEFINE_IMPLEMENTATION(Point2D Tactical::func_60F150(const Coord&) const, 0x0060F150);
DEFINE_IMPLEMENTATION(Point2D Tactical::func_60F270(const Point2D&) const, 0x0060F270);
DEFINE_IMPLEMENTATION(Point2D Tactical::func_60F350(const Coord&) const, 0x0060F350);
DEFINE_IMPLEMENTATION(bool Tactical::Coord_To_Pixel(const Coord&, Point2D&) const, 0x0060F4B0);
DEFINE_IMPLEMENTATION(Coord Tactical::Pixel_To_Coord(const Point2D&) const, 0x0060F660);
DEFINE_IMPLEMENTATION(Coord Tactical::func_60F740(const Point2D&) const, 0x0060F740);
DEFINE_IMPLEMENTATION(void Tactical::func_60F800(const Coord&, int), 0x0060F800);
DEFINE_IMPLEMENTATION(int Tactical::Z_Lepton_To_Pixel(LEPTON), 0x0060F3C0);
DEFINE_IMPLEMENTATION(LEPTON Tactical::Pixel_To_Z_Lepton(int), 0x0060F450);
DEFINE_IMPLEMENTATION(void Tactical::Render(XSurface& surface, bool full_redraw, RenderPassEnum render_pass), 0x006111E0);
DEFINE_IMPLEMENTATION(void Tactical::Set_Caption_Text(int), 0x00611C00);
DEFINE_IMPLEMENTATION(void Tactical::Clear_Caption_Text(), 0x00611C50);
DEFINE_IMPLEMENTATION(void Tactical::Draw_Screen_Text(const char*), 0x00611C60);
DEFINE_IMPLEMENTATION(void Tactical::Set_Tactical_Dimensions(const Rect&), 0x00612B40);
DEFINE_IMPLEMENTATION(void Tactical::Set_Tactical_Center_Position(const Point2D&), 0x00612BE0);
DEFINE_IMPLEMENTATION(void Tactical::Set_Tactical_Position(const Coord&), 0x00612C50);
DEFINE_IMPLEMENTATION(Point2D Tactical::Get_Tactical_Center_Position() const, 0x00612D50);
DEFINE_IMPLEMENTATION(Point2D Tactical::Get_Tactical_Position() const, 0x00612D70);
DEFINE_IMPLEMENTATION(Cell Tactical::Click_Cell_Calc(Point2D&) const, 0x006131C0);
DEFINE_IMPLEMENTATION(int Tactical::Cell_Shadow(Cell&, bool), 0x00614F90);
DEFINE_IMPLEMENTATION(Point2D Tactical::func_60F0F0(Point2D), 0x0060F0F0);
DEFINE_IMPLEMENTATION(void Tactical::Register_Dirty_Area(Rect, bool), 0x0060FBB0);
DEFINE_IMPLEMENTATION(void Tactical::Debug_Draw_Occupiers(), 0x006173B0);
DEFINE_IMPLEMENTATION(void Tactical::Debug_Draw_Occupiers_Flags(), 0x006177A0);
DEFINE_IMPLEMENTATION(void Tactical::Draw_Radial_Indicators() const, 0x00617FA0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(FuseClass::FuseClass(), 0x004A99F0);
FuseClass::FuseClass(const NoInitClass&) {}
FuseClass::~FuseClass() {}
DEFINE_IMPLEMENTATION(void FuseClass::Arm_Fuse(Coord&, Coord&, int, int), 0x004A9A20);
DEFINE_IMPLEMENTATION(FuseResultType FuseClass::Fuse_Checkup(Coord&), 0x004A9AE0);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE OverlayTypeClass::GetClassID(CLSID*), 0x0058D900);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE OverlayTypeClass::Load(IStream*), 0x0058D7F0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE OverlayTypeClass::Save(IStream*, BOOL), 0x0058D8E0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(OverlayTypeClass::OverlayTypeClass(const char *), ObjectTypeClass, 0x0058CFF0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(OverlayTypeClass::OverlayTypeClass(const NoInitClass &), ObjectTypeClass, 0x0058D140);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(OverlayTypeClass::~OverlayTypeClass(), 0x0058D160);
DEFINE_IMPLEMENTATION(RTTIType OverlayTypeClass::Fetch_RTTI() const, 0x0058DC20);
DEFINE_IMPLEMENTATION(int OverlayTypeClass::Get_Object_Size(bool) const, 0x0058DC30);
DEFINE_IMPLEMENTATION(void OverlayTypeClass::Object_CRC(CRCEngine&) const, 0x0058D750);
DEFINE_IMPLEMENTATION(int OverlayTypeClass::Fetch_Heap_ID() const, 0x0058DC40);
DEFINE_IMPLEMENTATION(bool OverlayTypeClass::Read_INI(CCINIClass&), 0x0058D490);
DEFINE_IMPLEMENTATION(Coord OverlayTypeClass::Coord_Fixup(Coord*) const, 0x0058D730);
DEFINE_IMPLEMENTATION(bool OverlayTypeClass::Create_And_Place(Cell&, HouseClass*) const, 0x0058D2B0);
DEFINE_IMPLEMENTATION(ObjectClass* const OverlayTypeClass::Create_One_Of(HouseClass*) const, 0x0058D2E0);
DEFINE_IMPLEMENTATION(Cell* OverlayTypeClass::Occupy_List(bool) const, 0x0058D240);
DEFINE_IMPLEMENTATION(ShapeSet* const OverlayTypeClass::Get_Image_Data() const, 0x0058DB20);
DEFINE_IMPLEMENTATION(void OverlayTypeClass::Draw_It(Point2D&, Rect&, int) const, 0x0058D310);
DEFINE_IMPLEMENTATION(void OverlayTypeClass::Init(TheaterType), 0x0058D3A0);
DEFINE_IMPLEMENTATION(RGBStruct OverlayTypeClass::Get_Radar_Color(int), 0x0058D9D0);

DEFINE_IMPLEMENTATION(int Base64Pipe::Flush(), 0x0041ECF0);
DEFINE_IMPLEMENTATION(int Base64Pipe::Put(const void*, int), 0x0041EB60);

DEFINE_IMPLEMENTATION(int Base64Straw::Get(void*, int), 0x0041ED40);

DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE BaseClass::Load(IStream*), 0x0041FB90);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE BaseClass::Save(IStream*, BOOL), 0x0041FDB0);
DEFINE_IMPLEMENTATION(void BaseClass::Object_CRC(CRCEngine&) const, 0x0041FEB0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(BaseClass::BaseClass(), 0x0041F4C0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(BaseClass::BaseClass(const NoInitClass &), 0x0041FF10);
BaseClass::~BaseClass() {}
DEFINE_IMPLEMENTATION(bool BaseClass::Is_Built(int) const, 0x0041F550);
DEFINE_IMPLEMENTATION(BuildingClass* BaseClass::Get_Building(int) const, 0x0041F5D0);
DEFINE_IMPLEMENTATION(bool BaseClass::Is_Node(const BuildingClass*), 0x0041F750);
DEFINE_IMPLEMENTATION(BaseNodeClass* BaseClass::Get_Node(const BuildingClass*), 0x0041F7E0);
DEFINE_IMPLEMENTATION(BaseNodeClass* BaseClass::Get_Node(Cell&), 0x0041F860);
DEFINE_IMPLEMENTATION(BaseNodeClass* BaseClass::Next_Buildable(StructType), 0x0041F8B0);
DEFINE_IMPLEMENTATION(int BaseClass::Next_Buildable_Index(StructType), 0x0041F910);
DEFINE_IMPLEMENTATION(void BaseClass::Read_INI(CCINIClass&, const char*), 0x0041F970);
DEFINE_IMPLEMENTATION(void BaseClass::Write_INI(const CCINIClass&, const char*), 0x0041FAC0);

EventClass::EventClass() : Type(EVENT_EMPTY), ID(-1) {}
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(EventClass::EventClass(unsigned int, SpecialClass), 0x00493CC0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(EventClass::EventClass(unsigned int, EventType, TargetClass), 0x00493D00);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(EventClass::EventClass(unsigned int, EventType), 0x00493DE0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(EventClass::EventClass(unsigned int, EventType, Cell *), 0x00493D70);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(EventClass::EventClass(unsigned int, EventType, TargetClass, TargetClass), 0x00493EB0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(EventClass::EventClass(unsigned int, TargetClass, MissionType, TargetClass, TargetClass), 0x00493FA0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(EventClass::EventClass(unsigned int, TargetClass, MissionType, TargetClass, TargetClass, SpeedType, MPHType), 0x00494010);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(EventClass::EventClass(unsigned int, EventType, RTTIType, int), 0x004940A0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(EventClass::EventClass(unsigned int, EventType, RTTIType, Cell *), 0x00494110);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(EventClass::EventClass(unsigned int, EventType, int, Cell *), 0x00494190);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(EventClass::EventClass(unsigned int, AnimType, HousesType, Coord *), 0x00493F30);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(EventClass::EventClass(unsigned int, void *, unsigned long), 0x00494210);
DEFINE_IMPLEMENTATION(void EventClass::Execute(), 0x00494280);

WWMessageBox::WWMessageBox(int caption) { Caption = caption; }
DEFINE_IMPLEMENTATION(int WWMessageBox::Process(const char*, int, const char*, const char*, const char*, bool), 0x005727F0);
DEFINE_IMPLEMENTATION(int WWMessageBox::Process(int, int, int, int, int, bool), 0x00572B20);
DEFINE_IMPLEMENTATION(int WWMessageBox::Process(char const*, int, int, int, int, bool), 0x00572B70);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(SpotlightClass::SpotlightClass(Coord, int), 0x0058DFD0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(SpotlightClass::~SpotlightClass(), 0x0058E050);
DEFINE_IMPLEMENTATION(void SpotlightClass::Remove_If_Large(), 0x0058E0A0);
DEFINE_IMPLEMENTATION(void SpotlightClass::Update_All(), 0x0058E110);
DEFINE_IMPLEMENTATION(void SpotlightClass::One_Time(), 0x0058E1A0);
DEFINE_IMPLEMENTATION(void SpotlightClass::Clear_All(), 0x0058E580);
DEFINE_IMPLEMENTATION(void SpotlightClass::Draw_It(), 0x0058E5D0);
DEFINE_IMPLEMENTATION(void SpotlightClass::Draw_All(), 0x0058EA20);

DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE GScreenClass::QueryInterface(REFIID, LPVOID*), 0x004B9390);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE GScreenClass::AddRef(), 0x00402AD0);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE GScreenClass::Release(), 0x00402AE0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(GScreenClass::GScreenClass(), 0x004B9370);
GScreenClass::GScreenClass(const NoInitClass&) { *((unsigned long*)this) = (unsigned long)0x006D1A5C; }
GScreenClass::~GScreenClass() {}
DEFINE_IMPLEMENTATION(void GScreenClass::One_Time(), 0x004B93F0);
DEFINE_IMPLEMENTATION(void GScreenClass::Init_Theater(TheaterType), 0x004B9400);
DEFINE_IMPLEMENTATION(void GScreenClass::Init_Clear(), 0x004B9420);
DEFINE_IMPLEMENTATION(void GScreenClass::Init_IO(), 0x004B9430);
DEFINE_IMPLEMENTATION(void GScreenClass::Input(KeyNumType&, int&, int&), 0x004B9470);
DEFINE_IMPLEMENTATION(void GScreenClass::AI(KeyNumType&, Point2D&), 0x004B9A70);
DEFINE_IMPLEMENTATION(void GScreenClass::Add_A_Button(GadgetClass&), 0x004B9540);
DEFINE_IMPLEMENTATION(void GScreenClass::Remove_A_Button(GadgetClass&), 0x004B9580);
DEFINE_IMPLEMENTATION(void GScreenClass::Flag_To_Redraw(int), 0x004B9440);
DEFINE_IMPLEMENTATION(void GScreenClass::Render(), 0x004B95A0);
DEFINE_IMPLEMENTATION(void GScreenClass::Draw_It(bool), 0x0047C180);
DEFINE_IMPLEMENTATION(void GScreenClass::Blit_Display(), 0x004B96B0);
DEFINE_IMPLEMENTATION(void GScreenClass::Blit(bool, Surface*, int), 0x004B96C0);

CrateClass::CrateClass() : Timer(), Location(-1, -1) {}
CrateClass::~CrateClass() {}
void CrateClass::Init() { Make_Invalid(); }
DEFINE_IMPLEMENTATION(bool CrateClass::Create_Crate(Cell&), 0x00470820);
bool CrateClass::Is_Here(Cell& cell) const { return Is_Valid() && cell == Location; }
DEFINE_IMPLEMENTATION(bool CrateClass::Remove_It(), 0x004707B0);
bool CrateClass::Is_Expired() const { return Is_Valid() && Timer.Expired(); }
bool CrateClass::Is_Valid() const { return Location.X > 0 && Location.Y > 0; }
DEFINE_IMPLEMENTATION(bool CrateClass::Put_Crate(Cell&), 0x00470950);
DEFINE_IMPLEMENTATION(bool CrateClass::Get_Crate(Cell&), 0x00470B60);
void CrateClass::Make_Invalid() { Location = Cell(-1, -1); Timer.Stop(); }

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(ColorScheme::ColorScheme(), 0x005E2430);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(ColorScheme::ColorScheme(const char *, HSVClass *, PaletteClass *, PaletteClass *, int), 0x005E24F0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(ColorScheme::~ColorScheme(), 0x005E26C0);
DEFINE_IMPLEMENTATION(void ColorScheme::Build_Light_Converters(PaletteClass*, PaletteClass*, int, int, int), 0x005E2650);
DEFINE_IMPLEMENTATION(ConvertClass* ColorScheme::Build_Light_Converter(HSVClass*, PaletteClass*, PaletteClass*, PaletteClass*, Surface*, int, int, int, int, bool*), 0x005E2190);
DEFINE_IMPLEMENTATION(ConvertClass* ColorScheme::Build_Converter(HSVClass*, PaletteClass*, PaletteClass*, Surface*, PaletteClass*), 0x005E22E0);
DEFINE_IMPLEMENTATION(ColorScheme* ColorScheme::Find_Or_Make(const char*, HSVClass&, PaletteClass*, PaletteClass*, int), 0x005E27B0);
DEFINE_IMPLEMENTATION(ColorScheme* Fetch_Scheme_By_Name(const char*, int), 0x005E2840);
DEFINE_IMPLEMENTATION(ColorSchemeType Fetch_Scheme_Index_By_Name(const char*, int), 0x005E28A0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(StorageClass::StorageClass(), 0x0060AD60);
StorageClass::StorageClass(const NoInitClass& noinit) {}
StorageClass::~StorageClass() {}
DEFINE_IMPLEMENTATION(int StorageClass::Get_Total_Value() const, 0x0060AD80);
DEFINE_IMPLEMENTATION(int StorageClass::Get_Total_Amount() const, 0x0060ADB0);
DEFINE_IMPLEMENTATION(int StorageClass::Get_Amount(TiberiumType) const, 0x0060ADD0);
DEFINE_IMPLEMENTATION(int StorageClass::Increase_Amount(int, TiberiumType), 0x0060ADE0);
DEFINE_IMPLEMENTATION(int StorageClass::Decrease_Amount(int, TiberiumType), 0x0060AE00);
DEFINE_IMPLEMENTATION(StorageClass StorageClass::operator+(StorageClass&) const, 0x0060AE20);
DEFINE_IMPLEMENTATION(StorageClass StorageClass::operator+=(StorageClass&), 0x0060AE90);
DEFINE_IMPLEMENTATION(StorageClass StorageClass::operator-(StorageClass&) const, 0x0060AEE0);
DEFINE_IMPLEMENTATION(StorageClass StorageClass::operator-=(StorageClass&), 0x0060AF50);
DEFINE_IMPLEMENTATION(int StorageClass::First_Used_Slot() const, 0x0060AFA0);

DEFINE_IMPLEMENTATION(BOOL STDMETHODCALLTYPE MapClass::Is_Visible(Cell), 0x0050F1B0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(MapClass::MapClass(), 0x0050EAD0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(MapClass::MapClass(const NoInitClass &), 0x0050EBE0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(MapClass::~MapClass(), 0x0050ED30);
DEFINE_IMPLEMENTATION(void MapClass::One_Time(), 0x0050F2E0);
DEFINE_IMPLEMENTATION(void MapClass::Init_Clear(), 0x0050F4D0);
DEFINE_IMPLEMENTATION(void MapClass::Alloc_Cells(), 0x0050F590);
DEFINE_IMPLEMENTATION(void MapClass::Free_Cells(), 0x0050F5F0);
DEFINE_IMPLEMENTATION(void MapClass::Init_Cells(), 0x0050F6B0);
DEFINE_IMPLEMENTATION(void MapClass::Detach(AbstractClass*, bool), 0x0051DE80);
DEFINE_IMPLEMENTATION(bool MapClass::entry_64() const, 0x0047C190);
DEFINE_IMPLEMENTATION(void MapClass::Logic(), 0x00514300);
DEFINE_IMPLEMENTATION(void MapClass::Set_Map_Dimensions(Rect&, bool, int, bool), 0x0050F700);
DEFINE_IMPLEMENTATION(void MapClass::entry_70(Rect&), 0x00510A20);
DEFINE_IMPLEMENTATION(CellClass& MapClass::operator[](const Cell&), 0x0050F280);
DEFINE_IMPLEMENTATION(CellClass& MapClass::operator[](const Coord&), 0x0050F210);
DEFINE_IMPLEMENTATION(void MapClass::Sight_From(const Coord&, int, HouseClass*, bool, bool, bool, bool), 0x00510B60);
DEFINE_IMPLEMENTATION(bool MapClass::In_Radar(const Cell&) const, 0x00510FB0);
DEFINE_IMPLEMENTATION(bool MapClass::In_Radar(const Coord&) const, 0x00511000);
DEFINE_IMPLEMENTATION(void MapClass::Place_Down(Cell&, ObjectClass*), 0x00511070);
DEFINE_IMPLEMENTATION(void MapClass::Pick_Up(Cell&, ObjectClass*), 0x005111B0);
DEFINE_IMPLEMENTATION(long MapClass::Overpass(), 0x005112F0);
DEFINE_IMPLEMENTATION(int MapClass::Cell_Region(Cell&), 0x00514460);
DEFINE_IMPLEMENTATION(int MapClass::Cell_Threat(Cell&, HouseClass*), 0x00514490);
DEFINE_IMPLEMENTATION(bool MapClass::Place_Random_Crate(), 0x00514500);
DEFINE_IMPLEMENTATION(bool MapClass::Remove_Crate(Cell&), 0x005145D0);
DEFINE_IMPLEMENTATION(int MapClass::MapClass::Validate(), 0x005147E0);
DEFINE_IMPLEMENTATION(ObjectClass* MapClass::Close_Object(Coord&) const, 0x005147F0);
DEFINE_IMPLEMENTATION(void MapClass::Update_Cell_Zone(const Cell&), 0x00515A00);
DEFINE_IMPLEMENTATION(Cell MapClass::Nearby_Location(Cell const&, SpeedType, int zone, MZoneType, bool, Point2D, bool, bool, bool, bool, Cell const&) const, 0x005161A0);
DEFINE_IMPLEMENTATION(bool MapClass::Is_Area_Clear(const Cell&, int, int, SpeedType, int, MZoneType, int, bool, bool) const, 0x00516BE0);
DEFINE_IMPLEMENTATION(bool MapClass::Base_Region(const Cell&, HousesType&, ZoneType&) const, 0x00516CB0);
DEFINE_IMPLEMENTATION(const Cell MapClass::Pick_Random_Location(), 0x0051DFB0);
DEFINE_IMPLEMENTATION(void MapClass::Shroud_The_Map(), 0x0051E010);
DEFINE_IMPLEMENTATION(void MapClass::Reveal_The_Map(), 0x0051E0A0);
DEFINE_IMPLEMENTATION(int MapClass::Get_Height_GL(const Coord&) const, 0x0051E130);
DEFINE_IMPLEMENTATION(CellClass* MapClass::Iterate(), 0x0051E1B0);
DEFINE_IMPLEMENTATION(void MapClass::Reset_Iterator(), 0x0051E270);
DEFINE_IMPLEMENTATION(bool MapClass::In_Local_Radar(Rect&, bool) const, 0x0051E2B0);
DEFINE_IMPLEMENTATION(bool MapClass::In_Local_Radar(const Cell&, bool) const, 0x0051E380);
DEFINE_IMPLEMENTATION(bool MapClass::In_Local_Radar(CellClass&, bool) const, 0x0051E460);
DEFINE_IMPLEMENTATION(bool MapClass::In_Local_Radar(const Coord&) const, 0x0051E510);
DEFINE_IMPLEMENTATION(CellClass* MapClass::Local_Iterate(), 0x0051E630);
DEFINE_IMPLEMENTATION(void MapClass::Reset_Local_Iterator(), 0x0051E770);
DEFINE_IMPLEMENTATION(bool MapClass::Deform(const Cell&, bool), 0x0051E9E0);
DEFINE_IMPLEMENTATION(bool MapClass::Crack_Ice(CellClass&, ObjectClass*), 0x00520700);
DEFINE_IMPLEMENTATION(bool MapClass::Destroy_Low_Bridge_At(const Cell&), 0x005241B0);
DEFINE_IMPLEMENTATION(void MapClass::Collapse_Cliff(CellClass&), 0x00526C50);
DEFINE_IMPLEMENTATION(void MapClass::Clear_SubZones(), 0x00527AC0);
DEFINE_IMPLEMENTATION(void MapClass::Update_Cell_Subzones(const Cell&), 0x00529AC0);
DEFINE_IMPLEMENTATION(bool MapClass::Is_Shrouded(Coord&), 0x0052B870);
DEFINE_IMPLEMENTATION(bool MapClass::Is_Fogged(Coord&), 0x0052B9B0);
DEFINE_IMPLEMENTATION(void MapClass::Fog_Map(), 0x0052BBE0);
DEFINE_IMPLEMENTATION(void MapClass::Recalc_Ice(), 0x0052C610);
DEFINE_IMPLEMENTATION(bool MapClass::Destroy_Bridge_At(const Cell&), 0x0052C690);
DEFINE_IMPLEMENTATION(void MapClass::Place_Firestorm_Wall(const Cell&, HouseClass*, BuildingTypeClass*), 0x0052D7B0);
DEFINE_IMPLEMENTATION(void MapClass::Place_Wall(const Cell&, HouseClass*, BuildingTypeClass*), 0x0052D990);
DEFINE_IMPLEMENTATION(bool MapClass::Is_Same_Zone(Cell const&, Cell const&, MZoneType, bool, bool, bool), 0x005156E0);
DEFINE_IMPLEMENTATION(int MapClass::Get_Cell_Zone(Cell const&, MZoneType, bool), 0x00515810);

LayerClass::LayerClass() : DynamicVectorClass() { *((unsigned long*)this) = (unsigned long)0x006CDAE0; }
LayerClass::~LayerClass() {}
DEFINE_IMPLEMENTATION(bool LayerClass::Submit(ObjectClass const*, bool), 0x004FCD70);
DEFINE_IMPLEMENTATION(void LayerClass::Sort(), 0x004FCDF0);
DEFINE_IMPLEMENTATION(bool LayerClass::Sorted_Add(ObjectClass const*), 0x004FCE50);
DEFINE_IMPLEMENTATION(HRESULT LayerClass::Save(IStream*), 0x004FCEE0);
DEFINE_IMPLEMENTATION(HRESULT LayerClass::Load(IStream*), 0x004FCF50);

LogicClass::LogicClass() : LayerClass() { *((unsigned long*)this) = (unsigned long)0x006CA704; }
LogicClass::~LogicClass() {}
DEFINE_IMPLEMENTATION(bool LogicClass::Submit(ObjectClass const*, bool), 0x00507600);
DEFINE_IMPLEMENTATION(void LogicClass::Init(), 0x00402480);
DEFINE_IMPLEMENTATION(void LogicClass::One_Time(), 0x00402490);
DEFINE_IMPLEMENTATION(void LogicClass::Detach(AbstractClass*, bool), 0x00507400);
DEFINE_IMPLEMENTATION(void LogicClass::AI(), 0x00506AB0);
DEFINE_IMPLEMENTATION(void LogicClass::func_507210(), 0x00507210);
DEFINE_IMPLEMENTATION(void LogicClass::Remove(ObjectClass* const), 0x00507630);
DEFINE_IMPLEMENTATION(void LogicClass::func_507470(), 0x00507470);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(LCWPipe::LCWPipe(LCWPipe::CompControl, int), 0x004FD3B0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(LCWPipe::~LCWPipe(), 0x004FD420);
DEFINE_IMPLEMENTATION(int LCWPipe::Flush(), 0x004FD690);
DEFINE_IMPLEMENTATION(int LCWPipe::Put(const void*, int), 0x004FD460);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(LCWStraw::LCWStraw(LCWStraw::CompControl, int), 0x004FD7A0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(LCWStraw::~LCWStraw(), 0x004FD810);
DEFINE_IMPLEMENTATION(int LCWStraw::Get(void*, int), 0x004FD850);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(LZOPipe::LZOPipe(LZOPipe::CompControl, int), 0x00507DF0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(LZOPipe::~LZOPipe(), 0x00507E50);
DEFINE_IMPLEMENTATION(int LZOPipe::Flush(), 0x00508120);
DEFINE_IMPLEMENTATION(int LZOPipe::Put(const void*, int), 0x00507E90);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(LZOStraw::LZOStraw(LZOStraw::CompControl, int), 0x00508260);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(LZOStraw::~LZOStraw(), 0x005082C0);
DEFINE_IMPLEMENTATION(int LZOStraw::Get(void*, int), 0x00508300);

DEFINE_IMPLEMENTATION(int lzo1x_1_compress(const lzo_bytep, lzo_uint, lzo_bytep, lzo_uintp, lzo_voidp), 0x005076D0);
DEFINE_IMPLEMENTATION(int lzo1x_decompress(const lzo_bytep, lzo_uint, lzo_bytep, lzo_uintp, lzo_voidp), 0x00507C20);

PKey::PKey() : Modulus(0), Exponent(0), BitPrecision(0) {}
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(PKey::PKey(void const *, void const *), 0x005A94F0);
DEFINE_IMPLEMENTATION(int PKey::Encrypt(void const*, int, void*) const, 0x005A9CD0);
DEFINE_IMPLEMENTATION(int PKey::Decrypt(void const*, int, void*) const, 0x005A9E00);
int PKey::Plain_Block_Size() const { return (BitPrecision - 1) / 8; }
int PKey::Crypt_Block_Size() const { return Plain_Block_Size() + 1; }
int PKey::Block_Count(int plaintext_length) const { return (((plaintext_length - 1) / Plain_Block_Size()) + 1); }
DEFINE_IMPLEMENTATION(int PKey::Encode_Modulus(void*) const, 0x005A9550);
DEFINE_IMPLEMENTATION(int PKey::Encode_Exponent(void*) const, 0x005A9570);
DEFINE_IMPLEMENTATION(void PKey::Decode_Modulus(void*), 0x005A9590);
DEFINE_IMPLEMENTATION(void PKey::Decode_Exponent(void*), 0x005A95C0);
long PKey::Fast_Exponent() { return 65537L; }
DEFINE_IMPLEMENTATION(void PKey::Generate(Straw&, int, PKey&, PKey&), 0x005A95E0);

GadgetClass::GadgetClass() : X(0), Y(0), Width(0), Height(0), IsToRepaint(false), IsSticky(false), IsDisabled(false), Flags(0) { *((unsigned long*)this) = (unsigned long)0x006D07F4; }
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(GadgetClass::GadgetClass(int, int, int, int, unsigned, bool), 0x004A9BF0);
GadgetClass::GadgetClass(const NoInitClass& x) : LinkClass(x) { *((unsigned long*)this) = (unsigned long)0x006D07F4; }
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(GadgetClass::GadgetClass(const GadgetClass &), 0x004A9C40);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(GadgetClass::~GadgetClass(), 0x004A9C90);
DEFINE_IMPLEMENTATION(GadgetClass* GadgetClass::Get_Next() const, 0x004A9D90);
DEFINE_IMPLEMENTATION(GadgetClass* GadgetClass::Get_Prev() const, 0x004A9DA0);
DEFINE_IMPLEMENTATION(GadgetClass* GadgetClass::Remove(), 0x004A9D70);
DEFINE_IMPLEMENTATION(KeyNumType GadgetClass::Input(), 0x004A9E70);
DEFINE_IMPLEMENTATION(void GadgetClass::Draw_All(bool), 0x004A9E40);
DEFINE_IMPLEMENTATION(void GadgetClass::Delete_List(), 0x004A9DB0);
DEFINE_IMPLEMENTATION(ControlClass* GadgetClass::Extract_Gadget(unsigned), 0x004AA070);
DEFINE_IMPLEMENTATION(void GadgetClass::Flag_List_To_Redraw(), 0x0045DFA0);
DEFINE_IMPLEMENTATION(void GadgetClass::Disable(), 0x004A9D60);
DEFINE_IMPLEMENTATION(void GadgetClass::Enable(), 0x004A9D50);
DEFINE_IMPLEMENTATION(unsigned GadgetClass::Get_ID() const, 0x0047C150);
DEFINE_IMPLEMENTATION(void GadgetClass::Flag_To_Redraw(), 0x004AA0B0);
DEFINE_IMPLEMENTATION(void GadgetClass::Peer_To_Peer(unsigned, KeyNumType&, ControlClass&), 0x00463B50);
DEFINE_IMPLEMENTATION(void GadgetClass::Set_Focus(), 0x004AA0F0);
DEFINE_IMPLEMENTATION(void GadgetClass::Clear_Focus(), 0x004AA120);
DEFINE_IMPLEMENTATION(bool GadgetClass::Has_Focus(), 0x004AA140);
DEFINE_IMPLEMENTATION(bool GadgetClass::Is_List_To_Redraw(), 0x004AA150);
DEFINE_IMPLEMENTATION(bool GadgetClass::Is_To_Redraw(), 0x0045DFB0);
DEFINE_IMPLEMENTATION(void GadgetClass::Set_Position(int, int), 0x004AA170);
DEFINE_IMPLEMENTATION(void GadgetClass::Set_Size(int, int), 0x004AA190);
DEFINE_IMPLEMENTATION(bool GadgetClass::Draw_Me(bool), 0x004A9E20);
DEFINE_IMPLEMENTATION(void GadgetClass::Sticky_Process(unsigned), 0x004AA0C0);
DEFINE_IMPLEMENTATION(bool GadgetClass::Action(unsigned, KeyNumType&), 0x004A9E00);
DEFINE_IMPLEMENTATION(bool GadgetClass::Clicked_On(KeyNumType&, unsigned, int, int), 0x004A9CF0);
DEFINE_IMPLEMENTATION(ColorSchemeType GadgetClass::Get_Color_Scheme(), 0x004A9BD0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(ControlClass::ControlClass(unsigned, int, int, int, int, unsigned, bool), 0x00463A20);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(ControlClass::ControlClass(const ControlClass &), 0x00463A70);
ControlClass::ControlClass(const NoInitClass& x) : GadgetClass(x) { *((unsigned long*)this) = (unsigned long)0x006CD1AC; }
DEFINE_IMPLEMENTATION(void ControlClass::Make_Peer(GadgetClass&), 0x00463B00);
DEFINE_IMPLEMENTATION(bool ControlClass::Draw_Me(bool), 0x00463B20);
DEFINE_IMPLEMENTATION(unsigned ControlClass::Get_ID() const, 0x00463B10);
DEFINE_IMPLEMENTATION(bool ControlClass::Action(unsigned, KeyNumType&), 0x00463AA0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(DisplayClass::DisplayClass(), 0x00475BA0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(DisplayClass::DisplayClass(const NoInitClass &), 0x005F6950);
DisplayClass::~DisplayClass() {}
DEFINE_IMPLEMENTATION(void DisplayClass::One_Time(), 0x00475C80);
DEFINE_IMPLEMENTATION(void DisplayClass::Init_Clear(), 0x00475D20);
DEFINE_IMPLEMENTATION(void DisplayClass::Init_IO(), 0x00475D90);
DEFINE_IMPLEMENTATION(void DisplayClass::AI(KeyNumType&, Point2D&), 0x00476930);
DEFINE_IMPLEMENTATION(HRESULT DisplayClass::Load(IStream*), 0x0047B1E0);
DEFINE_IMPLEMENTATION(HRESULT DisplayClass::Save(IStream*), 0x0047B1B0);
DEFINE_IMPLEMENTATION(void DisplayClass::Read_INI(CCINIClass&), 0x00479C10);
DEFINE_IMPLEMENTATION(const char* DisplayClass::Help_Text(int), 0x0047AF20);
DEFINE_IMPLEMENTATION(void DisplayClass::Set_Dimensions(), 0x0047B170);
DEFINE_IMPLEMENTATION(void DisplayClass::Abort_Drag_Select(), 0x0047C070);
DEFINE_IMPLEMENTATION(bool DisplayClass::Map_Cell(Cell&, HouseClass*), 0x00476AB0);
DEFINE_IMPLEMENTATION(bool DisplayClass::entry_90(Cell&, HouseClass*), 0x00476EB0);
DEFINE_IMPLEMENTATION(bool DisplayClass::entry_94(Cell&, HouseClass*), 0x00477130);
DEFINE_IMPLEMENTATION(bool DisplayClass::Scroll_Map(FacingType, int&, bool), 0x00476A60);
DEFINE_IMPLEMENTATION(void DisplayClass::Set_View_Dimensions(Rect&), 0x00475DC0);
DEFINE_IMPLEMENTATION(void DisplayClass::Put_Place_Back(TechnoClass*), 0x00402AF0);
DEFINE_IMPLEMENTATION(void DisplayClass::Mouse_Right_Press(Point2D&), 0x00477D20);
DEFINE_IMPLEMENTATION(void DisplayClass::Mouse_Left_Press(Point2D&), 0x004791E0);
DEFINE_IMPLEMENTATION(void DisplayClass::Mouse_Left_Up(Cell&, bool, ObjectClass*, ActionType, bool), 0x00477E60);
DEFINE_IMPLEMENTATION(void DisplayClass::Mouse_Left_Held(Point2D&), 0x00479250);
DEFINE_IMPLEMENTATION(void DisplayClass::Mouse_Left_Release(Point2D&, Cell&, ObjectClass*, ActionType, bool), 0x00478880);
DEFINE_IMPLEMENTATION(void DisplayClass::Mouse_Right_Up(Point2D&), 0x00477D30);
DEFINE_IMPLEMENTATION(void DisplayClass::Set_Cursor_Shape(Cell const*), 0x00476040);
DEFINE_IMPLEMENTATION(Cell DisplayClass::Set_Cursor_Pos(Cell&), 0x00476490);
DEFINE_IMPLEMENTATION(bool DisplayClass::Passes_Proximity_Check(const ObjectTypeClass*, HousesType, const Cell*, Cell&), 0x004761A0);
DEFINE_IMPLEMENTATION(bool DisplayClass::Passes_Shroud_Check(const ObjectTypeClass*, HousesType, const Cell*, Cell&), 0x00476350);
DEFINE_IMPLEMENTATION(Cell DisplayClass::Get_Occupy_Dimensions(Cell const*) const, 0x004767D0);
DEFINE_IMPLEMENTATION(void DisplayClass::Cursor_Mark(Cell&, bool), 0x00476880);
DEFINE_IMPLEMENTATION(void DisplayClass::Submit(ObjectClass const*), 0x00476950);
DEFINE_IMPLEMENTATION(void DisplayClass::Remove(ObjectClass const*), 0x004769A0);
DEFINE_IMPLEMENTATION(ObjectClass* DisplayClass::Cell_Object(Cell&, Point2D&), 0x00477370);
DEFINE_IMPLEMENTATION(ObjectClass* DisplayClass::Next_Object(ObjectClass*) const, 0x00477390);
DEFINE_IMPLEMENTATION(ObjectClass* DisplayClass::Prev_Object(ObjectClass*) const, 0x00477430);
DEFINE_IMPLEMENTATION(Cell DisplayClass::Calculated_Cell(SourceType, Cell&, Cell&, SpeedType, bool, MZoneType) const, 0x004774C0);
DEFINE_IMPLEMENTATION(bool DisplayClass::Good_Reinforcement_Cell(Cell&, Cell&, SpeedType, int, MZoneType) const, 0x00477B40);
DEFINE_IMPLEMENTATION(void DisplayClass::Bandbox_Select(ObjectClass*), 0x00479150);
DEFINE_IMPLEMENTATION(void DisplayClass::Compute_Start_Pos(), 0x004793A0);
DEFINE_IMPLEMENTATION(void DisplayClass::Sell_Mode_Control(int), 0x004794E0);
DEFINE_IMPLEMENTATION(void DisplayClass::Waypoint_Mode_Control(int, bool), 0x00479580);
DEFINE_IMPLEMENTATION(void DisplayClass::Power_Mode_Control(int), 0x00479690);
DEFINE_IMPLEMENTATION(void DisplayClass::Repair_Mode_Control(int), 0x00479730);
DEFINE_IMPLEMENTATION(Coord DisplayClass::Closest_Free_Spot(const Coord&, bool) const, 0x004797D0);
DEFINE_IMPLEMENTATION(bool DisplayClass::Is_Spot_Free(Coord&, bool) const, 0x00479850);
DEFINE_IMPLEMENTATION(void DisplayClass::Encroach_Shadow(), 0x00479880);
DEFINE_IMPLEMENTATION(void DisplayClass::Encroach_Fog(), 0x00479970);
DEFINE_IMPLEMENTATION(void DisplayClass::Fog_Cell(Cell&), 0x00479A00);
DEFINE_IMPLEMENTATION(void DisplayClass::Shroud_Cell(Cell&), 0x00479B40);
DEFINE_IMPLEMENTATION(void DisplayClass::Write_INI(CCINIClass&), 0x0047A540);
DEFINE_IMPLEMENTATION(void DisplayClass::All_To_Look(bool, bool), 0x0047AA30);
DEFINE_IMPLEMENTATION(void DisplayClass::Constrained_Look(Coord&, LEPTON), 0x0047AAF0);
DEFINE_IMPLEMENTATION(void DisplayClass::Center_On_Selection(), 0x0047ACD0);
DEFINE_IMPLEMENTATION(void DisplayClass::Update_Cell_Colors(), 0x0047AEF0);
DEFINE_IMPLEMENTATION(ObjectClass* DisplayClass::Following_What() const, 0x0047C0C0);
DEFINE_IMPLEMENTATION(void DisplayClass::Follow_This(ObjectClass*), 0x0047C0E0);
DisplayClass::TacticalClass::TacticalClass() : GadgetClass(0, 0, 0, 0, LEFTPRESS | LEFTRELEASE | LEFTHELD | LEFTUP | RIGHTPRESS | RIGHTRELEASE | RIGHTHELD, true) { *((unsigned long*)this) = (unsigned long)0x006CDB08; }
DEFINE_IMPLEMENTATION(bool DisplayClass::TacticalClass::Action(unsigned, KeyNumType&), 0x00477C10);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(CreditClass::CreditClass(), 0x00471440);
CreditClass::CreditClass(const NoInitClass& x) {}
CreditClass::~CreditClass() {}
void CreditClass::Update(bool, bool) {}
DEFINE_IMPLEMENTATION(void CreditClass::Graphic_Logic(bool), 0x00471460);
DEFINE_IMPLEMENTATION(void CreditClass::AI(bool), 0x004715F0);

DEFINE_IMPLEMENTATION(bool Queue_Mission(MissionType, TargetClass&, TargetClass, TargetClass&), 0x005B0FC0);
DEFINE_IMPLEMENTATION(bool Queue_Mission(MissionType, TargetClass&, TargetClass, TargetClass&, SpeedType, MPHType), 0x005B1050);
DEFINE_IMPLEMENTATION(bool Queue_Options(), 0x005B10F0);
DEFINE_IMPLEMENTATION(bool Queue_PageUser(), 0x005B1180);
DEFINE_IMPLEMENTATION(bool Queue_Exit(), 0x005B1210);
DEFINE_IMPLEMENTATION(void Queue_AI(), 0x005B1280);
DEFINE_IMPLEMENTATION(void Queue_AI_Multiplayer(), 0x005B15B0);
DEFINE_IMPLEMENTATION(void Wait_To_Exit(), 0x005B1F60);
DEFINE_IMPLEMENTATION(RetcodeType Wait_For_Players(int, ConnManClass*, int, int, int, char*, unsigned short, FrameStatsStruct*), 0x005B2320);
DEFINE_IMPLEMENTATION(unsigned short Send_Packets(ConnManClass*, char*, int, int, unsigned short), 0x005B3240);
DEFINE_IMPLEMENTATION(void Send_FrameSync(ConnManClass*, unsigned short), 0x005B3550);
DEFINE_IMPLEMENTATION(RetcodeType Process_Receive_Packet(ConnManClass*, char*, int, int, FrameStatsStruct*, CDTimerClass<SystemTimerClass>*), 0x005B3600);
DEFINE_IMPLEMENTATION(RetcodeType Process_Serial_Packet(char*, int), 0x005B38E0);
DEFINE_IMPLEMENTATION(void Kick_Player_Now(ConnManClass*, int, FrameStatsStruct*, bool), 0x005B4290);
DEFINE_IMPLEMENTATION(void Propose_Kick_Player(HWND, int), 0x005B3C20);
DEFINE_IMPLEMENTATION(int Handle_Timeout(ConnManClass*, FrameStatsStruct*), 0x005B4470);
DEFINE_IMPLEMENTATION(int Add_Compressed_Events(void*, int, int, int, int, int&), 0x005B4530);
DEFINE_IMPLEMENTATION(int Extract_Compressed_Events(void*, int), 0x005B4A40);
DEFINE_IMPLEMENTATION(int Execute_DoList(int, HousesType, ConnManClass*, CDTimerClass<FrameTimerClass>*, FrameStatsStruct*), 0x005B4D70);
DEFINE_IMPLEMENTATION(void Clean_DoList(ConnManClass*), 0x005B5410);
DEFINE_IMPLEMENTATION(void Queue_Record(), 0x005B5470);
DEFINE_IMPLEMENTATION(void Compute_Game_CRC(), 0x005B5550);
DEFINE_IMPLEMENTATION(void Add_CRC(unsigned long*, unsigned long), 0x005B58D0);
DEFINE_IMPLEMENTATION(void Print_CRCs(EventClass*), 0x005B58F0);
DEFINE_IMPLEMENTATION(void Dump_Packet_Too_Late_Stuff(EventClass*), 0x005B8470);
DEFINE_IMPLEMENTATION(void Check_Mirror(), 0x005B84F0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(RadarClass::RadarClass(), 0x005B8830);
RadarClass::RadarClass(const NoInitClass&) {}
// DEFINE_IMPLEMENTATION_DESTRUCTOR(RadarClass::~RadarClass(), 0x005B8AC0);
DEFINE_IMPLEMENTATION(void RadarClass::One_Time(), 0x005B8B90);
DEFINE_IMPLEMENTATION(void RadarClass::Init_Clear(), 0x005B8C50);
DEFINE_IMPLEMENTATION(void RadarClass::AI(KeyNumType&, Point2D&), 0x005B9130);
DEFINE_IMPLEMENTATION(void RadarClass::Draw_It(bool), 0x005B8CD0);
DEFINE_IMPLEMENTATION(void RadarClass::Set_Map_Dimensions(Rect&, bool, int, bool), 0x005B9580);
DEFINE_IMPLEMENTATION(void RadarClass::entry_70(Rect&), 0x005B99D0);
DEFINE_IMPLEMENTATION(HRESULT RadarClass::Load(IStream*), 0x005BBBE0);
DEFINE_IMPLEMENTATION(HRESULT RadarClass::Save(IStream*), 0x005BBDA0);
DEFINE_IMPLEMENTATION(void RadarClass::Set_Dimensions(), 0x005B9980);
DEFINE_IMPLEMENTATION(bool RadarClass::Map_Cell(Cell&, HouseClass*), 0x005B9110);
DEFINE_IMPLEMENTATION(Cell RadarClass::Click_Cell_Calc(Point2D&), 0x005B9060);
DEFINE_IMPLEMENTATION(void RadarClass::Set_Tactical_Position(Coord&), 0x005B95A0);
DEFINE_IMPLEMENTATION(void RadarClass::Init_For_House(), 0x005B8CB0);
DEFINE_IMPLEMENTATION(int RadarClass::Cell_On_Radar(Cell&) const, 0x005B95C0);
DEFINE_IMPLEMENTATION(void RadarClass::Draw_Names(), 0x005B95D0);
DEFINE_IMPLEMENTATION(void RadarClass::Compute_Radar_Image(), 0x005B9B90);
DEFINE_IMPLEMENTATION(bool RadarClass::Radar_Activate(int), 0x005BBEE0);
DEFINE_IMPLEMENTATION(void RadarClass::Toggle_Radar(bool), 0x005BC080);
DEFINE_IMPLEMENTATION(bool RadarClass::Is_Player_Names(), 0x005BC150);
DEFINE_IMPLEMENTATION(void RadarClass::Redraw_Radar(bool), 0x005BC190);
DEFINE_IMPLEMENTATION(void RadarClass::Total_Radar_Refresh(), 0x005BCE90);
RadarClass::RTacticalClass::RTacticalClass() : GadgetClass(0, 0, 0, 0, LEFTPRESS | LEFTRELEASE | LEFTHELD | LEFTUP | RIGHTPRESS, true) {}
DEFINE_IMPLEMENTATION(bool RadarClass::RTacticalClass::Action(unsigned, KeyNumType&), 0x005B9190);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(PowerClass::PowerClass(), 0x005AAFD0);
PowerClass::PowerClass(const NoInitClass& x) {}
PowerClass::~PowerClass() {}
DEFINE_IMPLEMENTATION(void PowerClass::One_Time(), 0x005AB0D0);
DEFINE_IMPLEMENTATION(void PowerClass::Init_Clear(), 0x005AB050);
DEFINE_IMPLEMENTATION(void PowerClass::AI(KeyNumType&, Point2D&), 0x005AB7C0);
DEFINE_IMPLEMENTATION(void PowerClass::Draw_It(bool), 0x005AB460);
DEFINE_IMPLEMENTATION(const char* PowerClass::Help_Text(int), 0x005ABD50);
DEFINE_IMPLEMENTATION(void PowerClass::Set_Dimensions(), 0x005ABCC0);
DEFINE_IMPLEMENTATION(void PowerClass::Init_For_House(), 0x005AB0E0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(SidebarClass::SidebarClass(), 0x005F2330);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(SidebarClass::SidebarClass(const NoInitClass &), 0x005F2510);
SidebarClass::~SidebarClass() {}
DEFINE_IMPLEMENTATION(void SidebarClass::One_Time(), 0x005F2610);
DEFINE_IMPLEMENTATION(void SidebarClass::Init_Clear(), 0x005F2660);
DEFINE_IMPLEMENTATION(void SidebarClass::Init_IO(), 0x005F2720);
DEFINE_IMPLEMENTATION(void SidebarClass::AI(KeyNumType&, Point2D&), 0x005F3C70);
DEFINE_IMPLEMENTATION(void SidebarClass::Draw_It(bool), 0x005F3560);
DEFINE_IMPLEMENTATION(HRESULT SidebarClass::Load(IStream*), 0x005F68A0);
DEFINE_IMPLEMENTATION(HRESULT SidebarClass::Save(IStream*), 0x005F68B0);
DEFINE_IMPLEMENTATION(const char* SidebarClass::Help_Text(int), 0x005F6620);
DEFINE_IMPLEMENTATION(void SidebarClass::Set_Dimensions(), 0x005F6080);
DEFINE_IMPLEMENTATION(void SidebarClass::Init_For_House(), 0x005F2900);
// 005F25E0
DEFINE_IMPLEMENTATION(void SidebarClass::Reload_Sidebar(), 0x005F2B00);
DEFINE_IMPLEMENTATION(int SidebarClass::Which_Column(RTTIType), 0x005F2C30);
DEFINE_IMPLEMENTATION(bool SidebarClass::Factory_Link(FactoryClass*, RTTIType, int), 0x005F2C50);
DEFINE_IMPLEMENTATION(bool SidebarClass::Activate_Repair(int), 0x005F2CD0);
DEFINE_IMPLEMENTATION(bool SidebarClass::Activate_Upgrade(int), 0x005F2D40);
DEFINE_IMPLEMENTATION(bool SidebarClass::Activate_Demolish(int), 0x005F2DB0);
DEFINE_IMPLEMENTATION(bool SidebarClass::Add(RTTIType, int), 0x005F2E20);
DEFINE_IMPLEMENTATION(bool SidebarClass::Scroll(bool, int), 0x005F2E90);
DEFINE_IMPLEMENTATION(bool SidebarClass::Scroll_Page(bool, int), 0x005F30F0);
DEFINE_IMPLEMENTATION(void SidebarClass::Blit_Sidebar(bool), 0x005F38C0);
DEFINE_IMPLEMENTATION(void SidebarClass::Recalc(), 0x005F3E20);
DEFINE_IMPLEMENTATION(bool SidebarClass::Activate(int), 0x005F3E60);
DEFINE_IMPLEMENTATION(bool SidebarClass::Abandon_Production(RTTIType, FactoryClass*), 0x005F5F70);
SidebarClass::StripClass::SelectClass::SelectClass() : ControlClass(0, 0, 0, (OBJECT_WIDTH - 1), OBJECT_HEIGHT, LEFTPRESS | RIGHTPRESS | LEFTUP), Strip(nullptr), Index(0) { *((unsigned long*)this) = (unsigned long)0x006D682C; }
SidebarClass::StripClass::SelectClass::SelectClass(const NoInitClass& x) : ControlClass(x) { *((unsigned long*)this) = (unsigned long)0x006D682C; }
DEFINE_IMPLEMENTATION(void SidebarClass::StripClass::One_Time(int), 0x005F4210);
DEFINE_IMPLEMENTATION(ShapeSet const* SidebarClass::StripClass::Get_Special_Cameo(SuperWeaponType), 0x005F4230);
DEFINE_IMPLEMENTATION(void SidebarClass::StripClass::Init_Clear(), 0x005F4260);
DEFINE_IMPLEMENTATION(void SidebarClass::StripClass::Init_IO(int), 0x005F42A0);
DEFINE_IMPLEMENTATION(void SidebarClass::StripClass::Activate(), 0x005F4450);
DEFINE_IMPLEMENTATION(void SidebarClass::StripClass::Deactivate(), 0x005F4560);
DEFINE_IMPLEMENTATION(bool SidebarClass::StripClass::Add(RTTIType, int), 0x005F4630);
DEFINE_IMPLEMENTATION(bool SidebarClass::StripClass::Scroll(bool), 0x005F46B0);
DEFINE_IMPLEMENTATION(bool SidebarClass::StripClass::Scroll_Page(bool), 0x005F4760);
DEFINE_IMPLEMENTATION(void SidebarClass::StripClass::Flag_To_Redraw(), 0x005F48F0);
DEFINE_IMPLEMENTATION(bool SidebarClass::StripClass::AI(KeyNumType&, Point2D&), 0x005F4910);
DEFINE_IMPLEMENTATION(const char* SidebarClass::StripClass::Help_Text(int), 0x005F4E40);
DEFINE_IMPLEMENTATION(void SidebarClass::StripClass::Draw_It(bool), 0x005F4F10);
DEFINE_IMPLEMENTATION(bool SidebarClass::StripClass::Recalc(), 0x005F5610);
DEFINE_IMPLEMENTATION(bool SidebarClass::StripClass::Factory_Link(FactoryClass*, RTTIType, int), 0x005F5F10);
DEFINE_IMPLEMENTATION(bool SidebarClass::StripClass::Abandon_Production(FactoryClass*), 0x005F5FB0);
// 005F6030
// 005F6080
// 005F6620
// 005F6670
DEFINE_IMPLEMENTATION(void Print_Cameo_Text(const char*, Point2D&, Rect&, int), 0x005F66E0);
DEFINE_IMPLEMENTATION(bool SidebarClass::StripClass::SelectClass::Action(unsigned, KeyNumType&), 0x005F59A0);
DEFINE_IMPLEMENTATION(void SidebarClass::StripClass::SelectClass::Set_Owner(StripClass&, int), 0x005F5980);
SidebarClass::StripClass::StripClass() : StageClass() {}
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(SidebarClass::StripClass::StripClass(const InitClass &), 0x005F4180);
SidebarClass::StripClass::StripClass(const NoInitClass& x) : StageClass(x) {}
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(SidebarClass::SBGadgetClass::SBGadgetClass(), 0x005F2310);
DEFINE_IMPLEMENTATION(bool SidebarClass::SBGadgetClass::Action(unsigned, KeyNumType&), 0x005F5EF0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(TabClass::TabClass(), 0x0060E3F0);
TabClass::TabClass(const NoInitClass& x) : SidebarClass(x) { *((unsigned long*)this) = (unsigned long)0x006D46B0; }
TabClass::~TabClass() {}
DEFINE_IMPLEMENTATION(void TabClass::One_Time(), 0x0060EA80);
DEFINE_IMPLEMENTATION(void TabClass::AI(KeyNumType&, Point2D&), 0x0060E980);
DEFINE_IMPLEMENTATION(void TabClass::Draw_It(bool), 0x0060E440);
DEFINE_IMPLEMENTATION(void TabClass::Init_For_House(), 0x0060EA90);
DEFINE_IMPLEMENTATION(void TabClass::Set_Active(int), 0x0060EA60);
DEFINE_IMPLEMENTATION(void TabClass::Flash_Money(), 0x0060EAC0);
DEFINE_IMPLEMENTATION(void TabClass::Draw_Credits_Tab(), 0x0060E690);
DEFINE_IMPLEMENTATION(void TabClass::Hilite_Tab(int), 0x0060E8B0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(ScrollClass::ScrollClass(), 0x005E85A0);
ScrollClass::ScrollClass(const NoInitClass& x) : TabClass(x) { *((unsigned long*)this) = (unsigned long)0x006D64D4; }
ScrollClass::~ScrollClass() {}
DEFINE_IMPLEMENTATION(void ScrollClass::Init_IO(), 0x00402B00);
DEFINE_IMPLEMENTATION(void ScrollClass::AI(KeyNumType&, Point2D&), 0x005E85E0);
DEFINE_IMPLEMENTATION(bool ScrollClass::entry_64() const, 0x005E92C0);
DEFINE_IMPLEMENTATION(void ScrollClass::Abort_Drag_Select(), 0x005E9A30);
DEFINE_IMPLEMENTATION(void ScrollClass::Mouse_Right_Press(Point2D&), 0x005E99F0);
DEFINE_IMPLEMENTATION(void ScrollClass::Mouse_Right_Up(Point2D&), 0x005E99B0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(MouseClass::MouseClass(), 0x005621A0);
MouseClass::MouseClass(const NoInitClass& x) : ScrollClass(x) { *((unsigned long*)this) = (unsigned long)0x006CA754; }
MouseClass::~MouseClass() {}
DEFINE_IMPLEMENTATION(void MouseClass::One_Time(), 0x00562640);
DEFINE_IMPLEMENTATION(void MouseClass::Init_Clear(), 0x00562660);
DEFINE_IMPLEMENTATION(void MouseClass::AI(KeyNumType&, Point2D&), 0x005624D0);
DEFINE_IMPLEMENTATION(void MouseClass::Set_Default_Mouse(MouseType, bool), 0x005621D0);
DEFINE_IMPLEMENTATION(bool MouseClass::Override_Mouse_Shape(MouseType, bool), 0x00562390);
DEFINE_IMPLEMENTATION(void MouseClass::Revert_Mouse_Shape(), 0x005621F0);
DEFINE_IMPLEMENTATION(void MouseClass::Mouse_Small(bool), 0x00562200);
DEFINE_IMPLEMENTATION(HRESULT MouseClass::Load(IStream*), 0x00562680);
DEFINE_IMPLEMENTATION(HRESULT MouseClass::Save(IStream*), 0x00562F10);
DEFINE_IMPLEMENTATION(MouseType MouseClass::Get_Mouse_Shape() const, 0x00402B10);
DEFINE_IMPLEMENTATION(int MouseClass::Get_Mouse_Current_Frame(MouseType, bool) const, 0x005622D0);
DEFINE_IMPLEMENTATION(Point2D MouseClass::Get_Mouse_Hotspot(MouseType) const, 0x00562310);
DEFINE_IMPLEMENTATION(int MouseClass::Get_Mouse_Start_Frame(MouseType) const, 0x00563220);
DEFINE_IMPLEMENTATION(int MouseClass::Get_Mouse_Frame_Count(MouseType) const, 0x00563240);

DEFINE_IMPLEMENTATION(bool Get_Scenario_File_From_Host(char*, int, bool), 0x005E9CE0);
DEFINE_IMPLEMENTATION(bool Receive_Remote_File(const char*, unsigned int, int, bool), 0x005EA220);
DEFINE_IMPLEMENTATION(bool Send_Remote_File(const char*, int, bool, bool), 0x005EA6B0);
DEFINE_IMPLEMENTATION(bool Find_Local_Scenario(const char*, unsigned int, char*, bool, bool), 0x005EAFE0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(MonoClass::MonoClass(), 0x00561720);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(MonoClass::~MonoClass(), 0x00561760);
DEFINE_IMPLEMENTATION(void MonoClass::Pan(int), 0x00561790);
DEFINE_IMPLEMENTATION(void MonoClass::Sub_Window(int, int, int, int), 0x005617C0);
DEFINE_IMPLEMENTATION(void MonoClass::Set_Cursor(int, int), 0x00561820);
DEFINE_IMPLEMENTATION(void MonoClass::Clear(), 0x00561870);
DEFINE_IMPLEMENTATION(void MonoClass::Fill_Attrib(int, int, int, int, MonoClass::MonoAttribute), 0x005618B0);
DEFINE_IMPLEMENTATION(void MonoClass::Scroll(int), 0x00561910);
DEFINE_IMPLEMENTATION(void MonoClass::Printf(char const*, ...), 0x00561940);
DEFINE_IMPLEMENTATION(void MonoClass::Printf(int, ...), 0x005619C0);
DEFINE_IMPLEMENTATION(void MonoClass::Print(char const*), 0x00561A40);
DEFINE_IMPLEMENTATION(void MonoClass::Set_Default_Attribute(MonoClass::MonoAttribute), 0x00561A80);
DEFINE_IMPLEMENTATION(void MonoClass::Text_Print(char const*, int, int, MonoClass::MonoAttribute), 0x00561AB0);
DEFINE_IMPLEMENTATION(void MonoClass::Text_Print(int, int, int, MonoClass::MonoAttribute), 0x00561B50);
DEFINE_IMPLEMENTATION(void MonoClass::Print(int), 0x00561C00);
DEFINE_IMPLEMENTATION(void MonoClass::View(), 0x00561C50);

DEFINE_IMPLEMENTATION(void Play_Movie(const char*, ThemeType, bool, bool, bool), 0x00563670);
DEFINE_IMPLEMENTATION(void Play_Movie(VQType, ThemeType, bool, bool), 0x005639A0);
DEFINE_IMPLEMENTATION(void Play_Fullscreen_Movie(const char*, ThemeType), 0x005638A0);
DEFINE_IMPLEMENTATION(void Play_Ingame_Movie(const char*), 0x00563A30);
DEFINE_IMPLEMENTATION(void Play_Ingame_Movie(VQType), 0x00563B00);
DEFINE_IMPLEMENTATION(void End_Ingame_Movie(), 0x00563C40);

DEFINE_IMPLEMENTATION(void Draw_Shape(Surface&, ConvertClass&, const ShapeSet*, int, const Point2D&, const Rect&, ShapeFlags_Type, const char*, int, ZGradientType, int, const ShapeSet*, int, Point2D), 0x0047C780);

DEFINE_IMPLEMENTATION(int Base64_Encode(const void*, int, void*, int), 0x004208B0);
DEFINE_IMPLEMENTATION(int Base64_Decode(const void*, int, void*, int), 0x004209D0);

DEFINE_IMPLEMENTATION(int __fastcall LCW_Compress(void const*, void*, int), 0x004FD210);
DEFINE_IMPLEMENTATION(int __fastcall LCW_Uncompress(void const*, void*, unsigned long), 0x004FD020);

DEFINE_IMPLEMENTATION(const char* Fetch_String(ULONG), 0x00472350);
DEFINE_IMPLEMENTATION(HGLOBAL Fetch_Resource(const char*, const char*), 0x00472490);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(DirectSoundAudioClass::DirectSoundAudioClass(), 0x00487A20);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(DirectSoundAudioClass::~DirectSoundAudioClass(), 0x00487B20);
DEFINE_IMPLEMENTATION(bool DirectSoundAudioClass::Init(HWND, int, bool, int), 0x00487C50);
DEFINE_IMPLEMENTATION(void DirectSoundAudioClass::End(), 0x00488380);
DEFINE_IMPLEMENTATION(void DirectSoundAudioClass::Stop_Sample(int), 0x00488540);
DEFINE_IMPLEMENTATION(bool DirectSoundAudioClass::Sample_Status(int), 0x00488640);
DEFINE_IMPLEMENTATION(bool DirectSoundAudioClass::Is_Sample_Playing(const void*), 0x00488730);
DEFINE_IMPLEMENTATION(void DirectSoundAudioClass::Stop_Sample_Playing(const void*), 0x00488780);
DEFINE_IMPLEMENTATION(int DirectSoundAudioClass::Play_Sample(const void*, int, int), 0x00488960);
DEFINE_IMPLEMENTATION(int DirectSoundAudioClass::File_Stream_Sample_Vol(char const*, int, bool), 0x00489850);
DEFINE_IMPLEMENTATION(void DirectSoundAudioClass::Fade_Sample(int, int), 0x0048A430);
DEFINE_IMPLEMENTATION(int DirectSoundAudioClass::Get_Playing_Sample_Handle(const void*), 0x0048A4D0);
DEFINE_IMPLEMENTATION(bool DirectSoundAudioClass::Lock_Global_Mutex(), 0x00489140);
DEFINE_IMPLEMENTATION(bool DirectSoundAudioClass::Unlock_Global_Mutex(), 0x00489160);
DEFINE_IMPLEMENTATION(bool DirectSoundAudioClass::Lock_Mutex(), 0x00489170);
DEFINE_IMPLEMENTATION(bool DirectSoundAudioClass::Unlock_Mutex(), 0x00489240);
DEFINE_IMPLEMENTATION(bool DirectSoundAudioClass::Set_Primary_Buffer_Format(void), 0x00489D70);
DEFINE_IMPLEMENTATION(void DirectSoundAudioClass::Restore_Sound_Buffers(void), 0x00489DA0);
DEFINE_IMPLEMENTATION(int DirectSoundAudioClass::Adjust_Volume_All(int), 0x00489F20);
DEFINE_IMPLEMENTATION(int DirectSoundAudioClass::Set_Volume_All(int), 0x00489E30);
DEFINE_IMPLEMENTATION(void DirectSoundAudioClass::Set_Handle_Volume(int, int), 0x0048A030);
DEFINE_IMPLEMENTATION(void DirectSoundAudioClass::Set_Sample_Volume(const void*, int), 0x0048A120);
DEFINE_IMPLEMENTATION(void DirectSoundAudioClass::sub_48A250(int, int), 0x0048A250);
DEFINE_IMPLEMENTATION(void DirectSoundAudioClass::sub_48A340(int), 0x0048A340);
DEFINE_IMPLEMENTATION(bool DirectSoundAudioClass::Start_Primary_Sound_Buffer(bool), 0x0048A520);
DEFINE_IMPLEMENTATION(void DirectSoundAudioClass::Stop_Primary_Sound_Buffer(), 0x0048A600);
DEFINE_IMPLEMENTATION(void DirectSoundAudioClass::Sound_Callback(), 0x00489A40);
DEFINE_IMPLEMENTATION(void __cdecl sosCODECInitStream(_SOS_COMPRESS_INFO*), 0x006B2B40);
DEFINE_IMPLEMENTATION(void __cdecl sosCODEC2InitStream(_SOS_COMPRESS_INFO_2*), 0x006B2680);
DEFINE_IMPLEMENTATION(int __cdecl sosCODECDecompressData(_SOS_COMPRESS_INFO*, int16_t), 0x006B2B62);
DEFINE_IMPLEMENTATION(int __cdecl sosCODEC2DecompressData(_SOS_COMPRESS_INFO_2*, int16_t), 0x006B26BC);
DEFINE_IMPLEMENTATION(int Convert_HMI_To_Direct_Sound_Volume(int), 0x004879C0);
void* Audio_Add_Long_To_Pointer(void const* ptr, long size) { return ((void*)((char const*)ptr + size)); }
DEFINE_IMPLEMENTATION(void Print_Sound_Error(char const*, HWND), 0x00489D10);
DEFINE_IMPLEMENTATION(long Simple_Copy(void**, long*, void**, long*, void**, long), 0x0048A690);
DEFINE_IMPLEMENTATION(long Sample_Copy(SampleTrackerType*, void**, long*, void**, long*, void*, long, SCompressType), 0x0048A750);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(PreviewClass::PreviewClass(), 0x005AC010);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(PreviewClass::~PreviewClass(), 0x005AC020);
DEFINE_IMPLEMENTATION(void PreviewClass::Render_Preview(HWND), 0x005AC040);
DEFINE_IMPLEMENTATION(void PreviewClass::Draw_Map(), 0x005AC200);
DEFINE_IMPLEMENTATION(bool PreviewClass::Write_Preview_INI(CCINIClass& ini), 0x005AC7E0);
DEFINE_IMPLEMENTATION(bool PreviewClass::Read_Preview_INI(CCINIClass& ini), 0x005ACA30);
DEFINE_IMPLEMENTATION(bool PreviewClass::Read_PCX_Preview(const char*), 0x005ACCD0);
DEFINE_IMPLEMENTATION(bool PreviewClass::Read_INI_Preview(const char*), 0x005ACE00);
DEFINE_IMPLEMENTATION(PreviewDataStruct* PreviewClass::Create_Paletted_Preview(int, int&), 0x005ACFF0);
DEFINE_IMPLEMENTATION(void PreviewClass::Create_Preview_Surface(PreviewDataStruct*), 0x005AD490);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(VeterancyClass::VeterancyClass(), 0x00664340);
VeterancyClass::VeterancyClass(const NoInitClass& noinit) {}
// DEFINE_IMPLEMENTATION_DESTRUCTOR(VeterancyClass::~VeterancyClass(), 0x00664350);
DEFINE_IMPLEMENTATION(void VeterancyClass::Gain_Experience(int, int), 0x00664360);
DEFINE_IMPLEMENTATION(bool VeterancyClass::Is_Veteran() const, 0x006643A0);
DEFINE_IMPLEMENTATION(bool VeterancyClass::Is_Rookie() const, 0x006643D0);
DEFINE_IMPLEMENTATION(bool VeterancyClass::Is_Dumbass() const, 0x00664400);
DEFINE_IMPLEMENTATION(bool VeterancyClass::Is_Elite() const, 0x00664420);
DEFINE_IMPLEMENTATION(double VeterancyClass::sub_664440(double), 0x00664440);
DEFINE_IMPLEMENTATION(void VeterancyClass::Set_Dumbass(bool), 0x006644B0);
DEFINE_IMPLEMENTATION(void VeterancyClass::Set_Rookie(bool), 0x006644E0);
DEFINE_IMPLEMENTATION(void VeterancyClass::Set_Veteran(bool), 0x006644F0);
DEFINE_IMPLEMENTATION(void VeterancyClass::Set_Elite(bool), 0x00664520);
DEFINE_IMPLEMENTATION(int VeterancyClass::To_Integer(), 0x00664550);
DEFINE_IMPLEMENTATION(void VeterancyClass::From_Integer(int), 0x00664560);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE SuperClass::GetClassID(CLSID*), 0x0060C750);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE SuperClass::Load(IStream*), 0x0060C790);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE SuperClass::Save(IStream*, BOOL), 0x0060C7E0);
DEFINE_IMPLEMENTATION(int STDMETHODCALLTYPE SuperClass::What_Am_I(), 0x0060CBA0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(SuperClass::SuperClass(), 0x0060B2C0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(SuperClass::SuperClass(const SuperWeaponTypeClass *, HouseClass *), 0x0060B360);
SuperClass::SuperClass(const NoInitClass& x) : Control(x) { *((unsigned long*)this) = (unsigned long)0x006D73D8; *((unsigned long*)this + 1) = (unsigned long)0x006D73BC; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(SuperClass::~SuperClass(), 0x0060B4C0);
DEFINE_IMPLEMENTATION(void SuperClass::Detach(AbstractClass*, bool), 0x0060C800);
DEFINE_IMPLEMENTATION(RTTIType SuperClass::Fetch_RTTI() const, 0x0060CBB0);
DEFINE_IMPLEMENTATION(int SuperClass::Get_Object_Size(bool) const, 0x0060CBC0);
DEFINE_IMPLEMENTATION(void SuperClass::Object_CRC(CRCEngine&) const, 0x0060C820);
DEFINE_IMPLEMENTATION(bool SuperClass::AI(bool), 0x0060BBD0);
DEFINE_IMPLEMENTATION(bool SuperClass::Suspend(bool), 0x0060B5C0);
DEFINE_IMPLEMENTATION(bool SuperClass::Enable(bool, bool, bool), 0x0060B6B0);
DEFINE_IMPLEMENTATION(void SuperClass::Forced_Charge(bool), 0x0060BE40);
DEFINE_IMPLEMENTATION(bool SuperClass::Remove(), 0x0060B830);
DEFINE_IMPLEMENTATION(bool SuperClass::Recharge(bool), 0x0060B860);
DEFINE_IMPLEMENTATION(void SuperClass::Impatient_Click() const, 0x0060BE20);
DEFINE_IMPLEMENTATION(int SuperClass::Anim_Stage() const, 0x0060BD10);
DEFINE_IMPLEMENTATION(bool SuperClass::Discharged(bool, Cell&), 0x0060B8E0);
DEFINE_IMPLEMENTATION(const char* SuperClass::Ready_String() const, 0x0060BEC0);
DEFINE_IMPLEMENTATION(bool SuperClass::Can_Place() const, 0x0060BF40);
DEFINE_IMPLEMENTATION(bool SuperClass::Is_Powered() const, 0x0060BEB0);
DEFINE_IMPLEMENTATION(bool SuperClass::Needs_Redraw() const, 0x0060C730);
DEFINE_IMPLEMENTATION(void SuperClass::Place(Cell*, bool), 0x0060BF70);
char const* SuperClass::Name() const { return Class->Name(); }

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE SuperWeaponTypeClass::GetClassID(CLSID*), 0x0060D100);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE SuperWeaponTypeClass::Load(IStream*), 0x0060D140);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE SuperWeaponTypeClass::Save(IStream*, BOOL), 0x0060D200);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(SuperWeaponTypeClass::SuperWeaponTypeClass(const char *), AbstractTypeClass, 0x0060CF70);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(SuperWeaponTypeClass::SuperWeaponTypeClass(const NoInitClass &), AbstractTypeClass, 0x0060D060);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(SuperWeaponTypeClass::~SuperWeaponTypeClass(), 0x0060D090);
DEFINE_IMPLEMENTATION(RTTIType SuperWeaponTypeClass::Fetch_RTTI() const, 0x0060D220);
DEFINE_IMPLEMENTATION(int SuperWeaponTypeClass::Get_Object_Size(bool) const, 0x0060D230);
DEFINE_IMPLEMENTATION(void SuperWeaponTypeClass::Object_CRC(CRCEngine&) const, 0x0060D240);
DEFINE_IMPLEMENTATION(int SuperWeaponTypeClass::Fetch_Heap_ID() const, 0x0060D2E0);
DEFINE_IMPLEMENTATION(bool SuperWeaponTypeClass::Read_INI(CCINIClass&), 0x0060D2F0);
DEFINE_IMPLEMENTATION(ActionType SuperWeaponTypeClass::What_Action(const Cell&, ObjectClass*) const, 0x0060D6C0);
DEFINE_IMPLEMENTATION(const SuperWeaponTypeClass* SuperWeaponTypeClass::From_Action(ActionType), 0x0060D5F0);

DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE ConnectionPointClass::QueryInterface(REFIID, LPVOID*), 0x0046F500);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE ConnectionPointClass::AddRef(), 0x0046F570);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE ConnectionPointClass::Release(), 0x0046F590);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE ConnectionPointClass::GetConnectionInterface(IID*), 0x0046F620);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE ConnectionPointClass::GetConnectionPointContainer(IConnectionPointContainer**), 0x0046F660);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE ConnectionPointClass::Advise(IUnknown*, DWORD*), 0x0046F680);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE ConnectionPointClass::Unadvise(DWORD), 0x0046F750);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE ConnectionPointClass::EnumConnections(IEnumConnections**), 0x0046F7B0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(ConnectionPointClass::ConnectionPointClass(REFIID, IUnknown *), 0x0046F8C0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(ConnectionPointClass::~ConnectionPointClass(), 0x0046F920);

DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE EnumConnectionsClass::QueryInterface(REFIID, LPVOID*), 0x0046EFD0);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE EnumConnectionsClass::AddRef(), 0x0046F040);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE EnumConnectionsClass::Release(), 0x0046F060);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE EnumConnectionsClass::Next(ULONG, LPCONNECTDATA, ULONG*), 0x0046F100);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE EnumConnectionsClass::Skip(ULONG), 0x0046F1B0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE EnumConnectionsClass::Reset(), 0x0046F1D0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE EnumConnectionsClass::Clone(IEnumConnections**), 0x0046F1E0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(EnumConnectionsClass::EnumConnectionsClass(const DynamicVectorClass<CONNECTDATA> &), 0x0046F300);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(EnumConnectionsClass::EnumConnectionsClass(const EnumConnectionsClass &), 0x0046F3D0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(EnumConnectionsClass::~EnumConnectionsClass(), 0x0046F4A0);

DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE EnumConnectionPointsClass::QueryInterface(REFIID, LPVOID*), 0x0046F970);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE EnumConnectionPointsClass::AddRef(), 0x0046F9E0);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE EnumConnectionPointsClass::Release(), 0x0046FA00);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE EnumConnectionPointsClass::Next(ULONG, LPCONNECTIONPOINT*, ULONG*), 0x0046FAA0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE EnumConnectionPointsClass::Skip(ULONG), 0x0046FB40);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE EnumConnectionPointsClass::Reset(), 0x0046FB60);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE EnumConnectionPointsClass::Clone(IEnumConnectionPoints**), 0x0046FB70);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(EnumConnectionPointsClass::EnumConnectionPointsClass(), 0x0046FC70);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(EnumConnectionPointsClass::EnumConnectionPointsClass(const DynamicVectorClass<LPCONNECTIONPOINT> &), 0x0046FD30);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(EnumConnectionPointsClass::~EnumConnectionPointsClass(), 0x0046FE00);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(DropshipLoadoutClass::DropshipLoadoutClass(), 0x00484040);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(DropshipLoadoutClass::~DropshipLoadoutClass(), 0x00484060);
DEFINE_IMPLEMENTATION(bool DropshipLoadoutClass::Add(TechnoTypeClass*), 0x00484070);
DEFINE_IMPLEMENTATION(bool DropshipLoadoutClass::Remove(int), 0x00484140);
DEFINE_IMPLEMENTATION(void DropshipLoadoutClass::Remove_All(), 0x00484210);
DEFINE_IMPLEMENTATION(void DropshipLoadoutClass::Load(), 0x00484240);
DEFINE_IMPLEMENTATION(TechnoTypeClass* DropshipLoadoutClass::Fetch(int), 0x00484270);
DEFINE_IMPLEMENTATION(int Dropship_Get_Allowable_Index(TechnoTypeClass*), 0x00484280);
DEFINE_IMPLEMENTATION(void Dropship_Draw_Text(int, int, XSurface*, Point2D*, char*, bool, ConvertClass*, Blitter*), 0x00486CE0);
DEFINE_IMPLEMENTATION(void Dropship_Draw_Info_Text(XSurface*, ConvertClass*, TechnoTypeClass*, bool), 0x00486EC0);
DEFINE_IMPLEMENTATION(void Dropship_Loadout(), 0x004842C0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(HouseClass::HouseStaticClass::HouseStaticClass(), 0x004BBC00);
HouseClass::HouseStaticClass::HouseStaticClass(const HouseClass::HouseStaticClass& that) {}
HouseClass::HouseStaticClass::HouseStaticClass(const NoInitClass& noinit) {}
HouseClass::HouseStaticClass::~HouseStaticClass() {}
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE HouseClass::QueryInterface(REFIID, LPVOID*), 0x004BB020);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE HouseClass::AddRef(), 0x004CBC10);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE HouseClass::Release(), 0x004CBC20);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE HouseClass::GetClassID(CLSID*), 0x004C5320);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE HouseClass::Load(IStream*), 0x004C4A00);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE HouseClass::Save(IStream*, BOOL), 0x004C5050);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE HouseClass::ID_Number(), 0x004BB400);
DEFINE_IMPLEMENTATION(BSTR STDMETHODCALLTYPE HouseClass::Name(), 0x004BB140);
DEFINE_IMPLEMENTATION(IApplication* STDMETHODCALLTYPE HouseClass::Get_Application(), 0x004BB120);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE HouseClass::Available_Money(), 0x004BB180);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE HouseClass::Available_Storage(), 0x004BB1A0);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE HouseClass::Power_Output(), 0x004BB1C0);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE HouseClass::Power_Drain(), 0x004BB1D0);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE HouseClass::Category_Quantity(CategoryType), 0x004BB1E0);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE HouseClass::Category_Power(CategoryType), 0x004BB2A0);
DEFINE_IMPLEMENTATION(Cell STDMETHODCALLTYPE HouseClass::Base_Center(), 0x004BB380);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE HouseClass::Fire_Sale(), 0x004C3450);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE HouseClass::All_To_Hunt(), 0x004C34C0);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE HouseClass::Apparent_Category_Quantity(CategoryType), 0x004BB240);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE HouseClass::Apparent_Category_Power(CategoryType), 0x004BB310);
DEFINE_IMPLEMENTATION(Cell STDMETHODCALLTYPE HouseClass::Apparent_Base_Center(), 0x004BB3C0);
DEFINE_IMPLEMENTATION(bool STDMETHODCALLTYPE HouseClass::Is_Powered(), 0x004BB100);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE HouseClass::EnumConnectionPoints(IEnumConnectionPoints**), 0x004C4350);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE HouseClass::FindConnectionPoint(REFIID, IConnectionPoint**), 0x004C43B0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(HouseClass::HouseClass(const HouseTypeClass *), AbstractClass, 0x004BA0B0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(HouseClass::HouseClass(const NoInitClass &), AbstractClass, 0x004B9EF0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(HouseClass::~HouseClass(), 0x004BB6B0);
DEFINE_IMPLEMENTATION(void HouseClass::Detach(AbstractClass*, bool), 0x004BEFF0);
DEFINE_IMPLEMENTATION(RTTIType HouseClass::Fetch_RTTI() const, 0x004CBC30);
DEFINE_IMPLEMENTATION(int HouseClass::Get_Object_Size(bool) const, 0x004C5360);
DEFINE_IMPLEMENTATION(void HouseClass::Object_CRC(CRCEngine&) const, 0x004C4760);
DEFINE_IMPLEMENTATION(int HouseClass::Fetch_Heap_ID() const, 0x004CBC40);
DEFINE_IMPLEMENTATION(void HouseClass::AI(), 0x004BC5E0);
DEFINE_IMPLEMENTATION(bool HouseClass::Can_Make_Money() const, 0x004BAED0);
DEFINE_IMPLEMENTATION(float HouseClass::Tiberium_Fraction() const, 0x004BB410);
DEFINE_IMPLEMENTATION(DiffType HouseClass::Assign_Handicap(DiffType), 0x004BB460);
DEFINE_IMPLEMENTATION(int HouseClass::Can_Build(const ObjectTypeClass*, bool, bool) const, 0x004BBC20);
DEFINE_IMPLEMENTATION(FactoryClass* HouseClass::Factory_Building_This(const ObjectTypeClass*) const, 0x004BC560);
DEFINE_IMPLEMENTATION(void HouseClass::Super_Weapon_Handler(), 0x004BD2E0);
DEFINE_IMPLEMENTATION(void HouseClass::Attacked(BuildingClass*), 0x004BD3C0);
DEFINE_IMPLEMENTATION(void HouseClass::Tiberium_Harvested(unsigned, TiberiumType), 0x004BD590);
DEFINE_IMPLEMENTATION(void HouseClass::Weed_Harvested(unsigned, TiberiumType), 0x004BD6F0);
DEFINE_IMPLEMENTATION(float HouseClass::Weed_Fraction() const, 0x004BD730);
DEFINE_IMPLEMENTATION(void HouseClass::Spend_Money(unsigned), 0x004BD770);
DEFINE_IMPLEMENTATION(void HouseClass::Refund_Money(unsigned), 0x004BD900);
DEFINE_IMPLEMENTATION(void HouseClass::Silo_Redraw_Check(long, long), 0x004BD920);
DEFINE_IMPLEMENTATION(bool HouseClass::Is_Ally(HousesType) const, 0x004BD9E0);
DEFINE_IMPLEMENTATION(bool HouseClass::Is_Ally(const HouseClass*) const, 0x004BDA20);
DEFINE_IMPLEMENTATION(bool HouseClass::Is_Ally(const ObjectClass*) const, 0x004BDA60);
DEFINE_IMPLEMENTATION(bool HouseClass::Is_Ally(const AbstractClass*) const, 0x004BDAC0);
DEFINE_IMPLEMENTATION(void HouseClass::Make_Ally(HousesType), 0x004BDB30);
DEFINE_IMPLEMENTATION(void HouseClass::Make_Ally(HouseClass*), 0x004BDB50);
DEFINE_IMPLEMENTATION(void HouseClass::Make_Enemy(HousesType), 0x004BDE80);
DEFINE_IMPLEMENTATION(void HouseClass::Make_Enemy(HouseClass*), 0x004BDEA0);
DEFINE_IMPLEMENTATION(TypeList<const TeamTypeClass*> HouseClass::Suggested_New_Team(bool), 0x004BE0C0);
DEFINE_IMPLEMENTATION(void HouseClass::Adjust_Threat(int, int), 0x004BE190);
DEFINE_IMPLEMENTATION(ProdFailType HouseClass::Begin_Production(RTTIType, int, bool), 0x004BE200);
DEFINE_IMPLEMENTATION(ProdFailType HouseClass::Suspend_Production(RTTIType), 0x004BE5D0);
DEFINE_IMPLEMENTATION(ProdFailType HouseClass::Abandon_Production(RTTIType, int), 0x004BE6A0);
DEFINE_IMPLEMENTATION(bool HouseClass::Special_Weapon_AI(SuperWeaponType), 0x004BE8A0);
DEFINE_IMPLEMENTATION(bool HouseClass::Place_Special_Blast(SuperWeaponType, Cell&), 0x004BE9E0);
DEFINE_IMPLEMENTATION(bool HouseClass::Place_Object(RTTIType, Cell&), 0x004BEA10);
DEFINE_IMPLEMENTATION(void HouseClass::Just_Built(TechnoClass*), 0x004BED80);
DEFINE_IMPLEMENTATION(bool HouseClass::Manual_Place(BuildingClass*, BuildingClass*), 0x004BEEA0);
DEFINE_IMPLEMENTATION(void HouseClass::Clobber_All(), 0x004BEF60);
DEFINE_IMPLEMENTATION(bool HouseClass::Does_Enemy_Building_Exist(StructType) const, 0x004BF100);
DEFINE_IMPLEMENTATION(const TechnoTypeClass* HouseClass::Suggest_New_Object(RTTIType, bool) const, 0x004BF180);
DEFINE_IMPLEMENTATION(bool HouseClass::Flag_Remove(AbstractClass*, bool), 0x004BF240);
DEFINE_IMPLEMENTATION(bool HouseClass::Flag_Attach(Cell&, bool), 0x004BF370);
DEFINE_IMPLEMENTATION(bool HouseClass::Flag_Attach(UnitClass*, bool), 0x004BF470);
DEFINE_IMPLEMENTATION(void HouseClass::MPlayer_Defeated(), 0x004BF4C0);
DEFINE_IMPLEMENTATION(void HouseClass::Blowup_All(), 0x004BF910);
DEFINE_IMPLEMENTATION(bool HouseClass::Flag_To_Die(), 0x004BFB00);
DEFINE_IMPLEMENTATION(bool HouseClass::Flag_To_Win(bool), 0x004BFC50);
DEFINE_IMPLEMENTATION(bool HouseClass::Flag_To_Lose(bool), 0x004BFE00);
// 004BFFB0
DEFINE_IMPLEMENTATION(void HouseClass::Init_Data(PlayerColorType, HousesType, int), 0x004BFFF0);
DEFINE_IMPLEMENTATION(float HouseClass::Power_Fraction() const, 0x004C0020);
DEFINE_IMPLEMENTATION(void HouseClass::Sell_Wall(Cell&, bool), 0x004C0070);
DEFINE_IMPLEMENTATION(const BuildingTypeClass* HouseClass::Suggest_New_Building() const, 0x004C0220);
DEFINE_IMPLEMENTATION(BuildingClass* HouseClass::Find_Building(StructType, ZoneType) const, 0x004C0240);
DEFINE_IMPLEMENTATION(Coord HouseClass::Find_Build_Location(BuildingClass*) const, 0x004C0310);
DEFINE_IMPLEMENTATION(void HouseClass::Recalc_Center(), 0x004C0340);
DEFINE_IMPLEMENTATION(int HouseClass::Expert_AI(), 0x004C0630);
DEFINE_IMPLEMENTATION(UrgencyType HouseClass::Check_Fire_Sale() const, 0x004C09D0);
DEFINE_IMPLEMENTATION(UrgencyType HouseClass::Check_Raise_Money() const, 0x004C0A40);
DEFINE_IMPLEMENTATION(bool HouseClass::AI_Fire_Sale(UrgencyType), 0x004C0CC0);
DEFINE_IMPLEMENTATION(bool HouseClass::AI_Raise_Money(UrgencyType), 0x004C0CF0);
DEFINE_IMPLEMENTATION(int HouseClass::AI_Building(), 0x004C10E0);
DEFINE_IMPLEMENTATION(int HouseClass::AI_Unit(), 0x004C1650);
DEFINE_IMPLEMENTATION(int HouseClass::AI_Infantry(), 0x004C1A30);
DEFINE_IMPLEMENTATION(int HouseClass::AI_Aircraft(), 0x004C1D40);
DEFINE_IMPLEMENTATION(void HouseClass::Production_Begun(const TechnoClass*), 0x004C2050);
DEFINE_IMPLEMENTATION(void HouseClass::Tracking_Remove(const TechnoClass*), 0x004C2060);
DEFINE_IMPLEMENTATION(void HouseClass::Tracking_Add(const TechnoClass*), 0x004C2190);
DEFINE_IMPLEMENTATION(int* HouseClass::Factory_Counter(RTTIType), 0x004C2330);
DEFINE_IMPLEMENTATION(void HouseClass::Active_Remove(const TechnoClass*), 0x004C23B0);
DEFINE_IMPLEMENTATION(void HouseClass::Active_Add(const TechnoClass*), 0x004C2450);
DEFINE_IMPLEMENTATION(ZoneType HouseClass::Which_Zone(Coord&) const, 0x004C24F0);
DEFINE_IMPLEMENTATION(ZoneType HouseClass::Which_Zone(const ObjectClass*) const, 0x004C2660);
DEFINE_IMPLEMENTATION(ZoneType HouseClass::Which_Zone(Cell&) const, 0x004C26A0);
DEFINE_IMPLEMENTATION(Cell HouseClass::Zone_Cell(ZoneType) const, 0x004C26E0);
DEFINE_IMPLEMENTATION(Cell HouseClass::Where_To_Go(const FootClass*) const, 0x004C2A20);
DEFINE_IMPLEMENTATION(AbstractClass* HouseClass::Find_Juicy_Target(Coord&) const, 0x004C2B20);
DEFINE_IMPLEMENTATION(FactoryClass* HouseClass::Fetch_Factory(RTTIType) const, 0x004C2CA0);
DEFINE_IMPLEMENTATION(void HouseClass::Set_Factory(RTTIType, FactoryClass*), 0x004C2D20);
DEFINE_IMPLEMENTATION(int HouseClass::Factory_Count(RTTIType) const, 0x004C2DB0);
// 004C2E40
DEFINE_IMPLEMENTATION(void HouseClass::Read_INI(CCINIClass&), 0x004C2F10);
// 004C31B0
DEFINE_IMPLEMENTATION(void HouseClass::Write_INI(CCINIClass&) const, 0x004C3230);
DEFINE_IMPLEMENTATION(bool HouseClass::Is_Allowed_To_Ally(HouseClass*) const, 0x004C3550);
DEFINE_IMPLEMENTATION(void HouseClass::Adjust_Power(int), 0x004C3710);
DEFINE_IMPLEMENTATION(void HouseClass::Adjust_Drain(int), 0x004C3880);
DEFINE_IMPLEMENTATION(void HouseClass::Update_Spied_Power_Plants(), 0x004C39E0);
DEFINE_IMPLEMENTATION(Cell HouseClass::Find_Cell_In_Zone(const TechnoClass*, ZoneType) const, 0x004C3A60);
DEFINE_IMPLEMENTATION(Cell HouseClass::Random_Cell_In_Zone(ZoneType) const, 0x004C3A80);
DEFINE_IMPLEMENTATION(void HouseClass::Make_Ally(TechnoClass*), 0x004C3F80);
DEFINE_IMPLEMENTATION(void HouseClass::Make_Enemy(TechnoClass*), 0x004C3FA0);
// 004C3FC0
// 004C40F0
// 004C4150
DEFINE_IMPLEMENTATION(Coord* HouseClass::Waypoint_Coord(Cell&), 0x004C4210);
DEFINE_IMPLEMENTATION(bool HouseClass::Place_Waypoint_At(Coord&, int&, bool&), 0x004C42C0);
// 004C4450
// 004C45D0
// 004C5320
// 004C5360
// 004C5370
// 004C53C0
// 004C5510
// 004C56A0
DEFINE_IMPLEMENTATION(void HouseClass::Add_Anger(int, HouseClass*), 0x004C5770);
// 004C5840
DEFINE_IMPLEMENTATION(void HouseClass::Begin_Construction(), 0x004C5880);
DEFINE_IMPLEMENTATION(TechnoTypeClass* HouseClass::Get_First_Ownable(TypeList<TechnoTypeClass*>&) const, 0x004C58B0);
DEFINE_IMPLEMENTATION(bool HouseClass::Has_Prerequisites(const TechnoTypeClass*, DynamicVectorClass<BuildingTypeClass*>&, int) const, 0x004C5920);
// 004C5BB0
// 004C68E0
// 004C6930
DEFINE_IMPLEMENTATION(Cell HouseClass::Find_Build_Location(BuildingTypeClass*, int(__fastcall*)(int, Cell&, int, int), int) const, 0x004C6A10);
// 004C7300
// 004C7310
// 004C7320
// 004C7470
// 004C74F0
DEFINE_IMPLEMENTATION(bool HouseClass::AI_Build_Defense(int, DynamicVectorClass<Cell>*), 0x004C7690);
// 004C83F0
// 004C85A0
// 004C8750
// 004C8900
DEFINE_IMPLEMENTATION(void HouseClass::AI_Build_Wall(), 0x004C8920);
// 004C93F0
DEFINE_IMPLEMENTATION(void HouseClass::Update_Radars(), 0x004C9560);
// 004C96A0
// 004C96F0
// 004C9730
DEFINE_IMPLEMENTATION(void HouseClass::Update_Factories(RTTIType), 0x004C9740);
DEFINE_IMPLEMENTATION(void HouseClass::Update_Radar_Spied(HouseClass*), 0x004C98E0);
DEFINE_IMPLEMENTATION(void HouseClass::Clear_Anger(HouseClass*), 0x004C9990);
DEFINE_IMPLEMENTATION(void HouseClass::Recalc_Threat_Regions(), 0x004C99D0);
// 004C9B80
// 004C9BC0
// 004C9CB0
DEFINE_IMPLEMENTATION(void HouseClass::AI_Super_Weapon_Handler(), 0x004C9EA0);
DEFINE_IMPLEMENTATION(void HouseClass::Super_Weapon_Ion_Cannon(SuperClass*), 0x004C9FB0);
DEFINE_IMPLEMENTATION(void HouseClass::Super_Weapon_Hunter_Seeker(SuperClass*), 0x004CA450);
DEFINE_IMPLEMENTATION(void HouseClass::Super_Weapon_Multi_Missile(SuperClass*), 0x004CA4A0);
DEFINE_IMPLEMENTATION(void HouseClass::Super_Weapon_Chem_Missile(SuperClass*), 0x004CA600);
// 004CA760
DEFINE_IMPLEMENTATION(void HouseClass::AI_Takeover(), 0x004CA880);
// 004CB2D0
// 004CB5B0
// 004CB720
// 004CB950
DEFINE_IMPLEMENTATION(bool HouseClass::Is_Player_Control() const, 0x004CB950);
DEFINE_IMPLEMENTATION(bool HouseClass::Is_Human_Player() const, 0x004CB990);
// 004CB9C0
DEFINE_IMPLEMENTATION(void HouseClass::Init_Remap_Color(), 0x004CBAA0);
DEFINE_IMPLEMENTATION(void HouseClass::Super_Weapon_Drop_Pods(SuperClass*), 0x004CBB30);
// 004CBC30
// 004CBC40
DEFINE_IMPLEMENTATION(void HouseClass::One_Time(), 0x004BB450);
DEFINE_IMPLEMENTATION(void HouseClass::Computer_Paranoid(), 0x004C3630);
DEFINE_IMPLEMENTATION(void HouseClass::Read_Scenario_INI(CCINIClass&), 0x004C2E40);
DEFINE_IMPLEMENTATION(void HouseClass::Write_Scenario_INI(CCINIClass&), 0x004C31B0);
DEFINE_IMPLEMENTATION(HouseClass* House_From_HousesType(HousesType), 0x004C4730);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(ThemeClass::ThemeClass(), 0x00643D60);
ThemeClass::~ThemeClass() { Clear(); }
DEFINE_IMPLEMENTATION(ThemeType ThemeClass::From_Name(const char*) const, 0x00644390);
DEFINE_IMPLEMENTATION(ThemeType ThemeClass::Next_Song(ThemeType) const, 0x00643E80);
DEFINE_IMPLEMENTATION(bool ThemeClass::Is_Allowed(ThemeType) const, 0x00644300);
DEFINE_IMPLEMENTATION(const char* ThemeClass::Base_Name(ThemeType) const, 0x00643D40);
DEFINE_IMPLEMENTATION(const char* ThemeClass::Full_Name(ThemeType) const, 0x00643DA0);
DEFINE_IMPLEMENTATION(int ThemeClass::Play_Song(ThemeType), 0x00643FE0);
DEFINE_IMPLEMENTATION(bool ThemeClass::Still_Playing() const, 0x006442B0);
DEFINE_IMPLEMENTATION(int ThemeClass::Track_Length(ThemeType) const, 0x00644160);
DEFINE_IMPLEMENTATION(void ThemeClass::AI(), 0x00643DC0);
DEFINE_IMPLEMENTATION(void ThemeClass::Queue_Song(ThemeType), 0x00643F20);
DEFINE_IMPLEMENTATION(void ThemeClass::Stop(bool), 0x00644190);
DEFINE_IMPLEMENTATION(void ThemeClass::Suspend(), 0x00644250);
DEFINE_IMPLEMENTATION(void ThemeClass::Clear(), 0x00643C20);
DEFINE_IMPLEMENTATION(void ThemeClass::Set_Volume(int), 0x00644410);
DEFINE_IMPLEMENTATION(int ThemeClass::Process(CCINIClass&), 0x00643AC0);
DEFINE_IMPLEMENTATION(const char* ThemeClass::Theme_File_Name(ThemeType), 0x00644120);
DEFINE_IMPLEMENTATION(void ThemeClass::Scan(), 0x00643C70);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(ThemeClass::ThemeControl::ThemeControl(), 0x006439B0);
ThemeClass::ThemeControl::~ThemeControl() {}
DEFINE_IMPLEMENTATION(bool ThemeClass::ThemeControl::Fill_In(CCINIClass&), 0x006439F0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(IPXInterfaceClass::IPXInterfaceClass(), 0x006A02F0);
IPXInterfaceClass::~IPXInterfaceClass() {}
DEFINE_IMPLEMENTATION(ProtocolEnum IPXInterfaceClass::Get_Protocol(), 0x006A0C20);
DEFINE_IMPLEMENTATION(int IPXInterfaceClass::Protocol_Event_Message(), 0x006A0C30);
DEFINE_IMPLEMENTATION(bool IPXInterfaceClass::Open_Socket(SOCKET), 0x006A05B0);
DEFINE_IMPLEMENTATION(LRESULT IPXInterfaceClass::Message_Handler(HWND, UINT, UINT, LONG), 0x006A08B0);
DEFINE_IMPLEMENTATION(bool IPXInterfaceClass::Get_Network_Card_Address(int, SOCKADDR_IPX*), 0x006A0330);
DEFINE_IMPLEMENTATION(bool IPXInterfaceClass::Get_Network_Card_Address_String(int, char*, int), 0x006A04A0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(UDPInterfaceClass::UDPInterfaceClass(), 0x006A1E70);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(UDPInterfaceClass::~UDPInterfaceClass(), 0x006A1EF0);
DEFINE_IMPLEMENTATION(void UDPInterfaceClass::Broadcast(void*, int), 0x006A2390);
DEFINE_IMPLEMENTATION(void UDPInterfaceClass::Set_Broadcast_Address(void*), 0x006A2090);
DEFINE_IMPLEMENTATION(void UDPInterfaceClass::Clear_Broadcast_Addresses(), 0x006A2030);
DEFINE_IMPLEMENTATION(ProtocolEnum UDPInterfaceClass::Get_Protocol(), 0x006A2730);
DEFINE_IMPLEMENTATION(int UDPInterfaceClass::Protocol_Event_Message(), 0x006A2740);
DEFINE_IMPLEMENTATION(bool UDPInterfaceClass::Open_Socket(SOCKET), 0x006A2130);
DEFINE_IMPLEMENTATION(LRESULT UDPInterfaceClass::Message_Handler(HWND, UINT, UINT, LONG), 0x006A2480);
DEFINE_IMPLEMENTATION(int UDPInterfaceClass::Local_Addresses_Count() const, 0x006A2750);
DEFINE_IMPLEMENTATION(unsigned char* UDPInterfaceClass::Get_Local_Address(int) const, 0x006A2760);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(LoadOptionsClass::LoadOptionsClass(), 0x005047B0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(LoadOptionsClass::~LoadOptionsClass(), 0x00504800);
DEFINE_IMPLEMENTATION(bool LoadOptionsClass::Load_File(const char*), 0x00505980);
DEFINE_IMPLEMENTATION(bool LoadOptionsClass::Save_File(const char*, const char*), 0x005059D0);
DEFINE_IMPLEMENTATION(bool LoadOptionsClass::Delete_File(const char*), 0x00505A20);
DEFINE_IMPLEMENTATION(bool LoadOptionsClass::Read_File(FileEntryClass*, WIN32_FIND_DATA*), 0x00505A40);
DEFINE_IMPLEMENTATION(bool LoadOptionsClass::Load_Dialog(), 0x00504860);
DEFINE_IMPLEMENTATION(bool LoadOptionsClass::Save_Dialog(const char*), 0x00504880);
DEFINE_IMPLEMENTATION(bool LoadOptionsClass::Delete_Dialog(), 0x005048A0);
DEFINE_IMPLEMENTATION(void LoadOptionsClass::Pick_Filename(char*), 0x00505270);
DEFINE_IMPLEMENTATION(void LoadOptionsClass::Clear_List(), 0x005052F0);
DEFINE_IMPLEMENTATION(void LoadOptionsClass::Fill_List(HWND), 0x00505320);
DEFINE_IMPLEMENTATION(bool LoadOptionsClass::Read_Save_Files(), 0x00505840);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(SHAEngine::SHAEngine(), 0x0055A400);
DEFINE_IMPLEMENTATION(int SHAEngine::Result(void*) const, 0x005F1290);
DEFINE_IMPLEMENTATION(void SHAEngine::Hash(void const*, long), 0x005F1210);
DEFINE_IMPLEMENTATION(void SHAEngine::Process_Block(void const*, SHADigest&) const, 0x005F13E0);
DEFINE_IMPLEMENTATION(void SHAEngine::Process_Partial(void const*&, long&), 0x005F1170);

SHAStraw::SHAStraw(bool bypass_sha) : BypassSHA(bypass_sha), SHA() {}
SHAStraw::~SHAStraw() {}
DEFINE_IMPLEMENTATION(int SHAStraw::Get(void*, int), 0x005F17B0);
DEFINE_IMPLEMENTATION(int SHAStraw::Result(void*) const, 0x005F17F0);

SHAPipe::SHAPipe() : SHA() {}
SHAPipe::~SHAPipe() {}
DEFINE_IMPLEMENTATION(int SHAPipe::Put(const void*, int), 0x005F1770);
DEFINE_IMPLEMENTATION(int SHAPipe::Result(void*) const, 0x005F17A0);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE SideClass::GetClassID(CLSID*), 0x005F1BD0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE SideClass::Load(IStream*), 0x005F1C10);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE SideClass::Save(IStream*, BOOL), 0x005F1D00);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(SideClass::SideClass(const char *), 0x005F1A30);
SideClass::SideClass(const NoInitClass& noinit) : AbstractTypeClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D6730; *((unsigned long*)this + 1) = (unsigned long)0x006D6714; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(SideClass::~SideClass(), 0x005F1AD0);
DEFINE_IMPLEMENTATION(RTTIType SideClass::Fetch_RTTI() const, 0x005F1D70);
DEFINE_IMPLEMENTATION(int SideClass::Get_Object_Size(bool) const, 0x005F1D60);
DEFINE_IMPLEMENTATION(void SideClass::Object_CRC(CRCEngine&) const, 0x005F1BB0);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE ScriptClass::GetClassID(CLSID*), 0x005E7A10);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE ScriptClass::Load(IStream*), 0x005E7A50);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE ScriptClass::Save(IStream*, BOOL), 0x005E7AA0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(ScriptClass::ScriptClass(ScriptTypeClass *), 0x005E7820);
ScriptClass::ScriptClass(const NoInitClass& noinit) : AbstractClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D63D0; *((unsigned long*)this + 1) = (unsigned long)0x006D63B0; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(ScriptClass::~ScriptClass(), 0x005E78B0);
DEFINE_IMPLEMENTATION(RTTIType ScriptClass::Fetch_RTTI() const, 0x005E81B0);
DEFINE_IMPLEMENTATION(int ScriptClass::Get_Object_Size(bool) const, 0x005E81C0);
DEFINE_IMPLEMENTATION(void ScriptClass::Object_CRC(CRCEngine&) const, 0x005E7920);
DEFINE_IMPLEMENTATION(ScriptMissionClass ScriptClass::Get_Current_Mission(), 0x005E7940);
DEFINE_IMPLEMENTATION(ScriptMissionClass ScriptClass::Get_Next_Mission(), 0x005E7980);
DEFINE_IMPLEMENTATION(bool ScriptClass::Stop_Script(), 0x005E79C0);
DEFINE_IMPLEMENTATION(bool ScriptClass::Set_Line(int), 0x005E79D0);
DEFINE_IMPLEMENTATION(bool ScriptClass::Next_Mission(), 0x005E79E0);
DEFINE_IMPLEMENTATION(bool ScriptClass::Has_Missions_Remaining() const, 0x005E7A00);
const char* ScriptClass::Name() const { return Class->Name(); }

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE ScriptTypeClass::GetClassID(CLSID*), 0x005E80F0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE ScriptTypeClass::Load(IStream*), 0x005E8130);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE ScriptTypeClass::Save(IStream*, BOOL), 0x005E8170);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(ScriptTypeClass::ScriptTypeClass(const char *), 0x005E7AC0);
ScriptTypeClass::ScriptTypeClass(const NoInitClass& noinit) : AbstractTypeClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D6434; *((unsigned long*)this + 1) = (unsigned long)0x006D6438; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(ScriptTypeClass::~ScriptTypeClass(), 0x005E7B70);
DEFINE_IMPLEMENTATION(RTTIType ScriptTypeClass::Fetch_RTTI() const, 0x005E8250);
DEFINE_IMPLEMENTATION(int ScriptTypeClass::Get_Object_Size(bool) const, 0x005E8260);
DEFINE_IMPLEMENTATION(void ScriptTypeClass::Object_CRC(CRCEngine&) const, 0x005E8190);
DEFINE_IMPLEMENTATION(int ScriptTypeClass::Fetch_Heap_ID() const, 0x005E8270);
DEFINE_IMPLEMENTATION(bool ScriptTypeClass::Read_INI(CCINIClass&), 0x005E7C80);
DEFINE_IMPLEMENTATION(bool ScriptTypeClass::Write_INI(CCINIClass&) const, 0x005E7BE0);
DEFINE_IMPLEMENTATION(void ScriptTypeClass::Read_Scenario_INI(CCINIClass&, bool), 0x005E7D40);
DEFINE_IMPLEMENTATION(void ScriptTypeClass::Write_Scenario_INI(CCINIClass&, bool), 0x005E7EF0);

DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE ObjectClass::Load(IStream*), 0x005866F0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(ObjectClass::ObjectClass(), AbstractClass, 0x005847D0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(ObjectClass::ObjectClass(const NoInitClass &), AbstractClass, 0x005849A0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(ObjectClass::~ObjectClass(), 0x005849C0);
DEFINE_IMPLEMENTATION(bool ObjectClass::operator<(const ObjectClass&) const, 0x005869D0);
DEFINE_IMPLEMENTATION(bool ObjectClass::operator>(const ObjectClass&) const, 0x00586A00);
DEFINE_IMPLEMENTATION(void ObjectClass::Detach(AbstractClass*, bool), 0x00585EF0);
DEFINE_IMPLEMENTATION(void ObjectClass::Object_CRC(CRCEngine&) const, 0x00586A30);
DEFINE_IMPLEMENTATION(bool ObjectClass::Is_Inactive() const, 0x00586E20);
DEFINE_IMPLEMENTATION(Coord ObjectClass::Center_Coord() const, 0x00586D60);
DEFINE_IMPLEMENTATION(bool ObjectClass::On_Ground() const, 0x00587280);
DEFINE_IMPLEMENTATION(bool ObjectClass::In_Air() const, 0x005872A0);
DEFINE_IMPLEMENTATION(void ObjectClass::AI(), 0x00584C10);
DEFINE_IMPLEMENTATION(bool ObjectClass::Is_Players_Army() const, 0x00417400);
DEFINE_IMPLEMENTATION(VisualType ObjectClass::Visual_Character(bool, const HouseClass*), 0x00417410);
DEFINE_IMPLEMENTATION(ShapeSet* const ObjectClass::Get_Image_Data() const, 0x00584BD0);
DEFINE_IMPLEMENTATION(ActionType ObjectClass::What_Action(const ObjectClass*, bool), 0x00584EF0);
DEFINE_IMPLEMENTATION(ActionType ObjectClass::What_Action(const Cell&, bool, bool) const, 0x00584F00);
DEFINE_IMPLEMENTATION(LayerType ObjectClass::In_Which_Layer() const, 0x00584F10);
DEFINE_IMPLEMENTATION(bool ObjectClass::entry_7C() const, 0x005872F0);
DEFINE_IMPLEMENTATION(bool ObjectClass::entry_80() const, 0x00417420);
DEFINE_IMPLEMENTATION(const TechnoTypeClass* ObjectClass::Techno_Type_Class() const, 0x005872C0);
DEFINE_IMPLEMENTATION(const ObjectTypeClass* ObjectClass::Class_Of() const, 0x004A8D90);
DEFINE_IMPLEMENTATION(int ObjectClass::Get_Ownable() const, 0x00584F50);
DEFINE_IMPLEMENTATION(const char* ObjectClass::Full_Name() const, 0x00417430);
DEFINE_IMPLEMENTATION(bool ObjectClass::Can_Repair() const, 0x00584F60);
DEFINE_IMPLEMENTATION(bool ObjectClass::Can_Demolish() const, 0x00584F70);
DEFINE_IMPLEMENTATION(bool ObjectClass::Can_Player_Fire() const, 0x00584F80);
DEFINE_IMPLEMENTATION(bool ObjectClass::Can_Player_Move() const, 0x00584F90);
DEFINE_IMPLEMENTATION(Coord ObjectClass::Target_Coord() const, 0x0040F140);
DEFINE_IMPLEMENTATION(Coord ObjectClass::Docking_Coord() const, 0x0040F170);
DEFINE_IMPLEMENTATION(Coord ObjectClass::Render_Coord() const, 0x0040F1A0);
DEFINE_IMPLEMENTATION(Coord ObjectClass::Fire_Coord(WeaponSlotType) const, 0x00417440);
DEFINE_IMPLEMENTATION(Coord ObjectClass::Exit_Coord() const, 0x0040F1D0);
DEFINE_IMPLEMENTATION(int ObjectClass::Sort_Y() const, 0x005872D0);
DEFINE_IMPLEMENTATION(bool ObjectClass::entry_BC(), 0x005871B0);
DEFINE_IMPLEMENTATION(bool ObjectClass::entry_C0() const, 0x00417480);
DEFINE_IMPLEMENTATION(bool ObjectClass::Limbo(), 0x00585A50);
DEFINE_IMPLEMENTATION(bool ObjectClass::Unlimbo(const Coord&, Dir256), 0x00585BE0);
DEFINE_IMPLEMENTATION(void ObjectClass::Detach_All(bool), 0x00585F30);
DEFINE_IMPLEMENTATION(void ObjectClass::Record_The_Kill(const ObjectClass*), 0x00584FA0);
DEFINE_IMPLEMENTATION(bool ObjectClass::Paradrop(Coord&), 0x005864C0);
DEFINE_IMPLEMENTATION(void ObjectClass::entry_D8(), 0x00584E20);
DEFINE_IMPLEMENTATION(void ObjectClass::Set_Occupy_Bit(Coord&), 0x00586880);
DEFINE_IMPLEMENTATION(void ObjectClass::Clear_Occupy_Bit(Coord&), 0x00586900);
DEFINE_IMPLEMENTATION(void ObjectClass::Delete_Me(), 0x00586DB0);
DEFINE_IMPLEMENTATION(void ObjectClass::Do_Shimmer(), 0x00584FB0);
DEFINE_IMPLEMENTATION(ExitType ObjectClass::Exit_Object(const TechnoClass*), 0x00584FC0);
DEFINE_IMPLEMENTATION(bool ObjectClass::Render(Rect&, bool, bool), 0x00585830);
DEFINE_IMPLEMENTATION(Cell* ObjectClass::Occupy_List(bool) const, 0x005865B0);
DEFINE_IMPLEMENTATION(void ObjectClass::entry_F8(Point2D&, Rect&) const, 0x00417490);
DEFINE_IMPLEMENTATION(void ObjectClass::entry_FC(Point2D&, Rect&) const, 0x004174A0);
DEFINE_IMPLEMENTATION(void ObjectClass::Draw_It(Point2D&, Rect&) const, 0x00559850);
DEFINE_IMPLEMENTATION(void ObjectClass::Placement_Draw_It(Point2D&, Rect&) const, 0x00586D90);
DEFINE_IMPLEMENTATION(void ObjectClass::Hidden(), 0x00584FD0);
DEFINE_IMPLEMENTATION(void ObjectClass::Look(bool, bool), 0x00584FE0);
DEFINE_IMPLEMENTATION(bool ObjectClass::Mark(MarkType), 0x00586400);
DEFINE_IMPLEMENTATION(Rect ObjectClass::entry_114() const, 0x005853B0);
DEFINE_IMPLEMENTATION(Rect ObjectClass::entry_118() const, 0x00585510);
DEFINE_IMPLEMENTATION(void ObjectClass::Draw_Radial_Indicator() const, 0x0040F200);
DEFINE_IMPLEMENTATION(void ObjectClass::Mark_For_Redraw(), 0x00585A30);
DEFINE_IMPLEMENTATION(bool ObjectClass::Active_Click_With(ActionType, ObjectClass*, bool), 0x00584FF0);
DEFINE_IMPLEMENTATION(bool ObjectClass::Active_Click_With(ActionType, Cell&, bool), 0x00585000);
DEFINE_IMPLEMENTATION(void ObjectClass::Clicked_As_Target(int), 0x00585010);
DEFINE_IMPLEMENTATION(bool ObjectClass::Select(), 0x005851D0);
DEFINE_IMPLEMENTATION(void ObjectClass::Unselect(), 0x00585150);
DEFINE_IMPLEMENTATION(bool ObjectClass::In_Range(Coord&, WeaponSlotType) const, 0x00585020);
DEFINE_IMPLEMENTATION(int ObjectClass::Weapon_Range(WeaponSlotType) const, 0x00585030);
DEFINE_IMPLEMENTATION(ResultType ObjectClass::Take_Damage(int&, int, const WarheadTypeClass*, const ObjectClass*, bool, bool), 0x00585FD0);
DEFINE_IMPLEMENTATION(void ObjectClass::Scatter(const Coord&, bool, bool), 0x00585040);
DEFINE_IMPLEMENTATION(bool ObjectClass::Catch_Fire(), 0x00585050);
DEFINE_IMPLEMENTATION(void ObjectClass::Fire_Out(), 0x00585060);
DEFINE_IMPLEMENTATION(int ObjectClass::Value() const, 0x00585070);
DEFINE_IMPLEMENTATION(MissionType ObjectClass::Get_Mission() const, 0x00585080);
DEFINE_IMPLEMENTATION(void ObjectClass::Assign_Mission(MissionType), 0x004174B0);
DEFINE_IMPLEMENTATION(void ObjectClass::Per_Cell_Process(PCPType), 0x004174C0);
DEFINE_IMPLEMENTATION(BuildingClass* const ObjectClass::Who_Can_Build_Me(bool, bool) const, 0x00586640);
DEFINE_IMPLEMENTATION(RadioMessageType ObjectClass::Receive_Message(RadioClass*, RadioMessageType, long&), 0x00585FB0);
DEFINE_IMPLEMENTATION(bool ObjectClass::Revealed(const HouseClass*), 0x005864B0);
DEFINE_IMPLEMENTATION(void ObjectClass::Repair(int), 0x00585090);
DEFINE_IMPLEMENTATION(void ObjectClass::Sell_Back(int), 0x005850A0);
DEFINE_IMPLEMENTATION(void ObjectClass::entry_174(int, int), 0x00587270);
DEFINE_IMPLEMENTATION(void ObjectClass::Move(FacingType), 0x005850B0);
DEFINE_IMPLEMENTATION(MoveType ObjectClass::Can_Enter_Cell(const CellClass*, FacingType, int, const CellClass*, bool), 0x004174D0);
DEFINE_IMPLEMENTATION(MoveType ObjectClass::entry_180(const CellClass*, FacingType, int*, bool*, const CellClass*), 0x004174E0);
DEFINE_IMPLEMENTATION(Coord ObjectClass::Get_Coord() const, 0x0040F210);
DEFINE_IMPLEMENTATION(void ObjectClass::Set_Coord(const Coord&), 0x005870C0);
DEFINE_IMPLEMENTATION(Cell ObjectClass::Get_Cell() const, 0x0040F230);
DEFINE_IMPLEMENTATION(CellClass* ObjectClass::Get_Cell_Ptr() const, 0x005870E0);
DEFINE_IMPLEMENTATION(Cell ObjectClass::Get_Target_Cell() const, 0x00587100);
DEFINE_IMPLEMENTATION(AbstractClass* ObjectClass::Get_Target_Cell_Ptr() const, 0x00587150);
DEFINE_IMPLEMENTATION(int ObjectClass::Get_Height_AGL() const, 0x00586770);
DEFINE_IMPLEMENTATION(void ObjectClass::Set_Height_AGL(int) const, 0x005867B0);
DEFINE_IMPLEMENTATION(int ObjectClass::Get_Height() const, 0x00586760);
DEFINE_IMPLEMENTATION(bool ObjectClass::Attach_Tag(TagClass*), 0x00586570);
DEFINE_IMPLEMENTATION(double ObjectClass::Get_Health_Ratio() const, 0x00586680);
DEFINE_IMPLEMENTATION(void ObjectClass::Set_Health_Ratio(double), 0x005866A0);
DEFINE_IMPLEMENTATION(int ObjectClass::Get_Cell_Height() const, 0x00586730);
DEFINE_IMPLEMENTATION(void ObjectClass::Set_Height(int), 0x00586840);
DEFINE_IMPLEMENTATION(bool ObjectClass::Is_Foot() const, 0x00584BF0);
DEFINE_IMPLEMENTATION(DirType ObjectClass::Direction(AbstractClass*) const, 0x00584B50);
DEFINE_IMPLEMENTATION(int ObjectClass::Distance(AbstractClass*) const, 0x00586B20);
DEFINE_IMPLEMENTATION(int ObjectClass::Distance(const AbstractClass*) const, 0x00586C00);
DEFINE_IMPLEMENTATION(int ObjectClass::Relative_Distance(const AbstractClass*) const, 0x00586CC0);
DEFINE_IMPLEMENTATION(int ObjectClass::Relative_Distance(const Coord&), 0x00586D20);
// 00586E30
// 00586F10
// 00586F90
const char* ObjectClass::Name() const { return Class_Of()->Name(); }

// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(MissionClass::MissionClass(), ObjectClass, 0x00558E40);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(MissionClass::MissionClass(const NoInitClass &), ObjectClass, 0x0063A600);
MissionClass::~MissionClass() {}
DEFINE_IMPLEMENTATION(void MissionClass::Object_CRC(CRCEngine&) const, 0x005597C0);
DEFINE_IMPLEMENTATION(void MissionClass::AI(), 0x00559010);
DEFINE_IMPLEMENTATION(MissionType MissionClass::Get_Mission() const, 0x00559000);
DEFINE_IMPLEMENTATION(void MissionClass::Assign_Mission(MissionType), 0x00559490);
DEFINE_IMPLEMENTATION(bool MissionClass::Commence(), 0x00559450);
DEFINE_IMPLEMENTATION(bool MissionClass::Ready_To_Commence() const, 0x004A8DA0);
DEFINE_IMPLEMENTATION(int MissionClass::Mission_Sleep(), 0x00558E80);
DEFINE_IMPLEMENTATION(int MissionClass::Mission_Harmless(), 0x00558E90);
DEFINE_IMPLEMENTATION(int MissionClass::Mission_Ambush(), 0x00558EA0);
DEFINE_IMPLEMENTATION(int MissionClass::Mission_Attack(), 0x00558EB0);
DEFINE_IMPLEMENTATION(int MissionClass::Mission_Capture(), 0x00558EC0);
DEFINE_IMPLEMENTATION(int MissionClass::Mission_Guard(), 0x00558ED0);
DEFINE_IMPLEMENTATION(int MissionClass::Mission_Guard_Area(), 0x00558EE0);
DEFINE_IMPLEMENTATION(int MissionClass::Mission_Harvest(), 0x00558EF0);
DEFINE_IMPLEMENTATION(int MissionClass::Mission_Hunt(), 0x00558F00);
DEFINE_IMPLEMENTATION(int MissionClass::Mission_Move(), 0x00558F10);
DEFINE_IMPLEMENTATION(int MissionClass::Mission_Retreat(), 0x00558F20);
DEFINE_IMPLEMENTATION(int MissionClass::Mission_Return(), 0x00558F30);
DEFINE_IMPLEMENTATION(int MissionClass::Mission_Stop(), 0x00558F40);
DEFINE_IMPLEMENTATION(int MissionClass::Mission_Unload(), 0x00558F50);
DEFINE_IMPLEMENTATION(int MissionClass::Mission_Enter(), 0x00558F60);
DEFINE_IMPLEMENTATION(int MissionClass::Mission_Construction(), 0x00558F70);
DEFINE_IMPLEMENTATION(int MissionClass::Mission_Deconstruction(), 0x00558F80);
DEFINE_IMPLEMENTATION(int MissionClass::Mission_Repair(), 0x00558F90);
DEFINE_IMPLEMENTATION(int MissionClass::Mission_Missile(), 0x00558FA0);
DEFINE_IMPLEMENTATION(int MissionClass::Mission_Open(), 0x00558FB0);
DEFINE_IMPLEMENTATION(int MissionClass::Mission_Rescue(), 0x00558FC0);
DEFINE_IMPLEMENTATION(int MissionClass::Mission_Patrol(), 0x00558FD0);
DEFINE_IMPLEMENTATION(void MissionClass::Set_Mission(MissionType), 0x00558FE0);
DEFINE_IMPLEMENTATION(void MissionClass::Override_Mission(MissionType, AbstractClass*, AbstractClass*), 0x005594D0);
DEFINE_IMPLEMENTATION(bool MissionClass::Restore_Mission(), 0x00559510);
DEFINE_IMPLEMENTATION(bool MissionClass::Has_Suspended_Mission() const, 0x00559840);
DEFINE_IMPLEMENTATION(const MissionControlClass& MissionClass::Get_Current_Mission_Control() const, 0x00559830);
DEFINE_IMPLEMENTATION(bool MissionClass::Is_Recruitable_Mission(MissionType), 0x00559530);
DEFINE_IMPLEMENTATION(const char* MissionClass::Mission_Name(MissionType), 0x005597A0);
DEFINE_IMPLEMENTATION(MissionType MissionClass::Mission_From_Name(const char*), 0x00559760);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(MissionControlClass::MissionControlClass(), 0x00559550);
DEFINE_IMPLEMENTATION(const char* MissionControlClass::Name() const, 0x00559590);
DEFINE_IMPLEMENTATION(bool MissionControlClass::Read_INI(CCINIClass&), 0x005595B0);

DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE RadioClass::Load(IStream*), 0x005BDAA0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(RadioClass::RadioClass(), 0x005BD850);
RadioClass::RadioClass(const NoInitClass& noinit) : MissionClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D5B80; *((unsigned long*)this + 1) = (unsigned long)0x006D5B64; }
RadioClass::~RadioClass() { Radio = nullptr; }
DEFINE_IMPLEMENTATION(void RadioClass::Detach(AbstractClass*, bool), 0x005BDA30);
DEFINE_IMPLEMENTATION(void RadioClass::Object_CRC(CRCEngine&) const, 0x005BDA60);
DEFINE_IMPLEMENTATION(bool RadioClass::Limbo(), 0x005BD9E0);
DEFINE_IMPLEMENTATION(RadioMessageType RadioClass::Receive_Message(RadioClass*, RadioMessageType, long&), 0x005BD880);
DEFINE_IMPLEMENTATION(RadioMessageType RadioClass::Transmit_Message(RadioMessageType, long&, RadioClass*), 0x005BD940);
DEFINE_IMPLEMENTATION(RadioMessageType RadioClass::Transmit_Message(RadioMessageType, RadioClass*), 0x005BDA10);

CargoClass::CargoClass() : Quantity(0), CargoHold(nullptr) {}
CargoClass::CargoClass(const NoInitClass& noinit) {}
CargoClass::~CargoClass() { CargoHold = nullptr; }
void CargoClass::AI() {}
DEFINE_IMPLEMENTATION(void CargoClass::Attach(FootClass*), 0x004491B0);
DEFINE_IMPLEMENTATION(FootClass* CargoClass::Attached_Object() const, 0x00449260);
DEFINE_IMPLEMENTATION(FootClass* CargoClass::Detach_Object(), 0x00449240);
DEFINE_IMPLEMENTATION(void CargoClass::Detach(FootClass*), 0x00449270);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(FacingClass::FacingClass(), 0x00496530);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(FacingClass::FacingClass(int), 0x00496550);
FacingClass::FacingClass(DirType& facing) : DesiredFacing(DIR_N), StartFacing(DIR_N), RotationTimer(0), ROT(0) {}
FacingClass::FacingClass(Dir256 dir) : DesiredFacing(dir), StartFacing(dir), RotationTimer(0), ROT(0) {}
FacingClass::FacingClass(const NoInitClass& noinit) : RotationTimer(noinit) {}
DEFINE_IMPLEMENTATION(bool FacingClass::Set_Desired(const DirType&), 0x00496590);
DEFINE_IMPLEMENTATION(bool FacingClass::Set(const DirType&), 0x00496670);
DEFINE_IMPLEMENTATION(DirType FacingClass::Desired() const, 0x004967E0);
DEFINE_IMPLEMENTATION(DirType FacingClass::Current() const, 0x00496740);
DEFINE_IMPLEMENTATION(bool FacingClass::Is_Rotating() const, 0x004967F0);
DEFINE_IMPLEMENTATION(bool FacingClass::Is_Rotating_CW() const, 0x00496820);
DEFINE_IMPLEMENTATION(bool FacingClass::Is_Rotating_CCW() const, 0x00496860);
DEFINE_IMPLEMENTATION(DirType FacingClass::Difference() const, 0x004968A0);
DEFINE_IMPLEMENTATION(DirType FacingClass::Difference(DirType&) const, 0x00496940);
DEFINE_IMPLEMENTATION(void FacingClass::Set_ROT(int), 0x004969F0);

DEFINE_IMPLEMENTATION(bool DirType::Difference_Not_Greater(const DirType&, const DirType&), 0x005589F0);
DEFINE_IMPLEMENTATION(bool DirType::Turn_Towards(const DirType&, const DirType&), 0x00558A20);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(DoorClass::DoorClass(), 0x00473C70);
DoorClass::~DoorClass() {}
DEFINE_IMPLEMENTATION(bool DoorClass::Is_Door_Opening() const, 0x00473C90);
DEFINE_IMPLEMENTATION(bool DoorClass::Is_Door_Closing() const, 0x00473CB0);
DEFINE_IMPLEMENTATION(bool DoorClass::Has_Finished() const, 0x00473CD0);
DEFINE_IMPLEMENTATION(bool DoorClass::Is_Door_Open() const, 0x00473D30);
DEFINE_IMPLEMENTATION(bool DoorClass::Is_Door_Closed() const, 0x00473D50);
DEFINE_IMPLEMENTATION(void DoorClass::Open_Door(double), 0x00473D70);
DEFINE_IMPLEMENTATION(void DoorClass::Close_Door(double), 0x00473DC0);
DEFINE_IMPLEMENTATION(void DoorClass::Flip_State(), 0x00473E10);
DEFINE_IMPLEMENTATION(void DoorClass::Force_Open(), 0x00473E50);
DEFINE_IMPLEMENTATION(void DoorClass::Force_Close(), 0x00473E60);
DEFINE_IMPLEMENTATION(double DoorClass::Get_Percent_Complete() const, 0x00473E70);
DEFINE_IMPLEMENTATION(void DoorClass::AI(), 0x00473EE0);

DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TechnoClass::Load(IStream*), 0x00638D70);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(TechnoClass::TechnoClass(HouseClass *house), RadioClass, 0x00629CB0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(TechnoClass::TechnoClass(const NoInitClass &), RadioClass, 0x0062A7F0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(TechnoClass::~TechnoClass(), 0x0062A8E0);
DEFINE_IMPLEMENTATION(void TechnoClass::Init(), 0x0062A7C0);
DEFINE_IMPLEMENTATION(void TechnoClass::Detach(AbstractClass*, bool), 0x006362E0);
DEFINE_IMPLEMENTATION(void TechnoClass::Object_CRC(CRCEngine&) const, 0x00638E80);
DEFINE_IMPLEMENTATION(HousesType TechnoClass::Owner() const, 0x0062E6F0);
DEFINE_IMPLEMENTATION(HouseClass* TechnoClass::Owner_HouseClass() const, 0x0062E700);
DEFINE_IMPLEMENTATION(void TechnoClass::AI(), 0x0062E750);
DEFINE_IMPLEMENTATION(bool TechnoClass::Is_Players_Army() const, 0x0062A070);
DEFINE_IMPLEMENTATION(VisualType TechnoClass::Visual_Character(bool, const HouseClass*), 0x00633CB0);
DEFINE_IMPLEMENTATION(ActionType TechnoClass::What_Action(const Cell&, bool, bool) const, 0x00631AE0);
DEFINE_IMPLEMENTATION(ActionType TechnoClass::What_Action(const ObjectClass*, bool), 0x00631700);
DEFINE_IMPLEMENTATION(const TechnoTypeClass* TechnoClass::Techno_Type_Class() const, 0x0062A010);
DEFINE_IMPLEMENTATION(int TechnoClass::Get_Ownable() const, 0x00637200);
DEFINE_IMPLEMENTATION(bool TechnoClass::Can_Repair() const, 0x00632380);
DEFINE_IMPLEMENTATION(bool TechnoClass::Can_Player_Fire() const, 0x00632310);
DEFINE_IMPLEMENTATION(bool TechnoClass::Can_Player_Move() const, 0x00631FF0);
DEFINE_IMPLEMENTATION(Coord TechnoClass::Fire_Coord(WeaponSlotType) const, 0x0062A3D0);
DEFINE_IMPLEMENTATION(bool TechnoClass::Limbo(), 0x0062CA90);
DEFINE_IMPLEMENTATION(bool TechnoClass::Unlimbo(const Coord&, Dir256), 0x0062CB30);
DEFINE_IMPLEMENTATION(void TechnoClass::Record_The_Kill(const ObjectClass*), 0x006336F0);
DEFINE_IMPLEMENTATION(void TechnoClass::Do_Shimmer(), 0x00633CA0);
DEFINE_IMPLEMENTATION(ExitType TechnoClass::Exit_Object(const TechnoClass*), 0x006374D0);
DEFINE_IMPLEMENTATION(void TechnoClass::entry_F8(Point2D&, Rect&) const, 0x0062C080);
DEFINE_IMPLEMENTATION(void TechnoClass::entry_FC(Point2D&, Rect&) const, 0x0062B220);
DEFINE_IMPLEMENTATION(void TechnoClass::Hidden(), 0x0062ABD0);
DEFINE_IMPLEMENTATION(void TechnoClass::Look(bool, bool), 0x00638310);
DEFINE_IMPLEMENTATION(bool TechnoClass::Mark(MarkType), 0x0062AC00);
DEFINE_IMPLEMENTATION(void TechnoClass::Clicked_As_Target(int), 0x0062E710);
DEFINE_IMPLEMENTATION(bool TechnoClass::Select(), 0x0062F900);
DEFINE_IMPLEMENTATION(bool TechnoClass::In_Range(Coord&, WeaponSlotType) const, 0x0062CDB0);
DEFINE_IMPLEMENTATION(int TechnoClass::Weapon_Range(WeaponSlotType) const, 0x006323D0);
DEFINE_IMPLEMENTATION(ResultType TechnoClass::Take_Damage(int&, int, const WarheadTypeClass*, const ObjectClass*, bool, bool), 0x00632750);
DEFINE_IMPLEMENTATION(int TechnoClass::Value() const, 0x00636520);
DEFINE_IMPLEMENTATION(void TechnoClass::Per_Cell_Process(PCPType), 0x0062B130);
DEFINE_IMPLEMENTATION(RadioMessageType TechnoClass::Receive_Message(RadioClass*, RadioMessageType, long&), 0x0062AC40);
DEFINE_IMPLEMENTATION(bool TechnoClass::Revealed(const HouseClass*), 0x0062AAD0);
DEFINE_IMPLEMENTATION(void TechnoClass::Override_Mission(MissionType, AbstractClass*, AbstractClass*), 0x006323F0);
DEFINE_IMPLEMENTATION(bool TechnoClass::Restore_Mission(), 0x00632430);
DEFINE_IMPLEMENTATION(bool TechnoClass::entry_220() const, 0x0040F270);
DEFINE_IMPLEMENTATION(bool TechnoClass::Is_Allowed_To_Recloak() const, 0x0000639120);
DEFINE_IMPLEMENTATION(bool TechnoClass::entry_228() const, 0x0062A020);
DEFINE_IMPLEMENTATION(bool TechnoClass::entry_22C() const, 0x0043B8D0);
DEFINE_IMPLEMENTATION(bool TechnoClass::entry_230() const, 0x00638CA0);
DEFINE_IMPLEMENTATION(bool TechnoClass::entry_234() const, 0x0062E720);
DEFINE_IMPLEMENTATION(bool TechnoClass::entry_238() const, 0x0040F280);
DEFINE_IMPLEMENTATION(bool TechnoClass::entry_23C() const, 0x0062F750);
DEFINE_IMPLEMENTATION(bool TechnoClass::entry_240() const, 0x0062F650);
DEFINE_IMPLEMENTATION(DirType TechnoClass::Turret_Facing() const, 0x004A8DB0);
DEFINE_IMPLEMENTATION(bool TechnoClass::Is_Weapon_Equipped() const, 0x00632360);
DEFINE_IMPLEMENTATION(bool TechnoClass::Is_On_Elevation() const, 0x00639140);
DEFINE_IMPLEMENTATION(double TechnoClass::Tiberium_Load() const, 0x00637230);
DEFINE_IMPLEMENTATION(double TechnoClass::Weed_Load() const, 0x006391A0);
DEFINE_IMPLEMENTATION(int TechnoClass::Pip_Count() const, 0x00637260);
DEFINE_IMPLEMENTATION(int TechnoClass::Refund_Amount() const, 0x00638090);
DEFINE_IMPLEMENTATION(int TechnoClass::Risk() const, 0x00637210);
DEFINE_IMPLEMENTATION(bool TechnoClass::Is_In_Same_Zone_As(const ObjectClass*) const, 0x0043B8E0);
DEFINE_IMPLEMENTATION(DirType TechnoClass::entry_268(const ObjectClass*) const, 0x00630210);
DEFINE_IMPLEMENTATION(bool TechnoClass::Is_In_Same_Zone(const Coord&) const, 0x006366B0);
DEFINE_IMPLEMENTATION(int TechnoClass::How_Many_Survivors() const, 0x0062A300);
DEFINE_IMPLEMENTATION(void TechnoClass::entry_274() const, 0x0063A250);
DEFINE_IMPLEMENTATION(int TechnoClass::entry_278() const, 0x0063A090);
DEFINE_IMPLEMENTATION(int TechnoClass::Get_Z_Adjustment() const, 0x00634790);
DEFINE_IMPLEMENTATION(ZGradientType TechnoClass::Get_Z_Gradient() const, 0x0043B8F0);
DEFINE_IMPLEMENTATION(BuildingClass* const TechnoClass::Find_Docking_Bay(const BuildingTypeClass*, bool, bool) const, 0x00637E60);
DEFINE_IMPLEMENTATION(Cell TechnoClass::Find_Exit_Cell(const TechnoClass*) const, 0x00638040);
DEFINE_IMPLEMENTATION(Coord TechnoClass::entry_28C(WeaponSlotType) const, 0x0062A5A0);
DEFINE_IMPLEMENTATION(FacingType TechnoClass::Desired_Load_Dir(const ObjectClass*, Cell&) const, 0x00637240);
DEFINE_IMPLEMENTATION(DirType TechnoClass::Fire_Direction() const, 0x00637310);
DEFINE_IMPLEMENTATION(InfantryTypeClass* const TechnoClass::Crew_Type() const, 0x006364A0);
DEFINE_IMPLEMENTATION(bool TechnoClass::entry_29C() const, 0x00632020);
DEFINE_IMPLEMENTATION(bool TechnoClass::Can_Deploy_Now() const, 0x00632070);
DEFINE_IMPLEMENTATION(bool TechnoClass::Is_Immobilized() const, 0x00632350);
DEFINE_IMPLEMENTATION(int TechnoClass::Get_Max_Speed() const, 0x0063A510);
DEFINE_IMPLEMENTATION(int TechnoClass::Rearm_Delay(WeaponSlotType) const, 0x0062FE30);
DEFINE_IMPLEMENTATION(int TechnoClass::Threat_Range(int) const, 0x006365B0);
DEFINE_IMPLEMENTATION(bool TechnoClass::Is_Allowed_To_Leave_Map() const, 0x0043B900);
DEFINE_IMPLEMENTATION(bool TechnoClass::entry_2B8(int*) const, 0x00639CA0);
DEFINE_IMPLEMENTATION(bool TechnoClass::entry_2BC() const, 0x00639E70);
DEFINE_IMPLEMENTATION(bool TechnoClass::entry_2C0(const HouseClass*) const, 0x00639EB0);
DEFINE_IMPLEMENTATION(bool TechnoClass::Is_Renovator() const, 0x0040F290);
DEFINE_IMPLEMENTATION(void TechnoClass::entry_2C8() const, 0x0043B910);
DEFINE_IMPLEMENTATION(void TechnoClass::Response_Select() const, 0x00637330);
DEFINE_IMPLEMENTATION(void TechnoClass::Response_Move() const, 0x00637390);
DEFINE_IMPLEMENTATION(void TechnoClass::Response_Attack() const, 0x006373F0);
DEFINE_IMPLEMENTATION(void TechnoClass::Player_Assign_Mission(MissionType, AbstractClass*, AbstractClass*), 0x00631650);
DEFINE_IMPLEMENTATION(void TechnoClass::Reduce_Ammunition(), 0x0063A070);
DEFINE_IMPLEMENTATION(bool TechnoClass::Target_Something_Nearby(Coord&, ThreatType), 0x00637450);
DEFINE_IMPLEMENTATION(void TechnoClass::Stun(), 0x0062FD20);
DEFINE_IMPLEMENTATION(bool TechnoClass::In_Range_Of(AbstractClass*, WeaponSlotType) const, 0x0062CD20);
DEFINE_IMPLEMENTATION(FireErrorType TechnoClass::Can_Fire(AbstractClass*, WeaponSlotType) const, 0x0062F980);
DEFINE_IMPLEMENTATION(AbstractClass* TechnoClass::Greatest_Threat(ThreatType, Coord&, bool) const, 0x0062DC80);
DEFINE_IMPLEMENTATION(void TechnoClass::Assign_Target(AbstractClass*) const, 0x0062FD70);
DEFINE_IMPLEMENTATION(const BulletClass* TechnoClass::Fire_At(AbstractClass*, WeaponSlotType), 0x00630350);
DEFINE_IMPLEMENTATION(bool TechnoClass::Captured(HouseClass*), 0x006324D0);
DEFINE_IMPLEMENTATION(void TechnoClass::Laser_Zap(AbstractClass*, int, const WeaponTypeClass*, Coord&), 0x0062FFD0);
DEFINE_IMPLEMENTATION(void TechnoClass::Rock(const Coord&, float), 0x006384A0);
DEFINE_IMPLEMENTATION(WeaponInfoStruct* const TechnoClass::Get_Weapon(WeaponSlotType) const, 0x0040F2A0);
DEFINE_IMPLEMENTATION(bool TechnoClass::Is_Turret_Equipped() const, 0x0040F2F0);
DEFINE_IMPLEMENTATION(void TechnoClass::Renovate() const, 0x00632460);
DEFINE_IMPLEMENTATION(void TechnoClass::Cloaking_AI(bool) const, 0x0062F150);
DEFINE_IMPLEMENTATION(void TechnoClass::entry_31C() const, 0x00638790);
DEFINE_IMPLEMENTATION(void TechnoClass::entry_320() const, 0x0062AF80);
DEFINE_IMPLEMENTATION(void TechnoClass::entry_324() const, 0x0043B920);
DEFINE_IMPLEMENTATION(void TechnoClass::Draw_Voxel(VoxelObject&, unsigned int, int, VoxelIndexClass&, Rect&, Point2D&, Matrix3D&, int, int) const, 0x006354E0);
DEFINE_IMPLEMENTATION(void TechnoClass::entry_32C(Point2D&, Rect&) const, 0x0062C070);
DEFINE_IMPLEMENTATION(void TechnoClass::entry_330(Point2D&, Rect&, bool) const, 0x0062C450);
DEFINE_IMPLEMENTATION(void TechnoClass::Draw_Pips(Point2D&, Point2D&, Rect&) const, 0x00637540);
DEFINE_IMPLEMENTATION(void TechnoClass::Draw_Text_Overlay(Point2D&, Point2D&, Rect&) const, 0x00637D60);
DEFINE_IMPLEMENTATION(void TechnoClass::Do_Uncloak(bool), 0x00633B20);
DEFINE_IMPLEMENTATION(void TechnoClass::Do_Cloak(bool), 0x00633BF0);
DEFINE_IMPLEMENTATION(int TechnoClass::entry_344(int) const, 0x00639C70);
DEFINE_IMPLEMENTATION(bool TechnoClass::Is_Ready_To_Random_Animate() const, 0x006374E0);
DEFINE_IMPLEMENTATION(bool TechnoClass::Random_Animate(), 0x0040F300);
DEFINE_IMPLEMENTATION(void TechnoClass::Assign_Destination(const AbstractClass*, bool), 0x00637520);
DEFINE_IMPLEMENTATION(bool TechnoClass::Enter_Idle_Mode(bool, bool), 0x00637530);
DEFINE_IMPLEMENTATION(void TechnoClass::entry_358(), 0x00639790);
DEFINE_IMPLEMENTATION(void TechnoClass::entry_35C(), 0x006397C0);
DEFINE_IMPLEMENTATION(void TechnoClass::entry_360() const, 0x006397F0);
DEFINE_IMPLEMENTATION(void TechnoClass::entry_364(bool), 0x0063A260);
DEFINE_IMPLEMENTATION(WeaponSlotType TechnoClass::What_Weapon_Should_I_Use(AbstractClass*) const, 0x0062A0D0);
DEFINE_IMPLEMENTATION(int TechnoClass::Combat_Damage(int) const, 0x0062A320);
DEFINE_IMPLEMENTATION(int TechnoClass::Time_To_Build() const, 0x0062A970);
// 0062BEA0);
// 0062BFE0);
// 0062CD00);
DEFINE_IMPLEMENTATION(double TechnoClass::Area_Modify(Cell&) const, 0x0062CDE0);
// 0062D0F0);
// 0062D8D0);
DEFINE_IMPLEMENTATION(int TechnoClass::Evaluate_Just_Cell(Cell&) const, 0x0062DA70);
DEFINE_IMPLEMENTATION(bool TechnoClass::Evaluate_Object(ThreatType, int, int, const TechnoClass*, int&, int, Coord&) const, 0x0062D0F0);
DEFINE_IMPLEMENTATION(bool TechnoClass::Evaluate_Cell(ThreatType, int, Cell&, int, const TechnoClass**, int&, int) const, 0x0062D8D0);
DEFINE_IMPLEMENTATION(Cell TechnoClass::Nearby_Location(const TechnoClass*) const, 0x00633A00);
DEFINE_IMPLEMENTATION(bool TechnoClass::Is_Z_Fudge_Bridge() const, 0x00633F60);
// 00634110);
DEFINE_IMPLEMENTATION(bool TechnoClass::Is_Z_Fudge_Column() const, 0x006342C0);
DEFINE_IMPLEMENTATION(bool TechnoClass::Is_Z_Fudge_Tunnel() const, 0x00634450);
DEFINE_IMPLEMENTATION(bool TechnoClass::Is_Z_Fudge_Cliff() const, 0x00634690);
// 00635860);
// 00635B00);
// 00635E20);
// 00635FA0);
// 00636280);
DEFINE_IMPLEMENTATION(void TechnoClass::Kill_Cargo(TechnoClass*), 0x00636430);
DEFINE_IMPLEMENTATION(void TechnoClass::Base_Is_Attacked(const TechnoClass*), 0x006367D0);
DEFINE_IMPLEMENTATION(bool TechnoClass::Is_Allowed_To_Retaliate(const TechnoClass*, const WarheadTypeClass*) const, 0x00636F00);
DEFINE_IMPLEMENTATION(int TechnoClass::Anti_Air() const, 0x006380F0);
DEFINE_IMPLEMENTATION(int TechnoClass::Anti_Armor() const, 0x00638170);
DEFINE_IMPLEMENTATION(int TechnoClass::Anti_Infantry() const, 0x00638240);
DEFINE_IMPLEMENTATION(Coord TechnoClass::func_638AF0() const, 0x00638AF0);
// 00638C70);
DEFINE_IMPLEMENTATION(void TechnoClass::Assign_Archive_Target(AbstractClass*), 0x00639130);
// 006391B0);
DEFINE_IMPLEMENTATION(float TechnoClass::Target_Threat(TechnoClass*, Coord&) const, 0x00639810);
// 00639BB0);
// 00639C30);
// 00639C60);
DEFINE_IMPLEMENTATION(void TechnoClass::Update_Mission_Targets(AbstractClass*), 0x00639EF0);
// 00639F80);
// 0063A0C0);
// 0063A100);
// 0063A1D0);
// 0063A530);
DEFINE_IMPLEMENTATION(void TechnoClass::Techno_Draw_Object(const ShapeSet*, int, const Point2D&, const Rect&, Dir256, int, int, int a8, bool, int, const ShapeSet*, int, Point2D, ShapeFlags_Type) const, 0x00634E00);
DEFINE_IMPLEMENTATION(void TechnoClass::Reset_Action_Line_Timer(), 0x00639C30);
DEFINE_IMPLEMENTATION(void TechnoClass::Set_Action_Lines(bool), 0x00639C60);

DEFINE_IMPLEMENTATION(char* strtrim(char*), 0x0064AC10);

DEFINE_IMPLEMENTATION(void WinDialogClass::Display_Dialog(HWND), 0x005A0820);
DEFINE_IMPLEMENTATION(void WinDialogClass::End_Dialog(HWND), 0x005A0700);
DEFINE_IMPLEMENTATION(HWND WinDialogClass::Do_Message_Box(const char*, const char*, bool*), 0x005A0C60);
DEFINE_IMPLEMENTATION(bool WinDialogClass::Dialog_Move(HWND, WPARAM, LPARAM, UINT), 0x00685300);
DEFINE_IMPLEMENTATION(bool WinDialogClass::Center_Window_Within(HWND, HWND), 0x00685600);
DEFINE_IMPLEMENTATION(bool WinDialogClass::Center_Window(HWND), 0x006855E0);

DEFINE_IMPLEMENTATION(void Fatal(const char*, ...), 0x004F91D0);
DEFINE_IMPLEMENTATION(void Emergency_Exit(int), 0x00602480);

DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE FootClass::Load(IStream*), 0x004A5F40);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE FootClass::Save(IStream*, BOOL), 0x004A61B0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(FootClass::FootClass(HouseClass *), TechnoClass, 0x004A00F0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(FootClass::FootClass(const NoInitClass &), TechnoClass, 0x004A0390);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(FootClass::~FootClass(), 0x004A03D0);
DEFINE_IMPLEMENTATION(void FootClass::Detach(AbstractClass*, bool), 0x004A4E50);
DEFINE_IMPLEMENTATION(void FootClass::Object_CRC(CRCEngine&) const, 0x004A6580);
DEFINE_IMPLEMENTATION(Coord FootClass::entry_50() const, 0x004A68A0);
DEFINE_IMPLEMENTATION(bool FootClass::On_Ground() const, 0x004A8CC0);
DEFINE_IMPLEMENTATION(bool FootClass::In_Air() const, 0x004A8BF0);
DEFINE_IMPLEMENTATION(void FootClass::AI(), 0x004A5890);
DEFINE_IMPLEMENTATION(VisualType FootClass::Visual_Character(bool, const HouseClass*), 0x004A5840);
DEFINE_IMPLEMENTATION(ActionType FootClass::What_Action(const Cell&, bool, bool) const, 0x004A8430);
DEFINE_IMPLEMENTATION(ActionType FootClass::What_Action(const ObjectClass*, bool), 0x004A8520);
DEFINE_IMPLEMENTATION(LayerType FootClass::In_Which_Layer() const, 0x004A6300);
DEFINE_IMPLEMENTATION(bool FootClass::Can_Demolish() const, 0x004A5230);
DEFINE_IMPLEMENTATION(bool FootClass::entry_BC(), 0x004A82E0);
DEFINE_IMPLEMENTATION(bool FootClass::entry_C0() const, 0x0040F330);
DEFINE_IMPLEMENTATION(bool FootClass::Limbo(), 0x004A5E80);
DEFINE_IMPLEMENTATION(bool FootClass::Unlimbo(const Coord&, Dir256), 0x004A2C70);
DEFINE_IMPLEMENTATION(void FootClass::Detach_All(bool), 0x004A4BC0);
DEFINE_IMPLEMENTATION(void FootClass::Delete_Me(), 0x004A8BD0);
DEFINE_IMPLEMENTATION(void FootClass::Draw_It(Point2D&, Rect&) const, 0x004A5E70);
DEFINE_IMPLEMENTATION(bool FootClass::Mark(MarkType), 0x004A0590);
DEFINE_IMPLEMENTATION(bool FootClass::Active_Click_With(ActionType, ObjectClass*, bool), 0x004A35A0);
DEFINE_IMPLEMENTATION(bool FootClass::Active_Click_With(ActionType, Cell&, bool), 0x004A2EB0);
DEFINE_IMPLEMENTATION(ResultType FootClass::Take_Damage(int&, int, const WarheadTypeClass*, const ObjectClass*, bool, bool), 0x004A2DE0);
DEFINE_IMPLEMENTATION(void FootClass::Per_Cell_Process(PCPType), 0x004A3CA0);
DEFINE_IMPLEMENTATION(RadioMessageType FootClass::Receive_Message(RadioClass*, RadioMessageType, long&), 0x004A4560);
DEFINE_IMPLEMENTATION(void FootClass::Sell_Back(int), 0x004A5310);
DEFINE_IMPLEMENTATION(void FootClass::entry_174(int, int), 0x004A6E90);
DEFINE_IMPLEMENTATION(MoveType FootClass::Can_Enter_Cell(const CellClass*, FacingType, int, const CellClass*, bool), 0x004A4FD0);
DEFINE_IMPLEMENTATION(MoveType FootClass::entry_180(const CellClass*, FacingType, int*, bool*, const CellClass*), 0x004A5020);
DEFINE_IMPLEMENTATION(void FootClass::Set_Coord(const Coord&), 0x004A6330);
DEFINE_IMPLEMENTATION(int FootClass::Mission_Attack(), 0x004A1A30);
DEFINE_IMPLEMENTATION(int FootClass::Mission_Capture(), 0x004A18E0);
DEFINE_IMPLEMENTATION(int FootClass::Mission_Guard(), 0x004A1A90);
DEFINE_IMPLEMENTATION(int FootClass::Mission_Guard_Area(), 0x004A2830);
DEFINE_IMPLEMENTATION(int FootClass::Mission_Hunt(), 0x004A1BE0);
DEFINE_IMPLEMENTATION(int FootClass::Mission_Move(), 0x004A0FB0);
DEFINE_IMPLEMENTATION(int FootClass::Mission_Retreat(), 0x004A5630);
DEFINE_IMPLEMENTATION(int FootClass::Mission_Enter(), 0x004A4820);
DEFINE_IMPLEMENTATION(int FootClass::Mission_Rescue(), 0x004A85E0);
DEFINE_IMPLEMENTATION(int FootClass::Mission_Patrol(), 0x004A1080);
DEFINE_IMPLEMENTATION(void FootClass::Override_Mission(MissionType, AbstractClass*, AbstractClass*), 0x004A44F0);
DEFINE_IMPLEMENTATION(bool FootClass::Restore_Mission(), 0x004A4530);
DEFINE_IMPLEMENTATION(bool FootClass::Is_Allowed_To_Recloak() const, 0x004A6850);
DEFINE_IMPLEMENTATION(bool FootClass::entry_22C() const, 0x0040F310);
DEFINE_IMPLEMENTATION(bool FootClass::Is_In_Same_Zone_As(const ObjectClass*) const, 0x004A6500);
DEFINE_IMPLEMENTATION(bool FootClass::Is_In_Same_Zone(const Coord&) const, 0x004A0620);
DEFINE_IMPLEMENTATION(int FootClass::Get_Z_Adjustment() const, 0x004A5C00);
DEFINE_IMPLEMENTATION(ZGradientType FootClass::Get_Z_Gradient() const, 0x004A5CE0);
DEFINE_IMPLEMENTATION(bool FootClass::Is_Allowed_To_Leave_Map() const, 0x004A5560);
DEFINE_IMPLEMENTATION(void FootClass::entry_2C8() const, 0x004A8B80);
DEFINE_IMPLEMENTATION(void FootClass::Stun(), 0x004A1E00);
DEFINE_IMPLEMENTATION(void FootClass::Death_Announcement(const TechnoClass*) const, 0x004A4D60);
DEFINE_IMPLEMENTATION(AbstractClass* FootClass::Greatest_Threat(ThreatType, Coord&, bool) const, 0x004A4DC0);
DEFINE_IMPLEMENTATION(bool FootClass::Captured(HouseClass*), 0x004A6980);
DEFINE_IMPLEMENTATION(void FootClass::entry_324() const, 0x004A6A40);
DEFINE_IMPLEMENTATION(void FootClass::Draw_Voxel(VoxelObject&, unsigned int, int, VoxelIndexClass&, Rect&, Point2D&, Matrix3D&, int, int) const, 0x004A5B50);
DEFINE_IMPLEMENTATION(void FootClass::Assign_Destination(const AbstractClass*, bool), 0x004A49F0);
DEFINE_IMPLEMENTATION(bool FootClass::Enter_Idle_Mode(bool, bool), 0x004A3AA0);
DEFINE_IMPLEMENTATION(bool FootClass::entry_368(), 0x004A6E10);
DEFINE_IMPLEMENTATION(bool FootClass::entry_36C(), 0x004A69C0);
DEFINE_IMPLEMENTATION(bool FootClass::Deploy_To_Fire(), 0x0040F320);
DEFINE_IMPLEMENTATION(Coord FootClass::Likely_Coord() const, 0x004A5390);
DEFINE_IMPLEMENTATION(void FootClass::entry_378(), 0x004A6A10);
DEFINE_IMPLEMENTATION(bool FootClass::entry_37C(), 0x0040F340);
DEFINE_IMPLEMENTATION(bool FootClass::Start_Driver(Coord&), 0x004A1D90);
DEFINE_IMPLEMENTATION(bool FootClass::Stop_Driver(), 0x004A1D60);
DEFINE_IMPLEMENTATION(bool FootClass::entry_388(), 0x004A6480);
DEFINE_IMPLEMENTATION(void FootClass::Draw_Object(const ShapeSet*, int, Point2D&, Rect&, Dir256, int, int, int a8, bool, int, ShapeSet*, int, Point2D, ShapeFlags_Type) const, 0x0040F350);
DEFINE_IMPLEMENTATION(void FootClass::entry_390(), 0x0040F3B0);
DEFINE_IMPLEMENTATION(void FootClass::entry_394(), 0x0040F3C0);
DEFINE_IMPLEMENTATION(void FootClass::entry_398(), 0x0040F3D0);
DEFINE_IMPLEMENTATION(void FootClass::entry_39C(int), 0x0040F3E0);
DEFINE_IMPLEMENTATION(int FootClass::Offload_Tiberium_Bail(), 0x004A4FC0);
DEFINE_IMPLEMENTATION(void FootClass::Overrun_Square(Cell&, bool), 0x0040F3F0);
DEFINE_IMPLEMENTATION(int FootClass::Current_Speed(), 0x004A5DD0);
DEFINE_IMPLEMENTATION(void FootClass::Approach_Target(), 0x004A1E30);
DEFINE_IMPLEMENTATION(void FootClass::Fixup_Path(PathType*), 0x0040F400);
DEFINE_IMPLEMENTATION(void FootClass::Set_Speed(double), 0x004A0520);
DEFINE_IMPLEMENTATION(void FootClass::entry_3B8(), 0x004A64F0);
DEFINE_IMPLEMENTATION(bool FootClass::Is_LZ_Clear(AbstractClass*), 0x004A8300);
DEFINE_IMPLEMENTATION(int FootClass::Rescue_Mission(AbstractClass*), 0x004A4C40);
DEFINE_IMPLEMENTATION(Cell FootClass::Adjust_Dest(Cell&), 0x004A53C0);
DEFINE_IMPLEMENTATION(void FootClass::Handle_Navigation_List(), 0x004A53D0);
DEFINE_IMPLEMENTATION(void FootClass::Queue_Navigation_List(AbstractClass* target), 0x004A5480);
DEFINE_IMPLEMENTATION(void FootClass::Clear_Navigation_List(), 0x004A5550);
DEFINE_IMPLEMENTATION(bool FootClass::Is_Recruitable(const HouseClass*) const, 0x004A55C0);
DEFINE_IMPLEMENTATION(bool FootClass::Is_On_Priority_Mission() const, 0x004A5620);
// 004A5D10
DEFINE_IMPLEMENTATION(void FootClass::Link_Droppod(), 0x004A6370);
// 004A6DE0
// 004A6F40
DEFINE_IMPLEMENTATION(bool FootClass::Tiberium_Check(Cell&), 0x004A74D0);
DEFINE_IMPLEMENTATION(bool FootClass::Goto_Tiberium(int, bool), 0x004A7630);
DEFINE_IMPLEMENTATION(Cell FootClass::Search_For_Tiberium(int, bool), 0x004A76F0);
DEFINE_IMPLEMENTATION(Cell FootClass::Search_For_Tiberium_Weighted(int), 0x004A7990);
DEFINE_IMPLEMENTATION(Cell FootClass::Search_For_Weed(int), 0x004A7F40);
DEFINE_IMPLEMENTATION(bool FootClass::Weed_Check(Cell&, int, int), 0x004A80A0);
DEFINE_IMPLEMENTATION(bool FootClass::Goto_Weed(int), 0x004A8230);
// 004A8800
DEFINE_IMPLEMENTATION(bool FootClass::Basic_Path(Cell&, int, int), 0x004A0730);
DEFINE_IMPLEMENTATION(PathType* FootClass::Find_Path(Cell&, int*, int, int, int, int), 0x00498EF0);
DEFINE_IMPLEMENTATION(Cell FootClass::Safety_Point(Cell&, Cell&, int, int), 0x00498F90);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE BuildingClass::GetClassID(CLSID*), 0x0043B950);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE BuildingClass::Load(IStream*), 0x00438060);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE BuildingClass::Save(IStream*, BOOL), 0x00438210);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(BuildingClass::BuildingClass(BuildingTypeClass *, HouseClass *), TechnoClass, 0x00426190);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(BuildingClass::BuildingClass(NoInitClass &), TechnoClass, 0x00426140);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(BuildingClass::~BuildingClass(), 0x00426620);
DEFINE_IMPLEMENTATION(void BuildingClass::Init(), 0x0042BBE0);
DEFINE_IMPLEMENTATION(void BuildingClass::Detach(AbstractClass*, bool), 0x00433EB0);
DEFINE_IMPLEMENTATION(RTTIType BuildingClass::Fetch_RTTI() const, 0x0043B990);
DEFINE_IMPLEMENTATION(int BuildingClass::Get_Object_Size(bool) const, 0x0043B930);
DEFINE_IMPLEMENTATION(void BuildingClass::Object_CRC(CRCEngine&) const, 0x00438240);
DEFINE_IMPLEMENTATION(Coord BuildingClass::Center_Coord() const, 0x0042F250);
DEFINE_IMPLEMENTATION(Coord BuildingClass::entry_50() const, 0x0042F3B0);
DEFINE_IMPLEMENTATION(void BuildingClass::AI(), 0x00429A60);
DEFINE_IMPLEMENTATION(VisualType BuildingClass::Visual_Character(bool, const HouseClass*), 0x00438450);
DEFINE_IMPLEMENTATION(ShapeSet* const BuildingClass::Get_Image_Data() const, 0x00435E40);
DEFINE_IMPLEMENTATION(ActionType BuildingClass::What_Action(const ObjectClass*, bool), 0x0042EED0);
DEFINE_IMPLEMENTATION(ActionType BuildingClass::What_Action(const Cell&, bool, bool) const, 0x0042EBD0);
DEFINE_IMPLEMENTATION(bool BuildingClass::entry_80() const, 0x0043AF40);
DEFINE_IMPLEMENTATION(const ObjectTypeClass* BuildingClass::Class_Of() const, 0x0043B9B0);
DEFINE_IMPLEMENTATION(const char* BuildingClass::Full_Name() const, 0x0043B9A0);
DEFINE_IMPLEMENTATION(bool BuildingClass::Can_Repair() const, 0x00436B60);
DEFINE_IMPLEMENTATION(bool BuildingClass::Can_Demolish() const, 0x0042FEF0);
DEFINE_IMPLEMENTATION(bool BuildingClass::Can_Player_Move() const, 0x00434520);
DEFINE_IMPLEMENTATION(Coord BuildingClass::Target_Coord() const, 0x00434FB0);
DEFINE_IMPLEMENTATION(Coord BuildingClass::Docking_Coord() const, 0x0042F2C0);
DEFINE_IMPLEMENTATION(Coord BuildingClass::Render_Coord() const, 0x0043B9C0);
DEFINE_IMPLEMENTATION(Coord BuildingClass::Fire_Coord(WeaponSlotType) const, 0x00437BD0);
DEFINE_IMPLEMENTATION(Coord BuildingClass::Exit_Coord() const, 0x00434580);
DEFINE_IMPLEMENTATION(int BuildingClass::Sort_Y() const, 0x0042FE40);
DEFINE_IMPLEMENTATION(bool BuildingClass::Limbo(), 0x0042DB50);
DEFINE_IMPLEMENTATION(bool BuildingClass::Unlimbo(const Coord&, Dir256), 0x00429E20);
DEFINE_IMPLEMENTATION(void BuildingClass::Detach_All(bool), 0x00434000);
DEFINE_IMPLEMENTATION(void BuildingClass::Set_Occupy_Bit(Coord&), 0x00437FA0);
DEFINE_IMPLEMENTATION(void BuildingClass::Clear_Occupy_Bit(Coord&), 0x00438000);
DEFINE_IMPLEMENTATION(ExitType BuildingClass::Exit_Object(const TechnoClass*), 0x0042C640);
DEFINE_IMPLEMENTATION(bool BuildingClass::Render(Rect&, bool, bool), 0x00427210);
DEFINE_IMPLEMENTATION(void BuildingClass::Draw_It(Point2D&, Rect&) const, 0x004275B0);
DEFINE_IMPLEMENTATION(void BuildingClass::Placement_Draw_It(Point2D&, Rect&) const, 0x00427390);
DEFINE_IMPLEMENTATION(bool BuildingClass::Mark(MarkType), 0x00429370);
DEFINE_IMPLEMENTATION(Rect BuildingClass::entry_118() const, 0x00439B90);
DEFINE_IMPLEMENTATION(void BuildingClass::Draw_Radial_Indicator() const, 0x0043A6F0);
DEFINE_IMPLEMENTATION(bool BuildingClass::Active_Click_With(ActionType, ObjectClass*, bool), 0x0042C210);
DEFINE_IMPLEMENTATION(bool BuildingClass::Active_Click_With(ActionType, Cell&, bool), 0x0042C0B0);
DEFINE_IMPLEMENTATION(void BuildingClass::Clicked_As_Target(int), 0x0043AB00);
DEFINE_IMPLEMENTATION(ResultType BuildingClass::Take_Damage(int&, int, const WarheadTypeClass*, const ObjectClass*, bool, bool), 0x0042B330);
DEFINE_IMPLEMENTATION(RadioMessageType BuildingClass::Receive_Message(RadioClass*, RadioMessageType, long&), 0x004268C0);
DEFINE_IMPLEMENTATION(bool BuildingClass::Revealed(const HouseClass*), 0x00433230);
DEFINE_IMPLEMENTATION(void BuildingClass::Repair(int), 0x0042E9F0);
DEFINE_IMPLEMENTATION(void BuildingClass::Sell_Back(int), 0x0042EAE0);
DEFINE_IMPLEMENTATION(MoveType BuildingClass::Can_Enter_Cell(const CellClass*, FacingType, int, const CellClass*, bool), 0x0042FE70);
DEFINE_IMPLEMENTATION(bool BuildingClass::Ready_To_Commence() const, 0x00438230);
DEFINE_IMPLEMENTATION(int BuildingClass::Mission_Attack(), 0x00431360);
DEFINE_IMPLEMENTATION(int BuildingClass::Mission_Guard(), 0x004300D0);
DEFINE_IMPLEMENTATION(int BuildingClass::Mission_Guard_Area(), 0x00430490);
DEFINE_IMPLEMENTATION(int BuildingClass::Mission_Harvest(), 0x00431870);
DEFINE_IMPLEMENTATION(int BuildingClass::Mission_Unload(), 0x00433540);
DEFINE_IMPLEMENTATION(int BuildingClass::Mission_Construction(), 0x004304A0);
DEFINE_IMPLEMENTATION(int BuildingClass::Mission_Deconstruction(), 0x00430630);
DEFINE_IMPLEMENTATION(int BuildingClass::Mission_Repair(), 0x00431880);
DEFINE_IMPLEMENTATION(int BuildingClass::Mission_Missile(), 0x004326D0);
DEFINE_IMPLEMENTATION(int BuildingClass::Mission_Open(), 0x00433AC0);
DEFINE_IMPLEMENTATION(bool BuildingClass::entry_220() const, 0x00439D10);
;
DEFINE_IMPLEMENTATION(bool BuildingClass::entry_23C() const, 0x0043B0A0);
DEFINE_IMPLEMENTATION(bool BuildingClass::entry_240() const, 0x0043B1F0);
DEFINE_IMPLEMENTATION(DirType BuildingClass::Turret_Facing() const, 0x0042E030);
DEFINE_IMPLEMENTATION(int BuildingClass::Pip_Count() const, 0x00433360);
DEFINE_IMPLEMENTATION(DirType BuildingClass::entry_268(const ObjectClass*) const, 0x00428B70);
DEFINE_IMPLEMENTATION(int BuildingClass::How_Many_Survivors() const, 0x00435DA0);
DEFINE_IMPLEMENTATION(void BuildingClass::entry_274() const, 0x0043B020);
DEFINE_IMPLEMENTATION(int BuildingClass::entry_278() const, 0x0043AED0);
DEFINE_IMPLEMENTATION(int BuildingClass::Get_Z_Adjustment() const, 0x00428B20);
DEFINE_IMPLEMENTATION(Cell BuildingClass::Find_Exit_Cell(const TechnoClass*) const, 0x00434140);
DEFINE_IMPLEMENTATION(Coord BuildingClass::entry_28C(WeaponSlotType) const, 0x00437D00);
DEFINE_IMPLEMENTATION(DirType BuildingClass::Fire_Direction() const, 0x00433490);
DEFINE_IMPLEMENTATION(InfantryTypeClass* const BuildingClass::Crew_Type() const, 0x00433FB0);
DEFINE_IMPLEMENTATION(bool BuildingClass::entry_2B8(int*) const, 0x0043AC70);
DEFINE_IMPLEMENTATION(void BuildingClass::Death_Announcement(const TechnoClass*) const, 0x00433420);
DEFINE_IMPLEMENTATION(FireErrorType BuildingClass::Can_Fire(AbstractClass*, WeaponSlotType) const, 0x0042F400);
DEFINE_IMPLEMENTATION(AbstractClass* BuildingClass::Greatest_Threat(ThreatType, Coord&, bool) const, 0x0042E0E0);
DEFINE_IMPLEMENTATION(void BuildingClass::Assign_Target(AbstractClass*) const, 0x0042C570);
DEFINE_IMPLEMENTATION(bool BuildingClass::Captured(HouseClass*), 0x0042F660);
DEFINE_IMPLEMENTATION(WeaponInfoStruct* const BuildingClass::Get_Weapon(WeaponSlotType) const, 0x00436C10);
DEFINE_IMPLEMENTATION(bool BuildingClass::Is_Turret_Equipped() const, 0x00436CA0);
DEFINE_IMPLEMENTATION(void BuildingClass::Cloaking_AI(bool) const, 0x00438990);
DEFINE_IMPLEMENTATION(int BuildingClass::entry_344(int) const, 0x0043AC40);
DEFINE_IMPLEMENTATION(void BuildingClass::Assign_Destination(const AbstractClass*, bool), 0x00439CC0);
DEFINE_IMPLEMENTATION(bool BuildingClass::Enter_Idle_Mode(bool, bool), 0x00433300);
DEFINE_IMPLEMENTATION(void BuildingClass::entry_358(), 0x0043A5C0);
DEFINE_IMPLEMENTATION(void BuildingClass::entry_35C(), 0x0043A620);
DEFINE_IMPLEMENTATION(void BuildingClass::entry_360() const, 0x0043A680);
DEFINE_IMPLEMENTATION(void BuildingClass::Grand_Opening(bool), 0x0042E170);
DEFINE_IMPLEMENTATION(void BuildingClass::Update_Buildables(), 0x0042D9A0);
DEFINE_IMPLEMENTATION(void BuildingClass::entry_370(Point2D&, Rect&), 0x00427B60);
DEFINE_IMPLEMENTATION(DirType BuildingClass::entry_374(AbstractClass*), 0x00428F60);
DEFINE_IMPLEMENTATION(void BuildingClass::entry_378(TechnoClass*, TechnoClass*, bool, Cell*), 0x0042AB00);
DEFINE_IMPLEMENTATION(bool BuildingClass::Toggle_Primary(), 0x0042F590);
DEFINE_IMPLEMENTATION(unsigned BuildingClass::entry_380(), 0x00436780);
DEFINE_IMPLEMENTATION(void BuildingClass::Draw_Overlays(Point2D&, Rect&), 0x00428810);
// 00429070
// 00429100
DEFINE_IMPLEMENTATION(int BuildingClass::Shape_Number() const, 0x00429220);
DEFINE_IMPLEMENTATION(void BuildingClass::Drop_Debris(AbstractClass*), 0x0042BC60);
DEFINE_IMPLEMENTATION(void BuildingClass::Assign_Rally_Point(Cell&), 0x0042C340);
DEFINE_IMPLEMENTATION(void BuildingClass::Begin_Mode(BStateType), 0x042F020);
// 0042FF70
// 004305C0
// 00433A20
DEFINE_IMPLEMENTATION(int BuildingClass::Power_Output() const, 0x00433DF0);
DEFINE_IMPLEMENTATION(int BuildingClass::Power_Drain() const, 0x00433E60);
DEFINE_IMPLEMENTATION(bool BuildingClass::Flush_For_Placement(TechnoClass*, Cell&), 0x00434110);
DEFINE_IMPLEMENTATION(Cell BuildingClass::Check_Point(CheckPointType) const, 0x00434680);
DEFINE_IMPLEMENTATION(void BuildingClass::Update_Radar_Spied(), 0x00434740);
DEFINE_IMPLEMENTATION(void BuildingClass::Build_INI_Entry(CCINIClass&) const, 0x00434DE0);
DEFINE_IMPLEMENTATION(void BuildingClass::Factory_AI(), 0x00434FE0);
DEFINE_IMPLEMENTATION(void BuildingClass::Charging_AI(), 0x00435220);
DEFINE_IMPLEMENTATION(void BuildingClass::Repair_AI(), 0x00435540);
DEFINE_IMPLEMENTATION(void BuildingClass::Animation_AI(), 0x00435A50);
// 00435E60
// 00436020
DEFINE_IMPLEMENTATION(void BuildingClass::Begin_Anim(BAnimType, bool, int), 0x004360E0);
DEFINE_IMPLEMENTATION(void BuildingClass::Set_Anim_Coords(), 0x00436140);
DEFINE_IMPLEMENTATION(void BuildingClass::Create_Anim(char const*, BAnimType, bool, int), 0x00436200);
DEFINE_IMPLEMENTATION(void BuildingClass::Detach_Anim(AnimClass*), 0x00436410);
DEFINE_IMPLEMENTATION(void BuildingClass::End_Anim(BAnimType), 0x004364A0);
DEFINE_IMPLEMENTATION(void BuildingClass::Set_Anim_Damage_State(bool), 0x00436500);
DEFINE_IMPLEMENTATION(void BuildingClass::Set_Anim_Drawer(ConvertClass*, int), 0x00436580);
DEFINE_IMPLEMENTATION(void BuildingClass::Update_Anim_Appearance(), 0x00436610);
DEFINE_IMPLEMENTATION(void BuildingClass::Set_Anim_Translucency(int), 0x00436730);
DEFINE_IMPLEMENTATION(void BuildingClass::Turn_On(), 0x00436790);
DEFINE_IMPLEMENTATION(void BuildingClass::Turn_Off(), 0x00436890);
// 00436950
// 004369D0
// 00436A80
// 00436B20
// 00436B90
// 00436CF0
// 00436D50
// 00436EC0
DEFINE_IMPLEMENTATION(void BuildingClass::Init_Laser_Fences(), 0x00437050);
// 004370D0
// 00437370
// 00437550
// 00437680
// 004376B0
// 00437E30
// 00438590
// 004388D0
// 00438910
// 00438950
DEFINE_IMPLEMENTATION(bool BuildingClass::Is_Powered_On() const, 0x00439280);
// 004392F0
// 00439500
// 004396D0
// 00439750
DEFINE_IMPLEMENTATION(bool BuildingClass::Crossing_Firestorm(ObjectClass*, bool) const, 0x00439A90);
// 00439D40
// 00439E90
// 0043A180
// 0043A4D0
// 0043A520
// 0043A570
DEFINE_IMPLEMENTATION(void BuildingClass::Update_Spied(HouseClass* house), 0x0043ADE0);
// 0043AE50
// 0043AF60
// 0043AFC0
// 0043B340
// 0043B3D0
// 0043B5C0
// 0043B770
// 0043B810
DEFINE_IMPLEMENTATION(void BuildingClass::Read_INI(CCINIClass&), 0x004347C0);
DEFINE_IMPLEMENTATION(void BuildingClass::Write_INI(CCINIClass&), 0x00434D90);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE TeamTypeClass::GetClassID(CLSID*), 0x00628F50);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TeamTypeClass::Load(IStream*), 0x00628ED0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TeamTypeClass::Save(IStream*, BOOL), 0x00628EB0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(TeamTypeClass::TeamTypeClass(const char *), 0x00627D90);
TeamTypeClass::TeamTypeClass(const NoInitClass& noinit) : AbstractTypeClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D7AE8; *((unsigned long*)this + 1) = (unsigned long)0x006D7ACC; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(TeamTypeClass::~TeamTypeClass(), 0x00627EE0);
DEFINE_IMPLEMENTATION(void TeamTypeClass::Detach(AbstractClass*, bool), 0x00628570);
DEFINE_IMPLEMENTATION(RTTIType TeamTypeClass::Fetch_RTTI() const, 0x00629250);
DEFINE_IMPLEMENTATION(int TeamTypeClass::Get_Object_Size(bool) const, 0x00629260);
DEFINE_IMPLEMENTATION(void TeamTypeClass::Object_CRC(CRCEngine&) const, 0x00628F90);
DEFINE_IMPLEMENTATION(int TeamTypeClass::Fetch_Heap_ID() const, 0x00629270);
DEFINE_IMPLEMENTATION(bool TeamTypeClass::Read_INI(CCINIClass&), 0x006285C0);
DEFINE_IMPLEMENTATION(bool TeamTypeClass::Write_INI(CCINIClass&) const, 0x00628950);
DEFINE_IMPLEMENTATION(TeamClass* TeamTypeClass::Create_One_Of(HouseClass*) const, 0x00627F50);
DEFINE_IMPLEMENTATION(void TeamTypeClass::Destroy_All_Of() const, 0x00627FE0);
DEFINE_IMPLEMENTATION(TypeList<const TeamTypeClass*> TeamTypeClass::Suggested_New_Team(HouseClass*, bool), 0x00628020);
// 00628BE0
DEFINE_IMPLEMENTATION(Cell TeamTypeClass::Get_Origin() const, 0x00628C00);
// 006290F0
// 006291E0
// 00629220
DEFINE_IMPLEMENTATION(void TeamTypeClass::Read_Scenario_INI(CCINIClass&, int), 0x00628CD0);
DEFINE_IMPLEMENTATION(void TeamTypeClass::Write_Scenario_INI(CCINIClass&, int), 0x00628DD0);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE TeamClass::GetClassID(CLSID*), 0x00625360);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TeamClass::Load(IStream*), 0x00625250);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TeamClass::Save(IStream*, BOOL), 0x00625340);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(TeamClass::TeamClass(TeamTypeClass *, HouseClass *, void *), 0x00622100);
TeamClass::TeamClass(const NoInitClass& noinit) : AbstractClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D7A54; *((unsigned long*)this + 1) = (unsigned long)0x006D7A38; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(TeamClass::~TeamClass(), 0x00622420);
DEFINE_IMPLEMENTATION(void TeamClass::Detach(AbstractClass*, bool), 0x00623FA0);
DEFINE_IMPLEMENTATION(RTTIType TeamClass::Fetch_RTTI() const, 0x00627A70);
DEFINE_IMPLEMENTATION(int TeamClass::Get_Object_Size(bool) const, 0x00627A60);
DEFINE_IMPLEMENTATION(void TeamClass::Object_CRC(CRCEngine&) const, 0x006253A0);
DEFINE_IMPLEMENTATION(void TeamClass::AI(), 0x00622750);
DEFINE_IMPLEMENTATION(void TeamClass::Assign_Mission_Target(AbstractClass*), 0x00622660);
// 00623360
// 006233B0
// 00623680
DEFINE_IMPLEMENTATION(bool TeamClass::Add(FootClass*), 0x00623780);
DEFINE_IMPLEMENTATION(bool TeamClass::Can_Add(FootClass*, int&) const, 0x00623880);
DEFINE_IMPLEMENTATION(bool TeamClass::Remove(FootClass*, int), 0x00623A00);
DEFINE_IMPLEMENTATION(int TeamClass::Recruit(int typeindex), 0x00623BF0);
DEFINE_IMPLEMENTATION(void TeamClass::Calc_Center(AbstractClass*&, AbstractClass*&) const, 0x00624020);
DEFINE_IMPLEMENTATION(void TeamClass::Took_Damage(FootClass*, ResultType, TechnoClass*), 0x00624440);
DEFINE_IMPLEMENTATION(void TeamClass::Coordinate_Attack(), 0x006245B0);
DEFINE_IMPLEMENTATION(bool TeamClass::Coordinate_Regroup(), 0x00624880);
DEFINE_IMPLEMENTATION(void TeamClass::Coordinate_Move(), 0x0624A90);
DEFINE_IMPLEMENTATION(bool TeamClass::Lagging_Units(), 0x00624E00);
DEFINE_IMPLEMENTATION(bool TeamClass::Coordinate_Conscript(FootClass*), 0x00624FA0);
DEFINE_IMPLEMENTATION(bool TeamClass::Is_A_Member(const FootClass*) const, 0x00625040);
DEFINE_IMPLEMENTATION(bool TeamClass::Is_Leaving_Map() const, 0x00625120);
DEFINE_IMPLEMENTATION(bool TeamClass::Has_Entered_Map() const, 0x00625190);
DEFINE_IMPLEMENTATION(void TeamClass::Scan_Limit(), 0x006251C0);
DEFINE_IMPLEMENTATION(FootClass* TeamClass::Fetch_A_Leader() const, 0x006251F0);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Go_to_Shroud(ScriptMissionClass*, bool), 0x00625520);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Move_To_Cell(ScriptMissionClass*, bool), 0x00625560);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Move_To_Waypoint(ScriptMissionClass*, bool), 0x006255C0);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Attack_Waypoint(ScriptMissionClass*, bool), 0x00625770);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Patrol(ScriptMissionClass*, bool), 0x00625840);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Spy(ScriptMissionClass*, bool), 0x00625980);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Scatter(ScriptMissionClass*, bool), 0x00625A30);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Change_House(ScriptMissionClass*, bool), 0x00625A70);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Change_Team(ScriptMissionClass*, bool), 0x00625AC0);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Change_Script(ScriptMissionClass*, bool), 0x00625B30);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Attack(ScriptMissionClass*, bool), 0x00625B90);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Load(ScriptMissionClass*, bool), 0x00625DF0);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Deploy(ScriptMissionClass*, bool), 0x00626010);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Guard(ScriptMissionClass*, bool), 0x00626200);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Do(ScriptMissionClass*, bool), 0x00626260);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Set_Global(ScriptMissionClass*, bool), 0x006264B0);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Clear_Global(ScriptMissionClass*, bool), 0x006264D0);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Set_Local(ScriptMissionClass*, bool), 0x006264F0);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Clear_Local(ScriptMissionClass*, bool), 0x00626510);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Follow(ScriptMissionClass*, bool), 0x00626530);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Unpanic(ScriptMissionClass*, bool), 0x00626650);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Force_Facing(ScriptMissionClass*, bool), 0x00626680);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Panic(ScriptMissionClass*, bool), 0x00626730);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Go_Berzerk(ScriptMissionClass*, bool), 0x00626760);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Idle_Anim(ScriptMissionClass*, bool), 0x00626790);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Loop(ScriptMissionClass*, bool), 0x006267D0);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Player_Wins(ScriptMissionClass*, bool), 0x006267F0);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Player_Loses(ScriptMissionClass*, bool), 0x00626810);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Play_Speech(ScriptMissionClass*, bool), 0x00626830);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Play_Sound(ScriptMissionClass*, bool), 0x00626850);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Play_Movie(ScriptMissionClass*, bool), 0x00626870);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Play_Music(ScriptMissionClass*, bool), 0x00626890);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Reduce_Tiberium(ScriptMissionClass*, bool), 0x006268B0);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Begin_Production(ScriptMissionClass*, bool), 0x00626920);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Fire_Sale(ScriptMissionClass*, bool), 0x00626940);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Self_Destruct(ScriptMissionClass*, bool), 0x00626960);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Delete_Members(ScriptMissionClass*, bool), 0x006269D0);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Ion_Storm_Start(ScriptMissionClass*, bool), 0x00626A10);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Ion_Storm_End(ScriptMissionClass*, bool), 0x00626A50);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Center_View_On_Team(ScriptMissionClass*, bool), 0x00626A70);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Reshroud_Map(ScriptMissionClass*, bool), 0x00626B20);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Reveal_Map(ScriptMissionClass*, bool), 0x00626B40);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Wait_Until_Loaded(ScriptMissionClass*, bool), 0x00626B60);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Truck_Unload(ScriptMissionClass*, bool), 0x00626BA0);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Truck_Load(ScriptMissionClass*, bool), 0x00626C10);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Attack_Enemy_Building(ScriptMissionClass*, bool), 0x00626C80);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Move_To_Enemy_Building(ScriptMissionClass*, bool), 0x00626D10);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Scout(ScriptMissionClass*, bool), 0x00626E90);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Unload(ScriptMissionClass*, bool), 0x006274B0);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Success(ScriptMissionClass*, bool), 0x00627790);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Flash(ScriptMissionClass*, bool), 0x006278E0);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Play_Animation(ScriptMissionClass*, bool), 0x00627930);
DEFINE_IMPLEMENTATION(void TeamClass::TMission_Talk_Bubble(ScriptMissionClass*, bool), 0x006279F0);
DEFINE_IMPLEMENTATION(void TeamClass::Flash_For(int), 0x00627910);
DEFINE_IMPLEMENTATION(bool TeamClass::Has_Air_Transport(), 0x006277A0);
DEFINE_IMPLEMENTATION(void TeamClass::Team_Members(DynamicVectorClass<const TechnoTypeClass*>&), 0x00627800);
// 00627A20
const char* TeamClass::Name() const { return Class->Name(); }
DEFINE_IMPLEMENTATION(void TeamClass::func_6271F0(BuildingTypeClass*, HouseClass*, FootClass*, int, bool), 0x006271F0);
DEFINE_IMPLEMENTATION(void TeamClass::Suspend_Teams(int, const HouseClass*), 0x00625070);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(TargetClass::TargetClass(AbstractClass *), 0x0061FEE0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(TargetClass::TargetClass(Cell &), 0x0061FF60);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(TargetClass::TargetClass(Coord &), 0x0061FFB0);
DEFINE_IMPLEMENTATION(AbstractTypeClass* xTargetClass::As_TypeClass() const, 0x0061FFF0);
DEFINE_IMPLEMENTATION(TagClass* xTargetClass::As_Tag() const, 0x006200D0);
DEFINE_IMPLEMENTATION(TagTypeClass* xTargetClass::As_TagType() const, 0x006201B0);
DEFINE_IMPLEMENTATION(AbstractClass* xTargetClass::As_Abstract() const, 0x00620290);
DEFINE_IMPLEMENTATION(TechnoClass* xTargetClass::As_Techno() const, 0x00620390);
DEFINE_IMPLEMENTATION(ObjectClass* xTargetClass::As_Object() const, 0x00620460);
DEFINE_IMPLEMENTATION(FootClass* xTargetClass::As_Foot() const, 0x00620540);
DEFINE_IMPLEMENTATION(TriggerClass* xTargetClass::As_Trigger() const, 0x00620620);
DEFINE_IMPLEMENTATION(HouseClass* xTargetClass::As_House() const, 0x00620700);
DEFINE_IMPLEMENTATION(TechnoTypeClass* xTargetClass::As_TechnoType() const, 0x006207E0);
DEFINE_IMPLEMENTATION(TriggerTypeClass* xTargetClass::As_TriggerType() const, 0x006208C0);
DEFINE_IMPLEMENTATION(TeamTypeClass* xTargetClass::As_TeamType() const, 0x006209A0);
DEFINE_IMPLEMENTATION(TerrainClass* xTargetClass::As_Terrain() const, 0x00620A80);
DEFINE_IMPLEMENTATION(BulletClass* xTargetClass::As_Bullet() const, 0x00620B60);
DEFINE_IMPLEMENTATION(AnimClass* xTargetClass::As_Anim() const, 0x00620C40);
DEFINE_IMPLEMENTATION(TeamClass* xTargetClass::As_Team() const, 0x00620D20);
DEFINE_IMPLEMENTATION(InfantryClass* xTargetClass::As_Infantry() const, 0x00620E00);
DEFINE_IMPLEMENTATION(UnitClass* xTargetClass::As_Unit() const, 0x00620EE0);
DEFINE_IMPLEMENTATION(BuildingClass* xTargetClass::As_Building() const, 0x00620FC0);
DEFINE_IMPLEMENTATION(AircraftClass* xTargetClass::As_Aircraft() const, 0x006210A0);
DEFINE_IMPLEMENTATION(CellClass* xTargetClass::As_Cell() const, 0x00621180);
DEFINE_IMPLEMENTATION(int xTargetClass::Pack() const, 0x0050A060);
DEFINE_IMPLEMENTATION(TargetClass xTargetClass::Unpack(int), 0x0050A080);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE TEventClass::GetClassID(CLSID*), 0x00642D60);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TEventClass::Load(IStream*), 0x00642DA0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TEventClass::Save(IStream*, BOOL), 0x00642E00);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(TEventClass::TEventClass(), 0x006420C0);
TEventClass::TEventClass(TEventType event) : Event(event) { Data.Value = 0; *((unsigned long*)this) = (unsigned long)0x006D8564; *((unsigned long*)this + 1) = (unsigned long)0x006D854C; }
TEventClass::TEventClass(const NoInitClass& noinit) : AbstractClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D8564; *((unsigned long*)this + 1) = (unsigned long)0x006D854C; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(TEventClass::~TEventClass(), 0x00642210);
DEFINE_IMPLEMENTATION(void TEventClass::Detach(AbstractClass*, bool), 0x00642CE0);
DEFINE_IMPLEMENTATION(RTTIType TEventClass::Fetch_RTTI() const, 0x00642EF0);
DEFINE_IMPLEMENTATION(int TEventClass::Get_Object_Size(bool) const, 0x00642EE0);
DEFINE_IMPLEMENTATION(void TEventClass::Object_CRC(CRCEngine&) const, 0x00642D00);
DEFINE_IMPLEMENTATION(int TEventClass::Fetch_Heap_ID() const, 0x00642F00);
DEFINE_IMPLEMENTATION(bool TEventClass::operator()(TEventType, HouseClass*, const ObjectClass*, CDTimerClass<FrameTimerClass>&, bool&, TechnoClass*), 0x00642310);
DEFINE_IMPLEMENTATION(bool TEventClass::Is_Temporal() const, 0x00642E20);
DEFINE_IMPLEMENTATION(bool TEventClass::Has_Memory() const, 0x00642E80);
DEFINE_IMPLEMENTATION(void TEventClass::Read_INI(), 0x00642A60);
DEFINE_IMPLEMENTATION(void TEventClass::Build_INI_Entry(char*) const, 0x00642A10);
DEFINE_IMPLEMENTATION(NeedType Event_Needs(TEventType), 0x00642AD0);
DEFINE_IMPLEMENTATION(AttachType Attaches_To(TEventType), 0x00642B90);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE TActionClass::GetClassID(CLSID*), 0x0061D860);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TActionClass::Load(IStream*), 0x0061D8A0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TActionClass::Save(IStream*, BOOL), 0x0061D910);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(TActionClass::TActionClass(), 0x00618B80);
TActionClass::TActionClass(const NoInitClass& noinit) : AbstractClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D77C4; *((unsigned long*)this + 1) = (unsigned long)0x006D77A8; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(TActionClass::~TActionClass(), 0x00618CF0);
DEFINE_IMPLEMENTATION(void TActionClass::Detach(AbstractClass*, bool), 0x00618DF0);
DEFINE_IMPLEMENTATION(RTTIType TActionClass::Fetch_RTTI() const, 0x0061DAA0);
DEFINE_IMPLEMENTATION(int TActionClass::Get_Object_Size(bool) const, 0x0061DA90);
DEFINE_IMPLEMENTATION(void TActionClass::Object_CRC(CRCEngine&) const, 0x0061D930);
DEFINE_IMPLEMENTATION(int TActionClass::Fetch_Heap_ID() const, 0x0061DAB0);
DEFINE_IMPLEMENTATION(bool TActionClass::operator()(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x00619110);
DEFINE_IMPLEMENTATION(void TActionClass::Read_INI(), 0x00618F70);
DEFINE_IMPLEMENTATION(void TActionClass::Build_INI_Entry(char*) const, 0x00618E30);
DEFINE_IMPLEMENTATION(Coord TActionClass::Get_Adjusted_Waypoint(), 0x0061DA50);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_DEACTIVATE_FIRESTORM(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061AB80);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_ACTIVATE_FIRESTORM(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061ABF0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_ION_LIGHTNING_STRIKE(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061AC60);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_REMOVE_PARTICLE_ANIM(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061AC90);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_PARTICLE_ANIM(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061AD10);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_WAKEUP_SELF(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061ADC0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_VEIN_GROWTH(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061AE50);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_TIB_GROWTH(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061AE70);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_ICE_GROWTH(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061AE90);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_WAKEUP_ALL_SLEEP(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061AEB0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_WAKEUP_ALL_HARMLESS(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061AF20);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_WAKEUP_GROUP(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061AFA0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_ANNOUNCE_WIN(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061B030);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_ANNOUNCE_LOSE(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061B050);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_FORCE_END(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061B070);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_DAMAGE(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061B080);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_LIGHT_SMALL(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061B380);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_LIGHT_MEDIUM(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061B3D0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_LIGHT_LARGE(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061B420);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_SELL_ATTACHED(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061B470);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_GO_BERZERK(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061B4E0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_TURN_OFF_ATTACHED(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061B550);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_TURN_ON_ATTACHED(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061B5C0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_CHANGE_HOUSE(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061B630);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_SET_GROUP_ID(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061B6B0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_ALL_CHANGE_HOUSE(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061B6E0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_TEXT_TRIGGER(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061B740);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_MAKE_ALLY(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061B820);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_MAKE_ENEMY(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061B860);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_PREFERRED_TARGET(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061B8A0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_BASE_BUILDING(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061B8C0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_CREEP_SHADOW(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061B980);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_SET_GLOBAL(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061B990);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_CLEAR_GLOBAL(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061B9B0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_REVEAL_SOME(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061B9D0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_REDUCE_TIBERIUM(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061BAF0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_REVEAL_ZONE(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061BB30);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_REVEAL_ALL(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061BC40);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_START_TIMER(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061BCB0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_STOP_TIMER(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061BD00);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_ADD_TIMER(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061BD80);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_SUB_TIMER(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061BDF0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_SET_TIMER(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061BE80);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_PLAY_MOVIE(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061BF00);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_PLAY_INGAME_MOVIE(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061BF20);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_PLAY_SOUND(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061BF30);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_PLAY_SOUND_RANDOM(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061BF50);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_PLAY_SOUND_AT(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C000);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_PLAY_MUSIC(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C030);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_PLAY_SPEECH(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C050);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_1_SPECIAL(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C060);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_FULL_SPECIAL(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C0B0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_DZ(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C110);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_WIN(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C200);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_LOSE(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C230);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_BEGIN_PRODUCTION(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C260);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_FIRE_SALE(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C280);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_AUTOCREATE(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C2A0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_CREATE_TEAM(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C2C0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_DESTROY_TEAM(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C2F0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_FLASH_TEAM(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C310);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_DISABLE_SPEECH(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C330);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_ENABLE_SPEECH(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C340);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_TALK_BUBBLE(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C350);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_REINFORCEMENTS(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C390);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_REINFORCEMENTS_SPECIAL(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C3B0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_ALL_HUNT(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C3D0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_DESTROY_OBJECT(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C3F0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_CHANGE_ZOOM(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C560);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_RESIZE_PLAYER_VIEW(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C570);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_PLAY_ANIM(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C620);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_DO_EXPLOSION(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C720);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_METEOR_IMPACT(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C900);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_ION_STORM_START(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061C9E0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_ION_STORM_STOP(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061CA20);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_LOCK_INPUT(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061CA40);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_UNLOCK_INPUT(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061CA60);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_CENTER_VIEWPOINT(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061CA70);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_ZOOM_IN(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061CB30);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_ZOOM_OUT(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061CBA0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_RESHROUD(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061CC00);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_CHANGE_SPOTLIGHT_BEHAVIOR(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061CC10);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_DESTROY_TRIGGER(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061CCB0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_DESTROY_TAG(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061CD00);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_FORCE_TRIGGER(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061CD50);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_ENABLE_TRIGGER(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061CDA0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_DISABLE_TRIGGER(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061CDE0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_RADAR_EVENT(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061CE20);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_SET_LOCAL(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061CE50);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_CLEAR_LOCAL(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061CE70);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_METEOR_SHOWER(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061CE90);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_SET_AMBIENT_STEP(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061D070);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_SET_AMBIENT_RATE(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061D090);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_SET_AMBIENT_LIGHT(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061D0B0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_BEGIN_AI_TRIGGERS(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061D0E0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_STOP_AI_TRIGGERS(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061D100);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_SET_AI_TRIGGER_TEAM_RATIO(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061D120);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_SET_TEAM_AIRCRAFT_RATIO(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061D140);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_SET_TEAM_INFANTRY_RATIO(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061D160);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_SET_TEAM_UNIT_RATIO(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061D180);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_ION_CANNON(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061D1A0);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_MULTI_MISSILE(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061D230);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_CHEM_MISSILE(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061D460);
DEFINE_IMPLEMENTATION(bool TActionClass::Do_TOGGLE_TRAIN_CARGO(HouseClass*, ObjectClass*, TriggerClass*, const Cell&), 0x0061D690);
DEFINE_IMPLEMENTATION(NeedType Action_Needs(TActionType), 0x0061D6B0);
DEFINE_IMPLEMENTATION(AttachType Attaches_To(TActionType), 0x0061D9C0);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE TaskForceClass::GetClassID(CLSID*), 0x00621D70);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TaskForceClass::Load(IStream*), 0x00621D10);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TaskForceClass::Save(IStream*, BOOL), 0x00621CF0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(TaskForceClass::TaskForceClass(const char *), AbstractTypeClass, 0x00621420);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(TaskForceClass::TaskForceClass(const NoInitClass &), AbstractTypeClass, 0x006214D0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(TaskForceClass::~TaskForceClass(), 0x006214F0);
DEFINE_IMPLEMENTATION(RTTIType TaskForceClass::Fetch_RTTI() const, 0x00621E10);
DEFINE_IMPLEMENTATION(int TaskForceClass::Get_Object_Size(bool) const, 0x00621E20);
DEFINE_IMPLEMENTATION(void TaskForceClass::Object_CRC(CRCEngine&) const, 0x00621DB0);
DEFINE_IMPLEMENTATION(bool TaskForceClass::Read_INI(CCINIClass&), 0x00621A20);
DEFINE_IMPLEMENTATION(bool TaskForceClass::Write_INI(CCINIClass&) const, 0x00621AE0);
// 006216C0
DEFINE_IMPLEMENTATION(bool TaskForceClass::Consists_Only_Of_Infantry() const, 0x00621B80);
// 00621DE0
DEFINE_IMPLEMENTATION(void TaskForceClass::Read_Scenario_INI(CCINIClass&, int), 0x00621780);
DEFINE_IMPLEMENTATION(void TaskForceClass::Write_Scenario_INI(CCINIClass&, int), 0x00621940);

DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE AircraftClass::QueryInterface(REFIID, LPVOID*), 0x004088C0);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE AircraftClass::AddRef(), 0x00408920);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE AircraftClass::Release(), 0x00408930);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE AircraftClass::GetClassID(CLSID*), 0x0040F440);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE AircraftClass::Load(IStream*), 0x0040EAD0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE AircraftClass::Save(IStream*, BOOL), 0x0040ECD0);
DEFINE_IMPLEMENTATION(LONG AircraftClass::Landing_Altitude(), 0x0040EDD0);
DEFINE_IMPLEMENTATION(LONG AircraftClass::Landing_Direction(), 0x0040EE70);
DEFINE_IMPLEMENTATION(BOOL AircraftClass::Is_Loaded(), 0x0040EEC0);
DEFINE_IMPLEMENTATION(LONG AircraftClass::Is_Strafe(), 0x0040EEE0);
DEFINE_IMPLEMENTATION(LONG AircraftClass::Is_Locked(), 0x0040EF30);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(AircraftClass::AircraftClass(AircraftTypeClass *, HouseClass *), FootClass, 0x004085D0);
AircraftClass::AircraftClass(const NoInitClass& noinit) : FootClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006CADF8; *((unsigned long*)this + 1) = (unsigned long)0x006CADDC; *((unsigned long*)this + 212) = (unsigned long)0x006CADB8; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(AircraftClass::~AircraftClass(), 0x0040DB20);
DEFINE_IMPLEMENTATION(void AircraftClass::Init(), 0x00408820);
DEFINE_IMPLEMENTATION(void AircraftClass::Detach(AbstractClass*, bool), 0x0040EDA0);
DEFINE_IMPLEMENTATION(RTTIType AircraftClass::Fetch_RTTI() const, 0x0040F430);
DEFINE_IMPLEMENTATION(int AircraftClass::Get_Object_Size(bool) const, 0x0040F410);
DEFINE_IMPLEMENTATION(void AircraftClass::Object_CRC(CRCEngine&) const, 0x0040ED20);
DEFINE_IMPLEMENTATION(void AircraftClass::AI(), 0x004090C0);
DEFINE_IMPLEMENTATION(ActionType AircraftClass::What_Action(const ObjectClass*, bool), 0x0040B9E0);
DEFINE_IMPLEMENTATION(ActionType AircraftClass::What_Action(const Cell&, bool, bool) const, 0x0040B7E0);
DEFINE_IMPLEMENTATION(LayerType AircraftClass::In_Which_Layer() const, 0x0040E520);
DEFINE_IMPLEMENTATION(bool AircraftClass::entry_80() const, 0x0040EFA0);
DEFINE_IMPLEMENTATION(const ObjectTypeClass* AircraftClass::Class_Of() const, 0x0040F4B0);
DEFINE_IMPLEMENTATION(const char* AircraftClass::Full_Name() const, 0x0040F480);
DEFINE_IMPLEMENTATION(bool AircraftClass::Unlimbo(const Coord&, Dir256), 0x00408940);
DEFINE_IMPLEMENTATION(ExitType AircraftClass::Exit_Object(const TechnoClass*), 0x00409920);
DEFINE_IMPLEMENTATION(void AircraftClass::Draw_It(Point2D&, Rect&) const, 0x00408AD0);
DEFINE_IMPLEMENTATION(void AircraftClass::Look(bool, bool), 0x0040E550);
DEFINE_IMPLEMENTATION(bool AircraftClass::Active_Click_With(ActionType, ObjectClass*, bool), 0x0040B740);
DEFINE_IMPLEMENTATION(bool AircraftClass::Active_Click_With(ActionType, Cell&, bool), 0x0040B690);
DEFINE_IMPLEMENTATION(ResultType AircraftClass::Take_Damage(int&, int, const WarheadTypeClass*, const ObjectClass*, bool, bool), 0x0040A1E0);
DEFINE_IMPLEMENTATION(void AircraftClass::Scatter(const Coord&, bool, bool), 0x0040DCE0);
DEFINE_IMPLEMENTATION(RadioMessageType AircraftClass::Receive_Message(RadioClass*, RadioMessageType, long&), 0x0040C8A0);
DEFINE_IMPLEMENTATION(MoveType AircraftClass::Can_Enter_Cell(const CellClass*, FacingType, int, const CellClass*, bool), 0x0040CDF0);
DEFINE_IMPLEMENTATION(bool AircraftClass::Commence(), 0x0040EF40);
DEFINE_IMPLEMENTATION(bool AircraftClass::Ready_To_Commence() const, 0x0040ECF0);
DEFINE_IMPLEMENTATION(int AircraftClass::Mission_Attack(), 0x0040BA40);
DEFINE_IMPLEMENTATION(int AircraftClass::Mission_Guard(), 0x0040DD10);
DEFINE_IMPLEMENTATION(int AircraftClass::Mission_Guard_Area(), 0x0040E0A0);
DEFINE_IMPLEMENTATION(int AircraftClass::Mission_Hunt(), 0x00408FB0);
DEFINE_IMPLEMENTATION(int AircraftClass::Mission_Move(), 0x0040A350);
DEFINE_IMPLEMENTATION(int AircraftClass::Mission_Retreat(), 0x00409910);
DEFINE_IMPLEMENTATION(int AircraftClass::Mission_Unload(), 0x004093F0);
DEFINE_IMPLEMENTATION(int AircraftClass::Mission_Enter(), 0x0040D360);
DEFINE_IMPLEMENTATION(int AircraftClass::Mission_Patrol(), 0x0040AEF0);
DEFINE_IMPLEMENTATION(DirType AircraftClass::Turret_Facing() const, 0x0040F490);
DEFINE_IMPLEMENTATION(FacingType AircraftClass::Desired_Load_Dir(const ObjectClass*, Cell&) const, 0x0040CCE0);
DEFINE_IMPLEMENTATION(DirType AircraftClass::Fire_Direction() const, 0x0040DB00);
DEFINE_IMPLEMENTATION(void AircraftClass::Player_Assign_Mission(MissionType, AbstractClass*, AbstractClass*), 0x0040B760);
DEFINE_IMPLEMENTATION(void AircraftClass::Reduce_Ammunition(), 0x0040EF90);
DEFINE_IMPLEMENTATION(FireErrorType AircraftClass::Can_Fire(AbstractClass*, WeaponSlotType) const, 0x0040E110);
DEFINE_IMPLEMENTATION(const BulletClass* AircraftClass::Fire_At(AbstractClass*, WeaponSlotType), 0x00409B70);
DEFINE_IMPLEMENTATION(void AircraftClass::Assign_Destination(const AbstractClass*, bool), 0x0040E1B0);
DEFINE_IMPLEMENTATION(bool AircraftClass::Enter_Idle_Mode(bool, bool), 0x0040B310);
DEFINE_IMPLEMENTATION(bool AircraftClass::entry_368(), 0x0040EF50);
DEFINE_IMPLEMENTATION(void AircraftClass::Draw_Rotors(Point2D&, Rect&) const, 0x00408FA0);
DEFINE_IMPLEMENTATION(int AircraftClass::Paradrop_Cargo(), 0x00409A70);
DEFINE_IMPLEMENTATION(int AircraftClass::Drop_Off_Cargo(), 0x0040A750);
DEFINE_IMPLEMENTATION(int AircraftClass::Do_Mission_Move_Carryall(), 0x0040A960);
DEFINE_IMPLEMENTATION(Dir256 AircraftClass::Pose_Dir() const, 0x0040BA30);
DEFINE_IMPLEMENTATION(CellClass* AircraftClass::New_LZ(CellClass*), 0x0040C610);
DEFINE_IMPLEMENTATION(CellClass* AircraftClass::Good_Fire_Location(AbstractClass*) const, 0x0040CF00);
DEFINE_IMPLEMENTATION(bool AircraftClass::Cell_Seems_Ok(Cell&, bool) const, 0x0040D260);
DEFINE_IMPLEMENTATION(CellClass* AircraftClass::Good_LZ(), 0x0040D710);
DEFINE_IMPLEMENTATION(bool AircraftClass::On_Death(ObjectClass*), 0x0040EFB0);
DEFINE_IMPLEMENTATION(void AircraftClass::Read_INI(CCINIClass&), 0x0040E7A0);
DEFINE_IMPLEMENTATION(void AircraftClass::Write_INI(CCINIClass&), 0x0040E620);
DEFINE_IMPLEMENTATION(bool AircraftClass::Counts_As_Civ_Evac(const ObjectClass*), 0x00408580);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE InfantryClass::GetClassID(CLSID*), 0x004D9E20);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE InfantryClass::Load(IStream*), 0x004D92F0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE InfantryClass::Save(IStream*, BOOL), 0x004D94D0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(InfantryClass::InfantryClass(InfantryTypeClass *, HouseClass *), FootClass, 0x004D1FD0);
InfantryClass::InfantryClass(const NoInitClass& noinit) : FootClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D211C; *((unsigned long*)this + 1) = (unsigned long)0x006D2100; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(InfantryClass::~InfantryClass(), 0x004D2240);
DEFINE_IMPLEMENTATION(void InfantryClass::Init(), 0x004D21F0);
DEFINE_IMPLEMENTATION(void InfantryClass::Detach(AbstractClass*, bool), 0x004D40C0);
DEFINE_IMPLEMENTATION(RTTIType InfantryClass::Fetch_RTTI() const, 0x004D9E60);
DEFINE_IMPLEMENTATION(int InfantryClass::Get_Object_Size(bool) const, 0x004D9E00);
DEFINE_IMPLEMENTATION(void InfantryClass::Object_CRC(CRCEngine&) const, 0x004D9640);
DEFINE_IMPLEMENTATION(void InfantryClass::AI(), 0x004D4EB0);
DEFINE_IMPLEMENTATION(ShapeSet* const InfantryClass::Get_Image_Data() const, 0x004D90B0);
DEFINE_IMPLEMENTATION(ActionType InfantryClass::What_Action(const ObjectClass*, bool), 0x004D78B0);
DEFINE_IMPLEMENTATION(ActionType InfantryClass::What_Action(const Cell&, bool, bool) const, 0x004D6FB0);
DEFINE_IMPLEMENTATION(const ObjectTypeClass* InfantryClass::Class_Of() const, 0x004D7B20);
DEFINE_IMPLEMENTATION(const char* InfantryClass::Full_Name() const, 0x004D77A0);
DEFINE_IMPLEMENTATION(bool InfantryClass::Limbo(), 0x004D6B20);
DEFINE_IMPLEMENTATION(bool InfantryClass::Unlimbo(const Coord&, Dir256), 0x004D6BD0);
DEFINE_IMPLEMENTATION(bool InfantryClass::Paradrop(Coord&), 0x004D9180);
DEFINE_IMPLEMENTATION(void InfantryClass::Set_Occupy_Bit(Coord&), 0x004D91D0);
DEFINE_IMPLEMENTATION(void InfantryClass::Clear_Occupy_Bit(Coord&), 0x004D9260);
DEFINE_IMPLEMENTATION(void InfantryClass::Draw_It(Point2D&, Rect&) const, 0x004D2D50);
DEFINE_IMPLEMENTATION(bool InfantryClass::Active_Click_With(ActionType, ObjectClass*, bool), 0x004D9E70);
DEFINE_IMPLEMENTATION(bool InfantryClass::Active_Click_With(ActionType, Cell&, bool), 0x004D7710);
DEFINE_IMPLEMENTATION(ResultType InfantryClass::Take_Damage(int&, int, const WarheadTypeClass*, const ObjectClass*, bool, bool), 0x004D2400);
DEFINE_IMPLEMENTATION(void InfantryClass::Scatter(const Coord&, bool, bool), 0x004D60A0);
DEFINE_IMPLEMENTATION(void InfantryClass::Per_Cell_Process(PCPType), 0x004D3240);
DEFINE_IMPLEMENTATION(MoveType InfantryClass::Can_Enter_Cell(const CellClass*, FacingType, int, const CellClass*, bool), 0x004D5210);
DEFINE_IMPLEMENTATION(bool InfantryClass::Ready_To_Commence() const, 0x004D9510);
DEFINE_IMPLEMENTATION(int InfantryClass::Mission_Attack(), 0x004D7800);
DEFINE_IMPLEMENTATION(int InfantryClass::Mission_Guard(), 0x004D9D30);
DEFINE_IMPLEMENTATION(Coord InfantryClass::entry_28C(WeaponSlotType) const, 0x004D96E0);
DEFINE_IMPLEMENTATION(bool InfantryClass::Is_Immobilized() const, 0x004D5B90);
DEFINE_IMPLEMENTATION(bool InfantryClass::Is_Renovator() const, 0x004D9D20);
DEFINE_IMPLEMENTATION(FireErrorType InfantryClass::Can_Fire(AbstractClass*, WeaponSlotType) const, 0x004D5AA0);
DEFINE_IMPLEMENTATION(AbstractClass* InfantryClass::Greatest_Threat(ThreatType, Coord&, bool) const, 0x004D6D10);
DEFINE_IMPLEMENTATION(void InfantryClass::Assign_Target(AbstractClass*) const, 0x004D4770);
DEFINE_IMPLEMENTATION(const BulletClass* InfantryClass::Fire_At(AbstractClass*, WeaponSlotType), 0x004D6B50);
DEFINE_IMPLEMENTATION(bool InfantryClass::Is_Ready_To_Random_Animate() const, 0x004D9110);
DEFINE_IMPLEMENTATION(bool InfantryClass::Random_Animate(), 0x004D5D90);
DEFINE_IMPLEMENTATION(void InfantryClass::Assign_Destination(const AbstractClass*, bool), 0x004D40F0);
DEFINE_IMPLEMENTATION(bool InfantryClass::Enter_Idle_Mode(bool, bool), 0x004D5BD0);
DEFINE_IMPLEMENTATION(void InfantryClass::entry_378(), 0x004D9770);
DEFINE_IMPLEMENTATION(bool InfantryClass::entry_37C(), 0x004D9850);
DEFINE_IMPLEMENTATION(bool InfantryClass::Start_Driver(Coord&), 0x004D6800);
DEFINE_IMPLEMENTATION(bool InfantryClass::Stop_Driver(), 0x004D6750);
DEFINE_IMPLEMENTATION(void InfantryClass::entry_390(), 0x004D9A90);
DEFINE_IMPLEMENTATION(void InfantryClass::entry_394(), 0x004D95C0);
DEFINE_IMPLEMENTATION(void InfantryClass::entry_398(), 0x004D95F0);
DEFINE_IMPLEMENTATION(void InfantryClass::entry_39C(int), 0x004D9610);
DEFINE_IMPLEMENTATION(int InfantryClass::Current_Speed(), 0x004D9720);
DEFINE_IMPLEMENTATION(void InfantryClass::Approach_Target(), 0x004D9CE0);
DEFINE_IMPLEMENTATION(void InfantryClass::entry_3B8(), 0x004D94F0);
DEFINE_IMPLEMENTATION(bool InfantryClass::Do_Action(DoType, bool, bool), 0x004D6600);
DEFINE_IMPLEMENTATION(int InfantryClass::Shape_Number() const, 0x004D2BA0);
DEFINE_IMPLEMENTATION(void InfantryClass::Tunnel_AI(), 0x004D4830);
DEFINE_IMPLEMENTATION(void InfantryClass::Fear_AI(), 0x004D8100);
DEFINE_IMPLEMENTATION(bool InfantryClass::Edge_Of_World_AI(), 0x004D8310);
DEFINE_IMPLEMENTATION(bool InfantryClass::Theft_AI(), 0x004D8390);
DEFINE_IMPLEMENTATION(void InfantryClass::Firing_AI(), 0x004D8750);
DEFINE_IMPLEMENTATION(void InfantryClass::Doing_AI(), 0x004D8AA0);
DEFINE_IMPLEMENTATION(void InfantryClass::Movement_AI(), 0x004D8CB0);
DEFINE_IMPLEMENTATION(bool InfantryClass::Is_JumpJet(), 0x004D9AA0);
// 004D9B70
DEFINE_IMPLEMENTATION(void InfantryClass::Read_INI(CCINIClass&), 0x004D7B30);
DEFINE_IMPLEMENTATION(void InfantryClass::Write_INI(CCINIClass&), 0x004D7F50);

DEFINE_IMPLEMENTATION(void Speak(VoxType, bool), 0x00665800);
DEFINE_IMPLEMENTATION(void Speak_AI(), 0x00665940);
DEFINE_IMPLEMENTATION(void Stop_Speaking(), 0x00665AF0);
DEFINE_IMPLEMENTATION(bool Is_Speaking(), 0x00665B20);
DEFINE_IMPLEMENTATION(void Set_Speech_Volume(int), 0x00665B70);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(VocClass::VocClass(const char *), 0x00664840);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(VocClass::~VocClass(), 0x00664920);
DEFINE_IMPLEMENTATION(void VocClass::Read_INI(CCINIClass&), 0x00664970);
DEFINE_IMPLEMENTATION(bool VocClass::Can_Play() const, 0x006651F0);
DEFINE_IMPLEMENTATION(int VocClass::Play(float, int), 0x00664A50);
DEFINE_IMPLEMENTATION(int VocClass::Play(float), 0x00664B00);
DEFINE_IMPLEMENTATION(int Sound_Effect(VocType, float, int), 0x00664BA0);
DEFINE_IMPLEMENTATION(int Voice_Sound_Effect(VocType, float), 0x00664C60);
DEFINE_IMPLEMENTATION(void Static_Sound(VocType, const Coord&), 0x00664D10);
DEFINE_IMPLEMENTATION(void VocClass::Process(CCINIClass&), 0x00664EC0);
DEFINE_IMPLEMENTATION(void VocClass::Clear(), 0x00665080);
DEFINE_IMPLEMENTATION(VocType VocClass::VocType_From_Voc(VocClass*), 0x006651C0);
DEFINE_IMPLEMENTATION(VocType VocClass::From_Name(const char*), 0x00665100);
DEFINE_IMPLEMENTATION(VocClass* VocClass::Voc_From_Name(const char*), 0x00665140);
DEFINE_IMPLEMENTATION(const char* VocClass::INI_Name_From(VocType), 0x006651A0);

DEFINE_IMPLEMENTATION(void IonStorm_Init_Clear(), 0x004EC760);
DEFINE_IMPLEMENTATION(HRESULT IonStorm_Save(IStream*), 0x004EC780);
DEFINE_IMPLEMENTATION(HRESULT IonStorm_Load(IStream*), 0x004EC7D0);
DEFINE_IMPLEMENTATION(void IonStorm_Do_Screen_Static(), 0x004EC820);
DEFINE_IMPLEMENTATION(void IonStorm_Set_Active(bool), 0x004EC910);
DEFINE_IMPLEMENTATION(void IonStorm_Start(int, int), 0x004EC920);
DEFINE_IMPLEMENTATION(void IonStorm_Stop(), 0x004ECC70);
DEFINE_IMPLEMENTATION(bool IonStorm_Is_Active(), 0x004ECEB0);
DEFINE_IMPLEMENTATION(void IonStorm_Lightning_Strike_At(Cell), 0x004ECEC0);
DEFINE_IMPLEMENTATION(void IonStorm_AI(), 0x004ED280);
DEFINE_IMPLEMENTATION(void IonStorm_Init(bool), 0x004ED5F0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(IonBlastClass::IonBlastClass(Coord), 0x004EDC20);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(IonBlastClass::~IonBlastClass(), 0x004EDCA0);
DEFINE_IMPLEMENTATION(void IonBlastClass::AI(), 0x004EDCF0);
DEFINE_IMPLEMENTATION(void IonBlastClass::Draw_It(), 0x004EE7F0);
DEFINE_IMPLEMENTATION(void IonBlastClass::Update_All(), 0x004EE580);
DEFINE_IMPLEMENTATION(void IonBlastClass::Draw_All(), 0x004EEAC0);
DEFINE_IMPLEMENTATION(void IonBlastClass::One_Time(), 0x004EE5A0);
DEFINE_IMPLEMENTATION(void IonBlastClass::Clear_All(), 0x004EE7C0);

BounceClass::BounceClass() {}
BounceClass::BounceClass(const NoInitClass&) {}
BounceClass::~BounceClass() {}
// 004245B0
// 00424700
DEFINE_IMPLEMENTATION(Coord BounceClass::Get_Coord() const, 0x00004248C0);
// 00424900
// 00424930
// 00424A20

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE AnimClass::GetClassID(CLSID*), 0x00417500);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE AnimClass::Load(IStream*), 0x004164B0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE AnimClass::Save(IStream*, BOOL), 0x00416510);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(AnimClass::AnimClass(), ObjectClass, 0x00414170);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(AnimClass::AnimClass(const AnimTypeClass *, Coord &, unsigned, unsigned, unsigned, int), ObjectClass, 0x00413AE0);
AnimClass::AnimClass(const NoInitClass& noinit) : ObjectClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006CB948; *((unsigned long*)this + 1) = (unsigned long)0x006CB92C; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(AnimClass::~AnimClass(), 0x004142B0);
DEFINE_IMPLEMENTATION(void AnimClass::Detach(AbstractClass*, bool), 0x00416390);
DEFINE_IMPLEMENTATION(RTTIType AnimClass::Fetch_RTTI() const, 0x00417540);
DEFINE_IMPLEMENTATION(int AnimClass::Get_Object_Size(bool) const, 0x004174F0);
DEFINE_IMPLEMENTATION(void AnimClass::Object_CRC(CRCEngine&) const, 0x00416530);
DEFINE_IMPLEMENTATION(Coord AnimClass::Center_Coord() const, 0x00414540);
DEFINE_IMPLEMENTATION(void AnimClass::AI(), 0x00414E80);
DEFINE_IMPLEMENTATION(LayerType AnimClass::In_Which_Layer() const, 0x00415D30);
DEFINE_IMPLEMENTATION(const ObjectTypeClass* AnimClass::Class_Of() const, 0x00416640);
DEFINE_IMPLEMENTATION(int AnimClass::Sort_Y() const, 0x00414530);
DEFINE_IMPLEMENTATION(bool AnimClass::Limbo(), 0x00416650);
DEFINE_IMPLEMENTATION(void AnimClass::Delete_Me(), 0x004167C0);
DEFINE_IMPLEMENTATION(bool AnimClass::Render(Rect&, bool, bool), 0x004145C0);
DEFINE_IMPLEMENTATION(Cell* AnimClass::Occupy_List(bool) const, 0x00414C80);
DEFINE_IMPLEMENTATION(void AnimClass::Draw_It(Point2D&, Rect&) const, 0x004145F0);
DEFINE_IMPLEMENTATION(bool AnimClass::Mark(MarkType), 0x00414C60);
DEFINE_IMPLEMENTATION(int AnimClass::Get_Height() const, 0x004167E0);
DEFINE_IMPLEMENTATION(int AnimClass::Bounce_AI(), 0x00414CE0);
DEFINE_IMPLEMENTATION(int AnimClass::Stage_Count() const, 0x00416630);
DEFINE_IMPLEMENTATION(void AnimClass::Attach_To(ObjectClass*), 0x00415C00);
DEFINE_IMPLEMENTATION(void AnimClass::Start(), 0x00415D60);
DEFINE_IMPLEMENTATION(void AnimClass::Middle(), 0x00415F40);
DEFINE_IMPLEMENTATION(void AnimClass::Disable(), 0x00416490);
DEFINE_IMPLEMENTATION(void AnimClass::Enable(), 0x004164A0);
DEFINE_IMPLEMENTATION(void AnimClass::Vein_Attack_AI(), 0x004166C0);
DEFINE_IMPLEMENTATION(void AnimClass::Flaming_Guy_AI(), 0x00416820);
// 00416E90
// 00417270
DEFINE_IMPLEMENTATION(void AnimClass::Init(), 0x00417340);
DEFINE_IMPLEMENTATION(void AnimClass::Do_Atom_Damage(HousesType, Cell&), 0x004163E0);
DEFINE_IMPLEMENTATION(void Shorten_Attached_Anims(), 0x00414500);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE AnimTypeClass::GetClassID(CLSID*), 0x004197B0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE AnimTypeClass::Load(IStream*), 0x00419640);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE AnimTypeClass::Save(IStream*, BOOL), 0x00419790);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(AnimTypeClass::AnimTypeClass(const char *), ObjectTypeClass, 0x004184C0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(AnimTypeClass::AnimTypeClass(const NoInitClass &), ObjectTypeClass, 0x004187A0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(AnimTypeClass::~AnimTypeClass(), 0x004187C0);
DEFINE_IMPLEMENTATION(void AnimTypeClass::Detach(AbstractClass*, bool), 0x00419A00);
DEFINE_IMPLEMENTATION(RTTIType AnimTypeClass::Fetch_RTTI() const, 0x00419BA0);
DEFINE_IMPLEMENTATION(int AnimTypeClass::Get_Object_Size(bool) const, 0x00419BC0);
DEFINE_IMPLEMENTATION(void AnimTypeClass::Object_CRC(CRCEngine&) const, 0x004197F0);
DEFINE_IMPLEMENTATION(int AnimTypeClass::Fetch_Heap_ID() const, 0x00419BB0);
DEFINE_IMPLEMENTATION(void AnimTypeClass::entry_64(), 0x004189E0);
DEFINE_IMPLEMENTATION(bool AnimTypeClass::Read_INI(CCINIClass&), 0x00418C20);
DEFINE_IMPLEMENTATION(bool AnimTypeClass::Create_And_Place(Cell&, HouseClass*) const, 0x00419BD0);
DEFINE_IMPLEMENTATION(ObjectClass* const AnimTypeClass::Create_One_Of(HouseClass*) const, 0x00419BE0);
DEFINE_IMPLEMENTATION(ShapeSet* const AnimTypeClass::Get_Image_Data() const, 0x00419A20);
DEFINE_IMPLEMENTATION(void AnimTypeClass::Load_Image(const char*), 0x00418A70);
DEFINE_IMPLEMENTATION(void AnimTypeClass::Free_Image(), 0x0419B40);
DEFINE_IMPLEMENTATION(void AnimTypeClass::Init(TheaterType), 0x00418890);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE TerrainTypeClass::GetClassID(CLSID*), 0x00641C60);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TerrainTypeClass::Load(IStream*), 0x00641B80);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TerrainTypeClass::Save(IStream*, BOOL), 0x00641C40);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(TerrainTypeClass::TerrainTypeClass(const char *), ObjectTypeClass, 0x006414E0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(TerrainTypeClass::TerrainTypeClass(const NoInitClass &), ObjectTypeClass, 0x00641620);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(TerrainTypeClass::~TerrainTypeClass(), 0x00641640);
DEFINE_IMPLEMENTATION(RTTIType TerrainTypeClass::Fetch_RTTI() const, 0x00641D30);
DEFINE_IMPLEMENTATION(int TerrainTypeClass::Get_Object_Size(bool) const, 0x00641D40);
DEFINE_IMPLEMENTATION(void TerrainTypeClass::Object_CRC(CRCEngine&) const, 0x00641AF0);
DEFINE_IMPLEMENTATION(int TerrainTypeClass::Fetch_Heap_ID() const, 0x00641D60);
DEFINE_IMPLEMENTATION(bool TerrainTypeClass::Read_INI(CCINIClass&), 0x00641840);
DEFINE_IMPLEMENTATION(Coord TerrainTypeClass::Coord_Fixup(Coord*) const, 0x00641A80);
DEFINE_IMPLEMENTATION(bool TerrainTypeClass::Create_And_Place(Cell&, HouseClass*) const, 0x00641780);
DEFINE_IMPLEMENTATION(ObjectClass* const TerrainTypeClass::Create_One_Of(HouseClass*) const, 0x006417B0);
DEFINE_IMPLEMENTATION(Cell* TerrainTypeClass::Occupy_List(bool) const, 0x006417E0);
DEFINE_IMPLEMENTATION(void TerrainTypeClass::Init(TheaterType), 0x006416B0);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE ParticleTypeClass::GetClassID(CLSID*), 0x005AF900);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE ParticleTypeClass::Load(IStream*), 0x005AF940);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE ParticleTypeClass::Save(IStream*, BOOL), 0x005AFA70);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(ParticleTypeClass::ParticleTypeClass(const char *), ObjectTypeClass, 0x005AEF00);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(ParticleTypeClass::ParticleTypeClass(const NoInitClass &), ObjectTypeClass, 0x005AF0E0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(ParticleTypeClass::~ParticleTypeClass(), 0x005AF140);
DEFINE_IMPLEMENTATION(void ParticleTypeClass::Detach(AbstractClass*, bool), 0x005AFB80);
DEFINE_IMPLEMENTATION(RTTIType ParticleTypeClass::Fetch_RTTI() const, 0x005AFBF0);
DEFINE_IMPLEMENTATION(int ParticleTypeClass::Get_Object_Size(bool) const, 0x005AFBE0);
DEFINE_IMPLEMENTATION(void ParticleTypeClass::Object_CRC(CRCEngine&) const, 0x005AF7C0);
DEFINE_IMPLEMENTATION(bool ParticleTypeClass::Read_INI(CCINIClass&), 0x005AF240);
DEFINE_IMPLEMENTATION(bool ParticleTypeClass::Create_And_Place(Cell&, HouseClass*) const, 0x005AFC00);
DEFINE_IMPLEMENTATION(ObjectClass* const ParticleTypeClass::Create_One_Of(HouseClass*) const, 0x005AFC10);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE ParticleSystemTypeClass::GetClassID(CLSID*), 0x005AEAA0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE ParticleSystemTypeClass::Load(IStream*), 0x005AEAE0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE ParticleSystemTypeClass::Save(IStream*, BOOL), 0x005AEB20);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(ParticleSystemTypeClass::ParticleSystemTypeClass(const char *), ObjectTypeClass, 0x005AE3D0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(ParticleSystemTypeClass::ParticleSystemTypeClass(const NoInitClass &), ObjectTypeClass, 0x005AE540);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(ParticleSystemTypeClass::~ParticleSystemTypeClass(), 0x005AE560);
DEFINE_IMPLEMENTATION(RTTIType ParticleSystemTypeClass::Fetch_RTTI() const, 0x005AEC20);
DEFINE_IMPLEMENTATION(int ParticleSystemTypeClass::Get_Object_Size(bool) const, 0x005AEC10);
DEFINE_IMPLEMENTATION(void ParticleSystemTypeClass::Object_CRC(CRCEngine&) const, 0x005AEA00);
DEFINE_IMPLEMENTATION(bool ParticleSystemTypeClass::Read_INI(CCINIClass&), 0x005AE5D0);
DEFINE_IMPLEMENTATION(bool ParticleSystemTypeClass::Create_And_Place(Cell&, HouseClass*) const, 0x005AEC30);
DEFINE_IMPLEMENTATION(ObjectClass* const ParticleSystemTypeClass::Create_One_Of(HouseClass*) const, 0x005AEC40);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE VoxelAnimClass::GetClassID(CLSID*), 0x0065F0C0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE VoxelAnimClass::Load(IStream*), 0x0065EF90);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE VoxelAnimClass::Save(IStream*, BOOL), 0x0065F000);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(VoxelAnimClass::VoxelAnimClass(), ObjectClass, 0x0065DE30);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(VoxelAnimClass::VoxelAnimClass(const VoxelAnimTypeClass *, Coord &, HouseClass *), ObjectClass, 0x0065D950);
VoxelAnimClass::VoxelAnimClass(const NoInitClass& noinit) : ObjectClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D9050; *((unsigned long*)this + 1) = (unsigned long)0x006D9034; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(VoxelAnimClass::~VoxelAnimClass(), 0x0065DF10);
DEFINE_IMPLEMENTATION(RTTIType VoxelAnimClass::Fetch_RTTI() const, 0x0065F110);
DEFINE_IMPLEMENTATION(int VoxelAnimClass::Get_Object_Size(bool) const, 0x0065F100);
DEFINE_IMPLEMENTATION(void VoxelAnimClass::Object_CRC(CRCEngine&) const, 0x0065F020);
DEFINE_IMPLEMENTATION(void VoxelAnimClass::AI(), 0x0065E3F0);
DEFINE_IMPLEMENTATION(LayerType VoxelAnimClass::In_Which_Layer() const, 0x0065EF80);
DEFINE_IMPLEMENTATION(const ObjectTypeClass* VoxelAnimClass::Class_Of() const, 0x0065F120);
DEFINE_IMPLEMENTATION(bool VoxelAnimClass::Render(Rect&, bool, bool), 0x0065E000);
DEFINE_IMPLEMENTATION(Cell* VoxelAnimClass::Occupy_List(bool) const, 0x0065F130);
DEFINE_IMPLEMENTATION(void VoxelAnimClass::Draw_It(Point2D&, Rect&) const, 0x0065E050);
DEFINE_IMPLEMENTATION(void VoxelAnimClass::Init(), 0x0065E3C0);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE AITriggerTypeClass::GetClassID(CLSID*), 0x00410660);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE AITriggerTypeClass::Load(IStream*), 0x004106A0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE AITriggerTypeClass::Save(IStream*, BOOL), 0x00410710);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(AITriggerTypeClass::AITriggerTypeClass(const char *), AbstractTypeClass, 0x004104E0);
AITriggerTypeClass::AITriggerTypeClass(const NoInitClass& noinit) : AbstractTypeClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006CB308; *((unsigned long*)this + 1) = (unsigned long)0x006CB2EC; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(AITriggerTypeClass::~AITriggerTypeClass(), 0x004105F0);
DEFINE_IMPLEMENTATION(RTTIType AITriggerTypeClass::Fetch_RTTI() const, 0x00411BF0);
DEFINE_IMPLEMENTATION(int AITriggerTypeClass::Get_Object_Size(bool) const, 0x00411C00);
DEFINE_IMPLEMENTATION(void AITriggerTypeClass::Object_CRC(CRCEngine&) const, 0x00410730);
DEFINE_IMPLEMENTATION(bool AITriggerTypeClass::Read_INI(CCINIClass&), 0x004112E0);
DEFINE_IMPLEMENTATION(bool AITriggerTypeClass::Write_INI(CCINIClass&) const, 0x00411830);
DEFINE_IMPLEMENTATION(bool AITriggerTypeClass::Process(HouseClass*, HouseClass*, bool), 0x00410840);
DEFINE_IMPLEMENTATION(bool AITriggerTypeClass::Check_Enemy_Owns(HouseClass*, HouseClass*), 0x00410BD0);
DEFINE_IMPLEMENTATION(bool AITriggerTypeClass::Check_House_Owns(HouseClass*, HouseClass*), 0x00410D70);
DEFINE_IMPLEMENTATION(bool AITriggerTypeClass::Check_Enemy_Yellow_Power(HouseClass*, HouseClass*), 0x00410F10);
DEFINE_IMPLEMENTATION(bool AITriggerTypeClass::Check_Enemy_Red_Power(HouseClass*, HouseClass*), 0x00410F60);
DEFINE_IMPLEMENTATION(bool AITriggerTypeClass::Check_Enemy_Money(HouseClass*, HouseClass*), 0x00410FB0);
DEFINE_IMPLEMENTATION(void AITriggerTypeClass::Set_Condition_Object(TechnoTypeClass*), 0x00411A40);
DEFINE_IMPLEMENTATION(void AITriggerTypeClass::Set_First_TeamType(TeamTypeClass*), 0x00411A50);
DEFINE_IMPLEMENTATION(void AITriggerTypeClass::Set_Second_TeamType(TeamTypeClass*), 0x00411A60);
DEFINE_IMPLEMENTATION(void AITriggerTypeClass::Record_Success(), 0x00411A70);
DEFINE_IMPLEMENTATION(void AITriggerTypeClass::Record_Fail(), 0x00411B30);
DEFINE_IMPLEMENTATION(void AITriggerTypeClass::Read_Scenario_INI(CCINIClass&, int), 0x00411060);
DEFINE_IMPLEMENTATION(void AITriggerTypeClass::Write_Scenario_INI(CCINIClass&, int), 0x00411200);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE TagTypeClass::GetClassID(CLSID*), 0x0061F7C0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TagTypeClass::Load(IStream*), 0x0061F820);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TagTypeClass::Save(IStream*, BOOL), 0x0061F870);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(TagTypeClass::TagTypeClass(const char *), AbstractTypeClass, 0x0061F030);
TagTypeClass::TagTypeClass(const NoInitClass& noinit) : AbstractTypeClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D791C; *((unsigned long*)this + 1) = (unsigned long)0x006D7900; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(TagTypeClass::~TagTypeClass(), 0x0061F150);
DEFINE_IMPLEMENTATION(void TagTypeClass::Detach(AbstractClass*, bool), 0x0061F2D0);
DEFINE_IMPLEMENTATION(RTTIType TagTypeClass::Fetch_RTTI() const, 0x0061F890);
DEFINE_IMPLEMENTATION(int TagTypeClass::Get_Object_Size(bool) const, 0x0061F8A0);
DEFINE_IMPLEMENTATION(void TagTypeClass::Object_CRC(CRCEngine&) const, 0x0061F800);
DEFINE_IMPLEMENTATION(int TagTypeClass::Fetch_Heap_ID() const, 0x0061F8B0);
DEFINE_IMPLEMENTATION(bool TagTypeClass::Read_INI(CCINIClass&), 0x0061F4F0);
DEFINE_IMPLEMENTATION(bool TagTypeClass::Write_INI(CCINIClass&) const, 0x0061F5C0);
// 0061F270
// 0061F290
DEFINE_IMPLEMENTATION(AttachType TagTypeClass::Attaches_To() const, 0x0061F640);
// 0061F660
// 0061F690
// 0061F6C0
// 0061F6F0
DEFINE_IMPLEMENTATION(void TagTypeClass::Read_Scenario_INI(CCINIClass&), 0x0061F350);
DEFINE_IMPLEMENTATION(void TagTypeClass::Write_Scenario_INI(CCINIClass&), 0x0061F450);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE BuildingLightClass::GetClassID(CLSID*), 0x00422A80);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE BuildingLightClass::Load(IStream*), 0x00422AC0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE BuildingLightClass::Save(IStream*, BOOL), 0x00422B20);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(BuildingLightClass::BuildingLightClass(TechnoClass *), ObjectClass, 0x00421AE0);
BuildingLightClass::BuildingLightClass(const NoInitClass& noinit) : ObjectClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006CBFE0; *((unsigned long*)this + 1) = (unsigned long)0x006CBFC4; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(BuildingLightClass::~BuildingLightClass(), 0x00421D70);
DEFINE_IMPLEMENTATION(void BuildingLightClass::Detach(AbstractClass*, bool), 0x00422B60);
DEFINE_IMPLEMENTATION(RTTIType BuildingLightClass::Fetch_RTTI() const, 0x00423240);
DEFINE_IMPLEMENTATION(int BuildingLightClass::Get_Object_Size(bool) const, 0x00422A70);
DEFINE_IMPLEMENTATION(void BuildingLightClass::Object_CRC(CRCEngine&) const, 0x00423080);
DEFINE_IMPLEMENTATION(void BuildingLightClass::AI(), 0x004223D0);
DEFINE_IMPLEMENTATION(LayerType BuildingLightClass::In_Which_Layer() const, 0x00422B50);
DEFINE_IMPLEMENTATION(const ObjectTypeClass* BuildingLightClass::Class_Of() const, 0x00422B40);
DEFINE_IMPLEMENTATION(bool BuildingLightClass::Limbo(), 0x00423150);
DEFINE_IMPLEMENTATION(bool BuildingLightClass::Unlimbo(const Coord&, Dir256), 0x00423170);
DEFINE_IMPLEMENTATION(void BuildingLightClass::Draw_It(Point2D&, Rect&) const, 0x00421DF0);
// 00422BA0
DEFINE_IMPLEMENTATION(void BuildingLightClass::Set_Behavior(SpotlightBehaviorType), 0x00422D40);
// 00422EE0
// 00422FC0

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE LightSourceClass::GetClassID(CLSID*), 0x00501CD0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE LightSourceClass::Load(IStream*), 0x00501D10);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE LightSourceClass::Save(IStream*, BOOL), 0x00501D50);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(LightSourceClass::LightSourceClass(), AbstractClass, 0x00501510);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(LightSourceClass::LightSourceClass(Coord, int, int, int, int, int), AbstractClass, 0x00501460);
LightSourceClass::LightSourceClass(const NoInitClass& noinit) : AbstractClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D38D8; *((unsigned long*)this + 1) = (unsigned long)0x006D38BC; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(LightSourceClass::~LightSourceClass(), 0x005015B0);
DEFINE_IMPLEMENTATION(RTTIType LightSourceClass::Fetch_RTTI() const, 0x00501D80);
DEFINE_IMPLEMENTATION(int LightSourceClass::Get_Object_Size(bool) const, 0x00501D70);
DEFINE_IMPLEMENTATION(void LightSourceClass::Object_CRC(CRCEngine&) const, 0x00501C70);
DEFINE_IMPLEMENTATION(void LightSourceClass::Enable(bool), 0x005016C0);
DEFINE_IMPLEMENTATION(void LightSourceClass::Disable(bool), 0x005016E0);
DEFINE_IMPLEMENTATION(void LightSourceClass::Process(), 0x00501700);
DEFINE_IMPLEMENTATION(void LightSourceClass::Init_Clear(), 0x00501650);
// 00501950

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE SmudgeTypeClass::GetClassID(CLSID*), 0x005FB7A0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE SmudgeTypeClass::Load(IStream*), 0x005FB730);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE SmudgeTypeClass::Save(IStream*, BOOL), 0x005FB780);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(SmudgeTypeClass::SmudgeTypeClass(const char *), ObjectTypeClass, 0x005FB1E0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(SmudgeTypeClass::SmudgeTypeClass(const NoInitClass &), ObjectTypeClass, 0x005FB2E0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(SmudgeTypeClass::~SmudgeTypeClass(), 0x005FB300);
DEFINE_IMPLEMENTATION(RTTIType SmudgeTypeClass::Fetch_RTTI() const, 0x005FBFE0);
DEFINE_IMPLEMENTATION(int SmudgeTypeClass::Get_Object_Size(bool) const, 0x005FBFF0);
DEFINE_IMPLEMENTATION(void SmudgeTypeClass::Object_CRC(CRCEngine&) const, 0x005FB6D0);
DEFINE_IMPLEMENTATION(int SmudgeTypeClass::Fetch_Heap_ID() const, 0x005FC000);
DEFINE_IMPLEMENTATION(bool SmudgeTypeClass::Read_INI(CCINIClass&), 0x005FB5C0);
DEFINE_IMPLEMENTATION(bool SmudgeTypeClass::Create_And_Place(Cell&, HouseClass*) const, 0x005FB440);
DEFINE_IMPLEMENTATION(ObjectClass* const SmudgeTypeClass::Create_One_Of(HouseClass*) const, 0x005FB4B0);
DEFINE_IMPLEMENTATION(void SmudgeTypeClass::Draw_It(Point2D&, Rect&, int, int, Cell&) const, 0x005FB4E0);
DEFINE_IMPLEMENTATION(bool SmudgeTypeClass::Can_Place_Here(Cell&, bool), 0x005FBE30);
DEFINE_IMPLEMENTATION(void SmudgeTypeClass::Place(Cell&), 0x005FBF30);
DEFINE_IMPLEMENTATION(bool SmudgeTypeClass::Create_Scorch(const Coord&, int, int, bool), 0x005FB870);
DEFINE_IMPLEMENTATION(bool SmudgeTypeClass::Create_Crater(const Coord&, int, int, bool), 0x005FBB50);
DEFINE_IMPLEMENTATION(void SmudgeTypeClass::Init(TheaterType), 0x005FB3C0);

DEFINE_IMPLEMENTATION(Coord Coord_Move(const Coord&, DirType&, unsigned), 0x004231B0);
DEFINE_IMPLEMENTATION(Coord Coord_Scatter(const Coord&, unsigned, bool), 0x0046E850);
DEFINE_IMPLEMENTATION(Coord Adjacent_Coord_With_Height(const Coord&, FacingType), 0x0046E980);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE FactoryClass::GetClassID(CLSID*), 0x00497570);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE FactoryClass::Load(IStream*), 0x004975B0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE FactoryClass::Save(IStream*, BOOL), 0x004976F0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(FactoryClass::FactoryClass(), AbstractClass, 0x00496C60);
FactoryClass::FactoryClass(const NoInitClass& x) : AbstractClass(x) { *((unsigned long*)this) = (unsigned long)0x006D0080; *((unsigned long*)this + 1) = (unsigned long)0x006D0064; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(FactoryClass::~FactoryClass(), 0x00496DA0);
DEFINE_IMPLEMENTATION(void FactoryClass::Detach(AbstractClass*, bool), 0x004978B0);
DEFINE_IMPLEMENTATION(RTTIType FactoryClass::Fetch_RTTI() const, 0x00497A70);
DEFINE_IMPLEMENTATION(int FactoryClass::Get_Object_Size(bool) const, 0x00497A80);
DEFINE_IMPLEMENTATION(void FactoryClass::Object_CRC(CRCEngine&) const, 0x00497760);
DEFINE_IMPLEMENTATION(void FactoryClass::AI(), 0x00496EA0);
DEFINE_IMPLEMENTATION(bool FactoryClass::Abandon(), 0x00497330);
DEFINE_IMPLEMENTATION(bool FactoryClass::Completed(), 0x004974E0);
DEFINE_IMPLEMENTATION(bool FactoryClass::Has_Changed(), 0x00496FB0);
DEFINE_IMPLEMENTATION(bool FactoryClass::Has_Completed(), 0x00497470);
DEFINE_IMPLEMENTATION(bool FactoryClass::Set(const TechnoTypeClass&, HouseClass&, bool), 0x00496FC0);
DEFINE_IMPLEMENTATION(bool FactoryClass::Set(TechnoClass&), 0x00497150);
DEFINE_IMPLEMENTATION(bool FactoryClass::Start(bool), 0x004971E0);
DEFINE_IMPLEMENTATION(bool FactoryClass::Suspend(bool), 0x004971A0);
DEFINE_IMPLEMENTATION(int FactoryClass::Completion(), 0x00497460);
DEFINE_IMPLEMENTATION(TechnoClass* FactoryClass::Get_Object() const, 0x004974A0);
DEFINE_IMPLEMENTATION(int FactoryClass::Get_Special_Item() const, 0x004974B0);
DEFINE_IMPLEMENTATION(void FactoryClass::Resume_Queue(), 0x004978D0);
DEFINE_IMPLEMENTATION(bool FactoryClass::Remove_From_Queue(const TechnoTypeClass&), 0x00497940);
DEFINE_IMPLEMENTATION(bool FactoryClass::Is_Queued(const TechnoTypeClass&), 0x004979D0);
DEFINE_IMPLEMENTATION(int FactoryClass::Total_Queued(const TechnoTypeClass&), 0x00497990);
DEFINE_IMPLEMENTATION(int FactoryClass::Cost_Per_Tick() const, 0x004974C0);
DEFINE_IMPLEMENTATION(int FactoryClass::Build_Rate() const, 0x004972F0);
DEFINE_IMPLEMENTATION(void FactoryClass::Recalculate_Times(HouseClass*), 0x00497A00);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE SmudgeClass::GetClassID(CLSID*), 0x005FAEA0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE SmudgeClass::Load(IStream*), 0x005FAE00);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE SmudgeClass::Save(IStream*, BOOL), 0x005FAE50);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(SmudgeClass::SmudgeClass(SmudgeTypeClass *, Coord &, HousesType), ObjectClass, 0x005FA9E0);
SmudgeClass::SmudgeClass(const NoInitClass& noinit) : ObjectClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D69F4; *((unsigned long*)this + 1) = (unsigned long)0x006D69D8; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(SmudgeClass::~SmudgeClass(), 0x005FAAC0);
DEFINE_IMPLEMENTATION(RTTIType SmudgeClass::Fetch_RTTI() const, 0x005FAE90);
DEFINE_IMPLEMENTATION(int SmudgeClass::Get_Object_Size(bool) const, 0x005FAE80);
DEFINE_IMPLEMENTATION(const ObjectTypeClass* SmudgeClass::Class_Of() const, 0x005FAE70);
DEFINE_IMPLEMENTATION(void SmudgeClass::Draw_It(Point2D&, Rect&) const, 0x005FAEE0);
DEFINE_IMPLEMENTATION(bool SmudgeClass::Mark(MarkType), 0x005FAB50);
DEFINE_IMPLEMENTATION(void SmudgeClass::Disown(Cell&), 0x005FABE0);
DEFINE_IMPLEMENTATION(void SmudgeClass::Read_INI(CCINIClass&), 0x005FABF0);
DEFINE_IMPLEMENTATION(void SmudgeClass::Write_INI(CCINIClass&), 0x005FAD30);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE OverlayClass::GetClassID(CLSID*), 0x0058CAA0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE OverlayClass::Load(IStream*), 0x0058C4D0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE OverlayClass::Save(IStream*, BOOL), 0x0058C520);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(OverlayClass::OverlayClass(OverlayTypeClass *, Cell &, HousesType), ObjectClass, 0x0058B460);
OverlayClass::OverlayClass(const NoInitClass& noinit) : ObjectClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D4F9C; *((unsigned long*)this + 1) = (unsigned long)0x006D4F80; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(OverlayClass::~OverlayClass(), 0x0058B550);
DEFINE_IMPLEMENTATION(RTTIType OverlayClass::Fetch_RTTI() const, 0x0058CAE0);
DEFINE_IMPLEMENTATION(int OverlayClass::Get_Object_Size(bool) const, 0x0058CA90);
DEFINE_IMPLEMENTATION(const ObjectTypeClass* OverlayClass::Class_Of() const, 0x0058C970);
DEFINE_IMPLEMENTATION(void OverlayClass::Draw_It(Point2D&, Rect&) const, 0x0058CAF0);
DEFINE_IMPLEMENTATION(void OverlayClass::Placement_Draw_It(Point2D&, Rect&) const, 0x0058C540);
DEFINE_IMPLEMENTATION(bool OverlayClass::Mark(MarkType), 0x0058B5E0);
// 0058C850
DEFINE_IMPLEMENTATION(TiberiumType OverlayClass::To_TiberiumType(OverlayType), 0x0058C8B0);
DEFINE_IMPLEMENTATION(void OverlayClass::Place_All_Veins(), 0x0058C980);
DEFINE_IMPLEMENTATION(void OverlayClass::Read_INI(CCINIClass&), 0x0058BE30);
DEFINE_IMPLEMENTATION(void OverlayClass::Write_INI(CCINIClass&), 0x0058C280);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE TiberiumClass::GetClassID(CLSID*), 0x00644FD0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TiberiumClass::Load(IStream*), 0x00645010);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TiberiumClass::Save(IStream*, BOOL), 0x00645250);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TiberiumClass::GetSizeMax(ULARGE_INTEGER*), 0x00645220);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(TiberiumClass::TiberiumClass(const char *), AbstractTypeClass, 0x00644890);
TiberiumClass::TiberiumClass(const NoInitClass& noinit) : AbstractTypeClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D86F0; *((unsigned long*)this + 1) = (unsigned long)0x006D86D4; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(TiberiumClass::~TiberiumClass(), 0x00644A30);
DEFINE_IMPLEMENTATION(void TiberiumClass::Detach(AbstractClass*, bool), 0x006452C0);
DEFINE_IMPLEMENTATION(RTTIType TiberiumClass::Fetch_RTTI() const, 0x00646860);
DEFINE_IMPLEMENTATION(int TiberiumClass::Get_Object_Size(bool) const, 0x00646850);
DEFINE_IMPLEMENTATION(void TiberiumClass::Object_CRC(CRCEngine&) const, 0x00644F60);
DEFINE_IMPLEMENTATION(int TiberiumClass::Fetch_Heap_ID() const, 0x00646870);
DEFINE_IMPLEMENTATION(bool TiberiumClass::Read_INI(CCINIClass&), 0x00644BF0);
DEFINE_IMPLEMENTATION(void TiberiumClass::Process(CCINIClass&), 0x00644EB0);
DEFINE_IMPLEMENTATION(void TiberiumClass::Spread_AI(), 0x00645330);
DEFINE_IMPLEMENTATION(void TiberiumClass::Spread_Init_Clear(), 0x00645510);
DEFINE_IMPLEMENTATION(void TiberiumClass::Spread(), 0x006455C0);
// 006458F0
// 00645A30
// 00645BA0
// 00645C30
DEFINE_IMPLEMENTATION(void TiberiumClass::Add_Spread_Cell(Cell&), 0x00645C70);
DEFINE_IMPLEMENTATION(void TiberiumClass::Growth_AI(), 0x00645DC0);
DEFINE_IMPLEMENTATION(void TiberiumClass::Growth_Init_Clear(), 0x00645E80);
DEFINE_IMPLEMENTATION(void TiberiumClass::Grow(), 0x00645FD0);
// 00646080
// 006463D0
// 00646510
// 00646680
DEFINE_IMPLEMENTATION(void TiberiumClass::Add_Growth_Cell(Cell&), 0x00646710);
DEFINE_IMPLEMENTATION(void TiberiumClass::Init_Cells(), 0x006453C0);
DEFINE_IMPLEMENTATION(void TiberiumClass::Init(), 0x00646840);

DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE BulletClass::AddRef(), 0x004471B0);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE BulletClass::Release(), 0x004471D0);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE BulletClass::GetClassID(CLSID*), 0x00447460);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE BulletClass::Load(IStream*), 0x004470F0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE BulletClass::Save(IStream*, BOOL), 0x00447190);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(BulletClass::BulletClass(), ObjectClass, 0x004444A0);
// BulletClass::BulletClass(BulletType id, AbstractClass * target, TechnoClass *payback, int strength, WarheadType warhead, int speed), 0x);
BulletClass::BulletClass(const NoInitClass& noinit) : ObjectClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006CC88C; *((unsigned long*)this + 1) = (unsigned long)0x006CC870; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(BulletClass::~BulletClass(), 0x004445E0);
DEFINE_IMPLEMENTATION(void BulletClass::Detach(AbstractClass*, bool), 0x00445F00);
DEFINE_IMPLEMENTATION(RTTIType BulletClass::Fetch_RTTI() const, 0x00447450);
DEFINE_IMPLEMENTATION(int BulletClass::Get_Object_Size(bool) const, 0x00447440);
DEFINE_IMPLEMENTATION(void BulletClass::AI(), 0x004446F0);
DEFINE_IMPLEMENTATION(LayerType BulletClass::In_Which_Layer() const, 0x004462B0);
DEFINE_IMPLEMENTATION(const ObjectTypeClass* BulletClass::Class_Of() const, 0x004474B0);
DEFINE_IMPLEMENTATION(Cell* BulletClass::Occupy_List(bool) const, 0x00444670);
DEFINE_IMPLEMENTATION(void BulletClass::Draw_It(Point2D&, Rect&) const, 0x00445C00);
DEFINE_IMPLEMENTATION(bool BulletClass::Mark(MarkType), 0x004446D0);
DEFINE_IMPLEMENTATION(int BulletClass::Shape_Number() const, 0x00445B70);
DEFINE_IMPLEMENTATION(void BulletClass::Assign_Target(AbstractClass*), 0x004474A0);
DEFINE_IMPLEMENTATION(bool BulletClass::Unlimbo(const Coord&, TVelocity3D&), 0x00445F40);
// 00444580
DEFINE_IMPLEMENTATION(bool BulletClass::Is_Forced_To_Explode(Coord& coord) const, 0x004462C0);
DEFINE_IMPLEMENTATION(void BulletClass::Bullet_Explodes(bool forced), 0x004463D0);
// 00446640
DEFINE_IMPLEMENTATION(bool BulletClass::Homes_In() const, 0x00447210);
// 004472C0
DEFINE_IMPLEMENTATION(BulletClass* BulletClass::Create_Bullet(BulletTypeClass*, AbstractClass*, TechnoClass*, int, WarheadTypeClass*, int, int, bool), 0x00447220);

DEFINE_IMPLEMENTATION(DirType TVelocity3D::Direction(), 0x0040F5E0);
DEFINE_IMPLEMENTATION(double TVelocity3D::Length_2D(), 0x0040F650);
DEFINE_IMPLEMENTATION(double TVelocity3D::Length_3D(), 0x0040F6C0);
DEFINE_IMPLEMENTATION(double TVelocity3D::Length_2D_0(), 0x0040F730);
DEFINE_IMPLEMENTATION(void TVelocity3D::Update_Position(DirType&), 0x00558A90);
DEFINE_IMPLEMENTATION(void TVelocity3D::If_XYZ_0_Set_X_100(), 0x0040F6F0);
DEFINE_IMPLEMENTATION(void TVelocity3D::If_XY_0_Set_X_100(), 0x0040F760);

DEFINE_IMPLEMENTATION(int Projectile_Motion(Coord&, TVelocity3D&, Coord&, DirType&, bool, bool, bool), 0x00558230);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE UnitClass::GetClassID(CLSID*), 0x0065B5D0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE UnitClass::Load(IStream*), 0x00659580);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE UnitClass::Save(IStream*, BOOL), 0x00659740);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(UnitClass::UnitClass(UnitTypeClass *, HouseClass *), FootClass, 0x0064D4B0);
UnitClass::UnitClass(const NoInitClass& noinit) : FootClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D8B6C; *((unsigned long*)this + 1) = (unsigned long)0x006D8B50; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(UnitClass::~UnitClass(), 0x0064D7C0);
DEFINE_IMPLEMENTATION(void UnitClass::Detach(AbstractClass*, bool), 0x00659830);
DEFINE_IMPLEMENTATION(RTTIType UnitClass::Fetch_RTTI() const, 0x0065B610);
DEFINE_IMPLEMENTATION(int UnitClass::Get_Object_Size(bool) const, 0x0065B5B0);
DEFINE_IMPLEMENTATION(void UnitClass::Object_CRC(CRCEngine&) const, 0x00659760);
DEFINE_IMPLEMENTATION(void UnitClass::AI(), 0x0064E020);
DEFINE_IMPLEMENTATION(ActionType UnitClass::What_Action(const ObjectClass*, bool), 0x006564A0);
DEFINE_IMPLEMENTATION(ActionType UnitClass::What_Action(const Cell&, bool, bool) const, 0x00655F90);
DEFINE_IMPLEMENTATION(bool UnitClass::entry_80() const, 0x0065B2D0);
DEFINE_IMPLEMENTATION(const ObjectTypeClass* UnitClass::Class_Of() const, 0x00657190);
DEFINE_IMPLEMENTATION(const char* UnitClass::Full_Name() const, 0x0065B620);
DEFINE_IMPLEMENTATION(bool UnitClass::Limbo(), 0x00659270);
DEFINE_IMPLEMENTATION(bool UnitClass::Unlimbo(const Coord&, Dir256), 0x0064F940);
DEFINE_IMPLEMENTATION(void UnitClass::Record_The_Kill(const ObjectClass*), 0x00659870);
DEFINE_IMPLEMENTATION(void UnitClass::Set_Occupy_Bit(Coord&), 0x00659300);
DEFINE_IMPLEMENTATION(void UnitClass::Clear_Occupy_Bit(Coord&), 0x00659360);
DEFINE_IMPLEMENTATION(bool UnitClass::Render(Rect&, bool, bool), 0x00651EC0);
DEFINE_IMPLEMENTATION(void UnitClass::Draw_It(Point2D&, Rect&) const, 0x00653A70);
DEFINE_IMPLEMENTATION(bool UnitClass::Active_Click_With(ActionType, ObjectClass*, bool), 0x00650330);
DEFINE_IMPLEMENTATION(bool UnitClass::Active_Click_With(ActionType, Cell&, bool), 0x006503A0);
DEFINE_IMPLEMENTATION(ResultType UnitClass::Take_Damage(int&, int, const WarheadTypeClass*, const ObjectClass*, bool, bool), 0x0064FA70);
DEFINE_IMPLEMENTATION(void UnitClass::Scatter(const Coord&, bool, bool), 0x00658D80);
DEFINE_IMPLEMENTATION(void UnitClass::Per_Cell_Process(PCPType), 0x006511B0);
DEFINE_IMPLEMENTATION(RadioMessageType UnitClass::Receive_Message(RadioClass*, RadioMessageType, long&), 0x0064F440);
DEFINE_IMPLEMENTATION(MoveType UnitClass::Can_Enter_Cell(const CellClass*, FacingType, int, const CellClass*, bool), 0x00655330);
DEFINE_IMPLEMENTATION(bool UnitClass::Ready_To_Commence() const, 0x006593C0);
DEFINE_IMPLEMENTATION(int UnitClass::Mission_Attack(), 0x006598F0);
DEFINE_IMPLEMENTATION(int UnitClass::Mission_Guard(), 0x006566E0);
DEFINE_IMPLEMENTATION(int UnitClass::Mission_Guard_Area(), 0x006592C0);
DEFINE_IMPLEMENTATION(int UnitClass::Mission_Harvest(), 0x00654A80);
DEFINE_IMPLEMENTATION(int UnitClass::Mission_Hunt(), 0x00655270);
DEFINE_IMPLEMENTATION(int UnitClass::Mission_Move(), 0x00656840);
DEFINE_IMPLEMENTATION(int UnitClass::Mission_Unload(), 0x006540C0);
DEFINE_IMPLEMENTATION(int UnitClass::Mission_Repair(), 0x00656D20);
DEFINE_IMPLEMENTATION(int UnitClass::Mission_Patrol(), 0x00656890);
DEFINE_IMPLEMENTATION(bool UnitClass::entry_238() const, 0x006592D0);
DEFINE_IMPLEMENTATION(DirType UnitClass::Turret_Facing() const, 0x0065B630);
DEFINE_IMPLEMENTATION(double UnitClass::Tiberium_Load() const, 0x006571A0);
DEFINE_IMPLEMENTATION(double UnitClass::Weed_Load() const, 0x00659900);
DEFINE_IMPLEMENTATION(int UnitClass::Pip_Count() const, 0x00656BD0);
DEFINE_IMPLEMENTATION(FacingType UnitClass::Desired_Load_Dir(const ObjectClass*, Cell&) const, 0x006568E0);
DEFINE_IMPLEMENTATION(DirType UnitClass::Fire_Direction() const, 0x00656DC0);
DEFINE_IMPLEMENTATION(InfantryTypeClass* const UnitClass::Crew_Type() const, 0x00656D10);
DEFINE_IMPLEMENTATION(bool UnitClass::Is_Immobilized() const, 0x0065B590);
DEFINE_IMPLEMENTATION(int UnitClass::Get_Max_Speed() const, 0x00659940);
DEFINE_IMPLEMENTATION(FireErrorType UnitClass::Can_Fire(AbstractClass*, WeaponSlotType) const, 0x00656E10);
DEFINE_IMPLEMENTATION(AbstractClass* UnitClass::Greatest_Threat(ThreatType, Coord&, bool) const, 0x00658520);
DEFINE_IMPLEMENTATION(const BulletClass* UnitClass::Fire_At(AbstractClass*, WeaponSlotType), 0x00657070);
DEFINE_IMPLEMENTATION(bool UnitClass::Captured(HouseClass*), 0x0065B280);
DEFINE_IMPLEMENTATION(void UnitClass::Assign_Destination(const AbstractClass*, bool), 0x00657520);
DEFINE_IMPLEMENTATION(bool UnitClass::Enter_Idle_Mode(bool, bool), 0x006503C0);
DEFINE_IMPLEMENTATION(bool UnitClass::Deploy_To_Fire(), 0x0064E880);
DEFINE_IMPLEMENTATION(void UnitClass::Overrun_Square(Cell&, bool), 0x006572B0);
DEFINE_IMPLEMENTATION(void UnitClass::Approach_Target(), 0x006571E0);
DEFINE_IMPLEMENTATION(void UnitClass::Unit_Draw_Voxel(Point2D, Rect, int), 0x00652330);
DEFINE_IMPLEMENTATION(void UnitClass::Unit_Draw_Shape(Point2D, Rect, int), 0x00653090);
DEFINE_IMPLEMENTATION(void UnitClass::Unit_Blit_Voxel(Surface&, Point2D, Rect, int, int), 0x00651F50);
DEFINE_IMPLEMENTATION(void UnitClass::Tunnel_AI(), 0x0064D9D0);
DEFINE_IMPLEMENTATION(void UnitClass::Rotation_AI(), 0x0064E560);
DEFINE_IMPLEMENTATION(bool UnitClass::Edge_Of_World_AI(), 0x0064E6F0);
DEFINE_IMPLEMENTATION(void UnitClass::Reload_AI(), 0x0064E760);
DEFINE_IMPLEMENTATION(void UnitClass::Firing_AI(), 0x0064E920);
DEFINE_IMPLEMENTATION(void UnitClass::Visceroid_AI(), 0x0064ECF0);
DEFINE_IMPLEMENTATION(void UnitClass::Jellyfish_AI(), 0x0064F020);
DEFINE_IMPLEMENTATION(bool UnitClass::Goto_Clear_Spot(), 0x00650680);
DEFINE_IMPLEMENTATION(bool UnitClass::Try_To_Deploy(), 0x00650B70);
DEFINE_IMPLEMENTATION(bool UnitClass::Harvesting(), 0x00653EE0);
DEFINE_IMPLEMENTATION(bool UnitClass::Flag_Attach(HousesType), 0x00656B70);
DEFINE_IMPLEMENTATION(bool UnitClass::Flag_Remove(), 0x00656BA0);
DEFINE_IMPLEMENTATION(void UnitClass::APC_Close_Door(), 0x00656C90);
DEFINE_IMPLEMENTATION(void UnitClass::APC_Open_Door(), 0x00656CB0);
DEFINE_IMPLEMENTATION(int UnitClass::Credit_Load() const, 0x00658C10);
DEFINE_IMPLEMENTATION(bool UnitClass::Should_Crush_It(const TechnoClass*) const, 0x00658C20);
// 00659970
// 0065B180
// 0065B2F0
// 0065B400
DEFINE_IMPLEMENTATION(void UnitClass::Read_INI(CCINIClass&), 0x006585C0);
DEFINE_IMPLEMENTATION(void UnitClass::Write_INI(CCINIClass&), 0x00658A40);

DEFINE_IMPLEMENTATION(float __cdecl FastMath::Sqrt(double), 0x00497F50);
DEFINE_IMPLEMENTATION(float __cdecl FastMath::Sin(double), 0x00497FC0);
DEFINE_IMPLEMENTATION(float __cdecl FastMath::Cos(double), 0x00498010);
DEFINE_IMPLEMENTATION(float __cdecl FastMath::Tan(double), 0x00498060);
DEFINE_IMPLEMENTATION(float __cdecl FastMath::Asin(double), 0x00498090);
DEFINE_IMPLEMENTATION(float __cdecl FastMath::Acos(double), 0x004980C0);
DEFINE_IMPLEMENTATION(float __cdecl FastMath::Atan(double), 0x004980F0);
DEFINE_IMPLEMENTATION(float __cdecl FastMath::Atan2(double, double), 0x00498140);
DEFINE_IMPLEMENTATION(float __stdcall FastMath::Sqrtf(float), 0x00498370);
DEFINE_IMPLEMENTATION(float __stdcall FastMath::Sinf(float), 0x00498460);
DEFINE_IMPLEMENTATION(float __stdcall FastMath::Cosf(float), 0x004984B0);
DEFINE_IMPLEMENTATION(float __stdcall FastMath::Tanf(float), 0x00498630);
DEFINE_IMPLEMENTATION(float __stdcall FastMath::Asinf(float), 0x00498570);
DEFINE_IMPLEMENTATION(float __stdcall FastMath::Acosf(float), 0x004985A0);
DEFINE_IMPLEMENTATION(float __stdcall FastMath::Atanf(float), 0x00498790);
DEFINE_IMPLEMENTATION(float __stdcall FastMath::Atan2f(float, float), 0x004986E0);
// DEFINE_IMPLEMENTATION(int __cdecl FastMath::ftol(double), 0x006B2330);
//__int64 __cdecl FastMath::ftol64(double val) { return static_cast<int>(FastMath::ftol(val)); }

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE TerrainClass::GetClassID(CLSID*), 0x00640BE0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TerrainClass::Load(IStream*), 0x00640650);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TerrainClass::Save(IStream*, BOOL), 0x006407D0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(TerrainClass::TerrainClass(), ObjectClass, 0x0063F710);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(TerrainClass::TerrainClass(TerrainTypeClass *classof, Cell &pos), ObjectClass, 0x0063F500);
TerrainClass::TerrainClass(const NoInitClass& noinit) : ObjectClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D828C; *((unsigned long*)this + 1) = (unsigned long)0x006D8270; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(TerrainClass::~TerrainClass(), 0x0063F170);
DEFINE_IMPLEMENTATION(void TerrainClass::Detach(AbstractClass*, bool), 0x00640880);
DEFINE_IMPLEMENTATION(RTTIType TerrainClass::Fetch_RTTI() const, 0x00640BD0);
DEFINE_IMPLEMENTATION(int TerrainClass::Get_Object_Size(bool) const, 0x00640BC0);
DEFINE_IMPLEMENTATION(void TerrainClass::Object_CRC(CRCEngine&) const, 0x00640810);
DEFINE_IMPLEMENTATION(void TerrainClass::AI(), 0x0063FFB0);
DEFINE_IMPLEMENTATION(const ObjectTypeClass* TerrainClass::Class_Of() const, 0x006409E0);
DEFINE_IMPLEMENTATION(bool TerrainClass::Limbo(), 0x00640210);
DEFINE_IMPLEMENTATION(bool TerrainClass::Unlimbo(const Coord&, Dir256), 0x006408B0);
DEFINE_IMPLEMENTATION(void TerrainClass::Set_Occupy_Bit(Coord&), 0x0063F9A0);
DEFINE_IMPLEMENTATION(void TerrainClass::Clear_Occupy_Bit(Coord&), 0x0063F910);
DEFINE_IMPLEMENTATION(bool TerrainClass::Render(Rect&, bool, bool), 0x00640510);
DEFINE_IMPLEMENTATION(void TerrainClass::Draw_It(Point2D&, Rect&) const, 0x0063FA30);
DEFINE_IMPLEMENTATION(void TerrainClass::Placement_Draw_It(Point2D&, Rect&) const, 0x0063FC00);
DEFINE_IMPLEMENTATION(bool TerrainClass::Mark(MarkType), 0x0063F8A0);
DEFINE_IMPLEMENTATION(Rect TerrainClass::entry_118() const, 0x006409F0);
DEFINE_IMPLEMENTATION(ResultType TerrainClass::Take_Damage(int&, int, const WarheadTypeClass*, const ObjectClass*, bool, bool), 0x0063F2D0);
DEFINE_IMPLEMENTATION(bool TerrainClass::Catch_Fire(), 0x0063FE60);
DEFINE_IMPLEMENTATION(void TerrainClass::Fire_Out(), 0x0063FF40);
DEFINE_IMPLEMENTATION(MoveType TerrainClass::Can_Enter_Cell(const CellClass*, FacingType, int, const CellClass*, bool), 0x0063FD80);
DEFINE_IMPLEMENTATION(void TerrainClass::Start_To_Crumble(), 0x006401D0);
DEFINE_IMPLEMENTATION(bool TerrainClass::Is_Animating() const, 0x006407F0);
DEFINE_IMPLEMENTATION(void TerrainClass::Read_INI(CCINIClass&), 0x00640340);
DEFINE_IMPLEMENTATION(void TerrainClass::Write_INI(CCINIClass&), 0x00640460);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE TriggerTypeClass::GetClassID(CLSID*), 0x0064AA70);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TriggerTypeClass::Load(IStream*), 0x0064AAB0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TriggerTypeClass::Save(IStream*, BOOL), 0x0064AB20);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(TriggerTypeClass::TriggerTypeClass(const char *), AbstractTypeClass, 0x00649CA0);
TriggerTypeClass::TriggerTypeClass(const NoInitClass& noinit) : AbstractTypeClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D888C; *((unsigned long*)this + 1) = (unsigned long)0x006D8870; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(TriggerTypeClass::~TriggerTypeClass(), 0x00649DF0);
DEFINE_IMPLEMENTATION(void TriggerTypeClass::Detach(AbstractClass*, bool), 0x0064A030);
DEFINE_IMPLEMENTATION(RTTIType TriggerTypeClass::Fetch_RTTI() const, 0x0064AB40);
DEFINE_IMPLEMENTATION(int TriggerTypeClass::Get_Object_Size(bool) const, 0x0064AB50);
DEFINE_IMPLEMENTATION(void TriggerTypeClass::Object_CRC(CRCEngine&) const, 0x0064A9F0);
DEFINE_IMPLEMENTATION(int TriggerTypeClass::Fetch_Heap_ID() const, 0x0064AB60);
DEFINE_IMPLEMENTATION(bool TriggerTypeClass::Read_INI(CCINIClass&), 0x0064A1B0);
DEFINE_IMPLEMENTATION(bool TriggerTypeClass::Write_INI(CCINIClass&) const, 0x0064A590);
// 00649F30
// 00649F50
// 00649F70
// 00649F90
// 00649FB0
// 00649FF0
DEFINE_IMPLEMENTATION(AttachType TriggerTypeClass::Attaches_To() const, 0x0064A160);
DEFINE_IMPLEMENTATION(bool TriggerTypeClass::Remove_Action(TActionClass*), 0x0064A8B0);
DEFINE_IMPLEMENTATION(bool TriggerTypeClass::Remove_Event(TEventClass*), 0x0064A910);
DEFINE_IMPLEMENTATION(void TriggerTypeClass::Read_Scenario_INI(CCINIClass&), 0x0064A4C0);
DEFINE_IMPLEMENTATION(void TriggerTypeClass::Write_Scenario_INI(CCINIClass&), 0x0064A750);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE TriggerClass::GetClassID(CLSID*), 0x00649830);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TriggerClass::Load(IStream*), 0x00649870);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TriggerClass::Save(IStream*, BOOL), 0x006498D0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(TriggerClass::TriggerClass(), AbstractClass, 0x00649190);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(TriggerClass::TriggerClass(TriggerTypeClass *), AbstractClass, 0x00649040);
TriggerClass::TriggerClass(const NoInitClass& noinit) : AbstractClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D87F0; *((unsigned long*)this + 1) = (unsigned long)0x006D87D4; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(TriggerClass::~TriggerClass(), 0x00649190);
DEFINE_IMPLEMENTATION(void TriggerClass::Detach(AbstractClass*, bool), 0x006496A0);
DEFINE_IMPLEMENTATION(RTTIType TriggerClass::Fetch_RTTI() const, 0x00649920);
DEFINE_IMPLEMENTATION(int TriggerClass::Get_Object_Size(bool) const, 0x00649910);
DEFINE_IMPLEMENTATION(void TriggerClass::Object_CRC(CRCEngine&) const, 0x006497A0);
DEFINE_IMPLEMENTATION(bool TriggerClass::Fire(ObjectClass*, Cell), 0x006495E0);
DEFINE_IMPLEMENTATION(bool TriggerClass::Is_Triggered(TEventType, ObjectClass*, bool, bool, TechnoClass*), 0x00649500);
DEFINE_IMPLEMENTATION(void TriggerClass::Enable(), 0x006498F0);
DEFINE_IMPLEMENTATION(void TriggerClass::Disable(), 0x00649900);
DEFINE_IMPLEMENTATION(void TriggerClass::Draw_It(int, int, int, int, int, bool, TextPrintType) const, 0x00);
DEFINE_IMPLEMENTATION(void TriggerClass::Timer_Global_Reset(int), 0x006493E0);
DEFINE_IMPLEMENTATION(void TriggerClass::Timer_Local_Reset(int), 0x00649410);
DEFINE_IMPLEMENTATION(void TriggerClass::Reset_Timer_Events(), 0x00649440);
DEFINE_IMPLEMENTATION(bool TriggerClass::Is_Horizontal_Cross() const, 0x00649290);
DEFINE_IMPLEMENTATION(bool TriggerClass::Is_Vertical_Cross() const, 0x006492D0);
DEFINE_IMPLEMENTATION(bool TriggerClass::Is_Enters_Zone() const, 0x00649310);
DEFINE_IMPLEMENTATION(bool TriggerClass::Is_Allow_Win() const, 0x00649350);
DEFINE_IMPLEMENTATION(bool TriggerClass::Is_Tied_To_Global(int) const, 0x00649390);
DEFINE_IMPLEMENTATION(void TriggerClass::Mark_Event_Sprung(int), 0x006496D0);
DEFINE_IMPLEMENTATION(void TriggerClass::Mark_Event_Unsprung(int), 0x006496F0);
DEFINE_IMPLEMENTATION(bool TriggerClass::Is_Event_Sprung(int), 0x00649710);
DEFINE_IMPLEMENTATION(void TriggerClass::Mark_To_Die(), 0x00649730);
DEFINE_IMPLEMENTATION(bool TriggerClass::Is_Marked_To_Die() const, 0x00649790);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE TagClass::GetClassID(CLSID*), 0x0061EB50);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TagClass::Load(IStream*), 0x0061EBE0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TagClass::Save(IStream*, BOOL), 0x0061EC40);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(TagClass::TagClass(TagTypeClass *), AbstractClass, 0x0061E330);
TagClass::TagClass(const NoInitClass& noinit) : AbstractClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D7850; *((unsigned long*)this + 1) = (unsigned long)0x006D7834; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(TagClass::~TagClass(), 0x0061E4A0);
DEFINE_IMPLEMENTATION(void TagClass::Detach(AbstractClass*, bool), 0x0061EAC0);
DEFINE_IMPLEMENTATION(RTTIType TagClass::Fetch_RTTI() const, 0x0061ED30);
DEFINE_IMPLEMENTATION(int TagClass::Get_Object_Size(bool) const, 0x0061ED20);
DEFINE_IMPLEMENTATION(void TagClass::Object_CRC(CRCEngine&) const, 0x0061EB90);
DEFINE_IMPLEMENTATION(void TagClass::Mark_To_Die(), 0x0061E750);
DEFINE_IMPLEMENTATION(bool TagClass::Is_Marked_To_Die() const, 0x0061E7B0);
DEFINE_IMPLEMENTATION(bool TagClass::Is_Horizontal_Cross() const, 0x0061E830);
DEFINE_IMPLEMENTATION(bool TagClass::Is_Vertical_Cross() const, 0x0061E820);
DEFINE_IMPLEMENTATION(bool TagClass::Is_Enters_Zone() const, 0x0061E840);
DEFINE_IMPLEMENTATION(bool TagClass::Is_Allow_Win() const, 0x0061E850);
DEFINE_IMPLEMENTATION(bool TagClass::Is_Transferable() const, 0x0061EC60);
DEFINE_IMPLEMENTATION(void TagClass::Timer_Global_Reset(int), 0x0061EA50);
DEFINE_IMPLEMENTATION(void TagClass::Timer_Local_Reset(int), 0x0061EA60);
DEFINE_IMPLEMENTATION(bool TagClass::Is_Trigger_Attached(TriggerClass*) const, 0x0061E860);
DEFINE_IMPLEMENTATION(bool TagClass::Spring(TEventType, ObjectClass*, Cell, bool, TechnoClass*), 0x0061E880);
DEFINE_IMPLEMENTATION(Cell TagClass::Get_Position() const, 0x0061E810);
DEFINE_IMPLEMENTATION(void TagClass::Set_Position(Cell), 0x0061EA10);
DEFINE_IMPLEMENTATION(void TagClass::All_Timer_Global_Reset(int), 0x0061EC80);
DEFINE_IMPLEMENTATION(void TagClass::All_Timer_Local_Reset(int), 0x0061ECB0);
DEFINE_IMPLEMENTATION(void TagClass::Link(TriggerClass*), 0x0061EA70);
DEFINE_IMPLEMENTATION(bool TagClass::Unlink(TriggerClass*), 0x0061EA80);
DEFINE_IMPLEMENTATION(bool TagClass::Is_One_Of_A_Kind(), 0x0061ECE0);

DEFINE_IMPLEMENTATION(void ScenarioClass::Reset(), 0x005DAE90);
DEFINE_IMPLEMENTATION(void ScenarioClass::Set_Scenario_Name(char const*), 0x005DD0D0);
DEFINE_IMPLEMENTATION(bool ScenarioClass::Read_INI(CCINIClass&), 0x005DFDE0);
DEFINE_IMPLEMENTATION(bool ScenarioClass::Write_INI(CCINIClass&), 0x005E0950);
DEFINE_IMPLEMENTATION(bool ScenarioClass::Read_Global_INI(INIClass&), 0x005DF930);
DEFINE_IMPLEMENTATION(bool ScenarioClass::Read_Local_INI(INIClass&), 0x005DFBD0);
DEFINE_IMPLEMENTATION(bool ScenarioClass::Write_Local_INI(INIClass&), 0x005DFD10);
DEFINE_IMPLEMENTATION(bool ScenarioClass::Set_Global_To(int, bool), 0x005DF720);
DEFINE_IMPLEMENTATION(bool ScenarioClass::Set_Global_To(char const*, bool), 0x005DF770);
DEFINE_IMPLEMENTATION(bool ScenarioClass::Get_Global_Value(int, bool&), 0x005DF810);
DEFINE_IMPLEMENTATION(bool ScenarioClass::Get_Global_Value(char const*, bool&), 0x005DF840);
DEFINE_IMPLEMENTATION(bool ScenarioClass::Set_Local_To(int, bool), 0x005DF9C0);
DEFINE_IMPLEMENTATION(bool ScenarioClass::Set_Local_To(char const*, bool), 0x005DFA10);
DEFINE_IMPLEMENTATION(bool ScenarioClass::Get_Local_Value(int, bool&), 0x005DFAB0);
DEFINE_IMPLEMENTATION(bool ScenarioClass::Get_Local_Value(char const*, bool&), 0x005DFAE0);
DEFINE_IMPLEMENTATION(int ScenarioClass::Find_Global_Variable_Index(char const*), 0x005DF8D0);
DEFINE_IMPLEMENTATION(int ScenarioClass::Find_Local_Variable_Index(char const*), 0x00DFB70);
DEFINE_IMPLEMENTATION(int ScenarioClass::Find_Free_Local() const, 0x005DFDC0);
DEFINE_IMPLEMENTATION(int ScenarioClass::Num_Locals() const, 0x005DFDA0);
DEFINE_IMPLEMENTATION(int ScenarioClass::Unique_ID(), 0x005E1450);
DEFINE_IMPLEMENTATION(Cell ScenarioClass::Waypoint_Cell(WAYPOINT) const, 0x005E1460);
DEFINE_IMPLEMENTATION(AbstractClass* ScenarioClass::Waypoint_Target(WAYPOINT) const, 0x005E1480);
DEFINE_IMPLEMENTATION(CellClass* ScenarioClass::Waypoint_CellClass(WAYPOINT) const, 0x005E1700);
DEFINE_IMPLEMENTATION(Coord ScenarioClass::Waypoint_Coord(WAYPOINT) const, 0x005E14A0);
DEFINE_IMPLEMENTATION(void ScenarioClass::Clear_Waypoint(WAYPOINT), 0x005E16C0);
DEFINE_IMPLEMENTATION(void ScenarioClass::Clear_All_Waypoints(), 0x005E1500);
DEFINE_IMPLEMENTATION(bool ScenarioClass::Is_Waypoint_Valid(WAYPOINT) const, 0x005E1520);
DEFINE_IMPLEMENTATION(char const* ScenarioClass::Unused_Waypoint() const, 0x005E1720);
DEFINE_IMPLEMENTATION(void ScenarioClass::Set_Waypoint(WAYPOINT, Cell), 0x005E16E0);
DEFINE_IMPLEMENTATION(void ScenarioClass::Read_Waypoints(CCINIClass&), 0x005E1560);
DEFINE_IMPLEMENTATION(void ScenarioClass::Write_Waypoints(CCINIClass&), 0x005E1630);
DEFINE_IMPLEMENTATION(void ScenarioClass::Object_CRC(CRCEngine&) const, 0x005E10D0);
DEFINE_IMPLEMENTATION(void ScenarioClass::Save_Self(LPSTREAM), 0x005DF3C0);
DEFINE_IMPLEMENTATION(void ScenarioClass::Load_Self(LPSTREAM), 0x005DF500);
DEFINE_IMPLEMENTATION(bool Start_Scenario(char*, bool, CampaignType), 0x005DB170);
DEFINE_IMPLEMENTATION(bool Read_Scenario(char* name), 0x005DB9A0);
DEFINE_IMPLEMENTATION(void Clear_Scenario(), 0x005DC510);
DEFINE_IMPLEMENTATION(void Do_Win(), 0x005DC8D0);
DEFINE_IMPLEMENTATION(void Do_Lose(), 0x005DCC20);
DEFINE_IMPLEMENTATION(void Do_Restart(), 0x005DCE60);
DEFINE_IMPLEMENTATION(void Do_Abort(), 0x005DCF70);
DEFINE_IMPLEMENTATION(void Assign_Houses(), 0x005DE210);
DEFINE_IMPLEMENTATION(void Pause_Scenario(), 0x005DB4C0);
DEFINE_IMPLEMENTATION(void Resume_Scenario(), 0x005DB590);
DEFINE_IMPLEMENTATION(bool Change_Video_Mode(int, int), 0x0050AC30);
DEFINE_IMPLEMENTATION(bool Read_Scenario_INI(const char*, bool), 0x005DD100);
DEFINE_IMPLEMENTATION(bool Read_Scenario_INI(CCINIClass&, bool), 0x005DD4C0);
DEFINE_IMPLEMENTATION(void Last_Minute_Multiplayer_Fixups(bool), 0x005DD290);
DEFINE_IMPLEMENTATION(void Write_Scenario_INI(const char*, bool), 0x005DDFE0);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE WaypointPathClass::GetClassID(CLSID*), 0x006738B0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE WaypointPathClass::Load(IStream*), 0x006738F0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE WaypointPathClass::Save(IStream*, BOOL), 0x00673A00);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(WaypointPathClass::WaypointPathClass(), 0x006733D0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(WaypointPathClass::WaypointPathClass(int), 0x006734A0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(WaypointPathClass::WaypointPathClass(const NoInitClass &), 0x00673470);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(WaypointPathClass::~WaypointPathClass(), 0x00673550);
DEFINE_IMPLEMENTATION(RTTIType WaypointPathClass::Fetch_RTTI() const, 0x00673A80);
DEFINE_IMPLEMENTATION(int WaypointPathClass::Get_Object_Size(bool) const, 0x00673A70);
DEFINE_IMPLEMENTATION(void WaypointPathClass::Object_CRC(CRCEngine&) const, 0x00673880);
DEFINE_IMPLEMENTATION(Coord* WaypointPathClass::Get_Waypoint_Coord(int) const, 0x00673600);
// 00673620
// 006736D0
// 00673770
// 006737B0
// 00673820
// 00673860
// 006733A0

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(WaypointClass::WaypointClass(), 0x00673390);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(WaypointClass::~WaypointClass(), 0x006733C0);
DEFINE_IMPLEMENTATION(const char* Waypoint_As_String(int), 0x006732B0);
DEFINE_IMPLEMENTATION(int Waypoint_From_String(const char*), 0x00673330);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE CampaignClass::GetClassID(CLSID*), 0x00448DC0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE CampaignClass::Load(IStream*), 0x00448E60);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE CampaignClass::Save(IStream*, BOOL), 0x00448EA0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(CampaignClass::CampaignClass(const char *), AbstractTypeClass, 0x00448A10);
CampaignClass::CampaignClass(const NoInitClass& noinit) : AbstractTypeClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006CCBA8; *((unsigned long*)this + 1) = (unsigned long)0x006CCB8C; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(CampaignClass::~CampaignClass(), 0x00448AD0);
DEFINE_IMPLEMENTATION(RTTIType CampaignClass::Fetch_RTTI() const, 0x00448ED0);
DEFINE_IMPLEMENTATION(int CampaignClass::Get_Object_Size(bool) const, 0x00448EC0);
DEFINE_IMPLEMENTATION(void CampaignClass::Object_CRC(CRCEngine&) const, 0x00448E00);
DEFINE_IMPLEMENTATION(bool CampaignClass::Read_INI(CCINIClass&), 0x00448B80);
DEFINE_IMPLEMENTATION(int CampaignClass::Process(CCINIClass&), 0x00448C30);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE WaveClass::GetClassID(CLSID*), 0x00670D10);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE WaveClass::Load(IStream*), 0x00670B50);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE WaveClass::Save(IStream*, BOOL), 0x00670CA0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(WaveClass::WaveClass(), ObjectClass, 0x006700B0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(WaveClass::WaveClass(Coord &, Coord &, AbstractClass *, WaveType, AbstractClass *), ObjectClass, 0x0066FDE0);
WaveClass::WaveClass(const NoInitClass& noinit) : ObjectClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D97C8; *((unsigned long*)this + 1) = (unsigned long)0x006D97AC; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(WaveClass::~WaveClass(), 0x006702C0);
DEFINE_IMPLEMENTATION(void WaveClass::Detach(AbstractClass*, bool), 0x00670B10);
DEFINE_IMPLEMENTATION(RTTIType WaveClass::Fetch_RTTI() const, 0x00672E50);
DEFINE_IMPLEMENTATION(int WaveClass::Get_Object_Size(bool) const, 0x00670D50);
DEFINE_IMPLEMENTATION(void WaveClass::AI(), 0x00671B00);
DEFINE_IMPLEMENTATION(LayerType WaveClass::In_Which_Layer() const, 0x00670D60);
DEFINE_IMPLEMENTATION(const ObjectTypeClass* WaveClass::Class_Of() const, 0x00670D70);
DEFINE_IMPLEMENTATION(bool WaveClass::Limbo(), 0x00670E40);
DEFINE_IMPLEMENTATION(bool WaveClass::Unlimbo(const Coord&, Dir256), 0x00670D80);
DEFINE_IMPLEMENTATION(void WaveClass::Draw_It(Point2D&, Rect&) const, 0x00670EA0);
DEFINE_IMPLEMENTATION(void WaveClass::Sonic_AI(), 0x00671BB0);
DEFINE_IMPLEMENTATION(void WaveClass::Laser_AI(), 0x00671C20);
DEFINE_IMPLEMENTATION(void WaveClass::func_6709C0(Cell&), 0x006709C0);
DEFINE_IMPLEMENTATION(void WaveClass::Sonic_Draw_It(Point2D&, Rect&) const, 0x00670F10);
DEFINE_IMPLEMENTATION(void WaveClass::Laser_Draw_It(Point2D&, Rect&) const, 0x006715F0);
DEFINE_IMPLEMENTATION(void WaveClass::func_670370(int, int, int, unsigned short*), 0x00670370);
DEFINE_IMPLEMENTATION(void WaveClass::func_670650(), 0x00670650);
DEFINE_IMPLEMENTATION(void WaveClass::func_670840(Coord&), 0x00670840);
DEFINE_IMPLEMENTATION(void WaveClass::func_671C40(), 0x00671C40);
DEFINE_IMPLEMENTATION(void WaveClass::func_672AA0(), 0x00672AA0);
DEFINE_IMPLEMENTATION(void WaveClass::func_672160(Coord&, Coord&), 0x00672160);
DEFINE_IMPLEMENTATION(void WaveClass::func_670580(), 0x00670580);
DEFINE_IMPLEMENTATION(void WaveClass::func_6704B0(int, int), 0x6704B0);

DEFINE_IMPLEMENTATION(HRESULT CStreamClass::QueryInterface(REFIID, LPVOID*), 0x00471930);
DEFINE_IMPLEMENTATION(ULONG CStreamClass::AddRef(), 0x004718D0);
DEFINE_IMPLEMENTATION(ULONG CStreamClass::Release(), 0x004718F0);
DEFINE_IMPLEMENTATION(HRESULT CStreamClass::Read(void*, ULONG, ULONG*), 0x00471B00);
DEFINE_IMPLEMENTATION(HRESULT CStreamClass::Write(const void*, ULONG, ULONG*), 0x00471C70);
DEFINE_IMPLEMENTATION(HRESULT CStreamClass::Seek(LARGE_INTEGER, DWORD, ULARGE_INTEGER*), 0x00471DA0);
DEFINE_IMPLEMENTATION(HRESULT CStreamClass::SetSize(ULARGE_INTEGER), 0x00471DF0);
DEFINE_IMPLEMENTATION(HRESULT CStreamClass::CopyTo(IStream*, ULARGE_INTEGER, ULARGE_INTEGER*, ULARGE_INTEGER*), 0x00471E40);
DEFINE_IMPLEMENTATION(HRESULT CStreamClass::Commit(DWORD), 0x00471E80);
DEFINE_IMPLEMENTATION(HRESULT CStreamClass::Revert(), 0x00471EB0);
DEFINE_IMPLEMENTATION(HRESULT CStreamClass::LockRegion(ULARGE_INTEGER, ULARGE_INTEGER, DWORD), 0x00471EE0);
DEFINE_IMPLEMENTATION(HRESULT CStreamClass::UnlockRegion(ULARGE_INTEGER, ULARGE_INTEGER, DWORD), 0x00471F20);
DEFINE_IMPLEMENTATION(HRESULT CStreamClass::Stat(STATSTG*, DWORD), 0x00471F60);
DEFINE_IMPLEMENTATION(HRESULT CStreamClass::Clone(IStream**), 0x00471F90);
DEFINE_IMPLEMENTATION(HRESULT CStreamClass::Link_Stream(IUnknown*), 0x004719C0);
DEFINE_IMPLEMENTATION(HRESULT CStreamClass::Unlink_Stream(IUnknown**), 0x00471A50);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(CStreamClass::CStreamClass(), 0x004717C0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(CStreamClass::~CStreamClass(), 0x00471820);
DEFINE_IMPLEMENTATION(HRESULT CStreamClass::Compress(void*, ULONG), 0x00471FC0);
DEFINE_IMPLEMENTATION(HRESULT CStreamClass::Compress(), 0x00472080);

DEFINE_IMPLEMENTATION(int CacheStraw::Get(void*, int), 0x00471720);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(MultiMission::MultiMission(INIClass &, const char *), 0x005EF000);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(MultiMission::MultiMission(const char *, const char *, const char *, bool), 0x005EF3C0);
MultiMission::~MultiMission() {}
DEFINE_IMPLEMENTATION(bool MultiMission::Is_Available(DiskID), 0x005EF730);
DEFINE_IMPLEMENTATION(DiskID MultiMission::Get_Disk() const, 0x005EF800);
DEFINE_IMPLEMENTATION(void MultiMission::Set_Description(const char*), 0x005EF810);
DEFINE_IMPLEMENTATION(void MultiMission::Set_Filename(const char*), 0x005EF860);
DEFINE_IMPLEMENTATION(void MultiMission::Set_Digest(const char*), 0x005EF8C0);
DEFINE_IMPLEMENTATION(void MultiMission::Set_Official(bool), 0x005EF920);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE ParticleClass::GetClassID(CLSID*), 0x005A4FB0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE ParticleClass::Load(IStream*), 0x005A4E30);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE ParticleClass::Save(IStream*, BOOL), 0x005A4E90);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(ParticleClass::ParticleClass(), ObjectClass, 0x005A3170);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(ParticleClass::ParticleClass(ParticleTypeClass *, Coord &, Coord &, ParticleSystemClass *), ObjectClass, 0x005A2C90);
ParticleClass::ParticleClass(const NoInitClass& noinit) : ObjectClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D52CC; *((unsigned long*)this + 1) = (unsigned long)0x006D52B0; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(ParticleClass::~ParticleClass(), 0x005A32E0);
DEFINE_IMPLEMENTATION(RTTIType ParticleClass::Fetch_RTTI() const, 0x005A5000);
DEFINE_IMPLEMENTATION(int ParticleClass::Get_Object_Size(bool) const, 0x005A4FF0);
DEFINE_IMPLEMENTATION(LayerType ParticleClass::In_Which_Layer() const, 0x005A4E00);
DEFINE_IMPLEMENTATION(const ObjectTypeClass* ParticleClass::Class_Of() const, 0x005A5010);
DEFINE_IMPLEMENTATION(Cell* ParticleClass::Occupy_List(bool) const, 0x005A4DA0);
DEFINE_IMPLEMENTATION(void ParticleClass::Draw_It(Point2D&, Rect&) const, 0x005A45C0);
DEFINE_IMPLEMENTATION(bool ParticleClass::Mark(MarkType), 0x005A4D80);
DEFINE_IMPLEMENTATION(int ParticleClass::Shape_Number() const, 0x005A4EB0);
DEFINE_IMPLEMENTATION(void ParticleClass::Smoke_Behavior_AI(), 0x005A3360);
DEFINE_IMPLEMENTATION(void ParticleClass::Railgun_Behavior_AI(), 0x005A3A00);
DEFINE_IMPLEMENTATION(void ParticleClass::Gas_Behavior_AI(), 0x005A3B80);
DEFINE_IMPLEMENTATION(void ParticleClass::Spark_Behavior_AI(), 0x005A3D00);
DEFINE_IMPLEMENTATION(void ParticleClass::Fire_Behavior_AI(), 0x005A4120);
DEFINE_IMPLEMENTATION(void ParticleClass::Web_Behavior_AI(), 0x005A4440);
DEFINE_IMPLEMENTATION(void ParticleClass::Behaviour_AI(), 0x005A4530);
DEFINE_IMPLEMENTATION(void ParticleClass::Smoke_Coord_AI(), 0x005A4940);
DEFINE_IMPLEMENTATION(void ParticleClass::Gas_Coord_AI(), 0x005A4A80);
DEFINE_IMPLEMENTATION(void ParticleClass::Fire_Coord_AI(), 0x005A4B90);
DEFINE_IMPLEMENTATION(void ParticleClass::Coord_AI(), 0x005A4C60);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE ParticleSystemClass::GetClassID(CLSID*), 0x005A7840);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE ParticleSystemClass::Load(IStream*), 0x005A75E0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE ParticleSystemClass::Save(IStream*, BOOL), 0x005A7730);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(ParticleSystemClass::ParticleSystemClass(), ObjectClass, 0x005A5580);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(ParticleSystemClass::ParticleSystemClass(const ParticleSystemTypeClass *, Coord &, AbstractClass *, AbstractClass *, Coord &), ObjectClass, 0x005A5300);
ParticleSystemClass::ParticleSystemClass(const NoInitClass& noinit) : ObjectClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D54B4; *((unsigned long*)this + 1) = (unsigned long)0x006D5498; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(ParticleSystemClass::~ParticleSystemClass(), 0x005A56C0);
DEFINE_IMPLEMENTATION(void ParticleSystemClass::Detach(AbstractClass*, bool), 0x005A7550);
DEFINE_IMPLEMENTATION(RTTIType ParticleSystemClass::Fetch_RTTI() const, 0x005A78A0);
DEFINE_IMPLEMENTATION(int ParticleSystemClass::Get_Object_Size(bool) const, 0x005A7890);
DEFINE_IMPLEMENTATION(void ParticleSystemClass::Object_CRC(CRCEngine&) const, 0x005A77A0);
DEFINE_IMPLEMENTATION(bool ParticleSystemClass::Is_Inactive() const, 0x005A7520);
DEFINE_IMPLEMENTATION(void ParticleSystemClass::AI(), 0x005A7420);
DEFINE_IMPLEMENTATION(LayerType ParticleSystemClass::In_Which_Layer() const, 0x005A7540);
DEFINE_IMPLEMENTATION(const ObjectTypeClass* ParticleSystemClass::Class_Of() const, 0x005A78B0);
DEFINE_IMPLEMENTATION(void ParticleSystemClass::Delete_Me(), 0x005A7880);
DEFINE_IMPLEMENTATION(void ParticleSystemClass::Draw_It(Point2D&, Rect&) const, 0x005A58A0);
DEFINE_IMPLEMENTATION(ParticleClass* ParticleSystemClass::Spawn_Held_Particle(const Coord&, const Coord&), 0x005A59B0);
DEFINE_IMPLEMENTATION(ParticleClass* ParticleSystemClass::Spawn_Particle(ParticleTypeClass*, const Coord&), 0x005A5A50);
DEFINE_IMPLEMENTATION(ParticleClass* ParticleSystemClass::Spawn_Held_Particle_Random(const Coord&, const Coord&, int), 0x005A5AD0);
DEFINE_IMPLEMENTATION(bool ParticleSystemClass::Delete_Particle(int), 0x005A5BD0);
DEFINE_IMPLEMENTATION(void ParticleSystemClass::Delete_All_Particles(), 0x005A5C40);
DEFINE_IMPLEMENTATION(void ParticleSystemClass::Gas_AI(), 0x005A5CB0);
DEFINE_IMPLEMENTATION(void ParticleSystemClass::Spark_AI(), 0x005A5E30);
DEFINE_IMPLEMENTATION(void ParticleSystemClass::Smoke_AI(), 0x005A6300);
DEFINE_IMPLEMENTATION(void ParticleSystemClass::Railgun_AI(), 0x005A67F0);
DEFINE_IMPLEMENTATION(void ParticleSystemClass::Fire_AI(), 0x005A6F20);
DEFINE_IMPLEMENTATION(void ParticleSystemClass::Web_AI(), 0x005A72A0);

#if 0
//DEFINE_IMPLEMENTATION_CONSTRUCTOR(Wstring::Wstring(), 0x006A2C10);
//DEFINE_IMPLEMENTATION_CONSTRUCTOR(Wstring::Wstring(const char *), 0x006A2C20);
//DEFINE_IMPLEMENTATION_CONSTRUCTOR(Wstring::Wstring(const Wstring &), 0x006A2C70);
//DEFINE_IMPLEMENTATION_DESTRUCTOR(Wstring::~Wstring(), 0x006A2CD0);
DEFINE_IMPLEMENTATION(bool Wstring::operator==(const char *) const, 0x006A2CF0);
DEFINE_IMPLEMENTATION(bool Wstring::operator==(const Wstring &) const, 0x006A2D50);
DEFINE_IMPLEMENTATION(bool Wstring::operator!=(const char *) const, 0x006A2DC0);
DEFINE_IMPLEMENTATION(bool Wstring::operator!=(const Wstring &) const, 0x006A2E10);
DEFINE_IMPLEMENTATION(const Wstring &Wstring::operator=(const char *), 0x006A2E80);
DEFINE_IMPLEMENTATION(const Wstring &Wstring::operator=(const Wstring &), 0x006A2EE0);
DEFINE_IMPLEMENTATION(bool Wstring::Concat(const char *), 0x006A2FA0);
DEFINE_IMPLEMENTATION(bool Wstring::Concat(unsigned, const char *), 0x006A3050);
DEFINE_IMPLEMENTATION(bool Wstring::Concat(const Wstring &), 0x006A30E0);
DEFINE_IMPLEMENTATION(Wstring &Wstring::operator+=(const char *), 0x006A31B0);
DEFINE_IMPLEMENTATION(Wstring &Wstring::operator+=(const Wstring &), 0x006A3260);
DEFINE_IMPLEMENTATION(Wstring Wstring::operator+(const char *) const, 0x006A3330);
DEFINE_IMPLEMENTATION(Wstring Wstring::operator+(const Wstring &) const, 0x006A3460);
DEFINE_IMPLEMENTATION(bool Wstring::Trim_Range(int, int), 0x006A35B0);
DEFINE_IMPLEMENTATION(bool Wstring::Remove_Character(const char), 0x006A3680);
DEFINE_IMPLEMENTATION(void Wstring::Remove_Spaces(), 0x006A3740);
DEFINE_IMPLEMENTATION(void Wstring::Release_Buffer(), 0x006A3760);
DEFINE_IMPLEMENTATION(void Wstring::Reserve(int), 0x006A3780);
DEFINE_IMPLEMENTATION(void Wstring::Merge_Strings(char *, int), 0x006A37D0);
DEFINE_IMPLEMENTATION(char *Wstring::Peek_Buffer(), 0x006A3820);
DEFINE_IMPLEMENTATION(char Wstring::operator[](int), 0x006A3830);
DEFINE_IMPLEMENTATION(int Wstring::Get_Length() const, 0x006A3860);
DEFINE_IMPLEMENTATION(bool Wstring::func_7B54D0(const char *, unsigned), 0x006A3880);
DEFINE_IMPLEMENTATION(bool Wstring::func_6A39E0(char, unsigned), 0x006A39E0);
DEFINE_IMPLEMENTATION(bool Wstring::func_6A3B20(const char *, const char *), 0x006A3B20);
DEFINE_IMPLEMENTATION(bool Wstring::Set(const char *), 0x006A3DB0);
DEFINE_IMPLEMENTATION(bool Wstring::Replace_Char(char, unsigned), 0x006A3E10);
DEFINE_IMPLEMENTATION(bool Wstring::Replace(unsigned, const char *), 0x006A3E40);
DEFINE_IMPLEMENTATION(Wstring Wstring::To_Lower() const, 0x006A3E90);
DEFINE_IMPLEMENTATION(Wstring Wstring::To_Upper() const, 0x006A3EE0);
DEFINE_IMPLEMENTATION(bool Wstring::Resize(unsigned), 0x006A3F30);
DEFINE_IMPLEMENTATION(bool Wstring::Trim_To_Char(char), 0x006A3FD0);
DEFINE_IMPLEMENTATION(int Wstring::Token(int, char *, Wstring &), 0x006A40A0);
DEFINE_IMPLEMENTATION(int Wstring::Next_Line(int, Wstring &), 0x006A4240);
#endif

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE IsometricTileClass::GetClassID(CLSID*), 0x004F2370);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE IsometricTileClass::Load(IStream*), 0x004F2260);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE IsometricTileClass::Save(IStream*, BOOL), 0x004F22B0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(IsometricTileClass::IsometricTileClass(IsometricTileType, Cell &), ObjectClass, 0x004F2070);
IsometricTileClass::IsometricTileClass(const NoInitClass& noinit) : ObjectClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D2DE0; *((unsigned long*)this + 1) = (unsigned long)0x006D2DC4; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(IsometricTileClass::~IsometricTileClass(), 0x004F2160);
DEFINE_IMPLEMENTATION(RTTIType IsometricTileClass::Fetch_RTTI() const, 0x004F2360);
DEFINE_IMPLEMENTATION(int IsometricTileClass::Get_Object_Size(bool) const, 0x004F2350);
DEFINE_IMPLEMENTATION(const ObjectTypeClass* IsometricTileClass::Class_Of() const, 0x004F23B0);
DEFINE_IMPLEMENTATION(bool IsometricTileClass::Limbo(), 0x004F2300);
DEFINE_IMPLEMENTATION(bool IsometricTileClass::Unlimbo(const Coord&, Dir256), 0x004F22D0);
DEFINE_IMPLEMENTATION(void IsometricTileClass::Draw_It(Point2D&, Rect&) const, 0x004F23C0);
DEFINE_IMPLEMENTATION(bool IsometricTileClass::Mark(MarkType), 0x004F1C50);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(RadarEventClass::RadarEventClass(RadarEventType, Cell), 0x005C1CE0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(RadarEventClass::~RadarEventClass(), 0x005C1E40);
DEFINE_IMPLEMENTATION(void RadarEventClass::Process(), 0x005C1EC0);
DEFINE_IMPLEMENTATION(void RadarEventClass::Draw(), 0x005C2120);
DEFINE_IMPLEMENTATION(void RadarEventClass::Plot(), 0x005C25A0);
DEFINE_IMPLEMENTATION(int RadarEventClass::Get_Visibility_Duration(), 0x005C2AD0);
DEFINE_IMPLEMENTATION(int RadarEventClass::Get_Duration(), 0x005C2AF0);
DEFINE_IMPLEMENTATION(int RadarEventClass::Get_Supression_Distance(), 0x005C2B10);
DEFINE_IMPLEMENTATION(RGBClass RadarEventClass::Get_Max_Color(), 0x005C29B0);
DEFINE_IMPLEMENTATION(RGBClass RadarEventClass::Get_Min_Color(), 0x005C2A40);
DEFINE_IMPLEMENTATION(RadarDrawStruct RadarEventClass::Get_Draw_Data() const, 0x005C2790);
DEFINE_IMPLEMENTATION(bool RadarEventClass::Create_Event(RadarEventType, Cell), 0x005C1BC0);
DEFINE_IMPLEMENTATION(bool RadarEventClass::Is_Combat_Event(RadarEventType), 0x005C1CC0);
DEFINE_IMPLEMENTATION(void RadarEventClass::Process_Events(), 0x005C1E90);
DEFINE_IMPLEMENTATION(void RadarEventClass::Draw_Events(), 0x005C20D0);
DEFINE_IMPLEMENTATION(void RadarEventClass::Remove_Finished(), 0x005C2400);
DEFINE_IMPLEMENTATION(bool RadarEventClass::Suppression_Check(RadarEventType, int, Cell), 0x005C24B0);
DEFINE_IMPLEMENTATION(bool RadarEventClass::Any_Active(), 0x005C2590);
DEFINE_IMPLEMENTATION(void RadarEventClass::Plot_Point(Point2D*), 0x005C1CB0);
DEFINE_IMPLEMENTATION(void RadarEventClass::Clear_All(), 0x005C2B30);
DEFINE_IMPLEMENTATION(bool RadarEventClass::Save_All(IStream*), 0x005C2830);
DEFINE_IMPLEMENTATION(bool RadarEventClass::Load_All(IStream*), 0x005C28A0);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE TeleportLocomotionClass::GetClassID(CLSID*), 0x0063EE70);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TeleportLocomotionClass::Load(IStream*), 0x0063EEB0);
DEFINE_IMPLEMENTATION(bool TeleportLocomotionClass::Is_Moving(), 0x0063ED00);
DEFINE_IMPLEMENTATION(Coord TeleportLocomotionClass::Destination(), 0x0063ED50);
DEFINE_IMPLEMENTATION(bool TeleportLocomotionClass::Process(), 0x0063EE10);
DEFINE_IMPLEMENTATION(void TeleportLocomotionClass::Move_To(Coord), 0x0063EDC0);
DEFINE_IMPLEMENTATION(void TeleportLocomotionClass::Stop_Moving(), 0x0063EDE0);
DEFINE_IMPLEMENTATION(LayerType TeleportLocomotionClass::In_Which_Layer(), 0x0063EEE0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(TeleportLocomotionClass::TeleportLocomotionClass(), 0x0063ECC0);
TeleportLocomotionClass::TeleportLocomotionClass(const NoInitClass& noinit) : LocomotionClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D8228; *((unsigned long*)this + 1) = (unsigned long)0x006D8164; }
TeleportLocomotionClass::~TeleportLocomotionClass() {}
DEFINE_IMPLEMENTATION(int TeleportLocomotionClass::Get_Object_Size(bool) const, 0x0063EEF0);
DEFINE_IMPLEMENTATION(bool TeleportLocomotionClass::Is_Stationary() const, 0x0063ED40);

DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE WalkLocomotionClass::QueryInterface(REFIID, LPVOID*), 0x0066E670);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE WalkLocomotionClass::AddRef(), 0x0066E9A0);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE WalkLocomotionClass::Release(), 0x0066E9B0);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE WalkLocomotionClass::GetClassID(CLSID*), 0x0066E4C0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE WalkLocomotionClass::Load(IStream*), 0x0066E500);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE WalkLocomotionClass::Save(IStream*, BOOL), 0x0066E580);
DEFINE_IMPLEMENTATION(bool WalkLocomotionClass::Is_Moving(), 0x0066CB00);
DEFINE_IMPLEMENTATION(Coord WalkLocomotionClass::Destination(), 0x0066CB70);
DEFINE_IMPLEMENTATION(Coord WalkLocomotionClass::Head_To_Coord(), 0x0066CBD0);
DEFINE_IMPLEMENTATION(bool WalkLocomotionClass::Process(), 0x0066CC40);
DEFINE_IMPLEMENTATION(void WalkLocomotionClass::Move_To(Coord), 0x0066CC70);
DEFINE_IMPLEMENTATION(void WalkLocomotionClass::Stop_Moving(), 0x0066CD30);
DEFINE_IMPLEMENTATION(void WalkLocomotionClass::Do_Turn(DirType), 0x0066CD80);
DEFINE_IMPLEMENTATION(LayerType WalkLocomotionClass::In_Which_Layer(), 0x0066E660);
DEFINE_IMPLEMENTATION(void WalkLocomotionClass::Force_Immediate_Destination(Coord), 0x0066CDB0);
DEFINE_IMPLEMENTATION(bool WalkLocomotionClass::Is_Moving_Now(), 0x0066CB10);
DEFINE_IMPLEMENTATION(void WalkLocomotionClass::Mark_All_Occupation_Bits(MarkType), 0x0066E8A0);
DEFINE_IMPLEMENTATION(bool WalkLocomotionClass::Is_Moving_Here(Coord), 0x0066E8F0);
DEFINE_IMPLEMENTATION(bool WalkLocomotionClass::Is_Really_Moving_Now(), 0x0066E990);
DEFINE_IMPLEMENTATION(void WalkLocomotionClass::Stop_Movement_Animation(), 0x0066E9E0);
DEFINE_IMPLEMENTATION(HRESULT WalkLocomotionClass::Begin_Piggyback(ILocomotion*), 0x0066E6D0);
DEFINE_IMPLEMENTATION(HRESULT WalkLocomotionClass::End_Piggyback(ILocomotion**), 0x0066E720);
DEFINE_IMPLEMENTATION(bool WalkLocomotionClass::Is_Ok_To_End(), 0x0066E760);
DEFINE_IMPLEMENTATION(HRESULT WalkLocomotionClass::Piggyback_CLSID(CLSID*), 0x0066E790);
DEFINE_IMPLEMENTATION(bool WalkLocomotionClass::Is_Piggybacking(), 0x0066E9C0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(WalkLocomotionClass::WalkLocomotionClass(), 0x0066CA60);
WalkLocomotionClass::WalkLocomotionClass(const NoInitClass& noinit) : LocomotionClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D96C8; *((unsigned long*)this + 1) = (unsigned long)0x006D9600; *((unsigned long*)this + 2) = (unsigned long)0x006D95DC; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(WalkLocomotionClass::~WalkLocomotionClass(), 0x0066CAD0);
DEFINE_IMPLEMENTATION(int WalkLocomotionClass::Get_Object_Size(bool) const, 0x0066E9F0);
DEFINE_IMPLEMENTATION(void WalkLocomotionClass::Internal_Process(bool), 0x0066CE10);
DEFINE_IMPLEMENTATION(bool WalkLocomotionClass::func_66E170(Coord&), 0x0066E170);

DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE DriveLocomotionClass::QueryInterface(REFIID, LPVOID*), 0x0047D0F0);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE DriveLocomotionClass::AddRef(), 0x004822F0);
DEFINE_IMPLEMENTATION(ULONG STDMETHODCALLTYPE DriveLocomotionClass::Release(), 0x00482300);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE DriveLocomotionClass::GetClassID(CLSID*), 0x00481E80);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE DriveLocomotionClass::Load(IStream*), 0x0047D150);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE DriveLocomotionClass::Save(IStream*, BOOL), 0x0047D1D0);
DEFINE_IMPLEMENTATION(bool DriveLocomotionClass::Is_Moving(), 0x0047D540);
DEFINE_IMPLEMENTATION(Coord DriveLocomotionClass::Destination(), 0x0047D640);
DEFINE_IMPLEMENTATION(Coord DriveLocomotionClass::Head_To_Coord(), 0x0047D670);
DEFINE_IMPLEMENTATION(Matrix3D DriveLocomotionClass::Draw_Matrix(int*), 0x0047D8C0);
DEFINE_IMPLEMENTATION(int DriveLocomotionClass::Z_Adjust(), 0x00481EC0);
DEFINE_IMPLEMENTATION(ZGradientType DriveLocomotionClass::Z_Gradient(), 0x00481ED0);
DEFINE_IMPLEMENTATION(bool DriveLocomotionClass::Process(), 0x0047DDA0);
DEFINE_IMPLEMENTATION(void DriveLocomotionClass::Move_To(Coord), 0x0047D6E0);
DEFINE_IMPLEMENTATION(void DriveLocomotionClass::Stop_Moving(), 0x0047D760);
DEFINE_IMPLEMENTATION(void DriveLocomotionClass::Do_Turn(DirType), 0x0047E710);
DEFINE_IMPLEMENTATION(void DriveLocomotionClass::Unlimbo(), 0x0047DD70);
DEFINE_IMPLEMENTATION(void DriveLocomotionClass::Force_Track(int, Coord), 0x0047E470);
DEFINE_IMPLEMENTATION(LayerType DriveLocomotionClass::In_Which_Layer(), 0x00481E70);
DEFINE_IMPLEMENTATION(void DriveLocomotionClass::Force_New_Slope(TileRampType), 0x0047D500);
DEFINE_IMPLEMENTATION(bool DriveLocomotionClass::Is_Moving_Now(), 0x0047D5D0);
DEFINE_IMPLEMENTATION(void DriveLocomotionClass::Mark_All_Occupation_Bits(MarkType), 0x00481F20);
DEFINE_IMPLEMENTATION(bool DriveLocomotionClass::Is_Moving_Here(Coord), 0x00481F70);
DEFINE_IMPLEMENTATION(bool DriveLocomotionClass::Will_Jump_Tracks(), 0x00482150);
DEFINE_IMPLEMENTATION(void DriveLocomotionClass::Lock(), 0x00482230);
DEFINE_IMPLEMENTATION(void DriveLocomotionClass::Unlock(), 0x00482240);
DEFINE_IMPLEMENTATION(int DriveLocomotionClass::Get_Track_Number(), 0x00482250);
DEFINE_IMPLEMENTATION(int DriveLocomotionClass::Get_Track_Index(), 0x00482260);
DEFINE_IMPLEMENTATION(int DriveLocomotionClass::Get_Speed_Accum(), 0x00482270);
DEFINE_IMPLEMENTATION(HRESULT DriveLocomotionClass::Begin_Piggyback(ILocomotion*), 0x0047D2B0);
DEFINE_IMPLEMENTATION(HRESULT DriveLocomotionClass::End_Piggyback(ILocomotion**), 0x0047D300);
DEFINE_IMPLEMENTATION(bool DriveLocomotionClass::Is_Ok_To_End(), 0x0047D340);
DEFINE_IMPLEMENTATION(HRESULT DriveLocomotionClass::Piggyback_CLSID(CLSID*), 0x0047CFE0);
DEFINE_IMPLEMENTATION(bool DriveLocomotionClass::Is_Piggybacking(), 0x00482310);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(DriveLocomotionClass::DriveLocomotionClass(), 0x0047CF10);
DriveLocomotionClass::DriveLocomotionClass(const NoInitClass& noinit) : LocomotionClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006CF824; *((unsigned long*)this + 1) = (unsigned long)0x006CF75C; *((unsigned long*)this + 2) = (unsigned long)0x006CF738; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(DriveLocomotionClass::~DriveLocomotionClass(), 0x0047CFB0);
DEFINE_IMPLEMENTATION(int DriveLocomotionClass::Get_Object_Size(bool) const, 0x00482330);
// 0047D370
// 0047D460
// 0047D4C0
// 0047D830
DEFINE_IMPLEMENTATION(void DriveLocomotionClass::Mark_Track(Coord&, MarkType), 0x0047E300);
DEFINE_IMPLEMENTATION(bool DriveLocomotionClass::Stop_Driver(), 0x0047E5D0);
DEFINE_IMPLEMENTATION(bool DriveLocomotionClass::Start_Driver(Coord&), 0x0047E620);
DEFINE_IMPLEMENTATION(bool DriveLocomotionClass::While_Moving(bool), 0x0047E740);
DEFINE_IMPLEMENTATION(bool DriveLocomotionClass::Start_Of_Move(bool*, bool, bool), 0x0047FD60);
// 00481DC0
DEFINE_IMPLEMENTATION(Coord DriveLocomotionClass::Smooth_Turn(Coord&, Dir256&), 0x00481DD0);
DEFINE_IMPLEMENTATION(bool DriveLocomotionClass::Incoming(Cell), 0x00481E50);
// 00481EE0

DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE FlyLocomotionClass::GetClassID(CLSID*), 0x0049CD20);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE FlyLocomotionClass::Load(IStream*), 0x0049CD60);
DEFINE_IMPLEMENTATION(bool FlyLocomotionClass::Is_Moving(), 0x00499550);
DEFINE_IMPLEMENTATION(Coord FlyLocomotionClass::Destination(), 0x004995A0);
DEFINE_IMPLEMENTATION(Matrix3D FlyLocomotionClass::Draw_Matrix(int*), 0x0049C640);
DEFINE_IMPLEMENTATION(Matrix3D FlyLocomotionClass::Shadow_Matrix(int*), 0x0049CBB0);
DEFINE_IMPLEMENTATION(Point2D FlyLocomotionClass::Draw_Point(), 0x0049C9E0);
DEFINE_IMPLEMENTATION(Point2D FlyLocomotionClass::Shadow_Point(), 0x0049CAF0);
DEFINE_IMPLEMENTATION(bool FlyLocomotionClass::Process(), 0x00499600);
DEFINE_IMPLEMENTATION(void FlyLocomotionClass::Move_To(Coord), 0x004997C0);
DEFINE_IMPLEMENTATION(void FlyLocomotionClass::Stop_Moving(), 0x00499AB0);
DEFINE_IMPLEMENTATION(void FlyLocomotionClass::Do_Turn(DirType), 0x0049CCB0);
DEFINE_IMPLEMENTATION(bool FlyLocomotionClass::Power_Off(), 0x0049CDC0);
DEFINE_IMPLEMENTATION(bool FlyLocomotionClass::Is_Powered(), 0x0049CE30);
DEFINE_IMPLEMENTATION(bool FlyLocomotionClass::Is_Ion_Sensitive(), 0x0049CE40);
DEFINE_IMPLEMENTATION(LayerType FlyLocomotionClass::In_Which_Layer(), 0x0049CD90);
DEFINE_IMPLEMENTATION(bool FlyLocomotionClass::Is_Moving_Now(), 0x00499580);
DEFINE_IMPLEMENTATION(int FlyLocomotionClass::Apparent_Speed(), 0x0049CEC0);
DEFINE_IMPLEMENTATION(int FlyLocomotionClass::Get_Status(), 0x0049CEF0);
DEFINE_IMPLEMENTATION(void FlyLocomotionClass::Acquire_Hunter_Seeker_Target(), 0x0049CF20);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(FlyLocomotionClass::FlyLocomotionClass(), 0x004994B0);
FlyLocomotionClass::FlyLocomotionClass(const NoInitClass&) {}
// DEFINE_IMPLEMENTATION_DESTRUCTOR(FlyLocomotionClass::~FlyLocomotionClass(), 0x00499530);
DEFINE_IMPLEMENTATION(int FlyLocomotionClass::Get_Object_Size(bool) const, 0x0049D3B0);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE MechLocomotionClass::GetClassID(CLSID*), 0x005579F0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE MechLocomotionClass::Load(IStream*), 0x00557A30);
DEFINE_IMPLEMENTATION(bool MechLocomotionClass::Is_Moving(), 0x005560C0);
DEFINE_IMPLEMENTATION(Coord MechLocomotionClass::Destination(), 0x005560D0);
DEFINE_IMPLEMENTATION(Coord MechLocomotionClass::Head_To_Coord(), 0x00556130);
DEFINE_IMPLEMENTATION(bool MechLocomotionClass::Process(), 0x005561A0);
DEFINE_IMPLEMENTATION(void MechLocomotionClass::Move_To(Coord), 0x005561C0);
DEFINE_IMPLEMENTATION(void MechLocomotionClass::Stop_Moving(), 0x00556240);
DEFINE_IMPLEMENTATION(void MechLocomotionClass::Do_Turn(DirType), 0x00556290);
DEFINE_IMPLEMENTATION(LayerType MechLocomotionClass::In_Which_Layer(), 0x00557A60);
DEFINE_IMPLEMENTATION(void MechLocomotionClass::Force_Immediate_Destination(Coord), 0x005562C0);
DEFINE_IMPLEMENTATION(bool MechLocomotionClass::Is_Moving_Now(), 0x00557A70);
DEFINE_IMPLEMENTATION(void MechLocomotionClass::Mark_All_Occupation_Bits(MarkType), 0x00557AE0);
DEFINE_IMPLEMENTATION(bool MechLocomotionClass::Is_Moving_Here(Coord), 0x00557B60);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(MechLocomotionClass::MechLocomotionClass(), 0x00556040);
MechLocomotionClass::MechLocomotionClass(const NoInitClass& noinit) : LocomotionClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D43EC; *((unsigned long*)this + 1) = (unsigned long)0x006D4324; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(MechLocomotionClass::~MechLocomotionClass(), 0x005560A0);
DEFINE_IMPLEMENTATION(int MechLocomotionClass::Get_Object_Size(bool) const, 0x00557C00);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE HoverLocomotionClass::GetClassID(CLSID*), 0x004D1860);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE HoverLocomotionClass::Load(IStream*), 0x004D18A0);
DEFINE_IMPLEMENTATION(bool HoverLocomotionClass::Is_Moving(), 0x004CF510);
DEFINE_IMPLEMENTATION(Coord HoverLocomotionClass::Destination(), 0x004CF590);
DEFINE_IMPLEMENTATION(Coord HoverLocomotionClass::Head_To_Coord(), 0x004CF5F0);
DEFINE_IMPLEMENTATION(Matrix3D HoverLocomotionClass::Draw_Matrix(int*), 0x004CEC00);
DEFINE_IMPLEMENTATION(bool HoverLocomotionClass::Process(), 0x004CED20);
DEFINE_IMPLEMENTATION(void HoverLocomotionClass::Move_To(Coord), 0x004CF660);
DEFINE_IMPLEMENTATION(void HoverLocomotionClass::Stop_Moving(), 0x004D0B70);
DEFINE_IMPLEMENTATION(void HoverLocomotionClass::Do_Turn(DirType), 0x004D0BC0);
DEFINE_IMPLEMENTATION(bool HoverLocomotionClass::Power_Off(), 0x004D1410);
DEFINE_IMPLEMENTATION(bool HoverLocomotionClass::Is_Powered(), 0x004D1480);
DEFINE_IMPLEMENTATION(bool HoverLocomotionClass::Is_Ion_Sensitive(), 0x004D14B0);
DEFINE_IMPLEMENTATION(bool HoverLocomotionClass::Push(DirType), 0x004D1600);
DEFINE_IMPLEMENTATION(bool HoverLocomotionClass::Shove(DirType), 0x004D17B0);
DEFINE_IMPLEMENTATION(LayerType HoverLocomotionClass::In_Which_Layer(), 0x004D18F0);
DEFINE_IMPLEMENTATION(bool HoverLocomotionClass::Is_Moving_Now(), 0x004CF560);
DEFINE_IMPLEMENTATION(void HoverLocomotionClass::Mark_All_Occupation_Bits(MarkType), 0x004D19B0);
DEFINE_IMPLEMENTATION(bool HoverLocomotionClass::Is_Moving_Here(Coord), 0x004D1A30);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(HoverLocomotionClass::HoverLocomotionClass(), 0x004CE8F0);
HoverLocomotionClass::HoverLocomotionClass(const NoInitClass& noinit) : LocomotionClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D1EEC; *((unsigned long*)this + 1) = (unsigned long)0x006D1F24; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(HoverLocomotionClass::~HoverLocomotionClass(), 0x004CE9D0);
DEFINE_IMPLEMENTATION(int HoverLocomotionClass::Get_Object_Size(bool) const, 0x004D1AD0);

CD::CD() {}
DEFINE_IMPLEMENTATION(bool CD::Is_Available(DiskID), 0x0044E7A0);
DEFINE_IMPLEMENTATION(bool CD::Insert_Disk(DiskID), 0x0044E7C0);
DEFINE_IMPLEMENTATION(bool CD::Init_Swap(DiskID), 0x0044E970);
DEFINE_IMPLEMENTATION(bool CD::Force_Available(DiskID), 0x004756B0);
DEFINE_IMPLEMENTATION(DiskID CD::Get_Volume_Index(), 0x0044E770);
DEFINE_IMPLEMENTATION(void CD::Set_Required_CD(DiskID), 0x0044E780);
DEFINE_IMPLEMENTATION(DiskID CD::Get_CD_Index(int, int), 0x004754A0);

DEFINE_IMPLEMENTATION(void VQA_Init_Option(), 0x0066C720);
DEFINE_IMPLEMENTATION(void VQA_Set_Option(VQAOptionType), 0x0066C760);
DEFINE_IMPLEMENTATION(void VQA_Clear_Option(VQAOptionType), 0x0066C780);
DEFINE_IMPLEMENTATION(bool VQA_Get_Option(VQAOptionType), 0x0066C7A0);
DEFINE_IMPLEMENTATION(bool VQA_Flip_Option(VQAOptionType), 0x0066C7C0);
DEFINE_IMPLEMENTATION(unsigned long VQA_GetTime(VQAHandle*), 0x007C3960);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(VQAClass::VQAClass(const char *, int, int, int, int, int, int), 0x0066B290);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(VQAClass::~VQAClass(), 0x0066B540);
DEFINE_IMPLEMENTATION(void VQAClass::func_66B780(void*), 0x0066B780);
DEFINE_IMPLEMENTATION(void VQAClass::func_66B7B0(), 0x0066B7B0);
DEFINE_IMPLEMENTATION(bool VQAClass::Open(), 0x0066B7C0);
DEFINE_IMPLEMENTATION(int VQAClass::func_66B830(), 0x0066B830);
DEFINE_IMPLEMENTATION(void VQAClass::Set_Volume(int), 0x0066B850);
DEFINE_IMPLEMENTATION(bool VQAClass::Play(int, int), 0x0066B870);
DEFINE_IMPLEMENTATION(bool VQAClass::func_66B8A0(int, int, int), 0x0066B8A0);
DEFINE_IMPLEMENTATION(void VQAClass::Seek_To_Frame(int), 0x0066B8F0);
DEFINE_IMPLEMENTATION(bool VQAClass::func_66B920(), 0x0066B920);
DEFINE_IMPLEMENTATION(int VQAClass::func_66B960(int, bool), 0x0066B960);
DEFINE_IMPLEMENTATION(void VQAClass::func_66BBC0(int), 0x0066BBC0);
DEFINE_IMPLEMENTATION(bool VQAClass::Advance_Frame(bool&), 0x0066BC30);
DEFINE_IMPLEMENTATION(void VQAClass::Pause(), 0x0066BDF0);
DEFINE_IMPLEMENTATION(void VQAClass::Resume(), 0x0066BE30);
DEFINE_IMPLEMENTATION(void VQAClass::Close(), 0x0066BE40);
DEFINE_IMPLEMENTATION(void VQAClass::func_66BE60(), 0x0066BE60);
DEFINE_IMPLEMENTATION(int VQAClass::func_66BE70() const, 0x0066BE70);
DEFINE_IMPLEMENTATION(bool VQAClass::Set_Draw_Buffer(void*, int, int, int, int), 0x0066BE80);
DEFINE_IMPLEMENTATION(void VQAClass::func_66BEF0(int), 0x0066BEF0);
DEFINE_IMPLEMENTATION(void VQAClass::func_66BF00(int, int), 0x0066BF00);
DEFINE_IMPLEMENTATION(int VQAClass::Get_Width() const, 0x0066BF40);
DEFINE_IMPLEMENTATION(int VQAClass::Get_Height() const, 0x0066BF50);
DEFINE_IMPLEMENTATION(void VQAClass::Lock_Surface(), 0x0066BF60);
DEFINE_IMPLEMENTATION(void VQAClass::Unlock_Surface(), 0x0066BF70);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(ProgressScreenClass::ProgressScreenClass(), 0x005AD890);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(ProgressScreenClass::~ProgressScreenClass(), 0x005AD8C0);
DEFINE_IMPLEMENTATION(void ProgressScreenClass::Init(double, int, bool), 0x005AD8D0);
DEFINE_IMPLEMENTATION(void ProgressScreenClass::Reset(), 0x005AD990);
DEFINE_IMPLEMENTATION(void ProgressScreenClass::Draw_Graphics(const char*, const char*, const char*, int, int), 0x005AD9A0);
DEFINE_IMPLEMENTATION(double ProgressScreenClass::Get_Total_Progress(), 0x005ADCB0);
DEFINE_IMPLEMENTATION(void ProgressScreenClass::Draw_Bars_And_Text(int, int), 0x005ADCE0);
DEFINE_IMPLEMENTATION(Rect ProgressScreenClass::Get_Bar_Dimensions(), 0x005ADFF0);
DEFINE_IMPLEMENTATION(void ProgressScreenClass::Update_Progress(int, double, int, int), 0x005AE050);
DEFINE_IMPLEMENTATION(void ProgressScreenClass::Add_Progress(int, double, int, int), 0x005AE0A0);
DEFINE_IMPLEMENTATION(void ProgressScreenClass::Init_Dialog(), 0x005AE0F0);
DEFINE_IMPLEMENTATION(void ProgressScreenClass::Destroy_Dialog(), 0x005AE130);
DEFINE_IMPLEMENTATION(LRESULT CALLBACK ProgressScreenClass::Dialog_Proc(HWND, UINT, WPARAM, LPARAM), 0x005AE150);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(EnvironmentClass::EnvironmentClass(), 0x00493860);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(EnvironmentClass::~EnvironmentClass(), 0x00493890);
DEFINE_IMPLEMENTATION(void EnvironmentClass::Snapshot_Game_State(), 0x004938A0);
DEFINE_IMPLEMENTATION(void EnvironmentClass::Apply_To_Game_State(), 0x00493920);
DEFINE_IMPLEMENTATION(void EnvironmentClass::Load(IStream*), 0x00493A30);
DEFINE_IMPLEMENTATION(void EnvironmentClass::Save(IStream*), 0x00493A50);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE TubeClass::GetClassID(CLSID*), 0x0064B5B0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TubeClass::Load(IStream*), 0x0064B080);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE TubeClass::Save(IStream*, BOOL), 0x0064B0C0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(TubeClass::TubeClass(Cell &, FacingType), AbstractClass, 0x0064AED0);
TubeClass::TubeClass(const NoInitClass &noinit) : AbstractClass(noinit) { *((unsigned long *)this) = (unsigned long)0x006D8928; *((unsigned long *)this+1) = (unsigned long)0x006D890C; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(TubeClass::~TubeClass(), 0x0064AFC0);
DEFINE_IMPLEMENTATION(RTTIType TubeClass::Fetch_RTTI() const, 0x0064B5A0);
DEFINE_IMPLEMENTATION(int TubeClass::Get_Object_Size(bool) const, 0x0064B590);
DEFINE_IMPLEMENTATION(void TubeClass::Object_CRC(CRCEngine&) const, 0x0064B510);
DEFINE_IMPLEMENTATION(void TubeClass::Add_Direction(FacingType), 0x0064B4B0);
DEFINE_IMPLEMENTATION(bool TubeClass::Is_Next_Cell(Cell&), 0x0064B420);
DEFINE_IMPLEMENTATION(void TubeClass::Assign_Tubes(), 0x0064B0E0);
DEFINE_IMPLEMENTATION(void TubeClass::Read_Scenario_INI(CCINIClass&), 0x0064B2A0);
DEFINE_IMPLEMENTATION(void TubeClass::Write_Scenario_INI(CCINIClass&), 0x0064B160);

DEFINE_IMPLEMENTATION(void Restate_Mission(ScenarioClass*), 0x005C0230);

DEFINE_IMPLEMENTATION(bool Detect_Addons(), 0x00407050);
DEFINE_IMPLEMENTATION(bool Is_Addon_Available(AddonType), 0x00407120);
DEFINE_IMPLEMENTATION(bool Is_Addon_Enabled(AddonType), 0x00407150);
DEFINE_IMPLEMENTATION(void Enable_Addon(AddonType), 0x00407190);
DEFINE_IMPLEMENTATION(void Disable_Addon(AddonType), 0x004071C0);
DEFINE_IMPLEMENTATION(bool Is_Required_Addon(AddonType), 0x004071F0);
DEFINE_IMPLEMENTATION(AddonType Get_Required_Addon(), 0x00407200);
DEFINE_IMPLEMENTATION(void Set_Required_Addon(AddonType), 0x00407210);

DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE LevitateLocomotionClass::GetClassID(CLSID*), 0x00500D10);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE LevitateLocomotionClass::Load(IStream*), 0x00500D50);
DEFINE_IMPLEMENTATION(HRESULT LevitateLocomotionClass::Link_To_Object(void*), 0x004FDF40);
DEFINE_IMPLEMENTATION(bool LevitateLocomotionClass::Is_Moving(), 0x00500C30);
DEFINE_IMPLEMENTATION(Coord LevitateLocomotionClass::Destination(), 0x00500C70);
DEFINE_IMPLEMENTATION(Coord LevitateLocomotionClass::Head_To_Coord(), 0x00500CA0);
DEFINE_IMPLEMENTATION(bool LevitateLocomotionClass::Process(), 0x00500990);
DEFINE_IMPLEMENTATION(LayerType LevitateLocomotionClass::In_Which_Layer(), 0x00500D80);
DEFINE_IMPLEMENTATION(bool LevitateLocomotionClass::Is_Moving_Now(), 0x00500C50);
DEFINE_IMPLEMENTATION(void LevitateLocomotionClass::Mark_All_Occupation_Bits(MarkType), 0x00501060);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(LevitateLocomotionClass::LevitateLocomotionClass(), 0x004FDEE0);
LevitateLocomotionClass::LevitateLocomotionClass(const NoInitClass &noinit) : LocomotionClass(noinit) { *((unsigned long *)this) = (unsigned long)0x006D3804; *((unsigned long *)this+1) = (unsigned long)0x006D373C; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(LevitateLocomotionClass::~LevitateLocomotionClass(), 0x004FDF60);
DEFINE_IMPLEMENTATION(int LevitateLocomotionClass::Get_Object_Size(bool) const, 0x005010B0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(NewMenuClass::NewMenuClass(), 0x0057FBE0);
DEFINE_IMPLEMENTATION(void NewMenuClass::Blit(), 0x0057FBA0);
DEFINE_IMPLEMENTATION(NewMenuClass* NewMenuClass::Get(), 0x0057FB40);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE JumpjetLocomotionClass::GetClassID(CLSID*), 0x004F9CE0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE JumpjetLocomotionClass::Load(IStream*), 0x004F9D20);
DEFINE_IMPLEMENTATION(bool JumpjetLocomotionClass::Is_Moving(), 0x004F9620);
DEFINE_IMPLEMENTATION(Coord JumpjetLocomotionClass::Destination(), 0x004F9630);
DEFINE_IMPLEMENTATION(Coord JumpjetLocomotionClass::Head_To_Coord(), 0x004FAD00);
DEFINE_IMPLEMENTATION(bool JumpjetLocomotionClass::Process(), 0x004F9690);
DEFINE_IMPLEMENTATION(void JumpjetLocomotionClass::Move_To(Coord), 0x004F9890);
DEFINE_IMPLEMENTATION(void JumpjetLocomotionClass::Stop_Moving(), 0x004F9AE0);
DEFINE_IMPLEMENTATION(void JumpjetLocomotionClass::Do_Turn(DirType), 0x004F9CB0);
DEFINE_IMPLEMENTATION(LayerType JumpjetLocomotionClass::In_Which_Layer(), 0x004F9D50);
DEFINE_IMPLEMENTATION(bool JumpjetLocomotionClass::Is_Moving_Now(), 0x004FA460);
DEFINE_IMPLEMENTATION(void JumpjetLocomotionClass::Mark_All_Occupation_Bits(MarkType), 0x004FAC80);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(JumpjetLocomotionClass::JumpjetLocomotionClass(), 0x004F9590);
JumpjetLocomotionClass::JumpjetLocomotionClass(const NoInitClass& noinit) : LocomotionClass(noinit) { *((unsigned long*)this) = (unsigned long)0x006D3684; *((unsigned long*)this + 1) = (unsigned long)0x006D35BC; }
// DEFINE_IMPLEMENTATION_DESTRUCTOR(JumpjetLocomotionClass::~JumpjetLocomotionClass(), 0x004F9600);
DEFINE_IMPLEMENTATION(int JumpjetLocomotionClass::Get_Object_Size(bool) const, 0x004FAD50);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(Dictionary::Dictionary(), 0x005FD410);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(Dictionary::~Dictionary(), 0x005FD4F0);
DEFINE_IMPLEMENTATION(unsigned Dictionary::CRC(Wstring&), 0x005FD4A0);

DEFINE_IMPLEMENTATION(bool SpriteCollectionClass::Load_PCX(const char*, int, bool), 0x005FDCC0);
DEFINE_IMPLEMENTATION(bool SpriteCollectionClass::Load_Mono_PCX(const char*), 0x005FE0E0);
DEFINE_IMPLEMENTATION(bool SpriteCollectionClass::Load_Bitmap(const char*, void*, int, int), 0x005FD700);
DEFINE_IMPLEMENTATION(BSurface* SpriteCollectionClass::Get_Image_Surface(const char*, void*), 0x005FE100);
DEFINE_IMPLEMENTATION(bool SpriteCollectionClass::Draw(Rect&, Surface&, Surface&, int, int), 0x005FE1F0);
DEFINE_IMPLEMENTATION(bool SpriteCollectionClass::Draw_Trans(Rect&, Surface&, Surface&, unsigned), 0x005FE390);
DEFINE_IMPLEMENTATION(bool SpriteCollectionClass::Draw_Alpha(Rect&, Surface&, Surface&, Surface&, void*, bool, int, int), 0x005FE490);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(ToggleClass::ToggleClass(unsigned, int, int, int, int), 0x00647000);
ToggleClass::~ToggleClass() {}
DEFINE_IMPLEMENTATION(bool ToggleClass::Action(unsigned, KeyNumType&), 0x00647060);
DEFINE_IMPLEMENTATION(void ToggleClass::Turn_On(), 0x00647040);
DEFINE_IMPLEMENTATION(void ToggleClass::Turn_Off(), 0x00647050);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(TextButtonClass::TextButtonClass(), 0x00643430);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(TextButtonClass::TextButtonClass(unsigned, const char *, TextPrintType, int, int, int, int, bool, bool), 0x006433A0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(TextButtonClass::TextButtonClass(unsigned, int, TextPrintType, int, int, int, int, bool, bool), 0x00643460);
TextButtonClass::~TextButtonClass() {}
DEFINE_IMPLEMENTATION(bool TextButtonClass::Draw_Me(bool), 0x00643510);
DEFINE_IMPLEMENTATION(void TextButtonClass::Set_Text(const char*, bool), 0x00643550);
DEFINE_IMPLEMENTATION(void TextButtonClass::Set_Text(int, bool), 0x006435A0);
DEFINE_IMPLEMENTATION(void TextButtonClass::Set_Style(TextPrintType), 0x005C1190);
DEFINE_IMPLEMENTATION(void TextButtonClass::Draw_Background(), 0x006435D0);
DEFINE_IMPLEMENTATION(void TextButtonClass::Draw_Text(const char*), 0x006436A0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(ABuffer::ABuffer(Rect), 0x00406540);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(ABuffer::~ABuffer(), 0x004066B0);
DEFINE_IMPLEMENTATION(void ABuffer::Copy_To(BSurface*, int, int, int, int), 0x00406620);
DEFINE_IMPLEMENTATION(void ABuffer::Set(unsigned int, int, unsigned), 0x004066D0);
DEFINE_IMPLEMENTATION(void ABuffer::Pan(int, int, unsigned), 0x00406730);
DEFINE_IMPLEMENTATION(bool ABuffer::Fill(unsigned), 0x00406B30);
DEFINE_IMPLEMENTATION(bool ABuffer::Fill(unsigned, Rect), 0x00406B70);
DEFINE_IMPLEMENTATION(void ABuffer::Update(int, int, int, int), 0x00406B90);
DEFINE_IMPLEMENTATION(unsigned int ABuffer::Get_Buffer_Offset(Point2D), 0x00406D10);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(ZBuffer::ZBuffer(Rect), 0x006A8DD0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(ZBuffer::~ZBuffer(), 0x006A8F40);
DEFINE_IMPLEMENTATION(void ZBuffer::Copy_To(BSurface*, int, int, int, int), 0x006A8EB0);
DEFINE_IMPLEMENTATION(void ZBuffer::Set(unsigned int, int, unsigned), 0x006A8F50);
DEFINE_IMPLEMENTATION(void ZBuffer::Pan(int, int, unsigned), 0x006A8FB0);
DEFINE_IMPLEMENTATION(bool ZBuffer::Fill(unsigned), 0x006A93B0);
DEFINE_IMPLEMENTATION(bool ZBuffer::Fill(unsigned, Rect), 0x006A93F0);
DEFINE_IMPLEMENTATION(void ZBuffer::Update(int, int, int, int), 0x006A9410);
DEFINE_IMPLEMENTATION(unsigned int ZBuffer::Get_Buffer_Offset(Point2D), 0x006A9590);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(GaugeClass::GaugeClass(unsigned, int, int, int, int), 0x004AACB0);
GaugeClass::~GaugeClass() {}
DEFINE_IMPLEMENTATION(bool GaugeClass::Draw_Me(bool), 0x004AAE40);
DEFINE_IMPLEMENTATION(bool GaugeClass::Action(unsigned, KeyNumType&), 0x004AAFE0);
DEFINE_IMPLEMENTATION(int GaugeClass::Set_Maximum(int), 0x004AAD30);
DEFINE_IMPLEMENTATION(int GaugeClass::Set_Value(int), 0x004AAD50);
DEFINE_IMPLEMENTATION(int GaugeClass::Get_Value() const, 0x004AB840);
DEFINE_IMPLEMENTATION(void GaugeClass::Use_Thumb(int), 0x004AB850);
DEFINE_IMPLEMENTATION(int GaugeClass::Thumb_Pixels(), 0x004AB860);
DEFINE_IMPLEMENTATION(void GaugeClass::Draw_Thumb(), 0x004AB140);
DEFINE_IMPLEMENTATION(int GaugeClass::Pixel_To_Value(int), 0x004AAD80);
DEFINE_IMPLEMENTATION(int GaugeClass::Value_To_Pixel(int), 0x004AAE00);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(TriColorGaugeClass::TriColorGaugeClass(unsigned, int, int, int, int), 0x004AB1F0);
TriColorGaugeClass::~TriColorGaugeClass() {}
DEFINE_IMPLEMENTATION(bool TriColorGaugeClass::Draw_Me(bool), 0x004AB2F0);
DEFINE_IMPLEMENTATION(int TriColorGaugeClass::Set_Red_Limit(int), 0x004AB290);
DEFINE_IMPLEMENTATION(int TriColorGaugeClass::Set_Yellow_Limit(int), 0x004AB2C0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(Dial8Class::Dial8Class(int, int, int, int, int, Dir256), 0x00473F30);
Dial8Class::~Dial8Class() {}
DEFINE_IMPLEMENTATION(bool Dial8Class::Draw_Me(bool), 0x00474330);
DEFINE_IMPLEMENTATION(bool Dial8Class::Action(unsigned, KeyNumType&), 0x004741E0);
DEFINE_IMPLEMENTATION(Dir256 Dial8Class::Get_Direction() const, 0x004744D0);
DEFINE_IMPLEMENTATION(void Dial8Class::Set_Direction(Dir256), 0x004744E0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(StaticButtonClass::StaticButtonClass(), 0x00608EF0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(StaticButtonClass::StaticButtonClass(unsigned, const char *, TextPrintType, int, int, int, int), 0x00608E50);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(StaticButtonClass::~StaticButtonClass(), 0x00608F30);
DEFINE_IMPLEMENTATION(bool StaticButtonClass::Draw_Me(bool), 0x00608F60);
DEFINE_IMPLEMENTATION(void StaticButtonClass::Set_Text(const char*, bool), 0x00608FA0);
DEFINE_IMPLEMENTATION(void StaticButtonClass::Draw_Background(), 0x00609070);
DEFINE_IMPLEMENTATION(void StaticButtonClass::Draw_Text(const char*), 0x00609120);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(ShapeButtonClass::ShapeButtonClass(), 0x005F15A0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(ShapeButtonClass::ShapeButtonClass(unsigned, const ShapeSet *, int, int), 0x005F15E0);
ShapeButtonClass::~ShapeButtonClass() {}
DEFINE_IMPLEMENTATION(bool ShapeButtonClass::Draw_Me(bool), 0x005F16A0);
DEFINE_IMPLEMENTATION(void ShapeButtonClass::Set_Shape(const ShapeSet*, int, int), 0x005F1660);

CheckBoxClass::CheckBoxClass(unsigned id, int x, int y) : ToggleClass(id, x, y, 7, 7) {}
CheckBoxClass::~CheckBoxClass() {}
DEFINE_IMPLEMENTATION(bool CheckBoxClass::Draw_Me(bool), 0x0045DA00);
DEFINE_IMPLEMENTATION(bool CheckBoxClass::Action(unsigned, KeyNumType&), 0x0045DB20);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(SliderClass::SliderClass(unsigned, int, int, int, int, bool), 0x005F7AC0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(SliderClass::~SliderClass(), 0x005F7C90);
DEFINE_IMPLEMENTATION(void SliderClass::Peer_To_Peer(unsigned, KeyNumType&, ControlClass&), 0x005F80E0);
DEFINE_IMPLEMENTATION(bool SliderClass::Draw_Me(bool), 0x005F8070);
DEFINE_IMPLEMENTATION(bool SliderClass::Action(unsigned, KeyNumType&), 0x005F7EE0);
DEFINE_IMPLEMENTATION(int SliderClass::Set_Maximum(int), 0x005F7CD0);
DEFINE_IMPLEMENTATION(int SliderClass::Set_Value(int), 0x005F7DE0);
DEFINE_IMPLEMENTATION(int SliderClass::Thumb_Pixels(), 0x005041A0);
DEFINE_IMPLEMENTATION(void SliderClass::Draw_Thumb(), 0x005F7FF0);
DEFINE_IMPLEMENTATION(void SliderClass::Set_Thumb_Size(int), 0x005F7D50);
DEFINE_IMPLEMENTATION(int SliderClass::Bump(bool), 0x005F7F80);
DEFINE_IMPLEMENTATION(int SliderClass::Step(bool), 0x005F7FC0);
DEFINE_IMPLEMENTATION(void SliderClass::Recalc_Thumb(), 0x005F7E70);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(ListClass::ListClass(int, int, int, int, int, TextPrintType, const void *, const void *), 0x00503280);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(ListClass::ListClass(const ListClass &), 0x005033E0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(ListClass::~ListClass(), 0x00503650);
DEFINE_IMPLEMENTATION(LinkClass& ListClass::Add(LinkClass&), 0x00503E90);
DEFINE_IMPLEMENTATION(LinkClass& ListClass::Add_Tail(LinkClass&), 0x00503F30);
DEFINE_IMPLEMENTATION(LinkClass& ListClass::Add_Head(LinkClass&), 0x00503EE0);
DEFINE_IMPLEMENTATION(GadgetClass* ListClass::Remove(), 0x00503F80);
DEFINE_IMPLEMENTATION(void ListClass::Flag_To_Redraw(), 0x00504050);
DEFINE_IMPLEMENTATION(void ListClass::Peer_To_Peer(unsigned, KeyNumType&, ControlClass&), 0x00503B90);
DEFINE_IMPLEMENTATION(void ListClass::Set_Position(int, int), 0x005035C0);
DEFINE_IMPLEMENTATION(bool ListClass::Draw_Me(bool), 0x005039A0);
DEFINE_IMPLEMENTATION(bool ListClass::Action(unsigned, KeyNumType&), 0x005038B0);
DEFINE_IMPLEMENTATION(int ListClass::Add_Item(const char*), 0x005036F0);
DEFINE_IMPLEMENTATION(int ListClass::Add_Item(int), 0x00503780);
DEFINE_IMPLEMENTATION(int ListClass::Add_Scroll_Bar(), 0x00503C60);
DEFINE_IMPLEMENTATION(void ListClass::Bump(int), 0x00503AA0);
DEFINE_IMPLEMENTATION(int ListClass::Count() const, 0x0045DFC0);
DEFINE_IMPLEMENTATION(int ListClass::Current_Index() const, 0x00503B80);
DEFINE_IMPLEMENTATION(char const* ListClass::Current_Item() const, 0x00503B60);
DEFINE_IMPLEMENTATION(char const* ListClass::Get_Item(int) const, 0x00503B40);
DEFINE_IMPLEMENTATION(int ListClass::Step_Selected_Index(int), 0x00504030);
DEFINE_IMPLEMENTATION(void ListClass::Remove_Item(const char*), 0x00503880);
DEFINE_IMPLEMENTATION(void ListClass::Remove_Item(int), 0x005037B0);
DEFINE_IMPLEMENTATION(int ListClass::Remove_Scroll_Bar(), 0x00503D30);
DEFINE_IMPLEMENTATION(void ListClass::Set_Selected_Index(const char*), 0x00504090);
DEFINE_IMPLEMENTATION(void ListClass::Set_Selected_Index(int), 0x00503FC0);
DEFINE_IMPLEMENTATION(void ListClass::Set_Tabs(const int*), 0x00503D90);
DEFINE_IMPLEMENTATION(int ListClass::Set_View_Index(int), 0x00503BF0);
DEFINE_IMPLEMENTATION(void ListClass::Step(int), 0x00503AF0);
DEFINE_IMPLEMENTATION(void ListClass::Draw_Entry(int, int, int, int, bool), 0x00503DA0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(ColorListClass::ColorListClass(int, int, int, int, int, TextPrintType, const void *, const void *), 0x0045E080);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(ColorListClass::~ColorListClass(), 0x0045E110);
DEFINE_IMPLEMENTATION(int ColorListClass::Add_Item(int), 0x0045E880);
DEFINE_IMPLEMENTATION(int ColorListClass::Add_Item(const char*), 0x0045E860);
DEFINE_IMPLEMENTATION(void ColorListClass::Remove_Item(int), 0x0045E290);
DEFINE_IMPLEMENTATION(void ColorListClass::Remove_Item(const char*), 0x0045E230);
DEFINE_IMPLEMENTATION(void ColorListClass::Draw_Entry(int, int, int, int, bool), 0x0045E300);
DEFINE_IMPLEMENTATION(int ColorListClass::Add_Item(const char*, ColorSchemeType), 0x0045E170);
DEFINE_IMPLEMENTATION(int ColorListClass::Add_Item(int, ColorSchemeType), 0x0045E1D0);
DEFINE_IMPLEMENTATION(void ColorListClass::Set_Selected_Style(SelectStyleType, ColorSchemeType), 0x0045E2E0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(CheckListClass::CheckListClass(int, int, int, int, int, TextPrintType, const void *, const void *), 0x0045DB90);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(CheckListClass::~CheckListClass(), 0x0045DBE0);
DEFINE_IMPLEMENTATION(bool CheckListClass::Action(unsigned, KeyNumType&), 0x0045DDB0);
DEFINE_IMPLEMENTATION(int CheckListClass::Add_Item(int), 0x0045DFD0);
DEFINE_IMPLEMENTATION(int CheckListClass::Add_Item(const char*), 0x0045DC20);
DEFINE_IMPLEMENTATION(const char* CheckListClass::Current_Item() const, 0x0045DC60);
DEFINE_IMPLEMENTATION(const char* CheckListClass::Get_Item(int) const, 0x0045DC70);
DEFINE_IMPLEMENTATION(void CheckListClass::Remove_Item(int), 0x0045DFE0);
DEFINE_IMPLEMENTATION(void CheckListClass::Remove_Item(const char*), 0x0045DC90);
DEFINE_IMPLEMENTATION(void CheckListClass::Set_Selected_Index(int), 0x0045DFF0);
DEFINE_IMPLEMENTATION(void CheckListClass::Set_Selected_Index(const char*), 0x0045DD00);
DEFINE_IMPLEMENTATION(void CheckListClass::Draw_Entry(int, int, int, int, bool), 0x0045DE30);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(EditClass::EditClass(int, char *, int, TextPrintType, int, int, int, int, EditStyle), 0x00490280);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(EditClass::~EditClass(), 0x00490380);
DEFINE_IMPLEMENTATION(void EditClass::Set_Focus(), 0x00490830);
DEFINE_IMPLEMENTATION(bool EditClass::Draw_Me(bool), 0x004903E0);
DEFINE_IMPLEMENTATION(bool EditClass::Action(unsigned, KeyNumType&), 0x00490460);
DEFINE_IMPLEMENTATION(void EditClass::Set_Text(const char*, int), 0x004903B0);
DEFINE_IMPLEMENTATION(const char* EditClass::Get_Text(), 0x00482BB0);
DEFINE_IMPLEMENTATION(void EditClass::Draw_Background(), 0x00490570);
DEFINE_IMPLEMENTATION(void EditClass::Draw_Text(const char*), 0x004905B0);
DEFINE_IMPLEMENTATION(bool EditClass::Handle_Key(KeyASCIIType), 0x004906F0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(DropListClass::DropListClass(int, char *, int, TextPrintType, int, int, int, int, const void *, const void *), 0x00482450);
DropListClass::~DropListClass() {}
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(DropListClass & DropListClass::operator = (const DropListClass &), 0x00482860);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(DropListClass::DropListClass(const DropListClass &), 0x00482A10);
DEFINE_IMPLEMENTATION(DropListClass& DropListClass::Add_Tail(LinkClass&), 0x00482560);
DEFINE_IMPLEMENTATION(DropListClass& DropListClass::Add_Head(LinkClass&), 0x00482580);
DEFINE_IMPLEMENTATION(DropListClass& DropListClass::Add(LinkClass&), 0x004825A0);
DEFINE_IMPLEMENTATION(void DropListClass::Zap(), 0x00482520);
DEFINE_IMPLEMENTATION(DropListClass* DropListClass::Remove(), 0x004825C0);
DEFINE_IMPLEMENTATION(void DropListClass::Peer_To_Peer(unsigned, KeyNumType&, ControlClass&), 0x00482710);
DEFINE_IMPLEMENTATION(void DropListClass::Clear_Focus(), 0x004826F0);
DEFINE_IMPLEMENTATION(void DropListClass::Set_Position(int, int), 0x00482AF0);
DEFINE_IMPLEMENTATION(int DropListClass::Add_Item(const char*), 0x004825F0);
DEFINE_IMPLEMENTATION(const char* DropListClass::Current_Item(), 0x00482630);
DEFINE_IMPLEMENTATION(int DropListClass::Current_Index(), 0x00482650);
DEFINE_IMPLEMENTATION(void DropListClass::Set_Selected_Index(int), 0x00482670);
DEFINE_IMPLEMENTATION(void DropListClass::Set_Selected_Index(const char*), 0x00482B40);
DEFINE_IMPLEMENTATION(int DropListClass::Count() const, 0x00482BC0);
DEFINE_IMPLEMENTATION(const char* DropListClass::Get_Item(int) const, 0x00482BE0);
DEFINE_IMPLEMENTATION(void DropListClass::Expand(), 0x004827E0);
DEFINE_IMPLEMENTATION(void DropListClass::Collapse(), 0x00482840);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(TextLabelClass::TextLabelClass(const char *, int, int, ColorSchemeType, TextPrintType), 0x0064D0C0);
TextLabelClass::~TextLabelClass() {}
DEFINE_IMPLEMENTATION(bool TextLabelClass::Draw_Me(bool), 0x0064D120);
DEFINE_IMPLEMENTATION(void TextLabelClass::Set_Text(const char*), 0x0064D200);

DEFINE_IMPLEMENTATION(void MultiScore::Presentation(), 0x00568060);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(LaserDrawClass::LaserDrawClass(Coord, Coord, int, bool, RGBClass, RGBClass, RGBClass, int, bool, bool, float, float), 0x004FBC80);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(LaserDrawClass::~LaserDrawClass(), 0x004FBDC0);
DEFINE_IMPLEMENTATION(void LaserDrawClass::Draw_It(), 0x004FC050);
DEFINE_IMPLEMENTATION(void LaserDrawClass::AI(), 0x004FBE90);
DEFINE_IMPLEMENTATION(void LaserDrawClass::Update_All(), 0x004FBF50);
DEFINE_IMPLEMENTATION(void LaserDrawClass::Clear_All(), 0x004FBE10);
DEFINE_IMPLEMENTATION(void LaserDrawClass::Draw_All(), 0x004FC030);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(EMPulseClass::EMPulseClass(Cell, int, int, TechnoClass *), 0x004926B0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(EMPulseClass::EMPulseClass(), 0x00492760);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR_BASE(EMPulseClass::EMPulseClass(const NoInitClass &), AbstractClass, 0x00492790);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(EMPulseClass::~EMPulseClass(), 0x004927B0);
DEFINE_IMPLEMENTATION(void EMPulseClass::Init_Clear(), 0x00492830);
DEFINE_IMPLEMENTATION(void EMPulseClass::Update_All(), 0x00492860);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE EMPulseClass::GetClassID(CLSID*), 0x00493100);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE EMPulseClass::Load(IStream*), 0x00493140);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE EMPulseClass::Save(IStream*, BOOL), 0x00493180);
DEFINE_IMPLEMENTATION(RTTIType EMPulseClass::Fetch_RTTI() const, 0x004931B0);
DEFINE_IMPLEMENTATION(int EMPulseClass::Get_Object_Size(bool) const, 0x004931A0);
DEFINE_IMPLEMENTATION(void EMPulseClass::Object_CRC(CRCEngine&) const, 0x004930B0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(PacketClass::PacketClass(char *), 0x005A22E0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(PacketClass::~PacketClass(), 0x005A22A0);
DEFINE_IMPLEMENTATION(void PacketClass::Add_Field(FieldClass*), 0x005A22D0);
DEFINE_IMPLEMENTATION(FieldClass* PacketClass::Find_Field(char*), 0x005A2510);
DEFINE_IMPLEMENTATION(bool PacketClass::Get_Field(char*, char&), 0x005A2550);
DEFINE_IMPLEMENTATION(bool PacketClass::Get_Field(char*, unsigned char&), 0x005A25A0);
DEFINE_IMPLEMENTATION(bool PacketClass::Get_Field(char*, short&), 0x005A25F0);
DEFINE_IMPLEMENTATION(bool PacketClass::Get_Field(char*, unsigned short&), 0x005A2640);
DEFINE_IMPLEMENTATION(bool PacketClass::Get_Field(char*, long&), 0x005A2690);
DEFINE_IMPLEMENTATION(bool PacketClass::Get_Field(char*, char*), 0x005A26E0);
DEFINE_IMPLEMENTATION(bool PacketClass::Get_Field(char*, unsigned long&), 0x005A2750);
DEFINE_IMPLEMENTATION(bool PacketClass::Get_Field(char*, void*, int&), 0x005A27A0);
DEFINE_IMPLEMENTATION(char* PacketClass::Create_Comms_Packet(int&), 0x005A23F0);

FieldClass::FieldClass() : ID(), DataType(0), Size(0), Data(nullptr), Next(nullptr) {}
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(FieldClass::FieldClass(char *, char), 0x00498890);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(FieldClass::FieldClass(char *, unsigned char), 0x004988F0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(FieldClass::FieldClass(char *, short), 0x00498950);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(FieldClass::FieldClass(char *, unsigned short), 0x004989B0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(FieldClass::FieldClass(char *, long), 0x00498A10);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(FieldClass::FieldClass(char *, unsigned long), 0x00498A70);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(FieldClass::FieldClass(char *, char *), 0x00498AD0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(FieldClass::FieldClass(char *, void *, int), 0x00498B40);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(FieldClass::~FieldClass(), 0x00498BA0);
DEFINE_IMPLEMENTATION(void FieldClass::Host_To_Net(), 0x00498BC0);
DEFINE_IMPLEMENTATION(void FieldClass::Net_To_Host(), 0x00498C30);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(IPXAddressClass::IPXAddressClass(), 0x004EF040);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(IPXAddressClass::IPXAddressClass(NetNumType, NetNodeType), 0x004EF070);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(IPXAddressClass::IPXAddressClass(IPXHeaderType *), 0x004EF0A0);
IPXAddressClass::~IPXAddressClass() {}
DEFINE_IMPLEMENTATION(void IPXAddressClass::Set_Address(NetNumType, NetNodeType), 0x004EF0D0);
DEFINE_IMPLEMENTATION(void IPXAddressClass::Set_Address(IPXHeaderType*), 0x004EF0F0);
DEFINE_IMPLEMENTATION(void IPXAddressClass::Get_Address(NetNumType, NetNodeType) const, 0x004EF150);
DEFINE_IMPLEMENTATION(void IPXAddressClass::Get_Address(IPXHeaderType*) const, 0x004EF170);
DEFINE_IMPLEMENTATION(bool IPXAddressClass::Is_Broadcast() const, 0x004EF190);
DEFINE_IMPLEMENTATION(bool IPXAddressClass::operator==(IPXAddressClass&) const, 0x004EF1D0);
DEFINE_IMPLEMENTATION(bool IPXAddressClass::operator!=(IPXAddressClass&) const, 0x004EF250);
DEFINE_IMPLEMENTATION(bool IPXAddressClass::operator>(IPXAddressClass&) const, 0x004EF2D0);
DEFINE_IMPLEMENTATION(bool IPXAddressClass::operator<(IPXAddressClass&) const, 0x004EF300);
DEFINE_IMPLEMENTATION(bool IPXAddressClass::operator>=(IPXAddressClass&) const, 0x004EF330);
DEFINE_IMPLEMENTATION(bool IPXAddressClass::operator<=(IPXAddressClass&) const, 0x004EF360);
DEFINE_IMPLEMENTATION(const char* IPXAddressClass::As_String() const, 0x004EF390);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(VoxelLibraryClass(), 0x00667E50);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(VoxelLibraryClass(FileClass&), 0x00667E70);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(~VoxelLibraryClass(), 0x00667EB0);
DEFINE_IMPLEMENTATION(void VoxelLibraryClass::Clear(), 0x00667F00);
DEFINE_IMPLEMENTATION(bool VoxelLibraryClass::Read_File(FileClass*, bool), 0x00667F50);
DEFINE_IMPLEMENTATION(VoxelLibraryClass::LayerStruct* VoxelLibraryClass::Get_Layer(int), 0x00668640);
DEFINE_IMPLEMENTATION(VoxelLibraryClass::LayerInfoStruct* VoxelLibraryClass::Get_Layer_Info(int, int), 0x00668650);
DEFINE_IMPLEMENTATION(void VoxelLibraryClass::func_668680(Vector3&, int, int), 0x00668680);
DEFINE_IMPLEMENTATION(int VoxelLibraryClass::Memory_Used(), 0x00668710);
DEFINE_IMPLEMENTATION(void VoxelLibraryClass::func_668730(void*, Vector3&), 0x00668730);
DEFINE_IMPLEMENTATION(void VoxelLibraryClass::func_668A00(void*, Vector3&), 0x00668A00);
DEFINE_IMPLEMENTATION(void VoxelLibraryClass::func_668BA0(), 0x00668BA0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(MotionLibraryClass(), 0x00561C90);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(MotionLibraryClass(FileClass&), 0x00561CA0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(~MotionLibraryClass(), 0x00561CD0);
DEFINE_IMPLEMENTATION(bool MotionLibraryClass::Read_File(FileClass*), 0x00561CF0);
DEFINE_IMPLEMENTATION(void MotionLibraryClass::Scale(float), 0x00561E50);
DEFINE_IMPLEMENTATION(void MotionLibraryClass::Clear(), 0x00561EE0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(VoxelPaletteClass(void*, void*), 0x0066A940);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(~VoxelPaletteClass(), 0x0066A9B0);
DEFINE_IMPLEMENTATION(bool VoxelPaletteClass::Read_Palette_File(FileClass*), 0x0066A9E0);
DEFINE_IMPLEMENTATION(bool VoxelPaletteClass::Read_File(FileClass*), 0x0066AA20);
DEFINE_IMPLEMENTATION(bool VoxelPaletteClass::Write_File(FileClass*), 0x0066AAC0);
DEFINE_IMPLEMENTATION(void VoxelPaletteClass::Calculate_Lookup_Table(float*, int), 0x0066AB60);
DEFINE_IMPLEMENTATION(unsigned char VoxelPaletteClass::Closest_Color(float, float, float) const, 0x0066AE00);
DEFINE_IMPLEMENTATION(unsigned char VoxelPaletteClass::Closest_Color(float, float, float, bool) const, 0x0066AE90);

BrainClass::BrainClass() : Neurons(), field_1C(nullptr), Max(0) {}
// DEFINE_IMPLEMENTATION_DESTRUCTOR(BrainClass::~BrainClass(), 0x00425540);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(NeuronClass::NeuronClass(), 0x004252B0);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(NeuronClass::~NeuronClass(), 0x00425390);
DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE NeuronClass::GetClassID(CLSID*), 0x00425440);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE NeuronClass::Load(IStream*), 0x00425480);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE NeuronClass::Save(IStream*, BOOL), 0x004254F0);
DEFINE_IMPLEMENTATION(RTTIType NeuronClass::Fetch_RTTI() const, 0x004258E0);
DEFINE_IMPLEMENTATION(int NeuronClass::Get_Object_Size(bool) const, 0x004258F0);
DEFINE_IMPLEMENTATION(void NeuronClass::Object_CRC(CRCEngine&) const, 0x00425510);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE AlphaShapeClass::GetClassID(CLSID*), 0x00412950);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE AlphaShapeClass::Load(IStream*), 0x004129F0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE AlphaShapeClass::Save(IStream*, BOOL), 0x00412A40);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(AlphaShapeClass::AlphaShapeClass(), 0x00412720);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(AlphaShapeClass::AlphaShapeClass(AbstractClass *, int, int), 0x004125A0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(AlphaShapeClass::AlphaShapeClass(NoInitClass &), 0x00412880);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(AlphaShapeClass::~AlphaShapeClass(), 0x004128A0);
DEFINE_IMPLEMENTATION(void AlphaShapeClass::Detach(AbstractClass*, bool), 0x00412A70);
DEFINE_IMPLEMENTATION(RTTIType AlphaShapeClass::Fetch_RTTI() const, 0x00412990);
DEFINE_IMPLEMENTATION(int AlphaShapeClass::Get_Object_Size(bool) const, 0x004129A0);
DEFINE_IMPLEMENTATION(void AlphaShapeClass::Object_CRC(CRCEngine&) const, 0x004129B0);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE VeinholeMonsterClass::GetClassID(CLSID*), 0x006636E0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE VeinholeMonsterClass::Save(IStream*, BOOL), 0x00663390);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(VeinholeMonsterClass::VeinholeMonsterClass(Cell), 0x00660C00);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(VeinholeMonsterClass::VeinholeMonsterClass(NoInitClass &), 0x00660A90);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(VeinholeMonsterClass::~VeinholeMonsterClass(), 0x00661000);
DEFINE_IMPLEMENTATION(RTTIType VeinholeMonsterClass::Fetch_RTTI() const, 0x00663720);
DEFINE_IMPLEMENTATION(int VeinholeMonsterClass::Get_Object_Size(bool) const, 0x00663730);
DEFINE_IMPLEMENTATION(void VeinholeMonsterClass::AI(), 0x00661420);
DEFINE_IMPLEMENTATION(LayerType VeinholeMonsterClass::In_Which_Layer() const, 0x00663740);
DEFINE_IMPLEMENTATION(const ObjectTypeClass* VeinholeMonsterClass::Class_Of() const, 0x006633B0);
DEFINE_IMPLEMENTATION(ResultType VeinholeMonsterClass::Take_Damage(int&, int, const WarheadTypeClass*, const ObjectClass*, bool, bool), 0x00661B80);
DEFINE_IMPLEMENTATION(bool VeinholeMonsterClass::Load_All(IStream*), 0x00662F20);
DEFINE_IMPLEMENTATION(bool VeinholeMonsterClass::Save_All(IStream*), 0x00663210);
DEFINE_IMPLEMENTATION(void VeinholeMonsterClass::Init_Clear(), 0x00661D00);
DEFINE_IMPLEMENTATION(void VeinholeMonsterClass::Draw_All(), 0x006619D0);
DEFINE_IMPLEMENTATION(void VeinholeMonsterClass::Update_All(), 0x006613C0);
DEFINE_IMPLEMENTATION(VeinholeMonsterClass* VeinholeMonsterClass::Fetch_At(const Cell&), 0x0000661330);
DEFINE_IMPLEMENTATION(void VeinholeMonsterClass::Place_Veinhole_Monsters(bool), 0x006623F0);

DEFINE_IMPLEMENTATION(LONG STDMETHODCALLTYPE FoggedObjectClass::GetClassID(CLSID*), 0x0049F6D0);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE FoggedObjectClass::Load(IStream*), 0x0049F420);
DEFINE_IMPLEMENTATION(HRESULT STDMETHODCALLTYPE FoggedObjectClass::Save(IStream*, BOOL), 0x0049F3B0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(FoggedObjectClass::FoggedObjectClass(), 0x0049D850);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(FoggedObjectClass::FoggedObjectClass(Coord &, OverlayType, int), 0x0049D910);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(FoggedObjectClass::FoggedObjectClass(Coord &, SmudgeType, int), 0x0049DBB0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(FoggedObjectClass::FoggedObjectClass(const BuildingClass *, bool), 0x0049DE60);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(FoggedObjectClass::FoggedObjectClass(const TerrainClass *), 0x0049E2C0);
// DEFINE_IMPLEMENTATION_CONSTRUCTOR(FoggedObjectClass::FoggedObjectClass(NoInitClass &), 0x0049D810);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(FoggedObjectClass::~FoggedObjectClass(), 0x0049E590);
DEFINE_IMPLEMENTATION(RTTIType FoggedObjectClass::Fetch_RTTI() const, 0x0049F6B0);
DEFINE_IMPLEMENTATION(int FoggedObjectClass::Get_Object_Size(bool) const, 0x0049F6C0);
DEFINE_IMPLEMENTATION(Cell FoggedObjectClass::Get_Cell() const, 0x0049F7D0);
DEFINE_IMPLEMENTATION(Cell* FoggedObjectClass::Get_Occupy_List() const, 0x0049F690);
DEFINE_IMPLEMENTATION(const ObjectTypeClass* FoggedObjectClass::Get_Object() const, 0x0049F7C0);
DEFINE_IMPLEMENTATION(void FoggedObjectClass::Draw_All(), 0x0049E7B0);
DEFINE_IMPLEMENTATION(void FoggedObjectClass::Update_All(), 0x0049F280);

DEFINE_IMPLEMENTATION(bool Need_To_Take(const AircraftClass*), 0x005BF040);
DEFINE_IMPLEMENTATION(bool Do_Reinforcements(const TeamTypeClass*, WAYPOINT), 0x005BF050);
DEFINE_IMPLEMENTATION(bool Pop_Group_Out_Of_Object(FootClass*, TechnoClass*), 0x005BF690);
DEFINE_IMPLEMENTATION(int Create_Tunnel_Reinforcement(const TeamTypeClass*, FootClass*, Cell&, bool), 0x005BF740);
DEFINE_IMPLEMENTATION(bool Create_Special_Reinforcement(HouseClass*, const TechnoTypeClass*, const TechnoTypeClass*, ScriptMissionType, int), 0x005BFD80);
DEFINE_IMPLEMENTATION(int Create_Air_Reinforcement(HouseClass*, AircraftType, int, MissionType, AbstractClass*, AbstractClass*, InfantryType), 0x005BFD90);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(StaticBufferClass::StaticBufferClass(), 0x0060A880);
// DEFINE_IMPLEMENTATION_DESTRUCTOR(StaticBufferClass::~StaticBufferClass(), 0x0060A8A0);
DEFINE_IMPLEMENTATION(DataStruct* StaticBufferClass::Write_To_Surface(BSurface&, AreaStruct&), 0x0060A8B0);
DEFINE_IMPLEMENTATION(DataStruct* StaticBufferClass::Write_To_Surface(BSurface&, Rect&, TPoint2D<unsigned short>), 0x0060A9E0);

// DEFINE_IMPLEMENTATION_CONSTRUCTOR(SaveVersionInfo::SaveVersionInfo(), 0x005D8BE0);
DEFINE_IMPLEMENTATION(void SaveVersionInfo::Set_Version(int), 0x005D8C40);
DEFINE_IMPLEMENTATION(int SaveVersionInfo::Get_Version(), 0x005D8C50);
DEFINE_IMPLEMENTATION(void SaveVersionInfo::Set_Internal_Version(int), 0x005D8C60);
DEFINE_IMPLEMENTATION(int SaveVersionInfo::Get_Internal_Version(), 0x005D8C70);
DEFINE_IMPLEMENTATION(void SaveVersionInfo::Set_Scenario_Description(const char*), 0x005D8C80);
DEFINE_IMPLEMENTATION(const char* SaveVersionInfo::Get_Scenario_Description(), 0x005D8CA0);
DEFINE_IMPLEMENTATION(void SaveVersionInfo::Set_Player_House(const char*), 0x005D8CB0);
DEFINE_IMPLEMENTATION(const char* SaveVersionInfo::Get_Player_House(), 0x005D8CD0);
DEFINE_IMPLEMENTATION(void SaveVersionInfo::Set_Campaign_Number(int), 0x005D8CE0);
DEFINE_IMPLEMENTATION(int SaveVersionInfo::Get_Campaign_Number(), 0x005D8CF0);
DEFINE_IMPLEMENTATION(void SaveVersionInfo::Set_Scenario_Number(int), 0x005D8D00);
DEFINE_IMPLEMENTATION(int SaveVersionInfo::Get_Scenario_Number(), 0x005D8D10);
DEFINE_IMPLEMENTATION(void SaveVersionInfo::Set_Unknown_String(const char*), 0x005D8D20);
DEFINE_IMPLEMENTATION(const char* SaveVersionInfo::Get_Unknown_String(), 0x005D8D50);
DEFINE_IMPLEMENTATION(void SaveVersionInfo::Set_Player_Name(const char*), 0x005D8D60);
DEFINE_IMPLEMENTATION(const char* SaveVersionInfo::Get_Player_Name(), 0x005D8D80);
DEFINE_IMPLEMENTATION(void SaveVersionInfo::Set_Executable_Name(const char*), 0x005D8D90);
DEFINE_IMPLEMENTATION(const char* SaveVersionInfo::Get_Executable_Name(), 0x005D8DC0);
DEFINE_IMPLEMENTATION(void SaveVersionInfo::Set_Start_Time(FILETIME&), 0x005D8DD0);
DEFINE_IMPLEMENTATION(FILETIME SaveVersionInfo::Get_Start_Time(), 0x005D8DF0);
DEFINE_IMPLEMENTATION(void SaveVersionInfo::Set_Play_Time(FILETIME&), 0x005D8E10);
DEFINE_IMPLEMENTATION(FILETIME SaveVersionInfo::Get_Play_Time(), 0x005D8E30);
DEFINE_IMPLEMENTATION(void SaveVersionInfo::Set_Last_Time(FILETIME&), 0x005D8E50);
DEFINE_IMPLEMENTATION(FILETIME SaveVersionInfo::Get_Last_Time(), 0x005D8E70);
DEFINE_IMPLEMENTATION(void SaveVersionInfo::Set_Game_Type(int), 0x005D8E90);
DEFINE_IMPLEMENTATION(int SaveVersionInfo::Get_Game_Type(), 0x005D8EA0);
DEFINE_IMPLEMENTATION(HRESULT SaveVersionInfo::Save(IStorage*), 0x005D8EB0);
DEFINE_IMPLEMENTATION(HRESULT SaveVersionInfo::Load(IStorage*), 0x005D9440);
DEFINE_IMPLEMENTATION(HRESULT SaveVersionInfo::Load_String(IStorage*, int, char*), 0x005D9D90);
DEFINE_IMPLEMENTATION(HRESULT SaveVersionInfo::Load_String_Set(IPropertySetStorage*, int, char*), 0x005D9E80);
DEFINE_IMPLEMENTATION(HRESULT SaveVersionInfo::Load_Int(IStorage*, int, int*), 0x005D9F60);
DEFINE_IMPLEMENTATION(HRESULT SaveVersionInfo::Load_Int_Set(IPropertySetStorage*, int, int*), 0x005DA020);
DEFINE_IMPLEMENTATION(HRESULT SaveVersionInfo::Save_String(IStorage*, int, char*), 0x005DA0F0);
DEFINE_IMPLEMENTATION(HRESULT SaveVersionInfo::Save_String_Set(IPropertySetStorage*, int, const char*), 0x005DA230);
DEFINE_IMPLEMENTATION(HRESULT SaveVersionInfo::Save_Int(IStorage*, int, int), 0x005DA350);
DEFINE_IMPLEMENTATION(HRESULT SaveVersionInfo::Save_Int_Set(IPropertySetStorage*, int, int), 0x005DA440);
DEFINE_IMPLEMENTATION(HRESULT SaveVersionInfo::Load_Time(IStorage*, int, FILETIME*), 0x005DA530);
DEFINE_IMPLEMENTATION(HRESULT SaveVersionInfo::Load_Time_Set(IPropertySetStorage*, int, FILETIME*), 0x005DA5F0);
DEFINE_IMPLEMENTATION(HRESULT SaveVersionInfo::Save_Time(IStorage*, int, FILETIME*), 0x005DA6D0);
DEFINE_IMPLEMENTATION(HRESULT SaveVersionInfo::Save_Time_Set(IPropertySetStorage*, int, FILETIME*), 0x005DA7C0);

DEFINE_IMPLEMENTATION(const WCHAR* Stream_Name_From_ID(int), 0x005DA8C0);
DEFINE_IMPLEMENTATION(bool Get_Savefile_Info(char const*, SaveVersionInfo&), 0x005D7E90);

/**
 *  Ahandle
 */
DEFINE_IMPLEMENTATION(unsigned long __cdecl Timer_Callback_Audio_Handler(VQAHandle*), 0x004072D0);
DEFINE_IMPLEMENTATION(long __cdecl Stream_Audio_Handler(VQAHandle*, long, void*, long), 0x00407450);
DEFINE_IMPLEMENTATION(long __cdecl Open_Audio_Handler(VQAHandleP*, AhandleInitParams*, long), 0x00407650);
DEFINE_IMPLEMENTATION(long __cdecl Close_Audio_Handler(VQAHandleP*), 0x00407980);
DEFINE_IMPLEMENTATION(long __cdecl Start_Audio_Handler(VQAHandleP*), 0x00407B20);
DEFINE_IMPLEMENTATION(long __cdecl Load_Audio_Handler(VQAHandleP*, void*, long), 0x00407D30);
DEFINE_IMPLEMENTATION(long __cdecl Pause_Audio_Handler(VQAHandleP*), 0x00407EF0);
DEFINE_IMPLEMENTATION(long __cdecl Play_Audio_Handler(VQAHandleP*), 0x00407F40);
DEFINE_IMPLEMENTATION(long __cdecl Stop_Audio_Handler(VQAHandleP*), 0x00407FE0);
DEFINE_IMPLEMENTATION(void CALLBACK AudioCallback(UINT, UINT, DWORD, DWORD, DWORD), 0x00408060);
DEFINE_IMPLEMENTATION(unsigned long __cdecl Simple_Timer_Callback_Audio_Handler(VQAHandle*), 0x00408200);
DEFINE_IMPLEMENTATION(void Pause_All_Audio_Handler(), 0x00408210);
DEFINE_IMPLEMENTATION(void Resume_All_Audio_Handler(), 0x00408260);
DEFINE_IMPLEMENTATION(long __cdecl Lock_Audio_Handler(), 0x004082B0);
DEFINE_IMPLEMENTATION(long __cdecl Unlock_Audio_Handler(), 0x004082C0);


/**
 *  GameTimeClass
 */
DEFINE_IMPLEMENTATION(unsigned long GameTimeClass::Get_Time(), 0x004AAC10);
DEFINE_IMPLEMENTATION(unsigned long Get_Game_Time(), 0x004AAC30);
DEFINE_IMPLEMENTATION(unsigned long Get_Game_Time_60Hz(), 0x004AAC50);
GameTimeClass& Game_Time = Make_Global<GameTimeClass>(0x007B340C);


/**
 *  Owner draw
 */
DEFINE_IMPLEMENTATION(void OwnerDraw::Init_Masks(), 0x0059CBC0);
DEFINE_IMPLEMENTATION(void OwnerDraw::Cache_Images(), 0x0059CC40);
DEFINE_IMPLEMENTATION(void OwnerDraw::Initialize(), 0x0058F060);

int& BorderThickness = Make_Global<int>(0x00809218);
int& ColorSteps = Make_Global<int>(0x00809250);
int& ScrollBarAdj = Make_Global<int>(0x00808B6C);
COLORREF& TextColor1 = Make_Global<COLORREF>(0x00808B7C);
COLORREF& TextColor2 = Make_Global<COLORREF>(0x00808B68);
COLORREF& CommonColor1 = Make_Global<COLORREF>(0x00809248);
COLORREF& CommonColor2 = Make_Global<COLORREF>(0x00809244);
COLORREF& ListBoxColor = Make_Global<COLORREF>(0x00809230);
COLORREF& TooltipBoxColor = Make_Global<COLORREF>(0x008093A4);
COLORREF& ColorUnused1 = Make_Global<COLORREF>(0x00808E30);

HFONT& FontPtr1 = Make_Global<HFONT>(0x00808D20);
HFONT& FontPtr2 = Make_Global<HFONT>(0x00809240);
char const*& FontName1 = Make_Global<char const*>(0x007071D0);
char const*& FontName2 = Make_Global<char const*>(0x007071D4);
int& FontSize1 = Make_Global<int>(0x007071D8);
int& FontSize2 = Make_Global<int>(0x007071DC);


/**
 *  CRT
 */
DEFINE_IMPLEMENTATION(void* __cdecl operator_new(unsigned int size), 0x006B51D7);
DEFINE_IMPLEMENTATION(void __cdecl operator_delete(void* ptr), 0x006B51CC);


/**
 *  Various global functions
 */
DEFINE_IMPLEMENTATION(void Call_Back(), 0x00462C60);
DEFINE_IMPLEMENTATION(void Load_Keyboard_Hotkeys(), 0x004E7050);
DEFINE_IMPLEMENTATION(bool VQA_Movie_Message_Loop(), 0x0066B230);
DEFINE_IMPLEMENTATION(bool Parse_Command_Line(int, char*[]), 0x004E3460);
DEFINE_IMPLEMENTATION(int Create_Main_Window(HINSTANCE, int, int, int), 0x00686190);
DEFINE_IMPLEMENTATION(void Prep_Direct_Draw(), 0x00472AD0);
DEFINE_IMPLEMENTATION(bool Set_Video_Mode(HWND, int, int, int), 0x00472DF0);
DEFINE_IMPLEMENTATION(void Reset_Video_Mode(), 0x00472FF0);
DEFINE_IMPLEMENTATION(bool Allocate_Surfaces(Rect*, Rect*, Rect*, Rect*, bool), 0x004E7310);
DEFINE_IMPLEMENTATION(void Free_Heaps(), 0x004E7730);
DEFINE_IMPLEMENTATION(void Wait_Blit(), 0x00473330);
DEFINE_IMPLEMENTATION(void Set_DD_Palette(void*), 0x00473280);
DEFINE_IMPLEMENTATION(LRESULT CALLBACK Main_Window_Procedure(HWND, UINT, WPARAM, LPARAM), 0x00685BC0);
DEFINE_IMPLEMENTATION(bool func_6A83E0(Rect&, const Rect&, Rect&, const Rect&), 0x006A83E0);
DEFINE_IMPLEMENTATION(void Unselect_All(), 0x00463180);
DEFINE_IMPLEMENTATION(const TechnoTypeClass* Fetch_Techno_Type(RTTIType, int), 0x004631B0);
DEFINE_IMPLEMENTATION(bool Prep_For_Side(SideType), 0x004E7EB0);
DEFINE_IMPLEMENTATION(bool Prep_Speech_For_Side(SideType), 0x004E8460);
DEFINE_IMPLEMENTATION(TechnoClass* Best_Selected_Object(), 0x004E8770);
DEFINE_IMPLEMENTATION(void Shake_The_Screen(int), 0x004633B0);
DEFINE_IMPLEMENTATION(long Owner_From_Name(const char*), 0x00463390);
DEFINE_IMPLEMENTATION(bool Main_Loop(), 0x00508A40);
DEFINE_IMPLEMENTATION(void Keyboard_Process(KeyNumType&), 0x005093B0);
DEFINE_IMPLEMENTATION(void Load_Title_Screen(const char*, XSurface*, PaletteClass*), 0x00686340);
DEFINE_IMPLEMENTATION(ThemeType Get_Intro_Theme(), 0x004E86F0);
DEFINE_IMPLEMENTATION(ThemeType Get_Maps_Theme(), 0x004E8730);
DEFINE_IMPLEMENTATION(void Init_Random(), 0x004E38A0);
DEFINE_IMPLEMENTATION(void Init_Campaigns(), 0x004E0C20);
DEFINE_IMPLEMENTATION(bool Init_Game(int, char*[]), 0x004DFB70);
DEFINE_IMPLEMENTATION(bool Init_Network(), 0x00574F90);
DEFINE_IMPLEMENTATION(void Focus_Loss(), 0x00685980);
DEFINE_IMPLEMENTATION(void Focus_Restore(), 0x00685A00);
DEFINE_IMPLEMENTATION(bool Select_Game(bool), 0x004E1DE0);
DEFINE_IMPLEMENTATION(void Init_Theater(TheaterType), 0x004E7B50);
DEFINE_IMPLEMENTATION(Matrix3D Get_Voxel_Draw_Matrix(), 0x00666E30);
DEFINE_IMPLEMENTATION(Matrix3D Get_Voxel_Ramp_Matrix(TileRampType), 0x00667B50);
DEFINE_IMPLEMENTATION(void Voxel_Calc_Normal_To_Pal_Indexes(const Vector3&, int), 0x0066A660);
DEFINE_IMPLEMENTATION(void Voxel_Calc_Normal_To_Pal_Indexes(const Vector3&, const Vector3&, float, int), 0x0066A6E0);
DEFINE_IMPLEMENTATION(int Voxel_Find_Best_Normal_Index(const Vector3&, int), 0x0066A870);
DEFINE_IMPLEMENTATION(void Init_Normal_Lookup(), 0x0066A920);
DEFINE_IMPLEMENTATION(void Set_Voxel_Light_Angle(float theta), 0x004E8AE0);
DEFINE_IMPLEMENTATION(void Init_Voxel_Matrices(), 0x00666E50);
DEFINE_IMPLEMENTATION(void Init_Voxel_Palette(FileClass* file), 0x00665DA0);


DEFINE_IMPLEMENTATION(const char* Name_From_RTTI(RTTIType), 0x00403500);
DEFINE_IMPLEMENTATION(RTTIType RTTI_From_Name(const char*), 0x00403530);

DEFINE_IMPLEMENTATION(bool Clip_Line(Point2D&, Point2D&, const Rect&), 0x006A8870);

DEFINE_IMPLEMENTATION(bool Scale_Rotate(Surface&, BitmapClass&, TPoint2D<int>&, int, unsigned char), 0x005FCEC0);

DEFINE_IMPLEMENTATION(HFONT WinCreateFont(HDC, TCHAR*, int, int, int), 0x006842E0);

DEFINE_IMPLEMENTATION(ArmorType Armor_From_Name(const char*), 0x00681320);

TextFileClass::TextFileClass(const Wstring& filename) : RawFileClass(filename) {}

DEFINE_IMPLEMENTATION(Vector3 operator*(const Matrix3D&, const Vector3&), 0x00555C90);


/**
 *  Various values calculated at runtime init.
 */
Rect& RECT_NONE = Make_Global<Rect>(0x00748138);
Cell& CELL_NONE = Make_Global<Cell>(0x00748158);
Coord& COORD_NONE = Make_Global<Coord>(0x00748178);

double& CELL_LEPTON_DIAG = Make_Global<double>(0x00748160);

double& ISO_TILE_SIZE = Make_Global<double>(0x00748148);
int& ISO_TILE_PIXEL_W = Make_Global<int>(0x00748150);
int& ISO_TILE_PIXEL_H = Make_Global<int>(0x00748154);

int& LEVEL_LEPTON_H = Make_Global<int>(0x007481A0);
int& LEVEL_PIXEL_H = Make_Global<int>(0x00748184);
double& CELL_SLOPE_ANGLE = Make_Global<double>(0x00748170);
double& CELL_DIAG_SLOPE_ANGLE = Make_Global<double>(0x00748188);
int& LEVEL_PIXEL_H_1 = Make_Global<int>(0x00748198);
int& BRIDGE_LEPTON_HEIGHT = Make_Global<int>(0x0074819C);


/**
 *  Global definitions
 */
WWKeyboardClass*& WWKeyboard = Make_Global<WWKeyboardClass*>(0x007482C0);
OptionsClass& Options = Make_Global<OptionsClass>(0x007E4720);
SpecialClass& Special = Make_Global<SpecialClass>(0x007E4548);
RulesClass*& Rule = Make_Global<RulesClass*>(0x0074C488);
WWMouseClass*& WWMouse = Make_Global<WWMouseClass*>(0x0074C8F0);
DSurface*& TileSurface = Make_Global<DSurface*>(0x0074C5CC);
DSurface*& SidebarSurface = Make_Global<DSurface*>(0x0074C5D0);
DSurface*& PrimarySurface = Make_Global<DSurface*>(0x0074C5D8);
DSurface*& HiddenSurface = Make_Global<DSurface*>(0x0074C5DC);
DSurface*& AlternateSurface = Make_Global<DSurface*>(0x0074C5E0);
DSurface*& LogicSurface = Make_Global<DSurface*>(0x0074C5E4);
DSurface*& CompositeSurface = Make_Global<DSurface*>(0x0074C5EC);
Random2Class& NonCriticalRandomNumber = Make_Global<Random2Class>(0x0074BE40);
long& Frame = Make_Global<long>(0x007E4924);
ScenarioClass*& Scen = Make_Global<ScenarioClass*>(0x007E2438);
SessionClass& Session = Make_Global<SessionClass>(0x007E2458);
SwizzleManagerClass& SwizzleManager = Make_Global<SwizzleManagerClass>(0x0080CD50);
ConvertClass*& CameoDrawer = Make_Global<ConvertClass*>(0x007481F0);
ConvertClass*& ObjectDrawer = Make_Global<ConvertClass*>(0x007481F4);
ConvertClass*& OverlayDrawer = Make_Global<ConvertClass*>(0x007481F8);
ConvertClass*& TiberiumDrawer = Make_Global<ConvertClass*>(0x007481FC);
ConvertClass*& AnimDrawer = Make_Global<ConvertClass*>(0x00748200);
ConvertClass*& NormalDrawer = Make_Global<ConvertClass*>(0x00748204);
ConvertClass*& MouseDrawer = Make_Global<ConvertClass*>(0x00748208);
ConvertClass*& SidebarDrawer = Make_Global<ConvertClass*>(0x0074820C);
ToolTipManager*& ToolTipHandler = Make_Global<ToolTipManager*>(0x0074C638);
VersionClass& VerNum = Make_Global<VersionClass>(0x007E4880);
CDControlClass& CDControl = Make_Global<CDControlClass>(0x007608B8);
WWFontClass*& Metal12FontPtr = Make_Global<WWFontClass*>(0x0074821C);
WWFontClass*& MapFontPtr = Make_Global<WWFontClass*>(0x00748228);
WWFontClass*& Font6Ptr = Make_Global<WWFontClass*>(0x00748220);
WWFontClass*& EditorFont = Make_Global<WWFontClass*>(0x00748214);
WWFontClass*& Font8Ptr = Make_Global<WWFontClass*>(0x00748224);
WWFontClass*& GradFont6Ptr = Make_Global<WWFontClass*>(0x00748218);
WinsockInterfaceClass*& PacketTransport = Make_Global<WinsockInterfaceClass*>(0x0074C8D8);
IPXManagerClass& Ipx = Make_Global<IPXManagerClass>(0x007E45A0);
Tactical*& TacticalMap = Make_Global<Tactical*>(0x0074C5F4);
LogicClass& Logic = Make_Global<LogicClass>(0x007482C8);
MouseClass& Map = Make_Global<MouseClass>(0x00748348);
DirectSoundAudioClass& Audio = Make_Global<DirectSoundAudioClass>(0x007A2448);
ThemeClass& Theme = Make_Global<ThemeClass>(0x007E2248);
HWND& MainWindow = Make_Global<HWND>(0x00865040);
HINSTANCE& ProgramInstance = Make_Global<HINSTANCE>(0x0086500C);
int& ShowCommand = Make_Global<int>(0x0086503C);
unsigned& ExceptionReturnBase = Make_Global<unsigned>(0x007B304C);
unsigned& ExceptionReturnStack = Make_Global<unsigned>(0x007B3044);
unsigned& ExceptionReturnAddress = Make_Global<unsigned>(0x007B3048);
bool& CatchExceptions = Make_Global<bool>(0x007E4E94);
bool& Debug_Windowed = Make_Global<bool>(0x007A1790);
bool& Debug_ScenarioFilenameSet = Make_Global<bool>(0x007E48FD);
char* Debug_ScenarioFilename = Make_Pointer<char>(0x007E2360);
bool& Debug_MotionCapture = Make_Global<bool>(0x007E4901);
bool& Debug_AllowModeToggle = Make_Global<bool>(0x007E4902);
bool& Debug_Quiet = Make_Global<bool>(0x007E4903);
bool& Debug_Cheat = Make_Global<bool>(0x007E4904);
bool& Debug_Remap = Make_Global<bool>(0x007E4905);
bool& Debug_Icon = Make_Global<bool>(0x007E4906);
bool& Debug_Flag = Make_Global<bool>(0x007E4907);
bool& Debug_Lose = Make_Global<bool>(0x007E4908);
bool& Debug_Win = Make_Global<bool>(0x007E4909);
bool& Debug_Map = Make_Global<bool>(0x007E490A);
bool& Debug_Passable = Make_Global<bool>(0x007E490B);
bool& Debug_Unshroud = Make_Global<bool>(0x007E490C);
bool& Debug_Threat = Make_Global<bool>(0x007E490D);
bool& Debug_Find_Path = Make_Global<bool>(0x007E490E);
bool& Debug_Check_Map = Make_Global<bool>(0x007E490F);
bool& Debug_Playtest = Make_Global<bool>(0x007E4910);
bool& Debug_Trap_Check_Heap = Make_Global<bool>(0x007E4911);
bool& Debug_Modem_Dump = Make_Global<bool>(0x007E4912);
bool& Debug_Print_Events = Make_Global<bool>(0x007E4913);
HouseClass*& PlayerPtr = Make_Global<HouseClass*>(0x007E2284);
int& SpeechVolume = Make_Global<int>(0x00712618);
bool& IsSpeechAllowed = Make_Global<bool>(0x0071261C);
CDTimerClass<SystemTimerClass>& SpeakTimer = Make_Global<CDTimerClass<SystemTimerClass>>(0x0080FC90);
ARRAY_DEF(0x0080FC9C, void*, SpeechBuffer, 2);
ARRAY_DEF(0x0080FC88, VoxType, SpeechRecord, 2);
ARRAY_DEF(0x00711D14, char const*, Speech, VOX_COUNT);
VoxType& SpeakQueue = Make_Global<VoxType>(0x00712610);
VoxType& CurrentVoice = Make_Global<VoxType>(0x00712614);
Rect& SidebarRect = Make_Global<Rect>(0x0074C240);
Rect& TacticalRect = Make_Global<Rect>(0x0074C250);
Rect& ScreenRect = Make_Global<Rect>(0x0074C260);
unsigned& Seed = Make_Global<unsigned>(0x007E4934);
unsigned& CustomSeed = Make_Global<unsigned>(0x007E4938);
bool& UserInputLocked = Make_Global<bool>(0x007E493C);
int& ScenarioInit = Make_Global<int>(0x007E4394);
bool& AllowVoice = Make_Global<bool>(0x006FB624);
PaletteClass& BlackPalette = Make_Global<PaletteClass>(0x0074A138);
PaletteClass& WaypointPalette = Make_Global<PaletteClass>(0x0074A438);
PaletteClass& CCPalette = Make_Global<PaletteClass>(0x0074A738);
PaletteClass& GamePalette = Make_Global<PaletteClass>(0x0074AA38);
PaletteClass& InGamePalette = Make_Global<PaletteClass>(0x0074AD38);
PaletteClass& WhitePalette = Make_Global<PaletteClass>(0x0074B038);
PaletteClass& OriginalPalette = Make_Global<PaletteClass>(0x0074B338);
PaletteClass& UnitPalette = Make_Global<PaletteClass>(0x0074B638);
PaletteClass& VoxelPalette = Make_Global<PaletteClass>(0x0074B938);
PKey& FastKey = Make_Global<PKey>(0x0074BC38);
CCINIClass*& RuleINI = Make_Global<CCINIClass*>(0x0074C2F0);
CCINIClass& ConfigINI = Make_Global<CCINIClass>(0x0074C378);
CCINIClass& AIINI = Make_Global<CCINIClass>(0x0074C3D8);
CCINIClass& ArtINI = Make_Global<CCINIClass>(0x0074C430);
CCINIClass& FSAIINI = Make_Global<CCINIClass>(0x0074C4A0);
CCINIClass& FSRuleINI = Make_Global<CCINIClass>(0x0074C4F0);
CDTimerClass<SystemTimerClass>& NetFrameTimer = Make_Global<CDTimerClass<SystemTimerClass>>(0x0074C5F8);
TTimerClass<SystemTimerClass>& TickCount = Make_Global<TTimerClass<SystemTimerClass>>(0x0074C608);
CDTimerClass<SystemTimerClass>& FrameTimer = Make_Global<CDTimerClass<SystemTimerClass>>(0x0074C618);
DynamicVectorClass<MFCD*>& ExpandMix = Make_Global<DynamicVectorClass<MFCD*>>(0x0074A098);
DynamicVectorClass<MFCD*>& ExpandSpeechMix = Make_Global<DynamicVectorClass<MFCD*>>(0x0074A0B0);
DynamicVectorClass<MFCD*>& ExpandSideMix = Make_Global<DynamicVectorClass<MFCD*>>(0x0074A0D0);
MFCD*& MultiMix = Make_Global<MFCD*>(0x0074A0C8);
MFCD*& TibSunMix = Make_Global<MFCD*>(0x0074A0E8);
MFCD*& TheaterMix = Make_Global<MFCD*>(0x0074A0EC);
MFCD*& TheaterCachedMix = Make_Global<MFCD*>(0x0074A0F0);
MFCD*& TheaterIsoMix = Make_Global<MFCD*>(0x0074A0F4);
MFCD*& MoviesMix = Make_Global<MFCD*>(0x0074A0F8);
MFCD*& ScoreMix = Make_Global<MFCD*>(0x0074A0FC);
MFCD*& MainMix = Make_Global<MFCD*>(0x0074A100);
MFCD*& ConquerMix = Make_Global<MFCD*>(0x0074A104);
MFCD*& CacheMix = Make_Global<MFCD*>(0x0074A108);
MFCD*& LocalMix = Make_Global<MFCD*>(0x0074A10C);
MFCD*& MapsMix = Make_Global<MFCD*>(0x0074A110);
MFCD*& SpeechMix = Make_Global<MFCD*>(0x0074A114);
MFCD*& SoundsMix = Make_Global<MFCD*>(0x0074A118);
MFCD*& FSSoundsMix = Make_Global<MFCD*>(0x0074A11C);
MFCD*& FSScoresMix = Make_Global<MFCD*>(0x0074A120);
MFCD*& SideCMix = Make_Global<MFCD*>(0x0074A124);
MFCD*& SideNCMix = Make_Global<MFCD*>(0x0074A128);
MFCD*& SideCDMix = Make_Global<MFCD*>(0x0074A12C);
bool& Cheat_Pengo = Make_Global<bool>(0x007E4930);
bool& Cheat_TheTeam = Make_Global<bool>(0x007E4931);
int& NewINIFormat = Make_Global<int>(0x007E491C);
bool& GameInFocus = Make_Global<bool>(0x007E4920);
ParticleSystemClass*& MasterParticle = Make_Global<ParticleSystemClass*>(0x007E4918);
ProgressScreenClass& ProgressScreen = Make_Global<ProgressScreenClass>(0x00809730);
EnvironmentClass& Environment = Make_Global<EnvironmentClass>(0x007A2ED0);
bool& TacticalViewActive = Make_Global<bool>(0x007E48FC);
bool& ScenarioStarted = Make_Global<bool>(0x007E4040);
unsigned& FramesPerSecond = Make_Global<unsigned>(0x00804D2C);
int& RequiredAddon = Make_Global<int>(0x0074C9F8);
bool& GameActive = Make_Global<bool>(0x007E4580);
SpecialDialogType& SpecialDialog = Make_Global<SpecialDialogType>(0x007E4940);
int& BuildLevel = Make_Global<int>(0x006FB628);
SpriteCollectionClass& SpriteCollection = Make_Global<SpriteCollectionClass>(0x00809360);
StaticBufferClass& StaticBuffer = Make_Global<StaticBufferClass>(0x0074C728);
bool& PlayerWins = Make_Global<bool>(0x007E2281);
bool& PlayerLoses = Make_Global<bool>(0x007E4870);
bool& PlayerRestarts = Make_Global<bool>(0x007B3510);
bool& PlayerAborts = Make_Global<bool>(0x007E2280);
int& NewMaxAheadFrame1 = Make_Global<int>(0x007E2400);
int& NewMaxAheadFrame2 = Make_Global<int>(0x007E23E4);
int& VPL_RemapStart = Make_Global<int>(0x0082233C);
int& VPL_RemapEnd = Make_Global<int>(0x00835644);
int& VPL_SectionCount = Make_Global<int>(0x00822320);
int& VPL_field_C = Make_Global<int>(0x00835640);
RGBStruct (&Voxel_Palette)[VOXEL_PALETTE_SIZE] = Make_Global<RGBStruct[VOXEL_PALETTE_SIZE]>(0x00822340);
unsigned char (&Voxel_PaletteLookup)[MAX_PALETTE_LOOKUP_ENTRIES][VOXEL_PALETTE_SIZE] = Make_Global<unsigned char[MAX_PALETTE_LOOKUP_ENTRIES][VOXEL_PALETTE_SIZE]>(0x00833640);
unsigned& GameVersion = Make_Global<unsigned>(0x0070BC58);
float& VoxelLightAngle = Make_Global<float>(0x0074C734);
Vector3& VoxelLightSource = Make_Global<Vector3>(0x0074C738);
Vector3& VoxelShadowLightSource = Make_Global<Vector3>(0x0074C6E8);


/**
 *  Class/namespaced static definitions.
 */
unsigned& DSurface::RedLeft = Make_Global<unsigned>(0x007A2C88);
unsigned& DSurface::RedRight = Make_Global<unsigned>(0x007A2C8C);
unsigned& DSurface::GreenLeft = Make_Global<unsigned>(0x007A2C98);
unsigned& DSurface::GreenRight = Make_Global<unsigned>(0x007A2C9C);
unsigned& DSurface::BlueLeft = Make_Global<unsigned>(0x007A2C90);
unsigned& DSurface::BlueRight = Make_Global<unsigned>(0x007A2C94);
unsigned short& DSurface::ColorGrey = Make_Global<unsigned short>(0x007A2CA0);
unsigned short& DSurface::ColorMidGrey = Make_Global<unsigned short>(0x007A2CA2);
unsigned short& DSurface::ColorDarkGrey = Make_Global<unsigned short>(0x007A2CA4);
int& DSurface::RGBPixelFormat = Make_Global<int>(0x006F9808);
bool& DSurface::AllowStretchBlits = Make_Global<bool>(0x007A2CA6);
bool& DSurface::AllowHardwareBlitFills = Make_Global<bool>(0x006F980C);
GadgetClass*& GScreenClass::Buttons = Make_Global<GadgetClass*>(0x007E4ABC);
GadgetClass*& GadgetClass::StuckOn = Make_Global<GadgetClass*>(0x007B3388);
GadgetClass*& GadgetClass::LastList = Make_Global<GadgetClass*>(0x007B338C);
GadgetClass*& GadgetClass::Focused = Make_Global<GadgetClass*>(0x007B3390);
char*& GadgetClass::GadgetColorScheme = Make_Global<char*>(0x006FB4FC);
DisplayClass::TacticalClass& DisplayClass::TacButton = Make_Global<TacticalClass>(0x007A2268);
ARRAY_DEF(0x007A1FA0, LayerClass, DisplayClass::Layer, LAYER_COUNT);
RadarClass::RTacticalClass& RadarClass::RadarButton = Make_Global<RadarClass::RTacticalClass>(0x00809EB0);
HWND& WinDialogClass::CurrentWindowHandle = Make_Global<HWND>(0x00864E54);
char* CDFileClass::RawPath = Make_Pointer<char>(0x0076092C);
CDFileClass::SearchDriveType*& CDFileClass::First = Make_Global<CDFileClass::SearchDriveType*>(0x00760920);
int& CDFileClass::CurrentCDDrive = Make_Global<int>(0x00760924);
int& CDFileClass::LastCDDrive = Make_Global<int>(0x00760928);
bool& IonStorm_IsActive = Make_Global<bool>(0x007F50E4);
// 007F50E8
int& IonStorm_StaticLoopCounter = Make_Global<int>(0x007F50F0);
int& IonStorm_StartFrame = Make_Global<int>(0x006FF280);
int& IonStorm_Duration = Make_Global<int>(0x006FF284);
ThemeType& IonStorm_RestoreTheme = Make_Global<ThemeType>(0x006FF288);
Cell& RadarEventClass::LastEventCell = Make_Global<Cell>(0x0080A0E8);
bool& CD::IsFilesLocal = Make_Global<bool>(0x007608B0);
DiskID& CD::RequiredCD = Make_Global<DiskID>(0x006F5558);
double& Levitation_Drag = Make_Global<double>(0x007001E8);
double& Levitation_MaxVelocityWhenHappy = Make_Global<double>(0x007001F0);
double& Levitation_MaxVelocityWhenFollowing = Make_Global<double>(0x007001F8);
double& Levitation_MaxVelocityWhenPissedOff = Make_Global<double>(0x00700200);
double& Levitation_AccelerationProbability = Make_Global<double>(0x00700208);
int& Levitation_AccelerationDuration = Make_Global<int>(0x00700210);
double& Levitation_Acceleration = Make_Global<double>(0x00700218);
double& Levitation_InitialBoost = Make_Global<double>(0x00700220);
int& Levitation_MaxBlockCount = Make_Global<int>(0x00700228);
double& Levitation_IntentionalDeacceleration = Make_Global<double>(0x00700230);
double& Levitation_IntentionalDriftVelocity = Make_Global<double>(0x00700238);
double& Levitation_ProximityDistance = Make_Global<double>(0x00700240);
TypeList<VocType>& Levitation_PropulsionSoundEffect = Make_Global<TypeList<VocType>>(0x00804A10);
const void*& AircraftTypeClass::LRotorData = Make_Global<const void*>(0x0074CBDC);
const void*& AircraftTypeClass::RRotorData = Make_Global<const void*>(0x0074CBE0);
ABuffer*& AlphaBuffer = Make_Global<ABuffer*>(0x007474A8);
ZBuffer*& DepthBuffer = Make_Global<ZBuffer*>(0x0074C8F4);
bool& ScoresPresent = Make_Global<bool>(0x007E4818);
int& TeamEvent = Make_Global<int>(0x00804DC8);
int& TeamNumber = Make_Global<int>(0x00804DCC);
HousesType& Whom = Make_Global<HousesType>(0x007E4838);
const ShapeSet*& Cell_ShroudShape = Make_Global<const ShapeSet*>(0x00760CB4);
const ShapeSet*& Cell_FogShape = Make_Global<const ShapeSet*>(0x00760CB0);
const ShapeSet*& Cell_FixupFogShape = Make_Global<const ShapeSet*>(0x00760C88);
MouseClass::MouseStruct* MouseClass::MouseControl = Make_Pointer<MouseStruct>(0x00703070);
ShapeSet const*& MouseClass::MouseShapes = Make_Global<const ShapeSet*>(0x00806CB4);
CDTimerClass<SystemTimerClass>& MouseClass::Timer = Make_Global<CDTimerClass<SystemTimerClass>>(0x00806CC8);
MonoClass*& MonoClass::Current = Make_Global<MonoClass*>(0x00806C50);
bool& MonoClass::Enabled = Make_Global<bool>(0x00806C54);
IsometricTileType& WaterSet = Make_Global<IsometricTileType>(0x007F59A0);
IsometricTileType& WaterfallEast = Make_Global<IsometricTileType>(0x007F59A4);
IsometricTileType& ClearToBlueMoldLAT = Make_Global<IsometricTileType>(0x007F59A8);
IsometricTileType& BridgeTopRight2 = Make_Global<IsometricTileType>(0x007F59B0);
IsometricTileType& HeightBase = Make_Global<IsometricTileType>(0x007F59B4);
IsometricTileType& ClearToGreenLAT = Make_Global<IsometricTileType>(0x007F59B8);
IsometricTileType& GreenTile = Make_Global<IsometricTileType>(0x007F5E0C);
IsometricTileType& RoughGround = Make_Global<IsometricTileType>(0x007F5E10);
IsometricTileType& Medians = Make_Global<IsometricTileType>(0x007F5E14);
IsometricTileType& ClearToSandLAT = Make_Global<IsometricTileType>(0x007F5E18);
IsometricTileType& BridgeSet = Make_Global<IsometricTileType>(0x007F5E1C);
IsometricTileType& BridgeBottomRight2 = Make_Global<IsometricTileType>(0x007F5E28);
IsometricTileType& WaterCliffs = Make_Global<IsometricTileType>(0x007F600C);
IsometricTileType& CliffSet = Make_Global<IsometricTileType>(0x007F6010);
IsometricTileType& MonorailSlopes = Make_Global<IsometricTileType>(0x007F6014);
IsometricTileType& BridgeMiddle2 = Make_Global<IsometricTileType>(0x007F6018);
IsometricTileType& Ice2Set = Make_Global<IsometricTileType>(0x007F601C);
IsometricTileType& WaterfallSouth = Make_Global<IsometricTileType>(0x007F6050);
IsometricTileType& Tunnels = Make_Global<IsometricTileType>(0x007F6054);
IsometricTileType& Ice1Set = Make_Global<IsometricTileType>(0x007F6058);
IsometricTileType& RampSmooth = Make_Global<IsometricTileType>(0x007F6060);
IsometricTileType& WaterToSwampLAT = Make_Global<IsometricTileType>(0x007F6064);
IsometricTileType& SwampTile = Make_Global<IsometricTileType>(0x007F6080);
IsometricTileType& PavedRoadSlopes = Make_Global<IsometricTileType>(0x007F60A8);
IsometricTileType& SlopeSetPieces2 = Make_Global<IsometricTileType>(0x007F60AC);
IsometricTileType& MMRampBase = Make_Global<IsometricTileType>(0x007F60B0);
IsometricTileType& IceShoreSet = Make_Global<IsometricTileType>(0x007F60B4);
IsometricTileType& WaterfallNorth = Make_Global<IsometricTileType>(0x007F60B8);
IsometricTileType& MiscPaveTile = Make_Global<IsometricTileType>(0x007F60BC);
IsometricTileType& ClearToPaveLAT = Make_Global<IsometricTileType>(0x007F60C0);
IsometricTileType& Ice3Set = Make_Global<IsometricTileType>(0x007F60C4);
IsometricTileType& DirtRoadStraight = Make_Global<IsometricTileType>(0x007F60C8);
IsometricTileType& ClearTile = Make_Global<IsometricTileType>(0x007F60CC);
IsometricTileType& ClearToCrystalLAT = Make_Global<IsometricTileType>(0x007F60D0);
IsometricTileType& DirtTunnels = Make_Global<IsometricTileType>(0x007F60D4);
IsometricTileType& BridgeTopLeft2 = Make_Global<IsometricTileType>(0x007F6150);
IsometricTileType& ClearToRoughLAT = Make_Global<IsometricTileType>(0x007F6154);
IsometricTileType& TrainBridgeSet = Make_Global<IsometricTileType>(0x007F6158);
IsometricTileType& BridgeBottomLeft2 = Make_Global<IsometricTileType>(0x007F6568);
IsometricTileType& BridgeTopRight1 = Make_Global<IsometricTileType>(0x007F656C);
IsometricTileType& DirtRoadJunction = Make_Global<IsometricTileType>(0x00803474);
IsometricTileType& BlueMold = Make_Global<IsometricTileType>(0x00803478);
IsometricTileType& WaterCaves = Make_Global<IsometricTileType>(0x0080347C);
IsometricTileType& ShorePieces = Make_Global<IsometricTileType>(0x00803480);
IsometricTileType& DirtTrackTunnels = Make_Global<IsometricTileType>(0x00803484);
IsometricTileType& BridgeMiddle1 = Make_Global<IsometricTileType>(0x00803488);
IsometricTileType& SandTile = Make_Global<IsometricTileType>(0x0080385C);
IsometricTileType& TrackTunnels = Make_Global<IsometricTileType>(0x00803860);
IsometricTileType& Rocks = Make_Global<IsometricTileType>(0x00803864);
IsometricTileType& WaterfallWest = Make_Global<IsometricTileType>(0x0080386C);
IsometricTileType& CliffRamps = Make_Global<IsometricTileType>(0x00804118);
IsometricTileType& DirtRoadSlopes = Make_Global<IsometricTileType>(0x0080411C);
IsometricTileType& PavedRoadEnds = Make_Global<IsometricTileType>(0x00804120);
IsometricTileType& PavedRoads = Make_Global<IsometricTileType>(0x00804124);
IsometricTileType& BridgeBottomLeft1 = Make_Global<IsometricTileType>(0x00804428);
IsometricTileType& CrystalTile = Make_Global<IsometricTileType>(0x0080442C);
IsometricTileType& DirtRoadCurve = Make_Global<IsometricTileType>(0x00804430);
IsometricTileType& RampBase = Make_Global<IsometricTileType>(0x00804434);
IsometricTileType& CrystalCliff = Make_Global<IsometricTileType>(0x00804440);
IsometricTileType& BridgeBottomRight1 = Make_Global<IsometricTileType>(0x00804444);
IsometricTileType& SlopeSetPieces = Make_Global<IsometricTileType>(0x00804450);
IsometricTileType& PaveTile = Make_Global<IsometricTileType>(0x008044F8);
IsometricTileType& BridgeTopLeft1 = Make_Global<IsometricTileType>(0x008044FC);
IsometricTileType& RoughTile = Make_Global<IsometricTileType>(0x00804500);
IsometricTileType& DestroyableCliff = Make_Global<IsometricTileType>(0x00804508);
IsometricTileType& BlackTile = Make_Global<IsometricTileType>(0x0080450C);
bool& RedrawSidebar = Make_Global<bool>(0x0080C3BC);
ShapeButtonClass (&SidebarClass::StripClass::UpButton)[COLUMNS] = Make_Global<ShapeButtonClass[COLUMNS]>(0x0080C250);
ShapeButtonClass (&SidebarClass::StripClass::DownButton)[COLUMNS] = Make_Global<ShapeButtonClass[COLUMNS]>(0x0080B630);
SidebarClass::StripClass::SelectClass (&SidebarClass::StripClass::SelectButton)[COLUMNS][20] = Make_Global<SidebarClass::StripClass::SelectClass[COLUMNS][20]>(0x0080B950);
const ShapeSet*& SidebarClass::StripClass::LogoShape = Make_Global<const ShapeSet*>(0x0080C3B8);
const ShapeSet*& SidebarClass::StripClass::ClockShape = Make_Global<const ShapeSet*>(0x0080C23C);
const ShapeSet*& SidebarClass::StripClass::RechargeClockShape = Make_Global<const ShapeSet*>(0x0080B6D0);
const ShapeSet*& SidebarClass::StripClass::DarkenShape = Make_Global<const ShapeSet*>(0x0080B6D4);
SidebarClass::SBGadgetClass& SidebarClass::Background = Make_Global<SidebarClass::SBGadgetClass>(0x0080C218);
ShapeButtonClass& SidebarClass::Repair = Make_Global<ShapeButtonClass>(0x0080C358);
ShapeButtonClass& SidebarClass::Sell = Make_Global<ShapeButtonClass>(0x0080C1C8);
ShapeButtonClass& SidebarClass::Power = Make_Global<ShapeButtonClass>(0x0080C2F0);
ShapeButtonClass& SidebarClass::Waypoint = Make_Global<ShapeButtonClass>(0x0080C178);
const ShapeSet*& SidebarClass::SidebarShape = Make_Global<const ShapeSet*>(0x0080C3A8);
const ShapeSet*& SidebarClass::SidebarMiddleShape = Make_Global<const ShapeSet*>(0x0080C3AC);
const ShapeSet*& SidebarClass::SidebarBottomShape = Make_Global<const ShapeSet*>(0x0080C3B0);
const ShapeSet*& SidebarClass::SidebarAddonShape = Make_Global<const ShapeSet*>(0x0080C3B4);
const ShapeSet*& BuildingClass::PowerOffShape = Make_Global<const ShapeSet*>(0x00760544);
const ShapeSet*& BuildingClass::WrenchShape = Make_Global<const ShapeSet*>(0x00760548);
const ShapeSet*& ObjectTypeClass::SelectShapes = Make_Global<const ShapeSet*>(0x0080874C);
const ShapeSet*& ObjectTypeClass::PipShapes = Make_Global<const ShapeSet*>(0x00808750);
const ShapeSet*& ObjectTypeClass::Pip2Shapes = Make_Global<const ShapeSet*>(0x00808754);
const ShapeSet*& ObjectTypeClass::TalkBubbleShapes = Make_Global<const ShapeSet*>(0x00808758);
bool& LightSourceClass::UpdateAllowed = Make_Global<bool>(0x00700398);
const ShapeSet*& BuildingTypeClass::BuildingZShape = Make_Global<const ShapeSet*>(0x0076053C);


/**
 *  Global vectors and heaps.
 */
DynamicVectorClass<AbstractTypeClass*>& AbstractTypes = Make_Global<DynamicVectorClass<AbstractTypeClass*>>(0x007E4550);
DynamicVectorClass<ObjectTypeClass*>& ObjectTypes = Make_Global<DynamicVectorClass<ObjectTypeClass*>>(0x008087C0);
DynamicVectorClass<TechnoTypeClass*>& TechnoTypes = Make_Global<DynamicVectorClass<TechnoTypeClass*>>(0x007E46C0);
DynamicVectorClass<BuildingTypeClass*>& BuildingTypes = Make_Global<DynamicVectorClass<BuildingTypeClass*>>(0x007E21A0);
DynamicVectorClass<ConvertClass*>& Converts = Make_Global<DynamicVectorClass<ConvertClass*>>(0x00761120);
DynamicVectorClass<LightConvertClass*>& TileDrawers = Make_Global<DynamicVectorClass<LightConvertClass*>>(0x00761120);
DynamicVectorClass<IsometricTileTypeClass*>& IsoTileTypes = Make_Global<DynamicVectorClass<IsometricTileTypeClass*>>(0x007E48C8);
DynamicVectorClass<HouseTypeClass*>& HouseTypes = Make_Global<DynamicVectorClass<HouseTypeClass*>>(0x007E21D0);
DynamicVectorClass<UnitTypeClass*>& UnitTypes = Make_Global<DynamicVectorClass<UnitTypeClass*>>(0x007E2218);
DynamicVectorClass<InfantryTypeClass*>& InfantryTypes = Make_Global<DynamicVectorClass<InfantryTypeClass*>>(0x007E4010);
DynamicVectorClass<AircraftTypeClass*>& AircraftTypes = Make_Global<DynamicVectorClass<AircraftTypeClass*>>(0x007E2420);
DynamicVectorClass<VoxelAnimTypeClass*>& VoxelAnimTypes = Make_Global<DynamicVectorClass<VoxelAnimTypeClass*>>(0x007E46F0);
DynamicVectorClass<WeaponTypeClass*>& Weapons = Make_Global<DynamicVectorClass<WeaponTypeClass*>>(0x0074C828);
DynamicVectorClass<BulletTypeClass*>& BulletTypes = Make_Global<DynamicVectorClass<BulletTypeClass*>>(0x007E21B8);
DynamicVectorClass<WarheadTypeClass*>& Warheads = Make_Global<DynamicVectorClass<WarheadTypeClass*>>(0x0074C798);
DynamicVectorClass<OverlayTypeClass*>& OverlayTypes = Make_Global<DynamicVectorClass<OverlayTypeClass*>>(0x007E22A0);
DynamicVectorClass<SpotlightClass*>& Spotlights = Make_Global<DynamicVectorClass<SpotlightClass*>>(0x008089A8);
DynamicVectorClass<CommandClass*>& Commands = Make_Global<DynamicVectorClass<CommandClass*>>(0x007481A8);
DynamicVectorClass<VQHandle*>& IngameVQ = Make_Global<DynamicVectorClass<VQHandle*>>(0x00838028);
DynamicVectorClass<SuperClass*>& Supers = Make_Global<DynamicVectorClass<SuperClass*>>(0x007E21F0);
DynamicVectorClass<SuperWeaponTypeClass*>& SuperWeaponTypes = Make_Global<DynamicVectorClass<SuperWeaponTypeClass*>>(0x007E3FF8);
DynamicVectorClass<HouseClass*>& Houses = Make_Global<DynamicVectorClass<HouseClass*>>(0x007E1558);
DynamicVectorClass<SideClass*>& Sides = Make_Global<DynamicVectorClass<SideClass*>>(0x007B3470);
DynamicVectorClass<ScriptClass*>& Scripts = Make_Global<DynamicVectorClass<ScriptClass*>>(0x0074C590);
DynamicVectorClass<ScriptTypeClass*>& ScriptTypes = Make_Global<DynamicVectorClass<ScriptTypeClass*>>(0x007B3518);
DynamicVectorClass<ObjectClass*>& Objects = Make_Global<DynamicVectorClass<ObjectClass*>>(0x007E4028);
DynamicVectorClass<TechnoClass*>& Technos = Make_Global<DynamicVectorClass<TechnoClass*>>(0x007E4820);
DynamicVectorClass<FootClass*>& Foots = Make_Global<DynamicVectorClass<FootClass*>>(0x007B32E0);
DynamicVectorClass<BuildingClass*>& Buildings = Make_Global<DynamicVectorClass<BuildingClass*>>(0x007E4708);
DynamicVectorClass<TeamTypeClass*>& TeamTypes = Make_Global<DynamicVectorClass<TeamTypeClass*>>(0x007E4840);
DynamicVectorClass<TeamClass*>& Teams = Make_Global<DynamicVectorClass<TeamClass*>>(0x007B3438);
DynamicVectorClass<TEventClass*>& TEvents = Make_Global<DynamicVectorClass<TEventClass*>>(0x0080F0E0);
DynamicVectorClass<TActionClass*>& TActions = Make_Global<DynamicVectorClass<TActionClass*>>(0x0080E6E8);
DynamicVectorClass<TaskForceClass*>& TaskForces = Make_Global<DynamicVectorClass<TaskForceClass*>>(0x007E44B8);
DynamicVectorClass<AircraftClass*>& Aircrafts = Make_Global<DynamicVectorClass<AircraftClass*>>(0x007E4058);
DynamicVectorClass<VocClass*>& Vocs = Make_Global<DynamicVectorClass<VocClass*>>(0x0080FC68);
DynamicVectorClass<IonBlastClass*>& IonBlasts = Make_Global<DynamicVectorClass<IonBlastClass*>>(0x007F5750);
DynamicVectorClass<AnimClass*>& Anims = Make_Global<DynamicVectorClass<AnimClass*>>(0x007E4588);
DynamicVectorClass<AnimTypeClass*>& AnimTypes = Make_Global<DynamicVectorClass<AnimTypeClass*>>(0x007B34A0);
DynamicVectorClass<TerrainTypeClass*>& TerrainTypes = Make_Global<DynamicVectorClass<TerrainTypeClass*>>(0x007E3FE0);
DynamicVectorClass<ParticleTypeClass*>& ParticleTypes = Make_Global<DynamicVectorClass<ParticleTypeClass*>>(0x007E22B8);
DynamicVectorClass<ParticleSystemTypeClass*>& ParticleSystemTypes = Make_Global<DynamicVectorClass<ParticleSystemTypeClass*>>(0x007E2288);
DynamicVectorClass<VoxelAnimClass*>& VoxelAnims = Make_Global<DynamicVectorClass<VoxelAnimClass*>>(0x0074C658);
DynamicVectorClass<AITriggerTypeClass*>& AITriggerTypes = Make_Global<DynamicVectorClass<AITriggerTypeClass*>>(0x007E2408);
DynamicVectorClass<TagTypeClass*>& TagTypes = Make_Global<DynamicVectorClass<TagTypeClass*>>(0x0080E800);
DynamicVectorClass<BuildingLightClass*>& BuildingLights = Make_Global<DynamicVectorClass<BuildingLightClass*>>(0x007B34E0);
DynamicVectorClass<LightSourceClass*>& LightSources = Make_Global<DynamicVectorClass<LightSourceClass*>>(0x00804AC0);
DynamicVectorClass<LightSourceClass::PendingCellClass*>& PendingLightCells = Make_Global<DynamicVectorClass<LightSourceClass::PendingCellClass*>>(0x00804AF0);
DynamicVectorClass<SmudgeTypeClass*>& SmudgeTypes = Make_Global<DynamicVectorClass<SmudgeTypeClass*>>(0x007E47C0);
DynamicVectorClass<FactoryClass*>& Factories = Make_Global<DynamicVectorClass<FactoryClass*>>(0x007E2348);
DynamicVectorClass<SmudgeClass*>& Smudges = Make_Global<DynamicVectorClass<SmudgeClass*>>(0x007E23E8);
DynamicVectorClass<OverlayClass*>& Overlays = Make_Global<DynamicVectorClass<OverlayClass*>>(0x007E4800);
DynamicVectorClass<TiberiumClass*>& Tiberiums = Make_Global<DynamicVectorClass<TiberiumClass*>>(0x0080F408);
DynamicVectorClass<BulletClass*>& Bullets = Make_Global<DynamicVectorClass<BulletClass*>>(0x007E48E0);
DynamicVectorClass<UnitClass*>& Units = Make_Global<DynamicVectorClass<UnitClass*>>(0x007B3458);
DynamicVectorClass<TerrainClass*>& Terrains = Make_Global<DynamicVectorClass<TerrainClass*>>(0x007E4568);
DynamicVectorClass<TriggerTypeClass*>& TriggerTypes = Make_Global<DynamicVectorClass<TriggerTypeClass*>>(0x007B34C8);
DynamicVectorClass<TriggerClass*>& Triggers = Make_Global<DynamicVectorClass<TriggerClass*>>(0x007E46A8);
DynamicVectorClass<TagClass*>& Tags = Make_Global<DynamicVectorClass<TagClass*>>(0x0080E7B8);
DynamicVectorClass<WaypointPathClass*>& WaypointPaths = Make_Global<DynamicVectorClass<WaypointPathClass*>>(0x008645F0);
DynamicVectorClass<CampaignClass*>& Campaigns = Make_Global<DynamicVectorClass<CampaignClass*>>(0x007E2230);
DynamicVectorClass<WaveClass*>& Waves = Make_Global<DynamicVectorClass<WaveClass*>>(0x007E47E8);
DynamicVectorClass<ParticleClass*>& Particles = Make_Global<DynamicVectorClass<ParticleClass*>>(0x007E22E0);
DynamicVectorClass<ParticleSystemClass*>& ParticleSystems = Make_Global<DynamicVectorClass<ParticleSystemClass*>>(0x007E1540);
DynamicVectorClass<IsometricTileClass*>& IsoTiles = Make_Global<DynamicVectorClass<IsometricTileClass*>>(0x007482A0);
DynamicVectorClass<RadarEventClass*>& RadarEvents = Make_Global<DynamicVectorClass<RadarEventClass*>>(0x0080A110);
DynamicVectorClass<InfantryClass*>& Infantry = Make_Global<DynamicVectorClass<InfantryClass*>>(0x007E2300);
DynamicVectorClass<TubeClass*>& Tubes = Make_Global<DynamicVectorClass<TubeClass*>>(0x007B3488);
DynamicVectorClass<ColorScheme*>& ColorSchemes = Make_Global<DynamicVectorClass<ColorScheme*>>(0x0080A2C8);
DynamicVectorClass<LaserDrawClass*>& LaserDraws = Make_Global<DynamicVectorClass<LaserDrawClass*>>(0x00804918);
DynamicVectorClass<EMPulseClass*>& Empulses = Make_Global<DynamicVectorClass<EMPulseClass*>>(0x007A2E68);
DynamicVectorClass<AlphaShapeClass*>& AlphaShapes = Make_Global<DynamicVectorClass<AlphaShapeClass*>>(0x0074CCE0);
DynamicVectorClass<FoggedObjectClass*>& FoggedObjects = Make_Global<DynamicVectorClass<FoggedObjectClass*>>(0x007B3238);
DynamicVectorClass<VeinholeMonsterClass*>& VeinholeMonsters = Make_Global<DynamicVectorClass<VeinholeMonsterClass*>>(0x0080FBA8);

MissionControlClass (&MissionControl)[MISSION_COUNT] = Make_Global<MissionControlClass[MISSION_COUNT]>(0x007E4070);

DynamicVectorClass<ObjectClass*>& CurrentObjects = Make_Global<DynamicVectorClass<ObjectClass*>>(0x007E4858);
SelectData (&SelectableObjects)[500] = Make_Global<SelectData[500]>(0x0080CEE8);

DynamicVectorClass<AbstractClass*>& HouseClassTracker = Make_Global<DynamicVectorClass<AbstractClass*>>(0x0080F5E0);
DynamicVectorClass<AbstractClass*>& AnimClassTracker = Make_Global<DynamicVectorClass<AbstractClass*>>(0x0080F4C0);
DynamicVectorClass<AbstractClass*>& AbstractTypeClassTracker = Make_Global<DynamicVectorClass<AbstractClass*>>(0x0080F588);
DynamicVectorClass<AbstractClass*>& FactoryClassTracker = Make_Global<DynamicVectorClass<AbstractClass*>>(0x0080F558);
DynamicVectorClass<AbstractClass*>& TeamClassTracker = Make_Global<DynamicVectorClass<AbstractClass*>>(0x0080F4E0);
DynamicVectorClass<AbstractClass*>& TriggerClassTracker = Make_Global<DynamicVectorClass<AbstractClass*>>(0x0080F620);
DynamicVectorClass<AbstractClass*>& TagClassTracker = Make_Global<DynamicVectorClass<AbstractClass*>>(0x0080F528);
DynamicVectorClass<AbstractClass*>& EventActionTracker = Make_Global<DynamicVectorClass<AbstractClass*>>(0x0080F570);
DynamicVectorClass<AbstractClass*>& WaypointClassTracker = Make_Global<DynamicVectorClass<AbstractClass*>>(0x0080F4F8);
DynamicVectorClass<AbstractClass*>& NeuronClassTracker = Make_Global<DynamicVectorClass<AbstractClass*>>(0x0080F600);

DynamicVectorClass<ULONG>& ClassFactories = Make_Global<DynamicVectorClass<ULONG>>(0x0080C9E0);

DynamicVectorClass<const char*>& Movies = Make_Global<DynamicVectorClass<const char*>>(0x00806DD0);
MovieClass*& CurrentMovie = Make_Global<MovieClass*>(0x00806E1C);

IndexClass<KeyNumType, CommandClass*>& HotkeyIndex = Make_Global<IndexClass<KeyNumType, CommandClass*>>(0x007481C0);
IndexClass<int, const char*>& TutorialText = Make_Global<IndexClass<int, const char*>>(0x007E2440);

QueueClass<EventClass, MAX_EVENTS>& OutList = Make_Global<QueueClass<EventClass, MAX_EVENTS>>(0x007E15F8);
QueueClass<EventClass, (MAX_EVENTS * 64)>& DoList = Make_Global<QueueClass<EventClass, (MAX_EVENTS * 64)>>(0x007B3530);

unsigned long& GameCRC = Make_Global<unsigned long>(0x00809894);
unsigned long& ScenarioCRC = Make_Global<unsigned long>(0x007E4390);
int& IsMono = Make_Global<int>(0x00809E28);

Cell& LastRadarEventCell = Make_Global<Cell>(0x0080A0E8);

const TheaterDataType* Theaters = Make_Pointer<const TheaterDataType>(0x006CA930);

LPDIRECTDRAW& DirectDrawObject = Make_Global<LPDIRECTDRAW>(0x007A1EAC);
LPDIRECTDRAWCLIPPER& DirectDrawClipper = Make_Global<LPDIRECTDRAWCLIPPER>(0x007A2C84);
LPDIRECTDRAWSURFACE& DirectDrawPrimarySurface = Make_Global<LPDIRECTDRAWSURFACE>(0x007A1EB8);

long& LParam = Make_Global<long>(0x007E47D8); // Additional information for RadioClass::Transmit_Message.

int& InstalledMode = Make_Global<int>(0x006F2638);
int& EnabledMode = Make_Global<int>(0x006F263C);

bool& _Select_Game_fade = Make_Global<bool>(0x006F688C);

MonoClass*& ScrollingScreen = Make_Global<MonoClass*>(0x0074A130);

CDTimerClass<FrameTimerClass>& ActionLineTimer = Make_Global<CDTimerClass<FrameTimerClass>>(0x0080EAE8);


/**
 *  Various global definitions, constants and strings.
 */
const Coord AdjacentCoord[FACING_COUNT] = {
    // 0x007611A8
    Coord(0, -256, 0),    // NORTH
    Coord(256, -256, 0),  // NORTH EAST
    Coord(256, 0, 0),     // EAST
    Coord(256, 256, 0),   // SOUTH EAST
    Coord(0, 256, 0),     // SOUTH
    Coord(-256, 256, 0),  // SOUTH WEST
    Coord(-256, 0, 0),    // WEST
    Coord(-256, -256, 0), // NORTH WEST
};

const Cell AdjacentCell[FACING_COUNT] = {
    // 0x00761148
    Cell(0, -1),  // NORTH
    Cell(1, -1),  // NORTH EAST
    Cell(1, 0),   // EAST
    Cell(1, 1),   // SOUTH EAST
    Cell(0, 1),   // SOUTH
    Cell(-1, 1),  // SOUTH WEST
    Cell(-1, 0),  // WEST
    Cell(-1, -1), // NORTH WEST
};

unsigned char const Facing8[256] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3,
                                    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                                    5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

unsigned char const Facing16[256] = {0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  4,  4,  4,
                                     4,  4,  4,  4,  4,  4,  4,  4,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  5,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  6,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  8,  8,  8,  8,  8,  8,  8,  8,
                                     8,  8,  8,  8,  8,  8,  8,  8,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  9,  10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12,
                                     12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 0,  0,  0,  0,  0,  0,  0,  0};

unsigned char const Facing32[256] = {0,  0,  0,  0,  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  3,  4,  4,  4,  4,  4,  4,  5,  5,  5,  5,  5,  5,  5,  6,  6,  6,  6,  6,  6,  6,  7,  7,  7,  7,  7,  7,  7,  8,  8,  8,  8,
                                     8,  8,  8,  9,  9,  9,  9,  9,  9,  9,  10, 10, 10, 10, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 13, 14, 14, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16, 16, 16, 16, 16,
                                     16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 20, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21, 21, 21, 22, 22, 22, 22, 22, 22, 22, 23, 23, 23, 23, 23, 23, 23, 24, 24, 24, 24,
                                     24, 24, 24, 25, 25, 25, 25, 25, 25, 25, 26, 26, 26, 26, 26, 26, 26, 27, 27, 27, 27, 27, 27, 27, 28, 28, 28, 28, 28, 28, 28, 28, 29, 29, 29, 29, 29, 29, 29, 29, 30, 30, 30, 30, 30, 30, 30, 30, 30, 31, 31, 31, 31, 31, 31, 31, 31, 31, 0,  0,  0,  0,  0,  0};


/**
 *  Instances for testing implementations (should be static!).
 */
static TClassFactory<UnitClass> UnitCOMFactory;
static TClassFactory<BuildingClass> BuildingCOMFactory;
static TClassFactory<InfantryClass> InfantryCOMFactory;
static TClassFactory<AircraftClass> AircraftCOMFactory;


/**
 *  Various global arrays.
 */
ARRAY_DEF(0x00838248, short, Wave_SonicBeamSineTable, 500);
ARRAY2D_DEF(0x0083867C, short, Wave_LUT_Pythagoras, 300, 300);
ARRAY_DEF(0x00838638, int, Wave_LUT_Linear1, 14);
ARRAY2D_DEF(0x008381A8, Vector3, Wave_SizeVectors, WAVE_COUNT, 4);

ARRAY_DEF(0x0075F2A0, Cell*, BuildingOccupys, 24);
ARRAY_DEF(0x0075FAE8, Cell*, BuildingExits, 30);

ARRAY_DEF(0x00707AF4, ProgressTextStruct, ProgressText, 8);

ARRAY_DEF(0x00760E90, GroundType, Ground, LAND_COUNT);
ARRAY_DEF(0x006CCC70, const char* const, ActionName, ACTION_COUNT);
ARRAY_DEF(0x006CD148, const char* const, ArmorName, ARMOR_COUNT);
ARRAY_DEF(0x006FD5CC, const char* const, SequenceName, DO_COUNT);

ARRAY_DEF(0x00809A28, unsigned long, CRC, 256);

ARRAY_DEF(0x007A1F24, MonoClass, MonoArray, DMONO_COUNT);

ARRAY_DEF(0x006F9A74, unsigned char, EventLength, EVENT_COUNT);
ARRAY_DEF(0x006F9A98, const char*, EventNames, EVENT_COUNT);

ARRAY2D_DEF(0x0075F2A0, Cell, BuildingOccupyLists, BSIZE_COUNT, 24);
ARRAY2D_DEF(0x0075FAE8, Cell, BuildingExitLists, BSIZE_COUNT, 24);

ARRAY2D_DEF(0x0080ED00, Cell, TerrainOccupyLists, BSIZE_COUNT, 10);

ARRAY_DEF(0x006CD15C, const char*, CrateNames, CRATE_COUNT);
ARRAY_DEF(0x006F6C64, int, CrateShares, CRATE_COUNT);
ARRAY_DEF(0x006F6CB0, AnimType, CrateAnims, CRATE_COUNT);
ARRAY_DEF(0x00761068, int, CrateData, CRATE_COUNT);


/**
 *  WOLAPI globals.
 */
WOL::Tournament& PlanetWestwoodTournament = Make_Global<WOL::Tournament>(0x00867008);
unsigned long& PlanetWestwoodGameID = Make_Global<unsigned long>(0x00867014);
unsigned long& PlanetWestwoodPortNumber = Make_Global<unsigned long>(0x0070FCF0);
unsigned long& PlanetWestwoodStartTime = Make_Global<unsigned long>(0x00866E68);
bool& GameStatisticsPacketSent = Make_Global<bool>(0x007E4FD0);
int& GameSKU = Make_Global<int>(0x00867200);
int& GameFSSKU = Make_Global<int>(0x00866E6C);
FrameSyncStruct (&FrameSyncSettings)[6] = Make_Global<FrameSyncStruct[6]>(0x00707F88);


#ifndef NDEBUG
/**
 *  Swizzle Manager debug globals.
 */
char* SwizzleManagerClass::DebugFile;
char* SwizzleManagerClass::DebugFunction;
int SwizzleManagerClass::DebugLine;
#endif


/**
 *
 *  Manually register the symbols from tspp_defs.asm as we can't add to the vector in assembly.
 *
 *  NOTE: Please update this list if you modify tspp_defs.asm!
 *
 */
REGISTER_ASM_SYMBOL("??0RawFileClass@@QAE@PBD@Z", 0x005BE310);
REGISTER_ASM_SYMBOL("??0MixFileClass@@QAE@PBDPBVPKey@@@Z", 0x00559A10);
REGISTER_ASM_SYMBOL("??0WWKeyboardClass@@QAE@XZ", 0x004FADC0);
REGISTER_ASM_SYMBOL("??0OptionsClass@@QAE@XZ", 0x00589960);
REGISTER_ASM_SYMBOL("??0Buffer@@QAE@PADJ@Z", 0x00425C70);
REGISTER_ASM_SYMBOL("??0Buffer@@QAE@PAXJ@Z", 0x00425C30);
REGISTER_ASM_SYMBOL("??0Buffer@@QAE@PBXJ@Z", 0x00425CB0);
REGISTER_ASM_SYMBOL("??0Buffer@@QAE@J@Z", 0x00425CF0);
REGISTER_ASM_SYMBOL("??0Buffer@@QAE@ABV0@@Z", 0x00425D20);
REGISTER_ASM_SYMBOL("??0RAMFileClass@@QAE@PAXH@Z", 0x005BDB00);
REGISTER_ASM_SYMBOL("??0BufferIOFileClass@@QAE@XZ", 0x00420D30);
REGISTER_ASM_SYMBOL("??0BufferIOFileClass@@QAE@PBD@Z", 0x00420C40);
REGISTER_ASM_SYMBOL("??0CDFileClass@@QAE@XZ", 0x00450610);
REGISTER_ASM_SYMBOL("??0CDFileClass@@QAE@PBD@Z", 0x004505E0);
REGISTER_ASM_SYMBOL("??0Surface@@QAE@HH@Z", 0x0047C1C0);
REGISTER_ASM_SYMBOL("??0CCFileClass@@QAE@XZ", 0x004497F0);
REGISTER_ASM_SYMBOL("??0CCFileClass@@QAE@PBD@Z", 0x004497B0);
REGISTER_ASM_SYMBOL("??0WWMouseClass@@QAE@PAVXSurface@@PAUHWND__@@@Z", 0x006A5000);
REGISTER_ASM_SYMBOL("??0XSurface@@QAE@HH@Z", 0x0047CCA0);
REGISTER_ASM_SYMBOL("??0DSurface@@QAE@XZ", 0x0048AD10);
REGISTER_ASM_SYMBOL("??0DSurface@@QAE@HH_N@Z", 0x0048ABB0);
REGISTER_ASM_SYMBOL("??0DSurface@@QAE@PAUIDirectDrawSurface@@@Z", 0x0048B250);
REGISTER_ASM_SYMBOL("??0AbstractClass@@QAE@XZ", 0x00405B50);
REGISTER_ASM_SYMBOL("??0AbstractClass@@QAE@ABVNoInitClass@@@Z", 0x00405B70);
REGISTER_ASM_SYMBOL("??0RandomClass@@QAE@I@Z", 0x005BDEE0);
REGISTER_ASM_SYMBOL("??0Random2Class@@QAE@I@Z", 0x005BDF80);
REGISTER_ASM_SYMBOL("??0Random3Class@@QAE@II@Z", 0x005BE120);
REGISTER_ASM_SYMBOL("??0MessageListClass@@QAE@XZ", 0x00572E00);
REGISTER_ASM_SYMBOL("??0PaletteClass@@QAE@ABVRGBClass@@@Z", 0x005A2810);
REGISTER_ASM_SYMBOL("??0PaletteClass@@QAE@ABV0@@Z", 0x005A2860);
REGISTER_ASM_SYMBOL("??0VersionClass@@QAE@XZ", 0x00663B30);
REGISTER_ASM_SYMBOL("??0CDControlClass@@QAE@XZ", 0x0044ED90);
REGISTER_ASM_SYMBOL("??0WWFontClass@@QAE@PBX_NH@Z", 0x006A43D0);
REGISTER_ASM_SYMBOL("??0UnitTrackerClass@@QAE@H@Z", 0x0065D5B0);
REGISTER_ASM_SYMBOL("??0LinkClass@@QAE@ABV0@@Z", 0x00503050);
REGISTER_ASM_SYMBOL("??0CounterClass@@QAE@XZ", 0x0046E9F0);
REGISTER_ASM_SYMBOL("??0DropPodLocomotionClass@@QAE@XZ", 0x004830F0);
REGISTER_ASM_SYMBOL("??0Quaternion@@QAE@MMMM@Z", 0x005AFE70);
REGISTER_ASM_SYMBOL("??0Matrix3D@@QAE@ABV0@@Z", 0x005546F0);
REGISTER_ASM_SYMBOL("??0Matrix3D@@QAE@MMMMMMMMMMMM@Z", 0x00554740);
REGISTER_ASM_SYMBOL("??0FuseClass@@QAE@XZ", 0x004A99F0);
REGISTER_ASM_SYMBOL("??0BaseClass@@QAE@XZ", 0x0041F4C0);
REGISTER_ASM_SYMBOL("??0BaseClass@@QAE@ABVNoInitClass@@@Z", 0x0041FF10);
REGISTER_ASM_SYMBOL("??0EventClass@@QAE@HVSpecialClass@@@Z", 0x00493CC0);
REGISTER_ASM_SYMBOL("??0EventClass@@QAE@HW4EventType@@VTargetClass@@@Z", 0x00493D00);
REGISTER_ASM_SYMBOL("??0EventClass@@QAE@HW4EventType@@ABVCell@@@Z", 0x00493D70);
REGISTER_ASM_SYMBOL("??0EventClass@@QAE@HW4EventType@@@Z", 0x00493DE0);
REGISTER_ASM_SYMBOL("??0EventClass@@QAE@HW4EventType@@H@Z", 0x00493E40);
REGISTER_ASM_SYMBOL("??0EventClass@@QAE@HW4EventType@@VTargetClass@@1@Z", 0x00493EB0);
REGISTER_ASM_SYMBOL("??0EventClass@@QAE@HW4AnimType@@W4HousesType@@ABVCoord@@@Z", 0x00493F30);
REGISTER_ASM_SYMBOL("??0EventClass@@QAE@HVTargetClass@@W4MissionType@@00@Z", 0x00493FA0);
REGISTER_ASM_SYMBOL("??0EventClass@@QAE@HVTargetClass@@W4MissionType@@00W4SpeedType@@W4MPHType@@@Z", 0x00494010);
REGISTER_ASM_SYMBOL("??0EventClass@@QAE@HW4EventType@@W4RTTIType@@H@Z", 0x004940A0);
REGISTER_ASM_SYMBOL("??0EventClass@@QAE@HW4EventType@@W4RTTIType@@ABVCell@@@Z", 0x00494110);
REGISTER_ASM_SYMBOL("??0EventClass@@QAE@HW4EventType@@HABVCell@@@Z", 0x00494190);
REGISTER_ASM_SYMBOL("??0EventClass@@QAE@HW4EventType@@PAXK@Z", 0x00494210);
REGISTER_ASM_SYMBOL("??0SpotlightClass@@QAE@VCoord@@H@Z", 0x0058DFD0);
REGISTER_ASM_SYMBOL("??0GScreenClass@@QAE@XZ", 0x004B9370);
REGISTER_ASM_SYMBOL("??0ColorScheme@@QAE@XZ", 0x005E2430);
REGISTER_ASM_SYMBOL("??0ColorScheme@@QAE@PBDPAVHSVClass@@PAVPaletteClass@@2H@Z", 0x005E24F0);
REGISTER_ASM_SYMBOL("??0StorageClass@@QAE@XZ", 0x0060AD60);
REGISTER_ASM_SYMBOL("??0GadgetClass@@QAE@HHHHI_N@Z", 0x004A9BF0);
REGISTER_ASM_SYMBOL("??0GadgetClass@@QAE@ABV0@@Z", 0x004A9C40);
REGISTER_ASM_SYMBOL("??0ControlClass@@QAE@IHHHHI_N@Z", 0x00463A20);
REGISTER_ASM_SYMBOL("??0ControlClass@@QAE@ABV0@@Z", 0x00463A70);
REGISTER_ASM_SYMBOL("??0DisplayClass@@QAE@XZ", 0x00475BA0);
REGISTER_ASM_SYMBOL("??0DisplayClass@@QAE@ABVNoInitClass@@@Z", 0x005F6950);
REGISTER_ASM_SYMBOL("??0CreditClass@@QAE@XZ", 0x00471440);
REGISTER_ASM_SYMBOL("??0PowerClass@@QAE@XZ", 0x005AAFD0);
REGISTER_ASM_SYMBOL("??0SidebarClass@@QAE@XZ", 0x005F2330);
REGISTER_ASM_SYMBOL("??0SidebarClass@@QAE@ABVNoInitClass@@@Z", 0x005F2510);
REGISTER_ASM_SYMBOL("??0StripClass@SidebarClass@@QAE@ABVInitClass@@@Z", 0x005F4180);
REGISTER_ASM_SYMBOL("??0SBGadgetClass@SidebarClass@@QAE@XZ", 0x005F2310);
REGISTER_ASM_SYMBOL("??0TabClass@@QAE@XZ", 0x0060E3F0);
REGISTER_ASM_SYMBOL("??0ScrollClass@@QAE@XZ", 0x005E85A0);
REGISTER_ASM_SYMBOL("??0MouseClass@@QAE@XZ", 0x005621A0);
REGISTER_ASM_SYMBOL("??0MonoClass@@QAE@XZ", 0x00561720);
REGISTER_ASM_SYMBOL("??1MonoClass@@QAE@XZ", 0x00561760);
REGISTER_ASM_SYMBOL("??0DirectSoundAudioClass@@QAE@XZ", 0x00487A20);
REGISTER_ASM_SYMBOL("??0PreviewClass@@QAE@XZ", 0x005AC010);
REGISTER_ASM_SYMBOL("??0VeterancyClass@@QAE@XZ", 0x00664340);
REGISTER_ASM_SYMBOL("??0SuperClass@@QAE@XZ", 0x0060B2C0);
REGISTER_ASM_SYMBOL("??0SuperClass@@QAE@PBVSuperWeaponTypeClass@@PAVHouseClass@@@Z", 0x0060B360);
REGISTER_ASM_SYMBOL("??0DropshipLoadoutClass@@QAE@XZ", 0x00484040);
REGISTER_ASM_SYMBOL("??0HouseStaticClass@HouseClass@@QAE@XZ", 0x004BBC00);
REGISTER_ASM_SYMBOL("??0ThemeControl@ThemeClass@@QAE@XZ", 0x006439B0);
REGISTER_ASM_SYMBOL("??0IPXInterfaceClass@@QAE@XZ", 0x006A02F0);
REGISTER_ASM_SYMBOL("??0SHAEngine@@QAE@XZ", 0x0055A400);
REGISTER_ASM_SYMBOL("??0MissionControlClass@@QAE@XZ", 0x00559550);
REGISTER_ASM_SYMBOL("??0RadioClass@@QAE@XZ", 0x005BD850);
REGISTER_ASM_SYMBOL("??0FacingClass@@QAE@XZ", 0x00496530);
REGISTER_ASM_SYMBOL("??0FacingClass@@QAE@H@Z", 0x00496550);
REGISTER_ASM_SYMBOL("??0DoorClass@@QAE@XZ", 0x00473C70);
REGISTER_ASM_SYMBOL("??0TargetClass@@QAE@PAVAbstractClass@@@Z", 0x0061FEE0);
REGISTER_ASM_SYMBOL("??0TargetClass@@QAE@AAVCell@@@Z", 0x0061FF60);
REGISTER_ASM_SYMBOL("??0TargetClass@@QAE@AAVCoord@@@Z", 0x0061FFB0);
REGISTER_ASM_SYMBOL("??0TEventClass@@QAE@XZ", 0x006420C0);
REGISTER_ASM_SYMBOL("??0TActionClass@@QAE@XZ", 0x00618B80);
REGISTER_ASM_SYMBOL("??0VocClass@@QAE@PBD@Z", 0x00664840);
REGISTER_ASM_SYMBOL("??0IonBlastClass@@QAE@VCoord@@@Z", 0x004EDC20);
REGISTER_ASM_SYMBOL("??0WaypointClass@@QAE@XZ", 0x00673390);
REGISTER_ASM_SYMBOL("??0CStreamClass@@QAE@XZ", 0x004717C0);
REGISTER_ASM_SYMBOL("??0MultiMission@@QAE@AAVINIClass@@PBD@Z", 0x005EF000);
REGISTER_ASM_SYMBOL("??0MultiMission@@QAE@PBD00_N@Z", 0x005EF3C0);
// REGISTER_ASM_SYMBOL("??0Wstring@@QAE@XZ", 0x006A2C10);
// REGISTER_ASM_SYMBOL("??0Wstring@@QAE@PBD@Z", 0x006A2C20);
// REGISTER_ASM_SYMBOL("??0Wstring@@QAE@ABV0@@Z", 0x006A2C70);
REGISTER_ASM_SYMBOL("??0RadarEventClass@@QAE@W4RadarEventType@@VCell@@@Z", 0x005C1CE0);
REGISTER_ASM_SYMBOL("??0TeleportLocomotionClass@@QAE@XZ", 0x0063ECC0);
REGISTER_ASM_SYMBOL("??0WalkLocomotionClass@@QAE@XZ", 0x0066CA60);
REGISTER_ASM_SYMBOL("??0DriveLocomotionClass@@QAE@XZ", 0x0047CF10);
REGISTER_ASM_SYMBOL("??0VQAClass@@QAE@PBDHHHHHH@Z", 0x0066B290);
REGISTER_ASM_SYMBOL("??0ProgressScreenClass@@QAE@XZ", 0x005AD890);
REGISTER_ASM_SYMBOL("??0EnvironmentClass@@QAE@XZ", 0x00493860);
REGISTER_ASM_SYMBOL("??0NewMenuClass@@QAE@XZ", 0x0057FBE0);
REGISTER_ASM_SYMBOL("??0LevitateLocomotionClass@@QAE@XZ", 0x004FDEE0);
REGISTER_ASM_SYMBOL("??0JumpjetLocomotionClass@@QAE@XZ", 0x004F9590);
REGISTER_ASM_SYMBOL("??0ABuffer@@QAE@VRect@@@Z", 0x00406540);
REGISTER_ASM_SYMBOL("??0ZBuffer@@QAE@VRect@@@Z", 0x006A8DD0);
REGISTER_ASM_SYMBOL("??1Pipe@@UAE@XZ", 0x005A9430);
REGISTER_ASM_SYMBOL("??1Straw@@UAE@XZ", 0x0060AFC0);
REGISTER_ASM_SYMBOL("??1RawFileClass@@UAE@XZ", 0x005BE290);
REGISTER_ASM_SYMBOL("??1MixFileClass@@UAE@XZ", 0x00559D40);
REGISTER_ASM_SYMBOL("??1WWKeyboardClass@@QAE@XZ", 0x004FADB0);
REGISTER_ASM_SYMBOL("??1Buffer@@QAE@XZ", 0x00425D80);
REGISTER_ASM_SYMBOL("??1RAMFileClass@@UAE@XZ", 0x005BDB50);
REGISTER_ASM_SYMBOL("??1BufferIOFileClass@@UAE@XZ", 0x00420D90);
REGISTER_ASM_SYMBOL("??1RulesClass@@QAE@XZ", 0x005C59B0);
REGISTER_ASM_SYMBOL("??1CCFileClass@@UAE@XZ", 0x004E8970);
REGISTER_ASM_SYMBOL("??1WWMouseClass@@UAE@XZ", 0x006A5170);
REGISTER_ASM_SYMBOL("??1DSurface@@UAE@XZ", 0x0048ACA0);
REGISTER_ASM_SYMBOL("??1AbstractClass@@UAE@XZ", 0x00405B90);
REGISTER_ASM_SYMBOL("??1AbstractTypeClass@@UAE@XZ", 0x00406330);
REGISTER_ASM_SYMBOL("??1MessageListClass@@QAE@XZ", 0x00572E80);
REGISTER_ASM_SYMBOL("??1SessionClass@@QAE@XZ", 0x005ED1C0);
REGISTER_ASM_SYMBOL("??1INIClass@@UAE@XZ", 0x004DB470);
REGISTER_ASM_SYMBOL("??1ObjectTypeClass@@UAE@XZ", 0x005878B0);
REGISTER_ASM_SYMBOL("??1TechnoTypeClass@@UAE@XZ", 0x0063B5F0);
REGISTER_ASM_SYMBOL("??1SwizzleManagerClass@@QAE@XZ", 0x0060DA00);
REGISTER_ASM_SYMBOL("??1BuildingTypeClass@@UAE@XZ", 0x0043F8F0);
REGISTER_ASM_SYMBOL("??1ConvertClass@@UAE@XZ", 0x00465970);
REGISTER_ASM_SYMBOL("??1IsometricTileTypeClass@@UAE@XZ", 0x004F3330);
REGISTER_ASM_SYMBOL("??1ToolTipManager@@UAE@XZ", 0x00647240);
REGISTER_ASM_SYMBOL("??1CDControlClass@@QAE@XZ", 0x0044EDB0);
REGISTER_ASM_SYMBOL("??1UnitTrackerClass@@QAE@XZ", 0x0065D600);
REGISTER_ASM_SYMBOL("??1LinkClass@@UAE@XZ", 0x00503090);
REGISTER_ASM_SYMBOL("??1CounterClass@@UAE@XZ", 0x0046EA10);
REGISTER_ASM_SYMBOL("??1HouseTypeClass@@UAE@XZ", 0x004CDE80);
REGISTER_ASM_SYMBOL("??1UnitTypeClass@@UAE@XZ", 0x0065BAC0);
REGISTER_ASM_SYMBOL("??1InfantryTypeClass@@UAE@XZ", 0x004DA3A0);
REGISTER_ASM_SYMBOL("??1AircraftTypeClass@@UAE@XZ", 0x0040FCC0);
REGISTER_ASM_SYMBOL("??1VoxelAnimTypeClass@@UAE@XZ", 0x0065F590);
REGISTER_ASM_SYMBOL("??1WeaponTypeClass@@UAE@XZ", 0x00680C40);
REGISTER_ASM_SYMBOL("??1BulletTypeClass@@UAE@XZ", 0x00447DB0);
REGISTER_ASM_SYMBOL("??1WinsockInterfaceClass@@UAE@XZ", 0x006A0F60);
REGISTER_ASM_SYMBOL("??1IPXManagerClass@@UAE@XZ", 0x004F0410);
REGISTER_ASM_SYMBOL("??1ConnectionClass@@UAE@XZ", 0x00461D80);
REGISTER_ASM_SYMBOL("??1CommBufferClass@@UAE@XZ", 0x00460CD0);
REGISTER_ASM_SYMBOL("??1DropPodLocomotionClass@@UAE@XZ", 0x00483140);
REGISTER_ASM_SYMBOL("??1CellClass@@UAE@XZ", 0x00451750);
REGISTER_ASM_SYMBOL("??1WarheadTypeClass@@UAE@XZ", 0x0066EF60);
REGISTER_ASM_SYMBOL("??1Tactical@@UAE@XZ", 0x0060F0D0);
REGISTER_ASM_SYMBOL("??1OverlayTypeClass@@UAE@XZ", 0x0058D160);
REGISTER_ASM_SYMBOL("??1SpotlightClass@@QAE@XZ", 0x0058E050);
REGISTER_ASM_SYMBOL("??1ColorScheme@@QAE@XZ", 0x005E26C0);
REGISTER_ASM_SYMBOL("??1MapClass@@UAE@XZ", 0x0050ED30);
REGISTER_ASM_SYMBOL("??1LCWPipe@@UAE@XZ", 0x004FD420);
REGISTER_ASM_SYMBOL("??1LCWStraw@@UAE@XZ", 0x004FD810);
REGISTER_ASM_SYMBOL("??1LZOPipe@@UAE@XZ", 0x00507E50);
REGISTER_ASM_SYMBOL("??1LZOStraw@@UAE@XZ", 0x005082C0);
REGISTER_ASM_SYMBOL("??1GadgetClass@@UAE@XZ", 0x004A9C90);
REGISTER_ASM_SYMBOL("??1RadarClass@@UAE@XZ", 0x005B8AC0);
REGISTER_ASM_SYMBOL("??1DirectSoundAudioClass@@QAE@XZ", 0x00487B20);
REGISTER_ASM_SYMBOL("??1PreviewClass@@QAE@XZ", 0x005AC020);
REGISTER_ASM_SYMBOL("??1VeterancyClass@@QAE@XZ", 0x00664350);
REGISTER_ASM_SYMBOL("??1SuperClass@@UAE@XZ", 0x0060B4C0);
REGISTER_ASM_SYMBOL("??1SuperWeaponTypeClass@@UAE@XZ", 0x0060D090);
REGISTER_ASM_SYMBOL("??1ConnectionPointClass@@QAE@XZ", 0x0046F920);
REGISTER_ASM_SYMBOL("??1EnumConnectionsClass@@QAE@XZ", 0x0046F4A0);
REGISTER_ASM_SYMBOL("??1EnumConnectionPointsClass@@QAE@XZ", 0x0046FE00);
REGISTER_ASM_SYMBOL("??1DropshipLoadoutClass@@QAE@XZ", 0x00484060);
REGISTER_ASM_SYMBOL("??1HouseClass@@UAE@XZ", 0x004BB6B0);
REGISTER_ASM_SYMBOL("??1UDPInterfaceClass@@UAE@XZ", 0x006A1EF0);
REGISTER_ASM_SYMBOL("??1LoadOptionsClass@@UAE@XZ", 0x00504800);
REGISTER_ASM_SYMBOL("??1SideClass@@UAE@XZ", 0x005F1AD0);
REGISTER_ASM_SYMBOL("??1ScriptClass@@UAE@XZ", 0x005E7820);
REGISTER_ASM_SYMBOL("??1ScriptTypeClass@@UAE@XZ", 0x005E7B70);
REGISTER_ASM_SYMBOL("??1ObjectClass@@UAE@XZ", 0x005849C0);
REGISTER_ASM_SYMBOL("??1TechnoClass@@UAE@XZ", 0x0062A8E0);
REGISTER_ASM_SYMBOL("??1FootClass@@UAE@XZ", 0x004A03D0);
REGISTER_ASM_SYMBOL("??1BuildingClass@@UAE@XZ", 0x00426620);
REGISTER_ASM_SYMBOL("??1TeamTypeClass@@UAE@XZ", 0x00627EE0);
REGISTER_ASM_SYMBOL("??1TeamClass@@UAE@XZ", 0x00622420);
REGISTER_ASM_SYMBOL("??1TEventClass@@UAE@XZ", 0x00642210);
REGISTER_ASM_SYMBOL("??1TActionClass@@UAE@XZ", 0x00618CF0);
REGISTER_ASM_SYMBOL("??1TaskForceClass@@UAE@XZ", 0x006214F0);
REGISTER_ASM_SYMBOL("??1AircraftClass@@UAE@XZ", 0x0040DB20);
REGISTER_ASM_SYMBOL("??1InfantryClass@@UAE@XZ", 0x004D2240);
REGISTER_ASM_SYMBOL("??1VocClass@@QAE@XZ", 0x00664920);
REGISTER_ASM_SYMBOL("??1IonBlastClass@@QAE@XZ", 0x004EDCA0);
REGISTER_ASM_SYMBOL("??1AnimClass@@UAE@XZ", 0x004142B0);
REGISTER_ASM_SYMBOL("??1AnimTypeClass@@UAE@XZ", 0x004187C0);
REGISTER_ASM_SYMBOL("??1TerrainTypeClass@@UAE@XZ", 0x00641640);
REGISTER_ASM_SYMBOL("??1ParticleTypeClass@@UAE@XZ", 0x005AF140);
REGISTER_ASM_SYMBOL("??1ParticleSystemTypeClass@@UAE@XZ", 0x005AE560);
REGISTER_ASM_SYMBOL("??1VoxelAnimClass@@UAE@XZ", 0x0065DF10);
REGISTER_ASM_SYMBOL("??1AITriggerTypeClass@@UAE@XZ", 0x004105F0);
REGISTER_ASM_SYMBOL("??1TagTypeClass@@UAE@XZ", 0x0061F150);
REGISTER_ASM_SYMBOL("??1BuildingLightClass@@UAE@XZ", 0x00421D70);
REGISTER_ASM_SYMBOL("??1LightSourceClass@@UAE@XZ", 0x005015B0);
REGISTER_ASM_SYMBOL("??1SmudgeTypeClass@@UAE@XZ", 0x005FB300);
REGISTER_ASM_SYMBOL("??1FactoryClass@@UAE@XZ", 0x00496DA0);
REGISTER_ASM_SYMBOL("??1SmudgeClass@@UAE@XZ", 0x005FAAC0);
REGISTER_ASM_SYMBOL("??1OverlayClass@@UAE@XZ", 0x0058B550);
REGISTER_ASM_SYMBOL("??1TiberiumClass@@UAE@XZ", 0x00644A30);
REGISTER_ASM_SYMBOL("??1BulletClass@@UAE@XZ", 0x004445E0);
REGISTER_ASM_SYMBOL("??1UnitClass@@UAE@XZ", 0x0064D7C0);
REGISTER_ASM_SYMBOL("??1TerrainClass@@UAE@XZ", 0x0063F170);
REGISTER_ASM_SYMBOL("??1TriggerTypeClass@@UAE@XZ", 0x00649DF0);
REGISTER_ASM_SYMBOL("??1TriggerClass@@UAE@XZ", 0x00649190);
REGISTER_ASM_SYMBOL("??1TagClass@@UAE@XZ", 0x0061E4A0);
REGISTER_ASM_SYMBOL("??1WaypointPathClass@@UAE@XZ", 0x00673550);
REGISTER_ASM_SYMBOL("??1WaypointClass@@QAE@XZ", 0x006733C0);
REGISTER_ASM_SYMBOL("??1CampaignClass@@UAE@XZ", 0x00448AD0);
REGISTER_ASM_SYMBOL("??1WaveClass@@UAE@XZ", 0x006702C0);
REGISTER_ASM_SYMBOL("??1CStreamClass@@UAE@XZ", 0x00471820);
REGISTER_ASM_SYMBOL("??1ParticleClass@@UAE@XZ", 0x005A32E0);
REGISTER_ASM_SYMBOL("??1ParticleSystemClass@@UAE@XZ", 0x005A56C0);
// REGISTER_ASM_SYMBOL("??1Wstring@@QAE@XZ", 0x006A2CD0);
REGISTER_ASM_SYMBOL("??1IsometricTileClass@@UAE@XZ", 0x004F2160);
REGISTER_ASM_SYMBOL("??1RadarEventClass@@QAE@XZ", 0x005C1E40);
REGISTER_ASM_SYMBOL("??1WalkLocomotionClass@@UAE@XZ", 0x0066CAD0);
REGISTER_ASM_SYMBOL("??1DriveLocomotionClass@@UAE@XZ", 0x0047CFB0);
REGISTER_ASM_SYMBOL("??1VQAClass@@QAE@XZ", 0x0066B540);
REGISTER_ASM_SYMBOL("??1ProgressScreenClass@@QAE@XZ", 0x005AD8C0);
REGISTER_ASM_SYMBOL("??1EnvironmentClass@@QAE@XZ", 0x00493890);
REGISTER_ASM_SYMBOL("??1TubeClass@@UAE@XZ", 0x0064AFC0);
REGISTER_ASM_SYMBOL("??1LevitateLocomotionClass@@UAE@XZ", 0x004FDF60);
REGISTER_ASM_SYMBOL("??1JumpjetLocomotionClass@@UAE@XZ", 0x004F9600);
REGISTER_ASM_SYMBOL("??1ABuffer@@QAE@XZ", 0x004066B0);
REGISTER_ASM_SYMBOL("??1ZBuffer@@QAE@XZ", 0x006A8F40);
REGISTER_ASM_SYMBOL("??1StaticButtonClass@@UAE@XZ", 0x00608F30);
REGISTER_ASM_SYMBOL("??1SliderClass@@UAE@XZ", 0x005F7C90);
REGISTER_ASM_SYMBOL("??1ListClass@@UAE@XZ", 0x00503650);
REGISTER_ASM_SYMBOL("??1ColorListClass@@UAE@XZ", 0x0045E110);
REGISTER_ASM_SYMBOL("??1CheckListClass@@UAE@XZ", 0x0045DBE0);
REGISTER_ASM_SYMBOL("??1EditClass@@UAE@XZ", 0x00490380);
REGISTER_ASM_SYMBOL("??1LaserDrawClass@@QAE@XZ", 0x004FBDC0);
REGISTER_ASM_SYMBOL("??0AbstractTypeClass@@QAE@PBD@Z", 0x004061D0);
REGISTER_ASM_SYMBOL("??0AbstractTypeClass@@QAE@ABVNoInitClass@@@Z", 0x00406310);
REGISTER_ASM_SYMBOL("??0SideClass@@QAE@PBD@Z", 0x005F1A30);
// REGISTER_ASM_SYMBOL("??0ScriptClass@@QAE@PAVScriptTypeClass@@@Z", 0x005F1A30);
REGISTER_ASM_SYMBOL("??0ScriptTypeClass@@QAE@PBD@Z", 0x005E7AC0);
REGISTER_ASM_SYMBOL("??0ObjectTypeClass@@QAE@PBD@Z", 0x00587620);
REGISTER_ASM_SYMBOL("??0ObjectTypeClass@@QAE@ABVNoInitClass@@@Z", 0x00587810);
REGISTER_ASM_SYMBOL("??0TechnoTypeClass@@QAE@PBDW4SpeedType@@@Z", 0x0063ADE0);
REGISTER_ASM_SYMBOL("??0TechnoTypeClass@@QAE@ABVNoInitClass@@@Z", 0x0063B480);
REGISTER_ASM_SYMBOL("??0BuildingTypeClass@@QAE@PBD@Z", 0x0043F410);
REGISTER_ASM_SYMBOL("??0BuildingTypeClass@@QAE@ABVNoInitClass@@@Z", 0x0043F8C0);
REGISTER_ASM_SYMBOL("??0ConvertClass@@QAE@PAVPaletteClass@@0PAVXSurface@@H_N@Z", 0x00463C40);
REGISTER_ASM_SYMBOL("??0LightConvertClass@@QAE@PAVPaletteClass@@0PAVSurface@@HHH_NPA_NH@Z", 0x00502A00);
REGISTER_ASM_SYMBOL("??0IsometricTileTypeClass@@QAE@W4IsometricTileType@@DDPBD_N@Z", 0x004F30A0);
REGISTER_ASM_SYMBOL("??0IsometricTileTypeClass@@QAE@ABVNoInitClass@@@Z", 0x004F32D0);
REGISTER_ASM_SYMBOL("??0HouseTypeClass@@QAE@PBD@Z", 0x004CDD10);
REGISTER_ASM_SYMBOL("??0HouseTypeClass@@QAE@ABVNoInitClass@@@Z", 0x004CDE60);
REGISTER_ASM_SYMBOL("??0UnitTypeClass@@QAE@PBD@Z", 0x0065B8F0);
REGISTER_ASM_SYMBOL("??0UnitTypeClass@@QAE@ABVNoInitClass@@@Z", 0x0065BAA0);
REGISTER_ASM_SYMBOL("??0InfantryTypeClass@@QAE@PBD@Z", 0x004DA1E0);
REGISTER_ASM_SYMBOL("??0InfantryTypeClass@@QAE@ABVNoInitClass@@@Z", 0x004DA370);
REGISTER_ASM_SYMBOL("??0AircraftTypeClass@@QAE@PBD@Z", 0x0040FBC0);
REGISTER_ASM_SYMBOL("??0AircraftTypeClass@@QAE@ABVNoInitClass@@@Z", 0x0040FCA0);
REGISTER_ASM_SYMBOL("??0VoxelAnimTypeClass@@QAE@PBD@Z", 0x0065F3B0);
REGISTER_ASM_SYMBOL("??0WeaponTypeClass@@QAE@PBD@Z", 0x00680A60);
REGISTER_ASM_SYMBOL("??0WeaponTypeClass@@QAE@ABVNoInitClass@@@Z", 0x00680C00);
REGISTER_ASM_SYMBOL("??0BulletTypeClass@@QAE@PBD@Z", 0x00447BC0);
REGISTER_ASM_SYMBOL("??0BulletTypeClass@@QAE@ABVNoInitClass@@@Z", 0x00447D90);
REGISTER_ASM_SYMBOL("??0CellClass@@QAE@XZ", 0x004517C0);
REGISTER_ASM_SYMBOL("??0CellClass@@QAE@ABVNoInitClass@@@Z", 0x00450F60);
REGISTER_ASM_SYMBOL("??0WarheadTypeClass@@QAE@PBD@Z", 0x0066ED40);
REGISTER_ASM_SYMBOL("??0WarheadTypeClass@@QAE@ABVNoInitClass@@@Z", 0x0066EF00);
REGISTER_ASM_SYMBOL("??0Tactical@@QAE@XZ", 0x0060EEC0);
REGISTER_ASM_SYMBOL("??0Tactical@@QAE@ABVNoInitClass@@@Z", 0x0060F090);
REGISTER_ASM_SYMBOL("??0OverlayTypeClass@@QAE@PBD@Z", 0x0058CFF0);
REGISTER_ASM_SYMBOL("??0OverlayTypeClass@@QAE@ABVNoInitClass@@@Z", 0x0058D140);
REGISTER_ASM_SYMBOL("??0SuperWeaponTypeClass@@QAE@PBD@Z", 0x0060CF70);
REGISTER_ASM_SYMBOL("??0SuperWeaponTypeClass@@QAE@ABVNoInitClass@@@Z", 0x0060D060);
REGISTER_ASM_SYMBOL("??0HouseClass@@QAE@PBVHouseTypeClass@@@Z", 0x004BA0B0);
REGISTER_ASM_SYMBOL("??0HouseClass@@QAE@ABVNoInitClass@@@Z", 0x004B9EF0);
REGISTER_ASM_SYMBOL("??0ObjectClass@@QAE@XZ", 0x005847D0);
REGISTER_ASM_SYMBOL("??0ObjectClass@@QAE@ABVNoInitClass@@@Z", 0x005849A0);
REGISTER_ASM_SYMBOL("??0MissionClass@@QAE@XZ", 0x00558E40);
REGISTER_ASM_SYMBOL("??0MissionClass@@QAE@ABVNoInitClass@@@Z", 0x0063A600);
REGISTER_ASM_SYMBOL("??0TechnoClass@@QAE@PAVHouseClass@@@Z", 0x00629CB0);
REGISTER_ASM_SYMBOL("??0TechnoClass@@QAE@ABVNoInitClass@@@Z", 0x0062A7F0);
REGISTER_ASM_SYMBOL("??0FootClass@@QAE@PAVHouseClass@@@Z", 0x004A00F0);
REGISTER_ASM_SYMBOL("??0FootClass@@QAE@ABVNoInitClass@@@Z", 0x004A0390);
REGISTER_ASM_SYMBOL("??0BuildingClass@@QAE@PAVBuildingTypeClass@@PAVHouseClass@@@Z", 0x00426190);
REGISTER_ASM_SYMBOL("??0BuildingClass@@QAE@AAVNoInitClass@@@Z", 0x00426140);
REGISTER_ASM_SYMBOL("??0TeamTypeClass@@QAE@PBD@Z", 0x00627D90);
REGISTER_ASM_SYMBOL("??0TeamClass@@QAE@PBVTeamTypeClass@@PAVHouseClass@@PAX@Z", 0x00622100);
REGISTER_ASM_SYMBOL("??0TaskForceClass@@QAE@PBD@Z", 0x00621420);
REGISTER_ASM_SYMBOL("??0TaskForceClass@@QAE@ABVNoInitClass@@@Z", 0x006214D0);
REGISTER_ASM_SYMBOL("??0AircraftClass@@QAE@PAVAircraftTypeClass@@PAVHouseClass@@@Z", 0x004085D0);
REGISTER_ASM_SYMBOL("??0InfantryClass@@QAE@PAVInfantryTypeClass@@PAVHouseClass@@@Z", 0x004D1FD0);
REGISTER_ASM_SYMBOL("??0AnimClass@@QAE@XZ", 0x00414170);
REGISTER_ASM_SYMBOL("??0AnimClass@@QAE@PBVAnimTypeClass@@ABVCoord@@IIIH@Z", 0x00413AE0);
REGISTER_ASM_SYMBOL("??0AnimTypeClass@@QAE@PBD@Z", 0x004184C0);
REGISTER_ASM_SYMBOL("??0AnimTypeClass@@QAE@ABVNoInitClass@@@Z", 0x004187A0);
REGISTER_ASM_SYMBOL("??0TerrainTypeClass@@QAE@PBD@Z", 0x006414E0);
REGISTER_ASM_SYMBOL("??0TerrainTypeClass@@QAE@ABVNoInitClass@@@Z", 0x00641620);
REGISTER_ASM_SYMBOL("??0ParticleTypeClass@@QAE@PBD@Z", 0x005AEF00);
REGISTER_ASM_SYMBOL("??0ParticleTypeClass@@QAE@ABVNoInitClass@@@Z", 0x005AF0E0);
REGISTER_ASM_SYMBOL("??0ParticleSystemTypeClass@@QAE@PBD@Z", 0x005AE3D0);
REGISTER_ASM_SYMBOL("??0ParticleSystemTypeClass@@QAE@ABVNoInitClass@@@Z", 0x005AE540);
REGISTER_ASM_SYMBOL("??0VoxelAnimClass@@QAE@XZ", 0x0065DE30);
REGISTER_ASM_SYMBOL("??0VoxelAnimClass@@QAE@PBVVoxelAnimTypeClass@@ABVCoord@@PAVHouseClass@@@Z", 0x0065D950);
REGISTER_ASM_SYMBOL("??0AITriggerTypeClass@@QAE@PBD@Z", 0x004104E0);
REGISTER_ASM_SYMBOL("??0TagTypeClass@@QAE@PBD@Z", 0x0061F030);
REGISTER_ASM_SYMBOL("??0BuildingLightClass@@QAE@PAVTechnoClass@@@Z", 0x00421AE0);
REGISTER_ASM_SYMBOL("??0LightSourceClass@@QAE@XZ", 0x00501510);
REGISTER_ASM_SYMBOL("??0LightSourceClass@@QAE@VCoord@@HHHHH@Z", 0x00501460);
REGISTER_ASM_SYMBOL("??0SmudgeTypeClass@@QAE@PBD@Z", 0x005FB1E0);
REGISTER_ASM_SYMBOL("??0SmudgeTypeClass@@QAE@ABVNoInitClass@@@Z", 0x005FB2E0);
REGISTER_ASM_SYMBOL("??0FactoryClass@@QAE@XZ", 0x00496C60);
REGISTER_ASM_SYMBOL("??0SmudgeClass@@QAE@PAVSmudgeTypeClass@@AAVCoord@@W4HousesType@@@Z", 0x005FA9E0);
REGISTER_ASM_SYMBOL("??0OverlayClass@@QAE@PAVOverlayTypeClass@@AAVCell@@W4HousesType@@@Z", 0x0058B460);
REGISTER_ASM_SYMBOL("??0TiberiumClass@@QAE@PBD@Z", 0x00644890);
REGISTER_ASM_SYMBOL("??0BulletClass@@QAE@XZ", 0x004444A0);
REGISTER_ASM_SYMBOL("??0UnitClass@@QAE@PAVUnitTypeClass@@PAVHouseClass@@@Z", 0x0064D4B0);
REGISTER_ASM_SYMBOL("??0TerrainClass@@QAE@XZ", 0x0063F710);
REGISTER_ASM_SYMBOL("??0TerrainClass@@QAE@PAVTerrainTypeClass@@AAVCell@@@Z", 0x0063F500);
REGISTER_ASM_SYMBOL("??0TriggerTypeClass@@QAE@PBD@Z", 0x00649CA0);
REGISTER_ASM_SYMBOL("??0TriggerClass@@QAE@PAVTriggerTypeClass@@@Z", 0x00649040);
REGISTER_ASM_SYMBOL("??0TagClass@@QAE@PAVTagTypeClass@@@Z", 0x0061E330);
REGISTER_ASM_SYMBOL("??0CampaignClass@@QAE@PBD@Z", 0x00448A10);
REGISTER_ASM_SYMBOL("??0WaveClass@@QAE@XZ", 0x006700B0);
REGISTER_ASM_SYMBOL("??0WaveClass@@QAE@AAVCoord@@0PAVAbstractClass@@W4WaveType@@1@Z", 0x0066FDE0);
REGISTER_ASM_SYMBOL("??0ParticleClass@@QAE@XZ", 0x005A3170);
REGISTER_ASM_SYMBOL("??0ParticleClass@@QAE@PAVParticleTypeClass@@AAVCoord@@1PAVParticleSystemClass@@@Z", 0x005A2C90);
REGISTER_ASM_SYMBOL("??0ParticleSystemClass@@QAE@XZ", 0x005A5580);
REGISTER_ASM_SYMBOL("??0ParticleSystemClass@@QAE@PBVParticleSystemTypeClass@@ABVCoord@@PAVAbstractClass@@21@Z", 0x005A5300);
REGISTER_ASM_SYMBOL("??0IsometricTileClass@@QAE@W4IsometricTileType@@AAVCell@@@Z", 0x004F2070);
REGISTER_ASM_SYMBOL("??0TubeClass@@QAE@AAVCell@@W4FacingType@@@Z", 0x0064AED0);
REGISTER_ASM_SYMBOL("??0SessionClass@@QAE@XZ", 0x005ECD00);
REGISTER_ASM_SYMBOL("??0UDPInterfaceClass@@QAE@XZ", 0x006A1E70);
REGISTER_ASM_SYMBOL("??0EnumConnectionPointsClass@@QAE@XZ", 0x0046FC70);
REGISTER_ASM_SYMBOL("??0EnumConnectionPointsClass@@QAE@ABV?$DynamicVectorClass@PAUIConnectionPoint@@@@@Z", 0x0046FD30);
REGISTER_ASM_SYMBOL("??0ThemeClass@@QAE@XZ", 0x00643D60);
REGISTER_ASM_SYMBOL("??0ToolTipManager@@QAE@PAUHWND__@@@Z", 0x00647190);
REGISTER_ASM_SYMBOL("??0WinsockInterfaceClass@@QAE@XZ", 0x006A0EB0);
REGISTER_ASM_SYMBOL("??0IPXManagerClass@@QAE@HHHHGG@Z", 0x004F0320);
REGISTER_ASM_SYMBOL("??0IPXConnClass@@QAE@HHHGPAVIPXAddressClass@@HPADH@Z", 0x004EF450);
REGISTER_ASM_SYMBOL("??0IPXGlobalConnClass@@QAE@HHHG@Z", 0x004EFA60);
REGISTER_ASM_SYMBOL("??0ConnectionClass@@QAE@HHHGKKKH@Z", 0x00461D00);
REGISTER_ASM_SYMBOL("??0CommBufferClass@@QAE@HHHH@Z", 0x00460BC0);
REGISTER_ASM_SYMBOL("??0LoadOptionsClass@@QAE@XZ", 0x005047B0);
REGISTER_ASM_SYMBOL("??0MapClass@@QAE@XZ", 0x0050EAD0);
REGISTER_ASM_SYMBOL("??0MapClass@@QAE@ABVNoInitClass@@@Z", 0x0050EBE0);
REGISTER_ASM_SYMBOL("??0LCWPipe@@QAE@W4CompControl@0@H@Z", 0x004FD3B0);
REGISTER_ASM_SYMBOL("??0LCWStraw@@QAE@W4CompControl@0@H@Z", 0x004FD7A0);
REGISTER_ASM_SYMBOL("??0LZOPipe@@QAE@W4CompControl@0@H@Z", 0x00507DF0);
REGISTER_ASM_SYMBOL("??0LZOStraw@@QAE@W4CompControl@0@H@Z", 0x00508260);
REGISTER_ASM_SYMBOL("??0WaypointPathClass@@QAE@XZ", 0x006733D0);
REGISTER_ASM_SYMBOL("??0WaypointPathClass@@QAE@H@Z", 0x006734A0);
REGISTER_ASM_SYMBOL("??0WaypointPathClass@@QAE@ABVNoInitClass@@@Z", 0x00673470);
REGISTER_ASM_SYMBOL("??0RadarClass@@QAE@XZ", 0x005B8830);
REGISTER_ASM_SYMBOL("??0ConnectionPointClass@@QAE@ABU_GUID@@PAUIUnknown@@@Z", 0x0046F8C0);
REGISTER_ASM_SYMBOL("??0EnumConnectionsClass@@QAE@ABV?$DynamicVectorClass@UtagCONNECTDATA@@@@@Z", 0x0046F300);
REGISTER_ASM_SYMBOL("??0EnumConnectionsClass@@QAE@ABV0@@Z", 0x0046F3D0);
REGISTER_ASM_SYMBOL("??0SwizzleManagerClass@@QAE@XZ", 0x0060D9B0);
REGISTER_ASM_SYMBOL("??0ScenarioClass@@QAE@XZ", 0x005DABC0);
REGISTER_ASM_SYMBOL("??0ScenarioClass@@QAE@ABVNoInitClass@@@Z", 0x005DAE00);
REGISTER_ASM_SYMBOL("??0RulesClass@@QAE@XZ", 0x005C4350);
REGISTER_ASM_SYMBOL("??0RulesClass@@QAE@ABVNoInitClass@@@Z", 0x005C3E00);
REGISTER_ASM_SYMBOL("??0Dictionary@@QAE@XZ", 0x005FD410);
REGISTER_ASM_SYMBOL("??1Dictionary@@QAE@XZ", 0x005FD4F0);
REGISTER_ASM_SYMBOL("??0ToggleClass@@QAE@IHHHH@Z", 0x00647000);
REGISTER_ASM_SYMBOL("??0TextButtonClass@@QAE@XZ", 0x00643430);
REGISTER_ASM_SYMBOL("??0TextButtonClass@@QAE@IPBDW4TextPrintType@@HHHH_N2@Z", 0x006433A0);
REGISTER_ASM_SYMBOL("??0TextButtonClass@@QAE@IHW4TextPrintType@@HHHH_N1@Z", 0x00643460);
REGISTER_ASM_SYMBOL("??0GaugeClass@@QAE@IHHHH@Z", 0x004AACB0);
REGISTER_ASM_SYMBOL("??0TriColorGaugeClass@@QAE@IHHHH@Z", 0x004AB1F0);
REGISTER_ASM_SYMBOL("??0Dial8Class@@QAE@HHHHHW4DirType@@@Z", 0x00473F30);
REGISTER_ASM_SYMBOL("??0StaticButtonClass@@QAE@XZ", 0x00608EF0);
REGISTER_ASM_SYMBOL("??0StaticButtonClass@@QAE@IPBDW4TextPrintType@@HHHH@Z", 0x00608E50);
REGISTER_ASM_SYMBOL("??0ShapeButtonClass@@QAE@XZ", 0x005F15A0);
REGISTER_ASM_SYMBOL("??0ShapeButtonClass@@QAE@IPBUShapeFileStruct@@HH@Z", 0x005F15E0);
REGISTER_ASM_SYMBOL("??0SliderClass@@QAE@IHHHH_N@Z", 0x005F7AC0);
REGISTER_ASM_SYMBOL("??0ListClass@@QAE@HHHHHW4TextPrintType@@PBX1@Z", 0x00503280);
REGISTER_ASM_SYMBOL("??0ListClass@@QAE@ABV0@@Z", 0x005033E0);
REGISTER_ASM_SYMBOL("??0ColorListClass@@QAE@HHHHHW4TextPrintType@@PBX1@Z", 0x0045E080);
REGISTER_ASM_SYMBOL("??CheckListClass@@YIHHHHHHW4TextPrintType@@PBX1@Z", 0x0045DB90);
REGISTER_ASM_SYMBOL("??0EditClass@@QAE@HPADHW4TextPrintType@@HHHHW4EditStyle@0@@Z", 0x00490280);
REGISTER_ASM_SYMBOL("??0DropListClass@@QAE@HPADHW4TextPrintType@@HHHHPBX2@Z", 0x00482450);
REGISTER_ASM_SYMBOL("??4DropListClass@@QAEAAV0@ABV0@@Z", 0x00482860);
REGISTER_ASM_SYMBOL("??0DropListClass@@QAE@ABV0@@Z", 0x00482A10);
REGISTER_ASM_SYMBOL("??0TextLabelClass@@QAE@PBDHHW4ColorSchemeType@@W4TextPrintType@@@Z", 0x0064D0C0);
REGISTER_ASM_SYMBOL("??0LaserDrawClass@@QAE@VCoord@@0H_NVRGBClass@@22H11MM@Z", 0x004FBC80);
REGISTER_ASM_SYMBOL("??0PacketClass@@QAE@PAD@Z", 0x005A22E0);
REGISTER_ASM_SYMBOL("??1PacketClass@@QAE@XZ", 0x005A22A0);
REGISTER_ASM_SYMBOL("??0FieldClass@@QAE@PADD@Z", 0x00498890);
REGISTER_ASM_SYMBOL("??0FieldClass@@QAE@PADE@Z", 0x004988F0);
REGISTER_ASM_SYMBOL("??0FieldClass@@QAE@PADF@Z", 0x00498950);
REGISTER_ASM_SYMBOL("??0FieldClass@@QAE@PADG@Z", 0x004989B0);
REGISTER_ASM_SYMBOL("??0FieldClass@@QAE@PADJ@Z", 0x00498A10);
REGISTER_ASM_SYMBOL("??0FieldClass@@QAE@PADK@Z", 0x00498A70);
REGISTER_ASM_SYMBOL("??0FieldClass@@QAE@PAD0@Z", 0x00498AD0);
REGISTER_ASM_SYMBOL("??0FieldClass@@QAE@PADPAXH@Z", 0x00498B40);
REGISTER_ASM_SYMBOL("??1FieldClass@@QAE@XZ", 0x00498BA0);
REGISTER_ASM_SYMBOL("??0PKey@@QAE@PBXPBX@Z", 0x005A94F0);
REGISTER_ASM_SYMBOL("??1BrainClass@@UAE@XZ", 0x00425540);
REGISTER_ASM_SYMBOL("??0NeuronClass@@QAE@XZ", 0x004252B0);
REGISTER_ASM_SYMBOL("??1NeuronClass@@QAE@XZ", 0x00425390);
REGISTER_ASM_SYMBOL("??0AlphaShapeClass@@QAE@XZ", 0x00412720);
REGISTER_ASM_SYMBOL("??0AlphaShapeClass@@QAE@PAVAbstractClass@@HH@Z", 0x004125A0);
REGISTER_ASM_SYMBOL("??0AlphaShapeClass@@QAE@ABVNoInitClass@@@Z", 0x00412880);
REGISTER_ASM_SYMBOL("??1AlphaShapeClass@@QAE@XZ", 0x004128A0);
REGISTER_ASM_SYMBOL("??0FlyLocomotionClass@@QAE@XZ", 0x004994B0);
REGISTER_ASM_SYMBOL("??1FlyLocomotionClass@@UAE@XZ", 0x00499530);
REGISTER_ASM_SYMBOL("??0MechLocomotionClass@@QAE@XZ", 0x00556040);
REGISTER_ASM_SYMBOL("??1MechLocomotionClass@@UAE@XZ", 0x005560A0);
REGISTER_ASM_SYMBOL("??0HoverLocomotionClass@@QAE@XZ", 0x004CE8F0);
REGISTER_ASM_SYMBOL("??1HoverLocomotionClass@@UAE@XZ", 0x004CE9D0);
REGISTER_ASM_SYMBOL("??0IPXAddressClass@@QAE@XZ", 0x004EF040);
REGISTER_ASM_SYMBOL("??0IPXAddressClass@@QAE@QAE0@Z", 0x004EF070);
REGISTER_ASM_SYMBOL("??0IPXAddressClass@@QAE@PAUIPXHEADER@@@Z", 0x004EF0A0);
REGISTER_ASM_SYMBOL("??0EMPulseClass@@QAE@VCell@@HHPAVTechnoClass@@@Z", 0x004926B0);
REGISTER_ASM_SYMBOL("??0EMPulseClass@@QAE@XZ", 0x00492760);
REGISTER_ASM_SYMBOL("??0EMPulseClass@@QAE@ABVNoInitClass@@@Z", 0x00492790);
REGISTER_ASM_SYMBOL("??1EMPulseClass@@UAE@XZ", 0x004927B0);
REGISTER_ASM_SYMBOL("??0VeinholeMonsterClass@@QAE@VCell@@@Z", 0x00660C00);
REGISTER_ASM_SYMBOL("??0VeinholeMonsterClass@@QAE@ABVNoInitClass@@@Z", 0x00660A90);
REGISTER_ASM_SYMBOL("??1VeinholeMonsterClass@@QAE@XZ", 0x00661000);
REGISTER_ASM_SYMBOL("??0FoggedObjectClass@@QAE@XZ", 0x0049D850);
REGISTER_ASM_SYMBOL("??0FoggedObjectClass@@QAE@AAVCoord@@W4OverlayType@@H@Z", 0x0049D910);
REGISTER_ASM_SYMBOL("??0FoggedObjectClass@@QAE@AAVCoord@@W4SmudgeType@@H@Z", 0x0049DBB0);
REGISTER_ASM_SYMBOL("??0FoggedObjectClass@@QAE@PBVBuildingClass@@_N@Z", 0x0049DE60);
REGISTER_ASM_SYMBOL("??0FoggedObjectClass@@QAE@PBVTerrainClass@@@Z", 0x0049E2C0);
REGISTER_ASM_SYMBOL("??0FoggedObjectClass@@QAE@ABVNoInitClass@@@Z", 0x0049D810);
REGISTER_ASM_SYMBOL("??1FoggedObjectClass@@QAE@XZ", 0x0049E590);
REGISTER_ASM_SYMBOL("??0VoxelLibraryClass@@QAE@XZ", 0x00667E50);
REGISTER_ASM_SYMBOL("??0VoxelLibraryClass@@QAE@PAVFileClass@@_N@Z", 0x00667E70);
REGISTER_ASM_SYMBOL("??1VoxelLibraryClass@@QAE@XZ", 0x00667EB0);
REGISTER_ASM_SYMBOL("??0MotionLibraryClass@@QAE@XZ", 0x00561C90);
REGISTER_ASM_SYMBOL("??0MotionLibraryClass@@QAE@PAVFileClass@@@Z", 0x00561CA0);
REGISTER_ASM_SYMBOL("??1MotionLibraryClass@@QAE@XZ", 0x00561CD0);
REGISTER_ASM_SYMBOL("??0StaticBufferClass@@QAE@I@Z", 0x0060A880);
REGISTER_ASM_SYMBOL("??1StaticBufferClass@@QAE@XZ", 0x0060A8A0);
REGISTER_ASM_SYMBOL("??0VoxelPaletteClass@@QAE@PAX0@Z", 0x0066A940);
REGISTER_ASM_SYMBOL("??1VoxelPaletteClass@@QAE@XZ", 0x0066A9B0);
REGISTER_ASM_SYMBOL("??0SaveVersionInfo@@QAE@XZ", 0x005D8BE0);
REGISTER_ASM_SYMBOL("??0GameTimeClass@@QAE@XZ", 0x004AAC00);


/**
 *
 *  Module ranges and source filename
 *
 */
REGISTER_MODULE(0x00401000, 0x00401030, "_alpha.cpp");
REGISTER_MODULE(0x00401030, 0x004015E0, "_astar.cpp");
REGISTER_MODULE(0x004015E0, 0x00401A10, "_command.cpp");
REGISTER_MODULE(0x00401A10, 0x00401DE0, "_convert.cpp");
REGISTER_MODULE(0x00401DE0, 0x00402400, "_isotile.cpp");
REGISTER_MODULE(0x00402400, 0x004027F0, "_logic.cpp");
REGISTER_MODULE(0x004027F0, 0x00402B80, "_map.cpp");
REGISTER_MODULE(0x00402B80, 0x00402BB0, "_millitimer.cpp");
REGISTER_MODULE(0x00402BB0, 0x00403080, "_mixfile.cpp");
REGISTER_MODULE(0x00403080, 0x004030A0, "_mono.cpp");
REGISTER_MODULE(0x004030A0, 0x004030B0, "_mono.cpp");
REGISTER_MODULE(0x004030B0, 0x004031D0, "_palette.cpp");
REGISTER_MODULE(0x004031D0, 0x00403210, "_pk.cpp");
REGISTER_MODULE(0x00403210, 0x004032B0, "_rect.cpp");
REGISTER_MODULE(0x004032B0, 0x00403610, "_rtti.cpp");
REGISTER_MODULE(0x00403610, 0x00403E60, "_rules.cpp");
REGISTER_MODULE(0x00403E60, 0x00404460, "_script.cpp");
REGISTER_MODULE(0x00404460, 0x00404520, "_timers.cpp");
REGISTER_MODULE(0x00404520, 0x00404B60, "_voxel.cpp");
REGISTER_MODULE(0x00404B60, 0x00404BE0, "_voxelshadow.cpp");
REGISTER_MODULE(0x00404BE0, 0x004052B0, "_warhead.cpp");
REGISTER_MODULE(0x004052B0, 0x004058B0, "_weapon.cpp");
REGISTER_MODULE(0x004058B0, 0x004058B0, "_winstuff.cpp");
REGISTER_MODULE(0x004058B0, 0x00405FA0, "abstract.cpp");
REGISTER_MODULE(0x00405FA0, 0x00406520, "abstype.cpp");
REGISTER_MODULE(0x00406520, 0x00406EE0, "abuffer.cpp");
REGISTER_MODULE(0x00406EE0, 0x004072D0, "addon.cpp");
REGISTER_MODULE(0x004072D0, 0x004082E0, "ahandle.cpp");
REGISTER_MODULE(0x004082E0, 0x00408330, "ahtoi.cpp");
REGISTER_MODULE(0x00408330, 0x0040F970, "aircraft.cpp");
REGISTER_MODULE(0x0040F970, 0x00410290, "airtype.cpp");
REGISTER_MODULE(0x00410290, 0x00411C90, "aitriggertype.cpp");
REGISTER_MODULE(0x00411C90, 0x004122D0, "alphalighting.cpp");
REGISTER_MODULE(0x004122D0, 0x00413890, "alphashape.cpp");
REGISTER_MODULE(0x00413890, 0x004175A0, "anim.cpp");
REGISTER_MODULE(0x004175A0, 0x00418270, "animfile.cpp");
REGISTER_MODULE(0x00418270, 0x00419D60, "animtype.cpp");
REGISTER_MODULE(0x00419D60, 0x0041A320, "app.cpp");
REGISTER_MODULE(0x0041A320, 0x0041EB60, "astar.cpp");
REGISTER_MODULE(0x0041EB60, 0x0041ED40, "b64pipe.cpp");
REGISTER_MODULE(0x0041ED40, 0x0041EE40, "b64straw.cpp");
REGISTER_MODULE(0x0041EE40, 0x0041F1E0, "bar.cpp");
REGISTER_MODULE(0x0041F1E0, 0x004208B0, "base.cpp");
REGISTER_MODULE(0x004208B0, 0x00420B00, "base64.cpp");
REGISTER_MODULE(0x00420B00, 0x00420C40, "bench.cpp");
REGISTER_MODULE(0x00420C40, 0x00421890, "bfiofile.cpp");
REGISTER_MODULE(0x00421890, 0x00423310, "blight.cpp");
REGISTER_MODULE(0x00423310, 0x00423F70, "blit.cpp");
REGISTER_MODULE(0x00423F70, 0x00424080, "blowfish.cpp");
REGISTER_MODULE(0x00424080, 0x00424230, "blowpipe.cpp");
REGISTER_MODULE(0x00424230, 0x00424360, "blowstraw.cpp");
REGISTER_MODULE(0x00424360, 0x00425080, "bounce.cpp");
REGISTER_MODULE(0x00425080, 0x00425C30, "brain.cpp");
REGISTER_MODULE(0x00425C30, 0x00425DE0, "buff.cpp");
REGISTER_MODULE(0x00425DE0, 0x00425E70, "buffer.cpp");
REGISTER_MODULE(0x00425E70, 0x0043C690, "building.cpp");
REGISTER_MODULE(0x0043C690, 0x00444250, "buildtype.cpp");
REGISTER_MODULE(0x00444250, 0x00447970, "bullet.cpp");
REGISTER_MODULE(0x00447970, 0x004487E0, "bullettype.cpp");
REGISTER_MODULE(0x004487E0, 0x00448F60, "campaign.cpp");
REGISTER_MODULE(0x00448F60, 0x004492C0, "cargo.cpp");
REGISTER_MODULE(0x004492C0, 0x00449700, "carry.cpp");
REGISTER_MODULE(0x00449700, 0x00449790, "category.cpp");
REGISTER_MODULE(0x00449790, 0x00449CE0, "ccfile.cpp");
REGISTER_MODULE(0x00449CE0, 0x0044E160, "ccini.cpp");
REGISTER_MODULE(0x0044E160, 0x0044E750, "cctooltip.cpp");
REGISTER_MODULE(0x0044E750, 0x0044ED60, "cd.cpp");
REGISTER_MODULE(0x0044ED60, 0x004505E0, "cdctrl.cpp");
REGISTER_MODULE(0x004505E0, 0x00450D10, "cdfile.cpp");
REGISTER_MODULE(0x00450D10, 0x0045D9E0, "cell.cpp");
REGISTER_MODULE(0x0045D9E0, 0x0045DB70, "checkbox.cpp");
REGISTER_MODULE(0x0045DB70, 0x0045E060, "cheklist.cpp");
REGISTER_MODULE(0x0045E060, 0x0045E910, "colorlist.cpp");
REGISTER_MODULE(0x0045E910, 0x00460BC0, "combat.cpp");
REGISTER_MODULE(0x00460BC0, 0x00461D00, "combuf.cpp");
REGISTER_MODULE(0x00461D00, 0x004623E0, "connect.cpp");
REGISTER_MODULE(0x004623E0, 0x00463730, "conquer.cpp");
REGISTER_MODULE(0x00463730, 0x00463B80, "control.cpp");
REGISTER_MODULE(0x00463B80, 0x0046E4D0, "convert.cpp");
REGISTER_MODULE(0x0046E4D0, 0x0046E9F0, "coord.cpp");
REGISTER_MODULE(0x0046E9F0, 0x0046ED40, "counter.cpp");
REGISTER_MODULE(0x0046ED40, 0x00470560, "cpoint.cpp");
REGISTER_MODULE(0x00470560, 0x00470CC0, "crate.cpp");
REGISTER_MODULE(0x00470CC0, 0x004710E0, "crc.cpp");
REGISTER_MODULE(0x004710E0, 0x00471160, "crcpipe.cpp");
REGISTER_MODULE(0x00471160, 0x004711F0, "crcstraw.cpp");
REGISTER_MODULE(0x004711F0, 0x00471720, "credits.cpp");
REGISTER_MODULE(0x00471720, 0x004717C0, "cstraw.cpp");
REGISTER_MODULE(0x004717C0, 0x004721F0, "cstream.cpp");
REGISTER_MODULE(0x004721F0, 0x00472710, "data.cpp");
REGISTER_MODULE(0x00472710, 0x00473970, "ddraw.cpp");
REGISTER_MODULE(0x00473970, 0x00473C20, "debug.cpp");
REGISTER_MODULE(0x00473C20, 0x00473F10, "delay.cpp");
REGISTER_MODULE(0x00473F10, 0x00474540, "dail8.cpp");
REGISTER_MODULE(0x00474540, 0x00475260, "dialog.cpp");
REGISTER_MODULE(0x00475260, 0x004754A0, "dib.cpp");
REGISTER_MODULE(0x004754A0, 0x00475850, "disk.cpp");
REGISTER_MODULE(0x00475850, 0x0047C6E0, "display.cpp");
REGISTER_MODULE(0x0047C6E0, 0x0047C760, "dllver.cpp");
REGISTER_MODULE(0x0047C760, 0x0047CCC0, "draw.cpp");
REGISTER_MODULE(0x0047CCC0, 0x00482430, "drive.cpp");
REGISTER_MODULE(0x00482430, 0x00482EA0, "droplist.cpp");
REGISTER_MODULE(0x00482EA0, 0x00483DF0, "droppod.cpp");
REGISTER_MODULE(0x00483DF0, 0x00487990, "dropship.cpp");
REGISTER_MODULE(0x00487990, 0x0048A960, "dsaudio.cpp");
REGISTER_MODULE(0x0048A960, 0x00490260, "dsurface.cpp");
REGISTER_MODULE(0x00490260, 0x00490860, "edit.cpp");
REGISTER_MODULE(0x00490860, 0x00490EF0, "effects.cpp");
REGISTER_MODULE(0x00490EF0, 0x00492080, "ego.cpp");
REGISTER_MODULE(0x00492080, 0x004923C0, "el.cpp");
REGISTER_MODULE(0x004923C0, 0x004935C0, "empulse.cpp");
REGISTER_MODULE(0x004935C0, 0x00493A70, "enviro.cpp");
REGISTER_MODULE(0x00493A70, 0x004951B0, "event.cpp");
REGISTER_MODULE(0x004951B0, 0x004964D0, "except.cpp");
REGISTER_MODULE(0x004964D0, 0x00496530, "expand.cpp");
REGISTER_MODULE(0x00496530, 0x00496A10, "facing.cpp");
REGISTER_MODULE(0x00496A10, 0x00497F50, "factory.cpp");
REGISTER_MODULE(0x00497F50, 0x00498890, "fastmath.cpp");
REGISTER_MODULE(0x00498890, 0x00498CA0, "field.cpp");
REGISTER_MODULE(0x00498CA0, 0x00499240, "findpath.cpp");
REGISTER_MODULE(0x00499240, 0x00499260, "flasher.cpp");
REGISTER_MODULE(0x00499260, 0x0049D4B0, "fly.cpp");
REGISTER_MODULE(0x0049D4B0, 0x0049FE20, "fogged.cpp");
REGISTER_MODULE(0x0049FE20, 0x004A97C0, "foot.cpp");
REGISTER_MODULE(0x004A97C0, 0x004A9BB0, "fuse.cpp");
REGISTER_MODULE(0x004A9BB0, 0x004AA240, "gadget.cpp");
REGISTER_MODULE(0x004AA240, 0x004AABF0, "gamedlg.cpp");
REGISTER_MODULE(0x004AABF0, 0x004AAC90, "gametime.cpp");
REGISTER_MODULE(0x004AAC90, 0x004AB8B0, "gauge.cpp");
REGISTER_MODULE(0x004AB8B0, 0x004AB990, "getcd.cpp");
REGISTER_MODULE(0x004AB990, 0x004AB9D0, "getcpu.cpp");
REGISTER_MODULE(0x004AB9D0, 0x004B6500, "globals.cpp");
REGISTER_MODULE(0x004B6500, 0x004B70A0, "goptions.cpp");
REGISTER_MODULE(0x004B70A0, 0x004B80F0, "gmenu.cpp");
REGISTER_MODULE(0x004B80F0, 0x004B8700, "gmenuimageitem.cpp");
REGISTER_MODULE(0x004B8700, 0x004B8940, "gmenuitem.cpp");
REGISTER_MODULE(0x004B8940, 0x004B8DD0, "gmenushortcutitem.cpp");
REGISTER_MODULE(0x004B8DD0, 0x004B9120, "gmenuversiontext.cpp");
REGISTER_MODULE(0x004B9120, 0x004B9AC0, "gscreen.cpp");
REGISTER_MODULE(0x004B9AC0, 0x004B9C00, "helpers.cpp");
REGISTER_MODULE(0x004B9C00, 0x004CDAC0, "house.cpp");
REGISTER_MODULE(0x004CDAC0, 0x004CE6A0, "housetype.cpp");
REGISTER_MODULE(0x004CE6A0, 0x004D1B60, "hover.cpp");
REGISTER_MODULE(0x004D1B60, 0x004D1D80, "hsv.cpp");
REGISTER_MODULE(0x004D1D80, 0x004D9F90, "infantry.cpp");
REGISTER_MODULE(0x004D9F90, 0x004DB450, "inftype.cpp");
REGISTER_MODULE(0x004DB450, 0x004DF920, "ini.cpp");
REGISTER_MODULE(0x004DF920, 0x004EBDA0, "init.cpp");
REGISTER_MODULE(0x004EBDA0, 0x004EBDB0, "int.cpp");
REGISTER_MODULE(0x004EBDB0, 0x004EC290, "interpal.cpp");
REGISTER_MODULE(0x004EC290, 0x004EC510, "intro.cpp");
REGISTER_MODULE(0x004EC510, 0x004ED8F0, "ion.cpp");
REGISTER_MODULE(0x004ED8F0, 0x004EF040, "ionblast.cpp");
REGISTER_MODULE(0x004EF040, 0x004EF430, "ipxaddr.cpp");
REGISTER_MODULE(0x004EF430, 0x004EF810, "ipxconn.cpp");
REGISTER_MODULE(0x004EF810, 0x004F00D0, "ipxgconn.cpp");
REGISTER_MODULE(0x004F00D0, 0x004F1A00, "ipxmgr.cpp");
REGISTER_MODULE(0x004F1A00, 0x004F24E0, "isotile.cpp");
REGISTER_MODULE(0x004F24E0, 0x004F91D0, "isotiletype.cpp");
REGISTER_MODULE(0x004F91D0, 0x004F9340, "jshell.cpp");
REGISTER_MODULE(0x004F9340, 0x004FAD90, "jumpjet.cpp");
REGISTER_MODULE(0x004FAD90, 0x004FB990, "keyboard.cpp");
REGISTER_MODULE(0x004FB990, 0x004FCB20, "laser.cpp");
REGISTER_MODULE(0x004FCB20, 0x004FD020, "layer.cpp");
REGISTER_MODULE(0x004FD020, 0x004FD3B0, "lcw.cpp");
REGISTER_MODULE(0x004FD3B0, 0x004FD7A0, "lcwpipe.cpp");
REGISTER_MODULE(0x004FD7A0, 0x004FDA00, "lcwstraw.cpp");
REGISTER_MODULE(0x004FDA00, 0x004FDBF0, "lcwuncomp.cpp");
REGISTER_MODULE(0x004FDBF0, 0x005010F0, "levitate.cpp");
REGISTER_MODULE(0x005010F0, 0x005024D0, "light.cpp");
REGISTER_MODULE(0x005024D0, 0x005027B0, "lightcalc.cpp");
REGISTER_MODULE(0x005027B0, 0x00503050, "lightconvert.cpp");
REGISTER_MODULE(0x00503050, 0x00503260, "link.cpp");
REGISTER_MODULE(0x00503260, 0x00504520, "list.cpp");
REGISTER_MODULE(0x00504520, 0x00504560, "load.cpp");
REGISTER_MODULE(0x00504560, 0x00505FC0, "loaddlg.cpp");
REGISTER_MODULE(0x00505FC0, 0x00506860, "locomotion.cpp");
REGISTER_MODULE(0x00506860, 0x005076D0, "logic.cpp");
REGISTER_MODULE(0x005076D0, 0x00507C20, "lzo1x_c.cpp");
REGISTER_MODULE(0x00507C20, 0x00507DF0, "lzo1x_d.cpp");
REGISTER_MODULE(0x00507DF0, 0x00508260, "lzopipe.cpp");
REGISTER_MODULE(0x00508260, 0x00508500, "lzostraw.cpp");
REGISTER_MODULE(0x00508500, 0x0050A240, "mainloop.cpp");
REGISTER_MODULE(0x0050A240, 0x0050B640, "mainopt.cpp");
REGISTER_MODULE(0x0050B640, 0x00530430, "map.cpp");
REGISTER_MODULE(0x00530430, 0x005306A0, "mapedit1.cpp");
REGISTER_MODULE(0x005306A0, 0x005308D0, "mapedit2.cpp");
REGISTER_MODULE(0x005308D0, 0x00530D40, "mapedit3.cpp");
REGISTER_MODULE(0x00530D40, 0x00553330, "mapgen.cpp");
REGISTER_MODULE(0x00553330, 0x005546F0, "mapsel.cpp");
REGISTER_MODULE(0x005546F0, 0x00555DF0, "matrix.cpp");
REGISTER_MODULE(0x00555DF0, 0x00557C40, "mech.cpp");
REGISTER_MODULE(0x00557C40, 0x00557FE0, "misec.cpp");
REGISTER_MODULE(0x00557FE0, 0x00558BF0, "missile.cpp");
REGISTER_MODULE(0x00558BF0, 0x00559890, "mission.cpp");
REGISTER_MODULE(0x00559890, 0x0055A510, "mixfile.cpp");
REGISTER_MODULE(0x0055A510, 0x0055D0D0, "modemgst.cpp");
REGISTER_MODULE(0x0055D0D0, 0x00560D30, "modemhst.cpp");
REGISTER_MODULE(0x00560D30, 0x00561720, "modemreg.cpp");
REGISTER_MODULE(0x00561720, 0x00561C90, "mono.cpp");
REGISTER_MODULE(0x00561C90, 0x00561F00, "motlib.cpp");
REGISTER_MODULE(0x00561F00, 0x005633C0, "mouse.cpp");
REGISTER_MODULE(0x005633C0, 0x00563D10, "movie.cpp");
REGISTER_MODULE(0x00563D10, 0x00564840, "movies.cpp");
REGISTER_MODULE(0x00564840, 0x00564D80, "mplayer.cpp");
REGISTER_MODULE(0x00564D80, 0x00567D80, "mpmath.cpp");
REGISTER_MODULE(0x00567D80, 0x0056A9B0, "mpscore.cpp");
REGISTER_MODULE(0x0056A9B0, 0x0056ABD0, "mpu.cpp");
REGISTER_MODULE(0x0056ABD0, 0x0056E0A0, "msanim.cpp");
REGISTER_MODULE(0x0056E0A0, 0x00570890, "mschoice.cpp");
REGISTER_MODULE(0x00570890, 0x00571E30, "msengine.cpp");
REGISTER_MODULE(0x00571E30, 0x005727D0, "msfont.cpp");
REGISTER_MODULE(0x005727D0, 0x00572BB0, "msgbox.cpp");
REGISTER_MODULE(0x00572BB0, 0x00574030, "msglist.cpp");
REGISTER_MODULE(0x00574030, 0x00574BE0, "msgloop.cpp");
REGISTER_MODULE(0x00574BE0, 0x00574D00, "mssfx.cpp");
REGISTER_MODULE(0x00574D00, 0x00574D40, "mstimer.cpp");
REGISTER_MODULE(0x00574D40, 0x005753C0, "netdlg.cpp");
REGISTER_MODULE(0x005753C0, 0x0057BEB0, "netdlg2.cpp");
REGISTER_MODULE(0x0057BEB0, 0x0057F8F0, "netshare.cpp");
REGISTER_MODULE(0x0057F8F0, 0x00580630, "newmenu.cpp");
REGISTER_MODULE(0x00580630, 0x00580800, "nullconn.cpp");
REGISTER_MODULE(0x00580800, 0x00582460, "nulldlg.cpp");
REGISTER_MODULE(0x00582460, 0x00584580, "nullmgr.cpp");
REGISTER_MODULE(0x00584580, 0x00587330, "object.cpp");
REGISTER_MODULE(0x00587330, 0x005894C0, "objtype.cpp");
REGISTER_MODULE(0x005894C0, 0x00589710, "obscure.cpp");
REGISTER_MODULE(0x00589710, 0x0058B210, "options.cpp");
REGISTER_MODULE(0x0058B210, 0x0058CDA0, "overlay.cpp");
REGISTER_MODULE(0x0058CDA0, 0x0058DD00, "overlaytype.cpp");
REGISTER_MODULE(0x0058DD00, 0x0058ED90, "ovrlight.cpp");
REGISTER_MODULE(0x0058ED90, 0x005A22A0, "ownrdraw.cpp");
REGISTER_MODULE(0x005A22A0, 0x005A2810, "packet.cpp");
REGISTER_MODULE(0x005A2810, 0x005A2A40, "palette.cpp");
REGISTER_MODULE(0x005A2A40, 0x005A50B0, "particle.cpp");
REGISTER_MODULE(0x005A50B0, 0x005A7980, "particlesys.cpp");
REGISTER_MODULE(0x005A7980, 0x005A8010, "pcx.cpp");
REGISTER_MODULE(0x005A8010, 0x005A9430, "phoneed.cpp");
REGISTER_MODULE(0x005A9430, 0x005A94F0, "pipe.cpp");
REGISTER_MODULE(0x005A94F0, 0x005AA240, "pk.cpp");
REGISTER_MODULE(0x005AA240, 0x005AA5E0, "pkpipe.cpp");
REGISTER_MODULE(0x005AA5E0, 0x005AA960, "pkstraw.cpp");
REGISTER_MODULE(0x005AA960, 0x005AAD80, "plotpix.cpp");
REGISTER_MODULE(0x005AAD80, 0x005ABDC0, "power.cpp");
REGISTER_MODULE(0x005ABDC0, 0x005AD5E0, "preview.cpp");
REGISTER_MODULE(0x005AD5E0, 0x005AE1A0, "progrscreen.cpp");
REGISTER_MODULE(0x005AE1A0, 0x005AECD0, "psystype.cpp");
REGISTER_MODULE(0x005AECD0, 0x005AFE20, "ptype.cpp");
REGISTER_MODULE(0x005AFE20, 0x005AFE70, "quarry.cpp");
REGISTER_MODULE(0x005AFE70, 0x005B0CC0, "quat.cpp");
REGISTER_MODULE(0x005B0CC0, 0x005B8590, "queue.cpp");
REGISTER_MODULE(0x005B8590, 0x005BD600, "radar.cpp");
REGISTER_MODULE(0x005BD600, 0x005BDB00, "radio.cpp");
REGISTER_MODULE(0x005BDB00, 0x005BDEE0, "ramfile.cpp");
REGISTER_MODULE(0x005BDEE0, 0x005BE290, "random.cpp");
REGISTER_MODULE(0x005BE290, 0x005BECA0, "rawfile.cpp");
REGISTER_MODULE(0x005BECA0, 0x005BEDF0, "readfile.cpp");
REGISTER_MODULE(0x005BEDF0, 0x005BFF20, "reinf.cpp");
REGISTER_MODULE(0x005BFF20, 0x005C18C0, "restate.cpp");
REGISTER_MODULE(0x005C18C0, 0x005C2F40, "radarevent.cpp");
REGISTER_MODULE(0x005C2F40, 0x005C3430, "rgb.cpp");
REGISTER_MODULE(0x005C3430, 0x005C35B0, "rle.cpp");
REGISTER_MODULE(0x005C35B0, 0x005C3BB0, "rndstraw.cpp");
REGISTER_MODULE(0x005C3BB0, 0x005D4530, "rules.cpp");
REGISTER_MODULE(0x005D4530, 0x005D8BE0, "saveload.cpp");
REGISTER_MODULE(0x005D8BE0, 0x005DA930, "saveversioninfo.cpp");
REGISTER_MODULE(0x005DA930, 0x005E2110, "scenario.cpp");
REGISTER_MODULE(0x005E2110, 0x005E2C50, "scheme.cpp");
REGISTER_MODULE(0x005E2C50, 0x005E75D0, "score.cpp");
REGISTER_MODULE(0x005E75D0, 0x005E8300, "script.cpp");
REGISTER_MODULE(0x005E8300, 0x005E9A90, "scroll.cpp");
REGISTER_MODULE(0x005E9A90, 0x005EB2D0, "sendfile.cpp");
REGISTER_MODULE(0x005EB2D0, 0x005ECAB0, "serialed.cpp");
REGISTER_MODULE(0x005ECAB0, 0x005F1580, "session.cpp");
REGISTER_MODULE(0x005F1580, 0x005F1800, "sha.cpp");
REGISTER_MODULE(0x005F1800, 0x005F1E30, "side.cpp");
REGISTER_MODULE(0x005F1E30, 0x005F6A00, "sidebar.cpp");
REGISTER_MODULE(0x005F6A00, 0x005F7AA0, "skrimish.cpp");
REGISTER_MODULE(0x005F7AA0, 0x005F7AA0, "slider.cpp");
REGISTER_MODULE(0x005F7AA0, 0x005F8120, "slider.cpp");
REGISTER_MODULE(0x005F8120, 0x005FA790, "smooth.cpp");
REGISTER_MODULE(0x005FA790, 0x005FAF90, "smudge.cpp");
REGISTER_MODULE(0x005FAF90, 0x005FC090, "smudgetype.cpp");
REGISTER_MODULE(0x005FC090, 0x005FC850, "sounddlg.cpp");
REGISTER_MODULE(0x005FC850, 0x005FCEA0, "special.cpp");
REGISTER_MODULE(0x005FCEA0, 0x005FD310, "sprite.cpp");
REGISTER_MODULE(0x005FD310, 0x005FEE50, "spritecollection.cpp");
REGISTER_MODULE(0x005FEE50, 0x00608E30, "startup.cpp");
REGISTER_MODULE(0x00608E30, 0x006091F0, "statbtn.cpp");
REGISTER_MODULE(0x006091F0, 0x0060A860, "stats.cpp");
REGISTER_MODULE(0x0060A860, 0x0060AB10, "statbuf.cpp");
REGISTER_MODULE(0x0060AB10, 0x0060AB30, "stimer.cpp");
REGISTER_MODULE(0x0060AB30, 0x0060B070, "storage.cpp");
REGISTER_MODULE(0x0060B070, 0x0060CCE0, "super.cpp");
REGISTER_MODULE(0x0060CCE0, 0x0060D8A0, "supertype.cpp");
REGISTER_MODULE(0x0060D8A0, 0x0060E1A0, "swizzle.cpp");
REGISTER_MODULE(0x0060E1A0, 0x0060EB00, "tab.cpp");
REGISTER_MODULE(0x0060EB00, 0x006188B0, "tactical.cpp");
REGISTER_MODULE(0x006188B0, 0x0061E060, "taction.cpp");
REGISTER_MODULE(0x0061E060, 0x0061ED60, "tag.cpp");
REGISTER_MODULE(0x0061ED60, 0x0061FC30, "tagtype.cpp");
REGISTER_MODULE(0x0061FC30, 0x006211D0, "target.cpp");
REGISTER_MODULE(0x006211D0, 0x00621EB0, "taskforce.cpp");
REGISTER_MODULE(0x00621EB0, 0x00627AE0, "team.cpp");
REGISTER_MODULE(0x00627AE0, 0x006299D0, "teamtype.cpp");
REGISTER_MODULE(0x006299D0, 0x0063AB90, "techno.cpp");
REGISTER_MODULE(0x0063AB90, 0x0063EA70, "techtype.cpp");
REGISTER_MODULE(0x0063EA70, 0x0063EF20, "teleport.cpp");
REGISTER_MODULE(0x0063EF20, 0x00640D90, "terrain.cpp");
REGISTER_MODULE(0x00640D90, 0x00641DF0, "terraintype.cpp");
REGISTER_MODULE(0x00641DF0, 0x00643380, "tevent.cpp");
REGISTER_MODULE(0x00643380, 0x00643760, "textbtn.cpp");
REGISTER_MODULE(0x00643760, 0x006445C0, "theme.cpp");
REGISTER_MODULE(0x006445C0, 0x00646BF0, "tiberium.cpp");
REGISTER_MODULE(0x00646BF0, 0x00646FE0, "tmission.cpp");
REGISTER_MODULE(0x00646FE0, 0x00647170, "toggle.cpp");
REGISTER_MODULE(0x00647170, 0x00648160, "tooltip.cpp");
REGISTER_MODULE(0x00648160, 0x00648DF0, "tracker.cpp");
REGISTER_MODULE(0x00648DF0, 0x00649A50, "trigger.cpp");
REGISTER_MODULE(0x00649A50, 0x0064AC10, "trigtype.cpp");
REGISTER_MODULE(0x0064AC10, 0x0064AC80, "trim.cpp");
REGISTER_MODULE(0x0064AC80, 0x0064B6C0, "tube.cpp");
REGISTER_MODULE(0x0064B6C0, 0x0064D0A0, "tunnel.cpp");
REGISTER_MODULE(0x0064D0A0, 0x0064D230, "txtlabel.cpp");
REGISTER_MODULE(0x0064D230, 0x0065B6A0, "unit.cpp");
REGISTER_MODULE(0x0065B6A0, 0x0065C800, "unittype.cpp");
REGISTER_MODULE(0x0065C800, 0x0065D5B0, "unvqtblc.cpp");
REGISTER_MODULE(0x0065D5B0, 0x0065D700, "utracker.cpp");
REGISTER_MODULE(0x0065D700, 0x0065F160, "voxelanim.cpp");
REGISTER_MODULE(0x0065F160, 0x006601E0, "voxelanimtype.cpp");
REGISTER_MODULE(0x006601E0, 0x006607A0, "vector.cpp");
REGISTER_MODULE(0x006607A0, 0x00663B30, "veinhole.cpp");
REGISTER_MODULE(0x00663B30, 0x00664300, "version.cpp");
REGISTER_MODULE(0x00664300, 0x00664570, "veteran.cpp");
REGISTER_MODULE(0x00664570, 0x00665560, "voc.cpp");
REGISTER_MODULE(0x00665560, 0x006657C0, "volcheck.cpp");
REGISTER_MODULE(0x006657C0, 0x00665BE0, "vox.cpp");
REGISTER_MODULE(0x00665BE0, 0x00666B20, "voxdrsys.cpp");
REGISTER_MODULE(0x00666B20, 0x00667E30, "voxel.cpp");
REGISTER_MODULE(0x00667E30, 0x0066AF60, "voxlib.cpp");
REGISTER_MODULE(0x0066AF60, 0x0066C720, "vqa.cpp");
REGISTER_MODULE(0x0066C720, 0x0066C810, "vqaoption.cpp");
REGISTER_MODULE(0x0066C810, 0x0066EAB0, "walk.cpp");
REGISTER_MODULE(0x0066EAB0, 0x0066FB90, "warhead.cpp");
REGISTER_MODULE(0x0066FB90, 0x00672FE0, "wave.cpp");
REGISTER_MODULE(0x00672FE0, 0x00674430, "waypoint.cpp");
REGISTER_MODULE(0x00674430, 0x00675650, "wdtcamp.cpp");
REGISTER_MODULE(0x00675650, 0x00676A90, "wdtconflict.cpp");
REGISTER_MODULE(0x00676A90, 0x00676FB0, "wdtgameoptions.cpp");
REGISTER_MODULE(0x00676FB0, 0x00677260, "wdthistory.cpp");
REGISTER_MODULE(0x00677260, 0x00677B00, "wdtmap.cpp");
REGISTER_MODULE(0x00677B00, 0x006796E0, "wdtmapstate.cpp");
REGISTER_MODULE(0x006796E0, 0x00679A30, "wdtprop.cpp");
REGISTER_MODULE(0x00679A30, 0x0067DB10, "wdtsel.cpp");
REGISTER_MODULE(0x0067DB10, 0x0067DEC0, "wdtstate.cpp");
REGISTER_MODULE(0x0067DEC0, 0x0067E550, "wdtterr.cpp");
REGISTER_MODULE(0x0067E550, 0x00680810, "wdtvoices.cpp");
REGISTER_MODULE(0x00680810, 0x006819F0, "weapon.cpp");
REGISTER_MODULE(0x006819F0, 0x00682F60, "wincomm.cpp");
REGISTER_MODULE(0x00682F60, 0x00683FA0, "windlg.cpp");
REGISTER_MODULE(0x00683FA0, 0x00684790, "winezfnt.cpp");
REGISTER_MODULE(0x00684790, 0x00685730, "winfix.cpp");
REGISTER_MODULE(0x00685730, 0x00686530, "winstub.cpp");
REGISTER_MODULE(0x00686530, 0x006867B0, "wolcom.cpp");
REGISTER_MODULE(0x006867B0, 0x0069F0C0, "wonline.cpp");
REGISTER_MODULE(0x0069F0C0, 0x0069FAC0, "worlddom.cpp");
REGISTER_MODULE(0x0069FAC0, 0x006A00C0, "writepcx.cpp");
REGISTER_MODULE(0x006A00C0, 0x006A0C60, "wsipx.cpp");
REGISTER_MODULE(0x006A0C60, 0x006A1C40, "wsproto.cpp");
REGISTER_MODULE(0x006A1C40, 0x006A2C10, "wsudp.cpp");
REGISTER_MODULE(0x006A2C10, 0x006A43B0, "wstring.cpp");
REGISTER_MODULE(0x006A43B0, 0x006A4DF0, "wwfont.cpp");
REGISTER_MODULE(0x006A4DF0, 0x006A6B90, "wwmous.cpp");
REGISTER_MODULE(0x006A6B90, 0x006A8DB0, "xsurface.cpp");
REGISTER_MODULE(0x006A8DB0, 0x006A95D0, "zbuffer.cpp");
REGISTER_MODULE(0x006A95D0, 0x006A9AF0, "winvq\audio.cpp");
REGISTER_MODULE(0x006A9AF0, 0x006AAAA0, "winvq\\buffer_.cpp");
REGISTER_MODULE(0x006AAAA0, 0x006AAAC0, "winvq\\config.cpp");
REGISTER_MODULE(0x006AAAC0, 0x006AB6A0, "winvq\\drawer.cpp");
REGISTER_MODULE(0x006AB6A0, 0x006AB8D0, "winvq\\dstream.cpp");
REGISTER_MODULE(0x006AB8D0, 0x006AE9F0, "winvq\\loader.cpp");
REGISTER_MODULE(0x006AE9F0, 0x006AFD70, "winvq\\task.cpp");
REGISTER_MODULE(0x006AFD70, 0x006AFDF0, "winvq\\timer.cpp");
REGISTER_MODULE(0x006AFDF0, 0x006B1FF0, "winvq\\unvq.cpp");
REGISTER_MODULE(0x006B1FF0, 0x006B21E0, "auduncmp.cpp");
REGISTER_MODULE(0x006B21E0, 0x006B2310, "cliprect.cpp");
REGISTER_MODULE(0x006B2310, 0x006B236D, "float_asm_thing.cpp");
REGISTER_MODULE(0x006B236D, 0x006B24D0, "detproc.cpp");
REGISTER_MODULE(0x006B24D0, 0x006B2680, "isoasm.cpp");
REGISTER_MODULE(0x006B2680, 0x006B2A30, "olsosdec.cpp");
REGISTER_MODULE(0x006B2A30, 0x006B2B40, "smoothasm.cpp");
REGISTER_MODULE(0x006B2B40, 0x006B2F80, "soscodec.cpp");
REGISTER_MODULE(0x006B2F80, 0x006B3760, "unvq.cpp");
REGISTER_MODULE(0x006B3760, 0x006B4330, "vqasos.cpp");
REGISTER_MODULE(0x006B4330, 0x006B4520, "vqaunzap.cpp");
REGISTER_MODULE(0x006B4520, 0x006B4772, "vqauncomp.cpp");
REGISTER_MODULE(0x006B4772, 0x006B7610, "RT_crt.cpp");
REGISTER_MODULE(0x006B7610, 0x006B7800, "RT_ieee87.cpp");
REGISTER_MODULE(0x006B7800, 0x006B78CD, "RT_exsup.cpp");
REGISTER_MODULE(0x006B78CD, 0x006B78F8, "RT_Unk2.cpp");
REGISTER_MODULE(0x006B78F8, 0x006B79D0, "RT_exsup3.cpp");
REGISTER_MODULE(0x006B79D0, 0x006BB15F, "RT_morecrt1.cpp");
REGISTER_MODULE(0x006BB15F, 0x006BC17D, "RT_sbheap.cpp");
REGISTER_MODULE(0x006BC17D, 0x006BC25D, "RT_close.cpp");
REGISTER_MODULE(0x006BC25D, 0x006BC288, "RT_freebuf.cpp");
REGISTER_MODULE(0x006BC288, 0x006BC34A, "RT_flush.cpp");
REGISTER_MODULE(0x006BC34A, 0x006BC3EE, "RT_fflush.cpp");
REGISTER_MODULE(0x006BC3EE, 0x006BC4A5, "RT_sftbuf.cpp");
REGISTER_MODULE(0x006BC4A5, 0x006BC615, "RT_open.cpp");
REGISTER_MODULE(0x006BC615, 0x006BC6DD, "RT_stream.cpp");
REGISTER_MODULE(0x006BC6DD, 0x006BC816, "RT_fwrite.cpp");
REGISTER_MODULE(0x006BC816, 0x006BCA26, "RT_ioinit.cpp");
REGISTER_MODULE(0x006BCA26, 0x006BCAB3, "RT_calloc.cpp");
REGISTER_MODULE(0x006BCAB3, 0x006BCB34, "RT_closeall.cpp");
REGISTER_MODULE(0x006BCB34, 0x006BCF38, "RT_mbctype.cpp");
REGISTER_MODULE(0x006BCF38, 0x006BCFD2, "RT_mbsnbcpy.cpp");
REGISTER_MODULE(0x006BCFD2, 0x006BD017, "RT_handler.cpp");
REGISTER_MODULE(0x006BD017, 0x006BD0F3, "RT_filbuf.cpp");
REGISTER_MODULE(0x006BD0F3, 0x006BD6D0, "RT_tzset.cpp");
REGISTER_MODULE(0x006BD6D0, 0x006BD750, "RT_ullrem.cpp");
REGISTER_MODULE(0x006BD750, 0x006BD7B8, "RT_ulldiv.cpp");
REGISTER_MODULE(0x006BD7B8, 0x006BD7F7, "RT_mbsnbico.cpp");
REGISTER_MODULE(0x006BD7F7, 0x006BD865, "RT_wtombenv.cpp");
REGISTER_MODULE(0x006BD865, 0x006BD865, "RT_signal.cpp");
REGISTER_MODULE(0x006BD865, 0x006BDC1A, "RT_winsig.cpp");
REGISTER_MODULE(0x006BDC1A, 0x006BE3D7, "RT_fpexcept.cpp");
REGISTER_MODULE(0x006BE3D7, 0x006BE591, "RT_frnd.cpp");
REGISTER_MODULE(0x006BE591, 0x006BE630, "RT_util.cpp");
REGISTER_MODULE(0x006BE630, 0x006BE630, "RT_fpctrl.cpp");
REGISTER_MODULE(0x006BE630, 0x006BE720, "RT_strcat.cpp");
REGISTER_MODULE(0x006BE720, 0x006BE791, "RT_strdup.cpp");
REGISTER_MODULE(0x006BE791, 0x006BEA77, "RT_open.cpp");
REGISTER_MODULE(0x006BEA77, 0x006BEC17, "RT_xtoa.cpp");
REGISTER_MODULE(0x006BEC17, 0x006BEC17, "RT_morecrt2.cpp");
REGISTER_MODULE(0x006BEC17, 0x006C4B79, "RT_Unk1.cpp");
REGISTER_MODULE(0x006C4B79, 0x006C5781, "RT_strftime.cpp");
REGISTER_MODULE(0x006C5781, 0x006C58BF, "RT_inithelp.cpp");
REGISTER_MODULE(0x006C58BF, 0x006C5AD4, "RT_w_str.cpp");
REGISTER_MODULE(0x006C5AD4, 0x006C5BA3, "RT_validate.cpp");
REGISTER_MODULE(0x006C5BA3, 0x006C5BA3, "RT_hooks.cpp");
REGISTER_MODULE(0x006C5BA3, 0x006C5E3F, "RT_tenpow.cpp");
REGISTER_MODULE(0x006C5E3F, 0x006C5ED6, "RT_mbschr.cpp");
REGISTER_MODULE(0x006C5ED6, 0x006C5F90, "RT_setmode.cpp");
REGISTER_MODULE(0x006C5F90, 0x006C60A3, "RT_w_loc.cpp");
REGISTER_MODULE(0x006C60A3, 0x006C61C1, "RT_a_loc.cpp");
REGISTER_MODULE(0x006C61C1, 0x006C61E0, "RT_abort.cpp");
REGISTER_MODULE(0x006C61E0, 0x006C6922, "RT_comsupp.cpp");
REGISTER_MODULE(0x006C6922, 0x006C6EE7, "RT_kernel32.cpp");
REGISTER_MODULE(0x006C6EE7, 0x006C76D0, "RT_output.cpp");
REGISTER_MODULE(0x006C76D0, 0x006C7880, "RT_strrev.cpp");
REGISTER_MODULE(0x006C7880, 0x006C8E40, "maplightasm.cpp");
REGISTER_MODULE(0x006C8E40, 0x006C9680, "voxelasm.cpp");
REGISTER_MODULE(0x006C9680, 0x006CD148, "winasm.cpp");
REGISTER_MODULE(0x006CD148, 0x006CD1A8, "const.cpp");
REGISTER_MODULE(0x006CD1A8, 0x006CD22C, "control.cpp");
REGISTER_MODULE(0x006CD22C, 0x006CD868, "convert.cpp");
REGISTER_MODULE(0x006CD868, 0x006CD890, "counter.cpp");
REGISTER_MODULE(0x006CD890, 0x006CD980, "cpoint.cpp");
REGISTER_MODULE(0x006CD980, 0x006CD9D8, "cstream.cpp");
REGISTER_MODULE(0x006CD9D8, 0x006CDA18, "dsurface.cpp");
REGISTER_MODULE(0x006CDA18, 0x006CDAA8, "dial8.cpp");
REGISTER_MODULE(0x006CDAA8, 0x006CDCF0, "display.cpp");
REGISTER_MODULE(0x006CDCF0, 0x006CF870, "drive.cpp");
REGISTER_MODULE(0x006CF870, 0x006CFA30, "drop.cpp");
REGISTER_MODULE(0x006CFA30, 0x006CFE38, "droppod.cpp");
REGISTER_MODULE(0x006CFE38, 0x006CFEE0, "dsurface.cpp");
REGISTER_MODULE(0x006CFEE0, 0x006CFF28, "ego.cpp");
REGISTER_MODULE(0x006CFF28, 0x006D0000, "empulse.cpp");
REGISTER_MODULE(0x006D0000, 0x006D0060, "except.cpp");
REGISTER_MODULE(0x006D0060, 0x006D0184, "factory.cpp");
REGISTER_MODULE(0x006D0184, 0x006D0290, "fly.cpp");
REGISTER_MODULE(0x006D0290, 0x006D0358, "fog.cpp");
REGISTER_MODULE(0x006D0358, 0x006D07F0, "foot.cpp");
REGISTER_MODULE(0x006D07F0, 0x006D08A8, "gadget.cpp");
REGISTER_MODULE(0x006D08A8, 0x006D09F8, "gauge.cpp");
REGISTER_MODULE(0x006D09F8, 0x006D1940, "globals.cpp");
REGISTER_MODULE(0x006D1940, 0x006D1A48, "gmenu.cpp");
REGISTER_MODULE(0x006D1A48, 0x006D1AB8, "gscreen.cpp");
REGISTER_MODULE(0x006D1AB8, 0x006D1E20, "house.cpp");
REGISTER_MODULE(0x006D1E20, 0x006D2020, "hover.cpp");
REGISTER_MODULE(0x006D2020, 0x006D2500, "infantry.cpp");
REGISTER_MODULE(0x006D2500, 0x006D25D8, "inftype.cpp");
REGISTER_MODULE(0x006D25D8, 0x006D2674, "ini.cpp");
REGISTER_MODULE(0x006D2674, 0x006D2C50, "init.cpp");
REGISTER_MODULE(0x006D2C50, 0x006D2CA8, "ionblast.cpp");
REGISTER_MODULE(0x006D2CA8, 0x006D2CE0, "ipxconn.cpp");
REGISTER_MODULE(0x006D2CE0, 0x006D2D20, "ipxgconn.cpp");
REGISTER_MODULE(0x006D2D20, 0x006D2D70, "ipxmgr.cpp");
REGISTER_MODULE(0x006D2D70, 0x006D2DC0, "conman.cpp");
REGISTER_MODULE(0x006D2DC0, 0x006D2F90, "isotile.cpp");
REGISTER_MODULE(0x006D2F90, 0x006D35B8, "isotiletype.cpp");
REGISTER_MODULE(0x006D35B8, 0x006D36C8, "jumpjet.cpp");
REGISTER_MODULE(0x006D36C8, 0x006D3708, "laser.cpp");
REGISTER_MODULE(0x006D3708, 0x006D3720, "lcwpipe.cpp");
REGISTER_MODULE(0x006D3720, 0x006D3738, "lcwstraw.cpp");
REGISTER_MODULE(0x006D3738, 0x006D3848, "levitate.cpp");
REGISTER_MODULE(0x006D3848, 0x006D3950, "light.cpp");
REGISTER_MODULE(0x006D3950, 0x006D3968, "lightconvert.cpp");
REGISTER_MODULE(0x006D3968, 0x006D3A6C, "list.cpp");
REGISTER_MODULE(0x006D3A6C, 0x006D3B28, "slider.cpp");
REGISTER_MODULE(0x006D3B28, 0x006D3B98, "loaddlg.cpp");
REGISTER_MODULE(0x006D3B98, 0x006D3BB0, "lzopipe.cpp");
REGISTER_MODULE(0x006D3BB0, 0x006D3BCC, "lzostraw.cpp");
REGISTER_MODULE(0x006D3BCC, 0x006D3F20, "map.cpp");
REGISTER_MODULE(0x006D3F20, 0x006D4308, "mapgen.cpp");
REGISTER_MODULE(0x006D4308, 0x006D4320, "mapsel.cpp");
REGISTER_MODULE(0x006D4320, 0x006D4430, "mech.cpp");
REGISTER_MODULE(0x006D4430, 0x006D4680, "mission.cpp");
REGISTER_MODULE(0x006D4680, 0x006D46B0, "mixfile.cpp");
REGISTER_MODULE(0x006D46B0, 0x006D47A8, "tab.cpp");
REGISTER_MODULE(0x006D47A8, 0x006D4BFC, "multiscore.cpp");
REGISTER_MODULE(0x006D4BFC, 0x006D4C38, "nullconn.cpp");
REGISTER_MODULE(0x006D4C38, 0x006D4C88, "nullmgr.cpp");
REGISTER_MODULE(0x006D4C88, 0x006D4E60, "object.cpp");
REGISTER_MODULE(0x006D4E60, 0x006D4F68, "objtype.cpp");
REGISTER_MODULE(0x006D4F68, 0x006D4F78, "options.cpp");
REGISTER_MODULE(0x006D4F78, 0x006D5168, "overlay.cpp");
REGISTER_MODULE(0x006D5168, 0x006D5238, "overlaytype.cpp");
REGISTER_MODULE(0x006D5238, 0x006D5298, "ovrlight.cpp");
REGISTER_MODULE(0x006D5298, 0x006D5494, "particle.cpp");
REGISTER_MODULE(0x006D5494, 0x006D5670, "psys.cpp");
REGISTER_MODULE(0x006D5670, 0x006D568C, "pkpipe.cpp");
REGISTER_MODULE(0x006D568C, 0x006D56A4, "blowpipe.cpp");
REGISTER_MODULE(0x006D56A4, 0x006D56C0, "pkstraw.cpp");
REGISTER_MODULE(0x006D56C0, 0x007474A8, "power.cpp");
REGISTER_MODULE(0x007474A8, 0x007474B0, "_alpha.cpp");
REGISTER_MODULE(0x007474B0, 0x007481A4, "_astar.cpp");
REGISTER_MODULE(0x007481A4, 0x007481A8, "_bench.cpp");
REGISTER_MODULE(0x007481A8, 0x007481D8, "_commands.cpp");
REGISTER_MODULE(0x007481D8, 0x00748214, "_drawers.cpp");
REGISTER_MODULE(0x00748214, 0x007482C0, "_fonts.cpp");
REGISTER_MODULE(0x007482C0, 0x0074A130, "_keyboard.cpp");
REGISTER_MODULE(0x0074A130, 0x0074A138, "_mono.cpp");
REGISTER_MODULE(0x0074A138, 0x0074BC38, "_palettes.cpp");
REGISTER_MODULE(0x0074BC38, 0x0074BE40, "_pk.cpp");
REGISTER_MODULE(0x0074BE40, 0x0074C240, "_rnd.cpp");
REGISTER_MODULE(0x0074C240, 0x0074C270, "_rects.cpp");
REGISTER_MODULE(0x0074C270, 0x0074C2E8, "_rtti.cpp");
REGISTER_MODULE(0x0074C2E8, 0x0074C548, "_rules.cpp");
REGISTER_MODULE(0x0074C548, 0x0074C5CC, "_scripts.cpp");
REGISTER_MODULE(0x0074C5CC, 0x0074C5F4, "_surfaces.cpp");
REGISTER_MODULE(0x0074C5F4, 0x0074C5F8, "_tactical.cpp");
REGISTER_MODULE(0x0074C5F8, 0x0074C624, "_timer.cpp");
REGISTER_MODULE(0x0074C624, 0x0074C640, "_tooltip.cpp");
REGISTER_MODULE(0x0074C640, 0x0074C748, "_voxel.cpp");
REGISTER_MODULE(0x0074C748, 0x0074C7C8, "_warhead.cpp");
REGISTER_MODULE(0x0074C7C8, 0x0074C848, "_weapon.cpp");
REGISTER_MODULE(0x0074C848, 0x0074C8D8, "_winver.cpp");
REGISTER_MODULE(0x0074C8D8, 0x0074C8F0, "_wsproto.cpp");
REGISTER_MODULE(0x0074C8F0, 0x0074C8F4, "_wwmous.cpp");
REGISTER_MODULE(0x0074C8F4, 0x0074C9D8, "_zbuffer.cpp");
REGISTER_MODULE(0x0074C9D8, 0x0074C9E8, "abuffer.cpp");
REGISTER_MODULE(0x0074C9E8, 0x0074CA00, "addon.cpp");


/**
 *
 *  Code segment ranges for checking valid symbol addresses.
 *
 */
DWORD64 TSPP_GAME_EXE_START = 0x00401000;
DWORD64 TSPP_GAME_EXE_END = 0x006CA000;
