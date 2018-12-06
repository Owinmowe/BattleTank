// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/Classes/GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float AcceptanceRadius = 7500;
};
