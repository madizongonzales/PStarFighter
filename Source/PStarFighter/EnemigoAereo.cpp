// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAereo.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"

AEnemigoAereo::AEnemigoAereo()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> EnemigoAereoMesh(TEXT("/Game/Meshes/nitro_sub.nitro_sub"));
	EnemigoMesh->SetStaticMesh(EnemigoAereoMesh.Object);
}

void AEnemigoAereo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	srand(time(NULL));

	float randx = rand() % 70 - 45;
	float randy = rand() % 70 - 45;

	//Velocidad
	MoveSpeed = 75.0f;


	const FVector Move = FVector(randx, 0.0f, 0.0f).GetClampedToMaxSize(1.0f);
	const FVector Movement = Move * MoveSpeed * DeltaTime;

	//<>
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	}
}
