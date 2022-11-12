// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerScript.h"

#include "GameFramework/GameModeBase.h"

// Sets default values for this component's properties
UMainPlayerScript::UMainPlayerScript()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMainPlayerScript::BeginPlay()
{
	Super::BeginPlay();

	// ...
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *UGameplayStatics::GetGameMode(this->GetWorld())->DefaultPawnClass->GetName());

	currentCharacter = (AFishCharacter*) UGameplayStatics::GetPlayerPawn(this->GetWorld(), 0);
	currentCharacterLocation = currentCharacter->GetActorLocation();

	UE_LOG(LogTemp, Warning, TEXT("%s"), *currentCharacter->GetName());
}


// Called every frame
void UMainPlayerScript::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	if(currentCharacter->willSwitch)
	{
		currentCharacter->GetController()->Possess(this->ClownfishCharacter);
		currentCharacter = (AFishCharacter*)UGameplayStatics::GetPlayerPawn(this->GetWorld(), 0);

		currentCharacter->SetActorLocation(currentCharacterLocation);
		currentCharacterLocation = currentCharacter->GetActorLocation();

		UE_LOG(LogTemp, Warning, TEXT("%s"), *currentCharacter->GetName());
		currentCharacter->willSwitch = false;
	}
}

