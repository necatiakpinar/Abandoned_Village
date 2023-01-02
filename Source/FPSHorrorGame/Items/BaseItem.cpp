// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseItem.h"

#include "Components/BoxComponent.h"
#include "Engine/DataTable.h"
#include "FPSHorrorGame/GameInstances/AbandonedVillageGameInstance.h"

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
	ItemProperties = DTItemProperties->FindRow<FItemProperties>(*FString("Flashlight"),NULL);
	if (ItemProperties)
	{	
		FString TableJson = DTItemProperties->GetTableAsJSON(EDataTableExportFlags::UseSimpleText);
		UE_LOG(LogTemp, Warning, TEXT("Entered!"));
		UE_LOG(LogTemp, Warning, TEXT("%s"),*TableJson);
	}
}


