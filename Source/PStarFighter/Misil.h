// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Proyectil.h"
#include "Misil.generated.h"

/**
 * 
 */
UCLASS()
class PSTARFIGHTER_API AMisil : public AProyectil
{
	GENERATED_BODY()
	
public:
	AMisil();

public:

	virtual void Tick(float DeltaTime) override;
};
