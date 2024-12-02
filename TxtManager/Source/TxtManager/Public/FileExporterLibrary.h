// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FileExporterLibrary.generated.h"

/**
 * 
 */
UCLASS()
class TXTMANAGER_API UFileExporterLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
    // Create a file (empty or with initial content)
    UFUNCTION(BlueprintCallable, Category = "File Exporter")
    static bool CreateFile(const FString& FilePath);

    // Create a file (empty or with initial content)
    UFUNCTION(BlueprintCallable, Category = "File Exporter")
    static bool FileExists(const FString& FilePath);

    // Append data to an existing file
    UFUNCTION(BlueprintCallable, Category = "File Exporter")
    static bool AppendToFile(const FString& FilePath, const FString& Data, bool appendEnter);

    // Delete a file
    UFUNCTION(BlueprintCallable, Category = "File Exporter")
    static bool DeleteFile(const FString& FilePath);
};
