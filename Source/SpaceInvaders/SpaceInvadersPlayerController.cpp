#include "SpaceInvadersPlayerController.h"
#include "SpaceInvaders/SpaceInvadersGameMode.h"
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

    InitializePlayerShip();
}

void ASpaceInvadersPlayerController::InitializePlayerShip()
{
    FVector ShipSpawnLocation = FVector(0.0f, 0.0f, 0.0f);
    const FRotator ShipSpawnRotation = FRotator(0.0f, 90.0f, 0.0f);

    ASpaceInvadersGameMode* GameMode = Cast<ASpaceInvadersGameMode>(GetWorld()->GetAuthGameMode());
    if (GameMode)
    {
        ShipSpawnLocation = FVector(GameMode->PlayingAreaWidth / 2, 0.0f , 0.0f);
	}
    PlayerShip = GetWorld()->SpawnActor<ASpaceInvadersPlayerShip>(ASpaceInvadersPlayerShip::StaticClass(), ShipSpawnLocation, ShipSpawnRotation);
}

void ASpaceInvadersPlayerController::MovePlayerShip(float Amount)
{
    if (PlayerShip)
    {
        const FVector currentLocation = PlayerShip->GetActorLocation();
        const float offset = Amount * MovementSpeed * UGameplayStatics::GetWorldDeltaSeconds(this);
        const FVector newLocation = FVector(
            FMath::Clamp(currentLocation.X + Amount * MovementSpeed, MinXLocation, MaxXLocation),
            currentLocation.Y,
            currentLocation.Z);

        PlayerShip->SetActorLocation(newLocation);
    }
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