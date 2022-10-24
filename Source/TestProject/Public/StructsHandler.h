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


/**
 * 
 */
class TESTPROJECT_API StructsHandler
{
public:
	StructsHandler();
	~StructsHandler();
};
