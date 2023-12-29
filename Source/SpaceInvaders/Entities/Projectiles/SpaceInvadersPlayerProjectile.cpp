#include "SpaceInvaders/Entities/Projectiles/SpaceInvadersPlayerProjectile.h"

ASpaceInvadersPlayerProjectile::ASpaceInvadersPlayerProjectile()
{
	UE_LOG(LogTemp, Log, TEXT("ASpaceInvadersPlayerProjectile's constructor called"));
	MeshComponent->SetCollisionProfileName(TEXT("PlayerProjectile"));
	MovementSpeed = 10000.0f;
	MeshComponent->SetWorldScale3D(FVector(1.0f, 0.2f, 1.0f));
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