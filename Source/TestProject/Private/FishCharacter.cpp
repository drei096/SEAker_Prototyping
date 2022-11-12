// Fill out your copyright notice in the Description page of Project Settings.

#include "FishCharacter.h"

#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


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

	// Set up components
	currentGameInstance = (USEAker_GameInstance*) GetGameInstance();
	currentGameInstance->CreateAlmanac();

	if (FindComponentByClass<UMPAttribs>() != nullptr)
		MPAttribs = FindComponentByClass<UMPAttribs>();
	
	spawnListManager = Actor_spawnListManager->FindComponentByClass<USpawnListManager>();

	// Set up values
	//SetUpCharacterValues(this->currentPlayerCreatureType);
}

// Called every frame
void AFishCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*
	 * TRIGGER VOLUME METHOD
	*/
	

	//UE_LOG(LogTemp, Warning, TEXT("%s"), canInteract ? TEXT("true") : TEXT("false"));



	
	/*
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
	
	*/
}

// Called to bind functionality to input
void AFishCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up "movement" bindings.
	PlayerInputComponent->BindAxis("MoveForward", this, &AFishCharacter::MoveForward);

	if(canStrafe)
		PlayerInputComponent->BindAxis("MoveRight", this, &AFishCharacter::MoveRight);

	// Set up mouse look bindings
	PlayerInputComponent->BindAxis("Turn", this, &AFishCharacter::AddYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AFishCharacter::AddPitchInput);

	// Set up action bindings
	PlayerInputComponent->BindAction("Interact", EInputEvent::IE_Pressed, this, &AFishCharacter::InteractWithFish);
	PlayerInputComponent->BindAction("FOR_TESTING-Switch", EInputEvent::IE_Pressed, this, &AFishCharacter::switchAnimal);
}

void AFishCharacter::switchAnimal()
{
	//this->GetController()->Possess((APawn*)MainPlayerScript->TurtleCharacter);
	this->willSwitch = true;
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

void AFishCharacter::SetGravityScale(float Value)
{
	this->FindComponentByClass<UCharacterMovementComponent>()->GravityScale = Value;
}

void AFishCharacter::SetCollisionCapsuleHalfHeight(float Value)
{
	this->FindComponentByClass<UCapsuleComponent>()->SetCapsuleHalfHeight(Value);
}

void AFishCharacter::SetCollisionCapsuleRadius(float Value)
{
	this->FindComponentByClass<UCapsuleComponent>()->SetCapsuleRadius(Value);
}

void AFishCharacter::InteractWithFish()
{
	if(canInteract == true)
	{
		//UE_LOG(LogTemp, Warning, TEXT("WORKING"));
		//UE_LOG(LogTemp, Warning, TEXT("%s"), *collidedActor->GetName());
		UAAnimalAttrib* animalAttrib = collidedActor->FindComponentByClass<UAAnimalAttrib>();
		currentGameInstance->almanac->tickCollected(animalAttrib->getID());
		currentGameInstance->almanac->ELastFishInteracted = animalAttrib->getID();
		spawnListManager->check_if_fishMap_completed();
	}
	
}

void AFishCharacter::SetUpCharacterValues(PlayerCreatureType type)
{
	/* NOTE:
	 * DEFAULT VALUES ARE SET AT
	 *
	 * SPEED = 1.0F
	 * SENSITIVITY = 0.3F
	 * GRAVITY SCALE = 1.0F
	 * CAPSULE HALF HEIGHT = 88.0F
	 * CAPSULE RADIUS = 34.0F
	*/

	/*
	switch(type)
	{
	case PlayerCreatureType::CRAB:
		this->SPEED_MULTIPLIER = 2.5f;
		this->SENSITIVITY_MULTIPLIER = 0.3f;
		this->SetGravityScale(10000.0f);
		this->SetCollisionCapsuleRadius(0.01f);
		this->SetCollisionCapsuleHalfHeight(0.01f);
		
		break;
	}
	*/
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
		UE_LOG(LogTemp, Warning, TEXT("%s"), *hitResult.GetActor()->GetName());

		UAAnimalAttrib* animalAttrib = hitResult.GetActor()->FindComponentByClass<UAAnimalAttrib>();
		currentGameInstance->almanac->tickCollected(animalAttrib->getID());
		
		return true;
	}

	latestWorldPoint = hitResult.Location;
	latestWorldPoint.Z += 100.0f;
	
	return false; 
}
