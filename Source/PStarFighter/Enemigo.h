// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Enemigo.generated.h"

class UCapsuleComponent;

UCLASS()
class PSTARFIGHTER_API AEnemigo : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEnemigo();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* EnemigoMesh;

	UPROPERTY(EditAnywhere)
		UCapsuleComponent* CollisionComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	float MoveSpeed;

public:
	/** Returns ShipMeshComponent subobject **/
	FORCEINLINE class UStaticMeshComponent* GetShipMeshComponent() const { return EnemigoMesh; }
	/** Returns CameraComponent subobject **/
	FORCEINLINE class UCapsuleComponent* GetCameraComponent() const { return CollisionComponent; }

};
