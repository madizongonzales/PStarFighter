// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"

#include "Proyectil.generated.h"

UCLASS()
class PSTARFIGHTER_API AProyectil : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProyectil();

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* BulletComponent;

	UPROPERTY(EditAnywhere)
		UCapsuleComponent* CapsuleCollision;

	UPROPERTY(EditAnywhere)
		float ProyectilSpeed;

	UFUNCTION()
		void OnBeginOverlap(AActor* ProyectilActor, AActor* OtherActor);
	FVector CurrentLocation;

	bool bHit;
	bool bDestroy;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** Returns ShipMeshComponent subobject **/
	FORCEINLINE class UStaticMeshComponent* GetShipMeshComponent() const { return BulletComponent; }
	/** Returns CameraComponent subobject **/
	FORCEINLINE class UCapsuleComponent* GetCameraComponent() const { return CapsuleCollision; }

};
