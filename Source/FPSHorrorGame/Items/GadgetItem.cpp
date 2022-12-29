// Fill out your copyright notice in the Description page of Project Settings.


#include "GadgetItem.h"


void AGadgetItem::ActivateGadget()
{
	isActivated = true;
}

void AGadgetItem::DeactivateGadget()
{
	isActivated = false;
}

void AGadgetItem::Equip()
{
	Super::Equip();
	UE_LOG(LogTemp, Warning, TEXT("Gadget Equipped!"));
}
