using UnrealBuildTool;
using System;
using System.IO;
using System.Text;
using System.Collections.Generic;
using System.Text.RegularExpressions;

public class Happy : ModuleRules
{
    public struct FunctionSignature
    {
        public string Description;
        public string Name;
        public List<string> Parameters;

        public string GetParameterString()
        {
            return string.Join(", ", Parameters.ToArray()).Trim(',');
        }
    }

    private List<FunctionSignature> GetFunctionsInHeader(string IncludeFile)
    {
        var Contents = File.ReadAllText(IncludeFile);

        var EmptyLineRegex = new Regex(@"^\s*$", RegexOptions.Multiline);
        var Split = EmptyLineRegex.Split(Contents);

        var Result = new List<FunctionSignature>();

        foreach (var S in Split)
        {
            var FunctionSignature = new FunctionSignature();
            var Fragment = S.Trim();

            if (Fragment.StartsWith("///"))
            {
                var FunctionRegex = new Regex(@"HAPI_DECL\s(?<Name>.*)\((?<Parameters>[\S\s]+)\);", RegexOptions.Multiline);
                var Match = FunctionRegex.Match(Fragment);
                if (!Match.Success)
                    continue;

                FunctionSignature.Description = Fragment.Substring(0, Match.Index);

                foreach (Group Group in Match.Groups)
                {
                    if (Group.Name == "Name")
                        FunctionSignature.Name = Group.Captures[0].Value.Trim().Remove(0, 5);

                    if (Group.Name == "Parameters")
                    {
                        FunctionSignature.Parameters = new List<string>();

                        var ParametersSplit = Group.Captures[0].Value.Split(',');
                        foreach(var Parameter in ParametersSplit)
                        {
                            FunctionSignature.Parameters.Add(Parameter.Trim());
                        }
                    }
                }

                Result.Add(FunctionSignature);
            }
        }

        return Result;
    }

    private string GenerateAPIHeader(List<FunctionSignature> Functions)
    {
        var HeaderTemplate = new StringBuilder();

        HeaderTemplate.AppendLine("#pragma once;");
        HeaderTemplate.AppendLine();
        HeaderTemplate.AppendLine("#include \"HAPI/HAPI.h\"");
        HeaderTemplate.AppendLine("#include \"HAL/PlatformProcess.h\"");
        HeaderTemplate.AppendLine();
        HeaderTemplate.AppendLine("struct HAPPY_API FHoudiniApi");
        HeaderTemplate.AppendLine("{");
        HeaderTemplate.AppendLine("public:");
        HeaderTemplate.AppendLine("\tstatic void Bind(void* Handle);");
        HeaderTemplate.AppendLine("\tstatic void Unbind();");
        HeaderTemplate.AppendLine("\tstatic bool IsValid();");

        HeaderTemplate.AppendLine();
        HeaderTemplate.AppendLine("public:");
        foreach(var Function in Functions)
            HeaderTemplate.AppendFormat("   typedef HAPI_Result (*{0}FuncPtr)({1});{2}", Function.Name, Function.GetParameterString(), Environment.NewLine);
        
        HeaderTemplate.AppendLine();
        HeaderTemplate.AppendLine("public:");
        foreach (var Function in Functions)
            HeaderTemplate.AppendFormat("   static {0}FuncPtr {0};{1}", Function.Name, Environment.NewLine);
        
        HeaderTemplate.AppendLine();
        HeaderTemplate.AppendLine("public:");
        foreach (var Function in Functions)
            HeaderTemplate.AppendFormat("   static HAPI_Result {0}EmptyStub({1});{2}", Function.Name, Function.GetParameterString(), Environment.NewLine);

        HeaderTemplate.AppendLine("};");

        return HeaderTemplate.ToString();
    }

