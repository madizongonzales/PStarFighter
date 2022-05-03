// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemigoAcuatico.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"

AEnemigoAcuatico::AEnemigoAcuatico()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> EnemigoAcuaticoMesh(TEXT("/Game/Meshes/nitro_sub.nitro_sub"));
	EnemigoMesh->SetStaticMesh(EnemigoAcuaticoMesh.Object);
}

void AEnemigoAcuatico::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	srand(time(NULL));

	float randx = rand() % 30 - 25;
	float randy = rand() % 30 - 25;

	//Velocidad
	MoveSpeed = 50.0f;

	const FVector Move = FVector(0.0f, randy, 0.0f).GetClampedToMaxSize(1.0f);
	const FVector Movement = Move * MoveSpeed * DeltaTime;

	//<>
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	}

}
