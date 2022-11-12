// Fill out your copyright notice in the Description page of Project Settings.


#include "SEAker_GM_cpp.h"

ASEAker_GM_cpp::ASEAker_GM_cpp()
{
	PrimaryActorTick.bCanEverTick = false;
	PrimaryActorTick.bStartWithTickEnabled = false;
	PrimaryActorTick.bAllowTickOnDedicatedServer = false;

	//maybe assign the default pawn here depending on the level?
	this->DefaultPawnClass = ATurtleCharacter::StaticClass();
}

ASEAker_GM_cpp::~ASEAker_GM_cpp()
{
}
