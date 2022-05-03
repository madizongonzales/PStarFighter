// Fill out your copyright notice in the Description page of Project Settings.


#include "Nave.h"

#include "Components/StaticMeshComponent.h"
#include "Components/CapsuleComponent.h"


/**Pila<class AProyectil*> ANave::balaAcumulador()

{
	//Pila<AProyectil*> balaAcumulador(30);
;
	//cout << "Numero de balas lanzadas: " << balaAcumulador.getCima() << endl;
	//return (cout << "Numero de balas lanzadas: " << balaAcumulador.getCima() << endl);
}*/

// Sets default values
ANave::ANave()

{
	//*** COLA

	const FVector MoveDirection = FVector(FireForwardValue, FireRightValue, 0.f).GetClampedToMaxSize(1.0f);

	const FRotator FireRotation = MoveDirection.Rotation();
	// Spawn projectile at an offset from this pawn
	const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

	UWorld* const World = GetWorld();
	if (World != nullptr)
	{
		//FTransform SpawnLocation;
		// spawn the projectile

		ColaProyectiles.Push(World->SpawnActor<AProyectil>(SpawnLocation, FireRotation));
		ColaProyectiles.Push(World->SpawnActor<AProyectil>(SpawnLocation, FireRotation));
		ColaProyectiles.Push(World->SpawnActor<AProyectil>(SpawnLocation, FireRotation));
		ColaProyectiles.Push(World->SpawnActor<AProyectil>(SpawnLocation, FireRotation));
		ColaProyectiles.Push(World->SpawnActor<AProyectil>(SpawnLocation, FireRotation));

		//UE_LOG(LogTemp, Warning, TEXT("SpawnLocation(X, Y) = %s, %s FireRotation(X, Y) =  s, s"), SpawnLocation.X, SpawnLocation.Y);
		//UE_LOG(LogTemp, Warning, TEXT("World not nullptr"));
	}



 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));


	NaveMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Nave Mesh"));


	CapsuleCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collision"));

	NaveMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	CapsuleCollision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	MaxVelocity = 500.0f;
	Current_X_Velocity = 0.0f;
	Current_Y_Velocity = 0.0f;
    
	bIsFiring = false;
	WeaponFireRate = 0.25f;
	TimeSinceLastShot = 0.0f;

	//***BALA

	bBalaIsFiring = false;
	FireBalaRate = 0.25;
	BalaTimeSinceLastShot = 0.0f;

	//*** BOMBA
	bBombaIsFiring = false;
	FireBombaRate = 0.25;
	BombaTimeSinceLastShot = 0.0f;

    //*** MISIL

	bMisilIsFiring = false;
	FireMisilRate = 0.25;
	MisilTimeSinceLastShot = 0.0f;


    //*** RAYO

	bRayoIsFiring = false;
	FireRayoRate = 0.25;
	RayoTimeSinceLastShot = 0.0f;


}

// Called when the game starts or when spawned
void ANave::BeginPlay()
{
	Super::BeginPlay();

	Current_Location = this->GetActorLocation();

	Current_Rotation = this->GetActorRotation();

	OnActorBeginOverlap.AddDynamic(this, &ANave::OnBeginOverLap);

	
}

void ANave::MoveUp(float AxisValue)
{

	Current_Y_Velocity = MaxVelocity * AxisValue;
}

void ANave::MoveRight(float AxisValue)
{
	Current_X_Velocity = MaxVelocity * AxisValue;
}

void ANave::StartFiring()
{
	bIsFiring = true;
}

void ANave::StopFiring()
{
	bIsFiring = false;
}

void ANave::FireWeapon()
{
	FActorSpawnParameters Params = {};
	Params.Owner = this;

	AActor* SpawnedProyectil = GetWorld()->SpawnActor(Proyectil_BP, &Current_Location, &Current_Rotation, Params);
}

