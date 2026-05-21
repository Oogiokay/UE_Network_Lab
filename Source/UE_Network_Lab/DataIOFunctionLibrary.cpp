// Fill out your copyright notice in the Description page of Project Settings.


#include "DataIOFunctionLibrary.h"

bool UDataIOFunctionLibrary::LoadStringFromFile(FString FileName, FString& LoadedString) {
    // Use ProjectContentDir() to target the Content folder
    FString FullFilePath = FPaths::Combine(FPaths::ProjectContentDir(), FileName);

    bool bSuccess = FFileHelper::LoadFileToString(LoadedString, *FullFilePath);

    if (bSuccess) {
        UE_LOG(LogTemp, Log, TEXT("Success: %s"), *FullFilePath);
    }
    else {
        UE_LOG(LogTemp, Warning, TEXT("Failed: %s"), *FullFilePath);
    }

    return bSuccess;
}