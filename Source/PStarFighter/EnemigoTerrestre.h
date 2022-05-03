// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoTerrestre.generated.h"

/**
 * 
 */
UCLASS()
class PSTARFIGHTER_API AEnemigoTerrestre : public AEnemigo
{
	GENERATED_BODY()
public:
	AEnemigoTerrestre();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
