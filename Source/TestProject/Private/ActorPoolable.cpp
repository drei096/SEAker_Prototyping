// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorPoolable.h"

// Sets default values
AActorPoolable::AActorPoolable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AActorPoolable::BeginPlay()
{
	Super::BeginPlay();

	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
	FindComponentByClass<UPrimitiveComponent>()->SetSimulatePhysics(false);
}

// Called every frame
void AActorPoolable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AActorPoolable::OnInitialize()
{
}

void AActorPoolable::OnRelease()
{
	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
	FindComponentByClass<UPrimitiveComponent>()->SetSimulatePhysics(false);
	ReturnPositionToParent();
}

void AActorPoolable::OnActivate()
{
	SetActorHiddenInGame(false);
	SetActorTickEnabled(true);
	FindComponentByClass<UPrimitiveComponent>()->SetSimulatePhysics(true);
}

void AActorPoolable::SetIndex(int i)
{
	index = i;
}

int AActorPoolable::GetIndex()
{
	return index;
}

void AActorPoolable::SetParent(AActor* Parent)
{
	parent = Parent;
}

void AActorPoolable::ReturnPositionToParent()
{
	FVector parentLocation = parent->GetActorLocation();
	FRotator parentRotation = parent->GetActorRotation();
	SetActorLocationAndRotation(parentLocation, parentRotation);
}

