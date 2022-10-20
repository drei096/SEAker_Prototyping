// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ActorPoolable.h"
#include "Components/ActorComponent.h"
#include "PoolManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTPROJECT_API UPoolManager : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPoolManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void Initialize();
	bool HasObjectsAvailable(int requestSize);
	int GetMaxPoolSize();
	AActorPoolable* RequestPoolable();
	TArray<AActorPoolable*> RequestPoolableBatch(int size);

	void ReleasePoolable(AActorPoolable* poolableObject);
	void ReleasePoolableBatch(TArray<AActorPoolable*> objectList);
	void ReleasePoolableBatch(int count);

private:
	UPROPERTY(EditAnywhere) int maxPoolSize = 20;
	UPROPERTY(EditAnywhere) AActorPoolable* actorCopy = nullptr;
	UPROPERTY(EditAnywhere) AActor* parent = nullptr;

	TArray<AActorPoolable*> availableObjects;
	TArray<AActorPoolable*> usedObjects;
};
