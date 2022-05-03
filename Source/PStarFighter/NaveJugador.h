// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
//Declarando la Clase Nave Jugador
#include "NaveJugador.generated.h"

class UFloatingPawnMovement;

UCLASS()
class PSTARFIGHTER_API ANaveJugador : public APawn
{
	GENERATED_BODY()

//Atributos de Nave Jugador

private:
	float Tamano;
	float NumeroDeVidas;
	float Velocidad;
	float UbicacionX;
	float UbicacionY;

//Metodos de Nave Jugador.

public:
	// Sets default values for this pawn's properties
	ANaveJugador();

	void Disparar();
	void Moverse();
	void Danarse();
	void Mejorar();

	//*** *** *** PRUEBA PARA PONER LÍMITES A LA NAVE

	UPROPERTY(EditAnywhere)
		float MaxValocity;

	float Current_X_Velocity;
	float Current_Y_Velocity;

	FVector Current_Location;
	FVector New_Location;

	UFUNCTION()
		void OnBeginOverLap(AActor* PlayerActor, AActor* OtherActor);

	UPROPERTY(EditAnywhere)
		float Field_Width;

	UPROPERTY(EditAnywhere)
		float Field_Height;

	//*** *** *** FIN DE PRUEBA

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_NaveJugador;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UFloatingPawnMovement* FloatingMovement;

    //Metodo moverse

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void MoveHorizontal(float AxisValue);
	virtual void MoveVertical(float AxisValue);
};
