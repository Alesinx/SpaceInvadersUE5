// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SpaceInvadersPlayerController.generated.h"

class ASpaceInvadersPlayersShip;

/**
 * Space Invaders Player Controller
 */
UCLASS()
class SPACEINVADERS_API ASpaceInvadersPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ASpaceInvadersPlayerController() = default;
	void SetupInputComponent() override;
	void BeginPlay() override;

private:
	UPROPERTY()
	ASpaceInvadersPlayersShip* PlayerShip;
	void MoveLeft();
	void MoveRight();
};