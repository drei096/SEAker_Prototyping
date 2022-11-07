// Fill out your copyright notice in the Description page of Project Settings.


#include "FishCharacter.h"
#include "AAnimalAttrib.h"

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
	almanac = new Almanac();
}

// Called every frame
void AFishCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	bool hasHit = GetRayHitLocation();
	if (hasHit)
	{
		//UE_LOG(LogTemp, Display, TEXT("HIT!!!"));
		if (GetWorldPoint())
		{
			UE_LOG(LogTemp, Display, TEXT("FISH DETECTED!!!"));
		}
	}


	//UE_LOG(LogTemp, Display, TEXT("Fish1 is collected: %s"), almanac->getFishInfo(FISH1).isCollected ? TEXT("true") : TEXT("false"));
	//UE_LOG(LogTemp, Display, TEXT("Fish2 is collected: %s"), almanac->getFishInfo(FISH2).isCollected ? TEXT("true") : TEXT("false"));
	//UE_LOG(LogTemp, Display, TEXT("Fish3 is collected: %s"), almanac->getFishInfo(FISH3).isCollected ? TEXT("true") : TEXT("false"));
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

bool AFishCharacter::GetRayHitLocation()
{
	APlayerController* PC = GetWorld()->GetFirstPlayerController();
	
	if (PC != nullptr)
	{
		bool hasHit = PC->DeprojectScreenPositionToWorld(crossHairScreenLoc.X, crossHairScreenLoc.Y, latestCameraLoc, latestWorldDirection);
		return hasHit;
	}
	else
	{
		return false;
	}
}

bool AFishCharacter::GetWorldPoint()
{
	FHitResult hitResult;
	FVector startLoc = latestCameraLoc;
	FVector endLoc = startLoc + (latestWorldDirection * 50000000.0f);

	bool result = GetWorld()->LineTraceSingleByChannel(hitResult, startLoc, endLoc, ECollisionChannel::ECC_Visibility);

	//DrawDebugLine(GetWorld(), startLoc, endLoc, FColor::Red, false, 5.0f, 0, 5.0f);

	if(hitResult.GetActor() != nullptr && hitResult.GetActor()->ActorHasTag("Fish"))
	{
		UAAnimalAttrib* animalAttrib = hitResult.GetActor()->FindComponentByClass<UAAnimalAttrib>();
		almanac->tickCollected(animalAttrib->getID());
		return true;
	}

	latestWorldPoint = hitResult.Location;
	latestWorldPoint.Z += 100.0f;
	
	return false; 
}
