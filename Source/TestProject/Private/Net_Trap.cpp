// Fill out your copyright notice in the Description page of Project Settings.


#include "Net_Trap.h"

bool ANet_Trap::ReactToTrigger(AActor* other)
{
	if(other->ActorHasTag("MainPlayer"))
	{
		
	}

	return false;
}
