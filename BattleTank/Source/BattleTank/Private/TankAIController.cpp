// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto Player = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (Player)
	{
		//Move towards player
		//Aim at player
		ATank* GamehendgeTank = Cast<ATank>(GetPawn());
		GamehendgeTank->AimAt(Player->GetActorLocation());

		GamehendgeTank->Fire(); // TODO limit fire rate
	}
}



