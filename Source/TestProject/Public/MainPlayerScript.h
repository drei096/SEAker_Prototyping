// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "SEAker_GameInstance.h"
#include "Kismet/GameplayStatics.h"

//maybe? include each class of fish/creature here?
#include "CrabCharacter.h"
#include "TurtleCharacter.h"

#include "MainPlayerScript.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTPROJECT_API UMainPlayerScript : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMainPlayerScript();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	// SWITCHABLE CHARACTERS
	UPROPERTY(EditAnywhere) ACrabCharacter* CrabCharacter = nullptr;
	UPROPERTY(EditAnywhere) ATurtleCharacter* TurtleCharacter = nullptr;

	// CURRENT CHARACTER
	AFishCharacter* currentCharacter = nullptr;
};
