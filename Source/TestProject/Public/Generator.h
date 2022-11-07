// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StructsHandler.h"
#include "GameFramework/Actor.h"
#include "Generator.generated.h"

UCLASS()
class TESTPROJECT_API AGenerator : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGenerator();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void zonesToLoad();
	void tileMapGeneration();

	UPROPERTY(EditAnywhere)
	TEnumAsByte<BiomeName> biome;

	UPROPERTY(EditAnywhere)
	FGeneratedLevelVariables variables;

	UPROPERTY(EditAnywhere)
	TArray<FMiniZones> miniZones;
	
private:
	//TOPLEFT -- TOPRIGHT -- BOTTOMLEFT -- BOTTOMRIGHT
	TArray<FVector4f> tileVertex;
};
