#include "SpaceInvaders/Entities/Projectiles/SpaceInvadersPlayerProjectile.h"

ASpaceInvadersPlayerProjectile::ASpaceInvadersPlayerProjectile()
{
	UE_LOG(LogTemp, Log, TEXT("ASpaceInvadersPlayerProjectile's constructor called"));
	MeshComponent->SetCollisionProfileName(TEXT("PlayerProjectile"));
	MovementSpeed = 4000.0f;
}

void ASpaceInvadersPlayerProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	const FVector CurrentLocation = GetActorLocation();
	if (CurrentLocation.Y > 5000)
	{
		Destroy();
	}
}
