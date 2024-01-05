#include "SpaceInvadersPlayerController.h"
#include "SpaceInvaders/SpaceInvadersGameModeInGame.h"
#include "SpaceInvaders/Entities/SpaceInvadersPlayerShip.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/GameplayStatics.h"

void ASpaceInvadersPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAxis("Move", this, &ASpaceInvadersPlayerController::MovePlayerShip);
    InputComponent->BindAction("Fire", IE_Pressed, this, &ASpaceInvadersPlayerController::Fire);
}

void ASpaceInvadersPlayerController::BeginPlay()
{
    Super::BeginPlay();

    GameMode = Cast<ASpaceInvadersGameModeInGame>(GetWorld()->GetAuthGameMode());
    if (!GameMode)
    {
		UE_LOG(LogTemp, Error, TEXT("Coudl not find Game Mode"));
    }

    InitializePlayerShip();
}

void ASpaceInvadersPlayerController::InitializePlayerShip()
{
    FVector ShipSpawnLocation = GameMode? ShipSpawnLocation = FVector(GameMode->PlayingAreaWidth * 1/2, 0.0f, 0.0f) : FVector::ZeroVector;
    const FRotator ShipSpawnRotation = FRotator(0.0f, 90.0f, 0.0f);
    PlayerShip = GetWorld()->SpawnActor<ASpaceInvadersPlayerShip>(ASpaceInvadersPlayerShip::StaticClass(), ShipSpawnLocation, ShipSpawnRotation);
}

void ASpaceInvadersPlayerController::MovePlayerShip(float Direction)
{
    if (!GameMode)
    {
        UE_LOG(LogTemp, Error, TEXT("Game mode not found. Aborting movement"));
        return;
    }

    if (!PlayerShip)
    {
        UE_LOG(LogTemp, Error, TEXT("Player ship not found. Aborting movement"));
        return;
    }

    FVector Location = PlayerShip->GetActorLocation();
    const float Min = 0.f;
    const float Max = GameMode->PlayingAreaWidth;
    const float DeltaTime = GetWorld()->GetDeltaSeconds();
    const float NewX = FMath::Clamp(Location.X + Direction * MovementSpeed * DeltaTime, Min, Max);
    Location.X = NewX;

    PlayerShip->SetActorLocation(Location);
}

void ASpaceInvadersPlayerController::Fire()
{
    if (!PlayerShip)
    {
        UE_LOG(LogTemp, Error, TEXT("Player ship not found. Aborting fire"));
		return;
	}

    if (GetWorld()->GetTimeSeconds() - LastFireTime < FireRate)
    {
		UE_LOG(LogTemp, Warning, TEXT("Player ship gun's is on cooldown!"));
		return;
	}

	PlayerShip->Fire();
    LastFireTime = GetWorld()->GetTimeSeconds();
}