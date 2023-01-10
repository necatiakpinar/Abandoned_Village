
#pragma once

UENUM(BlueprintType)
enum class EItemTypes  : uint8
{
	IT_Flashlight UMETA(DisplayName = "Flashlight"),
	IT_Camera UMETA(DisplayName = "Camera"),
	IT_Battery UMETA(DisplayName = "Battery"),
	
	IT_MAX UMETA(DisplayName  = "DefaultMAX")
};

inline TMap<FString,EItemTypes> StringToEnumItemConversation =
	{
		{"IT_Flashlight",EItemTypes::IT_Flashlight},
		{"IT_Camera",EItemTypes::IT_Camera},
		{"IT_Battery",EItemTypes::IT_Battery}
	};

