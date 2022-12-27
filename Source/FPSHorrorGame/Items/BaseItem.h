// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseItem.generated.h"

UCLASS()
class FPSHORRORGAME_API ABaseItem : public AActor
{
	GENERATED_BODY()
	
public:	
	ABaseItem();

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class UStaticMeshComponent* MeshComponent;
	
protected:
	virtual void BeginPlay() override;
	
};
