// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseGameCharacter.h"
#include "AbandonedVillagePlayer.generated.h"

/**
 * 
 */
UCLASS()
class FPSHORRORGAME_API AAbandonedVillagePlayer : public ABaseGameCharacter
{
	GENERATED_BODY()


public:
	AAbandonedVillagePlayer();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	
};
