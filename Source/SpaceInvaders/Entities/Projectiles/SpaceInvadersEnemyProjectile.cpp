#include "SpaceInvaders/Entities/Projectiles/SpaceInvadersEnemyProjectile.h"

ASpaceInvadersEnemyProjectile::ASpaceInvadersEnemyProjectile()
{
	UE_LOG(LogTemp, Log, TEXT("ASpaceInvadersEnemyProjectile's constructor called"));
	MeshComponent->SetCollisionProfileName(TEXT("EnemyProjectile"));
	MeshComponent->SetWorldScale3D(FVector(0.7f, 0.3f, 1.0f));
}