// Fill out your copyright notice in the Description page of Project Settings.


#include "ActorRandomGenerator.h"

// Sets default values for this component's properties
UActorRandomGenerator::UActorRandomGenerator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UActorRandomGenerator::GenerateActors(FGeneratedData generatedData)
{
	for (int i = 0; i < generatedData.density; i++) 
	{

		const static FName Tag = TEXT("TankTraceTag");
		GetWorld()->DebugDrawTraceTag = Tag;
		FCollisionQueryParams Params(Tag);


		FHitResult hitResult;
		float sampleX = FMath::RandRange(generatedData.xRange.X, generatedData.xRange.Y);
		float sampleY = FMath::RandRange(generatedData.zRange.X, generatedData.zRange.Y);
		FVector rayStart = FVector(sampleX, sampleY, generatedData.maxHeight);

		if (!GetWorld()->LineTraceSingleByChannel(hitResult, rayStart, FVector(rayStart.X, rayStart.Y, generatedData.minHeight), ECollisionChannel::ECC_Visibility, Params)) {
			UE_LOG(LogTemp, Display, TEXT("Hit"));
			continue;
		}

		if (hitResult.TraceEnd.Y < generatedData.minHeight)
			continue;

		AActor* tempRef = GetWorld()->SpawnActor<AActor>(generatedData.actorPrefab);
		tempRef->SetActorLocation(hitResult.TraceEnd);
		tempRef->SetActorScale3D(FVector3d(
			FMath::RandRange(generatedData.minScale.X, generatedData.maxScale.X),
			FMath::RandRange(generatedData.minScale.Y, generatedData.maxScale.Y),
			FMath::RandRange(generatedData.minScale.Z, generatedData.maxScale.Z)));

		UE_LOG(LogTemp, Display, TEXT("X : %f, Y : %f, Z: %f"), hitResult.TraceEnd.X, hitResult.TraceEnd.Y, hitResult.TraceEnd.Z);
	}
	
}

// Called when the game starts
void UActorRandomGenerator::BeginPlay()
{
	Super::BeginPlay();

	// ...
	for (int i = 0; i < toGenerateList.Num(); i++)
		GenerateActors(toGenerateList[i]);

	
}


// Called every frame
void UActorRandomGenerator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

