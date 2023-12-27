#include "SpaceInvadersPlayerShip.h"
#include "Math/UnrealMathUtility.h"

ASpaceInvadersPlayersShip::ASpaceInvadersPlayersShip()
{
	PrimaryActorTick.bCanEverTick = false;
	UE_LOG(LogTemp, Warning, TEXT("ASpaceInvadersPlayersShip's constructor called"));
}

void ASpaceInvadersPlayersShip::MoveLeft()
{
	ASpaceInvadersMoveable::MoveLeft();
}

void ASpaceInvadersPlayersShip::MoveRight()
{
	ASpaceInvadersMoveable::MoveRight();
}
