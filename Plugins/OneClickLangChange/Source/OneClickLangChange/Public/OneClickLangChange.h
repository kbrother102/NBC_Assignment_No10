#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FOneClickLangChangeModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;
    
    TSharedPtr<class FUICommandList> PluginCommands;
};

