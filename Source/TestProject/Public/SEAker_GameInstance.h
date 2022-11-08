// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Almanac.h"
#include "SEAker_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class TESTPROJECT_API USEAker_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable) bool CreateAlmanac();



public:
	Almanac* almanac;

};
