using UnrealBuildTool;
using System;
using System.IO;

public class HoudiniPlusEditor : ModuleRules
{
    private string GetHFSPath()
    {
        string HoudiniVersion = "16.5.587";
        bool bIsRelease = true;
        string HFSPath = "";
        string Log;

        if (!bIsRelease)
        {
            // Only use the preset build folder
            Console.WriteLine("Using HFS:" + HFSPath);
            return HFSPath;
        }

        // Look for the Houdini install folder for this platform
        PlatformID BuildPlatformId = Environment.OSVersion.Platform;
        if (BuildPlatformId == PlatformID.Win32NT)
        {
            // Look for the HEngine install path in the registry
            var HEngineRegistry = string.Format(@"HKEY_LOCAL_MACHINE\SOFTWARE\Side Effects Software\Houdini Engine {0}", HoudiniVersion);
            var HPath = Microsoft.Win32.Registry.GetValue(HEngineRegistry, "InstallPath", null) as string;
            if (HPath != null)
            {
                Log = string.Format("Houdini Engine : Looking for Houdini Engine {0} in {1}", HoudiniVersion, HPath);
                Console.WriteLine(Log);
                if (Directory.Exists(HPath))
                    return HPath;
            }

            // If we couldn't find the Houdini Engine registry path, try the default one
            string DefaultHPath = "C:/Program Files/Side Effects Software/Houdini Engine " + HoudiniVersion;
            if (DefaultHPath != HPath)
            {
                Log = string.Format("Houdini Engine : Looking for Houdini Engine {0} in {1}", HoudiniVersion, DefaultHPath);
                Console.WriteLine(Log);
                if (Directory.Exists(DefaultHPath))
                    return DefaultHPath;
            }

            // Look for the Houdini registry install path for the version the plug-in was compiled for
            var HoudiniRegistry = string.Format(@"HKEY_LOCAL_MACHINE\SOFTWARE\Side Effects Software\Houdini {0}", HoudiniVersion);
            HPath = Microsoft.Win32.Registry.GetValue(HoudiniRegistry, "InstallPath", null) as string;
            if (HPath != null)
            {
                Log = string.Format("Houdini Engine : Looking for Houdini {0} in {1}", HoudiniVersion, HPath);
                Console.WriteLine(Log);
                if (Directory.Exists(HPath))
                    return HPath;
            }

            // If we couldn't find the Houdini registry path, try the default one
            DefaultHPath = "C:/Program Files/Side Effects Software/Houdini " + HoudiniVersion;
            if (DefaultHPath != HPath)
            {
                Log = string.Format("Houdini Engine : Looking for Houdini {0} in {1}", HoudiniVersion, DefaultHPath);
                Console.WriteLine(Log);
                if (Directory.Exists(DefaultHPath))
                    return DefaultHPath;
            }

            // See if the preset build HFS exists
            if (Directory.Exists(HFSPath))
                return HFSPath;

            Log = string.Format("Houdini Engine : Failed to find Houdini {0}, will attempt to build using the latest installed version", HoudiniVersion);
            Console.WriteLine(Log);

            // We couldn't find the exact version the plug-in was built for, we can still try with the active version in the registry
            HEngineRegistry = "HKEY_LOCAL_MACHINE\\SOFTWARE\\Side Effects Software";
            string ActiveHEngine = Microsoft.Win32.Registry.GetValue(HEngineRegistry, "ActiveEngineVersion", null) as string;
            if (ActiveHEngine != null)
            {
                // See if the latest active HEngine version has the proper major/minor version
                if (ActiveHEngine.Substring(0, 4) == HoudiniVersion.Substring(0, 4))
                {
                    Log = string.Format("Houdini Engine : Found Active Houdini Engine version: {0}", ActiveHEngine);
                    Console.WriteLine(Log);

                    HEngineRegistry = string.Format(@"HKEY_LOCAL_MACHINE\SOFTWARE\Side Effects Software\Houdini Engine {0}", ActiveHEngine);
                    HPath = Microsoft.Win32.Registry.GetValue(HEngineRegistry, "InstallPath", null) as string;
                    if (HPath != null)
                    {
                        Log = string.Format("Houdini Engine : Looking for Houdini Engine {0} in {1}", ActiveHEngine, HPath);
                        Console.WriteLine(Log);
                        if (Directory.Exists(HPath))
                            return HPath;
                    }
                }
            }

            // Active HEngine version didn't match, so try with the active Houdini version
            HoudiniRegistry = "HKEY_LOCAL_MACHINE\\SOFTWARE\\Side Effects Software";
            var ActiveHoudini = Microsoft.Win32.Registry.GetValue(HoudiniRegistry, "ActiveVersion", null) as string;
            if (ActiveHoudini != null)
            {
                // See if the latest active Houdini version has the proper major/minor version
                if (ActiveHoudini.Substring(0, 4) == HoudiniVersion.Substring(0, 4))
                {
                    Log = string.Format("Houdini Engine : Found Active Houdini version: {0}", ActiveHoudini);
                    Console.WriteLine(Log);

                    HoudiniRegistry = string.Format(@"HKEY_LOCAL_MACHINE\SOFTWARE\Side Effects Software\Houdini {0}", ActiveHoudini);
                    HPath = Microsoft.Win32.Registry.GetValue(HoudiniRegistry, "InstallPath", null) as string;
                    if (HPath != null)
                    {
                        Log = string.Format("Houdini Engine : Looking for Houdini {0} in {1}", ActiveHoudini, HPath);
                        Console.WriteLine(Log);

                        if (Directory.Exists(HPath))
                            return HPath;
                    }
                }
            }
        }
        else if (BuildPlatformId == PlatformID.MacOSX)
        {
            // Check for Houdini installation.
            var HPath = "/Applications/Houdini/Houdini" + HoudiniVersion + "/Frameworks/Houdini.framework/Versions/Current/Resources";
            if (Directory.Exists(HPath))
                return HPath;

            if (Directory.Exists(HFSPath))
                return HFSPath;
        }
        else if (BuildPlatformId == PlatformID.Unix)
        {
            HFSPath = System.Environment.GetEnvironmentVariable("HFS");
            if (Directory.Exists(HFSPath))
            {
                Console.WriteLine("Linux - found HFS:" + HFSPath);
                return HFSPath;
            }
        }
        else
            Console.WriteLine(string.Format("Building on an unknown environment!"));

        var Error = string.Format("Houdini Engine : Please install Houdini or Houdini Engine {0}", HoudiniVersion);
        Console.WriteLine(Error);

        return string.Empty;
    }

