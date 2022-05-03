// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoAcuatico.generated.h"

/**
 * 
 */
UCLASS()
class PSTARFIGHTER_API AEnemigoAcuatico : public AEnemigo
{
	GENERATED_BODY()

public:
	AEnemigoAcuatico();
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
