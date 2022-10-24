// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnumsHandler.generated.h"

UENUM(BlueprintType,Category="FishName")
enum FishName
{
	FISH1 = 0,
	FISH2,
	FISH3
};

/**
 * 
 */
class TESTPROJECT_API EnumsHandler
{
public:
	EnumsHandler();
	~EnumsHandler();
};
