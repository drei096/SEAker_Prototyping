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
	currentGameInstance = (USEAker_GameInstance*) this->GetOwner()->GetGameInstance();
	initializeFishMap();
}


// Called every frame
void USpawnListManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	/*
	 *REMOVE THIS IN TICK
	if(check_if_fishMap_completed() == true)
	{
		//do something
	}
	*/
	
}

TMap<FishName, AAIFishCharacter*> USpawnListManager::getFishMap()
{
	return fishMap;
}

void USpawnListManager::initializeFishMap()
{
	fishMap.Add(fishCopy->FindComponentByClass<UAAnimalAttrib>()->getID(), fishCopy);
	fishMap.Add(fishCopy2->FindComponentByClass<UAAnimalAttrib>()->getID(), fishCopy2);

	/*
	FVector spawnLocation = FVector(FMath::RandRange(-100.0f, 100.0f), 2720.000000, FMath::RandRange(50.0f, 400.0f));

	FActorSpawnParameters actorSpawnParams;
	actorSpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	actorSpawnParams.Template = this->fishCopy;
	actorSpawnParams.Owner = this->GetOwner();


	if(this->fishCopy != nullptr)
	{
		AAIFishCharacter* spawnedActor = this->GetWorld()->SpawnActor<AClownfish>(this->fishCopy->GetClass(), actorSpawnParams);
		fishMap.Add(spawnedActor->FindComponentByClass<UAAnimalAttrib>()->getID(), spawnedActor);
		spawnedActor->SetActorHiddenInGame(false);
		spawnedActor->SetActorLocation(spawnLocation);
		spawnedActor->SetActorRotation(this->fishCopy->GetActorRotation());
	}
	*/
}

bool USpawnListManager::check_if_fishMap_completed()
{
	

	if (fishMap.IsEmpty())
	{
		UE_LOG(LogTemp, Warning, TEXT("FISH MAP COMPLETED"));
		return true;
	}
	else
	{
		if ( currentGameInstance->almanac->ELastFishInteracted != FishName::NONE &&
			currentGameInstance->almanac->getFishDictionaryRef()->Find(currentGameInstance->almanac->ELastFishInteracted)->isCollected)
		{
			fishMap.FindAndRemoveChecked(currentGameInstance->almanac->ELastFishInteracted);
			UE_LOG(LogTemp, Warning, TEXT("%d"), fishMap.Num());
		}
	}
	
		

	return false;

}




