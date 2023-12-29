#pragma once

#include "CoreMinimal.h"
#include "SpaceInvaders/Entities/Projectiles/SpaceInvadersProjectileBase.h"
#include "SpaceInvadersEnemyProjectile.generated.h"

/**
 * Class representing a projectile fired by an enemy
 */
UCLASS()
class SPACEINVADERS_API ASpaceInvadersEnemyProjectile : public ASpaceInvadersProjectileBase
{
	GENERATED_BODY()

public:
	ASpaceInvadersEnemyProjectile();
};
