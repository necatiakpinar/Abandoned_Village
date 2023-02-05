// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGameCharacter.h"

#include "Kismet/GameplayStatics.h"
#include "Subsystems/AVFileOperations.h"

// Sets default values
ABaseGameCharacter::ABaseGameCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ABaseGameCharacter::BeginPlay()
{
	Super::BeginPlay();
	CanAttack = true;
}

// Called every frame
void ABaseGameCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseGameCharacter::TakeDamage(float DamageAmount)
{
	Health -= DamageAmount;
	if (Health <= 0)
		Destroy();
	
}

void ABaseGameCharacter::Attack(AActor* TargetEntity)
{
	if (CanAttack)
	{
		IDamagable* DamagableEntity = Cast<IDamagable>(TargetEntity);
		if (DamagableEntity != nullptr)
			DamagableEntity->TakeDamage(this->AttackPower);

		CanAttack = false;
		
		//Start timer for new attack
		if (GetWorld() != nullptr) 
			GetWorld()->GetTimerManager().SetTimer(CombatTimerHandle, this, &ABaseGameCharacter::EnableCombat, AttackSpeed, true, AttackSpeed);
	}
}

void ABaseGameCharacter::EnableCombat()
{
	GetWorld()->GetTimerManager().ClearTimer(CombatTimerHandle);
	CanAttack = true;
}


