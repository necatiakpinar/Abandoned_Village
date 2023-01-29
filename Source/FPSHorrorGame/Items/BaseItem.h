// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPSHorrorGame/Enums/InventoryEnums.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "BaseItem.generated.h"


USTRUCT(BlueprintType)
struct FItemProperties : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EItemTypes ItemType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Definition;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bHasCollected;
	
};

UCLASS()
class FPSHORRORGAME_API ABaseItem : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseItem();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EItemTypes ItemType;
	

private:
	FItemProperties ItemProperties;
	
public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class UStaticMeshComponent* MeshComponent;

	FORCEINLINE FItemProperties GetItemProperties() {return ItemProperties;}
protected:
	virtual void BeginPlay() override;

private:
	void SetItemProperties();
};
