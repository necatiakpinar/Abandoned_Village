// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "Engine/DataTable.h"
#include "JsonObjectConverter.h"
#include "FPSHorrorGame/GameInstances/AbandonedVillageGameInstance.h"
#include "FPSHorrorGame/Subsystems/AVFileOperations.h"
#include "FPSHorrorGame/Subsystems/UnitTestSubSystem.h"
#include "Kismet/GameplayStatics.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	UAVFileOperations* FileOperations;
	if (GetWorld()->GetGameInstance())
	{
		UE_LOG(LogTemp, Warning, TEXT("Game Instance available!"));
		FileOperations = Cast<UAVFileOperations>(GetWorld()->GetGameInstance()->GetSubsystem<UAVFileOperations>());
		if (FileOperations)
		{
			FileOperations->SaveItemToJson();
			FileOperations->LoadItemsFromJson();
		}
		
	}
	
		
}

void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
