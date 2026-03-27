// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"

/**
 * 
 */
class ONECLICKLANGCHANGE_API FEditorLanguageCommands : public TCommands<FEditorLanguageCommands>
{
public:
	FEditorLanguageCommands();
	
	virtual void RegisterCommands() override;
	
	TSharedPtr<FUICommandInfo> ToggleLanguageCommand;
};
