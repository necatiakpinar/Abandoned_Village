// Fill out your copyright notice in the Description page of Project Settings.


#include "AbandonedVillagePlayer.h"

#include "ActorComponents/InventoryComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Items/GadgetItem.h"

AAbandonedVillagePlayer::AAbandonedVillagePlayer()
{
	SprintArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SprintArmComponent"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));
	
	SprintArmComponent->SetupAttachment(GetCapsuleComponent());
	CameraComponent->SetupAttachment(SprintArmComponent);

	SprintArmComponent->TargetArmLength = 5.f;

}

void AAbandonedVillagePlayer::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	InventoryComponentImplemented = FindComponentByClass<UInventoryComponent>();
}


void AAbandonedVillagePlayer::BeginPlay()
{
	Super::BeginPlay();
	FActorSpawnParameters ActorSpawnParameters = FActorSpawnParameters();
	ActorSpawnParameters.Owner = this;
	GadgetItem = GetWorld()->SpawnActor<AGadgetItem>(GadgetItemBP,GetActorLocation(),GetActorRotation(),ActorSpawnParameters);
	if (GadgetItem)
	{
		GadgetItem->Equip();
		FAttachmentTransformRules AttachmentRules = FAttachmentTransformRules(EAttachmentRule::SnapToTarget,
			EAttachmentRule::SnapToTarget,
			EAttachmentRule::KeepRelative,
			false);
		GadgetItem->AttachToComponent(GetMesh(), AttachmentRules ,FName("Hand_R_Socket"));
	}
}

void AAbandonedVillagePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAbandonedVillagePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Jump"),IE_Pressed,this,&AAbandonedVillagePlayer::JumpAction);
	PlayerInputComponent->BindAction(TEXT("ToggleGadget"),IE_Pressed, this, &AAbandonedVillagePlayer::ToggleGadget);
	
	
	PlayerInputComponent->BindAxis(TEXT("MoveForward"),this,&AAbandonedVillagePlayer::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"),this,&AAbandonedVillagePlayer::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"),this,&AAbandonedVillagePlayer::Turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"),this,&AAbandonedVillagePlayer::LookUp);
	
}

void AAbandonedVillagePlayer::MoveForward(float Value)
{
	if (Controller != nullptr && Value != 0.f)
	{
		const FRotator YawRotation(0.f,Controller->GetControlRotation().Yaw,0.f);
		const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X));
		AddMovementInput(Direction, Value);
	}
}

void AAbandonedVillagePlayer::MoveRight(float Value)
{
	const FRotator YawRotation(0.f,Controller->GetControlRotation().Yaw,0.f);
	const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y));
	AddMovementInput(Direction, Value);
}

void AAbandonedVillagePlayer::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void AAbandonedVillagePlayer::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void AAbandonedVillagePlayer::JumpAction()
{
	if (GetMovementComponent()->CanEverJump())
	{
		Jump();
	}
}

void AAbandonedVillagePlayer::ToggleGadget()
{
	if (GadgetItem->IsActivated())
		GadgetItem->DeactivateGadget();
	else
		GadgetItem->ActivateGadget();
}

