// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Smithy.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UStaticMeshComponent;
UCLASS()
class SHOOTER_API ASmithy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASmithy();

	UPROPERTY(VisibleAnywhere,BluePrintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* SpringCom;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* CameraCom;

	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = Player, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* MeshCom;
protected:
	
	void MoveForward(float Value);
	void MoveRight(float Value);
	void TurnAtRate(float Value);
	void LookUpRate(float Value);

	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = Player, meta = (AllowPrivateAccess = "true"))
	float BaseTurnRate;
	UPROPERTY(EditAnywhere, BluePrintReadOnly, Category = Player, meta = (AllowPrivateAccess = "true"))
	float BaseLookUpRate;
public:	
	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:

};
