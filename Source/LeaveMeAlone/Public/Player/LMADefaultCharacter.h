// LeaveMeAlone Game by Netologiya. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LMADefaultCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class ULMAHealthComponent;
class UAnimMontage;

UCLASS()
class LEAVEMEALONE_API ALMADefaultCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ALMADefaultCharacter();

	UFUNCTION()
	ULMAHealthComponent* GetHealthComponent() const { return HealthComponent; }  

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components|Health")
	ULMAHealthComponent* HealthComponent;

	UPROPERTY()
	UDecalComponent* CurrentCursor = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	UMaterialInterface* CursorMaterial = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	FVector CursorSize = FVector(20.0f, 40.0f, 40.0f);

	UPROPERTY(EditDefaultsOnly, Category="Animation")
	UAnimMontage* DeathMontage;

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ZoomMax")
	float ZoomMax = 1400.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ZoomMin")
	float ZoomMin = 500.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaminaMax")
	float StaminaMax = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaminaMin")
	float StaminaMin = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SprintVelocity")
	float SprintVelocity = 600.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WalkVelocity")
	float WalkVelocity = 300.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaminaCost")
	float StaminaCost = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stamina")
	float Stamina = StaminaMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "StaminaCooldown")
	float StaminaCooldown = 200.0f;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	float YRotation = -75.0f;

	float ArmLength = ZoomMax;

	float FOV = 55.0f;

	bool isShift = false;
	bool isStartCooldown = false;
	bool isStaminaFull = true;
	bool isSprintActive = false;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Zoom(float Value);
	void StartSprint();
	void StopSprint();


	void OnDeath();
	void OnHealthChanged(float NewHealth);

	void RotationPlayerOnCursor();

	void WalkOrSprint();
	void CheckSprintActivity(const float& Value);
	void OnStaminaChanged();
};
