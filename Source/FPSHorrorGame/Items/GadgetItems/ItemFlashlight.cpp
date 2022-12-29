// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemFlashlight.h"

void AItemFlashlight::BeginPlay()
{
	Super::BeginPlay();
	DeactivateGadget();
}

void AItemFlashlight::Use()
{
	
}

void AItemFlashlight::ActivateGadget()
{
	Super::ActivateGadget();
	SetActorHiddenInGame(false);
	SetActorTickEnabled(true);
	UE_LOG(LogTemp, Warning, TEXT("Gadget activated!"));
	
}

void AItemFlashlight::DeactivateGadget()
{
	Super::DeactivateGadget();
	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
	UE_LOG(LogTemp, Warning, TEXT("Gadget deactivated!"));	
}

