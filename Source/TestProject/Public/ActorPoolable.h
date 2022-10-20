// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/StaticMeshActor.h"
#include "ActorPoolable.generated.h"

UCLASS()
class TESTPROJECT_API AActorPoolable : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AActorPoolable();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// initializes the property of this object
	virtual void OnInitialize();
	// throws this evenet when this object has been released
	virtual void OnRelease();
	// throws this event when this object has been activated
	virtual void OnActivate();

	void SetIndex(int i);
	int GetIndex();
	void SetParent(AActor* Parent);
	void ReturnPositionToParent();

private:
	AActor* parent = nullptr;
	int index = -1;
};
