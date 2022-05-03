// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveJugador.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ANaveJugador::ANaveJugador()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


//Ajustes



//SM_NaveJugador->CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM NaveJugador"));
//RootComponent = SM_NaveJugador;

//SM_NaveJugador->SetEnableGravity(false);
//SM_NaveJugador->SetConstraintMode(EDOFMode::XZPlane);
//SM_NaveJugador->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
//SM_NaveJugador->SetCollisionProfileName(TEXT("PhysicsActor"));

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Movement"));

	//*** *** *** PRUEBA PARA PONER LÍMITES A LA NAVE
	//MaxVelocity=5000.0f
	Current_X_Velocity = 0.0f;
	Current_Y_Velocity = 0.0f;
	
	//*** *** *** FIN DE PRUEBA



}

//Metodos de Nave Jugador.

void ANaveJugador::Disparar()
{
	Tamano = 50;
	NumeroDeVidas = 7;
	Velocidad = 15;
	UbicacionX = 0;
	UbicacionY = 0;
}

void ANaveJugador::Moverse()
{
	Tamano = 50;
	NumeroDeVidas = 7;
	Velocidad = 15;
	UbicacionX = 0;
	UbicacionY = 0;
}

void ANaveJugador::Danarse()
{
	Tamano = 50;
	NumeroDeVidas = 6;
	Velocidad = 10;
	UbicacionX = 0;
	UbicacionY = 0;
}

void ANaveJugador::Mejorar()
{
	Tamano = 50;
	NumeroDeVidas = 7;
	Velocidad = 15;
	UbicacionX = 0;
	UbicacionY = 0;
}

void ANaveJugador::OnBeginOverLap(AActor* PlayerActor, AActor* OtherActor)
{
}

// Called when the game starts or when spawned
void ANaveJugador::BeginPlay()
{
	Super::BeginPlay();



	//*** *** ***

	Current_Location = this->GetActorLocation();

	OnActorBeginOverlap.AddDynamic(this, &ANaveJugador::OnBeginOverLap);


	//*** *** *** FIN DE PRUEBA


	
}

// Called every frame
void ANaveJugador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//*** *** ***


	if (this->GetActorLocation().X > Field_Width)
	{
		Current_Location = FVector(Field_Width - 1, Current_Location.Y, Current_Location.Z);
	}

	if (this->GetActorLocation().X < -Field_Width)
	{
		Current_Location = FVector(-Field_Width + 1, Current_Location.Y, Current_Location.Z);
	}

	if (this->GetActorLocation().Y > Field_Height)
	{
		Current_Location = FVector(Current_Location.X, Field_Height -1, Current_Location.Z);
	}

	if (this->GetActorLocation().Y < -Field_Height)
	{
		Current_Location = FVector(Current_Location.X, -Field_Height + 1, Current_Location.Z);
	}

	//*** *** ***

}

// Called to bind functionality to input
void ANaveJugador::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

//Permite movimiento a los Inputs

void ANaveJugador::MoveHorizontal(float AxisValue)
{
	AddMovementInput(FVector(AxisValue, 0.0f, 0.0f), 1.0f, false);
}

void ANaveJugador::MoveVertical(float AxisValue)
{
	AddMovementInput(FVector(0.0f, AxisValue, 0.0f), 1.0f, false);
}

