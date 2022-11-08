// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnumsHandler.h"
#include "StructsHandler.h"

/**
 * 
 */
class TESTPROJECT_API FishSchool
{
public:
	FishSchool();
	~FishSchool();

	void addCreatureToSchool(FishName fish);

private:
	TMap<FishName, FFish_Profile> collectedCreatureMap;
};
