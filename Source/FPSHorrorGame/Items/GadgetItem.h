// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EquippableItem.h"
#include "GadgetItem.generated.h"

UCLASS()
class FPSHORRORGAME_API AGadgetItem : public AEquippableItem
{
	GENERATED_BODY()

public:
	virtual void Use() PURE_VIRTUAL(,)
	virtual void Equip() override;
};
