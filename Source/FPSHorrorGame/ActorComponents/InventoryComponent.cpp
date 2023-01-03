// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "Engine/DataTable.h"
#include "JsonObjectConverter.h"
#include "FPSHorrorGame/GameInstances/AbandonedVillageGameInstance.h"

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UInventoryComponent::OnRegister()
{
	Super::OnRegister();
#if PLATFORM_WINDOWS
	UE_LOG(LogTemp, Warning, TEXT("ON REGISTER WORKED!"));
#endif
	
	//SaveToJson();
	
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

void UInventoryComponent::SaveToJson()
{
	if (DTItems)
	{
		//DTItems->FindRow<FItemProperties>("Flashlight", NULL)->Definition = "LOKKA";
		FString ItemsInJsonFormat = DTItems->GetTableAsJSON(EDataTableExportFlags::UseSimpleText);
		FFileHelper::SaveStringToFile(*ItemsInJsonFormat,*(FPaths::ProjectContentDir() + TEXT("/Json/Items.json")));
	}
}

void UInventoryComponent::LoadFromJson()
{
	FString ItemsInJsonFormat;
	FFileHelper::LoadFileToString(ItemsInJsonFormat, *(FPaths::ProjectContentDir() + TEXT("/Json/Items.json")));

	DTItems->FindRow<FItemProperties>("Flashlight", NULL)->Definition = "LOKKA";
//	DTItems->load(ItemsInJsonFormat);
	
	//
	// TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(ItemsInJsonFormat);
	// TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject());
	//
	// if (FJsonSerializer::Deserialize(JsonReader, JsonObject) &&  JsonObject.IsValid())
	// {
	// 	DTItems->CreateTableFromJSONString(ItemsInJsonFormat);
	// 	SaveToJson();
	// 	
	// }
}

