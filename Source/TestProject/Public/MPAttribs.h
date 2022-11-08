// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FishSchool.h"
#include "MPAttribs.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTPROJECT_API UMPAttribs : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMPAttribs();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FishSchool* getFishSchool();

private:
	FishSchool* fishSchool = nullptr;
	float speed = 1.0f;
	float FOV = 90.0f;
};
