// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EditorSubsystem.h"

#include "LanguageToolbarSubsystem.generated.h"



UCLASS()
class ONECLICKLANGCHANGE_API ULanguageToolbarSubsystem : public UEditorSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
	
private:
	void ResisterToolbarButton();
	void ToggleLanguage();
	// 단축키와 액션을 매핑할 커맨드 리스트
	TSharedPtr<class FUICommandList> PluginCommands;
	
};
