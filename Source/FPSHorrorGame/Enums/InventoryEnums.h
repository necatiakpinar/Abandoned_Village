
#pragma once

UENUM(BlueprintType)
enum class EItemTypes  : uint8
{
	IT_Flashlight UMETA(DisplayName = "Flashlight"),
	IT_Camera UMETA(DisplayName = "Camera"),
	
	IT_MAX UMETA(DisplayName  = "DefaultMAX")
};
 