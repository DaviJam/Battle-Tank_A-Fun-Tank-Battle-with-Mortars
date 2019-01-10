// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#include "Classes/GameFramework/Controller.h"
#include "BattleTank.h"


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto Controller = GetControlledTank();
	if (!Controller)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller not possessing a tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player controller possessing: %s"), *Controller->GetName())
	}

	

}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();


}

void ATankPlayerController::AimTowardsCrosshair()
{
	//if (!GetControlledTank()) { return; }

	//FVector HitLocation; //Out Parameter

	//UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"),*HitLocation.ToString())
	//Get world location if linetrace through crosshair
	//if it hits the landscape
	//Tell controlled tank to aim at this point
}