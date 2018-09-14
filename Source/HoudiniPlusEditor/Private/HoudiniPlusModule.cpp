#include "HoudiniPlusPrivatePCH.h"

#include "HoudiniPlusModule.h"
#include "HoudiniPlusSettings.h"

#define LOCTEXT_NAMESPACE "FHoudiniPlusModule"

DEFINE_LOG_CATEGORY(LogHoudiniPlus);

const FString FHoudiniPlusModule::HoudiniEngineAppIdentifier = TEXT("HoudiniEngineApp");

FHoudiniPlusModule::FHoudiniPlusModule()
{

}

void FHoudiniPlusModule::StartupModule()
{
    bHAPIVersionMismatch = false;
    HAPIState = HAPI_RESULT_NOT_INITIALIZED;

    UE_LOG(LogHoudiniPlus, Log, TEXT("Starting HoudiniPlus."));

    auto SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>(TEXT("Settings"));
    if (SettingsModule)
    {
        SettingsModule->RegisterSettings(
            "Project", "Plugins", "Houdini Plus",
            LOCTEXT("SettingsName", "Houdini Plus"),
            LOCTEXT("SettingsDescription", "Configure the Houdini Plus plugin."),
            GetMutableDefault<UHoudiniPlusSettings>());
    }

    //{
    //    //void* HAPILibraryHandle = 

    //    if (HAPILibraryHandle)
    //        HAPI->Initialize(HAPILibraryHandle);
    //    else
    //    {
    //        // Get HAPI name
    //        // UE_LOG(LogHoudiniPlus, Log, TEXT("Failed locating or loading %s."), *LibHAPIName);
    //    }
    //}

    //if (HAPI->IsInitialized())
    //{
    //    const auto Settings = GetDefault<UHoudiniPlusSettings>();

    //    HAPI_Result Result = HAPI_RESULT_FAILURE;

    //    auto Session = NewObject<UHoudiniPlusSession>(nullptr, Settings->SessionType, NAME_None, EObjectFlags::)
    //    auto SessionResult = Session->Create();

    //    if (SessionResult != HAPI_RESULT_SUCCESS || !Session)
    //        UE_LOG(HoudinPlusLog, Error, TEXT("Failed to create a Houdini Engine session."));
    //    
    //    auto Version = HAPI->GetHoudiniEngineVersion();
    //    if(Version.Matches())
    //    {
    //        HAPI_CookOptions CookOptions;
    //        FMemory::Memzero<HAPI_CookOptions>(CookOptions);
    //        CookOptions.curveRefineLOD = 8.0f;
    //        CookOptions.clearErrorsAndWarnings = false;
    //        CookOptions.maxVerticesPerPrimitive = 3;
    //        CookOptions.splitGeosByGroup = false;
    //        CookOptions.refineCurveToLinear = true;
    //        CookOptions.handleBoxPartTypes = false;
    //        CookOptions.handleSpherePartTypes = false;
    //        CookOptions.splitPointsByVertexAttributes = false;
    //        CookOptions.packedPrimInstancingMode = HAPI_PACKEDPRIM_INSTANCING_MODE_FLAT;

    //        auto Result = HAPI->Initialize(Session, &CookOptions);
    //        if (Result == HAPI_RESULT_SUCCESS)
    //        {
    //            UE_LOG(HoudiniPlusLog, Message, TEXT("Initialized the Houdini Plus module."));
    //            HAPI->SetServerEnvironmentString(Session, HAPI_ENV_CLIENT_NAME, HAPI_UNREAL_CLIENT_NAME);
    //        }
    //        else
    //        {
    //            UE_LOG(HoudiniPlusLog, Message, TEXT("Houdini Plus failed to initialize: %s"), HAPI->GetError(Result));
    //        }
    //    }
    //    else
    //    {
    //        bHAPIVersionMismatch = true;

    //        UE_LOG(HoudiniPlusLog, Message, TEXT("Houdini Plus failed to initialized: build and running versions don't match."));
    //    }

    //    Scheduler = MakeShareable(new FHoudiniPlusScheduler);
    //    SchedulerThread = FRunnableThread::Create(Scheduler.Get(), TEXT("HoudiniPlusScheduler"), 0, EThreadPriority::TPri_Normal);
    //}
}

void FHoudiniPlusModule::ShutdownModule()
{
    UE_LOG(LogHoudiniPlus, Log, TEXT("Shutting down HoudiniPlus."));

    auto SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>(TEXT("Settings"));
    if (SettingsModule)
        SettingsModule->UnregisterSettings(TEXT("Project"), TEXT("Plugins"), TEXT("HoudiniPlus"));

    //if (Scheduler.IsValid())
    //    Scheduler->Stop();

    //if (SchedulerThread)
    //{
    //    SchedulerThread->WaitForCompletion();

    //    delete SchedulerThread;
    //    SchedulerThread = nullptr;
    //}

    //if (Scheduler.IsValid())
    //    Schduler.Reset();
    //
    //if (HAPI->IsInitialized())
    //    HAPI->Cleanup();

    //HAPI->Finalize();
}

bool FHoudiniPlusModule::CheckHapiVersionMismatch() const
{
    throw std::logic_error("The method or operation is not implemented.");
}

HAPI_Result FHoudiniPlusModule::GetHapiState() const
{
    throw std::logic_error("The method or operation is not implemented.");
}

void FHoudiniPlusModule::SetHapiState(HAPI_Result Result)
{
    throw std::logic_error("The method or operation is not implemented.");
}

const HAPI_Session* FHoudiniPlusModule::GetSession()
{
    throw std::logic_error("The method or operation is not implemented.");
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FHoudiniPlusModule, HoudiniPlus)