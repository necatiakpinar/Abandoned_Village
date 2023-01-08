// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "Engine/DataTable.h"
#include "JsonObjectConverter.h"
#include "FPSHorrorGame/GameInstances/AbandonedVillageGameInstance.h"


const static FString ITEMS_JSON_PATH = "/Json/Items.json";
const static FString ITEMS_JSON_STARTER = " {\"AllItems\": ";;
const static FString ITEMS_JSON_END = " } ";
const static FString ITEMS_JSON_ALL_ITEMS_NAME = "AllItems";

UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	SaveToJson();
	LoadFromJson();
}

void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UInventoryComponent::SaveToJson()
{
	if (DTItems)
	{
		FString ItemsInJsonFormat = DTItems->GetTableAsJSON(EDataTableExportFlags::UseSimpleText);
		FString JsonCombined;
		
		JsonCombined.Append(ITEMS_JSON_STARTER);
		JsonCombined.Append(ItemsInJsonFormat);
		JsonCombined.Append(ITEMS_JSON_END);
		FFileHelper::SaveStringToFile(*JsonCombined,*(FPaths::ProjectContentDir() + ITEMS_JSON_PATH));
	}
}

void UInventoryComponent::LoadFromJson()
{
	FString ItemsInJsonFormat;
	FFileHelper::LoadFileToString(ItemsInJsonFormat, *(FPaths::ProjectContentDir() + ITEMS_JSON_PATH));
	
	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(ItemsInJsonFormat);
	TSharedPtr<FJsonObject> Data = MakeShareable(new FJsonObject());
	
	if (FJsonSerializer::Deserialize(Reader, Data) &&  Data.IsValid())
	{
		TArray<TSharedPtr<FJsonValue>> JsonValueArray = Data->GetArrayField(ITEMS_JSON_ALL_ITEMS_NAME);
		if (JsonValueArray.Num() > 0)
		{
			for(int32 i = 0; i < JsonValueArray.Num(); i++)
			{
				TSharedPtr<FJsonValue> JsonValue = JsonValueArray[i];
				TSharedPtr<FJsonObject> JsonValueObject = JsonValue->AsObject();
				FItemProperties ItemProperties;
				
				ItemProperties.Name = JsonValueObject->GetStringField(TEXT("Name"));
				ItemProperties.Definition = JsonValueObject->GetStringField(TEXT("Definition"));
				ItemProperties.bHasCollected = JsonValueObject->GetBoolField(TEXT("bHasCollected"));

				UE_LOG(LogTemp, Warning, TEXT("%s"), *ItemProperties.Definition);
			}
		}
		
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *ItemsInJsonFormat)
	}
	
}
