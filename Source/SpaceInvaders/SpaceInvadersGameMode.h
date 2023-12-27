#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SpaceInvadersGameMode.generated.h"

class ASpaceInvadersPlayersShip;
class ASpaceInvadersEnemy;

/**
 * Space Invaders Game Mode
 */
UCLASS()
class SPACEINVADERS_API ASpaceInvadersGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ASpaceInvadersGameMode();

	virtual void StartPlay() override;

	ASpaceInvadersPlayersShip* GetPlayerShip() { return nullptr; }

private:
	void InitializePlayerShip();
	void InitializeEnemies();

private:
	UPROPERTY()
	int EnemiesColums = 5;
	int EnemiesRows = 5;
	int SpacebetweenEnemies = 200;
	FVector2D EnemiesStartingPosition = FVector2D(100, 100);

	UPROPERTY()
	ASpaceInvadersPlayersShip* PlayerShip;

	TArray<ASpaceInvadersEnemy*> Enemies;
};
