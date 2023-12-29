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
    PlayerShip = GetWorld()->SpawnActor<ASpaceInvadersPlayerShip>(ASpaceInvadersPlayerShip::StaticClass());
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
    if (PlayerShip)
    {
		PlayerShip->Fire();
	}
}