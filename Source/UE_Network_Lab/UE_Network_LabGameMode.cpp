// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE_Network_LabGameMode.h"
#include "UE_Network_LabCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE_Network_LabGameMode::AUE_Network_LabGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
