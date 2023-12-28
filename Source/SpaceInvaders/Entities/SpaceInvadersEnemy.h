#pragma once

#include "CoreMinimal.h"
#include "SpaceInvadersEntity.h"
#include "SpaceInvadersEnemy.generated.h"

/**
 * Class representing a space invaders enemy
 */
UCLASS()
class SPACEINVADERS_API ASpaceInvadersEnemy : public ASpaceInvadersEntity
{
	GENERATED_BODY()

public:
	ASpaceInvadersEnemy();
};