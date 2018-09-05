using UnrealBuildTool;

public class HoudiniPlus : ModuleRules
{
	public HoudiniPlus(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				"HoudiniPlus/Public"
			});

		PrivateIncludePaths.AddRange(
			new string[] {
				"HoudiniPlus/Private",
			});

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
                "AssetTools",
                "EditorStyle",
			    "ContentBrowser",
                "Core",
			    "CoreUObject",
                "Landscape",
                "PropertyEditor",
			    "Slate",
			    "SlateCore",
				
				"HoudiniEngineRuntime",
                "HoudiniEngineEditor"
			});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
                "AssetTools",
                "ContentBrowser",
                "Core",
			    "CoreUObject",
                "Engine",
			    "EditorStyle",
                "InputCore",
			    "LandscapeEditor",
			    "LevelEditor",
                "Projects",
                "PropertyEditor",
			    "Slate",
			    "SlateCore",
                "UnrealEd"
			});

	    PrivateDependencyModuleNames.AddRange(PublicDependencyModuleNames);

		DynamicallyLoadedModuleNames.AddRange(new string[]{});
	}
}
