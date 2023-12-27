#include "SpaceInvadersMoveable.h"
#include "Math/UnrealMathUtility.h"

ASpaceInvadersMoveable::ASpaceInvadersMoveable()
{
	UE_LOG(LogTemp, Warning, TEXT("ASpaceInvadersMoveable construtor called"));
	PrimaryActorTick.bCanEverTick = false;
}

void ASpaceInvadersMoveable::MoveRight()
{
	Move(MovementStepX, 0);
}

void ASpaceInvadersMoveable::MoveLeft()
{
	Move(-MovementStepX, 0);
}

void ASpaceInvadersMoveable::Move(float OffsetX, float OffsetY)
{
	FVector CurrentLocation = GetActorLocation();
	float NewLocationX = FMath::Clamp(GetActorLocation().X + MovementStepX, MinXLocation, MaxXLocation);
	float NewLocationY = FMath::Clamp(GetActorLocation().X + MovementStepY, MinYLocation, MaxYLocation);
	FVector NewLocation = FVector(NewLocationX, NewLocationY, CurrentLocation.Z);
	SetActorLocation(NewLocation);
}