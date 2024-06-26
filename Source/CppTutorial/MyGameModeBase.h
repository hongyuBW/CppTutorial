// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/DefaultPawn.h"
#include "TimeManager.h"
#include "MyGameModeBase.generated.h"


/**
 * 
 */
UCLASS()
class CPPTUTORIAL_API AMyGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	void InitGameState() override;

	UFUNCTION(BlueprintCallable)
	ATimeManager* GetTimeManager();

protected:
	UPROPERTY(BlueprintReadOnly)
	ATimeManager* TimeManager = nullptr;

private:
	UPROPERTY(EditAnywhere, NoClear)
	TSubclassOf<APawn> CustomPawnClass = APawn::StaticClass();
	
};
