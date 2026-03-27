using UnrealBuildTool;

public class OneClickLangChange : ModuleRules
{
    public OneClickLangChange(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(
            new string[]
            {
                "Core",
                "CoreUObject", 
                "Engine"
            }
        );


        if(Target.bBuildEditor)// 에디터 빌드 환경에서만 아래 모듈들을 포함시킵니다. (패키징 에러 방지)
        {
            PrivateDependencyModuleNames.AddRange(new string[]
            {
                "EditorSubsystem", // 서브시스템 부모 클래스용
                "ToolMenus", // 툴바 제어용
                "Slate", // UI 기본
                "SlateCore", // UI 코어
                "InputCore", //단축키를 위한 모듈
                "MainFrame" //에디터 전역에서 사용
            });
        }
    }
}