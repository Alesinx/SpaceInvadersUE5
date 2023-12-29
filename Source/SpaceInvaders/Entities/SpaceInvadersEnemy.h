#pragma once

#include "CoreMinimal.h"
#include "SpaceInvadersEntity.h"
#include "SpaceInvadersEnemy.generated.h"

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

public:
	UFUNCTION()
	void Fire();

//private:
//	UPROPERTY()
//	TSubclassOf<ASpaceInvadersProjectileBase> ProjectileClass;
};