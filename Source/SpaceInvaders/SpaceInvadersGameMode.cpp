#include "SpaceInvadersGameMode.h"
#include "SpaceInvaders/SpaceInvadersPlayerController.h"
#include "SpaceInvaders/SpaceInvadersPlayerView.h"
#include "SpaceInvaders/Entities/SpaceInvadersEnemy.h"

ASpaceInvadersGameMode::ASpaceInvadersGameMode()
{
    UE_LOG(LogTemp, Warning, TEXT("ASpaceInvadersGameMode's constructor called"));
    PlayerControllerClass = ASpaceInvadersPlayerController::StaticClass();
    DefaultPawnClass = ASpaceInvadersPlayerView::StaticClass();
}

void ASpaceInvadersGameMode::StartPlay()
{
    Super::StartPlay();

    UE_LOG(LogTemp, Warning, TEXT("Space Invaders Game Mode has started!"));

    //InitializePlayerShip();
    InitializeEnemies();
}

void ASpaceInvadersGameMode::InitializeEnemies()
{  
    for (int i = 0; i < EnemiesRows; i++)
    {
        for (int j = 0; j < EnemiesColums; j++)
        {
			FVector EnemyLocation = FVector(i * SpacebetweenEnemies + EnemiesStartingPosition.X, j * SpacebetweenEnemies + EnemiesStartingPosition.Y, 0);
			ASpaceInvadersEnemy* Enemy = GetWorld()->SpawnActor<ASpaceInvadersEnemy>(ASpaceInvadersEnemy::StaticClass(), EnemyLocation, FRotator::ZeroRotator);
			Enemies.Add(Enemy);
		}
	}
}