// Fill out your copyright notice in the Description page of Project Settings.


#include "LanguageToolbarSubsystem.h"

#include "FEditorLanguageCommands.h"
#include "Internationalization/Culture.h"

// 에디터 환경에서만 컴파일 되도록 매크로 처리
#if WITH_EDITOR
#include "ToolMenus.h"
#include "Internationalization/Internationalization.h"
#include "Framework/Commands/UICommandList.h"
#include "LevelEditor.h"
#include "Interfaces/IMainFrameModule.h" // 메인 프레임 헤더 추가
#endif

void ULanguageToolbarSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
#if WITH_EDITOR
	// 에디터 메뉴 시스템이 초기화될 때 우리의 버튼도 같이 등록되도록 콜백을 걸어둡니다.
	UToolMenus::RegisterStartupCallback(
		FSimpleMulticastDelegate::FDelegate::CreateUObject(this, &ULanguageToolbarSubsystem::ResisterToolbarButton));
	
	// 1. 커맨드 리스트 인스턴스화
	PluginCommands = MakeShareable(new FUICommandList);
	// 2. 커맨드와 Subsystem의 멤버 함수 바인딩
	// 주의: Subsystem은 UObject이므로 CreateRaw가 아니라 CreateUObject를 사용해야 안전합니다!
	PluginCommands->MapAction(
		FEditorLanguageCommands::Get().ToggleLanguageCommand,
		FExecuteAction::CreateUObject(this, &ULanguageToolbarSubsystem::ToggleLanguage)
	);
	
	// 3. [중요] 생성한 커맨드 리스트를 레벨 에디터의 전역 커맨드에 등록합니다.
	// 이 작업을 해야 에디터 어디서든 Alt + L을 눌렀을 때 단축키가 작동합니다.
	//FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	//LevelEditorModule.GetGlobalLevelEditorActions()->Append(PluginCommands.ToSharedRef());
	
	// 3. [수정] 에디터 전체(MainFrame)를 관장하는 커맨드에 등록
	// 이렇게 하면 블루프린트, 머티리얼 에디터 등 모든 창에서 단축키가 작동합니다.
	IMainFrameModule& MainFrameModule = FModuleManager::LoadModuleChecked<IMainFrameModule>("MainFrame");
	MainFrameModule.GetMainFrameCommandBindings()->Append(PluginCommands.ToSharedRef());
#endif
}

void ULanguageToolbarSubsystem::Deinitialize()
{
#if WITH_EDITOR
	// 서브시스템 종료 시 정리할 내용이 있다면 여기에 작성
	PluginCommands.Reset(); // 명시적 해제 (선택사항)
	// 서브시스템이 종료될 때 콜백을 안전하게 해제합니다.
	UToolMenus::UnRegisterStartupCallback(this);


#endif

	Super::Deinitialize();
}

void ULanguageToolbarSubsystem::ResisterToolbarButton()
{
	UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.User");
	if (!ToolbarMenu) { return; }

	FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");


	// // 툴바에 들어갈 버튼을 구성합니다.
	// FToolMenuEntry LanguageEntry = FToolMenuEntry::InitToolBarButton(
	// 	"ToggleLanguageButton", // 내부 ID
	// 	FExecuteAction::CreateUObject(this, &ULanguageToolbarSubsystem::ToggleLanguage), // 클릭 시 실행할 함수 바인딩
	// 	FText::FromString(TEXT("한/영 변환")), // 버튼에 표시될 텍스트
	// 	FText::FromString(TEXT("에디터 언어를 한국어와 영어로 번갈아 변경합니다.")), // 마우스를 올렸을 때 툴팁
	// 	FSlateIcon() // 아이콘은 생략
	// );
	
	//커맨드를 버튼에 직접 주입
	FToolMenuEntry LanguageEntry = FToolMenuEntry::InitToolBarButton(
		FEditorLanguageCommands::Get().ToggleLanguageCommand);


	// 텍스트가 잘 보이도록 스타일 지정 (UE5 스타일)
	LanguageEntry.StyleNameOverride = "CalloutToolbar";

	// 툴바 섹션에 버튼을 최종 추가합니다.
	Section.AddEntry(LanguageEntry);
}

void ULanguageToolbarSubsystem::ToggleLanguage()
{
#if WITH_EDITOR
	// 현재 설정된 언어를 가져와서 비교한 뒤 전환합니다.
	FString CurrentCulture = FInternationalization::Get().GetCurrentCulture()->GetName();
	FString NewCulture = CurrentCulture.StartsWith(TEXT("ko")) ? TEXT("en") : TEXT("ko");

	FInternationalization::Get().SetCurrentCulture(NewCulture);
#endif
}


