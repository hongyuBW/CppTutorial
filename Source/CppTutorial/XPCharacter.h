// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "XPCharacter.generated.h"

UCLASS()
class CPPTUTORIAL_API AXPCharacter : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* PlayerCamera;

	UPROPERTY(EditDefaultsOnly, Category = Mesh)
	UStaticMeshComponent* PlayerMesh;

	UPROPERTY(EditAnywhere)
	float MoveSpeed = 1.f;

	UPROPERTY(EditAnywhere)
	float RotationSpeed = 1.f;

public:
	// Sets default values for this character's properties
	AXPCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveFB(float Value);
	void MoveLR(float Value);
	void Rotate(float Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
