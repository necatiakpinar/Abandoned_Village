// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseItem.h"
#include "EquippableItem.generated.h"

/**
 * 
 */
UCLASS()
class FPSHORRORGAME_API AEquippableItem : public ABaseItem
{
	GENERATED_BODY()

public:
	virtual void Equip();
};
