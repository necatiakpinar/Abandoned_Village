// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(Blueprintable,BlueprintSpawnableComponent) )
class FPSHORRORGAME_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInventoryComponent();
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UDataTable* DTItems;

protected:
	virtual void OnRegister() override;
	virtual void BeginPlay() override;
	
public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void SaveToJson();
	void LoadFromJson();
};
