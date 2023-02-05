// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Damagable.generated.h"

/**
 * 
 */
UINTERFACE(MinimalAPI, Blueprintable)
class UDamagable : public UInterface
{
	GENERATED_BODY()
};

class IDamagable
{    
	GENERATED_BODY()

public:
	/** Add interface function declarations here */
	virtual void TakeDamage(float DamageAmount)  PURE_VIRTUAL(,);
};