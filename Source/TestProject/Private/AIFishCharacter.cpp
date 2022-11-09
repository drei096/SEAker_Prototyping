// Fill out your copyright notice in the Description page of Project Settings.


#include "AIFishCharacter.h"

// Sets default values
AAIFishCharacter::AAIFishCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAIFishCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAIFishCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAIFishCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

ATriggerVolume* AAIFishCharacter::getFishTriggerBox()
{
	return fishTriggerBox;
}

