#include "SpaceInvaders/Entities/Projectiles/SpaceInvadersEnemyProjectile.h"

ASpaceInvadersEnemyProjectile::ASpaceInvadersEnemyProjectile()
{
	UE_LOG(LogTemp, Log, TEXT("ASpaceInvadersEnemyProjectile's constructor called"));
	MeshComponent->SetCollisionProfileName(TEXT("EnemyProjectile"));
	MeshComponent->SetWorldScale3D(FVector(0.7f, 0.3f, 1.0f));
}

void ASpaceInvadersEnemyProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FVector CurrentLocation = GetActorLocation();
	if (CurrentLocation.Y < -100)
	{
		Destroy();
	}
}