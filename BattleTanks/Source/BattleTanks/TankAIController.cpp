// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	if (!GetControlledTank())
	{
		auto PawnAIName = GetPawn()->GetName();
		UE_LOG(LogTemp, Error, TEXT("No AI Controller found on %s"), *PawnAIName);
	}
	else
	{
		if (!GetPlayerTank())
		{
			UE_LOG(LogTemp, Error, TEXT("No player controller found"));
		}
		else
		{
			return;
		}
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto playerTank = GetPlayerTank()->GetActorLocation();
	GetControlledTank()->AimAt(playerTank);
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	return Cast<ATank>(PlayerPawn);
}

