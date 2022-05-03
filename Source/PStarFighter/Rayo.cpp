// Fill out your copyright notice in the Description page of Project Settings.


#include "Rayo.h"

ARayo::ARayo()
{
	ProyectilSpeed = 1000.0f;
}

void ARayo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = FVector(CurrentLocation.X, CurrentLocation.Y + (ProyectilSpeed * DeltaTime), CurrentLocation.Z);

	this->SetActorLocation(NewLocation);
	CurrentLocation = NewLocation;
}
