// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FishCharacter.h"
#include "CrabCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TESTPROJECT_API ACrabCharacter : public AFishCharacter
{
	GENERATED_BODY()

public:
	bool canStrafe = true;
};
