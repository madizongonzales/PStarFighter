// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoTerrestre.h"

AEnemigoTerrestre::AEnemigoTerrestre()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> EnemigoTerrestreMesh(TEXT("/Game/Meshes/nitro_sub.nitro_sub"));
	EnemigoMesh->SetStaticMesh(EnemigoTerrestreMesh.Object);
}

void AEnemigoTerrestre::Tick(float DeltaTime)
{

	srand(time(NULL));

	float randx = rand() % 40 - 20;
	float randy = rand() % 40 - 20;

	//Velocidad
	MoveSpeed = 80.0f;

	const FVector Move = FVector(randx, randy, 0.0f).GetClampedToMaxSize(1.0f);
	const FVector Movement = Move * MoveSpeed * DeltaTime;

	//<>
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	}
}
