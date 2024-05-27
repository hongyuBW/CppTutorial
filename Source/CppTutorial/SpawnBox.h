// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "SpawnBox.generated.h"


UCLASS()
class CPPTUTORIAL_API ASpawnBox : public AActor
{
	GENERATED_BODY()
	
	// Box in which we will spawn the actors
	UPROPERTY(EditDefaultsOnly)
	UBoxComponent* SpawnBox;

	// Actor class to spawn
	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ActorClassToBeSpawned;

	
public:	
	// Sets default values for this actor's properties
	ASpawnBox();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called when the game end or when destroy
	void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Will spawn an actor of the specified class now
	UFUNCTION(BlueprintCallable)
	bool SpawnActor();

	// Will schedule an actor spawn
	UFUNCTION()
	void ScheduleActorSpawn();

	UFUNCTION()
	void SpawnActorScheduled();

	// Change if actors are spawned
	UFUNCTION(BlueprintCallable)
	void EnableSpawningActor(bool Enable);

private:
	// Average time between spawns (without random)
	UPROPERTY(EditAnywhere)
	float AvgSpawnTime = 5.f;

	// Random +/- offset of the spawn time
	UPROPERTY(EditAnywhere)
	float RandomSpawnTimeOffset = 1.f;

	UPROPERTY(EditAnywhere)
	bool ShouldSpawn = true;

	// Helper for timing
	FTimerHandle SpawnTimerHandle;

};
