// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * Class that control speed and maximun/minimun elevation of the barrel.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Physics"))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void Elevate(float RelativeSpeed);
	
private:

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxDegressPerSecond = 10.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxElevationDegress = 35.f;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MinElevationDegress = 0.f;
};
