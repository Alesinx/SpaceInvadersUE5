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
	ASpaceInvadersGameMode();

	virtual void StartPlay() override;

	ASpaceInvadersPlayerShip* GetPlayerShip() { return nullptr; }

private:
	void InitializeEnemies();

private:
	UPROPERTY()
	int EnemiesColums = 5;
	int EnemiesRows = 5;
	int SpacebetweenEnemies = 200;
	FVector2D EnemiesStartingPosition = FVector2D(0, 1000);

	UPROPERTY()
	ASpaceInvadersPlayerShip* PlayerShip;
	TArray<ASpaceInvadersEnemy*> Enemies;
};
