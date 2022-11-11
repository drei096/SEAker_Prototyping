// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StructsHandler.h"
#include "ActorRandomGenerator.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTPROJECT_API UActorRandomGenerator : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UActorRandomGenerator();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray <FGeneratedData> toGenerateList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray <AActor*> toIgnoreList;

	void GenerateActors(FGeneratedData generatedData);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
