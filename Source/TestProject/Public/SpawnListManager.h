// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AIFishCharacter.h"
#include "SEAker_GameInstance.h"
#include "Kismet/GameplayStatics.h"

//maybe? include each class of fish/creature here?
#include "Clownfish.h"


#include "SpawnListManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTPROJECT_API USpawnListManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpawnListManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	bool check_if_fishMap_completed();

public:
	TMap <FishName, AAIFishCharacter*> getFishMap();

private:
	TMap <FishName, AAIFishCharacter*> fishMap;
	UPROPERTY(EditAnywhere) AClownfish* fishCopy = nullptr;
	UPROPERTY(EditAnywhere) AClownfish* fishCopy2 = nullptr;

private:
	void initializeFishMap();
	USEAker_GameInstance* currentGameInstance = nullptr;
};