    private string GenerateAPICPP(List<FunctionSignature> Functions)
    {
        var CPPTemplate = new StringBuilder();

        CPPTemplate.AppendLine("#include \"HappyPrivatePCH.h\"");
        CPPTemplate.AppendLine("#include \"HoudiniAPI.h\"");
        CPPTemplate.AppendLine();

        foreach (var Function in Functions)
        {
            CPPTemplate.AppendFormat("FHoudiniApi::{0}FuncPtr FHoudiniApi::{0} = &FHoudiniApi::{0}EmptyStub;{1}", Function.Name, Environment.NewLine);
            CPPTemplate.AppendLine();
        }
        
        CPPTemplate.AppendLine("void FHoudiniApi::Bind(void* Handle)");
        CPPTemplate.AppendLine("{");
        CPPTemplate.AppendLine("    ensure(Handle);");
        CPPTemplate.AppendLine();

        foreach (var Function in Functions)
            CPPTemplate.AppendFormat("  FHoudiniApi::{0} = ({0}FuncPtr)FPlatformProcess::GetDllExport(Handle, TEXT(\"HAPI_{0}\"));{1}", Function.Name, Environment.NewLine);
        
        CPPTemplate.AppendLine("}");

        CPPTemplate.AppendLine();
        
        CPPTemplate.AppendLine("void FHoudiniApi::Unbind()");
        CPPTemplate.AppendLine("{");

        foreach (var Function in Functions)
            CPPTemplate.AppendFormat("  FHoudiniApi::{0} = &FHoudiniApi::{0}EmptyStub;{1}", Function.Name, Environment.NewLine);

        CPPTemplate.AppendLine("}");

        CPPTemplate.AppendLine();

        foreach (var Function in Functions)
        {
            CPPTemplate.AppendFormat("HAPI_Result FHoudiniApi::{0}EmptyStub({1}){2}", Function.Name, Function.GetParameterString(), Environment.NewLine);
            CPPTemplate.AppendLine("{");
            CPPTemplate.AppendLine("    return HAPI_RESULT_FAILURE;");
            CPPTemplate.AppendLine("}");
            CPPTemplate.AppendLine();
        }
        
        return CPPTemplate.ToString();
    }

    private void GenerateAPI(string IncludePath, string OutputRoot)
    {
        if (!Directory.Exists(IncludePath))
            throw new Exception("IncludePath not found.");

        if (!Directory.Exists(OutputRoot))
            throw new Exception("OutputRoot not found.");

        var HeaderPath = Path.Combine(OutputRoot, "Public", "HoudiniAPI.h");
        var CPPPath = Path.Combine(OutputRoot, "Private", "HoudiniAPI.cpp");

        var Functions = GetFunctionsInHeader(Path.Combine(IncludePath, "HAPI", "HAPI.h"));

        File.WriteAllText(HeaderPath, GenerateAPIHeader(Functions));
        File.WriteAllText(CPPPath, GenerateAPICPP(Functions));
    }

    private string GetLibFolder()
    {
        PlatformID BuildPlatformId = Environment.OSVersion.Platform;
        if (BuildPlatformId == PlatformID.Win32NT)
            return "bin";
        else if (BuildPlatformId == PlatformID.MacOSX)
            return "dsolib";
        else if (BuildPlatformId == PlatformID.Unix)
            return "dsolib";

        return string.Empty;
    }

    private string GetLibName()
    {
        PlatformID BuildPlatformId = Environment.OSVersion.Platform;
        if (BuildPlatformId == PlatformID.Win32NT)
            return "libHAPIL.dll";
        else if (BuildPlatformId == PlatformID.MacOSX)
            return "libHAPIL.dylib";
        else if (BuildPlatformId == PlatformID.Unix)
            return "libHAPIL.so";

        return string.Empty;
    }

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

    public Happy(ReadOnlyTargetRules Target) : base(Target)
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
                throw new Exception(string.Format("Couldn't find the HAPI include folder!"));
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
				"Happy/Public"
			});

		PrivateIncludePaths.AddRange(
			new string[] {
				"Happy/Private",
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
				
                "Slate",
                "SlateCore",
			});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
                "UnrealEd",
			});

		DynamicallyLoadedModuleNames.AddRange(
            new string[]{
                "PlacementMode"
            });

        var HAPILibPath = Path.Combine(HFSPath, GetLibFolder(), GetLibName());
        HAPILibPath = HAPILibPath.Replace("\\", "/");
        if(!File.Exists(HAPILibPath))
            throw new Exception(string.Format("Couldn't find the HAPI lib!"));
        else
        {
            PublicDefinitions.Add("HAPI_LIB_PATH=" + HAPILibPath);
            PublicDelayLoadDLLs.Add(GetLibName());
            RuntimeDependencies.Add(HAPILibPath);
        }

        GenerateAPI(HAPIIncludePath, ModuleDirectory);
	}
}