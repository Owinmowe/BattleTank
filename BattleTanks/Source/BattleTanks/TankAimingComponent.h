// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/Classes/Kismet/GameplayStatics.h"
#include "Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Lock,
	OutOfAmmo
};

class UTankBarrel;
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet, TSubclassOf<AProjectile> ProjectileToSet);

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable)
	void Fire();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	EFiringState GetFiringState() const;

	UFUNCTION(BlueprintCallable, Category = "Ammo")
	int32 GetCurrentAmmo();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

private:

	void MoveAimTowards(FVector AimDirection);

	bool IsBarrelMoving();

	FVector AimDirection;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 12500;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	int32 CurrentAmmo = 12;

	// Sets default values for this component's properties
	UTankAimingComponent();

	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 5;

	UPROPERTY(EditAnywhere, Category = "Firing")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	float LastFireTime = -5;
};
