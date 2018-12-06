// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/Classes/Engine/World.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

protected:

	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
	void FoundAimingComponent(UTankAimingComponent* AimCompRef); //Blueprint Implementable Events get defined in blueprint

private:

	UTankAimingComponent* AimingComponent = nullptr;

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector &OutHitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection, FVector& CameraLocation) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector CameraLocation, FVector& HitLocation) const;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairXLocation = .5f;

	UPROPERTY(EditDefaultsOnly)
	float CrosshairYLocation = .3333f;
};
