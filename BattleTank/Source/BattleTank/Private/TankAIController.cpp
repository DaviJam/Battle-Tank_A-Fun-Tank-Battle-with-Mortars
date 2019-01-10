// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "Engine/World.h"
#include "Classes/GameFramework/PlayerController.h"

ATank* ATankAIController::GetControlledTank() const{return Cast<ATank>(GetPawn());}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	return (!PlayerPawn)?nullptr:Cast<ATank>(PlayerPawn);
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerTank = GetPlayerTank();
	
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIcontroller can't find Player tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s AIcontroller found player: %s"),*GetControlledTank()->GetName(), *PlayerTank->GetName())
	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//AimTowardsCrosshair();

	UE_LOG(LogTemp, Warning, TEXT("AI controller ticking"))

}

