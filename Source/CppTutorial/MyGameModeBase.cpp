// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"

void AMyGameModeBase::InitGameState()
{
	Super::InitGameState();

	// Check if no hard override is active
	if (DefaultPawnClass == ADefaultPawn::StaticClass() || !DefaultPawnClass)
	{
		// Update to custom implementation
		DefaultPawnClass = CustomPawnClass;
	}

	// Init the time manager
	TimeManager = Cast<ATimeManager>(GetWorld()->SpawnActor(ATimeManager::StaticClass()));
	if (!TimeManager)
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to create TimeManager!"));
	}
}

ATimeManager* AMyGameModeBase::GetTimeManager()
{
	// Check time manager is valid
	if (!TimeManager)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tried to call GetTimeManager() before it existed"));
	}
	return TimeManager;
}
