#include "SpaceInvadersEnemy.h"
#include "Math/UnrealMathUtility.h"

ASpaceInvadersEnemy::ASpaceInvadersEnemy()
{
	PrimaryActorTick.bCanEverTick = false;
	UE_LOG(LogTemp, Warning, TEXT("ASpaceInvadersEnemy's constructor called"));
}
