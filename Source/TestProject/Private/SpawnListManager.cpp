// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnListManager.h"

// Sets default values for this component's properties
USpawnListManager::USpawnListManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	
}


// Called when the game starts
void USpawnListManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	initializeFishList();
	
}


// Called every frame
void USpawnListManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	
}

TArray <FishName> USpawnListManager::getFishList()
{
	return fishList;
}

void USpawnListManager::initializeFishList()
{
	/*
	 * ADDS FISH ENUMS TO THE FISH LIST
	 */

	fishList.Add(FISH1);
	fishList.Add(FISH2);
	fishList.Add(FISH3);
}

