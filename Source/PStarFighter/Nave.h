// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Proyectil.h"
#include "Bala.h"
#include "Bomba.h"
#include "Misil.h"
#include "Rayo.h"
#include "Cola.h"

#include "Nave.generated.h"


class UStaticMeshComponent;
class UCapsuleComponent;


UCLASS()
class PSTARFIGHTER_API ANave : public APawn
{
	GENERATED_BODY()

		Cola<class AProyectil*> ColaProyectiles;

		//<>
		//Pila<class AProyectil*>balaAcumulador();

public:

	// Sets default values for this pawn's properties
	ANave();
	UPROPERTY()
	FVector GunOffset;
	float FireForwardValue;
	float FireRightValue;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* NaveMesh;

	UPROPERTY(EditAnywhere)
		UCapsuleComponent* CapsuleCollision;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Movimiento

	void MoveUp(float AxisValue);
	void MoveRight(float AxisValue);

	void FireWeapon();
	void StartFiring();
	void StopFiring();
	bool bIsFiring;
	float WeaponFireRate;
	float TimeSinceLastShot;
		
	UPROPERTY(EditAnywhere)
		float MaxVelocity;

	float Current_X_Velocity;
	float Current_Y_Velocity;

	FVector Current_Location;
	FRotator Current_Rotation;
	FVector New_Location;

	UFUNCTION()
		void OnBeginOverLap(AActor* PlayerActor, AActor* OtherActor);
	//<>
	UPROPERTY(EditAnywhere)
		TSubclassOf<AProyectil> Proyectil_BP;

	//***BALA

	void FireWeaponBala();
	void StartFiringBala();
	void StopFiringBala();
	bool bBalaIsFiring;
	float FireBalaRate;
	float BalaTimeSinceLastShot;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABala> Bala_BP;


	//*** BOMBA

	void FireWeaponBomba();
	void StartFiringBomba();
	void StopFiringBomba();
	bool bBombaIsFiring;
	float FireBombaRate;
	float BombaTimeSinceLastShot;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABomba> Bomba_BP;


	//*** MISIL

	void FireWeaponMisil();
	void StartFiringMisil();
	void StopFiringMisil();
	bool bMisilIsFiring;
	float FireMisilRate;
	float MisilTimeSinceLastShot;

	UPROPERTY(EditAnywhere)
		TSubclassOf<AMisil> Misil_BP;


    //*** RAYO

	void FireWeaponRayo();
	void StartFiringRayo();
	void StopFiringRayo();
	bool bRayoIsFiring;
	float FireRayoRate;
	float RayoTimeSinceLastShot;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ARayo> Rayo_BP;


public:
		/** Returns ShipMeshComponent subobject **/
		FORCEINLINE class UStaticMeshComponent* GetShipMeshComponent() const { return NaveMesh; }
		/** Returns CameraComponent subobject **/
		FORCEINLINE class UCapsuleComponent* GetCameraComponent() const { return CapsuleCollision; }
};
