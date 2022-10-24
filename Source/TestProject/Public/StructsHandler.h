// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnumsHandler.h"
#include "StructsHandler.generated.h"

USTRUCT(BlueprintType)
struct FishInfo
{
	GENERATED_BODY();

	TEnumAsByte<FishName> fish;
	FString fishName;
	bool isCollected = false;
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