// Called every frame
void ANave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Current_X_Velocity != 0.0f || Current_Y_Velocity != 0.0f)
	{
		New_Location = FVector(Current_Location.X + (Current_X_Velocity * DeltaTime),
			Current_Location.Y + (Current_Y_Velocity * DeltaTime), 0);

		this->SetActorLocation(New_Location);

		Current_Location = New_Location;

	}
	//<>
	if (Current_X_Velocity > 0.1f)
	{
		this->SetActorRotation(FRotator(Current_Rotation.Pitch + 10.0f, Current_Rotation.Yaw, Current_Rotation.Roll));
	}

	else if (Current_X_Velocity < -0.1f)
	{
		this->SetActorRotation(FRotator(Current_Rotation.Pitch - 10.0f, Current_Rotation.Yaw, Current_Rotation.Roll));
	}

	else {
		this->SetActorRotation(FRotator(Current_Rotation));
	}

	if (bIsFiring)
	{
		if (TimeSinceLastShot > WeaponFireRate) {
			FireWeapon();
			TimeSinceLastShot = 0.0f;
		}
	}
	TimeSinceLastShot += DeltaTime;


	//*** BALA 

	if (bBalaIsFiring)
	{
		if (BalaTimeSinceLastShot > FireBalaRate) 
		{
			FireWeaponBala();
			BalaTimeSinceLastShot = 0.0f;
		}
	}
	BalaTimeSinceLastShot += DeltaTime;


	//*** BOMBA
	if (bBombaIsFiring)
	{
		if (BombaTimeSinceLastShot > FireBombaRate)
		{
			FireWeaponBomba();
			BombaTimeSinceLastShot = 0.0f;
		}
	}
	BombaTimeSinceLastShot += DeltaTime;

    //*** MISIL
	if (bMisilIsFiring)
	{
		if (MisilTimeSinceLastShot > FireMisilRate)
		{
			FireWeaponMisil();
			MisilTimeSinceLastShot = 0.0f;
		}
	}
	MisilTimeSinceLastShot += DeltaTime;


    //*** RAYO
	if (bRayoIsFiring)
	{
		if (RayoTimeSinceLastShot > FireRayoRate)
		{
			FireWeaponRayo();
			RayoTimeSinceLastShot = 0.0f;
		}
	}
	RayoTimeSinceLastShot += DeltaTime;
}

// Called to bind functionality to input
void ANave::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(FName("MoveUp"), this, &ANave::MoveUp);
	PlayerInputComponent->BindAxis(FName("MoveRight"), this, &ANave::MoveRight);

	PlayerInputComponent->BindAction(FName("Fire"), IE_Pressed, this, &ANave::StartFiring);
	PlayerInputComponent->BindAction(FName("Fire"), IE_Released, this, &ANave::StopFiring);

//*** BALA-BOMBA-MISIL-RAYO

	PlayerInputComponent->BindAction(FName("FireBala"), IE_Pressed, this, &ANave::StartFiringBala);
	PlayerInputComponent->BindAction(FName("FireBala"), IE_Released, this, &ANave::StopFiringBala);

	PlayerInputComponent->BindAction(FName("FireBomba"), IE_Pressed, this, &ANave::StartFiringBomba);
	PlayerInputComponent->BindAction(FName("FireBomba"), IE_Released, this, &ANave::StopFiringBomba);

	PlayerInputComponent->BindAction(FName("FireMisil"), IE_Pressed, this, &ANave::StartFiringMisil);
	PlayerInputComponent->BindAction(FName("FireMisil"), IE_Released, this, &ANave::StopFiringMisil);

	PlayerInputComponent->BindAction(FName("FireRayo"), IE_Pressed, this, &ANave::StartFiringRayo);
	PlayerInputComponent->BindAction(FName("FireRayo"), IE_Released, this, &ANave::StopFiringRayo);

}

//*** BALA

void ANave::StartFiringBala()
{
	bBalaIsFiring = true;
}

void ANave::StopFiringBala()
{

	bBalaIsFiring = false;
}

void ANave::FireWeaponBala()
{
	FActorSpawnParameters Params = {};
	Params.Owner = this;

	AActor* SpawnBala = GetWorld()->SpawnActor(Bala_BP, &Current_Location, &Current_Rotation, Params);
}

//*** BOMBA

void ANave::StartFiringBomba()
{
	bBombaIsFiring = true;
}

void ANave::StopFiringBomba()
{
	bBombaIsFiring = false;
}

void ANave::FireWeaponBomba()
{
	FActorSpawnParameters Params = {};
	Params.Owner = this;

	AActor* SpawnBomba = GetWorld()->SpawnActor(Bomba_BP, &Current_Location, &Current_Rotation, Params);
}

//*** MISIL

void ANave::StartFiringMisil()
{
	bMisilIsFiring = true;
}

void ANave::StopFiringMisil()
{
	bMisilIsFiring = false;
}

void ANave::FireWeaponMisil()
{
	FActorSpawnParameters Params = {};
	Params.Owner = this;

	AActor* SpawnMisil = GetWorld()->SpawnActor(Misil_BP, &Current_Location, &Current_Rotation, Params);
}

//*** RAYO

void ANave::StartFiringRayo()
{
	bRayoIsFiring = true;
}

void ANave::StopFiringRayo()
{
	bRayoIsFiring = false;
}

void ANave::FireWeaponRayo()
{
	FActorSpawnParameters Params = {};
	Params.Owner = this;

	AActor* SpawnRayo = GetWorld()->SpawnActor(Rayo_BP, &Current_Location, &Current_Rotation, Params);
}

void ANave::OnBeginOverLap(AActor* PlayerActor, AActor* OtherActor)
{
}
