// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CoreTypes.h"
#include "AVFileOperations.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class FPSHORRORGAME_API UAVFileOperations : public UGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UDataTable* DTItems;
	//TArray<class FItemProperties> AllItemProperties;
	//TArray<uint8> numberArr;

public:
	UAVFileOperations();
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;
	
	void Test();
	void SaveToJson() const;
	void LoadFromJson() const;
	
};
