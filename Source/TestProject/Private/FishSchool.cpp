// Fill out your copyright notice in the Description page of Project Settings.


#include "FishSchool.h"

FishSchool::FishSchool()
{
}

FishSchool::~FishSchool()
{
}

void FishSchool::addCreatureToSchool(FishName fish)
{
	FFish_Profile* info = &collectedCreatureMap.Add(fish);
	info->fishName = UEnum::GetValueAsString(fish);
	info->isCollected = true;

	
	UE_LOG(LogTemp, Warning, TEXT("%s"), *info->fishName)
}
