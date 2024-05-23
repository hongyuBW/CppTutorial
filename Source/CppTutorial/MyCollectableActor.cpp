// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCollectableActor.h"

// Sets default values
AMyCollectableActor::AMyCollectableActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create the (root) component for rendering
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	SetRootComponent(StaticMesh);
	
	// Create collision box
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	BoxCollision->SetupAttachment(StaticMesh);
	
}

void AMyCollectableActor::Jump(float velocity)
{
	// make shure jump jis only executed once
	if (!IsLaunched)
	{
		// Excute jump using the physics system
		StaticMesh->AddImpulse({ .0f,.0f,velocity * 500.f });

		// Initiate object destruction
		SetActorTickEnabled(true);
		//SetActorTickInterval(1.f);
		IsLaunched = true;
	}
}

// Called when the game starts or when spawned
void AMyCollectableActor::BeginPlay()
{
	Super::BeginPlay();

	// Setup per instance OnComponentOVerlap event
	FScriptDelegate DelegateSubscriber;
	DelegateSubscriber.BindUFunction(this, "OnComponentBeginOverlap");
	BoxCollision->OnComponentBeginOverlap.Add(DelegateSubscriber);

	// Ticking is only required after launching
	SetActorTickEnabled(false);

}

void AMyCollectableActor::OnComponentBeginOverlap(UBoxComponent* Component, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFormSweep, const FHitResult& SweepResult)
{
	if (!IsLaunched && OtherActor->IsA(TriggerClass))
	{
		//Jump(5.f);
		OnJumpTrigger.Broadcast(OtherActor, Component);
	}
}

// Called every frame
void AMyCollectableActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsLaunched)
	{
		// Decrement livetime
		Livetime -= DeltaTime;

		// Check actor destruction
		if (Livetime <= 0.f)
		{
			Destroy();
		}
	}
}

