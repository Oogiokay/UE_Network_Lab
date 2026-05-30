// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DataIOFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UE_NETWORK_LAB_API UDataIOFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	static bool LoadStringFromFile(FString FileName, FString& LoadedString);

	//UTexture2D because I need 1 of the outputs to be a texture file for the material.
	UFUNCTION(BlueprintCallable)
	static UTexture2D* LoadAsciiTexture(const FString& FilePath, int32 Width, int32 Height, TArray<int32>& CharacterSummation);

	static uint8 CharToValue(TCHAR Character);
};
