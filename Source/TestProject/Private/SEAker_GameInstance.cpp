// Fill out your copyright notice in the Description page of Project Settings.


#include "SEAker_GameInstance.h"

bool USEAker_GameInstance::CreateAlmanac()
{
	almanac = new Almanac();
	if (almanac)
		return true;

	return false;
}
