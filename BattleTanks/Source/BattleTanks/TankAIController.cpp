// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(PlayerPawn);
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto PawnAIName = GetPawn()->GetName();
	if(!GetPlayerTank())
	{
		UE_LOG(LogTemp, Error, TEXT("No player controller found"));
	}
	else 
	{
		auto PawnPlayerName = GetPlayerTank()->GetName();
		UE_LOG(LogTemp, Warning, TEXT("Player found on %s"), *PawnPlayerName);
	}
	if(!GetControlledTank())
	{
		UE_LOG(LogTemp, Error, TEXT("No AI Controller found on %s"), *PawnAIName);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possesing %s"), *PawnAIName);
	}
}
