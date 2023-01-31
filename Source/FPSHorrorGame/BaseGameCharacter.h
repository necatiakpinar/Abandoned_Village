// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseGameCharacter.generated.h"

UCLASS()
class FPSHORRORGAME_API ABaseGameCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Health;
	
public:
	// Sets default values for this character's properties
	ABaseGameCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FORCEINLINE uint8 GetHealth() {return Health;}

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	virtual void TakeDamage(int DamageAmount);
};
