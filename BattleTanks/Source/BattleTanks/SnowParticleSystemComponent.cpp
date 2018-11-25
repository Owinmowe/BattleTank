// Fill out your copyright notice in the Description page of Project Settings.

#include "SnowParticleSystemComponent.h"

void USnowParticleSystemComponent::ChangePosition(FVector Position)
{
	SetWorldLocation(FVector(Position.X, Position.Y, SystemAltitude));
}
