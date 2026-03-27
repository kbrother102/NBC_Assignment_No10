// Fill out your copyright notice in the Description page of Project Settings.


#include "FEditorLanguageCommands.h"
#include "Styling/AppStyle.h"

FEditorLanguageCommands::FEditorLanguageCommands()
: TCommands(
			TEXT("MyEditorTool"), // Context name
			NSLOCTEXT("Contexts", "MyEditorTool", "My Editor Tool"), // Context description
			NAME_None,
			FAppStyle::GetAppStyleSetName()) // UE5 기준 스타일 지정
{
	
}
#define LOCTEXT_NAMESPACE "FEditorLanguageCommands"
void FEditorLanguageCommands::RegisterCommands()
{
	UI_COMMAND(ToggleLanguageCommand, "한/영 전환하기", "에디터 언어설정을 한/영으로 전환합니다.",
		EUserInterfaceActionType::Button, FInputChord(EModifierKey::Alt, EKeys::L));
	
}
#undef LOCTEXT_NAMESPACE
