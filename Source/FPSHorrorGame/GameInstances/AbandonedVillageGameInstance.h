// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/GameInstance.h"
#include "AbandonedVillageGameInstance.generated.h"


/**
 * 
 */
UCLASS()
class FPSHORRORGAME_API UAbandonedVillageGameInstance : public UGameInstance
{
	GENERATED_BODY()
	

public:
	virtual void Init() override;
};
