#include "SpaceInvadersPlayerController.h"
#include "SpaceInvaders/SpaceInvadersGameMode.h"
#include "SpaceInvaders/Entities/SpaceInvadersPlayerShip.h"

void ASpaceInvadersPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    InputComponent->BindAction("MoveLeft", IE_Pressed, this, &ASpaceInvadersPlayerController::MoveLeft);
    InputComponent->BindAction("MoveRight", IE_Pressed, this, &ASpaceInvadersPlayerController::MoveRight);
}

void ASpaceInvadersPlayerController::BeginPlay()
{
    Super::BeginPlay();

    ASpaceInvadersGameMode* GameMode = Cast<ASpaceInvadersGameMode>(GetWorld()->GetAuthGameMode());
    if (GameMode)
    {
        PlayerShip = GameMode->GetPlayerShip();
    }
}

void ASpaceInvadersPlayerController::MoveLeft()
{
    if(PlayerShip)
    {
        PlayerShip->MoveLeft();
    }
}

void ASpaceInvadersPlayerController::MoveRight()
{
    if (PlayerShip)
    {
		PlayerShip->MoveRight();
	}
}
