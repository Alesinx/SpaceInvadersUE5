#include "SpaceInvadersPlayerController.h"
#include "SpaceInvaders/SpaceInvadersGameMode.h"
#include "SpaceInvaders/Entities/SpaceInvadersPlayerShip.h"
#include "Math/UnrealMathUtility.h"

void ASpaceInvadersPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAction("MoveLeft", IE_Repeat, this, &ASpaceInvadersPlayerController::MoveLeft);
    InputComponent->BindAction("MoveRight", IE_Repeat, this, &ASpaceInvadersPlayerController::MoveRight);
}

void ASpaceInvadersPlayerController::BeginPlay()
{
    Super::BeginPlay();

    InitializePlayerShip();
}

void ASpaceInvadersPlayerController::InitializePlayerShip()
{
    PlayerShip = GetWorld()->SpawnActor<ASpaceInvadersPlayerShip>(ASpaceInvadersPlayerShip::StaticClass());
}

void ASpaceInvadersPlayerController::MoveLeft()
{
    UE_LOG(LogTemp, Warning, TEXT("MoveLeft called"));
    MoveShip(MovementStepX, 0);
}

void ASpaceInvadersPlayerController::MoveRight()
{
    UE_LOG(LogTemp, Warning, TEXT("MoveRight called"));
    MoveShip(-MovementStepX, 0);
}

void ASpaceInvadersPlayerController::MoveShip(float OffsetX, float OffsetY)
{
    if (PlayerShip)
    {
        const FVector currentLocation = PlayerShip->GetActorLocation();
        const FVector newLocation = FVector(
            FMath::Clamp(currentLocation.X + OffsetX, MinXLocation, MaxXLocation),
            FMath::Clamp(currentLocation.Y + OffsetY, MinYLocation, MaxYLocation),
            0);

        PlayerShip->SetActorLocation(newLocation);
    }
}