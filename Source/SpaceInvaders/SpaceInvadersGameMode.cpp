#include "SpaceInvadersGameMode.h"
#include "SpaceInvaders/SpaceInvadersPlayerController.h"
#include "SpaceInvaders/SpaceInvadersPlayerView.h"
#include "SpaceInvaders/Entities/SpaceInvadersEnemy.h"

ASpaceInvadersGameMode::ASpaceInvadersGameMode()
{
    PrimaryActorTick.bCanEverTick = true;
    UE_LOG(LogTemp, Log, TEXT("ASpaceInvadersGameMode's constructor called"));
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
    const FRotator EnemySpawnRotation = FRotator(0.0f, -90.0f, 0.0f);
    for (int i = 0; i < EnemiesRows; i++)
    {
        for (int j = 0; j < EnemiesColums; j++)
        {
			FVector EnemyLocation = FVector(i * SpacebetweenEnemies + EnemiesStartingPosition.X, j * SpacebetweenEnemies + EnemiesStartingPosition.Y, 0);
			ASpaceInvadersEnemy* Enemy = GetWorld()->SpawnActor<ASpaceInvadersEnemy>(ASpaceInvadersEnemy::StaticClass(), EnemyLocation, EnemySpawnRotation);
			Enemies.Add(Enemy);
		}
	}
}

void ASpaceInvadersGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    if (Enemies.Num() > 0)
    {
        if (GetWorld()->GetTimeSeconds() - LastFireTime >= EnemyFireFrecSeconds)
        {
            int RandomEnemyIndex = FMath::RandRange(0, Enemies.Num() - 1);
            ASpaceInvadersEnemy* RandomEnemy = Enemies[RandomEnemyIndex];
            if (RandomEnemy) // Make sure it is not marked for destroy
            {
                RandomEnemy->Fire();
                LastFireTime = GetWorld()->GetTimeSeconds();
            }
        }
	}
}
