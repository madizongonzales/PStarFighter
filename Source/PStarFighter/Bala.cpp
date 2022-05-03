// Fill out your copyright notice in the Description page of Project Settings.


#include "Bala.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"

ABala::ABala()
{

	ProyectilSpeed = 1000.0f;
}

void ABala::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

	FVector NewLocation = FVector(CurrentLocation.X, CurrentLocation.Y + (ProyectilSpeed * DeltaTime), CurrentLocation.Z);

	this->SetActorLocation(NewLocation);
	CurrentLocation = NewLocation;


}
