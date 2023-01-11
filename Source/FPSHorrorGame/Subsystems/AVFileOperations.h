// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CoreTypes.h"
#include "FPSHorrorGame/Enums/InventoryEnums.h"
#include "FPSHorrorGame/Items/BaseItem.h"
#include "AVFileOperations.generated.h"


UCLASS(BlueprintType)
class FPSHORRORGAME_API UAVFileOperations : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UDataTable* DTItems;
	TArray<FItemProperties> AllItemProperties;


public:
	UAVFileOperations();
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	void SaveItemToJson();
	void LoadItemsFromJson();
	struct FItemProperties GetItemProperties(EItemTypes itemType);
	
};
