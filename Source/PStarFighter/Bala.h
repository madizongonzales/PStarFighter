// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Proyectil.h"
#include "Pila.h"
#include "Bala.generated.h"

/**
 * 
 */
UCLASS()
class PSTARFIGHTER_API ABala : public AProyectil
{
	GENERATED_BODY()

public:
	ABala();

public:

	virtual void Tick(float DeltaTime) override;

};
