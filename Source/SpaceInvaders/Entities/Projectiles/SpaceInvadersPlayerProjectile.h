#pragma once

#include "CoreMinimal.h"
#include "SpaceInvaders/Entities/Projectiles/SpaceInvadersProjectileBase.h"
#include "SpaceInvadersPlayerProjectile.generated.h"

/**
 * Class represeting a projectile fired by the player
 */
UCLASS()
class SPACEINVADERS_API ASpaceInvadersPlayerProjectile : public ASpaceInvadersProjectileBase
{
	GENERATED_BODY()

public:
	ASpaceInvadersPlayerProjectile();
};
