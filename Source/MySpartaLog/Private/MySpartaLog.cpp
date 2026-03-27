#include "MySpartaLog.h"

#define LOCTEXT_NAMESPACE "FMySpartaLogModule"
DEFINE_LOG_CATEGORY(LogMySpartaModule);
void FMySpartaLogModule::StartupModule()
{
	UE_LOG(LogMySpartaModule, Warning, TEXT("MySpartaLog is Start"));
}

void FMySpartaLogModule::ShutdownModule()
{
    
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FMySpartaLogModule, MySpartaLog)