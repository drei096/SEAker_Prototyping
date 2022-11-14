// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ReactToTriggerInterface.h"
#include "EnumsHandler.h"

#include "ATrap.generated.h"

UCLASS()
class TESTPROJECT_API AATrap : public AActor, public IReactToTriggerInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AATrap();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
