#pragma once

#include <objidl.h>
#include <minwindef.h>

extern unsigned& GameVersion;

class SaveVersionInfo
{
    public:
        SaveVersionInfo();

        void Set_Version(int num);
        int Get_Version();

        void Set_Internal_Version(int num);
        int Get_Internal_Version();

        void Set_Scenario_Description(const char * desc);
        const char * Get_Scenario_Description();

        void Set_Player_House(const char * name);
        const char * Get_Player_House();

        void Set_Campaign_Number(int num);
        int Get_Campaign_Number();

        void Set_Scenario_Number(int num);
        int Get_Scenario_Number();

        void Set_Unknown_String(const char * name);
        const char * Get_Unknown_String();

        void Set_Player_Name(const char * name);
        const char * Get_Player_Name();

        void Set_Executable_Name(const char * name);
        const char * Get_Executable_Name();

        void Set_Start_Time(FILETIME &time);
        FILETIME Get_Start_Time();

        void Set_Play_Time(FILETIME &time);
        FILETIME Get_Play_Time();

        void Set_Last_Time(FILETIME &time);
        FILETIME Get_Last_Time();

        void Set_Game_Type(int id);
        int Get_Game_Type();

        HRESULT Save(IStorage *storage);
        HRESULT Load(IStorage *storage);

    private:
        HRESULT Load_String(IStorage *storage, int id, char *string);
        HRESULT Load_String_Set(IPropertySetStorage *storageset, int id, char *string);

        HRESULT Load_Int(IStorage *storage, int id, int *integer);
        HRESULT Load_Int_Set(IPropertySetStorage *storageset, int id, int *integer);

        HRESULT Save_String(IStorage *storage, int id, char *string);
        HRESULT Save_String_Set(IPropertySetStorage *storageset, int id, const char *string);

        HRESULT Save_Int(IStorage *storage, int id, int integer);
        HRESULT Save_Int_Set(IPropertySetStorage *storageset, int id, int integer);

        HRESULT Load_Time(IStorage *storage, int id, FILETIME *time);
        HRESULT Load_Time_Set(IPropertySetStorage *storageset, int id, FILETIME *time);

        HRESULT Save_Time(IStorage *storage, int id, FILETIME *time);
        HRESULT Save_Time_Set(IPropertySetStorage *storageset, int id, FILETIME *time);

    private:
        int InternalVersion;
        int Version;
        char ScenarioDescription[128];
        char PlayerHouse[64];
        int CampaignNumber;
        int ScenarioNumber;
        char UnknownString[260];
        char PlayerName[64];
        char ExecutableName[260];
        FILETIME StartTime;
        FILETIME PlayTime;
        FILETIME LastSaveTime;
        int GameType;
};

const WCHAR *Stream_Name_From_ID(int id);
bool Get_Savefile_Info(char const * name, SaveVersionInfo * info);
