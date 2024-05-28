// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeManager.h"
#include "MathUtil.h"

// Sets default values
ATimeManager::ATimeManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATimeManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATimeManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (TimeReversalEnable)
	{
		CurrentRecordedTime = TMathUtil<float>::Min(ReverseTimeMaximum, CurrentRecordedTime + DeltaTime * CurrentTimeFactor);
		if (CurrentRecordedTime <= .0f)
		{
			EndTimeReverse();
		}
	}
}

float ATimeManager::GetTimeFactor()
{
	return CurrentTimeFactor;
}

float ATimeManager::GetCurrentRecoredTime()
{
	return CurrentRecordedTime;
}

void ATimeManager::BeginTimeReverse()
{
	if (TimeReversalEnable && CurrentRecordedTime >= ReverseTimeThreshold)
		CurrentTimeFactor = ReverseTimeFactor;
}

void ATimeManager::EndTimeReverse()
{
	CurrentTimeFactor = NormalTimeFactor;
	CurrentRecordedTime = .0f;
}

void ATimeManager::EnableTimeReversal(bool Enable)
{
	if (Enable)
	{
		TimeReversalEnable = true;
		BeginTimeReverse();
	}
	else
	{
		TimeReversalEnable = false;
		EndTimeReverse();
	}
}

