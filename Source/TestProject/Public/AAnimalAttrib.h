// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnumsHandler.h"
#include "AAnimalAttrib.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TESTPROJECT_API UAAnimalAttrib : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAAnimalAttrib();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
	UFUNCTION()
	void setID(FishName fID);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION()
	FishName getID();

private:
	UPROPERTY(EditAnywhere)
	TEnumAsByte<FishName> fishID;
		
};
