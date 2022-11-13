// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnumsHandler.h"
#include "StructsHandler.generated.h"

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

USTRUCT(BlueprintType)
struct FGeneratedData
{
	GENERATED_BODY();

	UPROPERTY(EditAnywhere)
	FString actorName = "ObjectName";
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AActor> actorPrefab;
	UPROPERTY(EditAnywhere)
	TEnumAsByte<ActorType> actorType = OBJECT;

	//Raycast Setting
	UPROPERTY(EditAnywhere)
	int density = 1;
	UPROPERTY(EditAnywhere)
	float maxHeight = -1;
	UPROPERTY(EditAnywhere)
	float minHeight = -1000;
	UPROPERTY(EditAnywhere)
	FVector2f xRange = FVector2f(-1,1);
	UPROPERTY(EditAnywhere)
	FVector2f zRange = FVector2f(-1, 1);

	//Object Setting
	UPROPERTY(EditAnywhere)
	FVector2f rotationRange;
	UPROPERTY(EditAnywhere)
	FVector3f minScale = FVector3f(1, 1, 1);
	UPROPERTY(EditAnywhere)
	FVector3f maxScale = FVector3f(1, 1, 1);
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
