// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPSHorrorGame/Items/GadgetItem.h"
#include "ItemFlashlight.generated.h"

/**
 * 
 */
UCLASS()
class FPSHORRORGAME_API AItemFlashlight : public AGadgetItem
{
	GENERATED_BODY()

public:
	AItemFlashlight();
	virtual void Use() override;
	void ActivateGadget() override;
	void DeactivateGadget() override;

protected:
	virtual void BeginPlay() override;
};
