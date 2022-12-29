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
	FORCEINLINE bool IsActivated() { return isActivated;}
private:
	bool isActivated;
public:
	virtual void Use() PURE_VIRTUAL(,)
	virtual void ActivateGadget();
	virtual void DeactivateGadget();
	virtual void Equip() override;
};
