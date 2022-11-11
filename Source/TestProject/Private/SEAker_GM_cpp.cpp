// Fill out your copyright notice in the Description page of Project Settings.


#include "SEAker_GM_cpp.h"

ASEAker_GM_cpp::ASEAker_GM_cpp()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
	PrimaryActorTick.bAllowTickOnDedicatedServer = false;

	this->DefaultPawnClass = ACrabCharacter::StaticClass();
}

ASEAker_GM_cpp::~ASEAker_GM_cpp()
{
}
