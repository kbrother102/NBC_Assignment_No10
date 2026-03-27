#include "OneClickLangChange.h"

#include "FEditorLanguageCommands.h"


#define LOCTEXT_NAMESPACE "FOneClickLangChangeModule"

void FOneClickLangChangeModule::StartupModule()
{
    FEditorLanguageCommands::Register();
}

void FOneClickLangChangeModule::ShutdownModule()
{
    // 모듈 종료 시 커맨드 등록 해제
    FEditorLanguageCommands::Unregister();
}

#undef LOCTEXT_NAMESPACE
    
IMPLEMENT_MODULE(FOneClickLangChangeModule, OneClickLangChange)