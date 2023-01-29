// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseItem.h"

#include "AssetRegistry/AssetRegistryModule.h"
#include "Components/BoxComponent.h"
#include "Engine/DataTable.h"
#include "FPSHorrorGame/GameInstances/AbandonedVillageGameInstance.h"
#include "FPSHorrorGame/Subsystems/AVFileOperations.h"
#include "Kismet/GameplayStatics.h"

ABaseItem::ABaseItem()
{
	PrimaryActorTick.bCanEverTick = true;
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

	MeshComponent->SetCollisionProfileName("NoCollision");
	MeshComponent->SetupAttachment(BoxComponent);

	SetRootComponent(BoxComponent);

}

void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
	SetItemProperties();
	
}

void ABaseItem::SetItemProperties()
{
	UAVFileOperations* FileOperations;
	if (GetWorld()->GetGameInstance())
	{
		FileOperations = Cast<UAVFileOperations>(GetWorld()->GetGameInstance()->GetSubsystem<UAVFileOperations>());
		if (FileOperations)
			ItemProperties = FileOperations->GetItemProperties(ItemType);
	}
}


