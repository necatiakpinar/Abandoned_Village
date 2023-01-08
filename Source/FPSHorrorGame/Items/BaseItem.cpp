// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseItem.h"

#include "AssetRegistry/AssetRegistryModule.h"
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
	// ItemProperties = DTItemProperties->FindRow<FItemProperties>(*FString("Flashlight"),NULL);
	// if (ItemProperties)
	// {	
	// 	FString TableJson = DTItemProperties->GetTableAsJSON(EDataTableExportFlags::UseSimpleText);
	// 	UE_LOG(LogTemp, Warning, TEXT("Entered!"));
	// 	UE_LOG(LogTemp, Warning, TEXT("%s"),*TableJson);
	// }

	// if (DTItemProperties == nullptr)
	// {
	// 	
	// 	//UE_LOG(LogTemp, Warning, TEXT("%d"),*(FPaths::ProjectContentDir() + TEXT("/Json/Items.json")));
	//
	// 	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	//
	// 	FSoftObjectPath Path("/Game/Blueprints/Character/Player_BP");
	// 	const FAssetData assetData = AssetRegistryModule.Get().GetAssetByObjectPath(Path);
	//
	// 	//UE_LOG(LogTemp, Warning, TEXT("%s"), *Cast<UDataTable>(AssetData[1].GetAsset())->GetName());	
	//
	// 	UE_LOG(LogTemp,Warning, TEXT("%s"), AssetRegistryModule.Get().IsLoadingAssets() ? "1" : "0");
	// 	if (assetData.GetAsset())
	// 	{
	// 		UObject* assetObject = assetData.GetAsset();
	// 		if (assetObject)
	// 		{
	// 			UE_LOG(LogTemp, Warning, TEXT("DATA COLLECTED!"));
	// 		}
	// 		else
	// 		{
	// 			UE_LOG(LogTemp, Warning, TEXT("ASSET EXIST BUT NOT FULL"));
	// 		}
	// 	}
	// 	else
	// 	{
	// 		UE_LOG(LogTemp, Warning, TEXT("ASSET IS NOT EXIST"));
	// 	}
	// 	
	// }

}


