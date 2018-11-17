// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"


ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (!GetControlledTank()) 
	{
		UE_LOG(LogTemp, Error, TEXT("Tank controlled by player not found"));
	}
	else
	{
		FString TankName = GetControlledTank()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("The Tank Controlled by the player is %s"), *TankName);
	}
}
