// Fill out your copyright notice in the Description page of Project Settings.


#include "FileExporterLibrary.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFilemanager.h"

// Create an empty file or write initial data to it
bool UFileExporterLibrary::CreateFile(const FString& FilePath)
{
    return FFileHelper::SaveStringToFile(TEXT(""), *FilePath); // Create an empty file
}

// valid a file exist 
bool UFileExporterLibrary::FileExists(const FString& FilePath)
{
    return FPlatformFileManager::Get().GetPlatformFile().FileExists(*FilePath);
}

// Append data to an existing file
bool UFileExporterLibrary::AppendToFile(const FString& FilePath, const FString& Data, bool appendEnter)
{
    FString DataToWrite = Data;

    // If appendEnter is true, add a newline character
    if (appendEnter)
    {
        DataToWrite += TEXT("\n");
    }
    return FFileHelper::SaveStringToFile(DataToWrite, *FilePath, FFileHelper::EEncodingOptions::AutoDetect, &IFileManager::Get(), FILEWRITE_Append);
}

// Delete a file
bool UFileExporterLibrary::DeleteFile(const FString& FilePath)
{
    return FPlatformFileManager::Get().GetPlatformFile().DeleteFile(*FilePath);
}
