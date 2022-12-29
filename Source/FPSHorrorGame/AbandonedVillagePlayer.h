// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseGameCharacter.h"
#include "AbandonedVillagePlayer.generated.h"

/**
 * 
 */
UCLASS()
class FPSHORRORGAME_API AAbandonedVillagePlayer : public ABaseGameCharacter
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	class USpringArmComponent* SprintArmComponent;
	
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	class UCameraComponent* CameraComponent;

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class TSubclassOf<class AGadgetItem> GadgetItemBP;

private:
	AGadgetItem* GadgetItem;
	class UInventoryComponent* InventoryComponentImplemented; //All of the components has blueprint reference, therefore add Implemented to the end.

public:
	AAbandonedVillagePlayer();
	virtual void Tick(float DeltaTime) override;
	void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void JumpAction();
	void ToggleGadget();
	
protected:
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;
	
};