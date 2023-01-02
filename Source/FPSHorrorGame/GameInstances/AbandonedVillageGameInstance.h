// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/GameInstance.h"
#include "AbandonedVillageGameInstance.generated.h"

USTRUCT(BlueprintType)
struct FItemProperties : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Definition;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bHasCollected;
	
};

/**
 * 
 */
UCLASS()
class FPSHORRORGAME_API UAbandonedVillageGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
};
