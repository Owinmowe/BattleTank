// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "Projectile.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();
	LastFireTime = GetWorld()->GetTimeSeconds();
}

void UTankAimingComponent::Initialize(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet, TSubclassOf<AProjectile> ProjectileToSet)
{
	if (!ensure(BarrelToSet && TurretToSet)) { return; }
	Barrel = BarrelToSet;
	Turret = TurretToSet;
	if (!ensure(ProjectileToSet)) { return; }
	ProjectileBlueprint = ProjectileToSet;
}

// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if(CurrentAmmo <= 0)
	{
		FiringState = EFiringState::OutOfAmmo;
	}
	else if((GetWorld()->GetTimeSeconds() - LastFireTime) < ReloadTimeInSeconds)
	{
		FiringState = EFiringState::Reloading;
	}
	else if(IsBarrelMoving())
	{
		FiringState = EFiringState::Aiming;
	}
	else
	{
		FiringState = EFiringState::Lock;
	}
}

void UTankAimingComponent::AimAt(FVector HitLocation)
{
	if (!ensure(Barrel)) { return; }
	FVector LaunchVelocity;
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		LaunchVelocity,
		Barrel->GetSocketLocation(FName("FiringLocation")),
		HitLocation,
		LaunchSpeed,
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if(bHaveAimSolution)
	{
		AimDirection = LaunchVelocity.GetSafeNormal();
		MoveAimTowards(AimDirection);
	}
}

void UTankAimingComponent::MoveAimTowards(FVector AimDirection)
{
	if (!ensure(Barrel && Turret)) { return; }
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(DeltaRotator.Pitch);
	if (FMath::Abs(DeltaRotator.Yaw) < 180)
	{
		Turret->Rotate(DeltaRotator.Yaw);
	}
	else
	{
		Turret->Rotate(-DeltaRotator.Yaw);
	}
}

void UTankAimingComponent::Fire()
{
	if (!ensure(Barrel && ProjectileBlueprint)) { return; }

	if (FiringState == EFiringState::Lock || FiringState == EFiringState::Aiming)
	{
		CurrentAmmo--;
		LastFireTime = GetWorld()->GetTimeSeconds();
		auto SocketLocation = Barrel->GetSocketLocation(FName("FiringLocation"));
		auto SocketRotation = Barrel->GetSocketRotation(FName("FiringLocation"));
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, SocketLocation, SocketRotation);

		Projectile->LaunchProjectile(LaunchSpeed);
	}
}

bool UTankAimingComponent::IsBarrelMoving()
{
	if (!ensure(Barrel)) { return false; }

	if(Barrel->GetForwardVector().Equals(AimDirection, 0.01f))
	{
		return false;
	}
	else
	{
		return true;
	}
}

EFiringState UTankAimingComponent::GetFiringState() const
{
	return FiringState;
}

int32 UTankAimingComponent::GetCurrentAmmo()
{
	return CurrentAmmo;
}
