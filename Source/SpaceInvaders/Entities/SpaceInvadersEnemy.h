#pragma once

#include "CoreMinimal.h"
#include "SpaceInvadersEntity.h"
#include "SpaceInvadersEnemy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnemyHit, int, ScoreValue);

class ASpaceInvadersProjectileBase;

/**
 * Class representing a space invaders enemy
 */
UCLASS()
class SPACEINVADERS_API ASpaceInvadersEnemy : public ASpaceInvadersEntity
{
	GENERATED_BODY()

public:
	ASpaceInvadersEnemy();

public:
	UPROPERTY()
	FVector ProjectileOffset = FVector(0.0f, -100.0f, 0.0f);

	UPROPERTY(BlueprintAssignable)
	FOnEnemyHit OnEnemyHit;

public:
	UFUNCTION()
	void Fire();

private:
	int EnemyIndex;
	int ScoreValue = 10;

private:
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
};