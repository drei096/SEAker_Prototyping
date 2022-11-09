// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnumsHandler.h"
#include "StructsHandler.h"
#include "AAnimalAttrib.h"
#include "Engine/TriggerVolume.h"
#include "AIFishCharacter.generated.h"

UCLASS()
class TESTPROJECT_API AAIFishCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAIFishCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	virtual ATriggerVolume* getFishTriggerBox();

private:
	ATriggerVolume* fishTriggerBox = nullptr;

protected:
	UAAnimalAttrib* animalAttrib = nullptr;

};
