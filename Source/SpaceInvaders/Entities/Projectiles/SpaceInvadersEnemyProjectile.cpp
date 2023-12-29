#include "SpaceInvaders/Entities/Projectiles/SpaceInvadersEnemyProjectile.h"

ASpaceInvadersEnemyProjectile::ASpaceInvadersEnemyProjectile()
{
	UE_LOG(LogTemp, Log, TEXT("ASpaceInvadersEnemyProjectile's constructor called"));
	MeshComponent->SetCollisionProfileName(TEXT("EnemyProjectile"));
}