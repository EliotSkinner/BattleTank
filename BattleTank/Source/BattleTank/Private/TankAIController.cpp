// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "TankAimingComponent.h"
#include "GameFramework/PlayerController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto Player = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto GamehendgeTank = GetPawn();

	if (!ensure(Player && GamehendgeTank)) { return; }
	//Move towards player
	MoveToActor(Player, AcceptanceRadius);
	//Aim at player
	auto AimingComponent = GamehendgeTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(Player->GetActorLocation());

	AimingComponent->Fire();
}



