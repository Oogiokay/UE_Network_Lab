// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE_Network_Lab : ModuleRules
{
	public UE_Network_Lab(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