    public HoudiniPlusEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseSharedPCHs;

	    // Check if we are compiling on unsupported platforms.
	    if (Target.Platform != UnrealTargetPlatform.Win64 &&
	        Target.Platform != UnrealTargetPlatform.Mac &&
	        Target.Platform != UnrealTargetPlatform.Linux &&
	        Target.Platform != UnrealTargetPlatform.Switch)
	    {
	        Console.WriteLine(string.Format("Houdini Engine : Compiling on untested platform.  Please let us know how it goes!"));
	    }

	    // Find HFS
	    var HFSPath = GetHFSPath();
	    HFSPath = HFSPath.Replace("\\", "/");

	    if (!string.IsNullOrEmpty(HFSPath))
	    {
	        var Log = string.Format("Houdini Engine : Found Houdini in {0}", HFSPath);
	        Console.WriteLine(Log);

	        var BuildPlatformId = Environment.OSVersion.Platform;
	        if (BuildPlatformId == PlatformID.Win32NT)
	            PublicDefinitions.Add("HOUDINI_ENGINE_HFS_PATH_DEFINE=" + HFSPath);
	    }

        // Find the HAPI include directory
        var HAPIIncludePath = HFSPath + "/toolkit/include";
        if (!Directory.Exists(HAPIIncludePath))
        {
            // Add the custom include path as well in case the toolkit path doesn't exist yet.
            HAPIIncludePath = HFSPath + "/custom/houdini/include";

            if (!Directory.Exists(HAPIIncludePath))
            {
                Console.WriteLine(string.Format("Couldn't find the HAPI include folder!"));
                HAPIIncludePath = string.Empty;
            }
        }

        if (!string.IsNullOrEmpty(HAPIIncludePath))
            PublicIncludePaths.Add(HAPIIncludePath);

        // Get the plugin path
        var PluginPath = Path.Combine(ModuleDirectory, "../../");
        PluginPath = Utils.MakePathRelativeTo(PluginPath, Target.RelativeEnginePath);

        PublicIncludePaths.AddRange(
			new string[] {
				"HoudiniPlusEditor/Public"
			});

		PrivateIncludePaths.AddRange(
			new string[] {
				"HoudiniPlusEditor/Private",
			});

        PrivateIncludePathModuleNames.AddRange(
            new string[] {
                "PlacementMode"
            });
        
        PublicDependencyModuleNames.AddRange(
			new string[]
			{
                "Core",
                "CoreUObject",
                "Engine",
                "Foliage",
                "InputCore",
                "Landscape",
                "RenderCore",
                "RHI",
                "ShaderCore",

                "Slate",
                "SlateCore",
			});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
                "AppFramework",
                "ApplicationCore",
                "AssetTools",
                "ContentBrowser",
                "DesktopWidgets",
                "EditorStyle",
                "EditorWidgets",
                "LevelEditor",
                "MainFrame",
                "Projects",
                "PropertyEditor",
                "RawMesh",
                "Settings",
                "Slate",
                "SlateCore",
                "TargetPlatform",
                "UnrealEd",
			});

		DynamicallyLoadedModuleNames.AddRange(
            new string[]{
                "PlacementMode"
            });
	}
}