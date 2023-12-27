#pragma once

#include "CoreMinimal.h"
#include "SpaceInvadersMoveable.h"
#include "SpaceInvadersEnemy.generated.h"

/**
 * Class representing a space invaders enemy
 */
UCLASS()
class SPACEINVADERS_API ASpaceInvadersEnemy : public ASpaceInvadersMoveable
{
	GENERATED_BODY()

public:
	ASpaceInvadersEnemy();
};
