// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include <vector>
#include <string>
#include <unordered_map>
#include "AAnimalAttrib.h"
#include "FishCharacter.h"
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

public:
	TArray <FishName> getFishList();

private:
	TArray <FishName> fishList;

	//we could also use
	//std::unordered_map<FishName, fish data type here> fishMap;

private:
	void initializeFishList(); //or initialize fish map
	


};
