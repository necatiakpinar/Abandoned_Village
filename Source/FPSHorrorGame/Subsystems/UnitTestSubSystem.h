// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "UnitTestSubSystem.generated.h"

/**
 * 
 */
UCLASS()
class FPSHORRORGAME_API UUnitTestSubSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	void Test();
};
