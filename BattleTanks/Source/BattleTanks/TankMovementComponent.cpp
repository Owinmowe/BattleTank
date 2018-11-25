// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"
#include "SnowParticleSystemComponent.h"

void UTankMovementComponent::IntendMoveFoward(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
	SPS->ChangePosition(GetOwner()->GetActorLocation());
}

void UTankMovementComponent::IntendRotate(float Throw)
{
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(-Throw);
}

void UTankMovementComponent::Initialize(UTankTrack * LeftTrackToSet, UTankTrack * RightTrackToSet, USnowParticleSystemComponent * SPSToSet)
{
	if (!LeftTrackToSet || !RightTrackToSet) { return; }
	
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;

	if (!SPSToSet) { return; }

	SPS = SPSToSet;
}

void UTankMovementComponent::RequestDirectMove(const FVector & MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto AIForwardIntention = MoveVelocity.GetSafeNormal();

	auto ForwardThrow = FVector::DotProduct(TankForward, AIForwardIntention);
	IntendMoveFoward(ForwardThrow);

	auto RotateThrow = FVector::CrossProduct(AIForwardIntention, TankForward).Z;
	IntendRotate(RotateThrow);
}

