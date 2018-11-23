// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * Class that controls the horizontal movement of the turret.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Physics"))
class BATTLETANKS_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()


public:

	void Rotate(float RelativeSpeed);

private:

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegressPerSecond = 30.f;

};
