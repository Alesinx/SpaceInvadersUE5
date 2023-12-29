#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SpaceInvadersGameModeInGame.generated.h"

class ASpaceInvadersPlayerShip;
class ASpaceInvadersEnemy;

/**
 * Space Invaders Game Mode
 */
UCLASS()
class SPACEINVADERS_API ASpaceInvadersGameModeInGame : public AGameModeBase
{
	GENERATED_BODY()

public:
	float PlayingAreaWidth = 3000;
	float PlayingAreaHeight = 3000;
	
public:
	ASpaceInvadersGameModeInGame();

	virtual void StartPlay() override;

private:
	int EnemiesColums = 11;
	int EnemiesRows = 5;
	int InitialEnemiesCount = EnemiesColums * EnemiesRows;

	float SpacebetweenEnemies = 150.0f;
	float EnemiesBlockWidth = EnemiesColums * SpacebetweenEnemies;
	float EnemiesOffsetX = PlayingAreaWidth / 2 - (EnemiesColums * SpacebetweenEnemies) / 2;
	float EnemiesOffsetY = 0;

	float EnemiesMovementDirection = 1.0f;
	float MaxEnemiesMovementSpeed = 1500.0f;
	float MinEnemiesMovementSpeed = 500.0f;

	float EnemyFireFrecSeconds = 2.0f;
	float LastFireTime = 0;

	TArray<ASpaceInvadersEnemy*> Enemies;

private:
	void InitializeEnemies();
	void Tick(float DeltaTime) override;
	void MoveEnemies(float DeltaTime);
	void FireRandomEnemy();
};