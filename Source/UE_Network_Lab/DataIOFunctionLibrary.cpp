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

UTexture2D* UDataIOFunctionLibrary::LoadAsciiTexture(const FString& FilePath, int32 Width, int32 Height, TArray<int32>& CharacterSummation)
{
    FString FileContent;
    CharacterSummation.Init(0, 5);

    // Failsafe to see if the file loaded.
    if (!FFileHelper::LoadFileToString(FileContent, *FilePath))
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to load file")); 
        return nullptr;
    }


    // The transient texture.
    UTexture2D* Texture = UTexture2D::CreateTransient( Width, Height, PF_B8G8R8A8);

    

    if (!Texture)
    {
        return nullptr;
    }

    //No compression
    Texture->CompressionSettings = TC_VectorDisplacementmap;
    Texture->SRGB = false;

    FTexture2DMipMap& Mip = Texture->GetPlatformData()->Mips[0];

    void* Data = Mip.BulkData.Lock(LOCK_READ_WRITE);

    FColor* Pixels = static_cast<FColor*>(Data);

    int32 PixelIndex = 0;

    for (int32 i = 0; i < FileContent.Len(); i++)
    {
        TCHAR Character = FileContent[i];

        // Skip line breaks
        if (Character == '\n' || Character == '\r')
        {
            continue;
        }

        //Using a vector4 Im hoping to get 
        switch (Character)
        {
        case '.':
            CharacterSummation[0] += 1;
            break;

        case '#':
            CharacterSummation[1] += 1;
            break;

        case '%':
            CharacterSummation[2] += 1;
            break;

        case '"':
            CharacterSummation[3] += 1;
            break;

        default:
            break;
        }

        uint8 Value = CharToValue(Character);
        
        

        // It only needs to be grey for height map :)
        Pixels[PixelIndex] = FColor( Value, Value, Value, 255);

        PixelIndex++;

        if (PixelIndex >= Width * Height)
        {
            break;
        }
    }
    
    

    Mip.BulkData.Unlock();

    Texture->UpdateResource();

    return Texture;
}

uint8 UDataIOFunctionLibrary::CharToValue(TCHAR Character)
{
    switch (Character)
    {
    case '.':
        return 0;

    case '#':
        return 80;

    case '%':
        return 160;

    case '"':
        return 255;

    default:
        return 0;
    }
}

