// Fill out your copyright notice in the Description page of Project Settings.


#include "AVFileOperations.h"
#include "Engine/DataTable.h"
#include "FPSHorrorGame/Items/BaseItem.h"
#include "CoreTypes.h"

const static FString ITEMS_JSON_PATH = "/Json/Items.json";
const static FString ITEMS_JSON_STARTER = " {\"AllItems\": ";;
const static FString ITEMS_JSON_END = " } ";
const static FString ITEMS_JSON_ALL_ITEMS_NAME = "AllItems";


UAVFileOperations::UAVFileOperations()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> ItemsData(TEXT("/Game/DataTables/DT_Items"));
	if (ItemsData.Object)
		DTItems = ItemsData.Object;
}

void UAVFileOperations::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UAVFileOperations::Deinitialize()
{
	Super::Deinitialize();
	
}

void UAVFileOperations::Test()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(
			-1,
			15.f,
			FColor::Red,
			FString(TEXT("Subsystem func is working!"))
		);
	}
}

void UAVFileOperations::SaveToJson() const
{
	if (DTItems)
	{
		UE_LOG(LogTemp, Warning, TEXT("SAVED!"));
		FString ItemsInJsonFormat = DTItems->GetTableAsJSON(EDataTableExportFlags::UseSimpleText);
		FString JsonCombined;
		
		JsonCombined.Append(ITEMS_JSON_STARTER);
		JsonCombined.Append(ItemsInJsonFormat);
		JsonCombined.Append(ITEMS_JSON_END);
		FFileHelper::SaveStringToFile(*JsonCombined,*(FPaths::ProjectContentDir() + ITEMS_JSON_PATH));
	}
}

void UAVFileOperations::LoadFromJson() const
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
				ItemProperties.ItemType = StringToEnumItemConversation[JsonValueObject->GetStringField(TEXT("ItemType"))];

				UE_LOG(LogTemp, Warning, TEXT("%s"), *UEnum::GetValueAsString(ItemProperties.ItemType));
			}
		}
	}
}
