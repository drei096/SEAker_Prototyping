// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StructsHandler.h"

/**
 * 
 */
class TESTPROJECT_API Almanac
{
public:
	Almanac();
	~Almanac();

	void addToDictionary(FishName fish);
	void tickCollected(FishName fish);
	TMap<FishName, FishInfo>* getDictionaryRef();

private:
	TMap<FishName, FishInfo> fishDictionary;


};
