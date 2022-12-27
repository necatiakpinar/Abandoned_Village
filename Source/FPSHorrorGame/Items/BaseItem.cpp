// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseItem.h"

#include "Components/BoxComponent.h"

ABaseItem::ABaseItem()
{
	PrimaryActorTick.bCanEverTick = true;
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));

	MeshComponent->SetupAttachment(BoxComponent);

	SetRootComponent(BoxComponent);
}


void ABaseItem::BeginPlay()
{
	Super::BeginPlay();
}


