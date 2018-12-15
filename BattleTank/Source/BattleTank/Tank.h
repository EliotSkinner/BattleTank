// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Fire")
	void Flip();

protected:
	virtual void BeginPlay() override;


private:	
	// Sets default values for this pawn's properties
	ATank();

	FRotator OringalRotation = FRotator(0.0f, 0.0f, 0.0f);
};
