// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Almanac.h"
#include "MPAttribs.h"
#include "AAnimalAttrib.h"
#include "SEAker_GameInstance.h"
#include "Engine/TriggerVolume.h"
#include "SpawnListManager.h"
#include "Kismet/GameplayStatics.h"

#include "FishCharacter.generated.h"

UCLASS()
class TESTPROJECT_API AFishCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFishCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
		float SPEED_MULTIPLIER = 1.0;

	UPROPERTY(EditAnywhere)
		float SENSITIVITY_MULTIPLIER = 0.3;

	UPROPERTY(EditAnywhere)
		float GRAVITY_SCALE_MULTIPLIER = 1.0;

	// Handles input for moving forward and backward.
	UFUNCTION()
		void MoveForward(float Value);

	// Handles input for moving right and left.
	UFUNCTION()
		void MoveRight(float Value);


	UFUNCTION()
		void AddYawInput(float Value);

	UFUNCTION()
		void AddPitchInput(float Value);

	UFUNCTION()
		void SetGravityScale(float Value);

	UFUNCTION()
		void SetCollisionCapsuleHalfHeight(float Value);

	UFUNCTION()
		void SetCollisionCapsuleRadius(float Value);

protected:
	UPROPERTY(BlueprintReadWrite) FVector2D crossHairScreenLoc;
	UPROPERTY(BlueprintReadWrite) bool canInteract = false;
	UPROPERTY(BlueprintReadWrite) AActor* collidedActor = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite) AActor* Actor_spawnListManager = nullptr;

private:
	//PlayerCreatureType currentPlayerCreatureType = PlayerCreatureType::CRAB;

	FVector latestCameraLoc;
	FVector latestWorldDirection;
	FVector latestWorldPoint;

	USEAker_GameInstance* currentGameInstance = nullptr;
	UMPAttribs* MPAttribs = nullptr;
	USpawnListManager* spawnListManager = nullptr;

private:
	bool GetRayHitLocation();
	bool GetWorldPoint();
	void InteractWithFish();
	void SetUpCharacterValues(PlayerCreatureType type);

	//FOR SWITCH TESTING
	void switchAnimal();

public:
	bool willSwitch = false;
};


