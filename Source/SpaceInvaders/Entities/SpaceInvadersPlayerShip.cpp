#include "SpaceInvadersPlayerShip.h"
#include "SpaceInvaders/Entities/Projectiles/SpaceInvadersPlayerProjectile.h"

ASpaceInvadersPlayerShip::ASpaceInvadersPlayerShip()
{
	UE_LOG(LogTemp, Log, TEXT("ASpaceInvadersPlayerShip's constructor called"));
	MeshComponent->SetCollisionProfileName(TEXT("PlayerShip"));
}

void ASpaceInvadersPlayerShip::Fire()
{
	const FVector SpawnLocation = GetActorLocation() + ProjectileOffset;
	const FRotator SpawnRotation = GetActorRotation();
	ASpaceInvadersPlayerProjectile* Projectile = GetWorld()->SpawnActor<ASpaceInvadersPlayerProjectile>(ASpaceInvadersPlayerProjectile::StaticClass(), SpawnLocation, SpawnRotation);

	if (!Projectile)
	{
		UE_LOG(LogTemp, Error, TEXT("Could not spawn projectile. Aborting fire"));
		return;
	}

	if (Projectile)
	{
		UE_LOG(LogTemp, Log, TEXT("Firing player projectile"));
		Projectile->SetOwner(this);
	}
}

void ASpaceInvadersPlayerShip::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("ASpaceInvadersPlayerShip::OnOverlapBegin() called"));
	OnShipHit.Broadcast();
}