// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	//UE_LOG(LogTemp, Warning, TEXT("AI Controller BeginPlay Method Logged to Gamehendge Mainframe"));

	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		//UE_LOG(LogTemp, Error, TEXT("Gamehendge Mainframe ERROR: Tank AI Controller NOT possesing a tank"));
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("Gamehendge Mainframe: Tank AI Controller %s possesiHELLOng a tank"), *(PlayerTank->GetName()));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		//Move towards player
		//Aim at player
		auto Tank = GetControlledTank();
		auto Player = GetPlayerTank();
		Tank->AimAt(Player->GetActorLocation());
		//Fire if ready
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	ATank* GamehendgeTank = Cast<ATank>(GetPawn());
	FString GamehendgeTankName = GamehendgeTank->GetName();

	if (GamehendgeTank)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Gamehendge Mainframe reporting: %s is now being controlled by the Tank AI Controller"), *GamehendgeTankName);
	}
	else
	{
		//UE_LOG(LogTemp, Error, TEXT("Gamehendge Mainframe ERROR: Tank AI Controller NOT possesing a tank"));
	}

	return GamehendgeTank;


}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerTank)
	{
		return nullptr;
	}
	return Cast<ATank>(PlayerTank);
}
