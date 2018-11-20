// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Physics"))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void Elevate(float RelativeSpeed);
	
private:

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegressPerSecond = 10.f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegress = 35.f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegress = 0.f;
};
