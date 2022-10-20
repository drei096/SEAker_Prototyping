// Fill out your copyright notice in the Description page of Project Settings.


#include "FishCharacter.h"

// Sets default values
AFishCharacter::AFishCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->AutoPossessPlayer = EAutoReceiveInput::Player0;
	this->AutoReceiveInput = EAutoReceiveInput::Player0;

}

// Called when the game starts or when spawned
void AFishCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFishCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFishCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up "movement" bindings.
	PlayerInputComponent->BindAxis("MoveForward", this, &AFishCharacter::MoveForward);
	//PlayerInputComponent->BindAxis("MoveRight", this, &AFishCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &AFishCharacter::AddYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AFishCharacter::AddPitchInput);
	
}

void AFishCharacter::MoveForward(float Value)
{
	// Find out which way is "forward" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value * SPEED_MULTIPLIER);
}

void AFishCharacter::MoveRight(float Value)
{
	// Find out which way is "right" and record that the player wants to move that way.
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value * SPEED_MULTIPLIER);
}

void AFishCharacter::AddYawInput(float Value)
{
	if (Value != 0.f && Controller && Controller->IsLocalPlayerController())
	{
		APlayerController* const PC = CastChecked<APlayerController>(Controller);
		PC->AddYawInput(Value * SENSITIVITY_MULTIPLIER);
	}

}

void AFishCharacter::AddPitchInput(float Value)
{
	if (Value != 0.f && Controller && Controller->IsLocalPlayerController())
	{
		APlayerController* const PC = CastChecked<APlayerController>(Controller);
		PC->AddPitchInput(Value * SENSITIVITY_MULTIPLIER);
	}

}
