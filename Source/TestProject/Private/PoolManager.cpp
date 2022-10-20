// Fill out your copyright notice in the Description page of Project Settings.


#include "PoolManager.h"

// Sets default values for this component's properties
UPoolManager::UPoolManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPoolManager::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UPoolManager::BeginDestroy()
{
	// IMPORTANT: Any lifecycle events must have super function. Or else Unreal Engine will crash
	Super::BeginDestroy();
	for (int i = 0; i < availableObjects.Num(); ++i)
	{
		availableObjects[i]->Destroy();
	}

	for (int i = 0; i < usedObjects.Num(); ++i)
	{
		usedObjects[i]->Destroy();
	}

	availableObjects.Empty();
	usedObjects.Empty();
}


// Called every frame
void UPoolManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPoolManager::Initialize()
{
	if (actorCopy == nullptr)
	{
		UE_LOG(LogTemp, Display, TEXT("Actor is NULL. Object pool not initialized"));
		return;
	}

	FActorSpawnParameters spawnParams;
	spawnParams.Template = actorCopy;
	spawnParams.Owner = GetOwner();

	const FTransform transform = actorCopy->GetActorTransform();
	for (int i = 0; i < maxPoolSize; ++i)
	{
		AActorPoolable* poolableObject = GetWorld()->SpawnActor<AActorPoolable>(actorCopy->GetClass(), spawnParams);
		poolableObject->SetIndex(i);
		poolableObject->OnInitialize();
		poolableObject->SetParent(parent);
		availableObjects.Push(poolableObject);
	}
}

bool UPoolManager::HasObjectsAvailable(int requestSize)
{
	if (availableObjects.Num() >= requestSize) return true;
	return false;
}

int UPoolManager::GetMaxPoolSize()
{
	return maxPoolSize;
}

AActorPoolable* UPoolManager::RequestPoolable()
{
	if (HasObjectsAvailable(1))
	{
		AActorPoolable* object = availableObjects.Pop();
		object->SetIndex(usedObjects.Num());
		usedObjects.Push(object);
		object->OnActivate();
		object->SetActorTransform(GetOwner()->GetActorTransform());
		//UE_LOG(LogTemp, Display, TEXT("Finished spawning: %s"), *object->GetName());
		return object;
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("No more available objects."));
		return nullptr;
	}
}

TArray<AActorPoolable*> UPoolManager::RequestPoolableBatch(int size)
{
	TArray<AActorPoolable*> objects;
	for (int i = 0; i < size && availableObjects.Num() > 0; ++i)
	{
		objects.Push(RequestPoolable());
	}

	return objects;
}

void UPoolManager::ReleasePoolable(AActorPoolable* poolableObject)
{
	poolableObject->OnRelease();
	usedObjects.Remove(poolableObject);
	availableObjects.Push(poolableObject);
}

void UPoolManager::ReleasePoolableBatch(TArray<AActorPoolable*> objectList)
{
	for (int i = 0; i < objectList.Num(); ++i)
	{
		ReleasePoolable(objectList[i]);
	}
}

void UPoolManager::ReleasePoolableBatch(int count)
{
	// terminate if pool count is not satisfied
	if (usedObjects.Num() < count) return;
	for (int i = 0; i < count; ++i)
	{
		ReleasePoolable(usedObjects[i]);
	}
}

