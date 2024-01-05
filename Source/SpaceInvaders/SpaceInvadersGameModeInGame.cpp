#include "SpaceInvaders/SpaceInvadersGameModeInGame.h"
#include "SpaceInvaders/SpaceInvadersPlayerController.h"
#include "SpaceInvaders/Entities/SpaceInvadersPlayerShip.h"
#include "SpaceInvaders/SpaceInvadersPlayerView.h"
#include "SpaceInvaders/Entities/SpaceInvadersEnemy.h"
#include "SpaceInvaders/UI/SpaceInvadersGameOverWidget.h"

ASpaceInvadersGameModeInGame::ASpaceInvadersGameModeInGame()
{
    PrimaryActorTick.bCanEverTick = true;
    UE_LOG(LogTemp, Log, TEXT("ASpaceInvadersGameModeInGame's constructor called"));
    PlayerControllerClass = ASpaceInvadersPlayerController::StaticClass();

    ConstructorHelpers::FClassFinder<USpaceInvadersGameOverWidget> WidgetClassFinder(TEXT("/Game/UI/WBP_GameOverScreen"));
    if (WidgetClassFinder.Succeeded())
    {
        GameOverScreenClass = WidgetClassFinder.Class;
    }
}

void ASpaceInvadersGameModeInGame::StartPlay()
{
    Super::StartPlay();

    UE_LOG(LogTemp, Warning, TEXT("Space Invaders Game Mode has started!"));

    InitializeEnemies();

    ASpaceInvadersPlayerController* PlayerController = Cast<ASpaceInvadersPlayerController>(GetWorld()->GetFirstPlayerController());
    if (PlayerController)
    {
		PlayerController->GetPlayerShip()->OnShipHit.AddDynamic(this, &ASpaceInvadersGameModeInGame::OnPlayerShipHit);
	}
}

void ASpaceInvadersGameModeInGame::InitializeEnemies()
{  
    const FRotator EnemySpawnRotation = FRotator(0.0f, -90.0f, 0.0f);
    for (int i = 0; i < EnemiesColums; i++)
    {
        for (int j = 0; j < EnemiesRows; j++)
        {
			FVector EnemyLocation = FVector(i * -SpacebetweenEnemies + EnemiesOffsetX, PlayingAreaHeight - j * SpacebetweenEnemies, 0);
			ASpaceInvadersEnemy* Enemy = GetWorld()->SpawnActor<ASpaceInvadersEnemy>(ASpaceInvadersEnemy::StaticClass(), EnemyLocation, EnemySpawnRotation);
			Enemies.Add(Enemy);
            ValidEnemiesCount++;
            Enemy->OnEnemyHit.AddDynamic(this, &ASpaceInvadersGameModeInGame::OnEnemyHit);
		}
	}
}

void ASpaceInvadersGameModeInGame::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    MoveEnemies(DeltaTime);
    FireRandomEnemy();
}

void ASpaceInvadersGameModeInGame::MoveEnemies(float DeltaTime)
{
    if (Enemies.Num() <= 0)
    {
        return;
	}

    FVector EnemyLocation = Enemies[0]->GetActorLocation();
    float MaxOffsetX = PlayingAreaWidth;
    float MinOffsetX = EnemiesBlockWidth;
    float EnemiesMovementSpeed = MaxEnemiesMovementSpeed - (MaxEnemiesMovementSpeed - MinEnemiesMovementSpeed) * ValidEnemiesCount / InitialEnemiesCount;
    EnemiesOffsetX += EnemiesMovementDirection - EnemiesMovementSpeed * EnemiesMovementDirection * DeltaTime;
    if (EnemiesOffsetX >= MaxOffsetX)
    {
        EnemiesOffsetX = MaxOffsetX;
        EnemiesMovementDirection = 1;
        EnemiesOffsetY -= 100;
    }
    else if (EnemiesOffsetX <= MinOffsetX)
    {
        EnemiesOffsetX = MinOffsetX;
        EnemiesMovementDirection = -1;
        EnemiesOffsetY -= 100;
    }

    for (int i = 0; i < EnemiesColums; i++)
    {
        for (int j = 0; j < EnemiesRows; j++)
        {
            ASpaceInvadersEnemy* Enemy = Enemies[i * EnemiesRows + j];
            if (IsValid(Enemy)) // Avoid moving destroyed enemies
            {
                FVector Location = Enemy->GetActorLocation();
                Location.X = i * -SpacebetweenEnemies + EnemiesOffsetX;
                Location.Y = PlayingAreaHeight - j * SpacebetweenEnemies + EnemiesOffsetY;

                Enemy->SetActorLocation(Location);
            }
        }
    }
}

void ASpaceInvadersGameModeInGame::FireRandomEnemy()
{
    if (Enemies.Num() <= 0)
    {
        return;
    }

    if (GetWorld()->GetTimeSeconds() - LastFireTime < EnemyFireRate)
    {
		return;
    }

    int RandomEnemyIndex = FMath::RandRange(0, Enemies.Num() - 1);
    ASpaceInvadersEnemy* RandomEnemy = Enemies[RandomEnemyIndex];
    if (IsValid(RandomEnemy)) // Avoid firing destroyed enemies
    {
        RandomEnemy->Fire();
        LastFireTime = GetWorld()->GetTimeSeconds();
    }
}

void ASpaceInvadersGameModeInGame::OnPlayerShipHit()
{
    UE_LOG(LogTemp, Log, TEXT("Player hit!"));
}

void ASpaceInvadersGameModeInGame::OnEnemyHit(int ScoreValue)
{
    UE_LOG(LogTemp, Log, TEXT("Enemy hit!"));
    Score += ScoreValue;
    ValidEnemiesCount--;
    if (ValidEnemiesCount <= 0)
	{
        if (GameOverScreenClass)
		{
            USpaceInvadersGameOverWidget* GameOverWidget = CreateWidget<USpaceInvadersGameOverWidget>(GetWorld(), GameOverScreenClass);
			if (GameOverWidget)
			{
				GameOverWidget->AddToViewport();
                GameOverWidget->SetScoreText(Score);
			}
		}
	}
}