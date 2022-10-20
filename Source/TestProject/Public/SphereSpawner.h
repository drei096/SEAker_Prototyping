// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PoolManager.h"
#include "Components/ActorComponent.h"
#include "SphereSpawner.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTPROJECT_API USphereSpawner : public UPoolManager
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USphereSpawner();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	float ticks = 0.0f;
	float spawn_interval = 2.0f;
		
};
