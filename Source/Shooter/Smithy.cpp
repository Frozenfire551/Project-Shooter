// Fill out your copyright notice in the Description page of Project Settings.


#include "Smithy.h"
#include <GameFramework/SpringArmComponent.h>
#include <Camera/CameraComponent.h>
#include <Components/InputComponent.h>
#include <Components/StaticMeshComponent.h>
#include <GameFramework/Controller.h>

// Sets default values
ASmithy::ASmithy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SpringCom = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringCom->SetupAttachment(RootComponent);

	CameraCom = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraCom->SetupAttachment(SpringCom);

	MeshCom = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerMesh"));
	MeshCom->SetupAttachment(RootComponent);

	BaseTurnRate = 45.0;
	BaseLookUpRate = 45.0;
}


void ASmithy::MoveForward(float Value)
{
	if ((Controller)&&(Value!=0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void ASmithy::MoveRight(float Value)
{
	if ((Controller) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void ASmithy::TurnAtRate(float Value)
{
	AddControllerYawInput(Value * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void ASmithy::LookUpRate(float Value)
{
	AddControllerPitchInput(Value * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}



// Called to bind functionality to input
void ASmithy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	/*PlayerInputComponent->BindAction("Fire", IE_Pressed, this, );
	PlayerInputComponent->BindAction("Reload", IE_Pressed, this, );
	PlayerInputComponent->BindAction("ChangeWeapon", IE_Axis, this, );*/


	PlayerInputComponent->BindAxis("MoveForward", this, &ASmithy::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASmithy::MoveRight);

	PlayerInputComponent->BindAxis("TurnRate", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &APawn::AddControllerPitchInput);
}

