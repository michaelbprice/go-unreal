using UnrealBuildTool;
using System.IO;

public class GoImpl: ModuleRules
{
    public GoImpl(ReadOnlyTargetRules Target) : base(Target)
    {
        PrivateDependencyModuleNames.AddRange(new string[] {"Core", "CoreUObject", "Engine"});

        // Path to Thirdparty/go-cpp
        string ThirdPartyPath = Path.Combine(ModuleDirectory, "..", "..", "Thirdparty", "go-cpp");
        string GoCppIncludePath = Path.Combine(ThirdPartyPath, "include");
        string GoCppLibPath = Path.Combine(ThirdPartyPath, "lib");

        PublicIncludePaths.Add(GoCppIncludePath);

        // Link Release build of go-cpp
        string ReleaseLibName = "goimpl.lib"; // Adjust if the library name differs
        PublicAdditionalLibraries.Add(Path.Combine(GoCppLibPath, "Release", ReleaseLibName));
    }
}
