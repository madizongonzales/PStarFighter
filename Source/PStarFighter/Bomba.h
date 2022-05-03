// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Proyectil.h"
#include "Bomba.generated.h"

/**
 * 
 */
UCLASS()
class PSTARFIGHTER_API ABomba : public AProyectil
{
	GENERATED_BODY()
	
public:
	ABomba();

public:

	virtual void Tick(float DeltaTime) override;
};
