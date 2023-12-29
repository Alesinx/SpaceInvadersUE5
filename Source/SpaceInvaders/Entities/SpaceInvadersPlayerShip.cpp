#include "SpaceInvadersPlayerShip.h"

ASpaceInvadersPlayerShip::ASpaceInvadersPlayerShip()
{
	PrimaryActorTick.bCanEverTick = false;
	UE_LOG(LogTemp, Warning, TEXT("ASpaceInvadersPlayerShip's constructor called"));
}

void ASpaceInvadersPlayerShip::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("ASpaceInvadersPlayerShip::Fire() called"));
}