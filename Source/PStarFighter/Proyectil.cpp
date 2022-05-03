// Fill out your copyright notice in the Description page of Project Settings.


#include "Proyectil.h"


// Sets default values
AProyectil::AProyectil()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));


	BulletComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlaneComponent"));
	CapsuleCollision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionComponent"));

	BulletComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	CapsuleCollision->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	ProyectilSpeed = 1000.0f;
	bHit = false;
	bDestroy = false;
}



// Called when the game starts or when spawned
void AProyectil::BeginPlay()
{
	Super::BeginPlay();

	CurrentLocation = this->GetActorLocation();

	OnActorBeginOverlap.AddDynamic(this, &AProyectil::OnBeginOverlap);
	
}

// Called every frame
void AProyectil::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = FVector(CurrentLocation.X, CurrentLocation.Y + (ProyectilSpeed * DeltaTime),CurrentLocation.Z);

	this->SetActorLocation(NewLocation);
	CurrentLocation = NewLocation;

}

void AProyectil::OnBeginOverlap(AActor* ProyectilActor, AActor* OtherActor)
{
}

