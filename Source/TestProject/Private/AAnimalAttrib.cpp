// Fill out your copyright notice in the Description page of Project Settings.


#include "AAnimalAttrib.h"

// Sets default values for this component's properties
UAAnimalAttrib::UAAnimalAttrib()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAAnimalAttrib::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UAAnimalAttrib::setID(FishName fID)
{
	this->fishID = fID;
}


// Called every frame
void UAAnimalAttrib::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FishName UAAnimalAttrib::getID()
{
	return this->fishID;
}

