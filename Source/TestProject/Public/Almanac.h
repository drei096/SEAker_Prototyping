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

public:
	void addToDictionary(FishName fish);
	void addToDictionary(BiomeName biome);
	void addToDictionary(PollutionType pollution);

	void removeFromDictionary(FishName fish);
	void removeFromDictionary(BiomeName biome);
	void removeFromDictionary(PollutionType pollution);

public:
	FFish_Profile getFishInfo(FishName fish);
	FBiome_Profile getBiomeInfo(BiomeName biome);
	FPollution_Profile getPollutionInfo(PollutionType pollution);

	void tickCollected(FishName fish);

public:
	TMap<FishName, FFish_Profile>* getFishDictionaryRef();
	TMap<BiomeName, FBiome_Profile>* getBiomeDictionaryRef();
	TMap<PollutionType, FPollution_Profile>* getPollutionDictionaryRef();

private:
	TMap<FishName, FFish_Profile> fishDictionary;
	TMap<BiomeName, FBiome_Profile> biomeDictionary;
	TMap<PollutionType, FPollution_Profile> pollutionDictionary;


};
