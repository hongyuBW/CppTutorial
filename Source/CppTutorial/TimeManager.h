// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimeManager.generated.h"

UCLASS()
class CPPTUTORIAL_API ATimeManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimeManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite)
	float NormalTimeFactor = 1.f;
	UPROPERTY(BlueprintReadWrite)
	float ReverseTimeFactor = -3.f;
	UPROPERTY(BlueprintReadOnly)
	float CurrentTimeFactor = NormalTimeFactor;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	float GetTimeFactor();

	// Time reverse contorl
	UFUNCTION(BlueprintCallable)
	void BeginTimeReverse();
	UFUNCTION(BlueprintCallable)
	void EndTimeReverse();

private:
	
};
