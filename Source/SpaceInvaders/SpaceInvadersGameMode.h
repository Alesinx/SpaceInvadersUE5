#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SpaceInvadersGameMode.generated.h"

class ASpaceInvadersPlayerShip;
class ASpaceInvadersEnemy;

/**
 * Space Invaders Game Mode
 */
UCLASS()
class SPACEINVADERS_API ASpaceInvadersGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY()
	float PlayingAreaWidth = 1000;

	UPROPERTY()
	float PlayingAreaHeight = 1000;
	
public:
	ASpaceInvadersGameMode();

	virtual void StartPlay() override;

	UFUNCTION()
	ASpaceInvadersPlayerShip* GetPlayerShip() { return nullptr; }

private:
	UPROPERTY()
	int EnemiesColums = 5;

	UPROPERTY()
	int EnemiesRows = 5;

	UPROPERTY()
	int SpacebetweenEnemies = 200;

	UPROPERTY()
	FVector2D EnemiesStartingPosition = FVector2D(0, 1000);

	UPROPERTY()
	ASpaceInvadersPlayerShip* PlayerShip;

	UPROPERTY()
	TArray<ASpaceInvadersEnemy*> Enemies;

private:
	UFUNCTION()
	void InitializeEnemies();
};
