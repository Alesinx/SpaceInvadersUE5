#include "SpaceInvadersEnemy.h"
#include "SpaceInvaders/Entities/Projectiles/SpaceInvadersEnemyProjectile.h"
#include "Math/UnrealMathUtility.h"

ASpaceInvadersEnemy::ASpaceInvadersEnemy()
{
	UE_LOG(LogTemp, Log, TEXT("ASpaceInvadersEnemy's constructor called"));
	MeshComponent->SetCollisionProfileName(TEXT("Enemy"));
}

void ASpaceInvadersEnemy::Fire()
{
	const FVector SpawnLocation = GetActorLocation() + ProjectileOffset;
	const FRotator SpawnRotation = GetActorRotation();
	ASpaceInvadersEnemyProjectile* Projectile = GetWorld()->SpawnActor<ASpaceInvadersEnemyProjectile>(ASpaceInvadersEnemyProjectile::StaticClass(), SpawnLocation, SpawnRotation);

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

void ASpaceInvadersEnemy::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	OnEnemyHit.Broadcast(ScoreValue);
	Super::OnOverlapBegin(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}