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

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float ReverseTimeThreshold = 3.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float ReverseTimeMaximum = 15.f;

	UPROPERTY(BlueprintReadOnly)
	float CurrentRecordedTime = .0f;
	UPROPERTY(BlueprintReadOnly)
	bool TimeReversalEnable = true;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	float GetTimeFactor();
	UFUNCTION(BlueprintCallable)
	float GetCurrentRecoredTime();

	// Time reverse contorl
	UFUNCTION(BlueprintCallable)
	void BeginTimeReverse();
	UFUNCTION(BlueprintCallable)
	void EndTimeReverse();

	UFUNCTION(BlueprintCallable)
	void EnableTimeReversal(bool Enable);

private:
	
};
