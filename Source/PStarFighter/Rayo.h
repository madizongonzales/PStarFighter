// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Proyectil.h"
#include "Rayo.generated.h"

/**
 * 
 */
UCLASS()
class PSTARFIGHTER_API ARayo : public AProyectil
{
	GENERATED_BODY()
	
public:
	ARayo();

public:

	virtual void Tick(float DeltaTime) override;
};
