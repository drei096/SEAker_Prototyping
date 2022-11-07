// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnumsHandler.h"
#include "StructsHandler.generated.h"

USTRUCT(BlueprintType)
struct FGeneratedData
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere)
		FString actorName;
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AActor> actorPrefab;

	//Raycast Setting
	UPROPERTY(EditAnywhere)
		int density;
	UPROPERTY(EditAnywhere)
		float maxHeight;
	UPROPERTY(EditAnywhere)
		float minHeight;
	UPROPERTY(EditAnywhere)
		FVector2f xRange;
	UPROPERTY(EditAnywhere)
		FVector2f zRange;

	//Object Setting
	UPROPERTY(EditAnywhere)
		FVector2f rotationRange;
	UPROPERTY(EditAnywhere)
		FVector3f minScale;
	UPROPERTY(EditAnywhere)
		FVector3f maxScale;
};

USTRUCT(BlueprintType)
struct FMiniZones 
{
	GENERATED_BODY();


	UPROPERTY(EditAnywhere)
	FString zoneName;

	UPROPERTY(EditAnywhere);
	TArray<FGeneratedData> objectsToGenerate;
};

USTRUCT(BlueprintType)
struct FGeneratedLevelVariables 
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere)
		int tilingSize[2];
	UPROPERTY(EditAnywhere)
		FVector3f minScale;
	UPROPERTY(EditAnywhere)
		FVector3f maxScale;
	UPROPERTY(EditAnywhere)
		float spacing;
};

USTRUCT(BlueprintType)
struct FFish_Profile
{
	GENERATED_BODY();

	FString fishName;
	FString description;
	bool isCollected = false;
};

USTRUCT(BlueprintType)
struct FBiome_Profile
{
	GENERATED_BODY();

	FString biomeName;
	FString description;
};

USTRUCT(BlueprintType)
struct FPollution_Profile
{
	GENERATED_BODY();

	FString pollutionName;
	FString description;
};


/**
 * 
 */
class TESTPROJECT_API StructsHandler
{
public:
	StructsHandler();
	~StructsHandler();
};
