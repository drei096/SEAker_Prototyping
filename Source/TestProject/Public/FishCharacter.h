// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Almanac.h"
#include "MPAttribs.h"
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

protected:
	UPROPERTY(BlueprintReadWrite) FVector2D crossHairScreenLoc;

private:
	FVector latestCameraLoc;
	FVector latestWorldDirection;
	FVector latestWorldPoint;


	bool GetRayHitLocation();
	bool GetWorldPoint();


	Almanac* almanac;
	UMPAttribs* MPAttribs = nullptr;
};
