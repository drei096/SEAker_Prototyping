// Fill out your copyright notice in the Description page of Project Settings.


#include "Almanac.h"

Almanac::Almanac()
{
}

Almanac::~Almanac()
{
}

void Almanac::addToDictionary(FishName fish)
{
	FishInfo* info = &fishDictionary.Add(fish);
	info->fish = fish;
	info->fishName = UEnum::GetValueAsString(fish);
	info->isCollected = false;
}

void Almanac::tickCollected(FishName fish)
{
	fishDictionary[fish].isCollected = true;
}

TMap<FishName, FishInfo>* Almanac::getDictionaryRef()
{
	return &fishDictionary;
}
