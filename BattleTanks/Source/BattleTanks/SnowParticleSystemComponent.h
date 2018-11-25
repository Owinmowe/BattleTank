// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Particles/ParticleSystemComponent.h"
#include "SnowParticleSystemComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API USnowParticleSystemComponent : public UParticleSystemComponent
{
	GENERATED_BODY()

public:

	void ChangePosition(FVector Position);
	

	UPROPERTY(EditDefaultsOnly)
	float SystemAltitude = 1000;
};
