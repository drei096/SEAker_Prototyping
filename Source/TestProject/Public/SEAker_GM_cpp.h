// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "SEAker_GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "MainPlayerScript.h"

//maybe? include each class of fish/creature here?
#include "CrabCharacter.h"
#include "TurtleCharacter.h"
#include "SeaCucumberCharacter.h"
#include "ClownfishCharacter.h"

#include "SEAker_GM_cpp.generated.h"

/**
 * 
 */
UCLASS()
class TESTPROJECT_API ASEAker_GM_cpp : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASEAker_GM_cpp();
	~ASEAker_GM_cpp();

	virtual void BeginPlay() override;
public:
	UFUNCTION(BlueprintCallable)
	void AddAlmanacToVP();
	UFUNCTION(BlueprintCallable)
	void AddMainMenuToVP();
	UFUNCTION(BlueprintCallable)
	void AddHUDToVP();
protected:
	UPROPERTY(EditAnywhere, Category = "Class Types")
		TSubclassOf<UUserWidget> Almanac_Class;
	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class UAlmanac_UI* AlmanacWidget;
	UPROPERTY(EditAnywhere, Category = "Class Types")
		TSubclassOf<UUserWidget> MainMenu_Class;
	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class UMainMenu_UI* MainMenuWidget;
	UPROPERTY(EditAnywhere, Category = "Class Types")
		TSubclassOf<UUserWidget> HUD_Class;
	UPROPERTY(VisibleInstanceOnly, Category = "Runtime")
		class UGameScene_HUD* HUDWidget;
};
