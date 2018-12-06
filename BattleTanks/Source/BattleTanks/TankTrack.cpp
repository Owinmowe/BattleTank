// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "Engine/Classes/Engine/World.h"

UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = false;
	SetNotifyRigidBodyCollision(true);
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	//UE_LOG(LogTemp, Warning, TEXT("I'm hit by %s"), *(OtherActor->GetName()));
	DriveTrack();
	ApplySidewayForce();
	CurrentThrottle = 0;
}

void UTankTrack::ApplySidewayForce()
{
	auto RightVector = GetRightVector();

	auto SidewaySpeed = FVector::DotProduct(RightVector, GetComponentVelocity());

	auto DeltaTime = GetWorld()->GetDeltaSeconds();
	auto CorrectionAceleration = -SidewaySpeed / DeltaTime * RightVector;

	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAceleration) / 2; //Divide by two because there is two tracks

	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::SetThrottle(float throttle)
{
	CurrentThrottle = FMath::Clamp<float>(CurrentThrottle + throttle, -1, 1);
}

void UTankTrack::DriveTrack()
{
	auto ForceApplied = GetForwardVector() * CurrentThrottle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}



