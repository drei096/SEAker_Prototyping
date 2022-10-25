// Fill out your copyright notice in the Description page of Project Settings.


#include "Almanac.h"

Almanac::Almanac()
{
	addToDictionary(FISH1);
	addToDictionary(FISH2);
	addToDictionary(FISH3);
}

Almanac::~Almanac()
{
}

void Almanac::addToDictionary(FishName fish)
{
	FFish_Profile* info = &fishDictionary.Add(fish);
	info->fishName = UEnum::GetValueAsString(fish);
	info->isCollected = false;
}

void Almanac::addToDictionary(BiomeName biome)
{
	FBiome_Profile* info = &biomeDictionary.Add(biome);
	info->biomeName = UEnum::GetValueAsString(biome);
}

void Almanac::addToDictionary(PollutionType pollution)
{
	FPollution_Profile* info = &pollutionDictionary.Add(pollution);
	info->pollutionName = UEnum::GetValueAsString(pollution);
}

void Almanac::removeFromDictionary(FishName fish)
{
	fishDictionary.Remove(fish);
}

void Almanac::removeFromDictionary(BiomeName biome)
{
	biomeDictionary.Remove(biome);
}

void Almanac::removeFromDictionary(PollutionType pollution)
{
	pollutionDictionary.Remove(pollution);
}

FFish_Profile Almanac::getFishInfo(FishName fish)
{
	return fishDictionary[fish];
}

FBiome_Profile Almanac::getBiomeInfo(BiomeName biome)
{
	return biomeDictionary[biome];
}

FPollution_Profile Almanac::getPollutionInfo(PollutionType pollution)
{
	return pollutionDictionary[pollution];
}

void Almanac::tickCollected(FishName fish)
{
	fishDictionary[fish].isCollected = true;
}

TMap<FishName, FFish_Profile>* Almanac::getFishDictionaryRef()
{
	return &fishDictionary;
}

TMap<BiomeName, FBiome_Profile>* Almanac::getBiomeDictionaryRef()
{
	return &biomeDictionary;
}

TMap<PollutionType, FPollution_Profile>* Almanac::getPollutionDictionaryRef()
{
	return &pollutionDictionary;
}
