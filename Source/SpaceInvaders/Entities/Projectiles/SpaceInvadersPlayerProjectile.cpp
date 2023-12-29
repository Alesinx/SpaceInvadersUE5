#include "SpaceInvaders/Entities/Projectiles/SpaceInvadersPlayerProjectile.h"

ASpaceInvadersPlayerProjectile::ASpaceInvadersPlayerProjectile()
{
	UE_LOG(LogTemp, Log, TEXT("ASpaceInvadersPlayerProjectile's constructor called"));
	MeshComponent->SetCollisionProfileName(TEXT("PlayerProjectile"));
}