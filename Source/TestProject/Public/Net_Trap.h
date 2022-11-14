// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ATrap.h"
#include "Net_Trap.generated.h"

/**
 * 
 */
UCLASS()
class TESTPROJECT_API ANet_Trap : public AATrap
{
	GENERATED_BODY()

public:
	virtual bool ReactToTrigger(AActor* other) override;

};
