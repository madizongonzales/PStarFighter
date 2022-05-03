// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveJugador_Player_Controller.h"
#include "Kismet/GameplayStatics.h"
#include "Camera/CameraActor.h"

#include "NaveJugador.h"

ANaveJugador_Player_Controller::ANaveJugador_Player_Controller()
{
}

//

void ANaveJugador_Player_Controller::BeginPlay()
{
	//Almacenamiento de camaras.

	TArray<AActor*> CameraActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), CameraActors);

	FViewTargetTransitionParams Params;
	SetViewTarget(CameraActors[0], Params);

}

void ANaveJugador_Player_Controller::SetupInputComponent()
{

	Super::SetupInputComponent();

	EnableInput(this);

	InputComponent->BindAxis("MoveHorizontal", this, &ANaveJugador_Player_Controller::MoveHorizontal);
	InputComponent->BindAxis("MoveVertical", this, &ANaveJugador_Player_Controller::MoveVertical);

}


void ANaveJugador_Player_Controller::MoveHorizontal(float AxisValue)
{

	//Acomodar recibiendo valores

	auto MyPawn = Cast<ANaveJugador>(GetPawn());

	if (MyPawn) {

		MyPawn->MoveHorizontal(AxisValue);

	 }
}

void ANaveJugador_Player_Controller::MoveVertical(float AxisValue)
{
	auto MyPawn = Cast<ANaveJugador>(GetPawn());

	if (MyPawn) {

		MyPawn->MoveVertical(AxisValue);
	}
}
