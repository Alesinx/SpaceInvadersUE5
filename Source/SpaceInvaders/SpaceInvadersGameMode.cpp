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

    InitializeEnemies();
}

void ASpaceInvadersGameMode::InitializeEnemies()
{  
    const FRotator EnemySpawnRotation = FRotator(0.0f, -90.0f, 0.0f);
    for (int i = 0; i < EnemiesColums; i++)
    {
        for (int j = 0; j < EnemiesRows; j++)
        {
			FVector EnemyLocation = FVector(i * SpacebetweenEnemies + EnemiesOffsetX, PlayingAreaHeight - j * SpacebetweenEnemies, 0);
			ASpaceInvadersEnemy* Enemy = GetWorld()->SpawnActor<ASpaceInvadersEnemy>(ASpaceInvadersEnemy::StaticClass(), EnemyLocation, EnemySpawnRotation);
			Enemies.Add(Enemy);
		}
	}
}

void ASpaceInvadersGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    MoveEnemies(DeltaTime);
    FireRandomEnemy();
}

void ASpaceInvadersGameMode::MoveEnemies(float DeltaTime)
{
    if (Enemies.Num() > 0)
    {
		int ValidEnemiesCount = 0;
        for (int i = 0; i < Enemies.Num(); i++)
        {
            if (IsValid(Enemies[i]))
            {
				ValidEnemiesCount++;
			}
		}

		FVector EnemyLocation = Enemies[0]->GetActorLocation();
        float MaxOffsetX = PlayingAreaWidth - EnemiesBlockWidth;
        float EnemiesMovementSpeed = MaxEnemiesMovementSpeed - (MaxEnemiesMovementSpeed - MinEnemiesMovementSpeed) * ValidEnemiesCount / InitialEnemiesCount;
        EnemiesOffsetX += EnemiesMovementDirection - EnemiesMovementSpeed * EnemiesMovementDirection * DeltaTime;
        if (EnemiesOffsetX >= MaxOffsetX)
        {
            EnemiesOffsetX = MaxOffsetX;
            EnemiesMovementDirection = 1;
            EnemiesOffsetY -= 100;
        }
        else if (EnemiesOffsetX <= 0.f)
        {
            EnemiesOffsetX = 0.f;
			EnemiesMovementDirection = -1;
            EnemiesOffsetY -= 100;
		}

        for (int i = 0; i < EnemiesColums; i++)
        {
            for (int j = 0; j < EnemiesRows; j++)
            {
                ASpaceInvadersEnemy* Enemy = Enemies[i * EnemiesRows + j];
                if (!IsValid(Enemy)) // Avoid moving destroyed enemies
                {
					continue;
				}

                FVector Location = Enemy->GetActorLocation();
                Location.X = i * SpacebetweenEnemies + EnemiesOffsetX;
                Location.Y = PlayingAreaHeight - j * SpacebetweenEnemies + EnemiesOffsetY;
                
                Enemy->SetActorLocation(Location);
            }
        }
	}
}

void ASpaceInvadersGameMode::FireRandomEnemy()
{
    if (Enemies.Num() > 0)
    {
        if (GetWorld()->GetTimeSeconds() - LastFireTime >= EnemyFireFrecSeconds)
        {
            int RandomEnemyIndex = FMath::RandRange(0, Enemies.Num() - 1);
            ASpaceInvadersEnemy* RandomEnemy = Enemies[RandomEnemyIndex];
            if (!IsValid(RandomEnemy)) // Avoid firing destroyed enemies
            {
                return; // Wait untill next tick
            }

            RandomEnemy->Fire();
            LastFireTime = GetWorld()->GetTimeSeconds();
        }
    }
}
